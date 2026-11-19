s32 EAPManager::ReEvaluate(Enemy *arg0, AITargetData *arg1) {
    EAPCondition *temp_r28_682;
    EAPItem *temp_r3_707;
    s32 var_r29_676;
    s32 var_r30_678;
    s32 var_r31_677;

    fCachedOwnerAngle = NormaliseAngle(KDMath_GetYaw(*((MKVector3 *) &arg0->unkC0)));
    MKVector3 sp8 = arg1->GetDir();
    fCachedTargetAngle = NormaliseAngle(KDMath_GetYaw(sp8));
    if ((EAPItem *) this->unk8 != NULL) {
        var_r29_676 = 0;
        var_r31_677 = 0;
        var_r30_678 = 0;
loop_7:
        temp_r3_707 = (EAPItem *) this->unk8;
        if (var_r29_676 >= temp_r3_707->unk8) {
            fCachedOwnerAngle = 0.0f;
            fCachedTargetAngle = 0.0f;
            return 1;
        }
        temp_r28_682 = (EAPCondition *) ((u8 *) temp_r3_707->unk4 + var_r30_678);
        if ((temp_r28_682->unkC < 0.0f) && ((u8) EvaluateCondition((EAPItem *) (*this->unk4 + var_r31_677), temp_r28_682, arg0, arg1) != 0) && (temp_r28_682->unkC < 0.0f)) {
            return 0;
        }
        var_r29_676 += 1;
        var_r31_677 += 0xC;
        var_r30_678 += 0x10;
        goto loop_7;
    }
    return 0;
}
