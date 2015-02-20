#include <assert.h>

#include "utils/bit.h"

bit get_bit(unsigned char byte, unsigned int index) {
  return (((byte >> index) & 0x01) == 0) ? ZERO : ONE;
}
