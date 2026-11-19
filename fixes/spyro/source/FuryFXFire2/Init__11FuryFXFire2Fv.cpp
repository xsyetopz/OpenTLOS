extern "C" void *malloc(u32);

void FuryFXFire2::Init() {
    u8 *pool;
    u8 *var_r5;
    s32 var_ctr;
    FuryFXFire2::Meteor **temp_r3;
    FuryFXFire2::Meteor **temp_r4;

    FuryFX::Init();
    SetDefaults();
    if (MKHeap::Current() != NULL) {
        pool = (u8 *) (((MKHeap *) (MKHeap::Current()))->Alloc(0x698, NULL, 0));
    } else {
        pool = (u8 *) malloc((u32) 0x698);
    }
    this->unk150 = (FuryFXFire2::Meteor **) pool;
    var_r5 = pool;
    this->unk150 = (FuryFXFire2::Meteor **) (var_r5 + 0x640);
    M2C_FIELD(var_r5, s32 *, 0x640) = 0;
    var_ctr = 0x14;
    do {
        temp_r3 = this->unk150 + 1;
        this->unk150 = temp_r3;
        *temp_r3 = (FuryFXFire2::Meteor *) var_r5;
        var_r5 += 0x50;
        var_ctr -= 1;
    } while (var_ctr != 0);
    temp_r4 = this->unk150 + 1;
    this->unk150 = temp_r4;
    *temp_r4 = NULL;
    this->unk148 = MKModel_Create("P0002_LavaCannonBall", NULL, 2, NULL);
    ((MKSceneManager *) gMK)->CreatePropDeferred("Explosion4", (MKProp **) &this->unk154);
    ((MKSceneManager *) gMK)->CreatePropDeferred("ClusterBomb", (MKProp **) &this->unk160);
    this->unk164.Init(0xA);
    this->unk158 = -1;
}
