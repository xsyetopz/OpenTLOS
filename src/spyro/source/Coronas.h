#ifndef SPYRO_SOURCE_CORONAS_H
#define SPYRO_SOURCE_CORONAS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "common/Source/MKVector4.h"

class Corona;
class Coronas;
class CoronasDescriptor;
class MKIniLine;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class MKVector4;
class MKZRequest;
class Matrix;

class Corona {
public:
    /* 0x000 */ f64 unk0;
    /* 0x008 */ f64 unk8;
    /* 0x010 */ MKVector4 unk10;
    /* 0x020 */ MKZRequest* unk20;
    /* 0x024 */ f32 unk24;
    /* 0x028 */ f32 unk28;
    /* 0x02c */ f32 unk2C;
    /* 0x030 */ u8 unk30;
    /* 0x031 */ u8 unk31;
};

class Coronas : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Coronas(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Reset(void);
    virtual void Update(void);
    virtual void Draw(void);
    void Free(Corona *);
    void * Alloc(const MKVector3 &, const MKVector4 &, const float &, const int &, const bool &);
    void DrawCorona(Corona *, Matrix *);
    /* 0x04c */ void* unk4C;
};

class CoronasDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    /* 0x048 */ u8 pad48[0x18];
    /* 0x060 */ s32 unk60;
    /* 0x064 */ s32 unk64;
    /* 0x068 */ s32 unk68;
};

#endif  // SPYRO_SOURCE_CORONAS_H
