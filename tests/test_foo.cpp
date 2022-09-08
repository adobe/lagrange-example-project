/*
 * Copyright 2022 Adobe
 * All Rights Reserved.
 *
 * NOTICE: Adobe permits you to use, modify, and distribute this file in
 * accordance with the terms of the Adobe license agreement accompanying
 * it.
 */
#include <foo/foo.h>
#include <catch2/catch_test_macros.hpp>

TEST_CASE("test foo")
{
    REQUIRE(foo::foo_add(1, 2) == 3);
}
