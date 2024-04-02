#include "key.h"

/**
 * @brief Constructor de la clase Key
 * @param number Número de Key
*/

Key::Key(long int key, const Position& pos) {
  this->key_ = static_cast<int>(key);
  this->pos_ = pos;
}

/**
 * @brief Sobrecarga del operador de igualdad
 * @param Key Key a comparar
*/

bool Key::operator==(const Key& key) {
  return this->key_ == key.key_;
}

/**
 * @brief Sobrecarga del operador de salida
 * @param os Stream de salida
*/

ostream& operator<<(ostream& os, const Key& key) {
  os << key.key_;
  return os;
}