# ComplexNumber

A lightweight, header-only C++23 library for working with complex numbers using modern C++ features.

**ComplexNumber** is a personal C++ project focused on template programming, operator overloading, type safety, and clean library design.

## Features

- **Header-only:** Easy to integrate into existing C++ projects.
- **C++23:** Uses modern C++ language features.
- **Template-based:** Supports floating-point types such as `float`, `double`, and `long double`.
- **Operator overloading:** Planned support for natural arithmetic operations.
- **Type constraints:** Uses C++ concepts to restrict supported numeric types.
- **CMake integration:** Simple, standardized build configuration.
- **Testing:** CTest integration for automated tests.
- **Compiler support:** Designed for compatible Clang and GCC toolchains.

> Note: Features described as planned should be marked complete as they are implemented and tested.

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

Replace the repository URL if you publish the project under a different name or account.

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

The example and test source files must be implemented before these targets can build successfully.

## Library Usage

Include the library header in your C++ project:

```cpp
#include <complex.hpp>
```

The header is exposed through the CMake target `ComplexNumber`. Link your executable against this target to inherit the library's include directory and C++23 requirement.

The exact class API and supported operations will be documented here as the implementation develops.

## Development Goals

- [ ] Implement the templated `Complex` class.
- [ ] Add constructors and accessors.
- [ ] Implement arithmetic operators.
- [ ] Implement compound assignment operators.
- [ ] Add equality comparisons.
- [ ] Add stream output support.
- [ ] Handle division-by-zero cases.
- [ ] Add unit tests and edge-case coverage.
- [ ] Document the public API with examples.
- [ ] Add continuous integration with GitHub Actions.

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

*Built as a modern C++ learning and showcase project.*
