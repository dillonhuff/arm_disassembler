#include <iostream>

#include "utils/bit_field_tests.h"
#include "utils/bit_pattern_tests.h"
#include "arm/disassembler_tests.h"

int main() {
  std::cout << "======================== All Tests =========================" << std::endl << std::endl;

  all_bit_field_tests();
  all_bit_pattern_tests();
  all_disassembler_tests();

  std::cout << "============================================================" << std::endl;
  return 0;
}
