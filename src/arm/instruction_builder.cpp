#include <iostream>

#include "arm/instruction_builder.h"

instruction instruction_builder::build_instruction(bit_field* instr_bits) {
  std::cout << "Error: instruction_builder::build_instruction called" << std::endl;
  throw;
}
