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

void le_28th_bit() {
  unsigned char bytes[4] = {0x00, 0x00, 0x00, 0x10};
  auto word32 = bit_field(LITTLE, 4, bytes, 4);
  test_result(word32[28] == ONE, "le 28th bit", "28th bit is not one");
}

void le_size_64() {
  unsigned char bytes[8] = {0x01, 0xff, 0x4b, 0xae, 0x32, 0x11, 0xcd, 0xc1};
  auto word64 = bit_field(LITTLE, 4, bytes, 8);
  test_result(word64.size() == 64, "word 64 size", "word 64 does not have size 64 bits");
}

void le_25th_bit_word16_twice() {
  unsigned char bytes[4] = {0x01, 0x02, 0x03, 0x04};
  auto two_word16 = bit_field(LITTLE, 2, bytes, 4);
  test_result(two_word16[25] == ONE, "25th bit of two consecutive le word16s", "25th bit is not one");
}

void le_word16_printout() {
  unsigned char bytes[2] = {0xb4, 0x12};
  auto word16 = bit_field(LITTLE, 2, bytes, 2);
  test_result(word16.to_bit_string() == "0001001010110100", "word16 bit string printout", "printout of 0x12b4 is not 0001001010110100");
}

void le_two_word16_printout() {
  unsigned char bytes[4] = {0x01, 0x02, 0x03, 0x04};
  auto two_word16 = bit_field(LITTLE, 2, bytes, 4);
  test_result(two_word16.to_bit_string() == "00000010000000010000010000000011", "two consecutive word16 printouts", "printout of 0x02010403 is not 0000 0010 0000 0001 0000 0100 0000 0011");
}

void all_bit_field_tests() {
  std::cout << "---------------------- bit_field tests ------------------------" << std::endl;

  le_first_bit();
  le_28th_bit();
  le_size_64();
  le_25th_bit_word16_twice();
  le_word16_printout();
  le_two_word16_printout();

  std::cout << "---------------------------------------------------------------" << std::endl;
}
