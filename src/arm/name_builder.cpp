#include "arm/name_builder.h"

name_builder::name_builder(std::string n) {
  name = n;
}

instruction name_builder::build_instruction(bit_field* instr_bits) {
  auto instr = instruction();
  instr.set_mnemonic(name);
  return instr;
}
