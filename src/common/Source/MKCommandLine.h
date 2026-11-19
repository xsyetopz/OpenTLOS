#ifndef COMMON_SOURCE_MKCOMMANDLINE_H
#define COMMON_SOURCE_MKCOMMANDLINE_H

#include <dolphin/types.h>

class MKCommandLine;

class MKCommandLine {
public:
    void ParseArgument(char *);
    u8 * GetParameter(const char *, bool);
    void AddFromString(char *);
    void InitFromString(char *);
    /* 0x000 */ s32 unk0;
};

#endif  // COMMON_SOURCE_MKCOMMANDLINE_H
