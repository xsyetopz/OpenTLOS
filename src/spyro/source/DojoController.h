#ifndef SPYRO_SOURCE_DOJOCONTROLLER_H
#define SPYRO_SOURCE_DOJOCONTROLLER_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/SpawnerObject.h"
#include "unplaced_enums.h"

class CharacterGraphNode;
class DojoController;
class DojoController_cpp;
class DojoLesson;
class DragonStatue;
class EarthDojoLesson;
class ElectricDojoLesson;
class EventMessage;
class FireDojoLesson;
class IceDojoLesson;
class MKIniLine;
class MKMessage;
class MKProp;
class MKSceneManager;
class MKVector3;
class SpawnPointData;
class SpawnerObject;

class DojoController : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~DojoController(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    void StateDojoStatueUpExit(void);
    void StateDojoStatueUpUpdate(void);
    void StateDojoStatueUpEnter(void);
    void StateDojoFinishExit(void);
    void StateDojoFinishUpdate(void);
    void StateDojoFinishEnter(void);
    void StateDojoSuccessExit(void);
    void StateDojoSuccessUpdate(void);
    void StateDojoSuccessEnter(void);
    void StateDojoFailExit(void);
    void StateDojoFailUpdate(void);
    void StateDojoFailEnter(void);
    void StateDojoFightExit(void);
    void StateDojoFightUpdate(void);
    void StateDojoFightEnter(void);
    void StateDojoInstructExit(void);
    void StateDojoInstructUpdate(void);
    void StateDojoInstructEnter(void);
    void StateDojoStatueDownExit(void);
    void StateDojoStatueDownUpdate(void);
    void StateDojoStatueDownEnter(void);
    void StateDojoWaitingForActivateExit(void);
    void StateDojoWaitingForActivateUpdate(void);
    void StateDojoWaitingForActivateEnter(void);
    void PlayButtonTone(void);
    void SetupSmashPropsVanguard(int, MKVector3, MKVector3, float, bool, bool, float);
    void SetupSpawnPointsRandomGraph(DojoTiers, CharacterGraphNode *, int, int, CharacterGraphNode **, bool, float, float, unsigned int);
    void SetupSpawnPointsVanguard(DojoTiers, MKVector3, MKVector3, float, bool, bool, float, unsigned int);
    void AddCombatArc(unsigned int);
    void ClearCombatArcs(void);
    void AttemptSpawn(void);
    DojoController(void);
    /* 0x04c */ EventMessage unk4C;
    /* 0x050 */ EventMessage unk50;
    /* 0x054 */ EventMessage unk54;
    /* 0x058 */ EventMessage unk58;
    /* 0x05c */ MKSceneManager* unk5C;
    /* 0x060 */ MKSceneManager* unk60;
    /* 0x064 */ MKSceneManager* unk64;
    /* 0x068 */ MKSceneManager* unk68;
    /* 0x06c */ MKSceneManager* unk6C;
    /* 0x070 */ void** unk70;
    /* 0x074 */ u8 pad74[0x24c];
    /* 0x2c0 */ SpawnerObject unk2C0;
    /* 0x30d */ u8 pad30D[0x3];
    /* 0x310 */ SpawnerObject unk310;
    /* 0x35d */ u8 pad35D[0x7];
    /* 0x364 */ s32 unk364;
    /* 0x368 */ s32 unk368;
    /* 0x36c */ s32 unk36C;
    /* 0x370 */ u8 pad370[0x8];
    /* 0x378 */ MKVector3 unk378;
    /* 0x388 */ f64 unk388;
    /* 0x390 */ f64 unk390;
    /* 0x398 */ f32 unk398;
    /* 0x39c */ f32 unk39C;
    /* 0x3a0 */ u8 pad3A0[0x4];
    /* 0x3a4 */ f32 unk3A4;
    /* 0x3a8 */ f32 unk3A8;
    /* 0x3ac */ f32 unk3AC;
    /* 0x3b0 */ f32 unk3B0;
    /* 0x3b4 */ f32 unk3B4;
    /* 0x3b8 */ f32 unk3B8;
    /* 0x3bc */ u8 unk3BC;
    /* 0x3bd */ u8 pad3BD[0x1];
    /* 0x3be */ u8 unk3BE;
    /* 0x3bf */ u8 unk3BF;
    /* 0x3c0 */ s8 unk3C0;
    /* 0x3c1 */ u8 unk3C1;
    /* 0x3c2 */ u8 unk3C2;
    /* 0x3c3 */ u8 unk3C3;
    /* 0x3c4 */ u8 unk3C4;
    /* 0x3c5 */ u8 pad3C5[0x3];
    /* 0x3c8 */ s32 unk3C8;
    /* 0x3cc */ s32 unk3CC;
    /* 0x3d0 */ s32 unk3D0;
    /* 0x3d4 */ s32 unk3D4;
    /* 0x3d8 */ CharacterGraphNode* unk3D8;
    /* 0x3dc */ CharacterGraphNode* unk3DC;
    /* 0x3e0 */ CharacterGraphNode* unk3E0;
    /* 0x3e4 */ MKSceneManager* unk3E4;
    /* 0x3e8 */ MKSceneManager* unk3E8;
    /* 0x3ec */ MKSceneManager* unk3EC;
    /* 0x3f0 */ MKSceneManager* unk3F0;
    /* 0x3f4 */ s32 unk3F4;
    /* 0x3f8 */ s32 unk3F8;
    /* 0x3fc */ s32 unk3FC;
    /* 0x400 */ s32 unk400;
    /* 0x404 */ DragonStatue* unk404;
    /* 0x408 */ MKSceneManager* unk408;
    /* 0x40c */ u32 unk40C;
    /* 0x410 */ u32 unk410;
    /* 0x414 */ u32 unk414;
    /* 0x418 */ u32 unk418;
    /* 0x41c */ u32 unk41C;
    /* 0x420 */ u32 unk420;
    /* 0x424 */ u32 unk424;
    /* 0x428 */ u32 unk428;
    /* 0x42c */ u32 unk42C;
    /* 0x430 */ u32 unk430;
    /* 0x434 */ u32 unk434;
    /* 0x438 */ u32 unk438;
    /* 0x43c */ u32 unk43C;
    /* 0x440 */ u32 unk440;
    /* 0x444 */ u32 unk444;
    /* 0x448 */ s32 unk448;
    /* 0x44c */ SpawnPointData* unk44C;
    /* 0x450 */ SpawnPointData* unk450;
    /* 0x454 */ SpawnPointData* unk454;
    /* 0x458 */ SpawnPointData* unk458;
    /* 0x45c */ f32 unk45C;
    /* 0x460 */ f32 unk460;
    /* 0x464 */ f32 unk464;
    /* 0x468 */ s8 unk468;
    /* 0x469 */ u8 pad469[0x1ff];
    /* 0x668 */ s32 unk668;
    /* 0x66c */ f32 unk66C;
    /* 0x670 */ s32 unk670;
    /* 0x674 */ s32 unk674;
    /* 0x678 */ u8 unk678;
    /* 0x679 */ u8 unk679;
    /* 0x67a */ u8 pad67A[0x2];
    /* 0x67c */ s32 unk67C;
    /* 0x680 */ s32 unk680;
    /* 0x684 */ s32 unk684;
    /* 0x688 */ s32 unk688;
    /* 0x68c */ s32 unk68C;
    /* 0x690 */ s32 unk690;
    /* 0x694 */ s32 unk694;
    /* 0x698 */ s32 unk698;
    /* 0x69c */ s32 unk69C;
    /* 0x6a0 */ s32 unk6A0;
    /* 0x6a4 */ s32 unk6A4;
    /* 0x6a8 */ s32 unk6A8;
    /* 0x6ac */ s32 unk6AC;
    /* 0x6b0 */ f32 unk6B0;
    /* 0x6b4 */ s32 unk6B4;
    /* 0x6b8 */ s32 unk6B8;
    /* 0x6bc */ s32 unk6BC;
    /* 0x6c0 */ s32 unk6C0;
    /* 0x6c4 */ s32 unk6C4;
    /* 0x6c8 */ s32 unk6C8;
    /* 0x6cc */ s32 unk6CC;
    /* 0x6d0 */ s32 unk6D0;
    /* 0x6d4 */ s32 unk6D4;
    /* 0x6d8 */ s32 unk6D8;
    /* 0x6dc */ s32 unk6DC;
    /* 0x6e0 */ s32 unk6E0;
    /* 0x6e4 */ f32 unk6E4;
    /* 0x6e8 */ s32 unk6E8;
    /* 0x6ec */ s32 unk6EC;
    /* 0x6f0 */ s32 unk6F0;
    /* 0x6f4 */ s32 unk6F4;
    /* 0x6f8 */ s32 unk6F8;
    /* 0x6fc */ s32 unk6FC;
    /* 0x700 */ s32 unk700;
    /* 0x704 */ s32 unk704;
    /* 0x708 */ s32 unk708;
    /* 0x70c */ s32 unk70C;
    /* 0x710 */ s32 unk710;
    /* 0x714 */ s32 unk714;
    /* 0x718 */ s32 unk718;
    /* 0x71c */ f32 unk71C;
    /* 0x720 */ s32 unk720;
    /* 0x724 */ s32 unk724;
    /* 0x728 */ f32 unk728;
    /* 0x72c */ s32 unk72C;
    /* 0x730 */ s32 unk730;
    /* 0x734 */ s32 unk734;
    /* 0x738 */ s32 unk738;
    /* 0x73c */ s32 unk73C;
    /* 0x740 */ s32 unk740;
    /* 0x744 */ s32 unk744;
    /* 0x748 */ s32 unk748;
    /* 0x74c */ s32 unk74C;
    /* 0x750 */ s32 unk750;
    /* 0x754 */ s32 unk754;
    /* 0x758 */ s32 unk758;
    /* 0x75c */ f32 unk75C;
    /* 0x760 */ s32 unk760;
    /* 0x764 */ s32 unk764;
    /* 0x768 */ f32 unk768;
    /* 0x76c */ s32 unk76C;
    /* 0x770 */ s32 unk770;
    /* 0x774 */ s32 unk774;
    /* 0x778 */ s32 unk778;
    /* 0x77c */ s32 unk77C;
    /* 0x780 */ s32 unk780;
    /* 0x784 */ s32 unk784;
    /* 0x788 */ s32 unk788;
    /* 0x78c */ s32 unk78C;
    /* 0x790 */ s32 unk790;
    /* 0x794 */ s32 unk794;
    /* 0x798 */ s32 unk798;
    /* 0x79c */ f32 unk79C;
    /* 0x7a0 */ s32 unk7A0;
    /* 0x7a4 */ s32 unk7A4;
    /* 0x7a8 */ s32 unk7A8;
    /* 0x7ac */ f32 unk7AC;
    /* 0x7b0 */ s32 unk7B0;
    /* 0x7b4 */ s32 unk7B4;
    /* 0x7b8 */ s32 unk7B8;
    /* 0x7bc */ s32 unk7BC;
    /* 0x7c0 */ s32 unk7C0;
    /* 0x7c4 */ s32 unk7C4;
    /* 0x7c8 */ s32 unk7C8;
    /* 0x7cc */ s32 unk7CC;
    /* 0x7d0 */ s32 unk7D0;
    /* 0x7d4 */ s32 unk7D4;
    /* 0x7d8 */ s32 unk7D8;
    /* 0x7dc */ s32 unk7DC;
    /* 0x7e0 */ s32 unk7E0;
    /* 0x7e4 */ s32 unk7E4;
    /* 0x7e8 */ f32 unk7E8;
    /* 0x7ec */ s32 unk7EC;
    /* 0x7f0 */ u8 unk7F0;
    /* 0x7f1 */ s8 unk7F1;
    /* 0x7f2 */ u8 pad7F2[0x22];
    /* 0x814 */ f32 unk814;
    /* 0x818 */ s32 unk818;
    /* 0x81c */ s32 unk81C;
};

