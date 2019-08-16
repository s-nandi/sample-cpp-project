#!/usr/bin/env bash
rm -r *
cmake .. -DCMAKE_TOOLCHAIN_FILE=${vcpkg_path} -DCMAKE_BUILD_TYPE=${BUILD} -DBUILD_TESTS=ON
cmake --build . --config ${BUILD}
ctest -C ${BUILD} --output-on-failure