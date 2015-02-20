#include <iostream>

#include "test_utils/test_result.h"

unsigned int test_result(bool result, std::string test_name, std::string fail_msg) {
  if (result) {
    return 0;
  } else {
    return 1;
  }
}
