s32 EnemyDescriptor::LoadLine(MKIniLine *arg0) {
    s32 var_r31_2421;

    var_r31_2421 = 0;
    if ((CharacterDescriptor::LoadLine(arg0) != 0) || (KDSound_LoadLine(arg0, "sndHeroHit", (int *) &this->unk180) != 0) || (KDSound_LoadLine(arg0, "sndHurt", (int *) &this->unk190) != 0) || (KDSound_LoadLine(arg0, "sndHitByHero", (int *) &this->unk184) != 0) || (KDSound_LoadLine(arg0, "sndHitByExplosion", (int *) &this->unk188) != 0) || (KDSound_LoadLine(arg0, "sndHitByHeroBlocked", (int *) &this->unk18C) != 0) || (KDSound_LoadLine(arg0, "sndArmourHitMelee", (int *) &this->unk1B0) != 0) || (KDSound_LoadLine(arg0, "sndArmourShatter", (int *) &this->unk1B4) != 0) || (arg0->LoadString("meleeTrailsPropName", (const char **) &this->unk274, 0) != 0) || (DataMap_LoadLine(arg0, "iElementType", &ElementTypeDataMap, (unsigned int *) &this->unk1D0) != 0) || (arg0->LoadString("addfile", (const char **) &this->unk278, 0) != 0) || (arg0->LoadBool("bBreathFX", (bool *) &this->unk264, 0) != 0) || (arg0->LoadBool("bBodyEffects", (bool *) &this->unk265, 0) != 0) || (arg0->LoadInt("iInitialAttackPattern", (int *) &this->unk22C, 0) != 0)) {
        var_r31_2421 = 1;
    }
    return var_r31_2421;
}
