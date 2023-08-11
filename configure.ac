#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([wiringpi-test], [3.0], [steve@how2flow.net])
AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_HEADERS([config.h])
AC_SUBST([EXTRA_CFLAGS], "-Wall -Werror")
AC_SUBST([EXTRA_LIBS], "-lwiringPi -lwiringPiDev -lm -lpthread -lrt -lcrypt")

AM_INIT_AUTOMAKE([foreign])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for macros.
AC_CONFIG_MACRO_DIRS([m4])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([pthread.h stdio.h stdlib.h string.h time.h unistd.h wiringPi.h wiringPiI2C.h wiringPiSPI.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CONFIG_FILES([
  Makefile
  src/Makefile])

AC_OUTPUT
