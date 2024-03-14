#include "hash_table.h"

/**
 * @brief Destructor de la clase HashTable
*/

HashTable::~HashTable() {
  for (int i = 0; i < size_; i++) {
    delete table_[i];
  }
  delete dispersion_function_;
}

/**
 * @brief Constructor de la clase OpenHashTable
 * @param size Tamaño de la tabla
 * @param dispersion_function Función de dispersión
*/

OpenHashTable::OpenHashTable(unsigned size, DispersionFunction* dispersion_function) {
  size_ = size;
  dispersion_function_ = dispersion_function;
  table_.resize(size);
  for (int i = 0; i < size; i++) {
    table_[i] = new DinamicSequence;
  }
}

/**
 * @brief Método que busca una clave en la tabla
 * @param key Clave a buscar
 * @return true si la clave está en la tabla, false en caso contrario
*/

bool OpenHashTable::Search(const Key& key) const {
  int index = dispersion_function_->operator()(key);
  return table_[index]->Search(key);
}

/**
 * @brief Método que inserta una clave en la tabla
 * @param key Clave a insertar
 * @return true si la clave se ha insertado, false en caso contrario
*/

bool OpenHashTable::Insert(const Key& key) const {
  int index = dispersion_function_->operator()(key);
  return table_[index]->Insert(key);
}

/**
 * @brief Sobrecarga del operador de salida
 * @param os Stream de salida
 * @param hash_table Tabla hash
*/

ostream& operator<<(ostream& os, const HashTable& hash_table) {
  os << "--- Tabla hash ---\n";
  for (int i = 0; i < hash_table.size_; i++) {
    os << "Posicion " << i << ": ";
    hash_table.table_[i]->Print(os) << endl;
  }
  os << "------------------\n";
  return os;
}