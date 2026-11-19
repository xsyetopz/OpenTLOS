s32 ExplosiveBarrelPath::GetNextInactiveBarrelID() {
    s32 count;
    s32 off;

    count = 0;
    off = 0;
    do {
        ExplosiveBarrel *barrel = M2C_FIELD(this, ExplosiveBarrel **, off + 0x78);
        if (barrel->IsActive() == 0) {
            return count;
        }
        count += 1;
        off += 0x44;
    } while (count < 4);
    return -1;
}
