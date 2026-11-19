void Gondola::WaveMotion::Update() {
    *(f32 *) this = *(f32 *) this + gUpdateTimeDelta;
}
