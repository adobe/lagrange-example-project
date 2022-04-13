#
# Copyright 2022 Adobe
# All Rights Reserved.
#
# NOTICE: Adobe permits you to use, modify, and distribute this file in
# accordance with the terms of the Adobe license agreement accompanying
# it.
#

# Include more application dependencies here
include(external/cli11)

file(GLOB APP_SOURCES "*.h" "*.cpp")
add_executable(foo_app ${APP_SOURCES})
target_link_libraries(foo_app PUBLIC
    foo::lib
    lagrange::ui
    CLI11::CLI11
)
