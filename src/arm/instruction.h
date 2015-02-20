#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <string>

class instruction {
 private:
  unsigned int byte_width;
  std::string mnemonic;

 public:
  bool operator==(instruction* other);
  bool operator!=(instruction* other);

  unsigned int width();
  std::string asm_string();

  void set_mnemonic(std::string new_mnemonic);
};


instruction undefined_32();
instruction lsl_16(int shift, int rm, int rd);
instruction lsr_16(int shift, int rm, int rd);
instruction asr_16(int shift, int rm, int rd);

#endif
