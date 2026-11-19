u8 SpyroEffects::TriggerFury(SpyroEffectsUpdateData *arg0) {
    MKVector3 zero;
    MKVector4 glow;
    f32 range;
    void *flags;
    u8 result;

    result = 0;
    zero.unk0 = 0.0f;
    zero.unk4 = 0.0f;
    zero.unk8 = 0.0f;
    *(s32 *) (&GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x7C)) = 3;
    if ((u8) arg0->unk3E != 0) {
        result = ((FuryFXConvexity *) (M2C_FIELD(this->unk4, FuryFXConvexity **, 0xBC)))->Trigger(arg0->unk10);
        if (result != 0) {
            ((KDSound_AfterRumble *) (((u8 *) this->unk4) + 0x40))->Trigger(arg0->unk10, GS_Rumble1, 7.5f, 2000.0f);
        }
        return result;
    }
    switch (arg0->unk24) {
    case 0:
        result = ((FlameBreathFX *) (M2C_FIELD(this->unk4, FlameBreathFX **, 0x14)))->Trigger(this->unk8, arg0->unk10, zero, *((MKVector3 *) arg0), 1.0f, lit_1018, 0U, 0U);
        if (result != 0) {
            KDSound_Play3d(GS_SpyroFuryStartSound, &arg0->unk10, 0U, -1, 0.0f, 0U);
            ((KDSound_AfterRumble *) (((u8 *) this->unk4) + 0x40))->Trigger(arg0->unk10, GS_Rumble1, 5.0f, 2000.0f);
        }
        break;
    case 1:
        result = ((ZapBreathFX *) (M2C_FIELD(this->unk4, ZapBreathFX **, 0x18)))->Trigger(this->unk8, arg0->unk10, zero, 1.0f, lit_1024, 0U);
        if (result != 0) {
            range = 7.0f;
            flags = &GameData::gameData[0x70] + ((M2C_FIELD(GameData::gameData, s32 *, 0x158) << 5) + 0x64);
            if ((s32) M2C_FIELD(flags, s32 *, 0) == 3 && (s32) M2C_FIELD(flags, s32 *, 4) == 3) {
                range = 12.0f;
            }
            ((CharacterZapFX *) (M2C_FIELD(this->unk4, CharacterZapFX **, 0xB4)))->Enable(1U, range, 1U);
            ((KDSound_AfterRumble *) (((u8 *) this->unk4) + 0x40))->Trigger(arg0->unk10, GS_Rumble1, 8.0f, 2000.0f);
        }
        break;
    case 2:
        result = ((IceBreathFX *) (M2C_FIELD(this->unk4, IceBreathFX **, 0x1C)))->Trigger(this->unk8, arg0->unk10, zero, *((MKVector3 *) arg0), 1.0f, lit_1032);
        if (result != 0) {
            ((KDSound_AfterRumble *) (((u8 *) this->unk4) + 0x40))->Trigger(arg0->unk10, GS_Rumble1, 7.5f, 2000.0f);
            glow.unk0 = 0.5f;
            glow.unk4 = 0.5f;
            glow.unk8 = 1.0f;
            glow.unkC = 1.0f;
            ((CharacterGlowFX *) (M2C_FIELD(this->unk4, CharacterGlowFX **, 0x28)))->Enable(1U, glow, 10.0f);
        }
        break;
    case 3:
        result = ((EarthBreathFX *) (M2C_FIELD(this->unk4, EarthBreathFX **, 0x20)))->Trigger(this->unk8, arg0->unk10, zero, *((MKVector3 *) arg0), 3, 0U);
        if (result != 0) {
            ((KDSound_AfterRumble *) (((u8 *) this->unk4) + 0x40))->Trigger(arg0->unk10, GS_Rumble1, 7.5f, 2000.0f);
            glow.unk0 = 0.25f;
            glow.unk4 = 1.0f;
            glow.unk8 = 0.25f;
            glow.unkC = 1.0f;
            ((CharacterGlowFX *) (M2C_FIELD(this->unk4, CharacterGlowFX **, 0x28)))->Enable(1U, glow, 10.0f);
        }
        break;
    }
    return result;
}
