# wiringpi-test

It is a package that helps test wiringpi and target board.

### Requirements

```
- libwiringpi2
- libwiringpi-dev
- wiringpi
```

### Circuit

gpio
```
Short all 40 pins (excluding voltage and GND) exposed in SBC.
```

i2c
```
There is no special case.
```

spi
```
There is no special case.
```

### Usage With apt package

Install
```
$ sudo add-apt-repository ppa:how2flow/ppa
$ sudo apt update
$ sudo apt install wiringpi-test
```

Usage
```
$ wiringpi-test [ --gpio | --help | --i2c | --spi ]
```

### Usage With Git source

Install
```
$ git clone https://github.com/how2flow/wiringpi-test
$ cd wiringpi-test
$ sudo ./autogen.sh
$ sudo ./configure
$ sudo make
$ sudo make install
```

Usage
```
$ wiringpi-test [ --gpio | --help | --i2c | --spi ]
```

### Supports

Board
```
- odroid
- raspberry pi
```

Pin
```
- gpio
- i2c
- spi
```

### contact

e-mail: steve@how2flow.net
