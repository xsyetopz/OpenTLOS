#ifndef SPYRO_SOURCE_NODELOOKAT_H
#define SPYRO_SOURCE_NODELOOKAT_H

#include <dolphin/types.h>

class MKModel;
class MKVector3;
class NLStyle;
class NodeLookAt;
class NodeLookAtIK;

class NodeLookAt {
public:
    void Reset(void);
    void Update(MKVector3 *);
    void Init(MKModel *, int, NLStyle);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ MKModel* unk30;
    /* 0x034 */ u32 unk34;
    /* 0x038 */ u8 unk38;
};

class NodeLookAtIK {
public:
    void Update(MKVector3 *);
    f32 GetYawAssist(void) const;
    f32 GetPitchAssist(void) const;
    void Init(MKModel *, int);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ MKModel* unk34;
    /* 0x038 */ u8 unk38;
    /* 0x039 */ u8 pad39[0x3];
    /* 0x03c */ u32 unk3C;
    /* 0x040 */ NodeLookAtIK* unk40;
    /* 0x044 */ void* unk44;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline f32 NodeLookAtIK::GetYawAssist() const {
    NodeLookAtIK *temp_r29_398;
    NodeLookAtIK *temp_r30_395;
    NodeLookAtIK *temp_r31_392;
    NodeLookAtIK *temp_r3_401;
    f32 var_f1_406;
    f32 var_f1_412;
    f32 var_f1_418;

    temp_r31_392 = this->unk40;
    if (temp_r31_392 != NULL) {
        temp_r30_395 = temp_r31_392->unk40;
        if (temp_r30_395 != NULL) {
            temp_r29_398 = temp_r30_395->unk40;
            if (temp_r29_398 != NULL) {
                temp_r3_401 = temp_r29_398->unk40;
                if (temp_r3_401 != NULL) {
                    var_f1_406 = temp_r29_398->unk1C + temp_r3_401->GetYawAssist();
                } else {
                    var_f1_406 = temp_r29_398->unk1C;
                }
                var_f1_412 = temp_r30_395->unk1C + var_f1_406;
            } else {
                var_f1_412 = temp_r30_395->unk1C;
            }
            var_f1_418 = temp_r31_392->unk1C + var_f1_412;
        } else {
            var_f1_418 = temp_r31_392->unk1C;
        }
        return this->unk1C + var_f1_418;
    }
    return this->unk1C;
}

inline f32 NodeLookAtIK::GetPitchAssist() const {
    NodeLookAtIK *temp_r29_450;
    NodeLookAtIK *temp_r30_447;
    NodeLookAtIK *temp_r31_444;
    NodeLookAtIK *temp_r3_453;
    f32 var_f1_458;
    f32 var_f1_464;
    f32 var_f1_470;

    temp_r31_444 = this->unk40;
    if (temp_r31_444 != NULL) {
        temp_r30_447 = temp_r31_444->unk40;
        if (temp_r30_447 != NULL) {
            temp_r29_450 = temp_r30_447->unk40;
            if (temp_r29_450 != NULL) {
                temp_r3_453 = temp_r29_450->unk40;
                if (temp_r3_453 != NULL) {
                    var_f1_458 = temp_r29_450->unk20 + temp_r3_453->GetPitchAssist();
                } else {
                    var_f1_458 = temp_r29_450->unk20;
                }
                var_f1_464 = temp_r30_447->unk20 + var_f1_458;
            } else {
                var_f1_464 = temp_r30_447->unk20;
            }
            var_f1_470 = temp_r31_444->unk20 + var_f1_464;
        } else {
            var_f1_470 = temp_r31_444->unk20;
        }
        return this->unk20 + var_f1_470;
    }
    return this->unk20;
}

#endif  // SPYRO_SOURCE_NODELOOKAT_H
