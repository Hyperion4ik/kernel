# $FreeBSD: releng/11.1/tests/sys/kqueue/Makefile 309469 2016-12-03 02:55:19Z ngie $

TESTSRC=	${SRCTOP}/contrib/netbsd-tests/kernel/kqueue

TESTSDIR=	${TESTSBASE}/sys/kqueue
BINDIR=		${TESTSDIR}

NETBSD_ATF_TESTS_C=	proc1_test
# XXX: fails `ke.fflags & NOTE_TRACKERR` invariant
#NETBSD_ATF_TESTS_C+=	proc2_test
NETBSD_ATF_TESTS_C+=	proc3_test
NETBSD_ATF_TESTS_C+=	sig_test
NETBSD_ATF_TESTS_C+=	vnode_test

WARNS?=		3

TESTS_SUBDIRS+=	libkqueue

.include <netbsd-tests.test.mk>
.include <bsd.test.mk>
