# $FreeBSD: releng/11.1/usr.bin/procstat/Makefile 287486 2015-09-05 17:02:01Z allanjude $

PROG=	procstat
MAN=	procstat.1
SRCS=	procstat.c		\
	procstat_args.c		\
	procstat_auxv.c		\
	procstat_basic.c	\
	procstat_bin.c		\
	procstat_cred.c		\
	procstat_cs.c		\
	procstat_files.c	\
	procstat_kstack.c	\
	procstat_rlimit.c	\
	procstat_rusage.c	\
	procstat_sigs.c		\
	procstat_threads.c	\
	procstat_vm.c

LIBADD+=	procstat xo util sbuf

.include <bsd.prog.mk>
