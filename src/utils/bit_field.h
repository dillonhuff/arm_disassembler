#ifndef BIT_FIELD_H_
#define BIT_FIELD_H_

#include "utils/endianness.h"

class bit_field {
 public:
  bit_field(endianness end, unsigned int bytes_per_word, unsigned char* bytes, unsigned int num_bytes);
};

#endif
