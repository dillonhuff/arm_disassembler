#ifndef INSTRUCTION_SEQUENCE_H_
#define INSTRUCTION_SEQUENCE_H_

#include <memory>

#include "arm/instruction.h"

class instruction_sequence {
 public:
  bool operator==(instruction_sequence* other);
};

std::unique_ptr<instruction_sequence> singleton_seq(instruction* instr, unsigned int start_addr);

#endif
