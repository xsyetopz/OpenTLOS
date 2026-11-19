#ifndef SPYRO_SOURCE_YAWPLATFORM_H
#define SPYRO_SOURCE_YAWPLATFORM_H

#include <dolphin/types.h>
#include "spyro/source/Platform.h"

class MKIniLine;
class MKMessage;
class Platform;
class YawPlatform;

class YawPlatform : public Platform {  // base: base ctor call
public:
    virtual ~YawPlatform(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual s32 LoadDone(void);
    virtual void Deinit(void);
    virtual void * Update(void);
    virtual void Message(MKMessage *);
    YawPlatform(void);
    /* 0x180 */ f32 unk180;
    /* 0x184 */ f32 unk184;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline YawPlatform::YawPlatform() {
}

inline YawPlatform::~YawPlatform() {
}

#endif  // SPYRO_SOURCE_YAWPLATFORM_H
