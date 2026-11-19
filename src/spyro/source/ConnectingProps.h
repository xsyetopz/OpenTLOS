#ifndef SPYRO_SOURCE_CONNECTINGPROPS_H
#define SPYRO_SOURCE_CONNECTINGPROPS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/PolyRegion.h"

class ChunkInfo;
class Connector;
class ConnectorDescriptor;
class MKIniLine;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class PolyRegion;

class Connector : public MKProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Connector(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    s32 UpdateState(void);
    /* 0x04c */ u8 pad4C[0x4];
    /* 0x050 */ PolyRegion unk50;
    /* 0x09c */ u8 pad9C[0x4];
    /* 0x0a0 */ ChunkInfo* unkA0;
    /* 0x0a4 */ u8 padA4[0x8];
    /* 0x0ac */ s32 unkAC;
};

class ConnectorDescriptor : public MKPropDescriptor {  // base: inlined ctor vtable stores
public:
    virtual void Init(void);
    virtual void Deinit(void);
    static u8 pFirstDesc[0x4];
    /* 0x044 */ u8 pad44[0x1c];
    /* 0x060 */ void* unk60;
    /* 0x064 */ ConnectorDescriptor* unk64;
    /* 0x068 */ ConnectorDescriptor* unk68;
};

s32 Connector_Update(const MKVector3 &);
// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline Connector::~Connector() {
    s32 temp_cr0_eq_15;

    temp_cr0_eq_15 = this == NULL;
    if (temp_cr0_eq_15 == 0) {
        if (temp_cr0_eq_15 == 0) {
        }
    }
}

#endif  // SPYRO_SOURCE_CONNECTINGPROPS_H
