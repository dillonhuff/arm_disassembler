#include "ld_st_word_or_ubyte_builder.h"

instruction ld_st_word_or_ubyte_builder::build_instruction(bit_field* instr_bits) {
  auto instr = instruction();
  auto bf = *instr_bits;
  instr.set_instr_class(LOAD_STORE_WD_OR_UB);
  instr.set_width(4);
  instr.set_lds_b(bf[22]);
  instr.set_lds_l(bf[20]);
  return instr;
}
