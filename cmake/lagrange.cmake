#
# Copyright 2022 Adobe
# All Rights Reserved.
#
# NOTICE: Adobe permits you to use, modify, and distribute this file in
# accordance with the terms of the Adobe license agreement accompanying
# it.
#
if(TARGET lagrange::core)
    return()
endif()

include(FetchContent)
FetchContent_Declare(
    lagrange
    GIT_REPOSITORY https://github.com/adobe/lagrange.git
    GIT_TAG v6.5.0
)
FetchContent_MakeAvailable(lagrange)
