#pragma once
#include <iostream>
#include <vector>
#include "../key/key.h"
#include "../position/position.h"

using namespace std;

template<class Key>
class Sequence {
 public:
  // Constructores
  Sequence() {}

  // Destructor
  virtual ~Sequence() {}

  // Métodos de la clase
  virtual bool Insert(const Key&) = 0;
  virtual bool IsFull() = 0;
  virtual int GetSize() const = 0;
  virtual void Swap(const Position&, const Position&) = 0;
  virtual void SetKey(const Key&, const Position&) = 0;

  // Sobrecarga de operadores
  virtual ostream& Print(ostream&) const = 0;
  virtual Key operator[](const Position&) const = 0;
};

// Secuencia para dispersión cerrada

template<class Key>
class StaticSequence : public Sequence<Key> {
  public:
    // Constructores
    inline StaticSequence() {}
    inline StaticSequence(int bloq_size) : bloq_size_(bloq_size) {}
    
    // Métodos de la clase
    bool Insert(const Key&) override;
    bool IsFull() override;
    void Swap(const Position&, const Position&) override;

    // Getters
    inline int GetSize() const override { return sequence_.size(); }

    // Setters
    inline void SetKey(const Key& key, const Position& pos) override { sequence_[pos.GetData()] = key; }

    // Sobrecarga de operadores
    ostream& Print(ostream&) const override;
    Key operator[](const Position&) const override;

  private:
    int bloq_size_;
    vector<Key> sequence_;
};

/**
 * @brief Método para insertar una llave
 * @param key Llave a insertar
*/

template<class Key> bool StaticSequence<Key>::Insert(const Key& key) {
  if (IsFull()) {
    return false;
  }
  sequence_.push_back(key);
  return true;
}

/**
 * @brief Método para verificar si la secuencia está llena
 * @return 1 si la secuencia está llena, 0 en caso contrario
*/

template<class Key> bool StaticSequence<Key>::IsFull() {
  return sequence_.size() == bloq_size_;
}

/**
 * @brief Método para intercambiar dos llaves
 * @param pos1 Posición de la primera llave
 * @param pos2 Posición de la segunda llave
*/

template<class Key> void StaticSequence<Key>::Swap(const Position& pos1, const Position& pos2) {
  swap(sequence_[pos1.GetData()], sequence_[pos2.GetData()]);
}

/**
 * @brief Métdodo para obtener una llave
 * @param pos Posición de la llave
 * @return Llave en la posición pos
*/

template<class Key> Key StaticSequence<Key>::operator[](const Position& pos) const {
  return sequence_[pos.GetData()];
}

/**
 * @brief Método para imprimir la secuencia
 * @param os Stream de salida
*/

template<class Key> ostream& StaticSequence<Key>::Print(ostream& os) const {
  for (const auto& k : sequence_) {
    os << k << " ";
  }
  os << endl;
  return os;
}