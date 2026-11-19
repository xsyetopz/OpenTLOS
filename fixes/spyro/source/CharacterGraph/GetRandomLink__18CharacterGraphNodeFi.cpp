CharacterGraphNode *CharacterGraphNode::GetRandomLink(int arg0) {
    CharacterGraphNode *var_r31_690;
    KDGraphNode *temp_r3_707;
    s32 var_r30_691;
    s32 var_r3_697;

    var_r31_690 = this;
    var_r30_691 = 0;
    while ((var_r30_691 < arg0) && (var_r31_690->GetNumLinks() != 0)) {
        var_r3_697 = MKRand_Int((int *) &gViewSeed, 0, 5);
        while ((temp_r3_707 = *(KDGraphNode **) ((u8 *) var_r31_690 + ((var_r3_697 * 4) + 0x18))) == NULL) {
            var_r3_697 = MKRand_Int((int *) &gViewSeed, 0, 6);
        }
        var_r31_690 = checked_cast<CharacterGraphNode *, KDGraphNode>(temp_r3_707);
        var_r30_691 += 1;
    }
    return var_r31_690;
}
