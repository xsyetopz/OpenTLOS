#ifndef SPYRO_SOURCE_GLOWINGPROPMANAGER_H
#define SPYRO_SOURCE_GLOWINGPROPMANAGER_H

#include <dolphin/types.h>

class GlowingProp;
class GlowingPropManager;
class MKMaterial;
class MKProp;

class GlowingProp {
public:
    void EndGlowingPropDraw(void);
    void BeginGlowingPropDraw(MKProp *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ MKMaterial* unk10;
    /* 0x014 */ u8 unk14;
};

class GlowingPropManager {
public:
    static u8 AddProp(MKProp *);
    void Deinit(void);
    void Draw(void);
    void Init(void);
    /* 0x000 */ MKProp*** unk0;
};

extern GlowingPropManager gGlowingPropManager;
#endif  // SPYRO_SOURCE_GLOWINGPROPMANAGER_H
