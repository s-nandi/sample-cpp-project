#!/usr/bin/env bash
if ! [[ -d ${TRAVIS_BUILD_DIR}/vcpkg/scripts ]]; then
    cd $TRAVIS_BUILD_DIR
    git clone https://github.com/microsoft/vcpkg && cd vcpkg
    if [[ "${TRAVIS_OS_NAME}" == "linux" ]] || [[ "${TRAVIS_OS_NAME}" == "osx" ]]; then
        ./bootstrap-vcpkg.sh
    else
        ./bootstrap-vcpkg.bat
    fi
    ./vcpkg integrate install
fi