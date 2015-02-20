#include <iostream>

#include "test_utils/test_result.h"
#include "utils/bit_field.h"
#include "utils/bit_pattern.h"

void match_all_zeros() {
  unsigned char bytes[1] = {0x00};
  auto word8 = bit_field(LITTLE, 1, bytes, 1);
  auto pat = bit_pattern(zero, 8);
  test_result(pat.matches(&word8), "one zero byte pattern match", "0x00 does not match all zeros pattern");
}

void match_all_ones() {
  unsigned char bytes[4] = {0xff, 0xff, 0xff, 0xff};
  auto word32 = bit_field(LITTLE, 4, bytes, 4);
  auto pat = bit_pattern(one, 32);
  test_result(pat.matches(&word32), "all zero word32 pattern match", "0xffffffff does not match all ones pattern");
}

void match_any() {
  unsigned char bytes[5] = {0x12, 0x4f, 0xd1, 0x87, 0xea};
  auto words = bit_field(LITTLE, 1, bytes, 5);
  auto pat = bit_pattern(any, 40);
  test_result(pat.matches(&words), "any pattern length 40", "40 bit sequence doesn't match 40 bit any pattern");
}

void all_bit_pattern_tests() {
  std::cout << "--------------------- bit_pattern tests -----------------------" << std::endl;

  match_all_zeros();
  match_all_ones();
  match_any();

  std::cout << "---------------------------------------------------------------" << std::endl << std::endl;
}
