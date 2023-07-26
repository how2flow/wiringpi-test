bin_PROGRAMS = wpitest

wpitest_SOURCES = \
	gpio.c \
	main.c \
	show.c

wpitest_CFLAGS = \
	-I ../include \
	-I /usr/include/wiringpi2 \
	-I /usr/local/include \
	@EXTRA_CFLAGS@

wpitest_LDADD = \
	@EXTRA_LIBS@
