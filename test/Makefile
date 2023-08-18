CC = gcc
SRCS = $(wildcard ../src/*.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

CFLAGS = -g
CFLAGS += -I ../include
CFLAGS += -I /usr/local/include
CFLAGS += -I /usr/include/wiringpi2
LIBS = -lwiringPi -lwiringPiDev -lm -lpthread -lrt -lcrypt
BIN= test

all: $(BIN)

$(BIN): $(OBJS)
	@$(CC) -o $@ $(OBJS) $(CFLAGS) $(LIBS)

%.o: %.c
	@$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

clean:
	@rm -rf $(BIN)
