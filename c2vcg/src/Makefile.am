## Makefile.am -- Process this file with automake to produce Makefile.in
## Copyright (C) 2006 Sharad Pratap
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2, or (at your option)
## any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
## MA 02110-1301, USA.


### Makefile.am --- 

## Author: s@large.net
## Version: $Id$
## Keywords: 
## X-URL: 


MAINTAINERCLEANFILES = Makefile.in

INCLUDES	= -I$(top_builddir)/ -I$(top_srcdir)/ \
		-I$(top_builddir)/c2vcgadt -I$(top_srcdir)/c2vcgadt



## Sort this problem of READLINE.

## if WITH_READLINE
## LIBADD_READLINE = -lreadline
## else
## LIBADD_READLINE =
## endif

noinst_HEADERS	= c2vcg.h
BUILT_SOURCES = gram.y

AM_YFLAGS    = -d 


bin_PROGRAMS = c2vcg
c2vcg_SOURCES = argopt.c c2vcg.c memmgm.c output.c gram.y scan.l 
c2vcg_LDADD = $(top_srcdir)/c2vcgadt/libc2vcgadt.a \
		$(top_builddir)/replace/libreplace.a $(LIBADD_READLINE)


EXTRA_DIST    = c2vcg.h  gram.h  memmgm.h  output.h

## EXTRA_DIST = argopt.c c2vcg.c memmgm.c output.c c2vcg.h memmgm.h output.h scan.l gram.y semantic.cache



### Makefile.am ends here
