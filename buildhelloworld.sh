#!/bin/bash

echo "-- Getting libretro-common submodule, if you don't want this, please comment these lines --"
cd libs/libretro-common
git submodule update --init .
cd ../..

# check if compiler is in /opt/mips32-mti-elf/2019.09-03-2/bin/mips-mti-elf-gcc
if [ ! -f "/opt/mips32-mti-elf/2019.09-03-2/bin/mips-mti-elf-gcc" ]; then
    echo "-- Compiler not found in /opt/mips32-mti-elf/2019.09-03-2/bin/mips-mti-elf-gcc --"
    echo "-- Do you want to download the toolchain? y/n --"
    read -r answer
    if [[ "$answer" == "y" || "$answer" == "Y" ]]; then
        echo "-- Downloading toolchain --"
        ./install-toolchain.sh
    else
        echo "-- Please install the toolchain first --"
        exit 1
    fi
fi

echo "-- Copying and renaming bisrv.asd from assets --"
cp assets/os/bisrv.asd bisrv_08_03.asd

echo "-- helloworld make --"
make CONSOLE=hi CORE=helloworld MAKEFILE=-fMakefile.libretro

# make updatelogo ALPHARELEASE=0.10
true