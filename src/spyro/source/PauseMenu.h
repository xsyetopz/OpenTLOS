#ifndef SPYRO_SOURCE_PAUSEMENU_H
#define SPYRO_SOURCE_PAUSEMENU_H

#include <dolphin/types.h>

class PauseMenu_cpp;

class PauseMenu_cpp {
public:
    void __sinit(void);
};

void PauseMenu_AutosaveScreen(const char *);
void PauseMenu_AllowStartToQuit(bool);
void PauseMenu_Draw(void);
s32 PauseMenu_Update(void);
void PauseMenu_Reset(const char *);
void PauseMenu_Deinit(void);
void PauseMenu_Init(void);
#endif  // SPYRO_SOURCE_PAUSEMENU_H
