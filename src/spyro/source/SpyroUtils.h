#ifndef SPYRO_SOURCE_SPYROUTILS_H
#define SPYRO_SOURCE_SPYROUTILS_H

#include <dolphin/types.h>

class MKMessage;
class SpyroSoundPlayer;
class SpyroUtils_cpp;

class SpyroSoundPlayer {
public:
    class SpyroLoopSounds {
    public:
        ~SpyroLoopSounds(void);
        SpyroLoopSounds(void);
    };
    void UpdatePitch(int);
    void PlaySounds(int, bool);
    void DetermineSoundPos(int);
    s8 Determine3DSound(int);
    void DetermineFadeTimes(int);
    s32 DetermineGameSound(int, int);
    u8 SoundIsFadingOut(int);
    u8 SoundIsFadingIn(int);
    u8 SoundIsPlaying(int);
    void StopAll(void);
    void Stop(int);
    void FadeOut(int);
    void FadeIn(int, int);
    void Update(void);
    void Message(MKMessage *);
    void Deinit(void);
    void Init(void);
    /* 0x000 */ s8 unk0;
};

class SpyroUtils_cpp {
public:
    void __sinit(void);
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: undefined identifier 'unk0'
inline SpyroSoundPlayer::SpyroLoopSounds::~SpyroLoopSounds() {
    s32 temp_cr0_eq_4881;

    temp_cr0_eq_4881 = this == NULL;
    if (temp_cr0_eq_4881 == 0) {
        if ((temp_cr0_eq_4881 == 0) && (temp_cr0_eq_4881 == 0)) {
            KDSound_Stop((int *) &this->unk0);
        }
        if (arg1 > 0) {
            operator delete(this);
        }
    }
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
inline SpyroSoundPlayer::SpyroLoopSounds::SpyroLoopSounds() {
    this->unk0 = 0;
}
#endif

#endif  // SPYRO_SOURCE_SPYROUTILS_H
