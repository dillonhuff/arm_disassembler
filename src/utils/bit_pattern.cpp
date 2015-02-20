#include <assert.h>

#include "bit_pattern.h"

bit_pattern::bit_pattern(bit_p val, unsigned int n) {
  for (unsigned int i = 0; i < n; i++) {
    pattern.push_back(val);
  }
}

bool bit_pattern::matches(bit_field* bits) {
  assert(bits->size() == pattern.size());
  for (unsigned int i = 0; i < bits->size(); i++) {
    if ((pattern[i] != any) &&
	(((*bits)[i] == ONE && pattern[i] == zero) ||
	 ((*bits)[i] == ZERO && pattern[i] == one))) {
      return false;
    }
  }
  return true;
}
