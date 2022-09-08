#
# Copyright 2022 Adobe
# All Rights Reserved.
#
# NOTICE: Adobe permits you to use, modify, and distribute this file in
# accordance with the terms of the Adobe license agreement accompanying
# it.
#
include(external/catch2)

file(GLOB TEST_SOURCES "*.h" "*.cpp")
add_executable(foo_tests ${TEST_SOURCES})
target_link_libraries(foo_tests PUBLIC
    foo::lib
    Catch2::Catch2WithMain
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/Extras)
include(CTest)
include(Catch)
catch_discover_tests(foo_tests)
