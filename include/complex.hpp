#pragma once

#include <concepts>
#include <iostream>

template <typename T>
    requires std::floating_point<T>
class Complex{
    public:
        // Constructors

        //Accessors
        //Real & Img parts

        //Arithmatics
        // +,-,*,/,%

        //Comparison

        //Compound Assignments
        // +=, -=, *=, /=

        //Stream Output
        //Stream Input

        //Increment
        //Decrement

    private:
        T m_real{};
        T m_imag{};
};