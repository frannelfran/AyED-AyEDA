#pragma once
#include <iostream>
#include "../nif/nif.h"
#include "../dispersion_function/dispersion_function.h"

using namespace std;

class ExplorationFunction {
  public:
    // Constructores
    inline ExplorationFunction() {}
    ExplorationFunction(const DispersionFunction&);

    // Métodos
    virtual unsigned operator() (const Nif&, unsigned) const = 0;
  protected:
    const DispersionFunction* dispersion_;
};

// Clase de exploración lineal

class ExplorationLinear : public ExplorationFunction {
  public:
    // Constructores
    inline ExplorationLinear() {}

    // Métodos
    unsigned operator() (const Nif&, unsigned) const override;
};

// Clase de exploración cuadrática

class ExplorationQuadratic : public ExplorationFunction {
  public:
    // Constructores
    inline ExplorationQuadratic() {}

    // Métodos
    unsigned operator() (const Nif&, unsigned) const override;
};

// Clase de exploracion doble

class ExplorationDouble : public ExplorationFunction {
  public:
    // Constructores
    inline ExplorationDouble() {}
    inline ExplorationDouble(const DispersionFunction& dispersion) : ExplorationFunction(dispersion) {}

    // Métodos
    unsigned operator() (const Nif&, unsigned) const override;
};

// Clase de exploración por re-dispersión

class ExplorationReDispersion : public ExplorationFunction {
  public:
    // Constructores
    inline ExplorationReDispersion() {}
    inline ExplorationReDispersion(const DispersionFunction& dispersion) : ExplorationFunction(dispersion) {}

    // Métodos
    unsigned operator() (const Nif&, unsigned) const override;
};
