s32 EnemyAttack::LoadLine(MKIniLine *arg0, EnemyDescriptor *arg1) {
    const char *sp8;
    f32 var_f0_805;
    f32 var_f0_835;
    f32 var_f0_944;
    f32 var_f0_976;
    s32 temp_r0_866;
    s32 temp_r28_633;
    s32 temp_r28_659;
    s32 temp_r5_637;
    s32 var_r27_674;
    s32 var_r28_675;
    s32 var_r30_999;
    u16 temp_r0_685;
    u32 *var_r3_667;

    sp8 = NULL;
    if (arg0->IsField("AnimSequence") != 0) {
        temp_r28_633 = DataMap_GetValue(&dataMapAnimSequence, (const char *) arg0->GetString(0));
        temp_r5_637 = arg0->GetInt(1);
        if (temp_r28_633 != 0) {
            this->unk0 = (AnimSequence *) (arg1->GetAnimSequence(temp_r28_633, temp_r5_637, this->unk3C, NULL));
        }
        return 1;
    }
    if (arg0->IsField("RefPoints") != 0) {
        this->unk78 = (s32) M2C_FIELD(arg0, s16 *, 0);
        temp_r28_659 = this->unk78 * 4;
        if (MKHeap::Current() != NULL) {
            var_r3_667 = (unsigned long *) (((MKHeap *) (MKHeap::Current()))->Alloc(temp_r28_659, NULL, 0));
        } else {
            var_r3_667 = (u32 *) malloc(temp_r28_659);
        }
        this->unk7C = var_r3_667;
        var_r27_674 = 0;
        var_r28_675 = 0;
loop_10:
        if (var_r27_674 < (s32) this->unk78) {
            temp_r0_685 = Tools_GetMatchingRefPointIndex(arg1->unk2C, (const char *) arg0->GetString(var_r27_674));
            var_r27_674 += 1;
            M2C_FIELD(this->unk7C, s32 *, var_r28_675) = (s32) temp_r0_685;
            var_r28_675 += 4;
            goto loop_10;
        }
        return 1;
    }
    if (arg0->IsField("EnemySettings") != 0) {
        this->unk54.LoadLine(((MKIni *) M2C_FIELD(arg0, void **, 0xC))->GetSubLine(arg0));
        return 1;
    }
    if (arg0->LoadString("ProjectileNode", &sp8, 0) != 0) {
        this->unk84 = (s32) Tools_GetMatchingRefPointIndex(arg1->unk2C, sp8);
        if ((u32) this->unk84 == -1U) {
            this->unk84 = (s32) Tools_GetMatchingNodeIndex(arg1->unk2C, sp8);
        }
        return 1;
    }
    if (arg0->IsField("HeroHurtType") != 0) {
        this->unk48 = DataMap_GetValue(&heroHurtReactionTypeDataMap, (const char *) arg0->GetString(0));
        return 1;
    }
    if (arg0->IsField("HeroRumbleType") != 0) {
        this->unk4C = DataMap_GetValue(&heroRumbleTypeDataMap, (const char *) arg0->GetString(0));
        return 1;
    }
    if (arg0->IsField("EnemyHitType") != 0) {
        this->unk50 = DataMap_GetValue(&attackHitTypeDataMap, (const char *) arg0->GetString(0));
        return 1;
    }
    if (arg0->LoadFloat("fAngleMin", &this->unk1C, 0) != 0) {
        var_f0_805 = 0.017453292f * this->unk1C;
        if (var_f0_805 < 6.2830853f) {

        } else {
            var_f0_805 = 6.2830853f;
        }
        if (var_f0_805 > 0.0f) {

        } else {
            var_f0_805 = 0.0f;
        }
        this->unk1C = var_f0_805;
        return 1;
    }
    if (arg0->LoadFloat("fAngleMax", &this->unk20, 0) != 0) {
        var_f0_835 = 0.017453292f * this->unk20;
        if (var_f0_835 < 6.2830853f) {

        } else {
            var_f0_835 = 6.2830853f;
        }
        if (var_f0_835 > 0.0f) {

        } else {
            var_f0_835 = 0.0f;
        }
        this->unk20 = var_f0_835;
        return 1;
    }
    if (DataMap_LoadLine(arg0, "ProjectileType", &projectileTypeDataMap, (unsigned int *) &this->unk80) != 0) {
        if ((s32) this->unk80 == 0) {
            temp_r0_866 = arg1->unk1D0;
            switch (temp_r0_866) {                  /* irregular */
            case 4:
            case 0:
                this->unk80 = 1;
                break;
            case 1:
                this->unk80 = 2;
                break;
            case 2:
                this->unk80 = 3;
                break;
            case 3:
                this->unk80 = 4;
                break;
            default:
                this->unk80 = 1;
                break;
            }
        }
        return 1;
    }
    if (arg0->LoadFloat("fSelectRangeMin", &this->unk24, 0) != 0) {
        this->unk8C = 1;
        return 1;
    }
    if (arg0->LoadFloat("fSelectRangeMax", &this->unk28, 0) != 0) {
        this->unk8D = 1;
        return 1;
    }
    if (arg0->LoadFloat("fSelectAngleMin", &this->unk2C, 0) != 0) {
        this->unk8E = 1;
        var_f0_944 = 0.017453292f * this->unk2C;
        if (var_f0_944 < 6.2830853f) {

        } else {
            var_f0_944 = 6.2830853f;
        }
        if (var_f0_944 > 0.0f) {

        } else {
            var_f0_944 = 0.0f;
        }
        this->unk2C = var_f0_944;
        return 1;
    }
    if (arg0->LoadFloat("fSelectAngleMax", &this->unk30, 0) != 0) {
        this->unk8F = 1;
        var_f0_976 = 0.017453292f * this->unk30;
        if (var_f0_976 < 6.2830853f) {

        } else {
            var_f0_976 = 6.2830853f;
        }
        if (var_f0_976 > 0.0f) {

        } else {
            var_f0_976 = 0.0f;
        }
        this->unk30 = var_f0_976;
        return 1;
    }
    var_r30_999 = 0;
    if ((arg0->LoadFloat("fAttackDelay", &this->unk8, 0) != 0) || (arg0->LoadFloat("fRangeMin", &this->unk14, 0) != 0) || (arg0->LoadFloat("fRangeMax", &this->unk18, 0) != 0) || (arg0->LoadFloat("iDamage", &this->unk4, 0) != 0) || (arg0->LoadInt("iAnimSet", (int *) &this->unk3C, 0) != 0) || (arg0->LoadInt("iAttackChance", (int *) &this->unk40, 0) != 0) || (arg0->LoadInt("iRunASV", (int *) &this->unk44, 0) != 0) || (arg0->LoadFloat("fProjectileSpeed", &this->unk88, 0) != 0) || (arg0->LoadFloat("fKnockbackForce", &this->unk34, 0) != 0) || (arg0->LoadFloat("fDefensiveThreshold", &this->unkC, 0) != 0) || (arg0->LoadFloat("fDefensivePenalty", &this->unk10, 0) != 0) || (DataMap_LoadLineBitfield(arg0, "uProperties", &dataMapEAP, (unsigned int *) &this->unk38) != 0)) {
        var_r30_999 = 1;
    }
    return var_r30_999;
}
