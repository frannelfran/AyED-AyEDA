#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cassert>

using namespace std;

class Nif {
  public:
    Nif(); // Generar un número aleatorio
    Nif(long int); // Convertir un número en Nif

    // Getters
    inline int GetNumber () const { return number_; }

    // Sobrecarga de operadores
    bool operator==(const Nif&);

  private:
    int number_;
};