#include "arm/decode16.h"
#include "arm/name_builder.h"
#include "utils/bit_pattern_table.hpp"

#define NUM_INSTRS 16

bit_pattern thumb16_pats[NUM_INSTRS] = { bit_pattern("00000xxxxxxxxxxx"),
					 bit_pattern("00001xxxxxxxxxxx"),
					 bit_pattern("00010xxxxxxxxxxx"),
					 bit_pattern("0001100xxxxxxxxx"),
					 bit_pattern("01000100xxxxxxxx"),
					 bit_pattern("0001101xxxxxxxxx"),
					 bit_pattern("0001110xxxxxxxxx"),
					 bit_pattern("00110xxxxxxxxxxx"),
					 bit_pattern("0001111xxxxxxxxx"),
					 bit_pattern("00111xxxxxxxxxxx"),
					 bit_pattern("00100xxxxxxxxxxx"),
					 bit_pattern("00101xxxxxxxxxxx"),
					 bit_pattern("0001110xxxxxxxxx"), // redundant
					 bit_pattern("00110xxxxxxxxxxx"), // redundant
					 bit_pattern("0001111xxxxxxxxx"), // redundant 
					 bit_pattern("00111xxxxxxxxxxx") }; // redundant

instruction_builder* builders[NUM_INSTRS] = { new name_builder("lsl", 16),
					      new name_builder("lsr", 16),
					      new name_builder("asr", 16),
					      new name_builder("add", 16),
					      new name_builder("add", 16),
					      new name_builder("sub", 16),
					      new name_builder("add", 16),
					      new name_builder("add", 16),
					      new name_builder("sub", 16),
					      new name_builder("sub", 16),
					      new name_builder("mov", 16),
					      new name_builder("cmp", 16),
					      new name_builder("add", 16),
					      new name_builder("add", 16),
					      new name_builder("sub", 16),
					      new name_builder("sub", 16) };
					      

bit_pattern_table<instruction_builder*> thumb16_table =
  bit_pattern_table<instruction_builder*>(thumb16_pats, builders, new name_builder("unknown_16", 16), NUM_INSTRS);

instruction decode16(bit_field* word16) {
  auto instr_builder = thumb16_table.match(word16);
  return instr_builder->build_instruction(word16);
}
