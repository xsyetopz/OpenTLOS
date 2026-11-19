#ifndef SPYRO_SOURCE_CUSTOMMATERIALUPDATER_H
#define SPYRO_SOURCE_CUSTOMMATERIALUPDATER_H

#include <dolphin/types.h>

class CustomMaterialUpdateManager;
class CustomMaterialUpdater;
class MKMaterial;

class CustomMaterialUpdateManager {
public:
    void UpdateCameraRelativeScroll(CustomMaterialUpdater *);
    void Destroy(CustomMaterialUpdater *);
    CustomMaterialUpdater * Create(MKMaterial *, int);
    void Deinit(void);
    void Update(void);
    void Init(void);
    /* 0x000 */ CustomMaterialUpdater** unk0;
};

class CustomMaterialUpdater {
public:
    /* 0x000 */ MKMaterial* unk0;
    /* 0x004 */ s32 unk4;
    /* 0x008 */ CustomMaterialUpdater** unk8;
};

#endif  // SPYRO_SOURCE_CUSTOMMATERIALUPDATER_H
