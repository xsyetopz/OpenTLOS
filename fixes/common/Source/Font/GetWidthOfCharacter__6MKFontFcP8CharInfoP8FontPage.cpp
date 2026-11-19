f32 MKFont::GetWidthOfCharacter(char arg0, CharInfo *arg1, FontPage *arg2) {
    if ((u8) arg0 > 0x20U) {
        if (arg1->unk1C != 0) {
            return arg1->unk18 + M2C_FIELD(*(s8 **) (*(s8 **) arg2->unk0 + arg2->unk4 * 4), f32 *, 8);
        }
        return M2C_FIELD(*(s8 **) (*(s8 **) arg2->unk0 + arg2->unk4 * 4), f32 *, 0xC);
    }
    return M2C_FIELD(*(s8 **) (*(s8 **) arg2->unk0 + arg2->unk4 * 4), f32 *, 0xC);
}
