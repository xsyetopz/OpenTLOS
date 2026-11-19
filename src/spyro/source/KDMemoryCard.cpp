#include "spyro/source/KDMemoryCard.h"
#include "common/Source/MKMemoryCard.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'tmpfileInfo' redeclared
static M2C_UNK lit_490;                                /* unable to generate initializer: unknown type */
static KDMemoryCard stateData__12KDMemoryCard[6] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
}; /* extra bytes: 9 */
static MKMemoryCardFileInfo tmpfileInfo[0x10];
#endif
#if 0 // DRAFT: illegal use of incomplete struct/union/class '_struct_card_0x280'
static struct _struct_card_0x280 card[2];
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::LoadData_Update(int arg0) {
    switch (arg0) {                                 /* irregular */
    case -2:
    case -3:
        Reset(0U);
        /* fallthrough */
    default:
        SetState((KDMCState) 1);
        return;
    case 0:
        SetState((KDMCState) 0);
        return;
    }
}
#endif

void KDMemoryCard::LoadData_Init() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::LoadData(int arg0, void *arg1, int arg2) {
    this->unk4 = arg0;
    SetState((KDMCState) 0xA);
    MKMemoryCard_Load(this->unk0, this->unk4, arg1, arg2);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::SaveData_Update(int arg0) {
    if (arg0 != 0) {
        this->unkA = arg0 == -0x12;
        if ((arg0 == -2) || (arg0 == -3)) {
            Reset(0U);
        }
        SetState((KDMCState) 1);
    } else {
        M2C_FIELD((this + (this->unk4 * 0xC0)), s8 *, 0xE4) = 1;
        SetState((KDMCState) 0);
    }
    this->unk4 = -1;
}
#endif

void KDMemoryCard::SaveData_Init() {

}

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::SaveData(int arg0, void *arg1, int arg2, const char *arg3) {
    s32 temp_r4_138;

    this->unk4 = arg0;
    SetState((KDMCState) 9);
    temp_r4_138 = this->unk4;
    MKMemoryCard_Save(this->unk0, temp_r4_138, arg1, arg2, arg3, this + ((temp_r4_138 * 0xC0) + 0xC0));
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::DeleteCorrupted_Update(int arg0) {
    if (arg0 == 0) {
        M2C_FIELD((this + (this->unk4 * 0xC0)), s8 *, 0xE5) = 0;
        M2C_FIELD((this + (this->unk4 * 0xC0)), s8 *, 0xE4) = 0;
        this->unk24 -= 1;
        SetState((KDMCState) 8);
        return;
    }
    SetState((KDMCState) 1);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void KDMemoryCard::DeleteCorrupted_Init() {
    s32 temp_r4_197;
    void *temp_r5_201;

loop_1:
    this->unk4 += 1;
    temp_r4_197 = this->unk4;
    if (temp_r4_197 < 3) {
        temp_r5_201 = this + (temp_r4_197 * 0xC0);
        if (((s8) M2C_FIELD(temp_r5_201, u8 *, 0xE4) == 0) || ((s8) M2C_FIELD(temp_r5_201, u8 *, 0xE5) == 0)) {
            goto loop_1;
        }
    }
    if (temp_r4_197 < 3) {
        MKMemoryCard_Delete(this->unk0, temp_r4_197);
        return;
    }
    this->unk4 = -1;
    SetState((KDMCState) 0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::Prepare_Update(int arg0) {
    if (arg0 != 0) {
        SetState((KDMCState) 1);
        return;
    }
    this->unk20 = 1;
    SetState((KDMCState) 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void KDMemoryCard::Prepare_Init() {
    MKMemoryCard_Prepare(this->unk0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::Format_Update(int arg0) {
    switch (arg0) {                                 /* irregular */
    case -2:
    case -3:
        Reset(0U);
        SetState((KDMCState) 1);
        return;
    default:
        this->unkA = arg0 == -0x12;
        SetState((KDMCState) 1);
        return;
    case 0:
        this->unk1C = 1;
        SetState((KDMCState) 0);
        return;
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void KDMemoryCard::Format_Init() {
    MKMemoryCard_Format(this->unk0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::CheckFilesExist_Update(int arg0) {
    s32 var_ctr_349;
    s32 var_r4_346;

    if ((arg0 == -2) || (arg0 == -3)) {
        Reset(0U);
        SetState((KDMCState) 0);
        return;
    }
    memcpy(this + 0x40, tmpfileInfo, 0x240U);
    var_r4_346 = 0;
    this->unk24 = 0;
    var_ctr_349 = 3;
    do {
        if ((s8) *(this + (var_r4_346 + 0xE4)) != 0) {
            this->unk24 += 1;
        }
        var_r4_346 += 0xC0;
        var_ctr_349 -= 1;
    } while (var_ctr_349 != 0);
    this->unk8 = 0;
    SetState((KDMCState) 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void KDMemoryCard::CheckFilesExist_Init() {
    MKMemoryCard_GetDirInfo(this->unk0, tmpfileInfo);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::CheckIsPrepared_Update(int arg0) {
    if ((arg0 == -2) || (arg0 == -3)) {
        Reset(0U);
        SetState((KDMCState) 0);
        return;
    }
    this->unk20 = (s32) (u8) (arg0 == 0);
    this->unkB = arg0 == -0xD;
    if ((s32) this->unk20 != 0) {
        SetState((KDMCState) 5);
        return;
    }
    this->unk8 = 0;
    SetState((KDMCState) 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void KDMemoryCard::CheckIsPrepared_Init() {
    MKMemoryCard_IsPrepared(this->unk0);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::CheckCard_Update(int arg0) {
    if ((arg0 == -2) || (arg0 == -3)) {
        Reset(0U);
        SetState((KDMCState) 0);
        return;
    }
    this->unkB = arg0 == -7;
    this->unkA = arg0 == -0x12;
    this->unkC = arg0 == -4;
    this->unkD = arg0 == -5;
    if (((u8) this->unkB != 0) || ((u8) this->unkA != 0) || ((u8) this->unkC != 0) || ((u8) this->unkD != 0)) {
        this->unk8 = 0;
        if ((u8) this->unkB != 0) {
            this->unk1C = 0;
            this->unk20 = 0;
        }
        SetState((KDMCState) 0);
        return;
    }
    if ((s32) this->unk1C != 0) {
        SetState((KDMCState) 4);
        return;
    }
    this->unk8 = 0;
    SetState((KDMCState) 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void KDMemoryCard::CheckCard_Init() {
    Reset(1U);
    MKMemoryCard_GetInfo(this->unk0, &this->unk18, &this->unk14, &this->unk10, &this->unk1C);
}
#endif

#if 0 // DRAFT: illegal explicit conversion from 'int' to
void KDMemoryCard::IsAttached_Update(int arg0) {
    if ((arg0 == -2) || (arg0 == -3)) {
        Reset(0U);
    } else if (((u8) this->unk9 == 0) || (arg0 == -0xC)) {
        Reset(1U);
    }
    SetState((KDMCState) 0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void KDMemoryCard::IsAttached_Init() {
    MKMemoryCard_IsAttached(this->unk0);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
s32 KDMemoryCard::IsBusy() {
    return MKMemoryCard_GetStatus(this->unk0) == 1;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void *KDMemoryCard::GetNextAvailable(KDMemoryCard *arg0) {
    s32 var_ctr_640;
    s32 var_r4_639;
    s32 var_r6_631;
    void *temp_r3_644;

    if (this != NULL) {
        var_r6_631 = this->unk0 + 1;
    } else {
        var_r6_631 = 0;
    }
    var_r4_639 = var_r6_631 * 0x280;
    var_ctr_640 = 2 - var_r6_631;
    if (var_r6_631 < 2) {
loop_4:
        temp_r3_644 = card + var_r4_639;
        if ((u8) M2C_FIELD(temp_r3_644, u8 *, 9) == 0) {
            var_r4_639 += 0x280;
            var_ctr_640 -= 1;
            if (var_ctr_640 == 0) {
                /* Duplicate return node #6. Try simplifying control flow for better match */
                return NULL;
            }
            goto loop_4;
        }
        return temp_r3_644;
    }
    return NULL;
}
#endif

#if 0 // DRAFT: undefined identifier 'card'
void *KDMemoryCard::GetFirstAvailable() {
    s32 var_ctr_662;
    s32 var_r4_661;
    void *temp_r3_664;

    var_r4_661 = 0;
    var_ctr_662 = 2;
loop_1:
    temp_r3_664 = card + var_r4_661;
    if ((u8) M2C_FIELD(temp_r3_664, u8 *, 9) == 0) {
        var_r4_661 += 0x280;
        var_ctr_662 -= 1;
        if (var_ctr_662 == 0) {
            return NULL;
        }
        goto loop_1;
    }
    return temp_r3_664;
}
#endif

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'KDMCState'
void KDMemoryCard::SetState(KDMCState arg0) {
    s32 temp_r5_679;

    temp_r5_679 = (s32) arg0 * 0x18;
    state.unk0 = (s32) arg0;
    currentCard.unk0 = (s32) this;
    if (__ptmf_test(stateData + temp_r5_679, temp_r5_679) != 0) {
        __ptmf_scall(this, state.unk0 * 0x18);
    }
}
#endif

#if 0 // DRAFT: expression syntax error
s32 KDMemoryCard::Update() {
    s32 var_r3_743;

    if (((u32) currentCard.unk0 == 0U) || ((s32) state.unk0 == 0) || ((s32) state.unk0 == 1)) {
        return 0;
    }
    if (MKMemoryCard_GetStatus(*currentCard.unk0) == 1) {
        return 1;
    }
    __ptmf_scall((KDMemoryCard *) currentCard.unk0, (s32) (stateData + (state.unk0 * 0x18)));
    var_r3_743 = 0;
    if (((s32) state.unk0 != 0) && ((s32) state.unk0 != 1)) {
        var_r3_743 = 1;
    }
    return var_r3_743;
}
#endif

#if 0 // DRAFT: expression syntax error
s32 KDMemoryCard::WasErrorDuringLast() {
    return state.unk0 == 1;
}
#endif

#if 0 // DRAFT: expression syntax error
void KDMemoryCard::Reset(bool arg0) {
    this->unk8 = 1;
    if ((u8) this->unk9 != arg0) {
        if (arg0 != 0) {
            numCardsPresent.unk0 += 1;
        } else {
            numCardsPresent.unk0 -= 1;
        }
    }
    this->unk9 = arg0;
    this->unkA = 0;
    this->unkB = 0;
    this->unkC = 0;
    this->unkD = 0;
    this->unk10 = 0;
    this->unk14 = 0;
    this->unk18 = 0;
    this->unk1C = 0;
    this->unk20 = 0;
    this->unk24 = 0;
    memset(this + 0x40, 0, 0x240U);
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void KDMemoryCard::Init(int arg0) {
    this->unk0 = arg0;
    state.unk0 = 0;
    this->unk4 = -1;
    Reset(0U);
}
#endif

#if 0 // DRAFT: undefined identifier 'card'
void KDMemoryCard::InitModule() {
    s32 var_r29_839;
    s32 var_r31_841;

    var_r29_839 = 0;
    var_r31_841 = 0;
    do {
        ((KDMemoryCard *) (card + var_r31_841))->Init(var_r29_839);
        var_r29_839 += 1;
        var_r31_841 += 0x280;
    } while (var_r29_839 < 2);
}
#endif

#if 0 // DRAFT: expression syntax error
s32 KDMemoryCard::GetNextCard() {
    if ((u32) currentCard.unk0 >= &card[1]) {
        return 0;
    }
    return currentCard.unk0 + 0x280;
}
#endif

#if 0 // DRAFT: undefined identifier 'card'
void *KDMemoryCard::GetCard(int arg0) {
    return &card[(s32) this];
}
#endif

#if 0 // DRAFT: undefined identifier 'lit_490'
void KDMemoryCard_cpp::__sinit() {
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    void *temp_r18_890;

    temp_r18_890 = &lit_490 + 0xD8;
    sp14 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    sp18 = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp1C = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(&lit_490, s32 *, 0xD8) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(&lit_490, s32 *, 0xDC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(&lit_490, s32 *, 0xE0) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    sp8 = M2C_FIELD(&__ptmf_null, s32 *, 0);
    spC = M2C_FIELD(&__ptmf_null, s32 *, 4);
    sp10 = M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r18_890, s32 *, 0xC) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r18_890, s32 *, 0x10) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r18_890, s32 *, 0x14) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r18_890, s32 *, 0x18) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r18_890, s32 *, 0x1C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r18_890, s32 *, 0x20) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r18_890, s32 *, 0x24) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 0);
    M2C_FIELD(temp_r18_890, s32 *, 0x28) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 4);
    M2C_FIELD(temp_r18_890, s32 *, 0x2C) = (s32) M2C_FIELD(&__ptmf_null, s32 *, 8);
    M2C_FIELD(temp_r18_890, s32 *, 0x30) = (s32) M2C_FIELD(&lit_490, s32 *, 0);
    M2C_FIELD(temp_r18_890, s32 *, 0x34) = (s32) M2C_FIELD(&lit_490, s32 *, 4);
    M2C_FIELD(temp_r18_890, s32 *, 0x38) = (s32) M2C_FIELD(&lit_490, s32 *, 8);
    M2C_FIELD(temp_r18_890, s32 *, 0x3C) = (s32) M2C_FIELD(&lit_490, s32 *, 0xC);
    M2C_FIELD(temp_r18_890, s32 *, 0x40) = (s32) M2C_FIELD(&lit_490, s32 *, 0x10);
    M2C_FIELD(temp_r18_890, s32 *, 0x44) = (s32) M2C_FIELD(&lit_490, s32 *, 0x14);
    M2C_FIELD(temp_r18_890, s32 *, 0x48) = (s32) M2C_FIELD(&lit_490, s32 *, 0x18);
    M2C_FIELD(temp_r18_890, s32 *, 0x4C) = (s32) M2C_FIELD(&lit_490, s32 *, 0x1C);
    M2C_FIELD(temp_r18_890, s32 *, 0x50) = (s32) M2C_FIELD(&lit_490, s32 *, 0x20);
    M2C_FIELD(temp_r18_890, s32 *, 0x54) = (s32) M2C_FIELD(&lit_490, s32 *, 0x24);
    M2C_FIELD(temp_r18_890, s32 *, 0x58) = (s32) M2C_FIELD(&lit_490, s32 *, 0x28);
    M2C_FIELD(temp_r18_890, s32 *, 0x5C) = (s32) M2C_FIELD(&lit_490, s32 *, 0x2C);
    M2C_FIELD(temp_r18_890, s32 *, 0x60) = (s32) M2C_FIELD(&lit_490, s32 *, 0x30);
    M2C_FIELD(temp_r18_890, s32 *, 0x64) = (s32) M2C_FIELD(&lit_490, s32 *, 0x34);
    M2C_FIELD(temp_r18_890, s32 *, 0x68) = (s32) M2C_FIELD(&lit_490, s32 *, 0x38);
    M2C_FIELD(temp_r18_890, s32 *, 0x6C) = (s32) M2C_FIELD(&lit_490, s32 *, 0x3C);
    M2C_FIELD(temp_r18_890, s32 *, 0x70) = (s32) M2C_FIELD(&lit_490, s32 *, 0x40);
    M2C_FIELD(temp_r18_890, s32 *, 0x74) = (s32) M2C_FIELD(&lit_490, s32 *, 0x44);
    M2C_FIELD(temp_r18_890, s32 *, 0x78) = (s32) M2C_FIELD(&lit_490, s32 *, 0x48);
    M2C_FIELD(temp_r18_890, s32 *, 0x7C) = (s32) M2C_FIELD(&lit_490, s32 *, 0x4C);
    M2C_FIELD(temp_r18_890, s32 *, 0x80) = (s32) M2C_FIELD(&lit_490, s32 *, 0x50);
    M2C_FIELD(temp_r18_890, s32 *, 0x84) = (s32) M2C_FIELD(&lit_490, s32 *, 0x54);
    M2C_FIELD(temp_r18_890, s32 *, 0x88) = (s32) M2C_FIELD(&lit_490, s32 *, 0x58);
    M2C_FIELD(temp_r18_890, s32 *, 0x8C) = (s32) M2C_FIELD(&lit_490, s32 *, 0x5C);
    sp28 = M2C_FIELD(&lit_490, s32 *, 0xC8);
    M2C_FIELD(temp_r18_890, s32 *, 0xF0) = (s32) M2C_FIELD(&lit_490, s32 *, 0xC0);
    sp20 = M2C_FIELD(&lit_490, s32 *, 0xCC);
    M2C_FIELD(temp_r18_890, s32 *, 0xF8) = sp28;
    M2C_FIELD(temp_r18_890, s32 *, 0xFC) = sp20;
    M2C_FIELD(temp_r18_890, s32 *, 0x90) = (s32) M2C_FIELD(&lit_490, s32 *, 0x60);
    M2C_FIELD(temp_r18_890, s32 *, 0x94) = (s32) M2C_FIELD(&lit_490, s32 *, 0x64);
    M2C_FIELD(temp_r18_890, s32 *, 0x98) = (s32) M2C_FIELD(&lit_490, s32 *, 0x68);
    M2C_FIELD(temp_r18_890, s32 *, 0x9C) = (s32) M2C_FIELD(&lit_490, s32 *, 0x6C);
    M2C_FIELD(temp_r18_890, s32 *, 0xA0) = (s32) M2C_FIELD(&lit_490, s32 *, 0x70);
    M2C_FIELD(temp_r18_890, s32 *, 0xA4) = (s32) M2C_FIELD(&lit_490, s32 *, 0x74);
    M2C_FIELD(temp_r18_890, s32 *, 0xA8) = (s32) M2C_FIELD(&lit_490, s32 *, 0x78);
    M2C_FIELD(temp_r18_890, s32 *, 0xAC) = (s32) M2C_FIELD(&lit_490, s32 *, 0x7C);
    M2C_FIELD(temp_r18_890, s32 *, 0xB0) = (s32) M2C_FIELD(&lit_490, s32 *, 0x80);
    M2C_FIELD(temp_r18_890, s32 *, 0xB4) = (s32) M2C_FIELD(&lit_490, s32 *, 0x84);
    M2C_FIELD(temp_r18_890, s32 *, 0xB8) = (s32) M2C_FIELD(&lit_490, s32 *, 0x88);
    M2C_FIELD(temp_r18_890, s32 *, 0xBC) = (s32) M2C_FIELD(&lit_490, s32 *, 0x8C);
    M2C_FIELD(temp_r18_890, s32 *, 0xC0) = (s32) M2C_FIELD(&lit_490, s32 *, 0x90);
    M2C_FIELD(temp_r18_890, s32 *, 0xC4) = (s32) M2C_FIELD(&lit_490, s32 *, 0x94);
    M2C_FIELD(temp_r18_890, s32 *, 0xC8) = (s32) M2C_FIELD(&lit_490, s32 *, 0x98);
    M2C_FIELD(temp_r18_890, s32 *, 0xCC) = (s32) M2C_FIELD(&lit_490, s32 *, 0x9C);
    M2C_FIELD(temp_r18_890, s32 *, 0xD0) = (s32) M2C_FIELD(&lit_490, s32 *, 0xA0);
    M2C_FIELD(temp_r18_890, s32 *, 0xD4) = (s32) M2C_FIELD(&lit_490, s32 *, 0xA4);
    M2C_FIELD(temp_r18_890, s32 *, 0xD8) = (s32) M2C_FIELD(&lit_490, s32 *, 0xA8);
    M2C_FIELD(temp_r18_890, s32 *, 0xDC) = (s32) M2C_FIELD(&lit_490, s32 *, 0xAC);
    M2C_FIELD(temp_r18_890, s32 *, 0xE0) = (s32) M2C_FIELD(&lit_490, s32 *, 0xB0);
    M2C_FIELD(temp_r18_890, s32 *, 0xE4) = (s32) M2C_FIELD(&lit_490, s32 *, 0xB4);
    M2C_FIELD(temp_r18_890, s32 *, 0xE8) = (s32) M2C_FIELD(&lit_490, s32 *, 0xB8);
    M2C_FIELD(temp_r18_890, s32 *, 0xEC) = (s32) M2C_FIELD(&lit_490, s32 *, 0xBC);
    M2C_FIELD(temp_r18_890, s32 *, 0xF4) = (s32) M2C_FIELD(&lit_490, s32 *, 0xC4);
    M2C_FIELD(temp_r18_890, s32 *, 0x100) = (s32) M2C_FIELD(&lit_490, s32 *, 0xD0);
    M2C_FIELD(temp_r18_890, s32 *, 0x104) = (s32) M2C_FIELD(&lit_490, s32 *, 0xD4);
    sp24 = M2C_FIELD(&lit_490, s32 *, 0xD0);
}
#endif
