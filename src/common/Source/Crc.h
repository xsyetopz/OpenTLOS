#ifndef COMMON_SOURCE_CRC_H
#define COMMON_SOURCE_CRC_H

#include <dolphin/types.h>

s32 Crc_Calculate(const void *, int);
u32 Crc_Update(unsigned int, const void *, int);
#endif  // COMMON_SOURCE_CRC_H
