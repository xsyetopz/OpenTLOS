#ifndef COMMON_SOURCE_MKATTACHMENT_H
#define COMMON_SOURCE_MKATTACHMENT_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

class MKAttachment;
class Matrix;

class MKAttachment {
public:
    /* 0x000 */ s32 unk0;
    /* 0x004 */ u8 unk4;
};

void MKAttachment_CalculateMatrix(const MKAttachment *, Matrix *, const Matrix *);
void MKAttachment_Init(MKAttachment *, const void *, MKAttachmentType, int);
#endif  // COMMON_SOURCE_MKATTACHMENT_H
