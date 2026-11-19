s32 ControllerRumbleProperty::LoadLineInstance(MKIniLine *arg0) {
    s32 result;

    result = 0;
    if (((u8) arg0->LoadFloat("LargeAct", (f32 *) (*(u8 **) KDProperty::pInstanceMem + this->unk8), 0) != 0) || ((u8) arg0->LoadFloat("SmallAct", (f32 *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 4)), 0) != 0) || ((u8) arg0->LoadFloat("Duration", (f32 *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 8)), 0) != 0) || ((u8) arg0->LoadFloat("DropOffDistance", (f32 *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0xC)), 0) != 0) || ((u8) arg0->LoadBool("CameraSensitive", (bool *) (*(u8 **) KDProperty::pInstanceMem + (this->unk8 + 0x10)), 0) != 0)) {
        result = 1;
    }
    return result;
}
