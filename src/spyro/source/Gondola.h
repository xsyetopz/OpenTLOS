#ifndef SPYRO_SOURCE_GONDOLA_H
#define SPYRO_SOURCE_GONDOLA_H

#include <dolphin/types.h>
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/Platform.h"

class EnemyGenerator;
class Gondola;
class GondolaDescriptor;
class Gondola_cpp;
class MKIniLine;
class MKMessage;
class Platform;
class PlatformDescriptor;
class SkyClouds;

class Gondola : public Platform {  // base: base ctor call
public:
    class WaveMotion {
    public:
        void Update(void);
        void Init(void);
        /* 0x000 */ s8 unk0;
    };
    virtual ~Gondola(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void UpdateMove(void);
    Gondola(void);
    void SetDefaults(void);
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
    /* 0x238 */ SkyClouds* unk238;
    /* 0x23c */ f32 unk23C;
    /* 0x240 */ s32 unk240;
    /* 0x244 */ s32 unk244;
    /* 0x248 */ s32 unk248;
    /* 0x24c */ u8 unk24C;
};

class GondolaDescriptor : public PlatformDescriptor {  // base: base ctor call
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    GondolaDescriptor(void);
};

class Gondola_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk184'
inline Gondola::Gondola() {
    EnemyGenerator *temp_r30_21538;

    temp_r30_21538 = &this->unk1B0;
    this->unk180 = 0;
    this->unk184 = 0;
    this->unk188 = 0.0f;
    this->unk18C = 0;
    this->unk194 = 0;
    this->unk198 = 0;
    this->unk19C = 0.0f;
    this->unk1A0 = 0;
    this->unk1B0.__vptr = &__vt;
    this->unk1B0.unk3C.unk0 = 0;
    temp_r30_21538->unk3C.Init();
    this->unk1B0.unk40.unk0 = 0;
    temp_r30_21538->unk40.Init();
    this->unk1B0.__vptr = &__vt;
    this->unk1B0.unk68.unk0 = 0;
    temp_r30_21538->unk68.Init();
    this->unk1B0.unk6C.unk0 = 0;
    temp_r30_21538->unk6C.Init();
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
inline Gondola::~Gondola() {
    EventMessage *temp_r3_24;
    EventMessage *temp_r3_30;
    EventMessage *temp_r3_37;
    EventMessage *temp_r3_43;

    if (this != NULL) {
        if (&this->unk1B0 != NULL) {
            temp_r3_24 = &this->unk1B0.unk6C;
            this->unk1B0.__vptr = &__vt;
            if (temp_r3_24 != NULL) {
                temp_r3_24->Deinit();
            }
            temp_r3_30 = &this->unk1B0.unk68;
            if (temp_r3_30 != NULL) {
                temp_r3_30->Deinit();
            }
            if (&this->unk1B0 != NULL) {
                temp_r3_37 = &this->unk1B0.unk40;
                this->unk1B0.__vptr = &__vt;
                if (temp_r3_37 != NULL) {
                    temp_r3_37->Deinit();
                }
                temp_r3_43 = &this->unk1B0.unk3C;
                if (temp_r3_43 != NULL) {
                    temp_r3_43->Deinit();
                }
            }
        }
    }
}
#endif

inline GondolaDescriptor::GondolaDescriptor() {
}

#endif  // SPYRO_SOURCE_GONDOLA_H
