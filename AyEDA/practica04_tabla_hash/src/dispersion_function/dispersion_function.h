#pragma once
#include <iostream>
#include "../nif/nif.h"

using namespace std;

class DispersionFunction {
  public:
    // Constructores
    inline DispersionFunction() {}
    inline DispersionFunction(int size) : size_(size) {}

    // Métodos
    virtual unsigned operator() (const Nif&) const = 0;
  protected:
    int size_;
};

// Clase de dispersión por módulo

class DispersionFunctionMod : public DispersionFunction {
  public:
    // Constructores
    inline DispersionFunctionMod() {}
    inline DispersionFunctionMod(int size) : DispersionFunction(size) {}

    // Métodos
    unsigned operator() (const Nif&) const override;
};

// Clase de dispersión por suma

class DispersionFunctionSum : public DispersionFunction {
  public:
    // Constructores
    inline DispersionFunctionSum() {}
    inline DispersionFunctionSum(int size) : DispersionFunction(size) {}

    // Métodos
    unsigned operator() (const Nif&) const override;
};

// Clase de dispersión aleatoria

class DispersionFunctionRandom : public DispersionFunction {
  public:
    // Constructores
    inline DispersionFunctionRandom() {}
    inline DispersionFunctionRandom(int size) : DispersionFunction(size) {}

    // Métodos
    unsigned operator() (const Nif&) const override;
};