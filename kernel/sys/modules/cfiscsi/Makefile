# $FreeBSD: releng/11.1/sys/modules/cfiscsi/Makefile 316212 2017-03-30 04:56:27Z ngie $

.PATH: ${SRCTOP}/sys/cam/ctl

KMOD=	cfiscsi

#CFLAGS+=-DICL_KERNEL_PROXY

MFILES=	dev/iscsi/icl_conn_if.m
SRCS=	ctl_frontend_iscsi.c icl_conn_if.h

.include <bsd.kmod.mk>
