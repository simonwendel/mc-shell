#!/bin/bash

if [ ! -d "build" ]; then
  mkdir build
fi

pushd build
cmake ..
cmake --build . --config Release
popd
