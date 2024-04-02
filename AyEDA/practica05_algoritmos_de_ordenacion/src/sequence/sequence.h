#pragma once
#include <iostream>
#include <vector>
#include "../key/key.h"
#include "../position/position.h"


using namespace std;

class Sequence {
  public:
    // Constructores
    Sequence() {}
    Sequence(bool show) : show_(show) {}
    // Destructor
    virtual ~Sequence() {}

    // Métodos de la clase
    virtual bool Search(const Key&) const = 0;
    virtual bool Insert(const Key&) = 0;
    virtual bool IsFull() = 0;
    virtual int GetSize() const = 0;
    virtual void Swap(const Position&, const Position&) = 0;

    // Sobrecarga de operadores
    virtual ostream& Print(ostream&) const = 0;
    virtual Key operator[](const Position&) const = 0;

  protected:
    bool show_;
};

// Secuencia para dispersión cerrada

class StaticSequence : public Sequence {
  public:
    // Constructores
    inline StaticSequence() {}
    inline StaticSequence(int bloq_size, bool show) : bloq_size_(bloq_size), Sequence(show) {}
    
    // Métodos de la clase
    bool Search(const Key&) const override;
    bool Insert(const Key&) override;
    bool IsFull() override;
    void Swap(const Position&, const Position&) override;

    // Getters
    inline int GetSize() const override { return sequence_.size(); }

    // Sobrecarga de operadores
    ostream& Print(ostream&) const override;
    Key operator[](const Position&) const override;

  private:
    int bloq_size_;
    vector<Key> sequence_;
};