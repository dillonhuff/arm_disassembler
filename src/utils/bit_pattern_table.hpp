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
  T default_case;
  std::vector<std::pair<bit_pattern, T>> pattern_pairs;

public:
  bit_pattern_table(std::vector<std::pair<bit_pattern, T>> pat_pairs, T def) {
    default_case = def;
    pattern_pairs = pat_pairs;
  }

  bit_pattern_table(bit_pattern* ps, T* ts, T def, unsigned int n) {
    default_case = def;
    for (unsigned int i = 0; i < n; i++) {
      pattern_pairs.push_back(std::pair<bit_pattern, T>(ps[i], ts[i]));
    }
  }

  bit_pattern_table(std::vector<std::pair<bit_pattern, T>> pat_pairs) {
    pattern_pairs = pat_pairs;
  }

  T match(bit_field* bits) {
    for (auto pat_pair : pattern_pairs) {
      if (pat_pair.first.matches(bits)) {
	return pat_pair.second;
      }
    }
    return default_case;
  }
};

#endif
