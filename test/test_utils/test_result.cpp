#include <iostream>

#include "test_utils/test_result.h"

unsigned int test_result(bool result, std::string test_name, std::string fail_msg) {
  std::cout << test_name;
  if (result) {
    std::cout << " passed" << std::endl;
    return 0;
  } else {
    std::cout << " FAILED: " << fail_msg << std::endl;
    return 1;
  }
}
