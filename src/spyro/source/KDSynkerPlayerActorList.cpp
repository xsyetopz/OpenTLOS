#include "spyro/source/KDSynkerPlayerActorList.h"
#include "common/Source/Animation.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKAttachment.h"
#include "common/Source/MKBaseSceneManager.h"
#include "common/Source/MKIni.h"
#include "common/Source/MKModel.h"
#include "common/Source/MKProp.h"
#include "common/Source/MKResource.h"
#include "common/Source/MKSoftBody.h"
#include "common/Source/MKVector3.h"
#include "common/Source/Matrix.h"
#include "spyro/source/KDInput.h"
#include "spyro/source/KDSynkerPlayer2Messages.h"
#include "spyro/source/KDSynkerPlayerActor.h"
#include "spyro/source/KDSynkerPlayerTools.h"
#include "common/Source/FileSys.h"
#include <m2c_macros.h>

s32 atoi(u8 *);                                     /* extern */
s32 strcmpi(s32, s8 *);                             /* extern */
s32 stricmp(s32, s8 *);                             /* extern */
s8 *strtok(s8 *, M2C_UNK *);                        /* extern */

void KDSP_Subtitles::Update(KDSP_ActorList *arg0, int arg1) {
    s32 actorOff;
    s32 entryOff;
    s32 count;
    s32 i;
    s32 j;
    s32 hit;
    s32 slot;
    s32 last;
    void *actor;
    void *entry;

    actorOff = 0;
    count = arg0->unk0;
    for (i = 0; i < count; i++) {
        actor = (void *) (arg0->unk4 + actorOff);
        entryOff = 0;
        for (j = 0; j < M2C_FIELD(actor, s32 *, 0x54); j++) {
            entry = (void *) (M2C_FIELD(actor, s32 *, 0x58) + entryOff);
            slot = M2C_FIELD(entry, s32 *, 0x1C);
            hit = 0;
            if (arg1 >= M2C_FIELD(entry, s32 *, 0) && arg1 < (s32) (M2C_FIELD(entry, s32 *, 0) + M2C_FIELD(entry, s32 *, 4))) {
                hit = 1;
            }
            if (slot == -1) {
                if (hit != 0) {
                    M2C_FIELD(entry, s32 *, 0x1C) = this->unkA8;
                    *(void **) ((u8 *) this + this->unkA8 * 8 + 0xAC) = *(void **) ((u8 *) this + M2C_FIELD(entry, s32 *, 8) * 4);
                    *(f32 *) ((u8 *) this + this->unkA8 * 8 + 0xB0) = 0.033f * (f32) M2C_FIELD(entry, s32 *, 4);
                    this->unkA8 = (this->unkA8 + 1) % 3;
                }
            } else {
                if (hit == 0) {
                    *(void **) ((u8 *) this + slot * 8 + 0xAC) = NULL;
                    *(f32 *) ((u8 *) this + slot * 8 + 0xB0) = 0.0f;
                    M2C_FIELD(entry, s32 *, 0x1C) = -1;
                }
            }
            entryOff += 0x24;
        }
        actorOff += 0x138;
    }

    last = 0;
    for (i = 0; i < 3; i++) {
        if (*(u32 *) ((u8 *) this + i * 8 + 0xAC) != 0) {
            last = i + 1;
        }
    }
    this->unkA4 = last;
    if (last == 0) {
        this->unkA8 = 0;
    }
}

