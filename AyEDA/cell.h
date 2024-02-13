#include <iostream>
#include "position.h"
#include "state.h"

#pragma once
using namespace std;


class Cell {
  public:
   // Constructores de la clase
   Cell();
   Cell(const Position&, const State&);



  private:
   Position posicion_;
   State estado_;
};