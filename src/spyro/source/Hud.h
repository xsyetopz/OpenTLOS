#ifndef SPYRO_SOURCE_HUD_H
#define SPYRO_SOURCE_HUD_H

#include <dolphin/types.h>

class HudItem;
class MKMaterial;
class MKVector2;
class MKVector4;
class Matrix;

void Hud_DrawArc(float, float, float, float, float, float, float, float, float, float, const MKVector4 *, const MKVector4 *, Matrix *, MKMaterial *, float, float, float, float);
void Hud_DrawIcon(int, int, const MKVector2 &, const MKVector2 &, const MKVector4 &, float, float, float, float, bool, bool, const Matrix &);
void Hud_DrawIcon(int, int, float, float, float, float, const MKVector4 &, float, float, float, float, bool, bool, const Matrix &);
void Hud_Show(bool);
void Hud_Remove(HudItem *);
void Hud_Add(HudItem *);
void Hud_Draw(void);
void Hud_Update(void);
void Hud_DeinitModule(void);
void Hud_InitModule(void);
extern s8 Hud_bDisableDraw;
#endif  // SPYRO_SOURCE_HUD_H
