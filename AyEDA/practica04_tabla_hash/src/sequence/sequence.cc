#include "sequence.h"

/**
 * @brief Constructor de la clase DinamicSequence
 * @param size Tamaño de la secuencia
*/

DinamicSequence::DinamicSequence(int size) {
  sequence_.resize(size);
}

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
  if (Search(key)) { // Insertar si se encuentra un sinónimo
    auto posicion = find(sequence_.begin(), sequence_.end(), key); // Buscar la posición de la llave
    sequence_.insert(posicion, key);
    return true;
  }
  else if (!Search(key) && sequence_.size() == sequence_.capacity()) { // Verificar si la secuencia ya está llena
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
  for (auto k : sequence_) {
    os << k << " ";
  }
  return os;
}