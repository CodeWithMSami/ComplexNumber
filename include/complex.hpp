#pragma once

//Headers
#include <concepts>
#include <iostream>

//Declarations
template <typename T>
    requires std::floating_point<T>
class Complex;

template <typename T>
    requires std::floating_point<T>
std::ostream& operator<<(std::ostream& os, const Complex<T>& obj);

template <typename T>
    requires std::floating_point<T>
std::istream& operator>>(std::istream& is, Complex<T>& obj);

//Definations
template <typename T>
    requires std::floating_point<T>
class Complex
{
public:
    // Constructors
    Complex() = default;
    Complex(T real, T imag) : m_real{real}, m_imag{imag} {}

    // Accessors
    // Real parts
    T real() const
    {
        return this->m_real;
    }

    // Imag part
    T imag() const
    {
        return this->m_imag;
    }

    // Setters
    // Real parts
    T setReal(T real)
    {
        this->m_real = real;
        return this->m_real;
    }

    // Imag part
    T setImag(T imag)
    {
        this->m_imag = imag;
        return this->m_imag;
    }

    // Arithmatics
    //  +,-,*,/
    Complex operator+(const Complex &_other) const
    {
        return Complex(this->m_real + _other.m_real, this->m_imag + _other.m_imag);
    }

    Complex operator-(const Complex &_other) const
    {
        return Complex(this->m_real - _other.m_real, this->m_imag - _other.m_imag);
    }

    Complex operator*(const Complex &_other) const
    {
        T a = this->m_real, b = this->m_imag, c = _other.m_real, d = _other.m_imag;
        return Complex((a * c) - (b * d), (a * d) + (b * c));
    }

    Complex operator/(const Complex &_other) const
    {
        T a = this->m_real, b = this->m_imag, c = _other.m_real, d = _other.m_imag;
        return Complex(((a * c) + (b * d)) / ((c * c) + (d * d)), ((b * c) - (a * d)) / ((c * c) + (d * d)));
    }

    // Comparison
    //==,!=
    bool operator==(const Complex &_other) const
    {
        return (this->m_real == _other.m_real) && (this->m_imag == _other.m_imag);
    }

    bool operator!=(const Complex &_other) const
    {
        return (this->m_real != _other.m_real) || (this->m_imag != _other.m_imag);
    }

    // Compound Assignments
    //  +=, -=, *=, /=
    Complex &operator+=(const Complex &_other)
    {
        this->m_real += _other.m_real;
        this->m_imag += _other.m_imag;
        return *this;
    }

    Complex &operator-=(const Complex &_other)
    {
        this->m_real -= _other.m_real;
        this->m_imag -= _other.m_imag;
        return *this;
    }

    Complex &operator*=(const Complex &_other)
    {
        T new_real = (this->m_real * _other.m_real) - (this->m_imag * _other.m_imag);
        T new_imag = (this->m_real * _other.m_imag) + (this->m_imag * _other.m_real);
        this->m_real = new_real;
        this->m_imag = new_imag;
        return *this;
    }

    Complex &operator/=(const Complex &_other)
    {
        T denom = (_other.m_real * _other.m_real) + (_other.m_imag * _other.m_imag);
        T new_real =  ((this->m_real * _other.m_real) + (this->m_imag * _other.m_imag)) / denom;
        T new_imag =  ((this->m_imag * _other.m_real) - (this->m_real * _other.m_imag)) / denom;
        this->m_real = new_real;
        this->m_imag = new_imag;
        return *this;
    }

    //I/O streams
    friend std::ostream &operator<< <T>(std::ostream &os, const Complex<T> &obj);
    friend std::istream &operator>> <T>(std::istream &is, Complex<T> &obj);

    //Conjugate
    Complex<T> conj() const {
        return Complex<T>(this->m_real, -(this->m_imag));
    }

private:
    T m_real{};
    T m_imag{};
};

// Stream Output
template<typename T>
requires std::floating_point<T>
std::ostream &operator<<(std::ostream &os, const Complex<T> &obj)
{
    os << obj.real() << (obj.imag()>0?" + ":" ") << obj.imag() << "i";
    return os;
}

// Stream Input
template<typename T>
requires std::floating_point<T>
std::istream &operator>>(std::istream &is, Complex<T> &obj)
{
    is >> obj.m_real >> obj.m_imag;
    return is;
}