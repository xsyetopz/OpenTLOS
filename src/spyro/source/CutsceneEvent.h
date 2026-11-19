#ifndef SPYRO_SOURCE_CUTSCENEEVENT_H
#define SPYRO_SOURCE_CUTSCENEEVENT_H

#include <dolphin/types.h>
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "spyro/source/KDSynkerPlayerEvents.h"

class AlphaChangeCE;
class AttachActorToRefPointCE;
class AttachCE;
class AttachPropCE;
class AttachPropToRefPointCE;
class AttachScaleOffsetCE;
class BreathEffectCE;
class CameraShakeCE;
class ColorCE;
class DepthOfFieldCE;
class DisableShadowCE;
class DisableWobbleTechCE;
class DropShadowCE;
class ExplosionCE;
class ExplosionNodeCE;
class FadeCE;
class ImageCE;
class KDSynkerPlayerEvent;
class LavaBubbleCE;
class MKAnim;
class MKAnimScript;
class MKMaterial;
class MKModel;
class MKProp;
class MKVector2;
class MKVector3;
class MKVector4;
class PlayMusicCE;
class PlaySecondaryAnimCE;
class ResetClothCE;
class ScaleCE;
class ScriptCE;
class SpawnGemsCE;
class TeleportCE;

class AlphaChangeCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ MKModel* unk4;
    /* 0x008 */ f32 unk8;
};

class AttachActorToRefPointCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ MKModel* unk4;
    /* 0x008 */ MKModel* unk8;
    /* 0x00c */ s32 unkC;
};

class AttachCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ MKVector3 unk8;
    /* 0x018 */ MKModel* unk18;
    /* 0x01c */ MKModel* unk1C;
    /* 0x020 */ s32 unk20;
    /* 0x024 */ s32 unk24;
};

class AttachPropCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ MKProp* unk4;
    /* 0x008 */ MKModel* unk8;
    /* 0x00c */ s32 unkC;
};

class AttachPropToRefPointCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ MKProp* unk4;
    /* 0x008 */ MKModel* unk8;
    /* 0x00c */ s32 unkC;
};

class AttachScaleOffsetCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ MKVector3 unk8;
    /* 0x018 */ MKModel* unk18;
    /* 0x01c */ MKModel* unk1C;
    /* 0x020 */ s32 unk20;
};

class BreathEffectCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void LoadDone(void);
    virtual void Enter(void);
    virtual void Update(void);
    virtual void Exit(void);
    /* 0x004 */ u8 pad4[0xc];
    /* 0x010 */ f64 unk10;
    /* 0x018 */ f64 unk18;
    /* 0x020 */ f64 unk20;
    /* 0x028 */ u8 pad28[0x4];
    /* 0x02c */ s32 unk2C;
    /* 0x030 */ s32 unk30;
    /* 0x034 */ s8 unk34;
    /* 0x035 */ u8 pad35[0x3];
    /* 0x038 */ s32 unk38;
    /* 0x03c */ s8 unk3C;
    /* 0x03d */ u8 pad3D[0x3];
    /* 0x040 */ s32 unk40;
    /* 0x044 */ s8 unk44;
    /* 0x045 */ s8 unk45;
    /* 0x046 */ u8 unk46;
    /* 0x047 */ u8 pad47[0x1];
    /* 0x048 */ MKModel* unk48;
    /* 0x04c */ s32 unk4C;
    /* 0x050 */ s32 unk50;
    /* 0x054 */ s32 unk54;
    /* 0x058 */ s32 unk58;
};

class CameraShakeCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f64 unk10;
};

class ColorCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Enter(void);
    virtual void Update(void);
    virtual void Exit(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ MKVector4 unk8;
    /* 0x018 */ MKVector3 unk18;
    /* 0x028 */ MKModel* unk28;
};

class DepthOfFieldCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Enter(void);
    virtual void Update(void);
    virtual void Exit(void);
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
};

class DisableShadowCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Enter(void);
    virtual void Exit(void);
    /* 0x004 */ s32 unk4;
};

class DisableWobbleTechCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Enter(void);
    virtual void Exit(void);
    /* 0x004 */ MKModel* unk4;
};

class DropShadowCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ MKModel* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ f32 unkC;
};

class ExplosionCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ MKModel* unk4;
    /* 0x008 */ f32 unk8;
};

class ExplosionNodeCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ MKModel* unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ f32 unkC;
};

class FadeCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void Deinit(void);
    virtual s32 LoadLine(void);
    virtual void Update(void);
    virtual void Exit(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ f64 unk8;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
};

class ImageCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual s32 LoadLine(void);
    virtual void LoadDone(void);
    virtual void Update(void);
    virtual void Draw(void);
    u8 LoadVector2(const char *, MKVector2 *);
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ s8 unk1C;
    /* 0x01d */ u8 pad1D[0x1f];
    /* 0x03c */ MKMaterial* unk3C;
    /* 0x040 */ f32 unk40;
    /* 0x044 */ f32 unk44;
};

class LavaBubbleCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Enter(void);
    virtual void Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ MKVector3 unk8;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
};

class MKVector2 {
public:
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
};

class PlayMusicCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(void);
    virtual void Enter(void);
    virtual void Exit(void);
    /* 0x004 */ s8 unk4;
    /* 0x005 */ u8 pad5[0x1f];
    /* 0x024 */ u8 unk24;
};

class PlaySecondaryAnimCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual s32 LoadLine(void);
    virtual void LoadDone(void);
    virtual void Enter(void);
    virtual void Update(void);
    /* 0x004 */ s8 unk4;
    /* 0x005 */ u8 pad5[0x23];
    /* 0x028 */ MKAnimScript unk28;
    /* 0x080 */ MKAnimScript* unk80;
    /* 0x084 */ MKModel* unk84;
    /* 0x088 */ MKAnim* unk88;
    /* 0x08c */ s32 unk8C;
};

class ResetClothCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ MKModel* unk4;
};

class ScaleCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ u8 pad4[0x4];
    /* 0x008 */ MKVector3 unk8;
    /* 0x018 */ MKModel* unk18;
};

class ScriptCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Deinit(void);
    virtual s32 LoadLine(void);
    virtual void Enter(void);
    /* 0x004 */ s8* unk4;
};

class SpawnGemsCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual s32 LoadLine(void);
    virtual void Enter(void);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ s32 unk8;
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ MKModel* unk14;
    /* 0x018 */ s32 unk18;
};

class TeleportCE : public KDSynkerPlayerEvent {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(void);
    virtual void Update(void);
    /* 0x004 */ MKProp* unk4;
    /* 0x008 */ MKModel* unk8;
};

extern u8 gEventCreationTable[0xd0];
extern u8 bIgnoreEvent;
#endif  // SPYRO_SOURCE_CUTSCENEEVENT_H
