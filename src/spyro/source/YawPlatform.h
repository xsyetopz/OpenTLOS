#ifndef SPYRO_SOURCE_YAWPLATFORM_H
#define SPYRO_SOURCE_YAWPLATFORM_H

#include <dolphin/types.h>
#include "spyro/source/Platform.h"

class MKIniLine;
class MKMessage;
class Platform;
class YawPlatform;

class YawPlatform : public Platform {  // base: vtable prefix
public:
    virtual ~YawPlatform(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    YawPlatform(void);
    /* 0x17c */ u8 pad17C[0x4];
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
};

#endif  // SPYRO_SOURCE_YAWPLATFORM_H
