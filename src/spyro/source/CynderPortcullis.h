#ifndef SPYRO_SOURCE_CYNDERPORTCULLIS_H
#define SPYRO_SOURCE_CYNDERPORTCULLIS_H

#include <dolphin/types.h>
#include "common/Source/MKProp.h"
#include "spyro/source/EnemyGenerator.h"
#include "spyro/source/GameProp.h"

class CynderPortcullis;
class CynderPortcullisDescriptor;
class EnemyGenerator;
class EnemyGeneratorDescriptor;
class GameProp;
class MKIniLine;
class MKMessage;
class MKPropDescriptor;

class CynderPortcullis : public GameProp {  // base: vtable prefix
public:
    virtual ~CynderPortcullis(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    CynderPortcullis(void);
    /* 0x0c4 */ u8 padC4[0x4];
    /* 0x0c8 */ EnemyGenerator unkC8;
};

class CynderPortcullisDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    CynderPortcullisDescriptor(void);
    /* 0x048 */ u8 pad48[0x1c];
    /* 0x064 */ s32 unk64;
    /* 0x068 */ u8 pad68[0x7c];
    /* 0x0e4 */ EnemyGeneratorDescriptor unkE4;
};

#endif  // SPYRO_SOURCE_CYNDERPORTCULLIS_H
