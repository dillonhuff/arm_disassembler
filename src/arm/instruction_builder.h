#ifndef INSTRUCTION_BUILDER_H_
#define INSTRUCTION_BUILDER_H_

#include "arm/instruction.h"
#include "utils/bit_field.h"

class instruction_builder {
 public:
  virtual instruction build_instruction(bit_field* instr_bits);
};

#endif
