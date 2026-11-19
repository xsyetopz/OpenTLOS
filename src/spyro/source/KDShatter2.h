#ifndef SPYRO_SOURCE_KDSHATTER2_H
#define SPYRO_SOURCE_KDSHATTER2_H

#include <dolphin/types.h>
#include "common/Source/Matrix.h"

class KDShatter2;
class KDShatterPool;
class MKModel;
class MKVector3;
class Matrix;

class KDShatter2 {
public:
    f32 GetRadius(int);
    void SetVisible(unsigned short *);
    void ClearVisible(void);
    void Draw(bool);
    void Update(void);
    void Finish(void);
    void ResetSubObjectMatrices(void);
    void Reset(void);
    void SetHitPlane(int);
    void SetInitialGroundPlane(void);
    void Shatter(int, MKVector3 *);
    void EnableSubObjectMatrices(bool);
    void SetVisibleUnshattered(void);
    void LoadDone(MKModel *, unsigned short *);
    void Deinit(void);
    void Init(void);
    static void DeinitModule(void);
    void InitModule(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ u8 padC[0x4];
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ u8 pad1C[0x4];
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ u8 pad2C[0x4];
    /* 0x030 */ s32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ u8 unk40;
    /* 0x041 */ u8 pad41[0x3];
    /* 0x044 */ s32 unk44;
    /* 0x048 */ u16* unk48;
    /* 0x04c */ MKModel* unk4C;
    /* 0x050 */ KDShatterPool* unk50;
    /* 0x054 */ u16* unk54;
    /* 0x058 */ u16* unk58;
    /* 0x05c */ u16* unk5C;
    /* 0x060 */ u8 unk60;
};

class KDShatterPool {
public:
    void Init(KDShatter2 *, MKModel *, unsigned short *);
    /* 0x000 */ KDShatterPool* unk0;
    /* 0x004 */ u8 pad4[0x15f8];
    /* 0x15fc */ u8 unk15FC;
    /* 0x15fd */ u8 pad15FD[0x3];
    /* 0x1600 */ Matrix unk1600;
    /* 0x1640 */ s32 unk1640;
    /* 0x1644 */ s32 unk1644;
    /* 0x1648 */ f32 unk1648;
    /* 0x164c */ KDShatter2* unk164C;
};

#endif  // SPYRO_SOURCE_KDSHATTER2_H
