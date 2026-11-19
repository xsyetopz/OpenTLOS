void MKSceneManager::PropResolver_Init() {
    s8 *var_r3;
    s32 var_r4;
    s32 var_ctr;

    if (MKHeap::Current() != NULL) {
        var_r3 = (signed char *) (((MKHeap *) (MKHeap::Current()))->Alloc(0xA000, NULL, 0));
    } else {
        var_r3 = malloc(0xA000);
    }
    var_r4 = 0;
    *(s8 **) MKSceneManager::pPropMapping = var_r3;
    *(s32 *) MKSceneManager::nmbrOfMappings = 0;
    var_ctr = 0x400;
    do {
        *(s32 *) (*(s8 **) MKSceneManager::pPropMapping + var_r4 + 4) = 0;
        *(s32 *) (*(s8 **) MKSceneManager::pPropMapping + var_r4) = -1;
        var_r4 += 0x28;
        var_ctr -= 1;
    } while (var_ctr != 0);
}
