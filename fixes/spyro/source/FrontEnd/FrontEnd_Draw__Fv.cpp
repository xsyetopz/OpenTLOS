void FrontEnd_Draw() {
    if ((void **) pFrontEndSystem != NULL) {
        /* The asm builds Tools_Ortho inside the if and destroys it at its end, so a block-scoped local matches the calls. */
        Tools_Ortho sp10;

        GameVideo_Draw(pVideo);
        if (videoFade > 0.0f) {
            MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
            MKPrimitive(0xC, 3);
            MKBegin(4);
            MKSetColorF(0.0f, 0.0f, 0.0f, videoFade);
            MKSetPositionF(-108.0f, 0.0f, 0.0f);
            MKSetPositionF(748.0f, 0.0f, 0.0f);
            MKSetPositionF(-108.0f, 512.0f, 0.0f);
            MKSetPositionF(748.0f, 512.0f, 0.0f);
            MKEnd();
            MKEndPrimitive();
        }
        {
            /* The asm builds RenderContext after the videoFade block and never destroys it. */
            RenderContext sp20;

            M2C_FIELD(*pFrontEndSystem, M2C_UNK (**)(void **, RenderContext *), 0x1C)(pFrontEndSystem, &sp20);
        }
        if (fade > 0.0f) {
            MKMaterial_SetMaterial(M2C_FIELD(&gb, MKMaterial **, 0x328));
            MKPrimitive(0xC, 3);
            MKBegin(4);
            MKSetColorF(0.0f, 0.0f, 0.0f, fade);
            MKSetPositionF(-108.0f, 0.0f, 0.0f);
            MKSetPositionF(748.0f, 0.0f, 0.0f);
            MKSetPositionF(-108.0f, 512.0f, 0.0f);
            MKSetPositionF(748.0f, 512.0f, 0.0f);
            MKEnd();
            MKEndPrimitive();
            if ((u8) bResetFade != 0) {
                bResetFade = 0;
                fade = 0.0f;
            }
        }
    }
}
