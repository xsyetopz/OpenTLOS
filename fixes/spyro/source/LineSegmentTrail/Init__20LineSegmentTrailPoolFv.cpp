void LineSegmentTrailPool::Init() {
    s32 i;
    s32 off;
    s32 count;
    void *buf;
    MKVector4 unit;

    count = *(s32 *) LineSegmentTrailPool::refCount;
    *(s32 *) LineSegmentTrailPool::refCount = count + 1;
    if (count <= 0) {
        if (MKHeap::Current() != NULL) {
            *(s8 **) LineSegmentTrailPool::pTrailPool = (s8 *) ((MKHeap *) (MKHeap::Current()))->Alloc(0x1E0, NULL, 0);
        } else {
            *(s8 **) LineSegmentTrailPool::pTrailPool = (s8 *) malloc(0x1E0);
        }
        unit.unk0 = 1.0f;
        unit.unk4 = 1.0f;
        unit.unk8 = 1.0f;
        unit.unkC = 1.0f;
        off = 0;
        for (i = 0; i < 0xA; i++) {
            if (MKHeap::Current() != NULL) {
                buf = ((MKHeap *) (MKHeap::Current()))->Alloc(0x3C0, NULL, 0);
            } else {
                buf = malloc(0x3C0);
            }
            *(void **) (*(s8 **) LineSegmentTrailPool::pTrailPool + off) = buf;
            memset(buf, 0, 0x3C0U);
            M2C_FIELD(*(s8 **) LineSegmentTrailPool::pTrailPool + off, s32 *, 0x18) = 0;
            M2C_FIELD(*(s8 **) LineSegmentTrailPool::pTrailPool + off, u8 *, 0x1C) = 0;
            *(MKVector4 *) (*(s8 **) LineSegmentTrailPool::pTrailPool + off + 8) = unit;
            M2C_FIELD(*(s8 **) LineSegmentTrailPool::pTrailPool + off, s32 *, 0x20) = 0;
            M2C_FIELD(*(s8 **) LineSegmentTrailPool::pTrailPool + off, u8 *, 0x24) = 0;
            off += 0x30;
        }
    }
}
