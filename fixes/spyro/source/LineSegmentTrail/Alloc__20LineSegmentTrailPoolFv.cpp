LineSegmentTrailPool *LineSegmentTrailPool::Alloc() {
    s32 i;
    s32 off;
    s8 *pool;
    MKVector4 unit;

    pool = *(s8 **) LineSegmentTrailPool::pTrailPool;
    off = 0;
    for (i = 0; i < 0xA; i++) {
        if ((u8) M2C_FIELD(pool + off, u8 *, 0x24) == 0) {
            memset(*(void **) (pool + off), 0, 0x3C0U);
            M2C_FIELD(pool + off, s32 *, 0x18) = 0;
            M2C_FIELD(pool + off, s8 *, 0x1C) = 0;
            unit.unk0 = 1.0f;
            unit.unk4 = 1.0f;
            unit.unk8 = 1.0f;
            unit.unkC = 1.0f;
            *(MKVector4 *) (pool + off + 8) = unit;
            M2C_FIELD(pool + off, s8 *, 0x24) = 1;
            M2C_FIELD(pool + off, s32 *, 0x20) = 0;
            return (LineSegmentTrailPool *) (pool + off);
        }
        off += 0x30;
    }
    return NULL;
}
