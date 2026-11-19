#include "spyro/source/LineSegmentTrail.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "common/Source/Texture.h"
#include "spyro/source/KDSpline.h"
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
#include "common/gc/MKMaterial_GC.h"
#include "common/gc/MKPrimitive_GC.h"
#include <m2c_macros.h>

M2C_UNK free(void *);                               /* extern */
void *malloc(M2C_UNK);                              /* extern */
extern f32 gUpdateTimeDelta;

s32 LineSegmentTrail::TrailActive() {
    s32 i;
    LSTrail **trails;
    LSTrail *trail;

    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        trail = trails[i];
        if ((trail != NULL) && ((u8) M2C_FIELD(trail, u8 *, 0x1C) == 0)) {
            return 1;
        }
    }
    return 0;
}

void LineSegmentTrailPool::Free(LSTrail *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s8 *, 0x24) = 0;
    }
}

LineSegmentTrailPool *LineSegmentTrailPool::Alloc() {
    s32 i;
    s32 off;
    s8 *pool;
    MKVector4 unit;

    pool = *(s8 **) LineSegmentTrailPool::pTrailPool;
    off = 0;
    for (i = 0; i < 0xA; i++) {
        if ((u8) M2C_FIELD(pool + off, u8 *, 0x24) == 0) {
            memset(*(void **) (pool + off), 0, 0x3C0U);
            M2C_FIELD(pool + off, s32 *, 0x18) = 0;
            M2C_FIELD(pool + off, s8 *, 0x1C) = 0;
            unit.unk0 = 1.0f;
            unit.unk4 = 1.0f;
            unit.unk8 = 1.0f;
            unit.unkC = 1.0f;
            *(MKVector4 *) (pool + off + 8) = unit;
            M2C_FIELD(pool + off, s8 *, 0x24) = 1;
            M2C_FIELD(pool + off, s32 *, 0x20) = 0;
            return (LineSegmentTrailPool *) (pool + off);
        }
        off += 0x30;
    }
    return NULL;
}

void LineSegmentTrailPool::Deinit() {
    s32 i;
    s32 off;
    s32 count;
    s8 *pool;
    void *buf;

    count = *(s32 *) LineSegmentTrailPool::refCount - 1;
    *(s32 *) LineSegmentTrailPool::refCount = count;
    if (count <= 0) {
        pool = *(s8 **) LineSegmentTrailPool::pTrailPool;
        off = 0;
        for (i = 0; i < 0xA; i++) {
            if ((u8) M2C_FIELD(pool + off, u8 *, 0x24) != 0) {
                return;
            }
            off += 0x30;
        }
        off = 0;
        for (i = 0; i < 0xA; i++) {
            buf = *(void **) (pool + off);
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(buf, NULL, 0);
            } else {
                free(buf);
            }
            off += 0x30;
        }
        buf = pool;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(buf, NULL, 0);
        } else {
            free(buf);
        }
        *(s8 **) LineSegmentTrailPool::pTrailPool = NULL;
    }
}

void LineSegmentTrailPool::Init() {
    s32 i;
    s32 off;
    s32 count;
    void *buf;
    MKVector4 unit;

    count = *(s32 *) LineSegmentTrailPool::refCount;
    *(s32 *) LineSegmentTrailPool::refCount = count + 1;
    if (count <= 0) {
        if (MKHeap::Current() != NULL) {
            *(s8 **) LineSegmentTrailPool::pTrailPool = (s8 *) ((MKHeap *) (MKHeap::Current()))->Alloc(0x1E0, NULL, 0);
        } else {
            *(s8 **) LineSegmentTrailPool::pTrailPool = (s8 *) malloc(0x1E0);
        }
        unit.unk0 = 1.0f;
        unit.unk4 = 1.0f;
        unit.unk8 = 1.0f;
        unit.unkC = 1.0f;
        off = 0;
        for (i = 0; i < 0xA; i++) {
            if (MKHeap::Current() != NULL) {
                buf = ((MKHeap *) (MKHeap::Current()))->Alloc(0x3C0, NULL, 0);
            } else {
                buf = malloc(0x3C0);
            }
            *(void **) (*(s8 **) LineSegmentTrailPool::pTrailPool + off) = buf;
            memset(buf, 0, 0x3C0U);
            M2C_FIELD(*(s8 **) LineSegmentTrailPool::pTrailPool + off, s32 *, 0x18) = 0;
            M2C_FIELD(*(s8 **) LineSegmentTrailPool::pTrailPool + off, u8 *, 0x1C) = 0;
            *(MKVector4 *) (*(s8 **) LineSegmentTrailPool::pTrailPool + off + 8) = unit;
            M2C_FIELD(*(s8 **) LineSegmentTrailPool::pTrailPool + off, s32 *, 0x20) = 0;
            M2C_FIELD(*(s8 **) LineSegmentTrailPool::pTrailPool + off, u8 *, 0x24) = 0;
            off += 0x30;
        }
    }
}

