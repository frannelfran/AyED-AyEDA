#include "alfabeto.h"

/**
 * @brief Constructor de la clase Alfabeto
 * @param parametro Caracter perteneciente al alfabeto
 * @return Objeto de la clase Alfabeto
*/

Alfabeto::Alfabeto(bool parametro) {
  alfabeto_.insert(parametro);
}

/**
 * @overload Sobrecarga del operador <<
*/

ostream& operator<<(ostream& os, const Alfabeto& alf) {
  os << "Alfabeto del autómata: ";
  for (bool it : alf.alfabeto_) {
    os << it << " ";
  }
  os << endl;
  return os;
}