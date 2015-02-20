#ifndef BIT_FIELD_H_
#define BIT_FIELD_H_

#include <vector>

#include "utils/bit.h"
#include "utils/endianness.h"

class bit_field {
 private:
  std::vector<bit> bits;

 private:
  void pack_byte(unsigned char byte);
  void pack_le_word(unsigned char* bytes, unsigned int bytes_per_word);
  void pack_le_bits(unsigned int bytes_per_word, unsigned char* bytes, unsigned int num_bytes);

 public:
  bit_field(endianness end, unsigned int bytes_per_word, unsigned char* bytes, unsigned int num_bytes);

  bit operator[](unsigned int);
};

#endif
