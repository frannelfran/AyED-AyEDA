#pragma once
#include <iostream>
#include <utility>

using namespace std;

class Position {
  public:
   // Constructores de la clase
   inline Position() {}
   inline Position(int position_M, int position_N) { this->position_.first = position_M, this->position_.second = position_N; }

   // Getters
   inline int GetDataM() const { return this->position_.first; }
   inline int GetDataN() const { return this->position_.second; }

   // Setters
   inline void SetData(int position_M, int position_N) { this->position_.first = position_M, this->position_.second = position_N; }

  private:
   pair<int, int> position_;
};