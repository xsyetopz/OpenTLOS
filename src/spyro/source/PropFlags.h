#ifndef SPYRO_SOURCE_PROPFLAGS_H
#define SPYRO_SOURCE_PROPFLAGS_H

#include <dolphin/types.h>

class MKIniLine;
class MKMessage;

s32 PropFlagsMessage(unsigned int *, MKMessage *);
void PropFlagsClear(unsigned int *, unsigned int);
void PropFlagsSet(unsigned int *, unsigned int);
s32 PropFlagsLoadLine(unsigned int *, MKIniLine *);
void PropFlagsInit(unsigned int *, unsigned int);
#endif  // SPYRO_SOURCE_PROPFLAGS_H
