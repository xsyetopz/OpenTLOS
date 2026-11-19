void SpyroTargetList::ClearCurrentTarget() {
    ((TargetContext *) this)->Set((Targetable *) NULL);
}
