s32 UIButtonGroup::Message(UIMessage *arg0) {
    s32 initial;
    s32 cur;
    UIObject *child;

    switch (arg0->unk0) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
    case 9:
        break;
    case 1:
        M2C_FIELD(*(s8 **) this, s32 (**)(UIButtonGroup *, s32), 0x38)(this, arg0->unk4);
        break;
    case 6:
        child = GetChild(this->unk68);
        M2C_FIELD(*(s8 **) child, s32 (**)(UIObject *, UIMessage *), 0x2C)(child, arg0);
        return 1;
    case 10:
        if ((u8) this->unk15 != 0) {
            initial = this->unk68;
            cur = initial;
            do {
                cur = (cur < this->unk64 - 1) ? cur + 1 : 0;
            } while (cur != initial && (u8) M2C_FIELD(*(s8 **) this, s32 (**)(UIButtonGroup *, s32), 0x38)(this, cur) == 0);
            if (initial != this->unk68) {
                M2C_FIELD(*(s8 **) this, void (**)(UIButtonGroup *), 0x3C)(this);
            }
            return this->unk68 != initial;
        }
        return 0;
    case 11:
        if ((u8) this->unk15 != 0) {
            initial = this->unk68;
            cur = initial;
            do {
                cur = (cur > 0) ? cur - 1 : this->unk64 - 1;
            } while (cur != initial && (u8) M2C_FIELD(*(s8 **) this, s32 (**)(UIButtonGroup *, s32), 0x38)(this, cur) == 0);
            if (initial != this->unk68) {
                M2C_FIELD(*(s8 **) this, void (**)(UIButtonGroup *), 0x3C)(this);
            }
            return this->unk68 != initial;
        }
        return 0;
    case 12:
        if ((u8) M2C_FIELD(*(s8 **) this, s32 (**)(UIButtonGroup *, s32), 0x38)(this, arg0->unk4) != 0) {
            M2C_FIELD(*(s8 **) this, void (**)(UIButtonGroup *), 0x3C)(this);
            return 1;
        }
        return 0;
    default:
        break;
    }
    return UIContainer::Message(arg0);
}
