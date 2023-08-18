# wiringpi-test

It is a package that helps test pins with [wiringPi](https://github.com/wiringPi).<br>
<br>

If you want to test gpio input/output functions,<br>
Short all 40 pins (excluding voltage and GND) exposed in Target board.<br>

### Requirements & Support

I have completed the basic gpio function.<br>
i2c and spi are thinking about generic testing.<br>
Because they are depending on the device they connect to.

```
<Support Board>
- odroid
- raspberry pi

<Support Functions>
- gpio
- i2c
- spi

<Requirements>
- libwiringpi2
- libwiringpi-dev
- wiringpi
```

### Usage in Ubuntu/Debian

Ubuntu/Devian Images support as a package.<br>
raspberry OS is not yet supported.<br>
<br>
Install
```
$ sudo add-apt-repository ppa:how2flow/ppa
$ sudo apt update
$ sudo apt install wiringpi-test
```

Run
```
$ wiringpi-test [ --gpio | --help | --i2c | --spi ]
```

### Usage in Rasbperry OS

This method is not only for Rasbperry OS, which is not yet supported as a package,<br>
but also for testing the wiringpi that has been personally changed.<br>
<br>
Install
```
$ git clone https://github.com/how2flow/wiringpi-test
$ cd wiringpi-test/test
$ make
```

Run
```
$ ./test [gpio | i2c | spi]
```

### contact

e-mail: steve@how2flow.net
