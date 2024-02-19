#include "state.h"

State::State() {}

/**
 * @brief constructor de la clase State
 * @param state Estado de la célula
 * @return Objeto de la clase State
*/

State::State(bool state) {
  this->state_ = state;
}