#ifndef SPYRO_SOURCE_NAMES_H
#define SPYRO_SOURCE_NAMES_H

#include <dolphin/types.h>

class Name;
class Names;
class Names_cpp;

class Name {
public:
    u8 * GetName(void);
    void Create(int);
    /* 0x000 */ u8* unk0;
    /* 0x004 */ u8* unk4;
};

class Names {
public:
    u8 * GetRandom(void);
    void Deinit(void);
    void Init(const char *);
    Names(void);
    /* 0x000 */ u8* unk0;
    /* 0x004 */ s32 unk4;
};

class Names_cpp {
public:
    void __sinit(void);
};

void Names_DeinitModule(void);
void Names_InitModule(void);
#endif  // SPYRO_SOURCE_NAMES_H
