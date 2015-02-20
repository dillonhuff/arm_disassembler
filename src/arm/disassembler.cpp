#include <iostream>
#include <memory>

#include "arm/disassembler.h"
#include "arm/decode16.h"
#include "utils/bit_field.h"
#include "utils/bit_pattern.h"

bit_pattern start32_p1 = bit_pattern("11101");
bit_pattern start32_p2 = bit_pattern("1111x");

bool is_start_of_32_bit_instruction(bit_field* bits) {
  auto b = bits->subfield(15, 11);
  return start32_p1.matches(&b) || start32_p2.matches(&b);
}

std::unique_ptr<instruction_sequence> disassemble_arm7m(unsigned int start_addr, endianness end, byte* bytes, unsigned int n) {
  if (end == BIG) {
    std::cout << "Error: big endian not yet supported" << std::endl;
    throw;
  }

  auto instrs = new instruction_sequence(start_addr);
  for (unsigned int i = 0; i < n; i++) {
    auto word16 = bit_field(end, 2, &(bytes[i]), 2);
    if (is_start_of_32_bit_instruction(&word16)) {
      instrs->add(undefined_32());
      i += 4;
    } else {
      instrs->add(decode16(&word16));
      i += 2;
    }
  }
  return std::unique_ptr<instruction_sequence>(instrs);
}
