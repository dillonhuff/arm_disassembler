#ifndef BIT_PATTERN_TABLE_H_
#define BIT_PATTERN_TABLE_H_

#include <iostream>
#include <utility>
#include <vector>

#include "utils/bit_field.h"
#include "utils/bit_pattern.h"

template <class T>
class bit_pattern_table {
private:
  std::vector<std::pair<bit_pattern, T>> pattern_pairs;

public:
  bit_pattern_table(bit_pattern* ps, T* ts, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
      pattern_pairs.push_back(std::pair<bit_pattern, T>(ps[i], ts[i]));
    }
  }

  T match(bit_field* bits) {
    for (auto pat_pair : pattern_pairs) {
      if (pat_pair.first.matches(bits)) {
	return pat_pair.second;
      }
    }
    std::cout << "Error: No match in bit pattern table" << std::endl;
    throw;
  }
};

#endif