void KDSP_Subtitles::Parse(KDSynkerHeap *arg0, const char *arg1) {
    u8 sp8[3];
    s32 align;
    s32 base;
    s32 size;
    s32 idx;
    s32 spaces;
    s32 field;
    u8 *cur;
    s32 c;

    size = this->unkA0;
    if (size > 0) {
        align = arg0->unk8 - 1;
        base = arg0->unk0;
        arg0->unk0 = base + ((size + align) & ~align);
        this->unk98 = (u8 *) MKArchive_Load(arg1, NULL, (void *) base, size);
        spaces = 0;
        field = 0;
        cur = this->unk98;
        sp8[2] = 0;
        while (((s32) (cur - this->unk98) < size) && (this->unk9C < 0x26)) {
            c = (s8) *cur;
            if (c == 13 || c == 10) {
                spaces = 0;
                *cur = 0;
                field = 0;
            } else if (c == 32 || c == 9) {
                spaces += 1;
                if (spaces == 1) {
                    idx = atoi(sp8);
                    field = 0;
                    if (idx < 0x26) {
                        ((u8 **) this)[idx] = cur + 1;
                    }
                }
            } else if (spaces == 0 && c > 0x20 && c <= 0x7A) {
                if (field == 8) {
                    sp8[0] = (u8) c;
                } else if (field == 9) {
                    sp8[1] = (u8) c;
                }
                field += 1;
            }
            cur += 1;
        }
    }
}

void KDSP_Subtitles::HeapAddSize(KDSynkerHeap *arg0, const char *arg1) {
    s32 temp_r4_245;

    if (MKArchive_Exists(arg1, (int *) &this->unkA0) != 0) {
        temp_r4_245 = arg0->unk8 - 1;
        arg0->unk4 += (this->unkA0 + temp_r4_245) & ~temp_r4_245;
    }
}

void KDSP_Subtitles::Reset() {
    s32 var_ctr_266;
    s32 var_r4_262;
    void *temp_r6_268;

    var_r4_262 = 0;
    var_ctr_266 = 3;
    do {
        temp_r6_268 = this + var_r4_262;
        var_r4_262 += 8;
        M2C_FIELD(temp_r6_268, s32 *, 0xAC) = 0;
        M2C_FIELD(temp_r6_268, f32 *, 0xB0) = 0.0f;
        var_ctr_266 -= 1;
    } while (var_ctr_266 != 0);
    this->unkA8 = 0;
    this->unkA4 = 0;
}

void KDSP_Subtitles::Init() {
    Reset();
    memset(this, 0, 0x98U);
    this->unk98 = NULL;
    this->unk9C = 0;
    this->unkA0 = 0;
}

s32 KDSP_ActorList::GetActorId(const char *arg0) {
    s32 i;
    s32 off;
    s32 name;

    off = 0;
    for (i = 0; i < this->unk0; i++) {
        name = M2C_FIELD(this->unk4, s32 *, off + 0x5C);
        if (strcmpi((s32) name, (s8 *) arg0) == 0) {
            return i;
        }
        off += 0x138;
    }
    return -1;
}

void KDSP_ActorList::Update(float arg0, KDSP_EnvelopeList *arg1, const MKVector3 &arg2, bool arg3) {
    s32 var_r30_356;
    s32 var_r30_371;
    s32 var_r31_355;
    s32 var_r31_370;

    KDSP_Actor::SetEnvelopeList(arg1);
    var_r31_355 = this->unk4;
    var_r30_356 = 0;
loop_2:
    if (var_r30_356 < (s32) this->unk0) {
        ((KDSP_Actor *) var_r31_355)->Update(arg0, arg2, arg3);
        var_r31_355 += 0x138;
        var_r30_356 += 1;
        goto loop_2;
    }
    var_r31_370 = this->unk4;
    var_r30_371 = 0;
loop_5:
    if (var_r30_371 < (s32) this->unk0) {
        ((KDSP_Actor *) var_r31_370)->UpdateLookat();
        var_r31_370 += 0x138;
        var_r30_371 += 1;
        goto loop_5;
    }
}

