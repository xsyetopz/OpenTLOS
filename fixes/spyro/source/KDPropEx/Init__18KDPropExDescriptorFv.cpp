void KDPropExDescriptor::Init() {
    KDProperty *p88;
    KDProperty *p9C;

    KDCommonProperties_RegisterAll((KDPropertyClassRegistry *) KDPropExDescriptor::propertyClassRegistry);
    KDPropDescriptor::Init();
    this->unk74.unk0 = NULL;
    this->unk74.unk4 = NULL;
    this->unk74.unk8 = NULL;
    this->unk74.unkC = 0;
    this->unk74.AllocInstanceMem(this->unk70, 0x40);
    this->unk84 = 0;
    this->unkB0.Init(*(const char **) pLocalToWorldPropertyName);
    this->unkB0.unk8 = 8;
    this->unk74.AddPublished((KDProperty *) &this->unkB0);
    p9C = (KDProperty *) ((u8 *) this + 0x9C);
    p9C->Init(*(const char **) pModelPropertyName);
    p9C->unk8 = 4;
    this->unk74.AddPublished(p9C);
    p88 = (KDProperty *) ((u8 *) this + 0x88);
    p88->Init(*(const char **) pAnimScriptPropertyName);
    p88->unk8 = 0x80;
    this->unk74.AddPublished(p88);
    this->unkC |= 1;
}
