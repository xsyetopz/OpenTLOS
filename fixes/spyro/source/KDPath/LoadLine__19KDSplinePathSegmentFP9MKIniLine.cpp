u8 KDSplinePathSegment::LoadLine(MKIniLine *arg0) {
    u8 var_r31_1156;

    var_r31_1156 = 0;
    if ((LoadLine(arg0, "waypoints") != 0) || (arg0->LoadBool("bForceLoop", (bool *) &this->unk44, 0) != 0)) {
        var_r31_1156 = 1;
    }
    return var_r31_1156;
}
