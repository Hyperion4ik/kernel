# $FreeBSD: releng/11.1/sys/modules/ibcore/Makefile 319182 2017-05-30 04:11:12Z ngie $
.PATH:  ${SRCTOP}/sys/ofed/drivers/infiniband/core

KMOD=	ibcore
SRCS=	addr.c iwcm.c sa_query.c ucma.c uverbs_cmd.c \
	agent.c multicast.c smi.c ud_header.c uverbs_main.c \
	mad.c peer_mem.c umem.c uverbs_marshall.c \
	cache.c device.c packer.c sysfs.c user_mad.c verbs.c \
	cm.c fmr_pool.c mad_rmpp.c ucm.c cma.c \
	vnode_if.h device_if.h bus_if.h pci_if.h \
	opt_inet.h opt_inet6.h

CFLAGS+= -I${SRCTOP}/sys/ofed/drivers/infiniband/core
CFLAGS+= -I${SRCTOP}/sys/ofed/include
CFLAGS+= -I${SRCTOP}/sys/compat/linuxkpi/common/include
CFLAGS+= -DINET6 -DINET

.include <bsd.kmod.mk>

CFLAGS+= -Wno-cast-qual -Wno-pointer-arith

CWARNFLAGS.cm.c=	-Wno-unused-function
