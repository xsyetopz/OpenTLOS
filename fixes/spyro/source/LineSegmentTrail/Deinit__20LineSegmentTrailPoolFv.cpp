void LineSegmentTrailPool::Deinit() {
    s32 i;
    s32 off;
    s32 count;
    s8 *pool;
    void *buf;

    count = *(s32 *) LineSegmentTrailPool::refCount - 1;
    *(s32 *) LineSegmentTrailPool::refCount = count;
    if (count <= 0) {
        pool = *(s8 **) LineSegmentTrailPool::pTrailPool;
        off = 0;
        for (i = 0; i < 0xA; i++) {
            if ((u8) M2C_FIELD(pool + off, u8 *, 0x24) != 0) {
                return;
            }
            off += 0x30;
        }
        off = 0;
        for (i = 0; i < 0xA; i++) {
            buf = *(void **) (pool + off);
            if (MKHeap::Current() != NULL) {
                ((MKHeap *) (MKHeap::Current()))->Free(buf, NULL, 0);
            } else {
                free(buf);
            }
            off += 0x30;
        }
        buf = pool;
        if (MKHeap::Current() != NULL) {
            ((MKHeap *) (MKHeap::Current()))->Free(buf, NULL, 0);
        } else {
            free(buf);
        }
        *(s8 **) LineSegmentTrailPool::pTrailPool = NULL;
    }
}
