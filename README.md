# sample-cpp-project
[![Build Status](https://travis-ci.com/s-nandi/sample-cpp-project.svg?token=3mg9UG8YzFsNX1EyxxCs&branch=master)](https://travis-ci.com/s-nandi/sample-cpp-project)
[![codecov](https://codecov.io/gh/s-nandi/sample-cpp-project/branch/master/graph/badge.svg?token=oC9INVfw3b)](https://codecov.io/gh/s-nandi/sample-cpp-project)
[![Documentation Status](https://readthedocs.org/projects/sample-cpp-project/badge/?version=latest)](https://sample-cpp-project.readthedocs.io/en/latest/?badge=latest)
[![License: Unlicense](https://img.shields.io/badge/license-Unlicense-blue.svg)](http://unlicense.org/)

A C++ project template, utilizing:
* Automatic Formatting ([Clang-Format](https://clang.llvm.org/docs/ClangFormat.html))
* Linting & Static Analysis ([Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/), 
[Include What You Use](https://include-what-you-use.org/),
[Cppcheck](http://cppcheck.sourceforge.net/))
* Sanitizers ([ASAN](https://github.com/google/sanitizers/wiki/AddressSanitizer))
* Unit Testing ([Catch2](https://github.com/catchorg/Catch2))
* Benchmarking ([Catch2](https://github.com/catchorg/Catch2)) 
* Continuous Integration ([Travis CI](https://travis-ci.org/))
* Code Coverage Reporting ([Codecov](https://codecov.io/))
* Documentation Generation & Hosting ([Doxygen](http://www.doxygen.nl/), 
[Sphinx](http://www.sphinx-doc.org/), [Read the Docs](https://readthedocs.org/))

## Prerequisites
To build the library you need:
* [CMake](https://cmake.org/)
* [vcpkg](https://github.com/microsoft/vcpkg) (optional)

To build the documentation, you also need:
* [Doxygen](http://www.doxygen.nl/)
* [Pip](https://pypi.org/project/pip/) (optional)

## Installing dependencies
* If you want to build tests and/or benchmarks, run:
    ```bash
    vcpkg install catch2
    ```
    
    If you did not install vcpkg, you need an alternate method of getting:
    * [Catch2](https://github.com/catchorg/Catch2)

* If you want to build documentation, run:
    ```bash
    pip install sphinx
    pip install sphinx_rtd_theme
    pip install recommonmark
    pip install breathe
    ```
    
    If you do not install Pip, you need an alternate method of getting:
    * [Sphinx](http://www.sphinx-doc.org/)
    * [Sphinx_rtd_theme](https://sphinx-rtd-theme.readthedocs.io/en/stable/)
    * [recommonmark](https://recommonmark.readthedocs.io/en/latest/)
    * [Breathe](https://breathe.readthedocs.io/en/latest/)

## Building
First, clone the repo and create a build folder
```bash
git clone https://github.com/s-nandi/sample-cpp-project.git
cd sample-cpp-project
mkdir build
cd build
```

Then, run
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=/path/to/your/vcpkg.cmake
```
you can pass in`-DBUILD_TESTS=ON`, `-DBUILD_BENCHMARKS=ON`, and `-DBUILD_DOCUMENTATION=ON` to build tests, benchmarks, and/or documentation respectively

And finally, build the project
```bash
cmake --build . --config Release
```

---

In order to run the tests, use the following line: `ctest -C Release --output-on-failure`

To run the benchmarks, go to `build/benches` and run the `benchmarks` executable.

The root documentation file is `build/docs/sphinx/index.html`.

## Setting up for your own project
* You might want to change the language standard (set to C++17 by default) in [CMakeLists.txt](CMakeLists.txt)

* You can modify the compiler flags used in [scripts/cmake/SetProjectCompileOptions.cmake](scripts/cmake/SetProjectCompileOptions.cmake)

* The project and author names must be set manually in [docs/source/conf.py](docs/source/conf.py),
similarly the project name must be set in [CMakeLists.txt](CMakeLists.txt)
(the project name in `conf.py` MUST be identical to the project name in CMakeLists.txt)

* Modify the library's source files in the root [CMakeLists.txt](CMakeLists.txt) file:
```cmake
set(${PROJECT_NAME}_SOURCE_FILES
        # List source files below
        src/library.cpp
        include/sample_cpp_project/library.hpp
        additional source files go here)
```

* List the files that should prompt Sphinx to regenerate documentation when changed, 
by modifying the sphinx target's dependency list in [docs/CMakeLists.txt](docs/CMakeLists.txt):
```cmake
add_custom_target(${SPHINX_TARGET_NAME} ALL
        ...
        # List documentation files below
        source/index.rst
        additional documentation files go here)
```

* Note that only public header files are documented (ie. the `.h/.hpp` files in `include/` but NOT the ones in `/src`)

* You will need to host the project on travis CI, codecov, and Read the Docs yourself.

## Acknowledgment

Ideas were taken from:
* [Doctest's `.travis.yml`](https://github.com/onqtam/doctest/blob/master/.travis.yml)
* [Simon Brand's article on clean c++ documentation](https://devblogs.microsoft.com/cppblog/clear-functional-c-documentation-with-sphinx-breathe-doxygen-cmake/)
