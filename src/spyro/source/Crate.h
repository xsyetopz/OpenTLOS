#ifndef SPYRO_SOURCE_CRATE_H
#define SPYRO_SOURCE_CRATE_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/PlatformObject.h"

class Attachment;
class Crate;
class CrateDescriptor;
class EventMessage;
class GameProp;
class KDPropEx;
class KDPropExDescriptor;
class MKIniLine;
class MKMessage;
class MKModel;
class MKProp;
class MKVector3;
class PlatformObject;
class ShatterObject;
class ShatterObjectDescriptor;
class ShockWave;

class Attachment {
public:
    /* 0x000 */ void* unk0;
    /* 0x004 */ Attachment* unk4;
    /* 0x008 */ Attachment* unk8;
};

class ShatterObject {
public:
    u8 Shatter(bool, MKVector3 *, int, MKVector3 *);
    void Draw(void);
    void Update(void);
    void Reset(void);
    void LoadDone(void);
    void LoadLine(MKIniLine *);
    void Deinit(void);
    void Init(ShatterObjectDescriptor *, KDPropEx *);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f64 unk20;
    /* 0x028 */ f64 unk28;
    /* 0x030 */ u8 pad30[0x8];
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ u8 pad40[0x4];
    /* 0x044 */ s32 unk44;
    /* 0x048 */ u8 pad48[0xc];
    /* 0x054 */ ShatterObjectDescriptor* unk54;
    /* 0x058 */ u16* unk58;
    /* 0x05c */ u16* unk5C;
    /* 0x060 */ u8 pad60[0x8];
    /* 0x068 */ s32 unk68;
    /* 0x06c */ s8 unk6C;
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ MKProp* unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ EventMessage unk78;
    /* 0x07c */ ShatterObjectDescriptor* unk7C;
    /* 0x080 */ MKProp* unk80;
};

class Crate : public GameProp {  // base: vtable prefix
public:
    virtual ~Crate(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void Shatter(bool);
    virtual void Respawn(void);
    Crate(void);
    void UpdateShadow(bool);
    void SpawnContents(void);
    void Shattering(void);
    void Spin(void);
    void Fall(void);
    void Burn(void);
    void ClearData(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ f32 unkCC;
    /* 0x0d0 */ f64 unkD0;
    /* 0x0d8 */ f64 unkD8;
    /* 0x0e0 */ ShatterObject unkE0;
    /* 0x164 */ u8 pad164[0x4];
    /* 0x168 */ f32 unk168;
    /* 0x16c */ f32 unk16C;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ f32 unk174;
    /* 0x178 */ u8 unk178;
    /* 0x179 */ u8 pad179[0x3];
    /* 0x17c */ u32 unk17C;
    /* 0x180 */ s32 unk180;
    /* 0x184 */ s32 unk184;
    /* 0x188 */ MKModel* unk188;
    /* 0x18c */ u8 pad18C[0x4];
    /* 0x190 */ PlatformObject unk190;
    /* 0x1d4 */ u8 pad1D4[0x4];
    /* 0x1d8 */ ShockWave* unk1D8;
    /* 0x1dc */ Attachment unk1DC;
};

class ShatterObjectDescriptor {
public:
    void LoadDone(MKModel *, const char *);
    u8 LoadLine(MKIniLine *, const char *);
    void Init(KDPropExDescriptor *);
    /* 0x000 */ u16 unk0;
    /* 0x002 */ s16 unk2;
    /* 0x004 */ u8 pad4[0x20];
    /* 0x024 */ u16 unk24;
    /* 0x026 */ s16 unk26;
    /* 0x028 */ u8 pad28[0x20];
    /* 0x048 */ u16 unk48;
    /* 0x04a */ s16 unk4A;
    /* 0x04c */ u8 pad4C[0x20];
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ KDPropExDescriptor* unk88;
    /* 0x08c */ s32 unk8C;
};

class CrateDescriptor : public KDPropExDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    CrateDescriptor(void);
    /* 0x0c0 */ u8 padC0[0x24];
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ s32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ s32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ f32 unk118;
    /* 0x11c */ f32 unk11C;
    /* 0x120 */ s8 unk120;
    /* 0x121 */ u8 unk121;
    /* 0x122 */ u8 pad122[0x2];
    /* 0x124 */ u8 unk124;
    /* 0x125 */ u8 pad125[0x3];
    /* 0x128 */ ShatterObjectDescriptor unk128;
    /* 0x1b8 */ u8 unk1B8;
    /* 0x1b9 */ u8 pad1B9[0x3];
    /* 0x1bc */ f32 unk1BC;
    /* 0x1c0 */ f32 unk1C0;
    /* 0x1c4 */ f32 unk1C4;
    /* 0x1c8 */ s32 unk1C8;
};

extern u8 crateDescFlags[0x50];
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier 'unk4'
inline Crate::~Crate() {
    EventMessage *temp_r3_56;
    PlatformAttachment *temp_r0_41;
    ShockWave **temp_r4_26;
    f32 *temp_r4_39;
    void *temp_r0_23;

    if (this != NULL) {
        if (&this->unk1D8 != NULL) {
            temp_r0_23 = this->unk1DC.unk0;
            if (temp_r0_23 != NULL) {
                temp_r4_26 = &this->unk1D8;
                if (temp_r0_23 != temp_r4_26) {
                    this->unk1DC.unk4->unk4 = (Attachment *) temp_r0_23;
                    M2C_FIELD(this->unk1DC.unk0, Attachment **, 8) = (Attachment *) this->unk1DC.unk4;
                    this->unk1DC.unk4 = (Attachment *) temp_r4_26;
                    this->unk1DC.unk0 = temp_r4_26;
                }
            }
        }
        if (&this->unk190 != NULL) {
            temp_r4_39 = &this->unk190.unk18.unkC;
            if (temp_r4_39 != NULL) {
                temp_r0_41 = this->unk190.unk28.unk4;
                if ((temp_r0_41 != NULL) && (temp_r0_41 != temp_r4_39)) {
                    this->unk190.unk28.unk8->unk8 = temp_r0_41;
                    this->unk190.unk28.unk4->unkC = this->unk190.unk28.unk8;
                    this->unk190.unk28.unk8 = (PlatformAttachment *) temp_r4_39;
                    this->unk190.unk28.unk4 = (PlatformAttachment *) temp_r4_39;
                }
            }
        }
        if (&this->unkE0 != NULL) {
            temp_r3_56 = &this->unkE0.unk78;
            if (temp_r3_56 != NULL) {
                temp_r3_56->Deinit();
            }
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk4'
inline Crate::Crate() {
    ShockWave **temp_r0_18686;
    f32 *temp_r4_18684;

    this->unkE0.unk78.unk0 = 0;
    this->unkE0.unk78.Init();
    temp_r4_18684 = &this->unk190.unk18.unkC;
    this->unk190.unk18.unkC = 0.0f;
    temp_r0_18686 = &this->unk1D8;
    this->unk190.unk28.unk0 = NULL;
    this->unk190.unk28.unk4 = temp_r4_18684;
    this->unk190.unk28.unk8 = (PlatformAttachment *) temp_r4_18684;
    this->unk1D8 = NULL;
    this->unk1DC.unk0 = temp_r0_18686;
    this->unk1DC.unk4 = (Attachment *) temp_r0_18686;
    return this;
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline CrateDescriptor::CrateDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_CRATE_H
