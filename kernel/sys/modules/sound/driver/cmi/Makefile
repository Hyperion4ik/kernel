# $FreeBSD: releng/11.1/sys/modules/sound/driver/cmi/Makefile 319182 2017-05-30 04:11:12Z ngie $

.PATH: ${SRCTOP}/sys/dev/sound/pci

KMOD=	snd_cmi
SRCS=	device_if.h bus_if.h pci_if.h
SRCS+= mpufoi_if.h
SRCS+=	cmi.c

.include <bsd.kmod.mk>
