void Shadow_Draw() {
    Frustum sp8;
    MKHeap **temp_r31_460;
    Shadow *var_r30_450;
    Shadow *var_r3_424;
    u8 var_r4_425;

    if (((u8) bShadowEnabled != 0) && ((Shadow *) pShadowList != NULL)) {
        var_r3_424 = pShadowList;
        var_r4_425 = 0;
loop_4:
        if ((var_r3_424 != NULL) && (var_r4_425 == 0)) {
            var_r4_425 = var_r3_424->unk2C;
            var_r3_424 = var_r3_424->unk18;
            goto loop_4;
        }
        if (var_r4_425 != 0) {
            Shadow_BeginDraw();
            M2C_STRUCT_COPY(&sp8, MKView_GetWorldFrustum(), 0x70);
            var_r30_450 = pShadowList;
loop_12:
            if (var_r30_450 != NULL) {
                if ((u8) var_r30_450->unk2C != 0) {
                    temp_r31_460 = MKModel_GetBoundingVolume(var_r30_450->unk10, (SubObjectType) 0, -1);
                    if (sp8.IsVisible((Matrix *) MKModel_GetWorldMatrix(var_r30_450->unk10), (BoundingVolume *) temp_r31_460) != 0) {
                        var_r30_450->Draw();
                    }
                }
                var_r30_450 = var_r30_450->unk18;
                goto loop_12;
            }
            Shadow_EndDraw();
        }
    }
}
