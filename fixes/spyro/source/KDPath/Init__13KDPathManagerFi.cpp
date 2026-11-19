void KDPathManager::Init(int arg0) {
    s32 temp_r31_583;
    s32 var_r4_601;
    void *var_r3_592;

    temp_r31_583 = arg0 * 4;
    *(s32 *) KDPathManager::numTypes = arg0;
    if (MKHeap::Current() != NULL) {
        var_r3_592 = ((MKHeap *) (MKHeap::Current()))->Alloc(temp_r31_583, NULL, 0);
    } else {
        var_r3_592 = malloc(temp_r31_583);
    }
    *(void **) KDPathManager::pPathLists = var_r3_592;
    for (var_r4_601 = *(s32 *) KDPathManager::numTypes - 1; var_r4_601 >= 0; var_r4_601--) {
        (*(KDPathSegment ***) KDPathManager::pPathLists)[var_r4_601] = NULL;
    }
}
