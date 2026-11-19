void FlameBreathFX::GetAttack1UpgradeVariables(int arg0, float &arg1, float &arg2, float &arg3) {
    switch (arg0) {
    case 0:
        arg1 = 0.3f;
        arg2 = 500.0f;
        arg3 = 1.0f;
        return;
    case 1:
        arg1 = 0.75f;
        arg2 = 700.0f;
        arg3 = 1.2f;
        return;
    case 2:
        arg1 = 1.0f;
        arg2 = 900.0f;
        arg3 = 1.4f;
        return;
    case 3:
        arg1 = 1.2f;
        arg2 = 1000.0f;
        arg3 = 1.6f;
        return;
    }
}
