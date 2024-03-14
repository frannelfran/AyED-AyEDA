#include "sequence.h"

/**
 * @brief Método para buscar una llave
 * @param key Llave a buscar
 * @return 1 si la llave se encuentra, 0 en caso contrario
*/

bool DinamicSequence::Search(const Key& key) const {
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

bool DinamicSequence::Insert(const Key& key) {
  if (Search(key)) {
    return false;
  }
  sequence_.push_back(key);
  return true;
}

/**
 * @brief Método para imprimir la secuencia
 * @param os Stream de salida
*/

ostream& DinamicSequence::Print(ostream& os) const {
  for (const auto& k : sequence_) {
    os << k << " ";
  }
  return os;
}