class DojoController_cpp {
public:
    void __sinit(void);
};

class DojoLesson {
public:
    virtual void Init(DojoController *, int);
    virtual void SetupNumEnemies(void) = 0;
    virtual void SetupSpawnPoints(void) = 0;
    virtual void SetupTimer(void) = 0;
    virtual s32 IsSubLessonComplete(void) = 0;
    virtual u8 IsLessonComplete(void) = 0;
    virtual s32 HasFailedLesson(void) = 0;
    virtual u8 HasSucceededLesson(void) = 0;
    virtual void IncrementNumInterations(void) = 0;
    virtual void TurnOffAbilities(void) = 0;
    virtual void MakeChildrenInvulnerable(void) = 0;
    void UpdateCombatArcs(void);
    /* 0x004 */ DojoController* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

class EarthDojoLesson : public DojoLesson {  // base: inlined ctor vtable stores
public:
    virtual void Init(DojoController *, int);
    virtual void SetupNumEnemies(void);
    virtual void SetupSpawnPoints(void);
    virtual void SetupTimer(void);
    virtual s32 IsSubLessonComplete(void);
    virtual u8 IsLessonComplete(void);
    virtual s32 HasFailedLesson(void);
    virtual u8 HasSucceededLesson(void);
    virtual void IncrementNumInterations(void);
    virtual void TurnOffAbilities(void);
    virtual void MakeChildrenInvulnerable(void);
    u8 HasSucceededFury(void);
    u8 HasSucceededBreath2(void);
    u8 HasSucceededBreath1(void);
    s32 HasFailedFury(void);
    s32 HasFailedBreath2(void);
    s32 HasFailedBreath1(void);
    s32 IsFuryComplete(void);
    void SetupFurySpawnPoints(void);
    void SetupNumFuryEnemies(void);
    s32 IsBreath2Complete(void);
    void SetupBreath2SpawnPoints(void);
    void SetupNumBreath2Enemies(void);
    s32 IsBreath1Complete(void);
    void SetupBreath1SpawnPoints(void);
    void SetupNumBreath1Enemies(void);
    /* 0x004 */ DojoController* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

class ElectricDojoLesson : public DojoLesson {  // base: inlined ctor vtable stores
public:
    virtual void Init(DojoController *, int);
    virtual void SetupNumEnemies(void);
    virtual void SetupSpawnPoints(void);
    virtual void SetupTimer(void);
    virtual s32 IsSubLessonComplete(void);
    virtual u8 IsLessonComplete(void);
    virtual s32 HasFailedLesson(void);
    virtual u8 HasSucceededLesson(void);
    virtual void IncrementNumInterations(void);
    virtual void TurnOffAbilities(void);
    virtual void MakeChildrenInvulnerable(void);
    u8 HasSucceededFury(void);
    u8 HasSucceededBreath2(void);
    u8 HasSucceededBreath1(void);
    s32 HasFailedFury(void);
    s32 HasFailedBreath2(void);
    s32 HasFailedBreath1(void);
    s32 IsFuryComplete(void);
    void SetupFurySpawnPoints(void);
    void SetupNumFuryEnemies(void);
    s32 IsBreath2Complete(void);
    void SetupBreath2SpawnPoints(void);
    void SetupNumBreath2Enemies(void);
    s32 IsBreath1Complete(void);
    void SetupBreath1SpawnPoints(void);
    void SetupNumBreath1Enemies(void);
    /* 0x004 */ DojoController* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

class FireDojoLesson : public DojoLesson {  // base: inlined ctor vtable stores
public:
    virtual void Init(DojoController *, int);
    virtual void SetupNumEnemies(void);
    virtual void SetupSpawnPoints(void);
    virtual void SetupTimer(void);
    virtual s32 IsSubLessonComplete(void);
    virtual u8 IsLessonComplete(void);
    virtual s32 HasFailedLesson(void);
    virtual u8 HasSucceededLesson(void);
    virtual void IncrementNumInterations(void);
    virtual void TurnOffAbilities(void);
    virtual void MakeChildrenInvulnerable(void);
    u8 HasSucceededFury(void);
    u8 HasSucceededBreath2(void);
    u8 HasSucceededBreath1(void);
    u8 HasSucceededMeleeKnockBack(void);
    u8 HasSucceededMeleeKnockUp(void);
    s32 HasFailedFury(void);
    s32 HasFailedBreath2(void);
    s32 HasFailedBreath1(void);
    s32 HasFailedMeleeKnockBack(void);
    s32 HasFailedMeleeKnockUp(void);
    s32 IsFuryComplete(void);
    void SetupFurySpawnPoints(void);
    void SetupNumFuryEnemies(void);
    s32 IsBreath2Complete(void);
    void SetupBreath2SpawnPoints(void);
    void SetupNumBreath2Enemies(void);
    s32 IsBreath1Complete(void);
    void SetupBreath1SpawnPoints(void);
    void SetupNumBreath1Enemies(void);
    s32 IsMeleeKnockBackComplete(void);
    void SetupMeleeKnockBackSpawnPoints(void);
    void SetupNumMeleeKnockBackEnemies(void);
    s32 IsMeleeKnockUpComplete(void);
    void SetupMeleeKnockUpSpawnPoints(void);
    void SetupNumMeleeKnockUpEnemies(void);
    /* 0x004 */ DojoController* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

class IceDojoLesson : public DojoLesson {  // base: inlined ctor vtable stores
public:
    virtual void Init(DojoController *, int);
    virtual void SetupNumEnemies(void);
    virtual void SetupSpawnPoints(void);
    virtual void SetupTimer(void);
    virtual s32 IsSubLessonComplete(void);
    virtual u8 IsLessonComplete(void);
    virtual s32 HasFailedLesson(void);
    virtual u8 HasSucceededLesson(void);
    virtual void IncrementNumInterations(void);
    virtual void TurnOffAbilities(void);
    virtual void MakeChildrenInvulnerable(void);
    u8 HasSucceededFury(void);
    u8 HasSucceededBreath2(void);
    u8 HasSucceededBreath1(void);
    s32 HasFailedFury(void);
    s32 HasFailedBreath2(void);
    s32 HasFailedBreath1(void);
    s32 IsFuryComplete(void);
    void SetupFurySpawnPoints(void);
    void SetupNumFuryEnemies(void);
    s32 IsBreath2Complete(void);
    void SetupBreath2SpawnPoints(void);
    void SetupNumBreath2Enemies(void);
    s32 IsBreath1Complete(void);
    void SetupBreath1SpawnPoints(void);
    void SetupNumBreath1Enemies(void);
    /* 0x004 */ DojoController* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vt'
inline DojoController::~DojoController() {
    EventMessage *temp_r3_14988;
    EventMessage *temp_r3_15001;
    EventMessage *temp_r3_15007;
    f32 *temp_r3_14994;

    if (this != NULL) {
        if (&this->unk310 != NULL) {
            temp_r3_14988 = &this->unk310.unk3C;
            M2C_FIELD(this, M2C_UNK **, 0x310) = &__vt;
            if (temp_r3_14988 != NULL) {
                temp_r3_14988->Deinit();
            }
            temp_r3_14994 = &this->unk310.unk38;
            if (temp_r3_14994 != NULL) {
                temp_r3_14994->Deinit();
            }
        }
        if (&this->unk2C0 != NULL) {
            temp_r3_15001 = &this->unk2C0.unk40;
            this->unk2C0.__vptr = &__vt;
            if (temp_r3_15001 != NULL) {
                temp_r3_15001->Deinit();
            }
            temp_r3_15007 = &this->unk2C0.unk3C;
            if (temp_r3_15007 != NULL) {
                temp_r3_15007->Deinit();
            }
        }
        if (&this->unk58 != NULL) {
            this->unk58.Deinit();
        }
        if (&this->unk54 != NULL) {
            this->unk54.Deinit();
        }
        if (&this->unk50 != NULL) {
            this->unk50.Deinit();
        }
        if (&this->unk4C != NULL) {
            this->unk4C.Deinit();
        }
        if (this != NULL) {
        }
    }
}
#endif

inline void DojoLesson::Init(DojoController *arg0, int arg1) {
    this->unk4 = arg0;
    this->unk8 = arg1;
    this->unkC = 0;
    this->unk10 = 0;
    this->unk14 = 0;
}

inline void EarthDojoLesson::Init(DojoController *arg0, int arg1) {
    this->unk4 = arg0;
    this->unk8 = arg1;
    this->unkC = 0;
    this->unk10 = 0;
    this->unk14 = 0;
    this->unk14 = 0x17;
}

inline void ElectricDojoLesson::Init(DojoController *arg0, int arg1) {
    this->unk4 = arg0;
    this->unk8 = arg1;
    this->unkC = 0;
    this->unk10 = 0;
    this->unk14 = 0;
    this->unk14 = 0xD;
}

inline void FireDojoLesson::Init(DojoController *arg0, int arg1) {
    this->unk4 = arg0;
    this->unk8 = arg1;
    this->unkC = 0;
    this->unk10 = 0;
    this->unk14 = 0;
    this->unk14 = 0;
}

inline void IceDojoLesson::Init(DojoController *arg0, int arg1) {
    this->unk4 = arg0;
    this->unk8 = arg1;
    this->unkC = 0;
    this->unk10 = 0;
    this->unk14 = 0;
    this->unk14 = 0x12;
}

#endif  // SPYRO_SOURCE_DOJOCONTROLLER_H
