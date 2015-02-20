#include <iostream>

#include "test_utils/test_result.h"
#include "utils/bit.h"
#include "utils/bit_field.h"
#include "utils/endianness.h"

void le_first_bit() {
  unsigned char bytes[2] = {0x01, 0x00};
  auto word16 = bit_field(LITTLE, 2, bytes, 2);
  test_result(word16[0] == ONE, "le first bit", "first bit is not one");
}

void all_bit_field_tests() {
  std::cout << "---------------------- bit_field tests ------------------------" << std::endl;

  le_first_bit();

  std::cout << "---------------------------------------------------------------" << std::endl;
}
