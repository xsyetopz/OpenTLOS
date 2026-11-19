#ifndef COMMON_SOURCE_DEBUG_H
#define COMMON_SOURCE_DEBUG_H

#include <dolphin/types.h>

class MKFont;
class MKVector3;

s32 ValidateVector(const MKVector3 &);
void Debug_SetFont(MKFont *);
void Debug_DeinitModule(void);
void Debug_InitModule(void);
extern MKFont * gpDebugFont;
#endif  // COMMON_SOURCE_DEBUG_H
