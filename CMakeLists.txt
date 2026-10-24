cmake_minimum_required(VERSION 3.28)

project(ComplexNumber
    VERSION 1.0
    DESCRIPTION "A Complex Number header-only project."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(ComplexNumber INTERFACE)

target_include_directories(ComplexNumber
    INTERFACE 
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_compile_features(ComplexNumber INTERFACE cxx_std_23)

add_executable(complex_example examples/main.cpp)
target_link_libraries(complex_example PRIVATE ComplexNumber)

include(CTest)

if(BUILD_TESTING)
    add_executable(complex_test tests/complex_test.cpp)
    target_link_libraries(complex_test PRIVATE ComplexNumber)

    add_test(NAME ComplexNumberTest COMMAND complex_test)
endif()