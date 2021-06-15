cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
file(GLOB src *.cpp *.hpp)

#最適化オプションの設定
set(CMAKE_CXX_FLAGS "-fopenmp -O3 -funroll-loops -mtune=native")
set(CMAKE_CXX_FLAGS "-Wl,-subsystem,windows")#for windows only
project(dekunobou-gui)

add_executable(dekunobou-gui ${src})

#for windows(MinGW)
target_link_libraries(dekunobou-gui -lfreeglut -lglu32 -lopengl32)
#for UNIX
#target_link_libraries(dekunobou-gui -lGL -lGLU -lglut)

set_property(TARGET dekunobou-gui PROPERTY CXX_STANDARD 17)
