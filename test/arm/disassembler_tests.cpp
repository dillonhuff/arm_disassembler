#include <iostream>

#include "arm/disassembler.h"
#include "arm/instruction.h"
#include "test_utils/test_result.h"
#include "utils/bit_field.h"

void undefined_32_instruction() {
  byte undef_bytes[4] = {0x00, 0xff, 0x00, 0x00};
  auto instr = undefined_32();
  auto correct = singleton_seq(instr, 0);
  auto res = disassemble_arm7m(0, LITTLE, undef_bytes, 4);
  test_result(*(res.get()) == correct.get(), "decode undefined 32 bit instruction", "0xff000000 is not undefined");
}

void lsl_16_decode() {
  byte undef_bytes[4] = {0x01, 0x01};
  auto instr = lsl_16(4, 0, 1);
  auto correct = singleton_seq(instr, 0);
  auto res = disassemble_arm7m(0, LITTLE, undef_bytes, 2);
  test_result(*(res.get()) == correct.get(), "decode lsl 16", "0x0101 does not decode to lsl r1, r0, #4");
  std::cout << res->assembly_string() << std::endl;
}

void all_disassembler_tests() {
  std::cout << "------------------------ disassembler tests -------------------" << std::endl;

  undefined_32_instruction();
  lsl_16_decode();

  std::cout << "---------------------------------------------------------------" << std::endl << std::endl;
}
