extern "C" double sin(double);

void KDSoundFlangedFader::Update(int arg0, bool arg1, bool arg2, MKProp *arg3, MKVector3 *arg4, unsigned int arg5, int arg6) {
    ((KDSoundFader *) this)->Update(arg0, arg1, arg2, arg3, arg4, arg5, arg6, true);
    ((KDSoundFader *) &this->unk28)->Update(arg0, arg1, arg2, arg3, arg4, arg5, arg6, true);
    if (arg2 != 0) {
        switch (this->unk50) {
        case 0:
            this->unk6C += gUpdateTimeDelta * this->unk60;
            if (this->unk6C >= 360.0f) {
                this->unk6C = this->unk6C - 360.0f;
            }
            KDSound_SetPitch(this->unk28, (this->unk68 * (f32) sin((f64) (0.017453292f * this->unk6C))) + this->unk64);
            return;
        case 1:
            this->unk6C += gUpdateTimeDelta * this->unk5C;
            if (((this->unk6C > this->unk58) && (this->unk5C > 0.0f)) || ((this->unk6C < this->unk58) && (this->unk5C < 0.0f))) {
                this->unk6C = this->unk54;
            }
            KDSound_SetPitch(this->unk28, this->unk6C);
            return;
        }
    } else {
        switch (this->unk50) {
        case 0:
            this->unk6C = 0.0f;
            return;
        case 1:
            this->unk6C = this->unk54;
            return;
        }
    }
}
