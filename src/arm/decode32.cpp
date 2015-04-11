#include "arm/branch_builder.h"
#include "arm/decode32.h"
#include "arm/ld_st_word_or_ubyte_builder.h"
#include "arm/name_builder.h"
#include "utils/bit_pattern_table.hpp"

#define NUM_ARM6_32_INSTRS 18

bit_pattern arm6_32_pats[NUM_ARM6_32_INSTRS] = { bit_pattern("xxxx00x0000xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x0001xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x0010xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x0011xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x0100xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x0101xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x0110xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x0111xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x1000xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x1001xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x1010xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x1011xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x1100xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x1101xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x1110xxxxxxxxxxxxxxxxxxxxx"),
						 bit_pattern("xxxx00x1111xxxxxxxxxxxxxxxxxxxxx"),
						 // load / store instructions
						 bit_pattern("xxxx01xxxxxxxxxxxxxxxxxxxxxxxxxx"),
						 //branches b, bl
						 bit_pattern("xxxx101xxxxxxxxxxxxxxxxxxxxxxxxx") };

instruction_builder* arm6_32_builders[NUM_ARM6_32_INSTRS] = { new name_builder("and", 32),
							      new name_builder("eor", 32),
							      new name_builder("sub", 32),
							      new name_builder("rsb", 32),
							      new name_builder("add", 32),
							      new name_builder("adc", 32),
							      new name_builder("sbc", 32),
							      new name_builder("rsc", 32),
							      new name_builder("tst", 32),
							      new name_builder("teq", 32),
							      new name_builder("cmp", 32),
							      new name_builder("cmn", 32),
							      new name_builder("orr", 32),
							      new name_builder("mov", 32),
							      new name_builder("bic", 32),
							      new name_builder("mvn", 32),
							      new ld_st_word_or_ubyte_builder(),
							      new branch_builder() };

auto arm6_32_table =
  bit_pattern_table<instruction_builder*>(arm6_32_pats, arm6_32_builders, new name_builder("unknown_32", 32), NUM_ARM6_32_INSTRS);

instruction decode_arm6_32(bit_field* word32) {
  auto instr_builder = arm6_32_table.match(word32);
  return instr_builder->build_instruction(word32);
}
