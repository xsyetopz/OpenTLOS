void EnemySpawnPool_Action(SpawnAction, int, MKProp **, SpawnerObject *);

void EnemyGenerator::Init(EnemyGeneratorDescriptor *arg0, MKProp *arg1) {
    EnemyGeneratorDescriptor *temp_r3_1956;
    s32 temp_r0_1958;
    s32 temp_r0_1964;
    s32 temp_r0_1989;
    s32 temp_r0_2015;
    s32 temp_r30_1967;
    s32 temp_r30_1992;
    s32 temp_r30_2018;
    s32 var_r4_1957;
    void *var_r3_1975;
    void *var_r3_2000;
    void *var_r3_2026;

    SpawnerObject::Init(EnemySpawnPool_Action, 1);
    this->unk50 = arg0;
    this->unk54 = NULL;
    this->unk58 = NULL;
    this->unk5C = NULL;
    this->unk60 = arg1;
    this->unk68.Init();
    this->unk6C.Init();
    this->unk7C = 0;
    this->unk74 = 0;
    this->unk78 = this->unk50->unkC;
    this->unk85 = this->unk50->unk19;
    this->unk80 = 0;
    temp_r3_1956 = this->unk50;
    var_r4_1957 = temp_r3_1956->unk0;
    temp_r0_1958 = temp_r3_1956->unk8;
    if (temp_r0_1958 > var_r4_1957) {
        var_r4_1957 = temp_r0_1958;
    }
    this->unk70 = var_r4_1957;
    temp_r0_1964 = this->unk70;
    if (temp_r0_1964 > 0) {
        temp_r30_1967 = temp_r0_1964 * 0x30;
        if (MKHeap::Current() != NULL) {
            var_r3_1975 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1967, NULL, 0);
        } else {
            var_r3_1975 = malloc(temp_r30_1967);
        }
        this->unk54 = var_r3_1975;
        memset(this->unk54, 0, this->unk70 * 0x30);
    }
    temp_r0_1989 = this->unk50->unk4;
    if (temp_r0_1989 > 0) {
        temp_r30_1992 = temp_r0_1989 * 4;
        if (MKHeap::Current() != NULL) {
            var_r3_2000 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_1992, NULL, 0);
        } else {
            var_r3_2000 = malloc(temp_r30_1992);
        }
        this->unk58 = var_r3_2000;
        memset(this->unk58, 0, this->unk50->unk4 * 4);
    }
    temp_r0_2015 = this->unk50->unk0;
    if (temp_r0_2015 > 0) {
        temp_r30_2018 = temp_r0_2015 * 4;
        if (MKHeap::Current() != NULL) {
            var_r3_2026 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r30_2018, NULL, 0);
        } else {
            var_r3_2026 = malloc(temp_r30_2018);
        }
        this->unk5C = var_r3_2026;
        memset(this->unk5C, 0, this->unk50->unk0 * 4);
    }
}
