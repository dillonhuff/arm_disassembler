#include "arm/instruction.h"

bool instruction::operator==(instruction* other) {
  return this->get_mnemonic().compare(other->get_mnemonic()) == 0 &&
    this->lds_b == other->lds_b &&
    this->lds_l == other->lds_l &&
    this->instr_class == other->instr_class;
}

bool instruction::operator!=(instruction* other) {
  return !(*(this) == other);
}

unsigned int instruction::width() {
  return byte_width;
}

std::string instruction::get_mnemonic() {
  if (instr_class == LOAD_STORE_WD_OR_UB) {
    std::string mn = "";
    if (lds_l == ONE) {
      mn += "ldr";
    } else {
      mn += "str";
    }
    if (lds_b == ONE) {
      mn += "b";
    }
    return mn;
  } else if (instr_class == BRANCH) {
    std::string mn = "";
    mn += "b";
    if (branch_l == ONE) {
      mn += "l";
    }
    return mn;
  }
  return mnemonic;
}

std::string instruction::asm_string() {
  return get_mnemonic();
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

instruction unknown_32() {
  auto instr = instruction();
  instr.set_mnemonic("unknown_32");
  instr.set_width(4);
  return instr;
}

instruction and_32() {
  auto instr = instruction();
  instr.set_mnemonic("and");
  instr.set_width(4);
  return instr;
}

instruction ldr_32() {
  auto instr = instruction();
  instr.set_instr_class(LOAD_STORE_WD_OR_UB);
  instr.set_width(4);
  instr.set_lds_b(ZERO);
  instr.set_lds_l(ONE);
  return instr;
}

instruction ldrb_32() {
  auto instr = instruction();
  instr.set_instr_class(LOAD_STORE_WD_OR_UB);
  instr.set_width(4);
  instr.set_lds_b(ONE);
  instr.set_lds_l(ONE);
  return instr;
}

instruction str_32() {
  auto instr = instruction();
  instr.set_instr_class(LOAD_STORE_WD_OR_UB);
  instr.set_width(4);
  instr.set_lds_b(ZERO);
  instr.set_lds_l(ZERO);
  return instr;
}

instruction strb_32() {
  auto instr = instruction();
  instr.set_instr_class(LOAD_STORE_WD_OR_UB);
  instr.set_width(4);
  instr.set_lds_b(ONE);
  instr.set_lds_l(ZERO);
  return instr;
}

instruction b_32() {
  auto instr = instruction();
  instr.set_instr_class(BRANCH);
  instr.set_width(4);
  instr.set_branch_l(ZERO);
  return instr;
}

instruction bl_32() {
  auto instr = instruction();
  instr.set_instr_class(BRANCH);
  instr.set_width(4);
  instr.set_branch_l(ONE);
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
