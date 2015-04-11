#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <memory>
#include <string>

#include "utils/bit.h"
#include "utils/bit_field.h"

enum instruction_class { DATA_PROCESSING, LOAD_STORE_WD_OR_UB };

class instruction {
 protected:
  instruction_class instr_class;
  unsigned int byte_width;
  std::string mnemonic;
  bit lds_b, lds_l;

 public:
  //  instruction(bit_field* bits);
  bool operator==(instruction* other);
  bool operator!=(instruction* other);

  unsigned int width();
  std::string asm_string();
  std::string get_mnemonic();

  //  void set_bits(bit_field b);
  void set_mnemonic(std::string new_mnemonic);
  void set_width(unsigned int new_width);
  void set_lds_b(bit new_val) { lds_b = new_val; }
  void set_lds_l(bit new_val) { lds_l = new_val; }
  void set_instr_class(instruction_class new_class) { instr_class = new_class; }
};


instruction undefined_32();
instruction unknown_32();
instruction and_32();
instruction undefined_16();
instruction ldr_32();
instruction ldrb_32();
instruction lsl_16(int shift, int rm, int rd);
instruction lsr_16(int shift, int rm, int rd);
instruction asr_16(int shift, int rm, int rd);
instruction cmp_thumb(int rn, int imm8);

#endif
