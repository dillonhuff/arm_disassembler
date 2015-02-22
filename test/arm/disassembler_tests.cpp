#include <iostream>

#include "arm/disassembler.h"
#include "arm/instruction.h"
#include "test_utils/test_result.h"
#include "utils/bit_field.h"

void test_instruction(byte* instr_bytes, instruction correct) {
  auto correct_seq = singleton_seq(correct, 0);
  auto res = disassemble_arm7m(0, LITTLE, instr_bytes, 2);
  test_result(*(res.get()) == correct_seq.get(), "decode " + correct.asm_string(), "result is not " + correct.asm_string());
}

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
}

void lsr_16_decode() {
  byte undef_bytes[4] = {0x13, 0x08};
  auto instr = lsr_16(0, 2, 3);
  auto correct = singleton_seq(instr, 0);
  auto res = disassemble_arm7m(0, LITTLE, undef_bytes, 2);
  test_result(*(res.get()) == correct.get(), "decode lsr 16", "0x1813 does not decode to lsr r3, r2, #0");
}

void asr_16_decode() {
  byte undef_bytes[2] = {0x00, 0x10};
  auto instr = asr_16(0, 0, 0);
  auto correct = singleton_seq(instr, 0);
  auto res = disassemble_arm7m(0, LITTLE, undef_bytes, 2);
  test_result(*(res.get()) == correct.get(), "decode asr 16", "0x1000 does not decode to asr r0, r0, #0");
}

void cmp_decode() {
  byte bts[2] = {0x00, 0x028};
  auto instr = cmp_thumb(0, 0);
  test_instruction(bts, instr);
}

void all_disassembler_tests() {
  std::cout << "------------------------ disassembler tests -------------------" << std::endl;

  undefined_32_instruction();
  lsl_16_decode();
  lsr_16_decode();
  asr_16_decode();
  cmp_decode();
 
  std::cout << "---------------------------------------------------------------" << std::endl << std::endl;
}
