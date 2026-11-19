void PlatformRider::LoadLine(MKIniLine *arg0) {
    arg0->LoadInt("platformID", &M2C_FIELD(this, int *, 4), 0);
}
