#include <iostream>

#include "arm/disassembler.h"
#include "arm/instruction.h"
#include "test_utils/test_result.h"
#include "utils/bit_field.h"

void undefined_32_instruction() {
  byte undef_bytes[4] = {0x00, 0xff, 0x00, 0x00};
  auto instr = undefined_32();
  auto correct = singleton_seq(&instr, 0);
  auto res = disassemble_arm6m(0, LITTLE, undef_bytes, 4);
  test_result(*(res.get()) == correct.get(), "decode undefined 32 bit instruction", "0xff000000 is not undefined");
}

void all_disassembler_tests() {
  std::cout << "------------------------ disassembler tests -------------------" << std::endl;

  undefined_32_instruction();

  std::cout << "---------------------------------------------------------------" << std::endl << std::endl;
}
