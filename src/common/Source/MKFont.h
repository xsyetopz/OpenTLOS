#ifndef COMMON_SOURCE_MKFONT_H
#define COMMON_SOURCE_MKFONT_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class CharInfo;
class FontPage;
class MKFont;
class MKVector3;
class MKVector4;
class Matrix;
class TextCharStrip;
class TextLineData;

class MKFont {
public:
    f32 * GetFontColour(int);
    void ParseFontColours(char *);
    s32 ScanForToken(const char *, unsigned int);
    void BuildMaterialList(const char *);
    void ResetFontStack(MKFont *, unsigned int);
    CharInfo * GetCharacter(const char *, int *, FontPage **);
    u8 IsToken(const char *, unsigned int);
    f32 GetWidthOfCharacter(char, CharInfo *, FontPage *);
    f32 DrawString2dWrapped(const char *, float, float, float, float, float, int, unsigned int);
    void * GetCharacterFontPage(unsigned int);
    f32 DrawString(const char *, float, float, Matrix *, int, unsigned int, float, float, void (*)(TextCharStrip **, int, const Matrix &), bool);
    void BuildLines(const char *, float, float, TextLineData *, float, float, bool);
    void RenderChars(TextCharStrip **, int, const Matrix &);
    void DeinitModule(void);
    static void InitModule(void);
    f32 CalcLength(const char *);
    f32 GetScale(float);
    f32 GetHeight(void);
    void Destroy(void);
    void * Find(const char *);
    MKFont * Create(const char *);
    static u8 pEndToken[0x4];
    static u8 pStartToken[0x4];
    static u8 pColourToken[0x4];
    static u8 pEndColourToken[0x4];
    static u8 pPageToken[0x4];
    static u8 bInitialised[0x1];
    static u8 endTokenLen[0x4];
    static u8 startTokenLen[0x4];
    static u8 colourTokenLen[0x4];
    static u8 endColourTokenLen[0x4];
    static u8 pageTokenLen[0x4];
    static u8 fontList[0x4];
    static u8 currentFontStack[0x4];
    static u8 currentFont[0x4];
    static u8 fontColours[0x4];
    static u8 currentColour[0x4];
    /* 0x000 */ f64 unk0;
    /* 0x008 */ s32 unk8;
};

f32 MKFont_DrawStringJustified(MKFont *, const char *, const MKVector3 &, float, float, FontJustify, float, const MKVector4 &, int, const Matrix &);
void MKFont_GetCharPosJustified(MKFont *, const char *, int, float, float, FontJustify, float);
void MKFont_GetNextWrapPoint(MKFont *, const char *, float, float, int *);
void MKFont_DrawDebugStringF(const char *, float, float, float, const MKVector4 &, int, MKFont *);
f32 MKFont_DrawString(MKFont *, const char *, const MKVector3 &, float, const MKVector4 &, int, const Matrix &);
s32 MKFont_GetNumRenderableChars(const char *, int);
void MKFont_GetCharPos(MKFont *, const char *, int, float);
f32 MKFont_CalculateWidth(MKFont *, const char *, float, float, int, float *);
f32 MKFontInternal_CalcHeightAndScale(MKFont *, float, float *);
f32 MKFont_GetHeight(MKFont *);
#endif  // COMMON_SOURCE_MKFONT_H
