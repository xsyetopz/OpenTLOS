#ifndef SPYRO_SOURCE_DROPBOX_H
#define SPYRO_SOURCE_DROPBOX_H

#include <dolphin/types.h>
#include "spyro/source/Shatterable.h"

class DropBox;
class DropBoxDescriptor;
class MKIniLine;
class MKMessage;
class Shatterable;
class ShatterableDescriptor;

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
    this->unk1C8.Init();
    return this;
}
#endif

#if 0 // DRAFT: undefined identifier 'unkC8'
inline DropBox::~DropBox() {
    this->unkC8 = &__vt.unk48;
    if (&this->unk1C8 != NULL) {
        this->unk1C8.Deinit();
    }
}
#endif

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline DropBoxDescriptor::DropBoxDescriptor() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_DROPBOX_H
