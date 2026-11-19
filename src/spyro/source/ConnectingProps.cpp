#include "spyro/source/ConnectingProps.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKDistanceLevelChunk.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Matrix.h"
#include "spyro/source/BoundingRegion.h"
#include "spyro/source/CustomMaterialUpdater.h"
#include "spyro/source/Level.h"
#include "spyro/source/PolyRegion.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

extern void **gMK;
extern M2C_UNK gb;
static M2C_UNK pChunkTypeNames;                     /* unable to generate initializer: unknown type */

s32 Connector::UpdateState() {
    if ((s32) M2C_FIELD(&gb, s32 *, 0x340) != 0) {
        return 1;
    }
    return ((Level *) (M2C_FIELD(&gb, Level **, 0x32C)))->SetDesiredChunks(&this->unkA0, this->unkAC);
}

s32 Connector::LoadDone() {
    s32 count;
    s32 off;
    const char *name;

    MKProp::LoadDone();
    count = 0;
    this->unkAC = 0;
    off = 0;
    do {
        name = M2C_FIELD(this, const char **, off + 0xA0);
        if ((name != NULL) && (*name != 0)) {
            M2C_FIELD(this, void **, off + 0xA0) = Level::GetChunkByName(name);
            this->unkAC += 1;
        } else {
            M2C_FIELD(this, void **, off + 0xA0) = NULL;
        }
        count += 1;
        off += 4;
    } while (count < 3);
}

s32 Connector::LoadLine(MKIniLine *arg0) {
    s32 count;
    s32 off;

    if ((MKProp::LoadLine(arg0) != 0) || (this->unk50.LoadLine("region", arg0) != 0)) {
        return 1;
    }
    count = 0;
    off = 0;
    do {
        if (arg0->LoadString(M2C_FIELD(&pChunkTypeNames, const char **, off), (const char **) ((s8 *) this + off + 0xA0), 0) != 0) {
            return 1;
        }
        count += 1;
        off += 4;
    } while (count < 3);
    return 0;
}

void Connector::Deinit() {
    this->unk50.Deinit();
    MKProp::Deinit();
}

void Connector::Init() {
    MKProp::Init();
    this->unk50.Init();
    memset(&this->unkA0, 0, 0xCU);
}

void ConnectorDescriptor::Deinit() {
    ConnectorDescriptor *temp_r4_211;
    ConnectorDescriptor *temp_r4_217;

    if ((ConnectorDescriptor *) *ConnectorDescriptor::pFirstDesc == this) {
        *ConnectorDescriptor::pFirstDesc = (unsigned char) (this->unk68);
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

void ConnectorDescriptor::Init() {
    ConnectorDescriptor **first;

    MKPropDescriptor::Init();
    first = (ConnectorDescriptor **) ConnectorDescriptor::pFirstDesc;
    this->unk68 = *first;
    this->unk64 = NULL;
    if (*first != NULL) {
        (*first)->unk64 = this;
    }
    *first = this;
    this->unk60 = M2C_FIELD(*gMK, void *(**)(void **), 0x7C)(gMK);
}

s32 Connector_Update(const MKVector3 &arg0) {
    Connector *var_r29_291;
    f32 temp_f1_297;
    u8 var_r31_298;
    void *var_r30_286;
    void *var_r4_274;
    void *var_r4_326;

    var_r4_274 = (void *) (*ConnectorDescriptor::pFirstDesc);
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
        if ((temp_f1_297 >= var_r29_291->unk50.unk4.unk18) && (temp_f1_297 <= var_r29_291->unk50.unk4.unk1C) && (var_r29_291->unk50.unk4.IsPointWithin(arg0) != 0)) {
            var_r31_298 = 1;
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
