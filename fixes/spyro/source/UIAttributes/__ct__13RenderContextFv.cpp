RenderContext::RenderContext() {
    ((Matrix *) this)->SetIdentity();
    M2C_FIELD(this, f32 *, 0x40) = 1.0f;
    M2C_FIELD(this, f32 *, 0x44) = 1.0f;
    M2C_FIELD(this, f32 *, 0x48) = 1.0f;
    M2C_FIELD(this, f32 *, 0x4C) = 1.0f;
}
