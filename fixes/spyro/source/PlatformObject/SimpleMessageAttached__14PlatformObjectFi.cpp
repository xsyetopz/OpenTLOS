void PlatformObject::SimpleMessageAttached(int arg0) {
    s32 sp8[2];
    PlatformAttachment *var_r29_45;

    var_r29_45 = this->unk28.unk8;
    while (var_r29_45 != &this->unk28) {
        sp8[1] = 0;
        sp8[0] = arg0;
        var_r29_45->unk0->Message((MKMessage *) sp8);
        var_r29_45 = var_r29_45->unk8;
    }
}
