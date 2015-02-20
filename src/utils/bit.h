#ifndef BIT_H_
#define BIT_H_

#define BITS_PER_BYTE 8

enum bit { ZERO, ONE };

bit get_bit(unsigned char byte, unsigned int index);

#endif
