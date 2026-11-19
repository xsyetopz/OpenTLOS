void MKParticleSystem_DeinitModule() {
    MKParticleChunk *var_r31_136;
    MKParticleChunk **var_r3_137;
    MKParticleChunk **var_r4_135;
    MKParticleChunk *temp_r0_140;
    MKParticleChunk *temp_r0_159;

    var_r4_135 = gParticleChunks;
    var_r31_136 = (MKParticleChunk *) var_r4_135;
    var_r3_137 = var_r4_135;
    do {
        var_r3_137 -= 1;
        temp_r0_140 = *var_r3_137;
        if (temp_r0_140 == NULL) {
            break;
        }
        if (temp_r0_140 < var_r31_136) {
            var_r31_136 = temp_r0_140;
        }
    } while (true);
    if (var_r3_137 != (MKParticleChunk **) &gEmptyPtrListDL) {
        while ((temp_r0_159 = *var_r4_135) != NULL) {
            if (temp_r0_159 < var_r31_136) {
                var_r31_136 = temp_r0_159;
            }
            var_r4_135 += 1;
        }
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(var_r31_136, NULL, 0);
        } else {
            free((MKParticleChunk **) var_r31_136);
        }
    }
    gParticleChunks = NULL;
}
