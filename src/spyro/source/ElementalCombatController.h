#ifndef SPYRO_SOURCE_ELEMENTALCOMBATCONTROLLER_H
#define SPYRO_SOURCE_ELEMENTALCOMBATCONTROLLER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/SpawnerObject.h"

class ElementalCombatController;
class ElementalCombatController_cpp;
class EventMessage;
class MKIniLine;
class MKMessage;
class MKProp;
class SpawnerObject;

class ElementalCombatController : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~ElementalCombatController(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    void AttemptSpawn(void);
    void SetupSpawnPoints(void);
    /* 0x04c */ u8 pad4C[0x48];
    /* 0x094 */ f32 unk94;
    /* 0x098 */ f32 unk98;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ u8 padAC[0x4];
    /* 0x0b0 */ EventMessage unkB0;
    /* 0x0b4 */ u8 padB4[0x4];
    /* 0x0b8 */ f32 unkB8;
    /* 0x0bc */ f32 unkBC;
    /* 0x0c0 */ f32 unkC0;
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ SpawnerObject unkC8;
    /* 0x115 */ u8 pad115[0x24b];
    /* 0x360 */ s32 unk360;
    /* 0x364 */ s32 unk364;
    /* 0x368 */ s32 unk368;
    /* 0x36c */ s32 unk36C;
    /* 0x370 */ s32 unk370;
    /* 0x374 */ s32 unk374;
    /* 0x378 */ s32 unk378;
    /* 0x37c */ s32 unk37C;
    /* 0x380 */ s32 unk380;
    /* 0x384 */ s32 unk384;
    /* 0x388 */ s32 unk388;
    /* 0x38c */ s32 unk38C;
    /* 0x390 */ s32 unk390;
    /* 0x394 */ s32 unk394;
    /* 0x398 */ s32 unk398;
    /* 0x39c */ s32 unk39C;
    /* 0x3a0 */ EventMessage unk3A0;
    /* 0x3a4 */ EventMessage unk3A4;
    /* 0x3a8 */ EventMessage unk3A8;
    /* 0x3ac */ EventMessage unk3AC;
    /* 0x3b0 */ EventMessage unk3B0;
    /* 0x3b4 */ EventMessage unk3B4;
    /* 0x3b8 */ EventMessage unk3B8;
    /* 0x3bc */ EventMessage unk3BC;
    /* 0x3c0 */ EventMessage unk3C0;
    /* 0x3c4 */ EventMessage unk3C4;
    /* 0x3c8 */ EventMessage unk3C8;
    /* 0x3cc */ EventMessage unk3CC;
    /* 0x3d0 */ EventMessage unk3D0;
    /* 0x3d4 */ EventMessage unk3D4;
    /* 0x3d8 */ EventMessage unk3D8;
    /* 0x3dc */ EventMessage unk3DC;
    /* 0x3e0 */ s32 unk3E0;
    /* 0x3e4 */ s32 unk3E4;
    /* 0x3e8 */ u8 unk3E8;
    /* 0x3e9 */ u8 pad3E9[0x3];
    /* 0x3ec */ f32 unk3EC;
    /* 0x3f0 */ f32 unk3F0;
};

class ElementalCombatController_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: '(' expected
inline ElementalCombatController::~ElementalCombatController() {
    EventMessage *temp_r3_30;
    EventMessage *temp_r3_36;

    if (this != NULL) {
        __destroy_arr(&this->unk39C, &EventMessage::~EventMessage, 4, 0x10);
        if (&this->unkC8 != NULL) {
            temp_r3_30 = &this->unkC8.unk40;
            this->unkC8.__vptr = &__vt;
            if (temp_r3_30 != NULL) {
                temp_r3_30->Deinit();
            }
            temp_r3_36 = &this->unkC8.unk3C;
            if (temp_r3_36 != NULL) {
                temp_r3_36->Deinit();
            }
        }
        if (&this->unkB0 != NULL) {
            this->unkB0.Deinit();
        }
        if (this != NULL) {
        }
    }
}
#endif

#endif  // SPYRO_SOURCE_ELEMENTALCOMBATCONTROLLER_H
