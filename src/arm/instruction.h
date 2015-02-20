#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <memory>
#include <string>

#include "utils/bit_field.h"

class instruction {
 private:
  //  std::unique_ptr<bit_field> bits;
  unsigned int byte_width;
  std::string mnemonic;

 public:
  //  instruction(bit_field* bits);
  bool operator==(instruction* other);
  bool operator!=(instruction* other);

  unsigned int width();
  std::string asm_string();

  //  void set_bits(bit_field b);
  void set_mnemonic(std::string new_mnemonic);
  void set_width(unsigned int new_width);
};


instruction undefined_32();
instruction undefined_16();
instruction lsl_16(int shift, int rm, int rd);
instruction lsr_16(int shift, int rm, int rd);
instruction asr_16(int shift, int rm, int rd);

#endif
