#!/bin/bash

git clone https://github.com/lxqt/lxqt.git
cd lxqt
git submodule init
git submodule update --remote --rebase
