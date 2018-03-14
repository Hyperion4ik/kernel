/*-
 * Copyright (c) 2008 Isilon Inc http://www.isilon.com/
 * Authors: Doug Rabson <dfr@rabson.org>
 * Developed with Red Inc: Alfred Perlstein <alfred@freebsd.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: releng/11.1/sys/kgssapi/gss_pname_to_uid.c 244370 2012-12-18 00:25:48Z rmacklem $");

#include <sys/param.h>
#include <sys/kernel.h>
#include <sys/kobj.h>
#include <sys/lock.h>
#include <sys/malloc.h>
#include <sys/mutex.h>

#include <kgssapi/gssapi.h>
#include <kgssapi/gssapi_impl.h>

#include "kgss_if.h"

OM_uint32
gss_pname_to_uid(OM_uint32 *minor_status, const gss_name_t pname,
    const gss_OID mech, uid_t *uidp)
{
	struct pname_to_uid_res res;
	struct pname_to_uid_args args;
	enum clnt_stat stat;
	CLIENT *cl;

	*minor_status = 0;

	if (pname == GSS_C_NO_NAME)
		return (GSS_S_BAD_NAME);

	cl = kgss_gssd_client();
	if (cl == NULL)
		return (GSS_S_FAILURE);

	args.pname = pname->handle;
	args.mech = mech;

	bzero(&res, sizeof(res));
	stat = gssd_pname_to_uid_1(&args, &res, cl);
	CLNT_RELEASE(cl);
	if (stat != RPC_SUCCESS) {
		*minor_status = stat;
		return (GSS_S_FAILURE);
	}

	if (res.major_status != GSS_S_COMPLETE) {
		*minor_status = res.minor_status;
		return (res.major_status);
	}

	*uidp = res.uid;
	return (GSS_S_COMPLETE);
}

OM_uint32
gss_pname_to_unix_cred(OM_uint32 *minor_status, const gss_name_t pname,
    const gss_OID mech, uid_t *uidp, gid_t *gidp,
    int *numgroups, gid_t *groups)
	      
{
	struct pname_to_uid_res res;
	struct pname_to_uid_args args;
	enum clnt_stat stat;
	int i, n;
	CLIENT *cl;

	*minor_status = 0;

	if (pname == GSS_C_NO_NAME)
		return (GSS_S_BAD_NAME);

	cl = kgss_gssd_client();
	if (cl == NULL)
		return (GSS_S_FAILURE);

	args.pname = pname->handle;
	args.mech = mech;

	bzero(&res, sizeof(res));
	stat = gssd_pname_to_uid_1(&args, &res, cl);
	CLNT_RELEASE(cl);
	if (stat != RPC_SUCCESS) {
		*minor_status = stat;
		return (GSS_S_FAILURE);
	}

	if (res.major_status != GSS_S_COMPLETE) {
		*minor_status = res.minor_status;
		return (res.major_status);
	}

	*uidp = res.uid;
	*gidp = res.gid;
	n = res.gidlist.gidlist_len;
	if (n > *numgroups)
		n = *numgroups;
	for (i = 0; i < n; i++)
		groups[i] = res.gidlist.gidlist_val[i];
	*numgroups = n;

	xdr_free((xdrproc_t) xdr_pname_to_uid_res, &res);

	return (GSS_S_COMPLETE);
}
