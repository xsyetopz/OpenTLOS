void GamePropColoredDescriptor::Deinit() {
    MKMaterial *temp_r3_108;

    temp_r3_108 = M2C_FIELD(this, MKMaterial **, 0xE4);
    if (temp_r3_108 != NULL) {
        MKMaterial_Destroy(temp_r3_108);
    }
    KDPropExDescriptor::Deinit();
}