void LineSegmentTrail::EndTrail() {
    s32 i;
    LSTrail **trails;
    LSTrail *trail;

    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        trail = trails[i];
        if ((trail != NULL) && ((u8) M2C_FIELD(trail, u8 *, 0x24) != 0) && ((u8) M2C_FIELD(trail, u8 *, 0x1C) == 0)) {
            M2C_FIELD(trail, u8 *, 0x1C) = 1U;
        }
    }
}

void LineSegmentTrail::BeginTrail(const MKVector4 &arg0) {
    s32 i;
    LSTrail **trails;
    LSTrail *trail;

    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        if (trails[i] == NULL) {
            trails[i] = (LSTrail *) LineSegmentTrailPool::Alloc();
            if (trails[i] != NULL) {
                trail = trails[i];
                *(MKVector4 *) &trail->unk8 = arg0;
                UpdateTrail(trail);
                return;
            }
        }
    }
}

#if 0 // DRAFT: function call 'MKModel_CalculateRefPointWorldPosition(MKModel *, long, long)' does not match 'MKModel_CalculateRefPointWorldPosition(const MKModel *, int, MKVec
void LineSegmentTrail::UpdateTrail(LSTrail *arg0) {
    MKVector4 spA8;
    f64 spA0;
    f64 sp98;
    f64 sp90;
    f64 sp88;
    f64 sp80;
    f64 sp78;
    f64 sp70;
    f64 sp68;
    f64 sp60;
    f64 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f64 sp30;
    f64 sp28;
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    MKVector3 *temp_r5_402;
    f64 temp_f0_466;
    s32 var_ctr_379;
    s32 var_r3_375;
    void *temp_r5_382;
    void *temp_r5_391;

    if (arg0 != NULL) {
        var_r3_375 = 0;
        var_ctr_379 = 0x14;
        do {
            temp_r5_382 = (void *) (arg0->unk0 + var_r3_375);
            if ((u8) M2C_FIELD(temp_r5_382, u8 *, 0x24) != 0) {
                M2C_FIELD(temp_r5_382, f32 *, 0x20) = (f32) (M2C_FIELD(temp_r5_382, f32 *, 0x20) + gUpdateTimeDelta);
                temp_r5_391 = (void *) (arg0->unk0 + var_r3_375);
                if (M2C_FIELD(temp_r5_391, f32 *, 0x20) > 0.3f) {
                    M2C_FIELD(temp_r5_391, s8 *, 0x24) = 0;
                }
            }
            var_r3_375 += 0x30;
            var_ctr_379 -= 1;
        } while (var_ctr_379 != 0);
        temp_r5_402 = (MKVector3 *) (arg0->unk0 + (arg0->unk18 * 0x30));
        if ((u8) M2C_FIELD(temp_r5_402, u8 *, 0x24) == 0) {
            MKModel_CalculateRefPointWorldPosition(this->unk4C->unk8, this->unk50, temp_r5_402);
            MKModel_CalculateRefPointWorldPosition(this->unk4C->unk8, this->unk54, arg0->unk0 + ((arg0->unk18 * 0x30) + 0x10));
            M2C_FIELD((arg0->unk0 + (arg0->unk18 * 0x30)), s8 *, 0x24) = 1;
            M2C_FIELD((arg0->unk0 + (arg0->unk18 * 0x30)), f32 *, 0x20) = 0.0f;
            arg0->unk18 += 1;
            if ((s32) arg0->unk18 >= 0x14) {
                arg0->unk18 = 0;
            }
            if ((u8) arg0->unk1C != 0) {
                sp38 = gUpdateTimeDelta;
                sp3C = gUpdateTimeDelta;
                sp48 = 0.0f;
                sp4C = 0.0f;
                sp50 = 0.0f;
                sp54 = 0.0f;
                sp40 = gUpdateTimeDelta;
                sp44 = gUpdateTimeDelta;
                sp68 = (f64) sp38;
                sp98 = (f64) sp48;
                spA0 = (f64) sp50;
                sp70 = (f64) sp40;
                sp28 = sp68 * 5.325712093e-315;
                temp_f0_466 = (f64) sp40 * 5.325712093e-315;
                sp30 = temp_f0_466;
                sp78 = sp28;
                sp80 = temp_f0_466;
                sp18 = arg0->unk8 - sp78;
                sp20 = arg0->unk10 - temp_f0_466;
                sp8 = 1.0f;
                spC = 1.0f;
                sp10 = 1.0f;
                sp14 = 1.0f;
                sp88 = sp18;
                sp90 = sp20;
                sp58 = (f64) sp8;
                sp60 = (f64) sp10;
                Clamp<MKVector4>(spA8, *((MKVector4 *) &sp98), *((MKVector4 *) &sp88));
                *(MKVector4 *) &arg0->unk8 = spA8;
                if (M2C_FIELD(arg0, f32 *, 0x14) <= 0.01f) {
                    FreeActiveTrail(arg0);
                }
            }
        }
    }
}
#endif

