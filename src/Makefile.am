bin_PROGRAMS = wpitest

# Warning!
# You must order the source files or the libraries to be linked.
# If you simply array by spelling, you'll encounter errors.
wpitest_SOURCES = \
	gpio.c \
	i2c.c \
	spi.c \
	main.c \
	show.c

wpitest_CFLAGS = \
	-I ../include \
	-I /usr/include/wiringpi2 \
	-I /usr/local/include \
	@EXTRA_CFLAGS@

wpitest_LDADD = \
	@EXTRA_LIBS@
