#include "hash_table.h"

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
 * @brief Destructor de la clase OpenHashTable
*/

void OpenHashTable::Delete() {
  for (int i = 0; i < size_; i++) {
    delete table_[i];
  }
  delete dispersion_function_;
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
 * @brief Constructor de la clase ClosedHashTable
 * @param size Tamaño de la tabla
 * @param dispersion_function Función de dispersión
 * @param exploration_function Función de exploración
 * @param bloq_size Tamaño del bloque
*/

ClosedHashTable::ClosedHashTable(unsigned size, DispersionFunction* dispersion_function, ExplorationFunction* exploration_function, unsigned bloq_size) {
  size_ = size;
  dispersion_function_ = dispersion_function;
  exploration_function_ = exploration_function;
  bloq_size_ = bloq_size;
  table_.resize(size);
  for (int i = 0; i < size; i++) {
    table_[i] = new StaticSequence(bloq_size);
  }
}

/**
 * @brief Destructor de la clase ClosedHashTable
*/

void ClosedHashTable::Delete() {
  for (int i = 0; i < size_; i++) {
    delete table_[i];
  }
  delete dispersion_function_;
  delete exploration_function_;
}

/**
 * @brief Método que busca una clave en la tabla
 * @param key Clave a buscar
 * @return true si la clave está en la tabla, false en caso contrario
*/

bool ClosedHashTable::Search(const Key& key) const {
  int index = dispersion_function_->operator()(key);
  int i = 0;
  while (i < size_) {
    if (table_[index]->Search(key)) {
      return true;
    }
    index = exploration_function_->operator()(key, i);
    i++;
  }
  return false;
}

/**
 * @brief Método que inserta una clave en la tabla
 * @param key Clave a insertar
 * @return true si la clave se ha insertado, false en caso contrario
*/

bool ClosedHashTable::Insert(const Key& key) const {
  int index = dispersion_function_->operator()(key);
  int i = 0;
  while (i < size_) {
    if (table_[index]->Insert(key)) {
      return true;
    }
    else if (table_[index]->Search(key)) {
      return false;
    }
    index = exploration_function_->operator()(key, i);
    i++;
  }
  return false;
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