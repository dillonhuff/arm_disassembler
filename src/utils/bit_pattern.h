#ifndef BIT_PATTERN_H_
#define BIT_PATTERN_H_

#include <vector>

#include "utils/bit_field.h"

enum bit_p { zero, one, any };

class bit_pattern {
 private:
  std::vector<bit_p> pattern;

  bit_pattern(std::vector<bit_p> bits);

 public:
  bit_pattern(bit_p val, unsigned int n);

  bool matches(bit_field* bits);
  bit_pattern operator+(bit_pattern other);
};

#endif
