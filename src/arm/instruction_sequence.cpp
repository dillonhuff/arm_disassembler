#include <iostream>

#include "arm/instruction_sequence.h"
#include "utils/hex_print.h"

instruction_sequence::instruction_sequence(instruction instr, unsigned int start_addr) {
  instructions.push_back(instr);
  start_address = start_addr;
}

instruction_sequence::instruction_sequence(unsigned int start_addr) {
  start_address = start_addr;
}

bool instruction_sequence::operator==(instruction_sequence* other) {
  if (instructions.size() != other->instructions.size()) {
    std::cout << "ERROR: instruction sets are not the same size" << std::endl;
    return false;
  }
  for (unsigned int i = 0; i < instructions.size(); i++) {
    if (instructions[i] != &(other->instructions[i])) {
      std::cout << "Failed. instructions[i] = " << instructions[i].asm_string() << std::endl;
      return false;
    }
  }
  return true;
}

void instruction_sequence::add(instruction instr) {
  instructions.push_back(instr);
}

std::string instruction_sequence::assembly_string() {
  std::string assembly_code = "";
  unsigned int instruction_address = start_address;
  for (auto instr : instructions) {
    assembly_code += "\t" + hex_num_to_string(8, ' ', instruction_address) + ":";
    assembly_code += "\t" + instr.asm_string() + "\n";
    instruction_address += instr.width();
  }
  return assembly_code;
}

std::unique_ptr<instruction_sequence> singleton_seq(instruction instr, unsigned int start_addr) {
  auto instrs = new instruction_sequence(instr, start_addr);
  return std::unique_ptr<instruction_sequence>(instrs);
}

