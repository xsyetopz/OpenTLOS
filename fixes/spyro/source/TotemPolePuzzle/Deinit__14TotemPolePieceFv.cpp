void TotemPolePiece::Deinit() {
    ((Targetable *) ((s8 *) this + 0xC8))->UnregisterTargetable();
    GameProp::Deinit();
}
