s32 EventCamera::LoadLine(MKIniLine *arg0) {
    MKIniLine *var_r29_3675;

    if ((MKProp::LoadLine(arg0) != 0) || (arg0->LoadInt("targetID", (int *) &this->unkF0, 0) != 0) || (arg0->LoadBool("bUsePropGroupVolumes", (bool *) &this->unkF4, 0) != 0) || (arg0->LoadBool("ShowSpyro", (bool *) &this->unkF6, 0) != 0) || (arg0->LoadBool("MapSplineStartToCurrentCam", (bool *) &this->unkF7, 0) != 0) || (arg0->LoadBool("MapTargetSplineStartToCurrentCamDir", (bool *) &this->unkF8, 0) != 0) || (arg0->LoadBool("FadeToBlack", (bool *) &this->unkF9, 0) != 0) || (arg0->LoadBool("HoldFadeToBlack", (bool *) &this->unkFA, 0) != 0) || (arg0->LoadInt("FollowSplineID", (int *) &this->unkB0, 0) != 0) || (arg0->LoadFloat("FollowSplineTime", &this->unkBC, 0) != 0) || (arg0->LoadInt("TargetSplineID", (int *) &this->unkB4, 0) != 0) || (arg0->LoadFloat("TargetSplineTime", &this->unkC0, 0) != 0) || (arg0->LoadInt("FollowOnEventCamera", (int *) &this->unkB8, 0) != 0) || (arg0->LoadFloat("FollowOnEventCameraLerpTime", &this->unkD4, 0) != 0) || (arg0->LoadBool("FuryCamera", (bool *) &this->unkFB, 0) != 0) || (arg0->LoadBool("TargetChild", (bool *) &this->unk102, 0) != 0) || (arg0->LoadBool("RotateCamera", (bool *) &this->unk103, 0) != 0) || (arg0->LoadBool("RotateCameraAngleChildOrientation", (bool *) &this->unk104, 0) != 0) || (arg0->LoadFloat("RotateCameraSpeed", &this->unkD8, 0) != 0) || (arg0->LoadFloat("RotateCameraRadius", &this->unkDC, 0) != 0) || (arg0->LoadFloat("RotateYOffset", &this->unkE0, 0) != 0) || (arg0->LoadFloat("TargetYOffset", &this->unkEC, 0) != 0) || (arg0->LoadFloat("RotateStartAngle", &this->unkE4, 0) != 0) || (arg0->LoadBool("TransitionBackToPlayer", (bool *) &this->unkFC, 0) != 0) || (arg0->LoadBool("TransitionBackToPlayerLookTarget", (bool *) &this->unkFE, 0) != 0) || (arg0->LoadBool("TransitionFromCurrentCamera", (bool *) &this->unkFF, 0) != 0) || (arg0->LoadBool("TransitionFromCurrentCameraLookTarget", (bool *) &this->unk100, 0) != 0) || (arg0->LoadFloat("TransitionBackToPlayerTime", &this->unkCC, 0) != 0) || (arg0->LoadFloat("TransitionFromCurrentCameraTime", &this->unkD0, 0) != 0)) {
        return 1;
    }
    if (arg0->IsField("camera") != 0) {
        var_r29_3675 = arg0->unkC->GetSubLine(arg0);
loop_35:
        if (var_r29_3675 != NULL) {
            if (var_r29_3675->LoadVector3("cameraSource", (MKVector3 *) &this->unk50, 0) == 0) {
                var_r29_3675->LoadVector3("cameraTarget", &this->unk60, 0);
            }
            var_r29_3675 = var_r29_3675->unkC->GetNextLine(var_r29_3675);
            goto loop_35;
        }
        return 1;
    }
    return 0;
}
