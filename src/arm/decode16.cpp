#include "arm/decode16.h"
#include "arm/name_builder.h"
#include "utils/bit_pattern_table.hpp"

unsigned int num_instrs = 6;

bit_pattern thumb16_pats[6] = { bit_pattern("00000xxxxxxxxxxx"),
				bit_pattern("00001xxxxxxxxxxx"),
				bit_pattern("00010xxxxxxxxxxx"),
				bit_pattern("0001100xxxxxxxxx"),
				bit_pattern("01000100xxxxxxxx"),
				bit_pattern("0001101xxxxxxxxx") };

instruction_builder* builders[6] = { new name_builder("lsl"),
				     new name_builder("lsr"),
				     new name_builder("asr"),
				     new name_builder("add"),
				     new name_builder("add"),
				     new name_builder("sub") };

bit_pattern_table<instruction_builder*> thumb16_table =
  bit_pattern_table<instruction_builder*>(thumb16_pats, builders, new name_builder("unknown_16"), num_instrs);

instruction decode16(bit_field* word16) {
  auto instr_builder = thumb16_table.match(word16);
  return instr_builder->build_instruction(word16);
}
