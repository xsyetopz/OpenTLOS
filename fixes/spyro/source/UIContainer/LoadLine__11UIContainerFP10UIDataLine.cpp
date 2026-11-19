extern "C" UIObject *malloc(u32);
s32 UIContainer::LoadLine(UIDataLine *arg0) {
    s8 *desc;
    UIObject *obj;
    MKIniLine *sub;
    s32 size;

    if (((MKIniLine *) arg0)->IsField("include") != 0) {
        UIObject::Load((const char *) ((MKIniLine *) arg0)->GetString(0), NULL);
        return 1;
    }
    for (desc = (s8 *) UIObjectDescriptor::list.unk0; desc != NULL; desc = M2C_FIELD(desc, s8 **, 0x10)) {
        if (((MKIniLine *) arg0)->IsField(M2C_FIELD(desc, const char **, 0x0)) != 0) {
            size = M2C_FIELD(desc, s32 *, 0x8);
            if (MKHeap::Current() != NULL) {
                obj = (UIObject *) MKHeap::Current()->Alloc(size, NULL, 0);
            } else {
                obj = malloc((u32) size);
            }
            M2C_FIELD(desc, void (**)(UIObject *), 0xC)(obj);
            obj->unk8 = desc;
            M2C_FIELD(*(s8 **) obj, void (**)(UIObject *), 0x8)(obj);
            sub = arg0->unkC->GetSubLine((MKIniLine *) arg0);
            for (; sub != NULL; sub = sub->unkC->GetNextLine(sub)) {
                M2C_FIELD(*(s8 **) obj, s32 (**)(UIObject *, UIDataLine *), 0x10)(obj, (UIDataLine *) sub);
            }
            AddBefore(NULL, obj);
            M2C_FIELD(*(s8 **) obj, void (**)(UIObject *), 0x14)(obj);
            return 1;
        }
    }
    return UIObject::LoadLine(arg0);
}
