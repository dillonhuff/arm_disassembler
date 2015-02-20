#include <assert.h>
#include <iostream>

#include "utils/bit_pattern.h"

bit_pattern::bit_pattern(std::vector<bit_p> bits) {
  pattern = bits;
}

bit_pattern::bit_pattern(bit_p val, unsigned int n) {
  for (unsigned int i = 0; i < n; i++) {
    pattern.push_back(val);
  }
}

bit_pattern::bit_pattern(std::string pat_str) {
  assert(pat_str.size() > 0);
  for (unsigned int i = 0; i < pat_str.size(); i++) {
    if (pat_str[i] == '1') {
      pattern.push_back(one);
    } else if (pat_str[i] == '0') {
      pattern.push_back(zero);
    } else if (pat_str[i] == 'x') {
      pattern.push_back(any);
    } else {
      std::cout << "Error: " << pat_str << " is not a valid pattern string" << std::endl;
      throw;
    }
  }
}

bool bit_pattern::matches(bit_field* bits) {
  assert(bits->size() == pattern.size());
  for (unsigned int i = 0; i < bits->size(); i++) {
    unsigned int k = bits->size() - i - 1;
    if ((pattern[i] != any) &&
	(((*bits)[k] == ONE && pattern[i] == zero) ||
	 ((*bits)[k] == ZERO && pattern[i] == one))) {
      return false;
    }
  }
  return true;
}

bit_pattern bit_pattern::operator+(bit_pattern other) {
  std::vector<bit_p> new_pat_bits;
  for (auto bit : pattern) {
    new_pat_bits.push_back(bit);
  }
  for (auto bit : other.pattern) {
    new_pat_bits.push_back(bit);
  }
  return bit_pattern(new_pat_bits);
}
