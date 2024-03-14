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

// Secuencia para dispersión cerrada

class StaticSequence : public Sequence {
  public:
    // Constructores
    inline StaticSequence() {}
    inline StaticSequence(int bloq_size) : bloq_size_(bloq_size) {}
    
    // Métodos de la clase
    bool Search(const Key&) const override;
    bool Insert(const Key&) override;
    bool IsFull();

    // Sobrecarga de operadores
    ostream& Print(ostream&) const override;

  private:
    int bloq_size_;
    vector<Key> sequence_;
};