#ifndef COMMON_SOURCE_MKSPLINETUBE_H
#define COMMON_SOURCE_MKSPLINETUBE_H

#include <dolphin/types.h>

class MKSplineTube_cpp;

class MKSplineTube_cpp {
public:
    void __sinit(void);
};

void MKSplineTube_InitModule(float, float, float);
extern u8 posMixer[0x40];
extern u8 velMixer[0x40];
extern u8 spacing[0x200];
extern f32 distScale;
#endif  // COMMON_SOURCE_MKSPLINETUBE_H
