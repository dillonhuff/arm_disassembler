#include <iostream>

#include "test_utils/test_result.h"
#include "utils/bit_pattern.h"
#include "utils/bit_pattern_table.hpp"

void one_pattern_table_match() {
  bit_pattern p[1] = {bit_pattern("11101000")};
  int nums[1] = {12};
  auto ptable = bit_pattern_table<int>(p, nums, 0, 1);
  byte b[1] = {0xe8};
  auto bf = bit_field(LITTLE, 1, b, 1);
  test_result(ptable.match(&bf) == 12, "one table match", "table whose only entry is 12 doesn't match");
}

void multi_pattern_table_match() {
  bit_pattern p[3] = {bit_pattern("11101000"), bit_pattern("1xx1xxxx"), bit_pattern("0000x1x1")};
  int nums[3] = {12, 15, 3};
  auto ptable = bit_pattern_table<int>(p, nums, 0, 3);
  byte b[1] = {0x0f};
  auto bf = bit_field(LITTLE, 1, b, 1);
  test_result(ptable.match(&bf) == 3, "multi pattern table match", "expected result to be 3");
}

void default_pattern_match() {
  bit_pattern p[3] = {bit_pattern("11101000"), bit_pattern("1xx1xxxx"), bit_pattern("0000x1x1")};
  int nums[3] = {12, 15, 3};
  auto ptable = bit_pattern_table<int>(p, nums, 0, 3);
  byte b[1] = {0x00};
  auto bf = bit_field(LITTLE, 1, b, 1);
  test_result(ptable.match(&bf) == 0, "pattern table default match", "expected result to be 0");
}

void all_bit_pattern_table_tests() {
  std::cout << "--------------------- bit_pattern_table tests -----------------" << std::endl;

  one_pattern_table_match();
  multi_pattern_table_match();
  default_pattern_match();

  std::cout << "---------------------------------------------------------------" << std::endl << std::endl;
}
