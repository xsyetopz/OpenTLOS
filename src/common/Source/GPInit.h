#ifndef COMMON_SOURCE_GPINIT_H
#define COMMON_SOURCE_GPINIT_H

#include <dolphin.h>
#include "unplaced_enums.h"

class _GXRenderModeObj;

void MK_SetVDMode(MK_VertexDescriptorMode);
void GPGetCurrentBuffer(void);
GXRenderModeObj * GPGetRenderModeObj(void);
void GPDoneRender(void);
void GPInit(_GXRenderModeObj *);
extern s32 gFramesPerSecond;
extern s32 gCPUFramesPerSecond;
extern s32 gGPUFramesPerSecond;
#endif  // COMMON_SOURCE_GPINIT_H
