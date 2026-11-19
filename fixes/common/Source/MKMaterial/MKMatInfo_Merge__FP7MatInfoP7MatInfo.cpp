void MKMatInfo_Merge(MatInfo *arg0, MatInfo *arg1) {
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x1) != 0) {
        strcpy((char *) ((s8 *) arg0 + 0x80), (const char *) ((s8 *) arg1 + 0x80));
        M2C_FIELD(arg0, s32 *, 0x1E4) = M2C_FIELD(arg1, s32 *, 0x1E4);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x2) != 0) {
        M2C_FIELD(arg0, s32 *, 0x24) = M2C_FIELD(arg1, s32 *, 0x24);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x4) != 0) {
        M2C_FIELD(arg0, s32 *, 0x28) = M2C_FIELD(arg1, s32 *, 0x28);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x8) != 0) {
        *(MKVector4 *) ((s8 *) arg0 + 0x30) = *(MKVector4 *) ((s8 *) arg1 + 0x30);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x10) != 0) {
        *(Matrix *) ((s8 *) arg0 + 0x40) = *(Matrix *) ((s8 *) arg1 + 0x40);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x20) != 0) {
        strcpy((char *) ((s8 *) arg0 + 0xA0), (const char *) ((s8 *) arg1 + 0xA0));
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x40) != 0) {
        strcpy((char *) ((s8 *) arg0 + 0xC0), (const char *) ((s8 *) arg1 + 0xC0));
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x80) != 0) {
        M2C_FIELD(arg0, f32 *, 0x2C) = M2C_FIELD(arg1, f32 *, 0x2C);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x100) != 0) {
        M2C_FIELD(arg0, s8 *, 0xE0) = M2C_FIELD(arg1, s8 *, 0xE0);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x200) != 0) {
        M2C_FIELD(arg0, s8 *, 0xE1) = M2C_FIELD(arg1, s8 *, 0xE1);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x400) != 0) {
        M2C_FIELD(arg0, s8 *, 0xE2) = M2C_FIELD(arg1, s8 *, 0xE2);
        M2C_FIELD(arg0, s8 *, 0xE3) = M2C_FIELD(arg1, s8 *, 0xE3);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x800) != 0) {
        M2C_FIELD(arg0, s8 *, 0xE4) = M2C_FIELD(arg1, s8 *, 0xE4);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x1000) != 0) {
        M2C_FIELD(arg0, s8 *, 0xE5) = M2C_FIELD(arg1, s8 *, 0xE5);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x2000) != 0) {
        M2C_FIELD(arg0, s8 *, 0xE6) = M2C_FIELD(arg1, s8 *, 0xE6);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x8000) != 0) {
        strcpy((char *) ((s8 *) arg0 + 0xE8), (const char *) ((s8 *) arg1 + 0xE8));
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x10000) != 0) {
        strcpy((char *) ((s8 *) arg0 + 0x108), (const char *) ((s8 *) arg1 + 0x108));
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x20000) != 0) {
        memcpy((s8 *) arg0 + 0x128, (s8 *) arg1 + 0x128, 0xCU);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x40000) != 0) {
        memcpy((s8 *) arg0 + 0x134, (s8 *) arg1 + 0x134, 0xCU);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x80000) != 0) {
        memcpy((s8 *) arg0 + 0x140, (s8 *) arg1 + 0x140, 0x10U);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x100000) != 0) {
        memcpy((s8 *) arg0 + 0x150, (s8 *) arg1 + 0x150, 0x10U);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x200000) != 0) {
        memcpy((s8 *) arg0 + 0x160, (s8 *) arg1 + 0x160, 0x10U);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x400000) != 0) {
        memcpy((s8 *) arg0 + 0x170, (s8 *) arg1 + 0x170, 0x24U);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x800000) != 0) {
        M2C_FIELD(arg0, f32 *, 0x194) = M2C_FIELD(arg1, f32 *, 0x194);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x1000000) != 0) {
        M2C_FIELD(arg0, s8 *, 0x198) = M2C_FIELD(arg1, s8 *, 0x198);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x2000000) != 0) {
        M2C_FIELD(arg0, s8 *, 0x199) = M2C_FIELD(arg1, s8 *, 0x199);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x4000000) != 0) {
        M2C_FIELD(arg0, s8 *, 0x19A) = M2C_FIELD(arg1, s8 *, 0x19A);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x4000) != 0) {
        M2C_FIELD(arg0, s8 *, 0xE7) = M2C_FIELD(arg1, s8 *, 0xE7);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x10000000) != 0) {
        strcpy((char *) ((s8 *) arg0 + 0x1BC), (const char *) ((s8 *) arg1 + 0x1BC));
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x40000000) != 0) {
        M2C_FIELD(arg0, s8 *, 0x1DC) = M2C_FIELD(arg1, s8 *, 0x1DC);
    }
    if ((M2C_FIELD(arg1, u32 *, 0x1E0) & 0x80000000) != 0) {
        M2C_FIELD(arg0, s8 *, 0x1DD) = M2C_FIELD(arg1, s8 *, 0x1DD);
    }
    M2C_FIELD(arg0, s8 *, 0x1DE) = 0;
    M2C_FIELD(arg0, u32 *, 0x1E0) = M2C_FIELD(arg1, u32 *, 0x1E0);
}
