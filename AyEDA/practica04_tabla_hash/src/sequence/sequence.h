#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "../key/key.h"

using namespace std;

class Sequence {
  public:
    // Destructor
    virtual ~Sequence() {}

    // Métodos de la clase
    virtual bool Search(const Key&) const = 0;
    virtual bool Insert(const Key&) = 0;
    virtual ostream& Print(ostream&) const = 0;
};

// Secuencia para dispersión abierta

class DinamicSequence : public Sequence {
  public:
    // Constructores
    inline DinamicSequence() {}
    
    // Métodos de la clase
    bool Search(const Key&) const override;
    bool Insert(const Key&) override;

    // Sobrecarga de operadores
    ostream& Print(ostream&) const override;

  private:
    list<Key> sequence_;
};