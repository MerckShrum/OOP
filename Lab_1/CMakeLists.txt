cmake_minimum_required(VERSION 3.30)
project(Lab_1 C)

set(CMAKE_C_STANDARD 11)

# Use the package PkgConfig to detect GTK+ headers/library files
FIND_PACKAGE(PkgConfig REQUIRED)
pkg_check_modules (GTK4 REQUIRED gtk4)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
INCLUDE_DIRECTORIES(${GTK4_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK4_LIBRARY_DIRS})

message(STATUS "GTK4 include dirs: ${GTK4_INCLUDE_DIRS}")

# Add other flags to the compiler
ADD_DEFINITIONS(${GTK4_CFLAGS_OTHER})

add_executable(Lab_1 src/main.c
        src/app.c
        inc/app.h
        inc/action.h
        src/action.c
        inc/errors.h
        src/processing.c
        inc/processing.h
        inc/scene.h
        src/scene.c
        inc/wire-frame_model.h
        inc/camera.h
        inc/canvas.h
        src/canvas.c)
target_link_libraries(Lab_1 PRIVATE  ${GTK4_LIBRARIES})