s32 Attributes::LoadLine(UIDataLine *arg0) {
    s8 *sp8;
    s32 var_r30_116;

    if (((MKIniLine *) arg0)->LoadVector4("colour", (MKVector4 *) this, 0) != 0) {
        this->unk40 |= 1;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadVector3("position", &this->unk10, 0) != 0) {
        this->unk40 |= 2;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadVector3("rotation", &this->unk20, 0) != 0) {
        this->unk40 |= 4;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadFloat("scale", &this->unk30, 0) != 0) {
        this->unk40 |= 8;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadFloat("width", &this->unk34, 0) != 0) {
        this->unk40 |= 0x10;
        return 1;
    }
    if (((MKIniLine *) arg0)->LoadFloat("height", &this->unk38, 0) != 0) {
        this->unk40 |= 0x10;
        return 1;
    }
    if (((MKIniLine *) arg0)->IsField("alignment") != 0) {
        var_r30_116 = 0;
        this->unk40 |= 0x20;
        sp8 = NULL;
loop_14:
        ((MKIniLine *) arg0)->AsString(var_r30_116, (const char **) &sp8);
        if (sp8 != NULL) {
            if (stricmp((s8 *) "top", sp8) == 0) {
                this->unk3C &= 3;
                goto block_29;
            }
            if (stricmp((s8 *) "middle", sp8) == 0) {
                this->unk3C = (this->unk3C & 3) | 4;
                goto block_29;
            }
            if (stricmp((s8 *) "bottom", sp8) == 0) {
                this->unk3C = (this->unk3C & 3) | 8;
                goto block_29;
            }
            if (stricmp((s8 *) "left", sp8) == 0) {
                this->unk3C &= 0xC;
                goto block_29;
            }
            if (stricmp((s8 *) "centre", sp8) == 0) {
                this->unk3C = (this->unk3C & 0xC) | 1;
                goto block_29;
            }
            if (stricmp((s8 *) "right", sp8) == 0) {
                this->unk3C = (this->unk3C & 0xC) | 2;
                goto block_29;
            }
            if (var_r30_116 == 0) {
                this->unk3C = ((MKIniLine *) arg0)->GetInt(0);
            } else {
block_29:
                var_r30_116 += 1;
                if (var_r30_116 < 2) {
                    goto loop_14;
                }
            }
        }
        return 1;
    }
    return 0;
}
