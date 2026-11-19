class CutsceneSystem;

void TeslaTower::Draw() {
    void *cutscene;
    u8 suppress;

    cutscene = M2C_FIELD(&gb, void **, 0xC);
    suppress = 0;
    if (cutscene != NULL) {
        if ((((u32) M2C_FIELD(cutscene, u32 *, 0x78) != 0U) || ((u32) M2C_FIELD(cutscene, u32 *, 0x84) != 0U)) && (((KDStateMachine<CutsceneSystem> *) ((s8 *) cutscene + 0x24))->GetState() != 0)) {
            suppress = 1;
        }
    }
    if (suppress == 0) {
        KDProp::Draw();
        DrawLightCone();
    }
}
