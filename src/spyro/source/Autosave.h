#ifndef SPYRO_SOURCE_AUTOSAVE_H
#define SPYRO_SOURCE_AUTOSAVE_H

#include <dolphin/types.h>

class Autosave_cpp;
class KDMemoryCard;
class TimerInfo;

class Autosave_cpp {
public:
    void __sinit(void);
};

s32 Autosave_GetGameDataSize(void);
void * Autosave_GetGameDataCopy(void);
void Autosave_CopyGameData(void);
void Autosave_Draw(void);
void Autosave_ConfirmCard(void);
void Autosave_Update(void);
void Autosave_Reset(void);
void Autosave_FreeResources(void);
void Autosave_LoadResources(void);
void Autosave_DeinitModule(void);
void Autosave_InitModule(void);
void Autosave_EnableRemovalCheck(bool);
u8 Autosave_IsActive(void);
void Autosave_Activate(void);
void Autosave_SetTarget(KDMemoryCard *, int, const TimerInfo &);
extern void * autosaveCard;
#endif  // SPYRO_SOURCE_AUTOSAVE_H
