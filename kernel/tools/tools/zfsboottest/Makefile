# $FreeBSD: releng/11.1/tools/tools/zfsboottest/Makefile 291738 2015-12-04 03:17:47Z bdrewery $

.PATH:		${.CURDIR}/../../../sys/boot/zfs ${.CURDIR}/../../../sys/cddl/boot/zfs

BINDIR?=	/usr/bin
SCRIPTSDIR?=	/usr/bin

PROG=		zfsboottest
SCRIPTS=	zfsboottest.sh
SCRIPTSNAME=	zfsboottest.sh
MAN=

CFLAGS=	-O1 \
	-I${.CURDIR}/../../../sys/boot/zfs \
	-I${.CURDIR}/../../../sys/cddl/boot/zfs \
	-I. \
	-fdiagnostics-show-option \
	-W -Wextra -Wno-sign-compare -Wno-unused-parameter
CFLAGS+=-m32
LIBADD+=	md

.if ${MACHINE_CPUARCH} == "amd64"
beforedepend zfsboottest.o: machine
CLEANFILES+=	machine
machine:
	ln -sf ${.CURDIR}/../../../sys/i386/include machine
.endif

.include <bsd.prog.mk>
