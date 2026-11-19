#ifndef SPYRO_SOURCE_DROPBOX_H
#define SPYRO_SOURCE_DROPBOX_H

#include <dolphin/types.h>
#include "common/Source/MKVector3.h"
#include "spyro/source/EventMessage.h"
#include "spyro/source/Shatterable.h"

class DropBox;
class DropBoxDescriptor;
class EventMessage;
class MKIniLine;
class MKMessage;
class MKModel;
class MKVector3;
class Shatterable;
class ShatterableDescriptor;
class SpawnerObject;

class DropBox : public Shatterable {  // base: vtable prefix
public:
    virtual ~DropBox(void);
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    virtual void Deinit(void);
    virtual void Resolve(void);
    virtual void Update(void);
    virtual void Message(MKMessage *);
    DropBox(void);
    void SetAnim(int);
    void SetDefaults(void);
    void Drop(void);
    void SpawnEnemies(void);
    void InitSpawnerObject(void);
    /* 0x1a3 */ u8 pad1A3[0x5];
    /* 0x1a8 */ f32 unk1A8;
    /* 0x1ac */ f32 unk1AC;
    /* 0x1b0 */ f32 unk1B0;
    /* 0x1b4 */ u8 pad1B4[0x4];
    /* 0x1b8 */ f32 unk1B8;
    /* 0x1bc */ f32 unk1BC;
    /* 0x1c0 */ u8 unk1C0;
    /* 0x1c1 */ u8 pad1C1[0x3];
    /* 0x1c4 */ MKModel* unk1C4;
    /* 0x1c8 */ s32 unk1C8;
    /* 0x1cc */ f32 unk1CC;
    /* 0x1d0 */ s32 unk1D0;
    /* 0x1d4 */ SpawnerObject* unk1D4;
    /* 0x1d8 */ EventMessage unk1D8;
    /* 0x1dc */ u8 pad1DC[0x20];
    /* 0x1fc */ u8 unk1FC;
    /* 0x1fd */ u8 unk1FD;
    /* 0x1fe */ u8 pad1FE[0x2];
    /* 0x200 */ MKVector3 unk200;
    /* 0x210 */ s32 unk210;
    /* 0x214 */ s32 unk214;
    /* 0x218 */ s32 unk218;
};

class DropBoxDescriptor : public ShatterableDescriptor {  // base: vtable prefix
public:
    virtual void Init(void);
    virtual s32 LoadLine(MKIniLine *);
    virtual void LoadDone(void);
    DropBoxDescriptor(void);
    /* 0x16c */ s32 unk16C;
    /* 0x170 */ s32 unk170;
    /* 0x174 */ s32 unk174;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unkC8'
inline DropBox::DropBox() {
    this->unkC8 = &__vt + 0x48;
    this->unk1C8 = 0;
    ((EventMessage *) &this->unk1C8)->Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline DropBox::~DropBox() {
    this->unkC8 = &__vt.unk48;
    if (&this->unk1C8 != NULL) {
        ((EventMessage *) &this->unk1C8)->Deinit();
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline DropBoxDescriptor::DropBoxDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_DROPBOX_H
