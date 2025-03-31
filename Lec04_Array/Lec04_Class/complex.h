#pragma once
#include <cstdio>
#include <cstring>

class Complex {
    double real;
    double imag;

public:
    // Set the real and imaginary parts of the complex number
    void set(double r, double i) {
        real = r;
        imag = i;
    }

    // Read input for complex number
    void read(const char* msg = "복소수 = ") {
        printf("%s", msg);
        scanf_s("%lf %lf", &real, &imag); // Use scanf for portability
    }

    // Print the complex number
    void print(const char* msg = "복소수 = ") const {
        printf("%s %4.2f + %4.2fi\n", msg, real, imag);
    }

    // Add two complex numbers and store the result in the current instance
    void add(const Complex& a, const Complex& b) {
        real = a.real + b.real;
        imag = a.imag + b.imag;
    }
};
