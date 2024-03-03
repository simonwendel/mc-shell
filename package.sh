#!/bin/bash

if [ ! -d "build" ]; then
  mkdir build
fi

START=`pwd`
pushd build
cmake $START
cmake --build . --config MinSizeRel --target all --
cpack --config CPackConfig.cmake
mv *.deb $START
popd
