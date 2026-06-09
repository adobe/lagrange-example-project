/*
 * Copyright 2022 Adobe
 * All Rights Reserved.
 *
 * NOTICE: Adobe permits you to use, modify, and distribute this file in
 * accordance with the terms of the Adobe license agreement accompanying
 * it.
 */
#include <foo/foo.h>

#include <lagrange/SurfaceMesh.h>

namespace foo {

int foo_add(int a, int b)
{
    lagrange::SurfaceMesh32f mesh;
    return a + b;
}

} // namespace foo
