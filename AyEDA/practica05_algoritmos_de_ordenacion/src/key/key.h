#pragma once
#include <iostream>
#include "../position/position.h"

using namespace std;

template<class T>
class Key {
 public:
  // Constructores
  Key() {}
  Key(const T key) : key_(key) {}

  // Destructor
  ~Key() {}

  // Getters
  inline T GetKey() const { return key_; }

  // Sobrecarga de operadores
  friend ostream& operator<<(ostream& os, const Key& key) {
    os << key.key_;
    return os;
  }
  bool operator==(const Key& key) { return key_ == key.key_; }
  bool operator<(const Key& key) { return key_ < key.key_;}
  bool operator>(const Key& key) { return key_ > key.key_;}
  bool operator<=(const Key& key) { return key_ <= key.key_;}
  bool operator>=(const Key& key) { return key_ >= key.key_;}

 private:
  T key_;
};