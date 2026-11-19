s32 ScriptProp::LoadLine(MKIniLine *arg0) {
    s32 var_r29_287;
    s32 var_r31_289;
    s32 var_r31_314;

    if (MKProp::LoadLine(arg0) != 0) {
        return 1;
    }
    var_r29_287 = 0;
    var_r31_289 = 0;
    do {
        if (((EventMessage *) ((u8 *) this + (var_r31_289 + 0x58)))->LoadLine(arg0, (const char *) Str_Printf("Message%d", var_r29_287)) != 0) {
            return 1;
        }
        var_r29_287 += 1;
        var_r31_289 += 4;
    } while (var_r29_287 < 0xA);
    var_r31_314 = 0;
    if ((arg0->LoadFloat("delay", &this->unk4C, 0) != 0) || (arg0->LoadBool("bDelayEachMessage", (bool *) &this->unk54, 0) != 0) || (PropFlagsLoadLine((unsigned int *) &this->unk10, arg0) != 0)) {
        var_r31_314 = 1;
    }
    return var_r31_314;
}
