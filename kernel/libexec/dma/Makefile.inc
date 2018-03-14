# $FreeBSD: releng/11.1/libexec/dma/Makefile.inc 304587 2016-08-22 07:08:00Z bapt $

.sinclude "${.CURDIR}/../../Makefile.inc"
DMA_SOURCES=	${.CURDIR}/../../../contrib/dma
.PATH:	${DMA_SOURCES}

CFLAGS+= -I${DMA_SOURCES} \
	-DHAVE_REALLOCF -DHAVE_STRLCPY -DHAVE_GETPROGNAME \
	-DCONF_PATH='"/etc/dma"' \
	-DLIBEXEC_PATH='"/usr/libexec"' -DDMA_VERSION='"v0.11+"' \
	-DDMA_ROOT_USER='"mailnull"' \
	-DDMA_GROUP='"mail"'
BINGRP=	mail
PACKAGE=	dma