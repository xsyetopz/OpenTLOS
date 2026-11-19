#ifndef SPYRO_SOURCE_COLLECTABLE_H
#define SPYRO_SOURCE_COLLECTABLE_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector3.h"
#include "unplaced_enums.h"

class Collectable;
class CollectableDescriptor;
class CollectableSpawner;
class CollectableSpawnerDescriptor;
class MKHeap;
class MKIniLine;
class MKMaterial;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKSceneManager;
class MKVector3;
class Matrix;
class SpawnInfo;

class Collectable : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Collectable(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Draw(void);
    virtual void Message(MKMessage *);
    virtual void GetDescriptor(void);
    virtual void DrawLocator(void);
    virtual void Spawn(const MKVector3 *, const MKVector3 *, bool);
    virtual void GetPos(void);
    virtual void SetPos(const MKVector3 &);
    virtual s32 GetTypeID(void);
    virtual s32 SetTypeID(int);
    virtual s32 GetItemType(void);
    virtual void CollectEffects(void);
    virtual void SetState(CollectableState);
    virtual void SetPlatformId(int);
    virtual void UpdateShadow(void);
    virtual void CalcShadowPos(void);
    virtual void SpawningState(void);
    virtual void FallingState(void);
    virtual void SlidingState(void);
    virtual void JustSpawnedState(void);
    virtual void IdleState(void);
    virtual void MagnetisedState(void);
    virtual void CollectingStateInit(void);
    virtual void CollectingState(void);
    virtual void PresentingState(void);
    virtual void CollectedState(void);
    virtual void RotateCameraFacing(void);
    virtual s32 PlayCollectSound(void);
    void PlatformDetach(void);
    void PlatformAttach(MKProp *);
    u8 FindGround(void);
    void SpawnDynamic(const MKVector3 &);
    void SpawnStatic(const MKVector3 &, const MKVector3 &);
    void DrawShadow(void);
    void ClearData(void);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ MKVector3 unk60;
    /* 0x070 */ f64 unk70;
    /* 0x078 */ u8 unk78;
    /* 0x079 */ u8 pad79[0x3];
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ u8 pad8C[0x4];
    /* 0x090 */ f64 unk90;
    /* 0x098 */ f64 unk98;
    /* 0x0a0 */ f64 unkA0;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ u8 padAC[0x4];
    /* 0x0b0 */ u8 unkB0;
    /* 0x0b1 */ u8 padB1[0xf];
    /* 0x0c0 */ void* unkC0;
    /* 0x0c4 */ MKProp* unkC4;
    /* 0x0c8 */ void* unkC8;
    /* 0x0cc */ s32 unkCC;
    /* 0x0d0 */ s32 unkD0;
    /* 0x0d4 */ s32 unkD4;
    /* 0x0d8 */ f32 unkD8;
    /* 0x0dc */ f32 unkDC;
    /* 0x0e0 */ f32 unkE0;
    /* 0x0e4 */ f32 unkE4;
    /* 0x0e8 */ f32 unkE8;
    /* 0x0ec */ f32 unkEC;
    /* 0x0f0 */ f32 unkF0;
    /* 0x0f4 */ f32 unkF4;
    /* 0x0f8 */ f32 unkF8;
    /* 0x0fc */ f32 unkFC;
    /* 0x100 */ f32 unk100;
    /* 0x104 */ MKSceneManager* unk104;
    /* 0x108 */ f32 unk108;
    /* 0x10c */ f32 unk10C;
    /* 0x110 */ f64 unk110;
    /* 0x118 */ f64 unk118;
    /* 0x120 */ u8 unk120;
    /* 0x121 */ s8 unk121;
    /* 0x122 */ u8 pad122[0x2];
    /* 0x124 */ MKHeap* unk124;
    /* 0x128 */ u8 unk128;
    /* 0x129 */ u8 pad129[0x3];
    /* 0x12c */ void* unk12C;
    /* 0x130 */ void* unk130;
    /* 0x134 */ f32 unk134;
    /* 0x138 */ f32 unk138;
    /* 0x13c */ u8 unk13C;
    /* 0x13d */ u8 pad13D[0x3];
    /* 0x140 */ s32 unk140;
    /* 0x144 */ u8 unk144;
};

class CollectableDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    static u8 bDrawLocator[0x1];
    /* 0x044 */ u8 pad44[0x20];
    /* 0x064 */ s8 unk64;
    /* 0x065 */ u8 pad65[0x1];
    /* 0x066 */ u16 unk66;
    /* 0x068 */ s32 unk68;
    /* 0x06c */ f32 unk6C;
    /* 0x070 */ f32 unk70;
    /* 0x074 */ f32 unk74;
    /* 0x078 */ f32 unk78;
    /* 0x07c */ f32 unk7C;
    /* 0x080 */ f32 unk80;
    /* 0x084 */ f32 unk84;
    /* 0x088 */ f32 unk88;
    /* 0x08c */ f32 unk8C;
    /* 0x090 */ f32 unk90;
    /* 0x094 */ f32 unk94;
    /* 0x098 */ s32 unk98;
    /* 0x09c */ s32 unk9C;
    /* 0x0a0 */ f32 unkA0;
    /* 0x0a4 */ f32 unkA4;
    /* 0x0a8 */ f32 unkA8;
    /* 0x0ac */ f32 unkAC;
    /* 0x0b0 */ f32 unkB0;
    /* 0x0b4 */ u8 padB4[0x4];
    /* 0x0b8 */ MKMaterial* unkB8;
    /* 0x0bc */ s32 unkBC;
    /* 0x0c0 */ s32 unkC0;
    /* 0x0c4 */ f32 unkC4;
};

class CollectableSpawner : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CollectableSpawner(void);
    virtual void Init(void);
    virtual void Deinit(void);
    virtual f32 Resolve(void);
    virtual void Reset(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    void Emit(SpawnInfo *);
    void Spawn(const MKVector3 &, float, float);
    void Spawn(const MKVector3 &, int, float, float, int, MKProp *);
    /* 0x04c */ Matrix* unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ u8 pad58[0x4];
    /* 0x05c */ s32 unk5C;
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ Matrix* unk68;
};

class CollectableSpawnerDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ s8* unk60;
};

class SpawnInfo {
public:
    /* 0x000 */ u8 pad0[0x4];
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline s32 Collectable::SetTypeID(int arg0) {
    this->unkD0 = arg0;
    return this->unkD0;
}

#if 0 // DRAFT: undefined identifier 'checked_cast'
inline void Collectable::GetDescriptor() {
    checked_cast<CollectableDescriptor *, MKPropDescriptor>((MKPropDescriptor *) this->unk0);
}
#endif

inline void Collectable::SetPos(const MKVector3 &arg0) {
    this->unk50 = M2C_FIELD(&arg0, f64 *, 0);
    this->unk58 = M2C_FIELD(&arg0, f64 *, 8);
}

inline s32 Collectable::GetTypeID() {
    return this->unkD0;
}

inline void Collectable::SetPlatformId(int arg0) {
    this->unk104 = (MKSceneManager *) arg0;
}

#if 0 // DRAFT: undefined identifier 'unkB8'
inline Collectable::~Collectable() {
    u8 *temp_r0_11042;
    u8 *temp_r5_11029;
    u8 *temp_r5_11045;
    void *temp_r0_11026;

    if (this != NULL) {
        if (&this->unk128 != NULL) {
            temp_r0_11026 = this->unk12C;
            if (temp_r0_11026 != NULL) {
                temp_r5_11029 = &this->unk128;
                if (temp_r0_11026 != temp_r5_11029) {
                    M2C_FIELD(this->unk130, void **, 4) = temp_r0_11026;
                    M2C_FIELD(this->unk12C, void **, 8) = (void *) this->unk130;
                    this->unk130 = temp_r5_11029;
                    this->unk12C = temp_r5_11029;
                }
            }
        }
        if (&this->unkB0 != NULL) {
            temp_r0_11042 = this->unkB8;
            if (temp_r0_11042 != NULL) {
                temp_r5_11045 = &this->unkB0;
                if (temp_r0_11042 != temp_r5_11045) {
                    M2C_FIELD(this->unkBC, u8 **, 8) = temp_r0_11042;
                    M2C_FIELD(this->unkB8, u8 **, 0xC) = (u8 *) this->unkBC;
                    this->unkBC = temp_r5_11045;
                    this->unkB8 = temp_r5_11045;
                }
            }
        }
        if (this != NULL) {
        }
    }
}
#endif

inline void Collectable::GetPos() {
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x50);
    M2C_FIELD(this, f64 *, 8) = (f64) M2C_FIELD(M2C_ERROR(/* Read from unset register $r4 */), f64 *, 0x58);
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKHeap'
inline s32 Collectable::GetItemType() {
    return this->unk124->unk98;
}
#endif

inline CollectableSpawner::~CollectableSpawner() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_COLLECTABLE_H
