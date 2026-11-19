extern "C" void *malloc(u32);
extern M2C_UNK gEmptyPtrListDL;
MKVector3 KDRand_Vector(const MKVector3 &, const MKVector3 &);

s32 SwarmProp::LoadDone() {
    f64 temp_f29;
    f64 temp_f30;
    MKVector3 sp28;
    SwarmEntity **head;
    SwarmEntity **walk;
    SwarmEntity **end;
    SwarmEntity **base;
    SwarmEntity **cur;
    SwarmEntity *entity;
    u32 walkValue;
    s32 n;
    s32 i;
    s32 count;
    s32 spawned;
    s32 ctr;

    KDProp::LoadDone();
    M2C_STRUCT_COPY(&this->unk90, &Matrix::identity, 0x40);
    this->unk90.Translate(&this->unk90, *((MKVector3 *) &MKProp::loadInfo.unk40));
    M2C_FIELD(this, Matrix **, 0x8) = &this->unk90;
    M2C_FIELD(this, f32 *, 0xD0) = -500.0f;
    M2C_FIELD(this, f32 *, 0xD4) = -500.0f;
    M2C_FIELD(this, f32 *, 0xD8) = -500.0f;
    M2C_FIELD(this, f32 *, 0xE0) = 500.0f;
    M2C_FIELD(this, f32 *, 0xE4) = 500.0f;
    M2C_FIELD(this, f32 *, 0xE8) = 500.0f;
    n = this->unkF0;
    if (n == 0) {
        this->unkF4 = (SwarmEntity **) ((u8 *) &gEmptyPtrListDL + 4);
    } else {
        if (MKHeap::Current() != NULL) {
            base = (SwarmEntity **) (((MKHeap *) (MKHeap::Current()))->Alloc(((n + 2) * 4) + (n << 6), NULL, 0));
        } else {
            base = (SwarmEntity **) malloc(((n + 2) * 4) + (n << 6));
        }
        this->unkF4 = base;
        cur = this->unkF4;
        this->unkF4 = (SwarmEntity **) ((u8 *) cur + (n << 6));
        *this->unkF4 = NULL;
        ctr = n;
        if (n > 0) {
            do {
                this->unkF4 += 1;
                *this->unkF4 = (SwarmEntity *) cur;
                cur = (SwarmEntity **) ((u8 *) cur + 0x40);
                ctr -= 1;
            } while (ctr != 0);
        }
        this->unkF4 += 1;
        *this->unkF4 = NULL;
    }
    temp_f29 = M2C_FIELD(&MKVector3::zero, f64 *, 0);
    spawned = 0;
    temp_f30 = M2C_FIELD(&MKVector3::zero, f64 *, 8);
loop_12:
    head = this->unkF4;
    walk = head;
    do {
        walkValue = M2C_FIELD(walk, u32 *, -4);
        walk -= 1;
    } while (walkValue != 0U);
    end = head;
    while (*end != NULL) {
        end += 1;
    }
    count = (s32) (head - walk) + (s32) (end - head) - 1;
    if (spawned < count) {
        this->unkF4 -= 1;
        entity = *this->unkF4;
        entity->unk0 = temp_f29;
        entity->unk8 = temp_f30;
        entity->unk10 = temp_f29;
        entity->unk18 = temp_f30;
        entity->unk20 = temp_f29;
        entity->unk28 = temp_f30;
        entity->unk30 = 0.0f;
        for (i = 0; i < 3; i++) {
            M2C_FIELD(entity, s32 *, 0x34 + (i * 4)) = 0;
        }
        sp28 = KDRand_Vector(this->unkD0, *((MKVector3 *) &this->unkE0));
        spawned += 1;
        *(MKVector3 *) &entity->unk0 = sp28;
        goto loop_12;
    }
}
