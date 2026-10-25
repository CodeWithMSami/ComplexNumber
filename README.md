# ComplexNumber

A lightweight, header-only C++23 library for working with complex numbers using modern C++ features.

**ComplexNumber** is a personal C++ project focused on template programming, operator overloading, type safety, and clean library design.

## Features

- **Header-only:** Easy to integrate into existing C++ projects.
- **C++23:** Uses modern C++ language features.
- **Template-based:** Supports floating-point types such as `float`, `double`, and `long double`.
- **Operator overloading:** Supports addition, subtraction, multiplication, and division of complex numbers.
- **Compound assignment:** Supports `+=`, `-=`, `*=`, and `/=`.
- **Type constraints:** Uses the `std::floating_point` concept to restrict supported types.
- **Comparison operators:** Supports equality (`==`) and inequality (`!=`).
- **Accessors and setters:** Provides access to and modification of real and imaginary components.
- **Stream operators:** Supports input (`>>`) and output (`<<`).
- **Complex conjugate:** Provides a `conj()` member function.
- **CMake integration:** Supports configuration and builds through CMake presets.
- **Testing:** Includes a test source file and CTest integration.
- **Compiler support:** Configured for Clang and GCC toolchains.

> Note: Division by zero and extreme floating-point values are not explicitly handled. Stream output formatting for negative imaginary components can also be improved.

## Project Structure

```text
ComplexNumber/
├── include/
│   └── complex.hpp
├── examples/
│   └── main.cpp
├── tests/
│   └── complex_test.cpp
├── .gitignore
├── CMakeLists.txt
├── CMakePresets.json
├── LICENSE
└── README.md
```

## Requirements

- A C++23-compatible compiler:
  - Clang
  - GCC
- CMake 3.28 or newer
- Ninja build system

## Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/CodeWithMSami/ComplexNumber.git
cd ComplexNumber
```

### 2. Configure the project

Configure using the Clang Debug preset:

```bash
cmake --preset clang-debug
```

Alternatively, use the GCC Release preset:

```bash
cmake --preset gcc-release
```

### 3. Build

For Clang:

```bash
cmake --build --preset clang-debug
```

For GCC:

```bash
cmake --build --preset gcc-release
```

### 4. Run tests

```bash
ctest --preset clang-debug
```

The test source covers constructors, accessors, setters, arithmetic operators, compound assignments, comparisons, stream operations, and complex conjugation. Division tests currently cover ordinary, nonzero divisors.

## Library Usage

Include the library header in your C++ project:

```cpp
#include <complex.hpp>
```

The `Complex<T>` class provides constructors, accessors, setters, arithmetic and compound assignment operators, equality comparisons, stream input/output, and complex conjugation.

The header is intended to be exposed through the CMake target `ComplexNumber`, allowing consuming targets to inherit its include directory and C++23 requirement.

## Development Goals

- [x] Implement the templated `Complex<T>` class.
- [x] Add constructors and accessors.
- [x] Implement arithmetic operators.
- [x] Implement compound assignment operators.
- [x] Add equality comparisons.
- [x] Add stream input and output support.
- [x] Implement complex conjugation.
- [x] Add an example program and test source.

## Design Philosophy

The project aims to demonstrate:

- Modern C++23 programming.
- Generic programming with templates and concepts.
- Operator overloading and const correctness.
- Reusable header-only library design.
- CMake-based build management.
- Testing and documentation practices.

## Contributing

Suggestions, bug reports, and improvements are welcome. Please open an issue to discuss substantial changes before submitting a pull request.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

## Author

**CodeWithMSami**

GitHub: [@CodeWithMSami](https://github.com/CodeWithMSami)

---

*Built as a modern C++ showcase project.*
