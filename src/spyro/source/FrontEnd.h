#ifndef SPYRO_SOURCE_FRONTEND_H
#define SPYRO_SOURCE_FRONTEND_H

#include <dolphin/types.h>

class FrontEnd_cpp;

class FrontEnd_cpp {
public:
    void __sinit(void);
};

void FrontEnd_PlayVideo(const char *);
void FrontEnd_GoToNewGame(void);
void ErrorMessage_Draw(const char *);
void FrontEnd_UpdateAutoLevelSwitch(void);
void FrontEnd_GotoMainMenu(void);
f32 FrontEnd_GetFade(void);
void FrontEnd_SetFade(float);
void FrontEnd_Draw(void);
void FrontEnd_Update(void);
void FrontEnd_PlayBackgroundVideo(bool);
void FrontEnd_Deinit(void);
void FrontEnd_Init(void);
extern s32 menuLoadingState;
#endif  // SPYRO_SOURCE_FRONTEND_H
