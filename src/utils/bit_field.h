#ifndef BIT_FIELD_H_
#define BIT_FIELD_H_

#include <string>
#include <vector>

#include "utils/bit.h"
#include "utils/endianness.h"

class bit_field {
 private:
  std::vector<bit> bits;

  void pack_byte(unsigned char byte);
  void pack_le_word(unsigned char* bytes, unsigned int bytes_per_word);
  void pack_le_bits(unsigned int bytes_per_word, unsigned char* bytes, unsigned int num_bytes);

 public:
  bit_field(endianness end, unsigned int bytes_per_word, unsigned char* bytes, unsigned int num_bytes);

  unsigned int size();
  bit operator[](unsigned int);

  std::string to_bit_string();
};

#endif
