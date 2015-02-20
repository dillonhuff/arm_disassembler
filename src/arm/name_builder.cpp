#include "arm/name_builder.h"

name_builder::name_builder(std::string n, unsigned int bits_wide) {
  name = n;
  width = bits_wide;
}

instruction name_builder::build_instruction(bit_field* instr_bits) {
  auto instr = instruction();
  instr.set_mnemonic(name);
  instr.set_width(width / BITS_PER_BYTE);
  return instr;
}
