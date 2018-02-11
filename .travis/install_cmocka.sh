#!/bin/bash

git clone https://github.com/clibs/cmocka.git cmocka_download
mkdir -p cmocka_build
LD_LIBRARY_PATH=$(pwd)/libs
cd cmocka_build
cmake -DCMAKE_INSTALL_PREFIX=$LD_LIBRARY_PATH ../cmocka_download
make
make install
cd ..
cp cmocka_download/include/cmocka.h $LD_LIBRARY_PATH
rm -rf cmocka_download -v
rm -rf cmocka_build -v
ls $LD_LIBRARY_PATH
