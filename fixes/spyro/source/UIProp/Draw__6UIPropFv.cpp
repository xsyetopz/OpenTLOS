void UIProp::Draw() {
    Tools_Ortho sp10;
    RenderContext sp20;
    UISystem *temp_r3_54;

    MKProp::Draw();
    temp_r3_54 = (UISystem *) this->unk54;
    if (temp_r3_54 != NULL) {
        temp_r3_54->Draw(sp20);
    }
}