void LineSegmentTrail::FreeActiveTrail(LSTrail *arg0) {
    s32 i;
    LSTrail **trails;

    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        if (trails[i] == arg0) {
            trails[i] = NULL;
            LineSegmentTrailPool::Free(arg0);
        }
    }
}

void LineSegmentTrail::Deinit() {
    s32 i;
    LSTrail **trails;
    LSTrail *trail;
    MKMaterial *material;

    material = this->unk70;
    if (material != NULL) {
        MKMaterial_Destroy(material);
        this->unk70 = NULL;
    }
    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        trail = trails[i];
        if (trail != NULL) {
            FreeActiveTrail(trail);
            trails[i] = NULL;
        }
    }
    this->unk74.Deinit();
    this->unk88.Deinit();
    LineSegmentTrailPool::Deinit();
    MKProp::Deinit();
}

#if 0 // DRAFT: illegal explicit conversion from 'LineSegmentTrail' to 'unsigned long'
void LineSegmentTrail::Draw() {
    f64 sp30;
    f64 sp28;
    M2C_UNK sp18;
    M2C_UNK sp8;
    MKVector3 *temp_r4_748;
    f32 var_f27_805;
    f32 var_f28_789;
    f32 var_f2_806;
    s32 temp_r0_756;
    s32 temp_r26_759;
    s32 temp_r27_746;
    s32 temp_r28_716;
    s32 var_r26_728;
    s32 var_r27_778;
    s32 var_r29_714;
    s32 var_r31_713;
    void *temp_r3_745;
    void *temp_r4_760;

    MKMaterial_SetMaterial(this->unk70);
    MKPrimitive(0xC, 0x10);
    MKSetMatrix(Matrix::identity);
    var_r31_713 = 0;
    var_r29_714 = 0;
    do {
        temp_r28_716 = var_r29_714 + 0x58;
        if ((u32) *(this + temp_r28_716) != 0U) {
            this->unk74.unk8 = 0.0f;
            this->unk74.unk4 = 0;
            this->unk88.unk8 = 0.0f;
            this->unk88.unk4 = 0;
            var_r26_728 = M2C_FIELD(*(this + temp_r28_716), s32 *, 0x18) - 1;
            if (var_r26_728 < 0) {
                var_r26_728 = 0x13;
            }
loop_6:
            temp_r3_745 = *(this + temp_r28_716);
            temp_r27_746 = var_r26_728 * 0x30;
            temp_r4_748 = (MKVector3 *) (M2C_FIELD(temp_r3_745, s32 *, 0) + temp_r27_746);
            if (((u8) M2C_FIELD(temp_r4_748, u8 *, 0x24) != 0) && (var_r26_728 != (s32) M2C_FIELD(temp_r3_745, s32 *, 0x18))) {
                this->unk74.AddNode(*temp_r4_748);
                this->unk88.AddNode(*(**(this + temp_r28_716) + (temp_r27_746 + 0x10)));
                var_r26_728 -= 1;
                if (var_r26_728 < 0) {
                    var_r26_728 = 0x13;
                }
                goto loop_6;
            }
            temp_r0_756 = this->unk74.unk4;
            if (temp_r0_756 > 1) {
                temp_r26_759 = temp_r0_756 * 3;
                temp_r4_760 = *(this + temp_r28_716);
                sp28 = M2C_FIELD(temp_r4_760, f64 *, 8);
                sp30 = M2C_FIELD(temp_r4_760, f64 *, 0x10);
                MKBegin(temp_r0_756 * 6);
                var_r27_778 = 0;
loop_28:
                if (var_r27_778 < temp_r26_759) {
                    var_f28_789 = (f32) var_r27_778 * (1.0f / (f32) (temp_r26_759 - 1));
                    if (var_f28_789 < 1.0f) {

                    } else {
                        var_f28_789 = 1.0f;
                    }
                    if (var_f28_789 > 0.0f) {

                    } else {
                        var_f28_789 = 0.0f;
                    }
                    MKSetColorV(*((MKVector4 *) &sp28));
                    var_f27_805 = 1.0f - var_f28_789;
                    var_f2_806 = 1.0f;
                    if (var_f27_805 < var_f2_806) {
                        var_f2_806 = var_f27_805;
                    }
                    if (var_f2_806 > 0.05f) {

                    } else {
                        var_f2_806 = 0.05f;
                    }
                    MKSetTexCoord1F(0.0f, var_f2_806);
                    ((KDSpline *) &sp18)->GetMeasure(var_f28_789, (Matrix *) &this->unk88);
                    MKSetPositionV(*((MKVector3 *) &sp18));
                    MKSetColorV(*((MKVector4 *) &sp28));
                    if (var_f27_805 < 1.0f) {

                    } else {
                        var_f27_805 = 1.0f;
                    }
                    if (var_f27_805 > 0.05f) {

                    } else {
                        var_f27_805 = 0.05f;
                    }
                    MKSetTexCoord1F(1.0f, var_f27_805);
                    ((KDSpline *) &sp8)->GetMeasure(var_f28_789, (Matrix *) &this->unk74);
                    MKSetPositionV(*((MKVector3 *) &sp8));
                    var_r27_778 += 1;
                    goto loop_28;
                }
                MKEnd();
            }
        }
        var_r31_713 += 1;
        var_r29_714 += 4;
    } while (var_r31_713 < 6);
    MKEndPrimitive();
}
#endif

void *LineSegmentTrail::Update() {
    s32 i;
    LSTrail **trails;
    LSTrail *trail;

    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        trail = trails[i];
        if (trail != NULL) {
            UpdateTrail(trail);
        }
    }
}

void LineSegmentTrail::SetUserData(MKAnimScript *arg0, const int &arg1, const int &arg2, char *arg3) {
    this->unk4C = arg0;
    this->unk50 = (long) (&arg1);
    this->unk54 = (long) (&arg2);
    this->unk70 = (MKMaterial *) (MKMaterial_Create(arg3));
}

void LineSegmentTrail::Init() {
    s32 i;
    LSTrail **trails;

    MKProp::Init();
    this->unk4C = NULL;
    this->unk50 = -1;
    this->unk54 = -1;
    this->unk70 = NULL;
    this->unk74.Init(0x14, 0U);
    this->unk88.Init(0x14, 0U);
    trails = (LSTrail **) ((s8 *) this + 0x58);
    for (i = 0; i < 6; i++) {
        trails[i] = NULL;
    }
    LineSegmentTrailPool::Init();
}
