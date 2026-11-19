#ifndef COMMON_SOURCE_MKSYSTEM_H
#define COMMON_SOURCE_MKSYSTEM_H

#include <dolphin/types.h>
#include "common/Source/MKCommandLine.h"
#include "unplaced_enums.h"

class MKCommandLine;

void FlipEndian(float *);
void FlipEndian(unsigned int *);
void FlipEndian(int *);
void FlipEndian(unsigned short *);
void FlipEndian(short *);
u8 System_IsWideScreenEnabled(void);
void System_EnableWideScreenMode(bool);
void MKDirtyState_Dirty(MKDirtyStateType);
void System_GetCommandLineParameter(const char *, bool);
void System_InitCommandLineArgs(char *);
extern MKCommandLine cmdLine;
extern u8 gbGoldMaster;
#endif  // COMMON_SOURCE_MKSYSTEM_H
