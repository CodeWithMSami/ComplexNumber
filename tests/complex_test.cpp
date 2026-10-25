#include <complex.hpp>

#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>
#include <type_traits>

int main()
{
    //Compile-time checks: the template accepts floating-point types.
    static_assert(std::is_default_constructible_v<Complex<float>>);
    static_assert(std::is_constructible_v<Complex<double>, double, double>);
    static_assert(std::is_same_v<decltype(std::declval<const Complex<double>&>().real()), double>);
    static_assert(std::is_same_v<decltype(std::declval<const Complex<double>&>().imag()), double>);

    //Constructors and accessors
    Complex<double> zero;
    assert(zero.real() == 0.0);
    assert(zero.imag() == 0.0);

    Complex<double> a{3.0, 4.0};
    Complex<double> b{1.0, 2.0};

    assert(a.real() == 3.0);
    assert(a.imag() == 4.0);

    //Setters
    assert(a.setReal(5.0) == 5.0);
    assert(a.setImag(6.0) == 6.0);
    assert(a == Complex<double>(5.0, 6.0));

    //Basic arithmetic
    assert((Complex<double>(3.0, 4.0) + Complex<double>(1.0, 2.0))
           == Complex<double>(4.0, 6.0));
    assert((Complex<double>(3.0, 4.0) - Complex<double>(1.0, 2.0))
           == Complex<double>(2.0, 2.0));
    assert((Complex<double>(3.0, 4.0) * Complex<double>(1.0, 2.0))
           == Complex<double>(-5.0, 10.0));

    //Division: ordinary nonzero divisor only.
    //(3 + 4i) / (1 + 2i) = 2.2 - 0.4i
    const Complex<double> quotient =
        Complex<double>(3.0, 4.0) / Complex<double>(1.0, 2.0);
    assert(std::abs(quotient.real() - 2.2) < 1e-12);
    assert(std::abs(quotient.imag() + 0.4) < 1e-12);

    //Equality and inequality
    assert(Complex<double>(3.0, 4.0) == Complex<double>(3.0, 4.0));
    assert(Complex<double>(3.0, 4.0) != Complex<double>(3.0, 5.0));

    //Compound assignments
    Complex<double> value{3.0, 4.0};
    value += Complex<double>{1.0, 2.0};
    assert(value == Complex<double>(4.0, 6.0));

    value -= Complex<double>{1.0, 2.0};
    assert(value == Complex<double>(3.0, 4.0));

    value *= Complex<double>{1.0, 2.0};
    assert(value == Complex<double>(-5.0, 10.0));

    value = Complex<double>{3.0, 4.0};
    value /= Complex<double>{1.0, 2.0};
    assert(std::abs(value.real() - 2.2) < 1e-12);
    assert(std::abs(value.imag() + 0.4) < 1e-12);

    //Conjugate
    assert(Complex<double>(3.0, 4.0).conj() == Complex<double>(3.0, -4.0));
    assert(Complex<double>(3.0, -4.0).conj() == Complex<double>(3.0, 4.0));

    //Stream output (checks the current formatting contract).
    std::ostringstream output;
    output << Complex<double>(3.0, 4.0);
    assert(output.str() == "3 + 4i");

    //Stream input reads real and imaginary components separated by whitespace.
    std::istringstream input{"7.5 -2.25"};
    Complex<double> parsed;
    input >> parsed;
    assert(input);
    assert(parsed == Complex<double>(7.5, -2.25));

    //Also check that extraction reports invalid input through stream state.
    std::istringstream invalid_input{"not-a-number 2"};
    Complex<double> invalid;
    invalid_input >> invalid;
    assert(!invalid_input);

    std::cout << "All Complex<T> tests passed.\n";
    return 0;
}
