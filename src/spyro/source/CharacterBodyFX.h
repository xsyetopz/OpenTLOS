#ifndef SPYRO_SOURCE_CHARACTERBODYFX_H
#define SPYRO_SOURCE_CHARACTERBODYFX_H

#include <dolphin/types.h>

class CBFXNode;
class CharacterBodyFX;
class CharacterBodyFXData;
class CharacterBodyFXManager;
class CharacterBodyFxInit;
class MKAnimScript;
class MKModel;

class CBFXNode {
public:
    /* 0x000 */ CharacterBodyFX** unk0;
};

class CharacterBodyFX {
public:
    virtual void Init(void);
    virtual void InitData(CharacterBodyFXData *, MKModel *, CBFXNode *);
    virtual void Update(void);
    virtual void Draw(void);
    virtual void Deinit(void);
    void SetDataActive(bool);
    void * GetRandomNode(CBFXNode *);
    void CalculateNodeData(int);
    /* 0x004 */ s32 unk4;
    /* 0x008 */ CharacterBodyFXData* unk8;
    /* 0x00c */ MKModel* unkC;
    /* 0x010 */ u8 unk10;
    /* 0x011 */ u8 unk11;
};

class CharacterBodyFXData {
public:
    void Deinit(void);
    void Init(CharacterBodyFxInit *, int, MKAnimScript *);
    /* 0x000 */ CharacterBodyFxInit* unk0;
    /* 0x004 */ s32 unk4;
};

class CharacterBodyFXManager {
public:
    void DestroyInstance(CharacterBodyFX *);
    CharacterBodyFX * CreateInstance(int);
    void Deinit(void);
    void Draw(void);
    void Update(void);
    void Init(void);
    /* 0x000 */ CharacterBodyFX*** unk0;
};

#endif  // SPYRO_SOURCE_CHARACTERBODYFX_H
