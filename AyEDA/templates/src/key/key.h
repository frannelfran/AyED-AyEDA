#pragma once
#include <iostream>
#include "../position/position.h"

using namespace std;

template <typename T>
class Key {
 public:
  // Constructores
  Key() {}
  Key(T key, const Position& pos) : key_(key), pos_(pos) {}

  // Destructor
  ~Key() {}

  // Getters
  inline T GetKey() const { return key_; }
  inline Position GetPosition() const { return pos_; }

  // Setters
  inline void SetPosition(const Position& pos) { pos_.SetData(pos.GetData()); }

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
  Position pos_;
};