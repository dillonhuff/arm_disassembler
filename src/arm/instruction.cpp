#include "arm/instruction.h"

bool instruction::operator==(instruction* other) {
  return mnemonic.compare(other->mnemonic) == 0;
}

bool instruction::operator!=(instruction* other) {
  return !(*(this) == other);
}

unsigned int instruction::width() {
  return byte_width;
}

std::string instruction::asm_string() {
  return mnemonic;
}

//void instruction::set_bits(bit_field* new_bits) {
  //  bits = new_bits->copy();
//}

void instruction::set_mnemonic(std::string new_mnemonic) {
  mnemonic = new_mnemonic;
}

void instruction::set_width(unsigned int new_width) {
  byte_width = new_width;
}

instruction undefined_32() {
  auto instr = instruction();
  instr.set_mnemonic("undefined_32");
  instr.set_width(4);
  return instr;
}

instruction undefined_16() {
  auto instr = instruction();
  instr.set_mnemonic("undefined_16");
  return instr;
}

instruction lsl_16(int shift, int rm , int rd) {
  auto instr = instruction();
  instr.set_mnemonic("lsl");
  return instr;
}

instruction lsr_16(int shift, int rm , int rd) {
  auto instr = instruction();
  instr.set_mnemonic("lsr");
  return instr;
}

instruction asr_16(int shift, int rm , int rd) {
  auto instr = instruction();
  instr.set_mnemonic("asr");
  return instr;
}

instruction cmp_thumb(int rn, int imm8) {
  auto instr = instruction();
  instr.set_mnemonic("cmp");
  return instr;
}
