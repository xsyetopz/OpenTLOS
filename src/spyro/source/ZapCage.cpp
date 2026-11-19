#include "spyro/source/ZapCage.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKCollision.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKMemoryCard.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/AITargetData.h"
#include "spyro/source/BoneBlurFX.h"
#include "spyro/source/CameraData.h"
#include "spyro/source/Character.h"
#include "spyro/source/CharacterBodyFX.h"
#include "spyro/source/CharacterBreathFX.h"
#include "spyro/source/CharacterFireFX.h"
#include "spyro/source/CharacterGraph.h"
#include "spyro/source/CharacterZapFX.h"
#include "spyro/source/CollisionObject.h"
#include "spyro/source/Enemy.h"
#include "spyro/source/EnemyAttackPattern.h"
#include "spyro/source/EnemyDataTypes.h"
#include "spyro/source/EnemyDescriptor.h"
#include "spyro/source/EnemyRegion.h"
#include "spyro/source/EnemySettings.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/FireAndIceFX.h"
#include "spyro/source/GameData.h"
#include "spyro/source/GameMessages.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/IceBitsPS.h"
#include "spyro/source/KDPath.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KDSound.h"
#include "spyro/source/KDSoundTools.h"
#include "spyro/source/Level.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/Names.h"
#include "spyro/source/NodeLookAt.h"
#include "spyro/source/SB2.h"
#include "spyro/source/Shadow.h"
#include "spyro/source/SpawnPointObject.h"
#include "spyro/source/SpawnerObject.h"
#include "spyro/source/TargetManager.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include "unplaced_enums.h"
#include "common/Source/StdMath.h"
#include "spyro/source/KDRandom.h"
#include "unplaced_inlines.h"
#include <m2c_macros.h>

extern f32 gUpdateTimeDelta;
extern s32 gViewSeed;
extern M2C_UNK gb;
static u8 lit_720 = 1;

void ZapCage::Reset() {
    MKProp::Reset();
    this->unk4C = 0;
    this->unk50 = 0.0f;
    this->unk54 = NULL;
}

void ZapCage::Trigger(MKProp *arg0, float arg1) {
    void *temp_r3_80;

    this->unk4C = 1;
    this->unk50 = arg1;
    this->unk58 = MKRand_Float((int *) &gViewSeed, 0.0f, 6.2831855f);
    this->unk54 = arg0;
    this->unk5C = 0.0f;
    temp_r3_80 = checked_cast<Enemy *, MKProp>(this->unk54);
    M2C_FIELD(temp_r3_80, u8 *, 0xB02) = (u8) (M2C_FIELD(temp_r3_80, u8 *, 0xB02) | 0x40);
}

void ZapCage::Deinit() {
    MKProp::Deinit();
}

