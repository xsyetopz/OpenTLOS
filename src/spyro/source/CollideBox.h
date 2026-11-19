#ifndef SPYRO_SOURCE_COLLIDEBOX_H
#define SPYRO_SOURCE_COLLIDEBOX_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class CollideBox;
class KDProp;
class MKIniLine;
class MKMessage;

class CollideBox : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~CollideBox(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Message(MKMessage *);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ u8 unk90;
};

#endif  // SPYRO_SOURCE_COLLIDEBOX_H
