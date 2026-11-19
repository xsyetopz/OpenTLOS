s32 LiquidFX::Emit(const int &arg0, const MKVector3 &arg1, const MKVector3 &arg2, const MKVector3 &arg3, const float &arg4, float arg5, bool arg6, BreathHitMessage *arg7, int arg8, int arg9) {
    u8 *slot;
    MKCollisionResult hit;
    MKVector3 groundPos;
    MKVector3 vel;
    f32 offX;
    f32 offY;
    f32 offZ;
    f32 rndA;
    f32 rndB;
    f32 rndC;
    f32 rndD;
    f32 rndE;

    slot = (u8 *) this + (this->unk3F5C * 0xA0);
    if (M2C_FIELD(slot, u8 *, 0x158) != 0) {
        return 0;
    }
    M2C_FIELD(slot, u8 *, 0x158) = 1;
    hit.Init();
    if (arg6 != 0) {
        M2C_FIELD(slot, f32 *, 0x154) = arg5;
    } else {
        offX = 0.0f;
        offY = 200.0f;
        offZ = 0.0f;
        groundPos.unk0 = arg1.unk0 + offX;
        groundPos.unk4 = arg1.unk4 + offY;
        groundPos.unk8 = arg1.unk8 + offZ;
        if (MKCollision_GetGroundPoint(groundPos, 3000.0f, &hit, 0, 2, NULL, (MKCollisionMode) 6) != 0) {
            M2C_FIELD(slot, f32 *, 0x154) = hit.unk4;
        }
    }
    M2C_FIELD(slot, f32 *, 0x14C) = 0.0f;
    M2C_FIELD(slot, f32 *, 0x150) = arg4;
    M2C_FIELD(slot, MKVector3 *, 0xC8) = arg1;
    M2C_FIELD(slot, MKVector3 *, 0xE8) = arg3;
    M2C_FIELD(slot, MKVector3 *, 0xF8) = arg3;
    M2C_FIELD(slot, MKVector3 *, 0xD8) = arg2;
    rndA = MKRand_Float((int *) &gViewSeed, 0.0f, 20.0f);
    rndB = MKRand_Float((int *) &gViewSeed, 0.0f, 20.0f);
    rndC = MKRand_Float((int *) &gViewSeed, 0.0f, 20.0f);
    M2C_FIELD(slot, f32 *, 0x108) = rndC;
    M2C_FIELD(slot, f32 *, 0x10C) = rndB;
    M2C_FIELD(slot, f32 *, 0x110) = rndA;
    rndD = MKRand_Float((int *) &gViewSeed, 20.0f, 60.0f);
    rndE = MKRand_Float((int *) &gViewSeed, 20.0f, 60.0f);
    vel = MKVector(MKRand_Float((int *) &gViewSeed, 20.0f, 60.0f), rndE, rndD);
    M2C_FIELD(slot, f32 *, 0x118) = vel.unk0 * 0.05f;
    M2C_FIELD(slot, f32 *, 0x11C) = vel.unk4 * 0.05f;
    M2C_FIELD(slot, f32 *, 0x120) = vel.unk8 * 0.05f;
    M2C_FIELD(slot, s8 *, 0x159) = 0;
    M2C_FIELD(slot, f32 *, 0x148) = 0.0f;
    M2C_FIELD(slot, f32 *, 0x160) = 0.0f;
    M2C_FIELD(slot, f32 *, 0x15C) = (M2C_FIELD(slot, f32 *, 0x100) + (M2C_FIELD(slot, f32 *, 0xF8) + M2C_FIELD(slot, f32 *, 0xFC))) / 3.0f;
    M2C_FIELD(slot, f32 *, 0x138) = 0.0f;
    M2C_FIELD(slot, f32 *, 0x13C) = 0.0f;
    M2C_FIELD(slot, f32 *, 0x140) = 0.0f;
    M2C_FIELD(slot, s32 *, 0x164) = arg9;
    if (arg8 != 0) {
        KDSound_Play3d(arg8, (const MKVector3 *) (slot + 0xC8), 0U, -1, 0.0f, false);
    }
    this->unk3F5C += 1;
    this->unk3F60 += 1;
    if (this->unk3F5C >= 0x64) {
        this->unk3F5C = 0;
    }
    this->unk3F78 = arg0;
    this->unk3F80 = arg7;
    return 1;
}
