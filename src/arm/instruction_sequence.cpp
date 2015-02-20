#include "instruction_sequence.h"

bool instruction_sequence::operator==(instruction_sequence* other) {
  return true;
}

std::unique_ptr<instruction_sequence> singleton_seq(instruction* instr, unsigned int start_addr) {
  return std::unique_ptr<instruction_sequence>(new instruction_sequence());
}