extern "C" char *strtok(char *, const char *);
void KDSP_ActorList::ResolveLookAt() {
    s8 sp8[0x20];
    s8 sp28[0x20];
    KDSP_Actor *actor;
    s8 *entry;
    s32 i;
    s32 j;
    s32 off;
    s32 roff;

    off = 0;
    for (i = 0; i < this->unk0; i++) {
        actor = (KDSP_Actor *) (this->unk4 + off);
        if (!(actor->unk40 & 4) && !(actor->unk40 & 8)) {
            roff = 0;
            for (j = 0; j < actor->unk44; j++) {
                entry = (s8 *) actor->unk48 + roff;
                strcpy((char *) sp28, (const char *) M2C_FIELD(entry, s8 **, 8));
                strtok((char *) sp28, ":");
                M2C_FIELD(entry, KDSP_Actor **, 0xC) = FindActor((const char *) sp28);
                roff += 0x14;
                M2C_FIELD(entry, s32 *, 0x10) = (u16) M2C_FIELD(entry, KDSP_Actor **, 0xC)->GetMatchingNodeIndex(strtok(NULL, "\n"));
            }
            roff = 0;
            for (j = 0; j < actor->unk4C; j++) {
                entry = (s8 *) actor->unk50 + roff;
                strcpy((char *) sp8, (const char *) M2C_FIELD(entry, s8 **, 8));
                strtok((char *) sp8, ":");
                M2C_FIELD(entry, KDSP_Actor **, 0xC) = FindActor((const char *) sp8);
                roff += 0x14;
                M2C_FIELD(entry, s32 *, 0x10) = (u16) M2C_FIELD(entry, KDSP_Actor **, 0xC)->GetMatchingNodeIndex(strtok(NULL, "\n"));
            }
        }
        off += 0x138;
    }
}

void KDSP_ActorList::SendMessageToActorProp(bool arg0) {
    KDS_Message_PropEnd sp10;
    s32 spC;
    s32 sp8;
    s32 var_r30_498;
    s32 var_r31_499;
    void *temp_r29_503;
    void *temp_r3_504;
    void *temp_r3_528;

    var_r30_498 = 0;
    var_r31_499 = 0;
loop_6:
    if (var_r30_498 < (s32) this->unk0) {
        temp_r29_503 = (void *) (this->unk4 + var_r31_499);
        temp_r3_504 = M2C_FIELD(temp_r29_503, void **, 0x30);
        if (temp_r3_504 != NULL) {
            if (arg0 != 0) {
                spC = 0;
                sp8 = 0x803;
                M2C_FIELD(M2C_FIELD(temp_r3_504, void **, 0x44), M2C_UNK (**)(s32 *), 0x2C)(&sp8);
            } else {
                sp10.unk4 = 0;
                sp10.Init((((u32) M2C_FIELD(temp_r29_503, u32 *, 0x40) >> 4U) & 1) ^ 1, 0U);
                temp_r3_528 = M2C_FIELD(temp_r29_503, void **, 0x30);
                M2C_FIELD(M2C_FIELD(temp_r3_528, void **, 0x44), M2C_UNK (**)(void *, KDS_Message_PropEnd *), 0x2C)(temp_r3_528, &sp10);
            }
        }
        var_r30_498 += 1;
        var_r31_499 += 0x138;
        goto loop_6;
    }
}

void KDSP_ActorList::Deinit(bool arg0) {
    s32 var_r30_557;
    s32 var_r31_558;

    var_r30_557 = 0;
    var_r31_558 = 0;
loop_2:
    if (var_r30_557 < (s32) this->unk0) {
        ((KDSP_Actor *) (this->unk4 + var_r31_558))->Deinit(arg0);
        var_r30_557 += 1;
        var_r31_558 += 0x138;
        goto loop_2;
    }
    this->unk4 = 0;
    this->unk0 = 0;
}

KDSP_Actor *KDSP_ActorList::FindActor(const char *arg0) {
    s32 i;
    s32 off;

    off = 0;
    for (i = 0; i < this->unk0; i++) {
        if (stricmp((s32) M2C_FIELD(this->unk4, s32 *, off + 0x5C), (s8 *) arg0) == 0) {
            return (KDSP_Actor *) (this->unk4 + off);
        }
        off += 0x138;
    }
    return NULL;
}

