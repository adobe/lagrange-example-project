/*
 * Copyright 2022 Adobe
 * All Rights Reserved.
 *
 * NOTICE: Adobe permits you to use, modify, and distribute this file in
 * accordance with the terms of the Adobe license agreement accompanying
 * it.
 */
#pragma once

namespace foo {

///
/// This is a class. Second sentence will be used as a long class description.
///
class Bar
{
public:
    ///
    /// Gets the variable.
    ///
    /// @return     The variable.
    ///
    int get_variable() const;

    ///
    /// Sets the variable.
    ///
    /// @param[in]  value  The value.
    ///
    void set_variable(int value);

protected:
    /// Internal variable, initialized to 0.
    int m_variable = 0;
};

} // namespace foo
