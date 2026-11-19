#ifndef SPYRO_SOURCE_ANIMUTILS_H
#define SPYRO_SOURCE_ANIMUTILS_H

#include <dolphin/types.h>

class AnimEntry;
class AnimEventDesc;
class AnimEventEntry;
class AnimEventManager;
class AnimManager;
class MKAnimScript;

class AnimEventDesc {
public:
    void Init(AnimEventEntry *, int, MKAnimScript *);
    /* 0x000 */ AnimEventEntry* unk0;
    /* 0x004 */ s32 unk4;
};

class AnimEventManager {
public:
    void Update(MKAnimScript *);
    void Init(AnimEventDesc *);
    /* 0x000 */ AnimEventDesc* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
};

class AnimManager {
public:
    void Init(AnimEntry *, int, MKAnimScript *);
    /* 0x000 */ AnimEntry* unk0;
    /* 0x004 */ s32 unk4;
};

#endif  // SPYRO_SOURCE_ANIMUTILS_H
