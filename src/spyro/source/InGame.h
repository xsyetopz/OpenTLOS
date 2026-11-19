#ifndef SPYRO_SOURCE_INGAME_H
#define SPYRO_SOURCE_INGAME_H

#include <dolphin/types.h>

class InGame_cpp;
class MKMessage;

class InGame_cpp {
public:
    void __sinit(void);
};

void InGame_SystemMessage(MKMessage *);
void InGame_Draw(void);
void InGame_Update(void);
void InGame_Deinit(void);
void InGame_Init(void);
extern s8 bShowLoading;
#endif  // SPYRO_SOURCE_INGAME_H
