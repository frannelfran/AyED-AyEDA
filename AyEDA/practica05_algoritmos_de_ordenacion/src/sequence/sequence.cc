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
 * @brief Método para intercambiar dos llaves
 * @param pos1 Posición de la primera llave
 * @param pos2 Posición de la segunda llave
*/

void StaticSequence::Swap(const Position& pos1, const Position& pos2) {
  swap(sequence_[pos1.GetData()], sequence_[pos2.GetData()]);
  // Asigno las posiciones
  sequence_[pos1.GetData()].SetPosition(pos1);
  sequence_[pos2.GetData()].SetPosition(pos2);
  if (show_) {
    Print(cout);
  }
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