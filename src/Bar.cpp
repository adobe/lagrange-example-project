/*
 * Copyright 2022 Adobe
 * All Rights Reserved.
 *
 * NOTICE: Adobe permits you to use, modify, and distribute this file in
 * accordance with the terms of the Adobe license agreement accompanying
 * it.
 */
#include <foo/Bar.h>

#include <cassert>

namespace foo {

int Bar::get_variable() const
{
    return m_variable;
}

void Bar::set_variable(int value)
{
    // Perform additional checks here.
    assert(value >= 0);
    m_variable = value;
}

} // namespace foo
