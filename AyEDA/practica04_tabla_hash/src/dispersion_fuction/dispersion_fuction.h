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

class DispersionFuctionMod : public DispersionFunction {
  public:
    // Constructores
    inline DispersionFuctionMod() {}
    inline DispersionFuctionMod(int size) : DispersionFunction(size) {}

    // Métodos
    unsigned operator() (const Nif&) const override;
};

class DispersionFuctionSum : public DispersionFunction {
  public:
    // Constructores
    inline DispersionFuctionSum() {}
    inline DispersionFuctionSum(int size) : DispersionFunction(size) {}

    // Métodos
    unsigned operator() (const Nif&) const override;
};

class DispersionFuctionRandom : public DispersionFunction {
  public:
    // Constructores
    inline DispersionFuctionRandom() {}
    inline DispersionFuctionRandom(int size) : DispersionFunction(size) {}

    // Métodos
    unsigned operator() (const Nif&) const override;
};