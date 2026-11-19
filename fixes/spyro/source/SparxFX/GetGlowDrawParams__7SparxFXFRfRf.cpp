float _table_sinf(float);

void SparxFX::GetGlowDrawParams(float &arg0, float &arg1) {
    f32 temp_f31_755;

    temp_f31_755 = _table_sinf(this->unkB0);
    arg0 = 0.25f * ((8.0f * (_table_sinf(this->unkAC) * this->unkCC)) + 100.0f);
    arg1 = (8.0f * temp_f31_755) + 75.0f;
}
