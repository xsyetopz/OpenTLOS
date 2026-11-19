void MiningMoleLeader::Message(MKMessage *arg0) {
    if ((s32) arg0->unk0 != 0x169) {
        ((KDSoundPlayer *) &this->unkB14)->Message(arg0);
        Enemy::Message(arg0);
        return;
    }
    checked_cast<NPCGoal_Think *, Goal<Enemy> >((Goal<Enemy> *) this->unkA3C)->AddGoal_BreakRock();
}
