extern "C" s32 stricmp(const char *, const char *);

void Texture::CreateRenderTarget(const char *arg0, int arg1, int arg2, int arg3) {
    s32 var_r30_749;
    s8 *var_r3_768;

    var_r30_749 = arg2;
    if (stricmp((const char *) &lit_stringBase0, arg0) == 0) {
        var_r3_768 = ((Texture *) arg0)->CreateFromRawData((const char *) &MKMat_MK2_Standard_CaptureTextureData, (void *) arg3, (s32) M2C_FIELD(&gDisplay, s32 *, 0x10) / 2, (s32) M2C_FIELD(&gDisplay, s32 *, 0x14) / 2, 0, M2C_ERROR(/* Read from unset register $r9 */));
    } else {
        if (var_r30_749 > 0x80) {
            var_r30_749 = 0x80;
        }
        var_r3_768 = ((Texture *) arg0)->CreateFromRawData(NULL, (void *) arg3, arg1, var_r30_749, 0, M2C_ERROR(/* Read from unset register $r9 */));
    }
    M2C_FIELD(var_r3_768, s8 *, 0x30) = 1;
}
