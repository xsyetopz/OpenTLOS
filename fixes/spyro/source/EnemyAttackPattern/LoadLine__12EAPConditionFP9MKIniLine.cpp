void EAPCondition::LoadLine(MKIniLine *arg0) {
    s32 temp_r0_27;

    this->unk4 = DataMap_GetValue(&dataMapEAPCondition, (const char *) arg0->GetFieldName());
    this->unk8 = EAP_GetEAPConditionType((eEAPCondition) this->unk4);
    temp_r0_27 = this->unk4;
    if ((temp_r0_27 >= 7) || (temp_r0_27 < 5)) {
        this->unkC = arg0->GetFloat(0);
        return;
    }
    this->unkC = arg0->GetFloat(2);
    this->unk0 = (EnemyAttack *) (pCurrEnemyDescriptor->GetAttack(arg0->GetInt(1)));
}
