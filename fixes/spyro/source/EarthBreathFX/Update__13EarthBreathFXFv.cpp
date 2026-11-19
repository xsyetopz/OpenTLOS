void *EarthBreathFX::Update() {
    MKVector3 sp58;
    MKVector3 sp68;
    MKVector3 vStart;
    MKVector3 vAim;
    MKVector3 vZero;
    ManagedLight *lt;
    u8 *dst;
    f32 sumx;
    f32 sumy;
    f32 sumz;
    f32 t;

    BaseBreathFX::Update();
    this->unkBC -= gUpdateTimeDelta;
    this->unk12C -= gUpdateTimeDelta;
    this->unk194 -= gUpdateTimeDelta;
    this->unk19C -= gUpdateTimeDelta;
    if (this->unkA8 > 0.0f) {
        if (this->unkAC >= 0.25f) {
            this->unkA8 = 0.0f;
        } else {
            this->unkA8 = this->unkA8 - gUpdateTimeDelta;
        }
        this->unkAC += gUpdateTimeDelta;
    }
    lt = this->unkB8;
    if (lt != NULL) {
        if (this->unk12C > 0.0f) {
            sp58 = ((MKVector3 *) &this->unk130)->operator*(5000.0f);
            sp68 = sp58.operator*(gUpdateTimeDelta);
            sumx = M2C_FIELD(lt, f32 *, 0x10) + sp68.unk0;
            sumy = M2C_FIELD(lt, f32 *, 0x14) + sp68.unk4;
            sumz = M2C_FIELD(lt, f32 *, 0x18) + sp68.unk8;
            M2C_FIELD(lt, f32 *, 0x10) = sumx;
            M2C_FIELD(lt, f32 *, 0x14) = sumy;
            M2C_FIELD(lt, f32 *, 0x18) = sumz;
            dst = M2C_FIELD(lt, u8 **, 0x3C);
            if (dst != NULL) {
                M2C_FIELD(dst, f32 *, 0x10) = sumx;
                M2C_FIELD(dst, f32 *, 0x14) = sumy;
                M2C_FIELD(dst, f32 *, 0x18) = sumz;
            }
            t = this->unk12C;
            if (t < 0.25f) {
            } else {
                t = 0.25f;
            }
            if (t > 0.0f) {
            } else {
                t = 0.0f;
            }
            t = t / 0.25f;
            M2C_FIELD(lt, f32 *, 0x20) = 0.0f;
            M2C_FIELD(lt, f32 *, 0x24) = t;
            M2C_FIELD(lt, f32 *, 0x28) = 0.0f;
            M2C_FIELD(lt, f32 *, 0x2C) = 1.0f;
            dst = M2C_FIELD(lt, u8 **, 0x3C);
            if (dst != NULL) {
                M2C_FIELD(dst, f32 *, 0x0) = 0.0f;
                M2C_FIELD(dst, f32 *, 0x4) = t;
                M2C_FIELD(dst, f32 *, 0x8) = 0.0f;
                M2C_FIELD(dst, f32 *, 0xC) = 1.0f;
            }
        } else {
            ((LightManager *) (M2C_FIELD(&gb, LightManager **, 0x80)))->EnableLight(lt, false);
        }
    }
    if (((u8) this->unk198 != 0) && (this->unk19C <= 0.0f)) {
        vStart.unk0 = M2C_FIELD(this, f32 *, 0x180);
        vStart.unk4 = M2C_FIELD(this, f32 *, 0x184);
        vStart.unk8 = M2C_FIELD(this, f32 *, 0x188);
        vStart.unkC = M2C_FIELD(this, f32 *, 0x18C);
        vAim.unk0 = M2C_FIELD(this, f32 *, 0x160);
        vAim.unk4 = M2C_FIELD(this, f32 *, 0x164);
        vAim.unk8 = M2C_FIELD(this, f32 *, 0x168);
        vAim.unkC = M2C_FIELD(this, f32 *, 0x16C);
        vZero.unk0 = 0.0f;
        vZero.unk4 = 0.0f;
        vZero.unk8 = 0.0f;
        vZero.unkC = 0.0f;
        ShootShotgun(vStart, vAim, vZero);
        this->unk198 = 0;
    }
    UpdateSeedBullets();
    this->unkB0 = 0;
}
