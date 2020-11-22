# lxqt-about

## Overview

`lxqt-about` is a dialogue window providing information about LXQt and the
system it's running on.

## Installation

### Sources

The only runtime dependency is [liblxqt](https://github.com/lxqt/liblxqt).
CMake is needed to build as well as optionally Git to pull latest VCS checkouts.

Code configuration is handled by CMake. CMake variable `CMAKE_INSTALL_PREFIX`
will normally have to be set to `/usr`.

To build run `make`, to install `make install` which accepts variable `DESTDIR`
as usual.

### Binary packages

The library is provided by all major Linux distributions like Arch Linux,
Debian, Fedora and openSUSE. Just use your package manager to search for string
`lxqt-about`.

### Translation

Translations can be done in [LXQt-Weblate](https://translate.lxqt-project.org/projects/lxqt-desktop/lxqt-about/)

<a href="https://translate.lxqt-project.org/projects/lxqt-desktop/lxqt-about/">
<img src="https://translate.lxqt-project.org/widgets/lxqt-desktop/-/lxqt-about/multi-auto.svg" alt="Translation status" />
</a>

