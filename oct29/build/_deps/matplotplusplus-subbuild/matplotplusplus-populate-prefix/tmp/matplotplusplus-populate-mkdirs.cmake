# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/Users/salehabdelrahman/Desktop/oct29/build/_deps/matplotplusplus-src")
  file(MAKE_DIRECTORY "/Users/salehabdelrahman/Desktop/oct29/build/_deps/matplotplusplus-src")
endif()
file(MAKE_DIRECTORY
  "/Users/salehabdelrahman/Desktop/oct29/build/_deps/matplotplusplus-build"
  "/Users/salehabdelrahman/Desktop/oct29/build/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix"
  "/Users/salehabdelrahman/Desktop/oct29/build/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/tmp"
  "/Users/salehabdelrahman/Desktop/oct29/build/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp"
  "/Users/salehabdelrahman/Desktop/oct29/build/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src"
  "/Users/salehabdelrahman/Desktop/oct29/build/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/salehabdelrahman/Desktop/oct29/build/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/salehabdelrahman/Desktop/oct29/build/_deps/matplotplusplus-subbuild/matplotplusplus-populate-prefix/src/matplotplusplus-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
