#
# Copyright 2022 Adobe
# All Rights Reserved.
#
# NOTICE: Adobe permits you to use, modify, and distribute this file in
# accordance with the terms of the Adobe license agreement accompanying
# it.
#
cmake_minimum_required(VERSION 3.20)

# Replace all instances of "foo" with your project name
project(Foo)

# Change "FOO" to your project name
option(FOO_BUILD_APP           "Build your test application" ON)
option(FOO_BUILD_TESTS         "Build your tests"            ON)
option(FOO_BUILD_DOCUMENTATION "Build Doxygen documentation" OFF)

list(PREPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Include the Lagrange library (only importing lagrange::core for now)
include(lagrange) # Note: Lagrange's version in `cmake/lagrange.cmake` might be old, update if needed.

# Import additional Lagrange modules lagrange::ui and lagrange::io
lagrange_include_modules(ui io)

# We can also include dependencies from Lagrange's .cmake files
FetchContent_GetProperties(lagrange)
list(PREPEND CMAKE_MODULE_PATH ${lagrange_SOURCE_DIR}/cmake/recipes)

# Include more core library dependencies here

# Core library
file(GLOB_RECURSE LIB_SOURCES
    "include/foo/*.h"
    "src/*.cpp"
)
add_library(foo_lib "${LIB_SOURCES}")
add_library(foo::lib ALIAS foo_lib)

# Include headers
target_include_directories(foo_lib PUBLIC include)

# Direct dependencies
target_link_libraries(foo_lib PUBLIC
    lagrange::core
)

# Compile definitions
target_compile_definitions(foo_lib PUBLIC _USE_MATH_DEFINES)
target_compile_definitions(foo_lib PUBLIC NOMINMAX)

# C++ standard
target_compile_features(foo_lib PUBLIC cxx_std_17)


# Application
if(FOO_BUILD_APP)
    add_subdirectory(app)
endif()

# Tests
if(FOO_BUILD_TESTS)
    include(CTest)
    add_subdirectory(tests)
endif()

# Documentation
if(FOO_BUILD_DOCUMENTATION)
    add_subdirectory(docs)
endif()
