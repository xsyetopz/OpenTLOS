#ifndef SPYRO_SOURCE_SPYROANIMTABLES_H
#define SPYRO_SOURCE_SPYROANIMTABLES_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class MKAnim;
class MKAnimScript;
class Spyro;
class SpyroAnimTables_cpp;
class SpyroBreatheAnimTable;
class SpyroIdleAnimEntry;
class SpyroIdleAnimTable;
class SpyroStartCycleAnimTable;

class SpyroAnimTables_cpp {
public:
    void __sinit(void);
};

class SpyroBreatheAnimTable {
public:
    void Update(Spyro *);
    void Start(Spyro *, float);
    /* 0x000 */ u32 unk0;
    /* 0x004 */ u32 unk4;
};

class SpyroIdleAnimEntry {
public:
    u8 IsValid(MaterialIndex, IdleAnimNumber, IdleAnimMoveVel);
    /* 0x000 */ s8* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ u8 pad8[0x4];
    /* 0x00c */ s32 unkC;
    /* 0x010 */ s32 unk10;
    /* 0x014 */ s32 unk14;
};

class SpyroIdleAnimTable {
public:
    void Update(Spyro *, bool, unsigned int, IdleAnimNumber, float);
    void Deinit(void);
    void Init(MKAnimScript *);
    /* 0x000 */ void* unk0;
};

class SpyroStartCycleAnimTable {
public:
    u8 IsAnimInTable(Spyro *, MKAnim *);
    void Update(Spyro *);
    void Start(Spyro *, float);
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u32 unk4;
};

void SpyroAnimTables_InitIndexTable(MKAnimScript *);
#endif  // SPYRO_SOURCE_SPYROANIMTABLES_H
