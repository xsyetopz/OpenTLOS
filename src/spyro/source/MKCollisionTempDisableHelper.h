#ifndef SPYRO_SOURCE_MKCOLLISIONTEMPDISABLEHELPER_H
#define SPYRO_SOURCE_MKCOLLISIONTEMPDISABLEHELPER_H

#include <dolphin/types.h>

class MKCollisionTempDisableHelper;

class MKCollisionTempDisableHelper {
public:
    ~MKCollisionTempDisableHelper(void);
    void __defctor(void);
    /* 0x000 */ void* unk0;
    /* 0x004 */ u8 unk4;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

inline MKCollisionTempDisableHelper::~MKCollisionTempDisableHelper() {
    void *temp_r3_6455;

    if (this != NULL) {
        temp_r3_6455 = this->unk0;
        if (temp_r3_6455 != NULL) {
            M2C_FIELD(temp_r3_6455, u8 *, 4) = (u8) this->unk4;
        }
    }
}

inline void MKCollisionTempDisableHelper::__defctor() {
    void *temp_r4_3386;

    this->unk0 = NULL;
    temp_r4_3386 = this->unk0;
    if (temp_r4_3386 != NULL) {
        this->unk4 = M2C_FIELD(temp_r4_3386, u8 *, 4);
        M2C_FIELD(this->unk0, u8 *, 4) = 0U;
    }
}

#endif  // SPYRO_SOURCE_MKCOLLISIONTEMPDISABLEHELPER_H
