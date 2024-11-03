# Our C++ project contains a single executable built from main.cpp
# It uses the definitions in my_library.cpp,  which are defined in the header file my_library.h

# Lets compile the library first

# Now we compile the executable
# We need to tell CMake that we want to build an executable
add_executable(ZipF ZipF_Law.cpp)
add_executable(ZipF2 ZipF_Law_2.cpp)
add_executable(Arabic Arabic.cpp)

target_include_directories(ZipF PUBLIC ${matplotplusplus_SOURCE_DIR}/include)
target_include_directories(ZipF2 PUBLIC ${matplotplusplus_SOURCE_DIR}/include)

target_link_libraries(ZipF PUBLIC matplot)
target_link_libraries(ZipF2 PUBLIC matplot)
