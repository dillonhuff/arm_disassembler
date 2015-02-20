#include "arm/instruction.h"

bool instruction::operator==(instruction* other) {
  return true;
}

instruction undefined_32() {
  return instruction();
}
