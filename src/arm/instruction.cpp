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

void instruction::set_mnemonic(std::string new_mnemonic) {
  mnemonic = new_mnemonic;
}

instruction undefined_32() {
  return instruction();
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
