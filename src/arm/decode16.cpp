#include "decode16.h"

instruction decode16(bit_field* word16) {
  return lsl_16(4, 0, 1);
}
