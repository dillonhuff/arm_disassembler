#include <iostream>

#include "arm/disassembler_tests.h"
#include "arm/disassembler.h"
#include "elfio/elfio.hpp"
#include "utils/bit_field_tests.h"
#include "utils/bit_pattern_table_tests.h"
#include "utils/bit_pattern_tests.h"
#include "utils/endianness.h"
#include "utils/hex_print.h"

using namespace ELFIO;

void disassemble_code(char* elf_file_name);
void run_all_tests();

int main(int argc, char** argv) {
  if (argc == 1) {
    run_all_tests();
  } else if (argc == 2) {
    disassemble_code(argv[1]);
  } else {
    std::cout << "Usage: ./tests <efl_file_name>" << std::endl;
    std::cout << "Or   : ./tests to run all tests" << std::endl;
  }
  return 0;
}

void disassemble_code(char* elf_file_name) {
  elfio reader;

  if (!reader.load(elf_file_name)) {
    std::cout << "Can't find or process the ELF file " << elf_file_name << std::endl;
  }

  section* text_section = NULL;  
  for (auto sec : reader.sections) {
    if (sec->get_name() == ".text") {
      text_section = sec;
    }
  }
  
  if (text_section == NULL) {
    std::cout << elf_file_name << " has no .text section" << std::endl;
    return;
  }

  std::cout << "text_section address: " << hex_num_to_string(8, ' ', text_section->get_address()) << std::endl;
  std::cout << "text_section size: " << std::to_string(text_section->get_size()) << std::endl;

  auto instructions = disassemble_arm6(text_section->get_address(), LITTLE, (unsigned char*) text_section->get_data(), (unsigned int) text_section->get_size());

  std::cout << instructions->assembly_string() << std::endl;
}


void run_all_tests() {
  std::cout << "========================= All Tests ===========================" << std::endl << std::endl;

  all_bit_field_tests();
  all_bit_pattern_tests();
  all_disassembler_tests();
  all_bit_pattern_table_tests();

  std::cout << "===============================================================" << std::endl;
}