void KDSP_ActorList::Load(MKIni *arg0, int &arg1, bool arg2, bool arg3) {
    s32 i;
    s32 off;
    MKIniLine *line;

    off = 0;
    for (i = 0; i < this->unk0; i++) {
        ((KDSP_Actor *) (this->unk4 + off))->Resolve(arg2, M2C_FIELD(this, void (**)(const char *, MKModel **, MKAnimScript **), 0x8), arg3);
        off += 0x138;
    }
    line = this->unk10;
    if (line != NULL && this->unk0 != 0) {
        line = line->unkC->GetSubLine(line);
        while (line != NULL) {
            FindActor((const char *) line->GetFieldName())->LoadActorSectionPostResolve(line, arg2, arg1);
            line = line->unkC->GetNextLine(line);
        }
    }
    off = 0;
    for (i = 0; i < this->unk0; i++) {
        ((KDSP_Actor *) (this->unk4 + off))->HideSpecialSubObjects();
        off += 0x138;
    }
}

void KDSP_ActorList::Parse(KDSynkerHeap *arg0, MKIni *arg1, int &arg2, KDInput *arg3) {
    MKIniLine *line;
    MKIniLine *sub;
    void *buf;
    s32 off;
    s32 align;

    KDSP_Actor::SetInput(arg3);
    line = this->unkC;
    if (line != NULL && this->unk0 != 0) {
        align = arg0->unk14 - 1;
        buf = arg0->unkC;
        arg0->unkC = (u8 *) buf + (((this->unk0 * 0x138) + align) & ~align);
        this->unk4 = (s32) buf;
        memset((void *) this->unk4, 0, this->unk0 * 0x138);
        off = this->unk4;
        sub = line->unkC->GetSubLine(line);
        sub = sub->unkC->GetNextLine(sub);
        while (sub != NULL) {
            ((KDSP_Actor *) off)->Init();
            ((KDSP_Actor *) off)->LoadActorDataSection(arg0, sub);
            off += 0x138;
            sub = sub->unkC->GetNextLine(sub);
        }
    }
    line = this->unk10;
    if (line != NULL && this->unk0 != 0) {
        sub = line->unkC->GetSubLine(line);
        while (sub != NULL) {
            FindActor((const char *) sub->GetFieldName())->LoadActorSection(arg0, sub, arg2);
            sub = sub->unkC->GetNextLine(sub);
        }
    }
}

void KDSP_ActorList::HeapAddSize(KDSynkerHeap *arg0, MKIni *arg1) {
    KDSP_Actor sp8;
    MKIniLine *temp_r29_810;
    MKIniLine *temp_r3_830;
    MKIniLine *temp_r4_849;
    MKIniLine *var_r29_834;
    MKIniLine *var_r29_854;
    s32 temp_r0_817;
    s32 temp_r3_824;

    this->unkC = arg1->GotoLine("ACTOR_DATA", NULL);
    this->unk10 = arg1->GotoLine("ACTORS", NULL);
    temp_r29_810 = this->unkC;
    if (temp_r29_810 != NULL) {
        this->unk0 = temp_r29_810->GetNmbrOfSubLines() - 1;
        temp_r0_817 = this->unk0;
        if (temp_r0_817 != 0) {
            temp_r3_824 = arg0->unk14 - 1;
            arg0->unk10 += ((temp_r0_817 * 0x138) + temp_r3_824) & ~temp_r3_824;
            temp_r3_830 = temp_r29_810->unkC->GetSubLine(temp_r29_810);
            var_r29_834 = temp_r3_830->unkC->GetNextLine(temp_r3_830);
loop_4:
            if (var_r29_834 != NULL) {
                sp8.HeapAddSize(arg0, var_r29_834);
                var_r29_834 = var_r29_834->unkC->GetNextLine(var_r29_834);
                goto loop_4;
            }
            goto block_5;
        }
    } else {
block_5:
        temp_r4_849 = this->unk10;
        if (temp_r4_849 != NULL) {
            var_r29_854 = temp_r4_849->unkC->GetSubLine(temp_r4_849);
loop_8:
            if (var_r29_854 != NULL) {
                sp8.HeapAddSize(arg0, var_r29_854);
                var_r29_854 = var_r29_854->unkC->GetNextLine(var_r29_854);
                goto loop_8;
            }
        }
    }
}

void KDSP_ActorList::Init() {
    this->unk0 = 0;
    this->unk4 = 0;
    M2C_FIELD(this, void **, 0x8) = NULL;
    this->unkC = NULL;
    this->unk10 = NULL;
}
