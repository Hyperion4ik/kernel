# $FreeBSD: releng/11.1/lib/libc/gdtoa/Makefile.inc 316423 2017-04-02 17:24:58Z dim $

# netlib gdtoa sources
.PATH: ${LIBC_SRCTOP}/gdtoa

MISRCS+=_hdtoa.c _hldtoa.c _ldtoa.c glue.c
GDTOASRCS+=dmisc.c dtoa.c gdtoa.c gethex.c gmisc.c \
	hd_init.c hexnan.c misc.c smisc.c \
	strtod.c strtodg.c strtof.c strtord.c sum.c ulp.c

SYM_MAPS+=${LIBC_SRCTOP}/gdtoa/Symbol.map

CFLAGS+=-I${SRCTOP}/contrib/gdtoa

.for src in ${GDTOASRCS}
MISRCS+=gdtoa_${src}
CLEANFILES+=gdtoa_${src}
gdtoa_${src}: ${SRCTOP}/contrib/gdtoa/${src} .NOMETA
	ln -sf ${.ALLSRC} ${.TARGET}
CFLAGS.gdtoa_${src}+=-fno-strict-aliasing
.endfor
