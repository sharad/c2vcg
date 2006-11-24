# @start 1
# configure.ac -- Process this file with autoconf to produce configure
# @end 1
# Copyright (C) 2006 Sharad Pratap
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.

# @start 2


AC_PREREQ(2.59)
AC_INIT([c2vcg], [1.0b1], [sh4r4d@gmail.com])
AC_CONFIG_HEADERS([config.h:config-h.in])
AC_CONFIG_SRCDIR([src/c2vcg.c])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([0.0.1 gnu])


ISODATE=`date +%Y-%m-%d`
AC_SUBST(ISODATE)


# Checks for programs.
AC_PROG_CC
AC_PROG_AWK
AM_PROG_LEX
AC_PROG_YACC
AC_PROG_RANLIB
AC_PROG_MAKE_SET
AM_GNU_GETTEXT
# Checks for libraries.

# Checks for header files.
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([errno.h stddef.h stdlib.h string.h strings.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T
AC_CHECK_DECLS([sys_siglist])

# Checks for library functions.

# AC_FUNC_ERROR_AT_LINE
AC_HEADER_MAJOR
AC_STRUCT_TM
AC_FUNC_ALLOCA
# AC_FUNC_MALLOC
AC_TYPE_SIGNAL
# AC_FUNC_STAT
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([atexit strdup])
AC_CHECK_HEADER(argp.h,,AC_MSG_ERROR(Cannot continue: argp.h not found))


AC_C_CONST
AC_TYPE_PID_T
AC_TYPE_SIZE_T
AC_C_VOLATILE

C2VCG_WITH_READLINE

C2VCG_VAR_SYS_ERRLIST
C2VCG_VAR_SYS_SIGLIST

AC_CHECK_FUNCS([bzero memset], [break])
AC_CHECK_FUNCS([calloc strchr strrchr])
AC_REPLACE_FUNCS([basename strspn strcspn strerror strsignal waitpid])

save_LIBS="$LIBS"
test x"${with_readline-no}" != xno && LIBS="$LIBS -lreadline"
AC_REPLACE_FUNCS([readline])
AC_CHECK_FUNCS([add_history])
LIBS="$save_LIBS"



AC_CONFIG_FILES([Makefile
		 replace/Makefile
		 c2vcgadt/Makefile
		 src/Makefile
		 doc/Makefile
		 share/Makefile
		 share/c-pgms/Makefile
		 c2vcg.lsm 
		 c2vcg.spec],
		[test -z "$CONFIG_HEADERS" || echo timestamp > \
		c2vcgadt/stamp-h.in])
AC_OUTPUT
# @end 2