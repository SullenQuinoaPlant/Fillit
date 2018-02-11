#!/bin/bash

git clone https://github.com/clibs/cmocka.git cmocka_download
mkdir -p cmocka_build
LD_LIBRARY_PATH=$(pwd)/libs
cd cmocka_build
cmake -DCMAKE_INSTALL_PREFIX=$LD_LIBRARY_PATH ../cmocka_download
make
make install
cd ..
rm -rf cmocka_download -v
rm -rf cmocka_build -v
echo "installed in $LD_LIBRARY_PATH :"
ls $LD_LIBRARY_PATH
