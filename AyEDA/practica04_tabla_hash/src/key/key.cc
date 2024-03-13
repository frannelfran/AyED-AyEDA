#include "key.h"

/**
 * @brief Constructor por defecto de la clase Key
*/

Key::Key() {
  this->key_ = rand() % 100000000;
}

/**
 * @brief Constructor de la clase Key
 * @param number Número de Key
*/

Key::Key(long int key) {
  this->key_ = static_cast<int>(key);
}

/**
 * @brief Sobrecarga del operador de igualdad
 * @param Key Key a comparar
*/

bool Key::operator==(const Key& key){
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