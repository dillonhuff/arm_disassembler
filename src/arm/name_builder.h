#ifndef NAME_BUILDER_H_
#define NAME_BUILDER_H_

#include <string>

#include "arm/instruction_builder.h"

class name_builder : public instruction_builder {
 private:
  std::string name;

 public:
  name_builder(std::string n);
  virtual instruction build_instruction(bit_field* instr_bits);
};

#endif
