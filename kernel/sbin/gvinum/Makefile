# $FreeBSD: releng/11.1/sbin/gvinum/Makefile 319185 2017-05-30 04:17:22Z ngie $

PACKAGE=runtime
PROG=	gvinum
SRCS=	gvinum.c gvinum.h geom_vinum_share.c
MAN=	gvinum.8

WARNS?=	2
CFLAGS+=	-I${SRCTOP}/sys -I${DESTDIR}/${INCLUDEDIR}/edit

LIBADD=	edit geom

.PATH: ${SRCTOP}/sys/geom/vinum

.include <bsd.prog.mk>
