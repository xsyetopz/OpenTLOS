#ifndef SPYRO_SOURCE_STEAMTRAINCABOOSE_H
#define SPYRO_SOURCE_STEAMTRAINCABOOSE_H

#include <dolphin/types.h>
#include "spyro/source/EventMessage.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnerObject.h"
#include "unplaced_enums.h"

class Enemy;
class EventMessage;
class GameProp;
class GamePropDescriptor;
class MKIniLine;
class MKMessage;
class MKProp;
class MKSceneManager;
class Shadow;
class SpawnerObject;
class SteamTrainCaboose;
class SteamTrainCabooseDescriptor;
class TrainChaseSpawnPool;

class SteamTrainCaboose : public GameProp {  // base: base ctor call
public:
    virtual ~SteamTrainCaboose(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    virtual void Enable(void);
    virtual void Disable(void);
    SteamTrainCaboose(void);
    void GetVel(void);
    void SetState(SteamTrainCabooseState);
    u8 IsBlownUp(void);
    void BlowUp(void);
    /* 0x0c8 */ s32 unkC8;
    /* 0x0cc */ MKSceneManager* unkCC;
    /* 0x0d0 */ MKSceneManager* unkD0;
    /* 0x0d4 */ f32 unkD4;
    /* 0x0d8 */ u8 unkD8;
    /* 0x0d9 */ u8 padD9[0x3];
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ Shadow unkE0;
    /* 0x110 */ SpawnerObject unk110;
    /* 0x160 */ TrainChaseSpawnPool* unk160;
};

class SteamTrainCabooseDescriptor : public GamePropDescriptor {  // base: base ctor call
public:
    virtual void LoadDone(void);
    SteamTrainCabooseDescriptor(void);
    /* 0x0e8 */ s32 unkE8;
    /* 0x0ec */ s32 unkEC;
    /* 0x0f0 */ s32 unkF0;
    /* 0x0f4 */ s32 unkF4;
};

class TrainChaseSpawnPool {
public:
    void Destroy(Enemy *);
    Enemy * Create(void);
    void Action(SpawnAction, int, MKProp **, SpawnerObject *);
    void Deinit(void);
    void Init(void);
    static u8 pInstance[0x4];
    /* 0x000 */ Enemy*** unk0;
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ EventMessage unk8;
    /* 0x00c */ EventMessage unkC;
    /* 0x010 */ EventMessage unk10;
    /* 0x014 */ EventMessage unk14;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier '__vptr'
inline SteamTrainCaboose::SteamTrainCaboose() {
    this->unk110.__vptr = &__vt;
    this->unk110.unk3C.unk0 = 0;
    this->unk110.unk3C.Init();
    this->unk110.unk40.unk0 = 0;
    this->unk110.unk40.Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier '__vptr'
inline SteamTrainCaboose::~SteamTrainCaboose() {
    EventMessage *temp_r3_24;
    EventMessage *temp_r3_30;

    if (this != NULL) {
        if (&this->unk110 != NULL) {
            temp_r3_24 = &this->unk110.unk40;
            this->unk110.__vptr = &__vt;
            if (temp_r3_24 != NULL) {
                temp_r3_24->Deinit();
            }
            temp_r3_30 = &this->unk110.unk3C;
            if (temp_r3_30 != NULL) {
                temp_r3_30->Deinit();
            }
        }
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline SteamTrainCabooseDescriptor::SteamTrainCabooseDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_STEAMTRAINCABOOSE_H
