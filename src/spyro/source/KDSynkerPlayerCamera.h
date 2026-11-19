#ifndef SPYRO_SOURCE_KDSYNKERPLAYERCAMERA_H
#define SPYRO_SOURCE_KDSYNKERPLAYERCAMERA_H

#include <dolphin/types.h>

class KDSP_Actor;
class KDSP_Bar;
class KDSP_Camera;
class KDSP_EnvelopeList;
class KDSynkerHeap;
class MKIni;

class KDSP_Bar {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ void* unk8;
    /* 0x00c */ KDSP_Actor* unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

class KDSP_Camera {
public:
    void * FindCameraPath(const char *);
    void * FindCAD(const char *);
    void ParseMCDFile(const char *);
    static void ParseCAD(KDSynkerHeap *, const char *);
    void HeapAddSizeCAD(KDSynkerHeap *, const char *);
    void Parse(KDSynkerHeap *, const char *, MKIni *, int &);
    void HeapAddSize(KDSynkerHeap *, const char *, MKIni *);
    void Update(const char *, float, KDSP_EnvelopeList *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ f32 unk0;
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00c */ f32 unkC;
    /* 0x010 */ f32 unk10;
    /* 0x014 */ f32 unk14;
    /* 0x018 */ f32 unk18;
    /* 0x01c */ f32 unk1C;
    /* 0x020 */ f32 unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ f32 unk30;
    /* 0x034 */ f32 unk34;
    /* 0x038 */ f32 unk38;
    /* 0x03c */ f32 unk3C;
    /* 0x040 */ f64 unk40;
    /* 0x048 */ f64 unk48;
    /* 0x050 */ f64 unk50;
    /* 0x058 */ f64 unk58;
    /* 0x060 */ f32 unk60;
    /* 0x064 */ f32 unk64;
    /* 0x068 */ f32 unk68;
    /* 0x06c */ s8 unk6C;
    /* 0x06d */ u8 pad6D[0x3];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ s32 unk74;
    /* 0x078 */ s32* unk78;
    /* 0x07c */ s32 unk7C;
    /* 0x080 */ MKIni* unk80;
    /* 0x084 */ s32* unk84;
    /* 0x088 */ s32 unk88;
    /* 0x08c */ s32* unk8C;
    /* 0x090 */ s32 unk90;
    /* 0x094 */ u32* unk94;
    /* 0x098 */ u32* unk98;
};

#endif  // SPYRO_SOURCE_KDSYNKERPLAYERCAMERA_H
