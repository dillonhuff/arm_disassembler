#include <assert.h>
#include <iostream>

#include "utils/bit_field.h"

void bit_field::pack_byte(unsigned char byte) {
  for (unsigned int i = 0; i < BITS_PER_BYTE; i++) {
    bits.push_back(get_bit(byte, i));
  }
}

void bit_field::pack_le_word(unsigned char* bytes, unsigned int bytes_per_word) {
  for (unsigned int i = 0; i < bytes_per_word; i++) {
    pack_byte(bytes[i]);
  }
}

void bit_field::pack_le_bits(unsigned int bytes_per_word, unsigned char* bytes, unsigned int num_bytes) {
  for (unsigned int i = 0; i < num_bytes; i += bytes_per_word) {
    pack_le_word(bytes, bytes_per_word);
    bytes += bytes_per_word;
  }
}

bit_field::bit_field(endianness end, unsigned int bytes_per_word, unsigned char* bytes, unsigned int num_bytes) {
  assert(num_bytes % bytes_per_word == 0);

  if (end == LITTLE) {
    pack_le_bits(bytes_per_word, bytes, num_bytes);
  } else {
    std::cout << "Big endian not yet supported" << std::endl;
    throw;
  }
}

bit bit_field::operator[](unsigned int i) {
  assert(bits.size() > i && i >= 0);
  return bits[i];
}
