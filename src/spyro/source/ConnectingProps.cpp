#include "spyro/source/ConnectingProps.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKProp.h"
#include "spyro/source/Level.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

extern void **gMK;
extern M2C_UNK gb;
static M2C_UNK pChunkTypeNames;                     /* unable to generate initializer: unknown type */

s32 Connector::UpdateState() {
    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) != 0) {
        return 1;
    }
    return ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->SetDesiredChunks((ChunkInfo **) &this->unk50.unk48, (s32) this->unkA0);
}

#if 0 // DRAFT: illegal implicit conversion from 'Connector' to
void Connector::LoadDone() {
    Level *temp_r3_79;
    s32 temp_r29_78;
    s32 var_r28_74;
    s32 var_r31_76;

    MKProp::LoadDone();
    var_r28_74 = 0;
    this->unkA0 = NULL;
    var_r31_76 = 0;
    do {
        temp_r29_78 = var_r31_76 + 0xA0;
        temp_r3_79 = *(this + temp_r29_78);
        if ((temp_r3_79 != NULL) && ((s8) temp_r3_79->unk0 != 0)) {
            *(this + temp_r29_78) = temp_r3_79->GetChunkByName(M2C_ERROR(/* Read from unset register $r4 */));
            this->unkA0 += 1;
        } else {
            *(this + temp_r29_78) = 0;
        }
        var_r28_74 += 1;
        var_r31_76 += 4;
    } while (var_r28_74 < 3);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'long' to
s32 Connector::LoadLine(MKIniLine *arg0) {
    s32 var_r29_130;
    s32 var_r31_132;

    if ((MKProp::LoadLine(arg0) != 0) || (this->unk50.LoadLine("region", arg0) != 0)) {
        return 1;
    }
    var_r29_130 = 0;
    var_r31_132 = 0;
loop_4:
    if (arg0->LoadString(*(&pChunkTypeNames + var_r31_132), this + (var_r31_132 + 0xA0), 0) != 0) {
        return 1;
    }
    var_r29_130 += 1;
    var_r31_132 += 4;
    if (var_r29_130 >= 3) {
        return 0;
    }
    goto loop_4;
}
#endif

void Connector::Deinit() {
    this->unk50.Deinit();
    MKProp::Deinit();
}

void Connector::Init() {
    MKProp::Init();
    this->unk50.Init();
    memset(&this->unk50.unk48, 0, 0xCU);
}

#if 0 // DRAFT: illegal implicit conversion from 'ConnectorDescriptor *' to
void ConnectorDescriptor::Deinit() {
    ConnectorDescriptor *temp_r4_211;
    ConnectorDescriptor *temp_r4_217;

    if ((ConnectorDescriptor *) *ConnectorDescriptor::pFirstDesc == this) {
        *ConnectorDescriptor::pFirstDesc = this->unk68;
    }
    temp_r4_211 = this->unk64;
    if (temp_r4_211 != NULL) {
        temp_r4_211->unk68 = this->unk68;
    }
    temp_r4_217 = this->unk68;
    if (temp_r4_217 != NULL) {
        temp_r4_217->unk64 = this->unk64;
    }
    this->unk64 = NULL;
    this->unk68 = NULL;
    this->unk60 = NULL;
    MKPropDescriptor::Deinit();
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
void ConnectorDescriptor::Init() {
    MKPropDescriptor::Init();
    this->unk68 = *ConnectorDescriptor::pFirstDesc;
    this->unk64 = NULL;
    if ((ConnectorDescriptor *) *ConnectorDescriptor::pFirstDesc != NULL) {
        (*ConnectorDescriptor::pFirstDesc)->unk64 = this;
    }
    *ConnectorDescriptor::pFirstDesc = this;
    this->unk60 = M2C_FIELD(*gMK, void *(**)(void **), 0x7C)(gMK);
}
#endif

#if 0 // DRAFT: illegal implicit conversion from 'unsigned char' to
s32 Connector_Update(const MKVector3 &arg0) {
    Connector *var_r29_291;
    f32 temp_f1_297;
    u8 var_r31_298;
    void *var_r30_286;
    void *var_r4_274;
    void *var_r4_326;

    var_r4_274 = *ConnectorDescriptor::pFirstDesc;
loop_2:
    if ((var_r4_274 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r4_274, void **, 0x60), s32 *, 0x138) & 2)) {
        var_r4_274 = M2C_FIELD(var_r4_274, void **, 0x68);
        goto loop_2;
    }
    var_r30_286 = var_r4_274;
loop_20:
    if (var_r30_286 == NULL) {
        return 1;
    }
    var_r29_291 = checked_cast<Connector *, MKProp>(M2C_FIELD(var_r30_286, MKProp **, 0x28));
loop_14:
    if (var_r29_291 == NULL) {
        var_r4_326 = M2C_FIELD(var_r30_286, void **, 0x68);
loop_17:
        if ((var_r4_326 != NULL) && !(M2C_FIELD(M2C_FIELD(var_r4_326, void **, 0x60), s32 *, 0x138) & 2)) {
            var_r4_326 = M2C_FIELD(var_r4_326, void **, 0x68);
            goto loop_17;
        }
        var_r30_286 = var_r4_326;
        goto loop_20;
    }
    if (!(var_r29_291->unk18 & 0x80000000)) {
        temp_f1_297 = arg0.unk4;
        var_r31_298 = 0;
        M2C_ERROR(/* unknown instruction: cror eq, gt, eq */);
        if (temp_f1_297 == var_r29_291->unk50.unk4.unk18) {
            M2C_ERROR(/* unknown instruction: cror eq, lt, eq */);
            if ((temp_f1_297 == var_r29_291->unk50.unk4.unk1C) && (var_r29_291->unk50.unk4.IsPointWithin(arg0) != 0)) {
                var_r31_298 = 1;
            }
        }
        if (var_r31_298 != 0) {
            return var_r29_291->UpdateState();
        }
        goto block_13;
    }
block_13:
    var_r29_291 = checked_cast<Connector *, MKProp>(var_r29_291->unk38);
    goto loop_14;
}
#endif
