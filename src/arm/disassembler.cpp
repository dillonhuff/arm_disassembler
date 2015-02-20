#include <memory>

#include "disassembler.h"

std::unique_ptr<instruction_sequence> disassemble_arm6m(unsigned int start_addr, endianness end, byte* bytes, unsigned int n) {
  return std::unique_ptr<instruction_sequence>(new instruction_sequence());
}
