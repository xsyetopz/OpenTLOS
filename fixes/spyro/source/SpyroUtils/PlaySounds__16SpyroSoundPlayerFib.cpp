void SpyroSoundPlayer::PlaySounds(int arg0, bool arg1) {
    s32 offset;
    s32 soundId;
    s32 param;
    u8 mode;
    u8 quiet;
    KDSoundFader *fader;

    offset = arg0 * 0x58;
    soundId = M2C_FIELD(this, s32 *, offset + 0x2C);
    param = M2C_FIELD(this, s32 *, offset + 0x30);
    mode = M2C_FIELD(this, u8 *, offset + 0x34);
    fader = (KDSoundFader *) ((s8 *) this + offset);
    if (mode == 1) {
        DetermineSoundPos(arg0);
        quiet = 0;
        if ((arg1 != 0) && (EventCamera_GetCurrent() == NULL)) {
            quiet = 1;
        }
        fader->Update(soundId, true, quiet, NULL, (const MKVector3 *) ((s8 *) fader + 0x48), 0U, param, true);
        return;
    }
    quiet = 0;
    if ((arg1 != 0) && (EventCamera_GetCurrent() == NULL)) {
        quiet = 1;
    }
    fader->Update(soundId, false, quiet, NULL, NULL, 0U, param, true);
    if (M2C_FIELD(this, f32 *, offset + 8) <= 0.0f) {
        M2C_FIELD(this, s32 *, offset + 0x28) = 2;
    }
}
