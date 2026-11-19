#include "common/Source/MKSystem.h"
#include "common/Source/MKCommandLine.h"
#include <m2c_macros.h>

extern u8 bWideScreenEnabled;
extern MKCommandLine cmdLine;
static s32 MKDirtyState_States[0xB];

void FlipEndian(float *arg0) {
    u8 temp_r4_13;
    u8 temp_r4_17;

    temp_r4_13 = M2C_FIELD(arg0, u8 *, 0);
    M2C_FIELD(arg0, u8 *, 0) = (u8) M2C_FIELD(arg0, u8 *, 3);
    M2C_FIELD(arg0, u8 *, 3) = temp_r4_13;
    temp_r4_17 = M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 1) = (u8) M2C_FIELD(arg0, u8 *, 2);
    M2C_FIELD(arg0, u8 *, 2) = temp_r4_17;
}

void FlipEndian(unsigned int *arg0) {
    u8 temp_r4_27;
    u8 temp_r4_31;

    temp_r4_27 = M2C_FIELD(arg0, u8 *, 0);
    M2C_FIELD(arg0, u8 *, 0) = (u8) M2C_FIELD(arg0, u8 *, 3);
    M2C_FIELD(arg0, u8 *, 3) = temp_r4_27;
    temp_r4_31 = M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 1) = (u8) M2C_FIELD(arg0, u8 *, 2);
    M2C_FIELD(arg0, u8 *, 2) = temp_r4_31;
}

void FlipEndian(int *arg0) {
    u8 temp_r4_41;
    u8 temp_r4_45;

    temp_r4_41 = M2C_FIELD(arg0, u8 *, 0);
    M2C_FIELD(arg0, u8 *, 0) = (u8) M2C_FIELD(arg0, u8 *, 3);
    M2C_FIELD(arg0, u8 *, 3) = temp_r4_41;
    temp_r4_45 = M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 1) = (u8) M2C_FIELD(arg0, u8 *, 2);
    M2C_FIELD(arg0, u8 *, 2) = temp_r4_45;
}

void FlipEndian(unsigned short *arg0) {
    u8 temp_r4_55;

    temp_r4_55 = M2C_FIELD(arg0, u8 *, 0);
    M2C_FIELD(arg0, u8 *, 0) = (u8) M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 1) = temp_r4_55;
}

void FlipEndian(short *arg0) {
    u8 temp_r4_65;

    temp_r4_65 = M2C_FIELD(arg0, u8 *, 0);
    M2C_FIELD(arg0, u8 *, 0) = (u8) M2C_FIELD(arg0, u8 *, 1);
    M2C_FIELD(arg0, u8 *, 1) = temp_r4_65;
}

u8 System_IsWideScreenEnabled() {
    return bWideScreenEnabled;
}

void System_EnableWideScreenMode(bool arg0) {
    bWideScreenEnabled = arg0;
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKDirtyStateType'
void MKDirtyState_Dirty(MKDirtyStateType arg0) {
    MKDirtyState_States[(s32) arg0] = -1;
}
#endif

void System_GetCommandLineParameter(const char *arg0, bool arg1) {
    cmdLine.GetParameter(arg0, arg1);
}

void System_InitCommandLineArgs(char *arg0) {
    cmdLine.InitFromString(arg0);
}
