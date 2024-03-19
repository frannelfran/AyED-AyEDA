#pragma once
#include "../key/key.h"
#include "../sequence/sequence.h"
#include "../dispersion_function/dispersion_function.h"
#include "../exploration_function/exploration_function.h"

using namespace std;

class HashTable {
  public:
    // Desctructor
    virtual void Delete() = 0;

    // Métodos de la clase
    virtual bool Search(const Key&) const = 0;
    virtual bool Insert(const Key&) const = 0;

    friend ostream& operator<<(ostream&, const HashTable&);

  protected:
    int size_;
    DispersionFunction* dispersion_function_;
    vector<Sequence*> table_;
};

// Tabla hash con dispersión abierta

class OpenHashTable : public HashTable {
  public:
    // Constructores
    OpenHashTable(unsigned, DispersionFunction*);

    // Destructor
    void Delete() override;

    // Métodos de la clase
    bool Search(const Key&) const override;
    bool Insert(const Key&) const override;
};

class ClosedHashTable : public HashTable {
  public:
    // Constructores
    ClosedHashTable(unsigned, DispersionFunction*, ExplorationFunction*, unsigned);

    // Destructor
    void Delete() override;

    // Métodos de la clase
    bool Search(const Key&) const override;
    bool Insert(const Key&) const override;

  private:
    int bloq_size_;
    ExplorationFunction* exploration_function_;
};