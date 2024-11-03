cmake_minimum_required(VERSION 3.10)
project( session_17 VERSION 1.0 LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable Testing
enable_testing()


# Include the directories for headers and source
include_directories(include)
add_subdirectory(homework)
add_subdirectory(docs)


# Include FetchContent for downloading Matplot++
include(FetchContent)

FetchContent_Declare(
    matplotplusplus
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
    GIT_TAG origin/master # You can specify a release tag instead of "origin/master"
)

# Download and make Matplot++ available
FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
    FetchContent_Populate(matplotplusplus)
    add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

