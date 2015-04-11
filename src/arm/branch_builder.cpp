#include "arm/branch_builder.h"

instruction branch_builder::build_instruction(bit_field* instr_bits) {
  auto instr = instruction();
  auto bf = *instr_bits;
  instr.set_instr_class(BRANCH);
  instr.set_width(4);
  instr.set_branch_l(bf[24]);
  return instr;

}
