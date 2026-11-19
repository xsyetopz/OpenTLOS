#ifndef SPYRO_SOURCE_KDCAMERADELTADRAG_H
#define SPYRO_SOURCE_KDCAMERADELTADRAG_H

#include <dolphin/types.h>

class KDCameraDeltaDrag;
class MKVector3;

class KDCameraDeltaDrag {
public:
    f32 SmoothDrag(float);
    u8 Disable(bool);
    void ClearData(void);
    void Update(const MKVector3 &);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ u8 unk10;
    /* 0x011 */ u8 unk11;
};

#endif  // SPYRO_SOURCE_KDCAMERADELTADRAG_H
