#include "arm/decode32.h"
#include "arm/name_builder.h"
#include "utils/bit_pattern_table.hpp"

#define NUM_ARM6_32_INSTRS 1

bit_pattern arm6_32_pats[NUM_ARM6_32_INSTRS] = { bit_pattern("xxxx00x0000xxxxxxxxxxxxxxxxxxxxx") };

instruction_builder* arm6_32_builders[NUM_ARM6_32_INSTRS] = { new name_builder("and", 32) };

auto arm6_32_table =
  bit_pattern_table<instruction_builder*>(arm6_32_pats, arm6_32_builders, new name_builder("unknown_32", 32), NUM_ARM6_32_INSTRS);

instruction decode_arm6_32(bit_field* word32) {
  auto instr_builder = arm6_32_table.match(word32);
  return instr_builder->build_instruction(word32);
}
