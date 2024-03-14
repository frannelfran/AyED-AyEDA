#pragma once
#include "../key/key.h"
#include "../dispersion_function/dispersion_function.h"

using namespace std;

class ExplorationFunction {
  public:
    virtual unsigned operator()(const Key&, unsigned) const = 0;
};

// Clase de exploración lineal

class LinearExploration : public ExplorationFunction {
  public:
    unsigned operator()(const Key&, unsigned) const override;
};

// Clase de exploración cuadrática

class QuadraticExploration : public ExplorationFunction {
  public:
    unsigned operator()(const Key&, unsigned) const override;
};

// Clase de exploración por doble dispersión

class DoubleDispersionExploration : public ExplorationFunction {
  public:
    inline DoubleDispersionExploration(const DispersionFunction* dispersion_function) : dispersion_function_(dispersion_function) {}

    unsigned operator()(const Key&, unsigned) const override;

  private:
    const DispersionFunction* dispersion_function_;
};

// Clase de exploración por re-dispersión

class ReDispersionExploration : public ExplorationFunction {
  public:
    inline ReDispersionExploration(int table_size) : table_size_(table_size) {}
    
    unsigned operator()(const Key&, unsigned) const override;
  private:
    int table_size_;
};