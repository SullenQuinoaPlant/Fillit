#!/bin/bash

git clone -b the_lib --single-branch https://github.com/SullenQuinoaPlant/Libft.git libft
cd libft
make
cp libft.a $INSTALL_HERE"/lib"
cp libft.h $INSTALL_HERE"/include"
cd ..
rm -rf libft/

