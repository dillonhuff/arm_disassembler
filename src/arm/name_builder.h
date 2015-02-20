#ifndef NAME_BUILDER_H_
#define NAME_BUILDER_H_

#include <string>

#include "arm/instruction_builder.h"

class name_builder : public instruction_builder {
 private:
  unsigned int width;
  std::string name;

 public:
  name_builder(std::string n, unsigned int bits_wide);
  virtual instruction build_instruction(bit_field* instr_bits);
};

#endif
