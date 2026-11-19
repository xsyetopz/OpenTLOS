void SpyroSoundPlayer::UpdatePitch(int arg0) {
    s32 offset;
    s32 sound;

    offset = arg0 * 0x58;
    sound = M2C_FIELD(this, s32 *, offset);
    if (sound > 0) {
        KDSound_SetPitch(sound, M2C_FIELD(this, f32 *, offset + 0x40));
        M2C_FIELD(this, s8 *, offset + 0x35) = 0;
    }
}
