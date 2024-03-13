#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cassert>

using namespace std;
 
class Key {
  public:
    inline Key() {}
    Key(long int); // Convertir un número en clave

    // Getters
    inline int GetKey() const { return key_; }

    // Sobrecarga de operadores
    bool operator==(const Key&);
    friend ostream& operator<<(ostream& os, const Key& key);

  private:
    int key_;
};