#if 0 // DRAFT: illegal type
void *ZapCage::Update() {
    BreathHitMessage sp1D0;
    f32 sp1CC;
    f32 sp1C8;
    f32 sp1C4;
    f32 sp1C0;
    M2C_UNK sp18C;
    f64 sp180;                                      /* compiler-managed */
    f64 sp178;
    f64 sp170;
    f64 sp168;
    f64 sp160;
    f64 sp158;
    f64 sp150;
    f64 sp148;
    f64 sp140;
    f64 sp138;
    MKVector3 sp128;
    MKVector3 sp118;
    f64 sp110;
    f64 sp108;
    f64 sp100;
    f64 spF8;
    f64 spF0;
    f64 spE8;
    MKVector3 spD8;
    f64 spD0;
    f64 spC8;
    f64 spC0;
    f64 spB8;
    f64 spB0;
    f64 spA8;
    f64 spA0;
    f64 sp98;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp80;
    f64 sp78;
    f32 sp70;
    f64 sp68;
    f32 sp60;
    f64 sp58;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp20;
    f32 sp1C;
    f32 sp18;
    f32 sp10;
    MKHeap **temp_r30_164;
    f32 temp_f2_220;
    f32 temp_f5_244;
    f64 temp_f0_186;
    f64 temp_f0_206;
    f64 temp_f0_226;
    f64 temp_f1_200;
    s32 temp_r0_127;
    void *temp_r29_332;
    void *temp_r3_198;

    this->unk50 -= gUpdateTimeDelta;
    this->unk58 += 12.566371f * gUpdateTimeDelta;
    temp_r0_127 = this->unk4C;
    if (temp_r0_127 != 1) {
        if ((temp_r0_127 < 1) && (temp_r0_127 < 0)) {

        }
    } else {
        sp10 = 1.0f;
        M2C_STRUCT_COPY((s32) &sp18C + 4, M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8) - 4 + 4, 0x40);
        sp1C0 = 0.0f;
        sp1C4 = 0.0f;
        sp1C8 = 0.0f;
        sp1CC = 1.0f;
        temp_r30_164 = MKModel_GetBoundingVolume(this->unk54->unk4, (SubObjectType) 0, -1);
        sp128 = this->unk54->GetPos();
        sp18 = (0.5f * M2C_FIELD(temp_r30_164, f32 *, 0x10)) + M2C_BITWISE(f32, M2C_FIELD(temp_r30_164, MKHeap **, 0));
        sp1C = (0.5f * M2C_FIELD(temp_r30_164, f32 *, 0x14)) + M2C_FIELD(temp_r30_164, f32 *, 4);
        sp20 = (0.5f * M2C_FIELD(temp_r30_164, f32 *, 0x18)) + M2C_FIELD(temp_r30_164, f32 *, 8);
        sp138 = (f64) sp18;
        sp140 = (f64) sp20;
        temp_f0_186 = (f64) sp18 + M2C_BITWISE(f64, sp128);
        sp78 = temp_f0_186;
        sp178 = temp_f0_186;
        sp148 = temp_f0_186;
        sp80 = (f32) sp140 + sp128.unk8;
        sp180 = (f64) sp80;
        temp_r3_198 = M2C_FIELD(M2C_FIELD(&gb, void **, 0x3B8), void **, 8);
        sp150 = (f64) sp80;
        temp_f1_200 = M2C_FIELD(temp_r3_198, f64 *, 0x30);
        spF8 = temp_f1_200;
        sp100 = M2C_FIELD(temp_r3_198, f64 *, 0x38);
        temp_f0_206 = temp_f1_200 - temp_f0_186;
        sp68 = temp_f0_206;
        sp108 = temp_f0_206;
        sp70 = (f32) sp100 - (f32) sp180;
        sp110 = (f64) sp70;
        sp118 = Normalise(*((MKVector3 *) &sp108));
        temp_f2_220 = M2C_FIELD(temp_r30_164, f32 *, 0xC);
        *(MKVector3 *) &sp158 = sp118;
        temp_f0_226 = sp158 * (f64) temp_f2_220;
        sp58 = temp_f0_226;
        spE8 = temp_f0_226;
        sp60 = (f32) sp160 * temp_f2_220;
        spF0 = (f64) sp60;
        sp178 += temp_f0_226;
        temp_f5_244 = temp_f2_220 / 300.0f;
        sp40 = 0.0f;
        sp50 = 0.0f;
        sp38 = temp_f5_244;
        sp3C = 1.0f;
        sp48 = -1.0f * temp_f5_244;
        sp4C = 0.125f * temp_f5_244;
        sp180 = (f32) sp180 + (f32) spF0;
        sp10 = temp_f5_244;
        spB8 = (f64) sp38;
        spC0 = (f64) sp40;
        spC8 = (f64) sp48;
        spD0 = (f64) sp50;
        spD8 = KDRand_Vector(*((MKVector3 *) &spC8), *((MKVector3 *) &spB8));
        *(MKVector3 *) &sp168 = spD8;
        sp88 = 1.0f;
        sp8C = 1.0f;
        sp30 = sp1C8 + (((f32) sp170 * sp1B8) + (((f32) sp168 * sp198) + ((*(f32 *) ((u8 *) &sp168 + 0x4)) * sp1A8)));
        sp28 = sp1C0 + (((f32) sp170 * sp1B0) + (((f32) sp168 * sp190) + ((*(f32 *) ((u8 *) &sp168 + 0x4)) * sp1A0)));
        sp2C = sp1C4 + (((f32) sp170 * sp1B4) + (((f32) sp168 * sp194) + ((*(f32 *) ((u8 *) &sp168 + 0x4)) * sp1A4)));
        sp90 = 0.2f;
        sp94 = 1.0f;
        spA8 = (f64) sp28;
        spB0 = (f64) sp30;
        sp168 = (f64) sp28;
        sp170 = (f64) sp30;
        sp98 = (f64) sp88;
        spA0 = (f64) sp90;
        ((ZapArcFX *) (M2C_FIELD(&gb, ZapArcFX **, 0x94)))->Trigger(*((MKVector3 *) &sp178), *((MKVector3 *) &sp168), sp10, lit_720, (MKVector4) &sp98);
        temp_r29_332 = checked_cast<Enemy *, MKProp>(this->unk54);
        this->unk5C -= gUpdateTimeDelta;
        if (this->unk5C <= 0.0f) {
            this->unk5C = 0.3f;
            sp1D0.unk4 = 0;
            sp1D0.Init(NULL, ((GameStats *) &GameData::gameData[0x70])->GetBreathAttackDamage(1, 1, 0), 1, 0, 1, 0, 0, -1);
            M2C_FIELD(M2C_FIELD(temp_r29_332, void **, 0x44), M2C_UNK (**)(void *, BreathHitMessage *), 0x2C)(temp_r29_332, &sp1D0);
        }
        if ((this->unk50 <= 0.0f) || (M2C_FIELD(temp_r29_332, f32 *, 0xAC8) <= 0.0f)) {
            M2C_FIELD(temp_r29_332, u8 *, 0xB02) = (u8) (M2C_FIELD(temp_r29_332, u8 *, 0xB02) & ~0x40);
            this->unk4C = 0;
            Disable(0);
        }
    }
}
#endif

void ZapCage::Init() {
    MKProp::Init();
    this->unk4C = 0;
    this->unk50 = 0.0f;
    this->unk58 = 0.0f;
    this->unk54 = NULL;
    this->unk5C = 0.0f;
}
