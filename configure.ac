AC_INIT([ParIS Parallel index of sequence], [1.3], [botao.peng@parisdescartes.fr],
             [libads])
AC_PREREQ([2.59])
AM_INIT_AUTOMAKE([1.15 -Wall no-define])
AC_CONFIG_HEADERS([config.h])
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_CC_C_O
AC_CHECK_HEADER(values.h)
AM_PROG_AR

if test "$ac_cv_header_values_h" == yes
then
	AC_DEFINE(VALUES, [], [include values.h])
fi

AC_ARG_WITH(without_ekosmas_dev_out, [  --without-ekosmas-dev-out            disable stuff])
if test "$without_ekosmas_dev_out" == "yes"
then
	AC_MSG_NOTICE([You have disabled ekosmas dev output!])
else
	AC_DEFINE(EKOSMAS_DEV_OUTPUT, [], [Print development output of ekosmas])
fi


AC_ARG_WITH(no_benchmarking, [  --no-benchmarking            disable stuff])
if test "$no_benchmarking" == "yes"
then
	AC_MSG_NOTICE([You have disabled benchmarking!])
else
	AC_DEFINE(BENCHMARK, [], [Create a benchmark version])
fi

AC_ARG_WITH(with_debug, [  --with-debug            enable stuff])
if test "$with_debug" == "yes"
then
	AC_MSG_NOTICE([You have enabled debugging info!])
	AC_DEFINE(DEBUG, [], [Enable debugging info])
fi

AC_ARG_WITH(with_clustering, [  --with-clustering            enable stuff])
if test "$with_clustering" == "yes"
then
	AC_MSG_NOTICE([You have enabled input file clustering!])
	AC_DEFINE(CLUSTERED, [], [Enable clustering])
fi

AC_ARG_WITH(verbose, [  --verbose            enable stuff])
if test "$verbose" == "yes"
then
	AC_MSG_NOTICE([You have enabled verbose output!])
	AC_DEFINE(VERBOSE, [2], [Enable verbose output])
else
	AC_DEFINE(VERBOSE, [0], [Disable verbose output])
fi


AC_CONFIG_FILES([Makefile])
AC_OUTPUT
