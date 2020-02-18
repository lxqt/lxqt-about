#!/bin/bash

find lxqt -name .git -printf "%h\n" | xargs -n1 -i cp -v .mailmap {}
