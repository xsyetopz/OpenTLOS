#ifndef COMMON_SOURCE_DISCERRORS_H
#define COMMON_SOURCE_DISCERRORS_H

#include <dolphin/types.h>

void DiscErr_DrawString(char *);
void DiscErr_DrawErrorString(void);
s8 * DiscErr_GetErrorString(void);
void DiscErr_ClearError(void);
s32 DiscErr_IsError(void);
void DiscErr_SetError(int);
#endif  // COMMON_SOURCE_DISCERRORS_H
