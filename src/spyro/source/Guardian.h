#ifndef SPYRO_SOURCE_GUARDIAN_H
#define SPYRO_SOURCE_GUARDIAN_H

#include <dolphin/types.h>
#include "spyro/source/KDProp.h"

class Guardian;
class KDProp;
class MKAnim;
class MKIniLine;

class Guardian : public KDProp {  // base: ctor/dtor vtable stores
public:
    virtual ~Guardian(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Draw(void);
    void AttachToCage(bool);
    /* 0x089 */ u8 pad89[0x7];
    /* 0x090 */ MKAnim* unk90;
    /* 0x094 */ MKAnim* unk94;
    /* 0x098 */ MKAnim* unk98;
    /* 0x09c */ MKAnim* unk9C;
    /* 0x0a0 */ u8 unkA0;
    /* 0x0a1 */ u8 unkA1;
};

#endif  // SPYRO_SOURCE_GUARDIAN_H
