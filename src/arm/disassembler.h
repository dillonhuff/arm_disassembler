#ifndef DISASSEMBLER_H_
#define DISASSEMBLER_H_

#include "arm/instruction_sequence.h"
#include "utils/bit.h"
#include "utils/endianness.h"

std::unique_ptr<instruction_sequence> disassemble_arm7m(unsigned int start_address, endianness end, byte* bytes, unsigned int num_bytes);

#endif
