#ifndef SPYRO_SOURCE_GONDOLA_H
#define SPYRO_SOURCE_GONDOLA_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/Platform.h"

class EnemyGenerator;
class EnemyGeneratorDescriptor;
class Gondola;
class GondolaDescriptor;
class Gondola_cpp;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;
class Platform;
class SkyClouds;

class Gondola : public Platform {  // base: vtable prefix
public:
    class WaveMotion {
    public:
        void Update(void);
        void Init(void);
    };
    virtual ~Gondola(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void UpdateMove(void);
    Gondola(void);
    void SetDefaults(void);
    /* 0x17c */ u8 pad17C[0x4];
    /* 0x180 */ s32 unk180;
    /* 0x184 */ u8 pad184[0x8];
    /* 0x18c */ s32 unk18C;
    /* 0x190 */ u8 pad190[0x4];
    /* 0x194 */ s32 unk194;
    /* 0x198 */ u8 pad198[0x8];
    /* 0x1a0 */ s32 unk1A0;
    /* 0x1a4 */ u8 pad1A4[0x4];
    /* 0x1a8 */ f32 unk1A8;
    /* 0x1ac */ Gondola::WaveMotion unk1AC;
    /* 0x1ad */ u8 pad1AD[0x3];
    /* 0x1b0 */ EnemyGenerator unk1B0;
    /* 0x236 */ u8 pad236[0x2];
    /* 0x238 */ SkyClouds* unk238;
    /* 0x23c */ f32 unk23C;
    /* 0x240 */ s32 unk240;
    /* 0x244 */ s32 unk244;
    /* 0x248 */ s32 unk248;
    /* 0x24c */ u8 unk24C;
};

class GondolaDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    GondolaDescriptor(void);
    /* 0x048 */ u8 pad48[0xdc];
    /* 0x124 */ EnemyGeneratorDescriptor unk124;
};

class Gondola_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_GONDOLA_H
