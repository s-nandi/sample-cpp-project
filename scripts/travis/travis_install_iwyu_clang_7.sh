#!/usr/bin/env bash
cd ${TRAVIS_BUILD_DIR}
git clone https://github.com/include-what-you-use/include-what-you-use.git
cd include-what-you-use
git checkout clang_7.0
mkdir build && cd build
cmake -G "Unix Makefiles" -DCMAKE_PREFIX_PATH=/usr/lib/llvm-7 ..
cmake --build .