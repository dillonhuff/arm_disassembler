#ifndef INSTRUCTION_SEQUENCE_H_
#define INSTRUCTION_SEQUENCE_H_

#include <memory>
#include <string>
#include <vector>

#include "arm/instruction.h"

class instruction_sequence {
 private:
  std::vector<instruction> instructions;
  unsigned int start_address;

 public:
  instruction_sequence(instruction instr, unsigned int start_address);
  instruction_sequence(unsigned int start_address);

  bool operator==(instruction_sequence* other);

  void add(instruction instr);

  std::string assembly_string();
};


std::unique_ptr<instruction_sequence> singleton_seq(instruction instr, unsigned int start_addr);

#endif
