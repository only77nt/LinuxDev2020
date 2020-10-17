#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Autotools Task], [0.01], [only77nt@gmail.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([Task.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AC_CHECK_FUNCS([setlocale])

# Checks for libraries.
AC_CHECK_LIB([ncursesw], [initscr], [], [AC_MSG_ERROR([Curses is needed])])
AC_CHECK_LIB([pcre2-8], [pcre2_code_free_8], [], [AC_MSG_ERROR([Could not find pcre2-8 library])])

# Checks for header files.
AC_CHECK_HEADERS([locale.h], [], [AC_MSG_ERROR([Could not find locale.h header])])
AC_CHECK_HEADERS([string.h], [], [AC_MSG_ERROR([Could not find string.h header])])
AC_CHECK_HEADERS([ncurses.h], [], [AC_MSG_ERROR([Could not find ncurses.h header])])
AC_CHECK_HEADER([pcre2.h], [], [AC_MSG_ERROR([Could not find pcre2.h header])],
    [#define PCRE2_CODE_UNIT_WIDTH 0
     #include <pcre2.h>
    ])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_ARG_ENABLE([utf],
	AS_HELP_STRING([--without-utf], [Disable UTF recognition]))
	
AS_IF([test "x$with_utf" != "xno"], [
	AC_DEFINE(UTF,[],[UTF recognition])
])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
