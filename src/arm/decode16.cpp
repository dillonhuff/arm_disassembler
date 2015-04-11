#include "arm/decode16.h"
#include "arm/name_builder.h"
#include "utils/bit_pattern_table.hpp"

#define NUM_INSTRS 14

std::vector<std::pair<bit_pattern, instruction_builder*>> pat_pairs{};

typedef std::pair<bit_pattern, instruction_builder*> bp;

auto lsl = bp(bit_pattern("0000xxxxxxxxxxx"), new name_builder("lsl", 16));
auto lsr = bp(bit_pattern("00001xxxxxxxxxxx"), new name_builder("lsr", 16));
auto asr = bp(bit_pattern("00010xxxxxxxxxxx"), new name_builder("asr", 16));
auto add = bp(bit_pattern("0001100xxxxxxxxx"), new name_builder("add", 16));
auto add_2 = bp(bit_pattern("01000100xxxxxxxx"), new name_builder("add", 16));
auto sub = bp(bit_pattern("0001101xxxxxxxxx"), new name_builder("sub", 16));
					 bit_pattern("0001110xxxxxxxxx")
					 bit_pattern("00110xxxxxxxxxxx")
					 bit_pattern("0001111xxxxxxxxx")
					 bit_pattern("00111xxxxxxxxxxx")
					 bit_pattern("00100xxxxxxxxxxx")
					 bit_pattern("00101xxxxxxxxxxx")
					 bit_pattern("0100000000xxxxxx")
					 bit_pattern("0100000001xxxxxx")
					      new name_builder("add", 16),
					      new name_builder("add", 16),
					      new name_builder("sub", 16),
					      new name_builder("sub", 16),
					      new name_builder("mov", 16),
					      new name_builder("cmp", 16),
					      new name_builder("and", 16),
					      new name_builder("eor", 16) };
					      

bit_pattern_table<instruction_builder*> thumb16_table =
  bit_pattern_table<instruction_builder*>(thumb16_pats, builders, new name_builder("unknown_16", 16), NUM_INSTRS);

instruction decode16(bit_field* word16) {
  auto instr_builder = thumb16_table.match(word16);
  return instr_builder->build_instruction(word16);
}
