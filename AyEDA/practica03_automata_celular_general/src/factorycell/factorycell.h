#pragma once
#include <iostream>
#include "position/position.h"
#include "state/state.h"
#include "cell/cell.h"
#include "cellace/cellace110.h"
#include "cellace/cellace30.h"
#include "cellLife/cellLife23_3.h"
#include "cellLife/cellLife51_346.h"

using namespace std;

class FactoryCell {
  public:
   virtual Cell* createCell(const Position&, const State&) const = 0;
};

class FactoryCellAce110 : public FactoryCell {
  public:
   Cell* createCell(const Position& position, const State& state) const override {
    return new CellAce110(position, state);
   }
};

class FactoryCellAce30 : public FactoryCell {
  public:
   Cell* createCell(const Position& position, const State& state) const override {
    return new CellAce30(position, state);
   }
};

class FactoryCellLife23_3 : public FactoryCell {
  public:
   Cell* createCell(const Position& position, const State& state) const override {
    return new CellLife23_3(position, state);
   }
};

class FactoryCellLife51_346 : public FactoryCell {
  public:
   Cell* createCell(const Position& position, const State& state) const override {
    return new CellLife51_346(position, state);
   }
};