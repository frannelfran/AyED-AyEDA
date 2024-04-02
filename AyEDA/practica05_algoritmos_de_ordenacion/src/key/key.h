#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cassert>
#include "../position/position.h"

using namespace std;
 
class Key {
  public:
    inline Key() {}
    Key(long int, const Position&); // Convertir un número en clave

    // Getters
    inline int GetKey() const { return key_; }
    inline Position GetPosition() const { return pos_; }

    // Sobrecarga de operadores
    bool operator==(const Key&);
    friend ostream& operator<<(ostream& os, const Key& key);

  private:
    int key_;
    Position pos_;
};