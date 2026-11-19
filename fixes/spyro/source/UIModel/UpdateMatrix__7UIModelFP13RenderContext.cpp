void UIModel::UpdateMatrix(RenderContext *arg0) {
    Matrix sp40;
    MKVector3 sp30;

    /* Lazily initialise the two static camera vectors on first use. */
    if ((s8) init_577 == 0) {
        camera_576.unk0 = 0.0f;
        camera_576.unk4 = 0.0f;
        camera_576.unk8 = 0.0f;
        init_577 = 1;
    }
    if ((s8) init_580 == 0) {
        lookat_579.unk0 = 0.0f;
        lookat_579.unk4 = 0.0f;
        lookat_579.unk8 = 1.0f;
        init_580 = 1;
    }
    MKView_SetCameraLookAt(camera_576, lookat_579, 0.0f);

    /* Start from the render context's leading matrix, negate the rotation terms, then rebuild the translation. */
    sp40 = *(Matrix *) arg0;
    sp40.unk4 *= -1.0f;
    sp40.unk10 *= -1.0f;
    sp40.unk18 *= -1.0f;
    sp40.unk1C *= -1.0f;
    sp40.unk24 *= -1.0f;
    sp40.unk34 *= -1.0f;
    MKView_TransformPoint2Dto3D(arg0->unk30, arg0->unk34, (1000.0f * arg0->unk38) + 1000.0f, &sp30);
    sp40.unk3C = 1.0f;
    sp40.unk30 = sp30.unk0;
    sp40.unk34 = sp30.unk4;
    sp40.unk38 = sp30.unk8;
    sp40.unk2C = 0.0f;
    sp40.unk1C = 0.0f;
    sp40.unkC = 0.0f;
    sp40.unk3C = 1.0f;
    MKModel_SetWorldMatrix(this->unk64, sp40);
    MKModel_SetColor(this->unk64, *((MKVector4 *) &arg0->unk40));
}
