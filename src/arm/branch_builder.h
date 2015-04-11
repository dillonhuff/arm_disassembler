#ifndef BRANCH_BUILDER_H_
#define BRANCH_BUILDER_H_

#include "instruction_builder.h"

class branch_builder : public instruction_builder {
 public:
  virtual instruction build_instruction(bit_field* instr_bits);
};

#endif
