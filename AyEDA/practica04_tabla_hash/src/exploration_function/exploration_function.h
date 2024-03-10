#pragma once
#include <iostream>
#include "../nif/nif.h"
#include "../dispersion_function/dispersion_function.h"

using namespace std;

class ExplorationFunction {
  public:
    // Constructores
    inline ExplorationFunction() {}
    inline ExplorationFunction(const Nif& clave, unsigned intento) : clave_(clave), intento_(intento) {}

    // Métodos
    virtual unsigned operator() (const Nif&, unsigned) const = 0;
    
  protected:
    Nif clave_;
    unsigned intento_;
};

// Clase de exploración lineal

class ExplorationLinear : public ExplorationFunction {
  public:
    // Constructores
    inline ExplorationLinear() {}
    inline ExplorationLinear(const Nif& clave, unsigned intento) : ExplorationFunction(clave, intento) {}

    // Métodos
    unsigned operator() (const Nif&, unsigned) const override;
};

// Clase de exploración cuadrática

class ExplorationQuadratic : public ExplorationFunction {
  public:
    // Constructores
    inline ExplorationQuadratic() {}
    inline ExplorationQuadratic(const Nif& clave, unsigned intento) : ExplorationFunction(clave, intento) {}

    // Métodos
    unsigned operator() (const Nif&, unsigned) const override;
};

// Clase de exploracion doble

class ExplorationDouble : public ExplorationFunction {
  public:
    inline ExplorationDouble(const DispersionFunction* dispersion) : dispersion_(dispersion) {}

    // Métodos
    unsigned operator() (const Nif&, unsigned) const override;

  private:
    const DispersionFunction* dispersion_;
};

// Clase de exploración por re-dispersión

class ExplorationReDispersion : public ExplorationFunction {
  public:
    // Constructores
    inline ExplorationReDispersion() {}
    inline ExplorationReDispersion(const Nif& clave, unsigned intento) : ExplorationFunction(clave, intento) {}

    // Métodos
    unsigned operator() (const Nif&, unsigned) const override;
};
