#include <iostream>

#pragma once
using namespace std;

class Position {
  public:
   Position(int);

   inline int GetPoicion() { return this->position_; }

  private:
   int position_;
};