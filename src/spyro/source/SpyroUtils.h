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
};

class SpyroUtils_cpp {
public:
    void __sinit(void);
};

#endif  // SPYRO_SOURCE_SPYROUTILS_H
