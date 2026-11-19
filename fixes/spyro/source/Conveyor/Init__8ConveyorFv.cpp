void Conveyor::Init() {
    s32 var_r29_745;
    s32 var_r31_747;

    GameProp::Init();
    ((KDUniformSpline *) &this->unk118)->Init(0xA, 0);
    ((KDUniformSpline *) &this->unk118.unk14)->Init(0xA, 0);
    var_r29_745 = 0;
    var_r31_747 = 0;
    do {
        var_r29_745 += 1;
        *(KDProp **) ((u8 *) this + (var_r31_747 + 0x140)) = checked_cast<KDProp *, MKProp>(gMK->CreateProp("ConveyorBucket"));
        var_r31_747 += 4;
    } while (var_r29_745 < 5);
    this->unk118.unk3C = 0.0f;
}
