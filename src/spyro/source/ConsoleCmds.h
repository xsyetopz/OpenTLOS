#ifndef SPYRO_SOURCE_CONSOLECMDS_H
#define SPYRO_SOURCE_CONSOLECMDS_H

#include <dolphin/types.h>

class MKProp;

void ConsoleCmds_Unregister(void);
void ConsoleCmds_Register(void);
extern MKProp * ConsoleCmds_pSenderProp;
#endif  // SPYRO_SOURCE_CONSOLECMDS_H
