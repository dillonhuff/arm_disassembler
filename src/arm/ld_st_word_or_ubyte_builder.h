#ifndef LD_ST_WORD_OR_UBYTE_BUILDER_H_
#define LD_ST_WORD_OR_UBYTE_BUILDER_H_

#include "arm/instruction_builder.h"

class ld_st_word_or_ubyte_builder : public instruction_builder {
 public:
  virtual instruction build_instruction(bit_field* instr_bits);
};

#endif
