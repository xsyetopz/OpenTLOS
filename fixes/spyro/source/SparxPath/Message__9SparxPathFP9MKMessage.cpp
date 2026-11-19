void SparxPath::Message(MKMessage *arg0) {
    Sparx *temp_r3_77;
    void *spyro;
    s32 temp_r0_58;

    temp_r0_58 = arg0->unk0;
    switch (temp_r0_58) {                           /* irregular */
    case 0xB5:
        spyro = gb.GetSpyro();
        ((Sparx *) (M2C_FIELD(spyro, Sparx **, 0xB70)))->SetPath(this);
        break;
    case 0xB4:
        spyro = gb.GetSpyro();
        temp_r3_77 = (Sparx *) M2C_FIELD(spyro, Sparx **, 0xB70);
        if ((u32) temp_r3_77->unk1F4 == (u32) this) {
            temp_r3_77->SetPath(NULL);
        }
        break;
    }
    MKProp::Message(arg0);
}
