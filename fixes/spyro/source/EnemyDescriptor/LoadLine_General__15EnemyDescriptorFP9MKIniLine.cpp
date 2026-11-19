extern DataMap dataMapRaces;
s32 EnemyDescriptor::LoadLine_General(MKIniLine *arg0) {
    u8 sp8;
    MKHeap *var_r3_1295;
    s32 temp_r28_1287;
    s32 var_r27_1307;
    s32 var_r31_1308;
    s32 var_r31_1333;
    u16 temp_r0_1320;

    sp8 = 0;
    if ((arg0->LoadBool("bFriend", (bool *) &sp8, 0) != 0) && (sp8 != 0)) {
        this->unkC &= 0xFFFFFFF7;
        this->unkC |= 4;
    }
    if (arg0->IsField("LeafEffectNodes") != 0) {
        temp_r28_1287 = arg0->unk0 + 1;
        if (MKHeap::Current() != NULL) {
            var_r3_1295 = (MKHeap *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r28_1287 * 4, NULL, 0));
        } else {
            var_r3_1295 = (MKHeap *) (malloc(temp_r28_1287 * 4));
        }
        this->unk27C = var_r3_1295;
        var_r27_1307 = 0;
        var_r31_1308 = 0;
        M2C_FIELD(((u8 *) this->unk27C + (temp_r28_1287 * 4)), s32 *, -4) = 0xFFFF;
        while (var_r27_1307 < (s32) (temp_r28_1287 - 1)) {
            temp_r0_1320 = Tools_GetMatchingNodeIndex(this->unk2C, (const char *) arg0->GetString(var_r27_1307));
            var_r27_1307 += 1;
            *(s32 *) ((u8 *) this->unk27C + var_r31_1308) = (s32) temp_r0_1320;
            var_r31_1308 += 4;
        }
    }
    var_r31_1333 = 0;
    if ((arg0->LoadFloat("iMaxHealth", &this->unkE8, 0) != 0) || (arg0->LoadFloat("iMaxShieldHealth", &this->unkEC, 0) != 0) || (arg0->LoadFloat("iMaxArmour", &this->unkF0, 0) != 0) || (arg0->LoadInt("uArmourType", (int *) &this->unk104, 0) != 0) || (arg0->LoadInt("iFuryDamage", (int *) &this->unkF8, 0) != 0) || (arg0->LoadBool("bCanSquish", (bool *) &this->unkFC, 0) != 0) || (arg0->LoadInt("iBreathDamage", (int *) &this->unk100, 0) != 0) || (arg0->LoadInt("iGemsHealth", (int *) &this->unk108, 0) != 0) || (arg0->LoadInt("iGemsSpirit", (int *) &this->unk10C, 0) != 0) || (arg0->LoadInt("iGemsMagic", (int *) &this->unk110, 0) != 0) || (arg0->LoadInt("iGemsFury", (int *) &this->unk114, 0) != 0) || (arg0->LoadInt("iTier", (int *) &this->unk118, 0) != 0) || (arg0->LoadInt("iHealthBarStages", (int *) &this->unk11C, 0) != 0) || (DataMap_LoadLine(arg0, "race", &dataMapRaces, (unsigned int *) &this->unk1CC) != 0) || (arg0->LoadBool("bImmortal", (bool *) &this->unk120, 0) != 0) || (arg0->LoadBool("bDieInLava", (bool *) &this->unk121, 0) != 0) || (arg0->LoadBool("bDieInWater", (bool *) &this->unk122, 0) != 0) || (arg0->LoadFloat("fMaxFreezeCount", &this->unk124, 0) != 0) || (arg0->LoadFloat("fFreezeDuration", &this->unk128, 0) != 0) || (arg0->LoadFloat("fAlertRange", &this->unk12C, 0) != 0) || (arg0->LoadFloat("fCriticalAlertRange", &this->unk130, 0) != 0) || (arg0->LoadFloat("fRemainAlertRange", &this->unk134, 0) != 0) || (arg0->LoadFloat("fMeleeDistanceMode", &this->unk138, 0) != 0) || (arg0->LoadFloat("fRangedDistanceMode", &this->unk13C, 0) != 0) || (arg0->LoadFloat("fVisibleAngle", &this->unk14C, 0) != 0) || (arg0->LoadFloat("fFocalPointDistance", &this->unk148, 0) != 0) || (arg0->LoadFloat("fDodgeChance", &this->unk150, 0) != 0) || (arg0->LoadFloat("fEvadeDistance", &this->unk140, 0) != 0) || (arg0->LoadFloat("fEvadeRandomChance", &this->unk144, 0) != 0) || (arg0->LoadFloat("fFlySpeed", &this->unk164, 0) != 0) || (arg0->LoadFloat("fIdleRotSpeed", &this->unk154, 0) != 0) || (arg0->LoadFloat("fWalkRotSpeed", &this->unk158, 0) != 0) || (arg0->LoadFloat("fRunRotSpeed", &this->unk15C, 0) != 0) || (arg0->LoadFloat("fAlertRotSpeed", &this->unk160, 0) != 0) || (arg0->LoadFloat("fMass", &this->unk168, 0) != 0) || (arg0->LoadFloat("fDefensiveMax", &this->unk170, 0) != 0) || (arg0->LoadFloat("fDefensiveHitWeight", &this->unk174, 0) != 0) || (arg0->LoadFloat("fDefensivenessDecayRate", &this->unk178, 0) != 0) || (arg0->LoadBool("bRandomPursuit", (bool *) &this->unk17C, 0) != 0) || (arg0->LoadBool("bSeekToAttackTarget", (bool *) &this->unk17D, 0) != 0) || (arg0->LoadBool("bFinishMovementAnim", (bool *) &this->unk17E, 0) != 0) || (arg0->LoadBool("bUseEnemySettings", (bool *) &this->unk1D6, 0) != 0) || (arg0->LoadBool("bOldArmourSystem", (bool *) &this->unk1D7, 0) != 0) || (KDSound_LoadLine(arg0, "soundLoop01", (int *) &this->unk1A4) != 0) || (KDSound_LoadLine(arg0, "soundLoop02", (int *) &this->unk1A8) != 0) || (KDSound_LoadLine(arg0, "soundLoop03", (int *) &this->unk1AC) != 0) || (KDSound_LoadLine(arg0, "sndAirFlinch", (int *) &this->unk1C0) != 0) || (KDSound_LoadLine(arg0, "sndAirSpin", (int *) &this->unk1C4) != 0) || (KDSound_LoadLine(arg0, "sndBurnFlee", (int *) &this->unk1C8) != 0) || (KDSound_LoadLine(arg0, "sndArmourHitBreathFire", (int *) &this->unk194) != 0) || (KDSound_LoadLine(arg0, "sndArmourHitBreathEarth", (int *) &this->unk198) != 0) || (KDSound_LoadLine(arg0, "sndArmourHitBreathIce", (int *) &this->unk19C) != 0) || (KDSound_LoadLine(arg0, "sndArmourHitBreathElectricity", (int *) &this->unk1A0) != 0) || (KDSound_LoadLine(arg0, "sndSpit", (int *) &this->unk1B8) != 0) || (KDSound_LoadLine(arg0, "sndSpitSplat", (int *) &this->unk1BC) != 0)) {
        var_r31_1333 = 1;
    }
    return var_r31_1333;
}
