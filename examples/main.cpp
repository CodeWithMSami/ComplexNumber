#include "complex.hpp"

int main() {
    //1. Constructors
    Complex<double> a;
    Complex<double> b(3.0, 4.0);
    Complex<double> c(1.0, 2.0);

    std::cout << "=== Constructors ===\n";
    std::cout << "Default: " << a << '\n';
    std::cout << "b: " << b << '\n';
    std::cout << "c: " << c << "\n\n";

    //2. Accessors
    std::cout << "=== Accessors ===\n";
    std::cout << "Real part of b: " << b.real() << '\n';
    std::cout << "Imaginary part of b: " << b.imag() << "\n\n";

    //3. Setters
    std::cout << "=== Setters ===\n";
    a.setReal(5.0);
    a.setImag(6.0);
    std::cout << "After setting components: " << a << "\n\n";

    //4. Arithmetic operators
    std::cout << "=== Arithmetic ===\n";
    std::cout << "b + c = " << b + c << '\n';
    std::cout << "b - c = " << b - c << '\n';
    std::cout << "b * c = " << b * c << '\n';
    std::cout << "b / c = " << b / c << "\n\n";

    //5. Comparison operators
    std::cout << "=== Comparisons ===\n";
    Complex<double> d(3.0, 4.0);

    std::cout << std::boolalpha;
    std::cout << "b == d: " << (b == d) << '\n';
    std::cout << "b != c: " << (b != c) << "\n\n";

    //6. Compound assignment operators
    std::cout << "=== Compound Assignments ===\n";

    Complex<double> x(3.0, 4.0);
    x += c;
    std::cout << "After += c: " << x << '\n';

    x = b;
    x -= c;
    std::cout << "After -= c: " << x << '\n';

    x = b;
    x *= c;
    std::cout << "After *= c: " << x << '\n';

    x = b;
    x /= c;
    std::cout << "After /= c: " << x << "\n\n";

    //7. Stream input
    std::cout << "=== Stream Input ===\n";
    Complex<double> input;

    std::cout << "Enter real and imaginary parts separated by a space: ";
    if (std::cin >> input)
    {
        std::cout << "You entered: " << input << '\n';
    }
    else
    {
        std::cout << "Invalid input.\n";
    }

    //8. Complex conjugate
    std::cout << "\n=== Conjugate ===\n";
    std::cout << "b: " << b << '\n';
    std::cout << "conj(b): " << b.conj() << '\n';

    
    return 0;
}