u32 OptimiseGrassTypeData(MKModel *arg0, GrassUsedType *arg1) {
    s32 dataBytes;
    s32 subObjectCount;
    s32 srcOffset;
    s32 dstOffset;
    s32 usedCount;
    s32 size;
    s32 alignedSize;
    s32 headerBytes;
    u32 totalBytes;
    u8 *oldTable;
    u8 *table;
    u8 *cursor;
    u8 *entry;
    u8 *dst;

    /* Pass 1: header bytes per sub-object, each data block 16-aligned plus 16. */
    dataBytes = 0;
    subObjectCount = 0;
    srcOffset = 0;
    oldTable = (u8 *) arg1->unk4;
    while (subObjectCount < MKModel_GetNmbrOfSubObjects(arg0, (SubObjectType) 0)) {
        subObjectCount += 1;
        size = M2C_FIELD(oldTable + srcOffset, s32 *, 4);
        srcOffset += 0xC;
        dataBytes = ((size + 0xF) & 0xFFFFFFF0) + dataBytes + 0x10;
    }

    headerBytes = ((arg1->unk2 * 0xC) + 0xF) & 0xFFFFFFF0;
    if (MKHeap::Current() != NULL) {
        table = (u8 *) ((MKHeap *) (MKHeap::Current()))->Alloc(headerBytes + dataBytes, NULL, 0);
    } else {
        table = (u8 *) malloc(headerBytes + dataBytes);
    }
    arg1->unk4 = table;
    totalBytes = headerBytes + dataBytes;
    memset(arg1->unk4, 0, totalBytes);

    /* Pass 2: compact the used entries and move their data behind the header table. */
    cursor = table + headerBytes;
    srcOffset = 0;
    dstOffset = 0;
    usedCount = 0;
    while (usedCount < (s32) arg1->unk2) {
        entry = oldTable + srcOffset;
        if (M2C_FIELD(entry, u16 *, 2) != 0) {
            dst = table + dstOffset;
            M2C_FIELD(dst, u16 *, 0) = M2C_FIELD(entry, u16 *, 0);
            M2C_FIELD(dst, u16 *, 2) = M2C_FIELD(entry, u16 *, 2);
            M2C_FIELD(dst, u32 *, 4) = M2C_FIELD(entry, u32 *, 4);
            M2C_FIELD(dst, void **, 8) = M2C_FIELD(entry, void **, 8);
            M2C_FIELD(dst, u8 **, 8) = cursor;
            alignedSize = (M2C_FIELD(entry, u32 *, 4) + 0xF) & 0xFFFFFFF0;
            M2C_FIELD(dst, s32 *, 4) = alignedSize;
            cursor += M2C_FIELD(dst, s32 *, 4);
            memcpy(M2C_FIELD(dst, void **, 8), M2C_FIELD(entry, void **, 8), M2C_FIELD(entry, u32 *, 4));
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Main()))->TFree(M2C_FIELD(entry, void **, 8), NULL, 0);
            } else {
                free(M2C_FIELD(entry, void **, 8));
            }
            usedCount += 1;
            dstOffset += 0xC;
        }
        srcOffset += 0xC;
    }

    if (MKHeap::Current() != NULL) {
        ((MKHeap *) (MKHeap::Current()))->Free(oldTable, NULL, 0);
    } else {
        free(oldTable);
    }
    return totalBytes;
}
