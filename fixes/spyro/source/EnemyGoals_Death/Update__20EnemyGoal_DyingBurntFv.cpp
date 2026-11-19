u8 EnemyGoal_DyingBurnt::Update() {
    MKCollisionResult sp30;
    MKVector3 ray;
    void *sp8;
    u8 spC;
    u8 var_r3_2210;
    u8 var_r30_2236;
    u8 var_r30_2273;

    ActivateIfInactive();
    var_r3_2210 = 0;
    if ((((Enemy *) this->unkC)->unk750.unk78 == 0) && ((u8) ((Enemy *) this->unkC)->unk750.unkA4 != 0)) {
        var_r3_2210 = 1;
    }
    if (var_r3_2210 != 0) {
        if (((Enemy *) this->unkC)->unkA08 != NULL) {
            ((Enemy *) this->unkC)->unkA08->Enable(0U, 1.0f);
        }
        this->unk8 = 2;
    }
    if (((Enemy *) this->unkC)->unkA50 != NULL) {
        var_r30_2236 = 0;
        if (this->unkC->HasAnimFinished() != 0) {
            if ((((Enemy *) this->unkC)->unkA50 != NULL) &&
                (M2C_FIELD(((Enemy *) this->unkC)->unkA50, u32 *, 0) == M2C_FIELD(this->unkC->unk630, u32 *, 0x20))) {
                var_r30_2236 = 1;
            }
        }
        if (var_r30_2236 != 0) {
            if (M2C_FIELD(((Enemy *) this->unkC)->unkA50, u32 *, 0x20) != 0U) {
                ((Enemy *) this->unkC)->SetAnim(((Enemy *) this->unkC)->unkA50,
                                                (AnimTransition *) ((s8 *) ((Enemy *) this->unkC)->unkA50 + 0x20), 0.15f, 0U);
            } else if (M2C_FIELD(((Enemy *) this->unkC)->unkA50, u32 *, 0x40) != 0U) {
                ((Enemy *) this->unkC)->SetAnim(((Enemy *) this->unkC)->unkA50,
                                                (AnimTransition *) ((s8 *) ((Enemy *) this->unkC)->unkA50 + 0x40), 0.15f, 0U);
            }
        } else {
            var_r30_2273 = 0;
            if (this->unkC->HasAnimFinished() != 0) {
                if ((((Enemy *) this->unkC)->unkA50 != NULL) &&
                    (M2C_FIELD(((Enemy *) this->unkC)->unkA50, u32 *, 0x40) == M2C_FIELD(this->unkC->unk630, u32 *, 0x20))) {
                    var_r30_2273 = 1;
                }
            }
            if ((var_r30_2273 == 0) && (this->unkC->HasAnimFinished() != 0)) {
                if (M2C_FIELD(((Enemy *) this->unkC)->unkA50, u32 *, 0x40) != 0U) {
                    ((Enemy *) this->unkC)->SetAnim(((Enemy *) this->unkC)->unkA50,
                                                    (AnimTransition *) ((s8 *) ((Enemy *) this->unkC)->unkA50 + 0x40), 0.15f, 0U);
                }
            }
        }
        sp8 = this->unkC->unk634;
        if (sp8 != NULL) {
            spC = M2C_FIELD(sp8, u8 *, 4);
            M2C_FIELD(sp8, u8 *, 4) = 0U;
        }
        ray.unk0 = this->unkC->unk588.unk0 + this->unkC->unk90;
        ray.unk4 = this->unkC->unk588.unk4 + this->unkC->unk94;
        ray.unk8 = this->unkC->unk588.unk8 + this->unkC->unk98;
        if (MKCollision_RayCollide(this->unkC->unk588, ray, &sp30, (MKCollisionMode) 7,
                                   M2C_FIELD(M2C_FIELD(this->unkC, void **, 0x570), s32 *, 0x18)) != 0) {
            M2C_FIELD(this->unkC, f64 *, 0x588) = M2C_FIELD(&sp30, f64 *, 0);
            M2C_FIELD(this->unkC, f64 *, 0x590) = M2C_FIELD(&sp30, f64 *, 8);
        }
        if (sp8 != NULL) {
            M2C_FIELD(sp8, u8 *, 4) = spC;
        }
    }
    return this->unk8;
}
