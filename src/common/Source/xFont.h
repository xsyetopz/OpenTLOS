#ifndef COMMON_SOURCE_XFONT_H
#define COMMON_SOURCE_XFONT_H

#include <dolphin/types.h>

void XFONTputString(short *, short *, char *, unsigned long *);
void XFONTClearScreen(unsigned long);
void XFONTSetFgColor(unsigned long);
void XFONTPrintf(short, short, char *, ...);
void XFONTSetFrameBuffer(void *);
void XFONTInit(unsigned long, unsigned long);
#endif  // COMMON_SOURCE_XFONT_H
