#!/usr/bin/env bash
set -e
rm -rf bfbs/
rm -rf install/
rm -rf build/
mkdir build/
pushd build 
cmake -DCMAKE_BUILD_KIT='GCC x86_64-linux-gnu' ..
make install
popd 



