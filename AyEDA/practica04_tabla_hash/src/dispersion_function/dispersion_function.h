#pragma once
#include <iostream>
#include "../nif/nif.h"

using namespace std;

class DispersionFunction {
  public:
    // Constructores
    inline DispersionFunction() {}
    inline DispersionFunction(int size) : size_(size) {}

    virtual unsigned operator() (const Nif&) const = 0;
  protected:
    int size_;
};

class DispersionFunctionMod : public DispersionFunction {
  public:
    // Constructores
    inline DispersionFunctionMod() {}
    inline DispersionFunctionMod(int size) : DispersionFunction(size) {}

    // Métodos
    unsigned operator() (const Nif&) const override;
};

class DispersionFunctionSum : public DispersionFunction {
  public:
    // Constructores
    inline DispersionFunctionSum() {}
    inline DispersionFunctionSum(int size) : DispersionFunction(size) {}

    // Métodos
    unsigned operator() (const Nif&) const override;
};

class DispersionFunctionRandom : public DispersionFunction {
  public:
    // Constructores
    inline DispersionFunctionRandom() {}
    inline DispersionFunctionRandom(int size) : DispersionFunction(size) {}

    // Métodos
    unsigned operator() (const Nif&) const override;
};