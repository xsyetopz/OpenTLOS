s32 FlowerCritter::LoadLine(MKIniLine *arg0) {
    s32 var_r31_895;

    var_r31_895 = 0;
    /* clrlwi. tests the low byte of each result, so both calls are compared as u8. */
    if ((((u8) Critters::LoadLine(arg0)) != 0) || ((((u8) arg0->LoadBool("CanLand", (bool *) &this->unk174, 0))) != 0)) {
        var_r31_895 = 1;
    }
    return var_r31_895;
}
