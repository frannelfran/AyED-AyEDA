#include "sequence.h"

/**
 * @brief Método para buscar una llave
 * @param key Llave a buscar
 * @return 1 si la llave se encuentra, 0 en caso contrario
*/

bool StaticSequence::Search(const Key& key) const {
  for (auto k : sequence_) {
    if (k == key) {
      return true;
    }
  }
  return false;
}

/**
 * @brief Método para insertar una llave
 * @param key Llave a insertar
*/

bool StaticSequence::Insert(const Key& key) {
  if (Search(key) || IsFull()) {
    return false;
  }
  sequence_.push_back(key);
  return true;
}

/**
 * @brief Método para verificar si la secuencia está llena
 * @return 1 si la secuencia está llena, 0 en caso contrario
*/

bool StaticSequence::IsFull() {
  return sequence_.size() == bloq_size_;
}

/**
 * @brief Métdodo para obtener una llave
 * @param pos Posición de la llave
 * @return Llave en la posición pos
*/

Key StaticSequence::operator[](const Position& pos) const {
  return sequence_[pos.GetData()];
}

/**
 * @brief Método para imprimir la secuencia
 * @param os Stream de salida
*/

ostream& StaticSequence::Print(ostream& os) const {
  for (const auto& k : sequence_) {
    os << k << " ";
  }
  os << endl;
  return os;
}