#ifndef COMMON_SOURCE_MKVECTOR3_H
#define COMMON_SOURCE_MKVECTOR3_H

#include <dolphin/types.h>

class MKVector3;
class MKVector3_cpp;

class MKVector3 {
public:
    void operator*(float) const;
    f32 Magnitude(void) const;
    void operator/(float) const;
    f32 Normalise(void);
    void operator-(void) const;
    void operator-(const MKVector3 &) const;
    void operator+(const MKVector3 &) const;
    f32 MagSquared(void) const;
    u8 IsNear(const MKVector3 &, float) const;
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
};

class MKVector3_cpp {
public:
    void __sinit(void);
};

void Max(const MKVector3 &, const MKVector3 &);
void Min(const MKVector3 &, const MKVector3 &);
#endif  // COMMON_SOURCE_MKVECTOR3_H
