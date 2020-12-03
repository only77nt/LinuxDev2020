#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([M4 Test Script], [0.0], [only77nt@gmail.com])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([const.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_PROG_MAKE_SET

# Checks for libraries.
# FIXME: Replace `main' with a function in `-loutput':
AC_CHECK_LIB([output], [main])
# FIXME: Replace `main' with a function in `-loutput_static':
AC_CHECK_LIB([output_static], [main])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

define(DATE, `date`)dnl
define(SEDCOM, [\/\* COMMENT:: AC_PACKAGE_NAME, AC_PACKAGE_VERSION: DATE \*\/])dnl
define(SEDSTR, [1 s/^\/\* COMMENT::.*\*\//SEDCOM/; t; 1 s/^/SEDCOM\n/;])dnl
define(SEDOPT, ["SEDSTR"])dnl

sed -i -s SEDOPT *.{c,h} | echo SEDCOM
