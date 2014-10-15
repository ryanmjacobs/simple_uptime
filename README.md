simple_uptime
=============

A fast, simple uptime command for Linux.
---

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

Copyright (c) 2014 Ryan Jacobs
