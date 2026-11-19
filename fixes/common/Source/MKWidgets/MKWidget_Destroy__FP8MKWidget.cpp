void MKWidget_Destroy(MKWidget *arg0) {
    MKWidget *temp_r29_815;
    MKWidget *temp_r3_814;
    u8 var_r31_818;

    temp_r3_814 = MKWidget_GetFocus();
    temp_r29_815 = arg0->unk18;
    var_r31_818 = 0;
    if ((MKWidget_IsDescendant(temp_r3_814, arg0) != 0) || (temp_r3_814 == arg0)) {
        var_r31_818 = 1;
    }
    if (var_r31_818 != 0) {
        if (temp_r29_815->unk20 == (u32) arg0) {
            temp_r29_815->unk20 = 0;
        }
        MKWidget_SendMessage(temp_r3_814, 0x20U, 0U);
        MKWidget_SendMessage(temp_r29_815, 0x20U, 1U);
    }
    MKWidget_SendMessage(arg0, 3U, 0U);
}
