simple_uptime
=============

####A fast, simple uptime command for Linux.

Background
----------
I needed a *very, very* lightweight uptime program for my
[dwm statusbar](https://github.com/ryanmjacobs/ryans_dotfiles/blob/master/.bin/dwmstatus#L19);
and, at just a mere **37** standard lines of code, this program fits the task
perfectly. The whole source code can be found right [here](https://github.com/ryanmjacobs/simple_uptime/blob/master/src/simple_uptime.c)!

Usage
-----
There's no arguments, no help, no nothing. Just simply uptime.
```
$ simple_uptime
3 days, 03:06:05
```

Build & Install
---------------

#### Arch Linux
The build and install process has been streamlined for Arch Linux users.
```
./build_abs.sh build
pacman -U simple_uptime*.pkg.tar.xz
./build_abs.sh clean
```

#### Other Distos
```
make
make install
```

Uninstall
---------

#### Arch Linux
```
pacman -Rns simple_uptime
```

#### Other Distros
```
make uninstall
```

License
-------

MIT License - see LICENSE

Copyright (c) 2015 Ryan Jacobs
