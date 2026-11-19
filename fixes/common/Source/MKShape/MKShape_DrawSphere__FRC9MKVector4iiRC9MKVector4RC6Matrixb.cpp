void MKShape_DrawSphere(const MKVector4 &arg0, int arg1, int arg2, const MKVector4 &arg3, const Matrix &arg4, bool arg5) {
    f32 sp1C;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;
    f32 temp_f24_1455;
    f32 temp_f24_1520;
    f32 temp_f24_1589;
    f32 temp_f24_1632;
    f32 temp_f24_1668;
    f32 temp_f25_1461;
    f32 temp_f25_1526;
    f32 temp_f25_1594;
    f32 temp_f25_1637;
    f32 temp_f25_1670;
    f32 temp_f26_1459;
    f32 temp_f26_1523;
    f32 temp_f26_1593;
    f32 temp_f26_1636;
    f32 temp_f26_1672;
    f32 temp_f27_1457;
    f32 temp_f27_1521;
    f32 temp_f27_1591;
    f32 temp_f27_1634;
    f32 temp_f27_1674;
    f32 temp_f28_1525;
    f32 temp_f29_1442;
    f32 temp_f6_1504;
    f32 var_f28_1441;
    f32 var_f30_1428;
    f32 var_f30_1527;
    f32 var_f30_1666;
    f32 var_f31_1423;
    f32 var_f31_1534;
    s32 var_r25_1460;
    s32 var_r25_1539;
    s32 var_r25_1675;
    s32 var_r26_1456;
    s32 var_r26_1524;
    s32 var_r26_1592;
    s32 var_r26_1635;
    s32 var_r27_1458;
    s32 var_r30_1690;

    var_f31_1423 = 0.0f;
    var_f30_1428 = 0.0f;
    var_f28_1441 = 3.1415927f / (1.0f + (f32) arg2);
    temp_f29_1442 = 6.2831855f / (f32) arg1;
    if (arg5 != 0) {
        MKPrimitive(0x10A, 3);
        MKSetMatrix(arg4);
        MKBegin((arg1 * (arg2 + 1)) + 1);
        MKSetColorV(arg3);
        temp_f24_1455 = arg0.unkC;
        var_r26_1456 = 0;
        temp_f27_1457 = arg0.unk0;
        var_r27_1458 = 0;
        temp_f26_1459 = arg0.unk4;
        var_r25_1460 = 1;
        temp_f25_1461 = arg0.unk8;
loop_5:
        if (var_r27_1458 < arg1) {
            _table_sincosf(var_f30_1428, sp1C, sp18);
            _table_sincosf(var_f31_1423, spC, sp8);
            MKSetPositionF((sp1C * (spC * temp_f24_1455)) + temp_f27_1457, (sp18 * temp_f24_1455) + temp_f26_1459, (sp1C * (sp8 * temp_f24_1455)) + temp_f25_1461);
            var_f30_1428 += var_f28_1441;
            var_r26_1456 += var_r25_1460;
            if ((var_r26_1456 == 0) || (var_r26_1456 == (s32) (arg2 + 1))) {
                var_f28_1441 = -var_f28_1441;
                var_r25_1460 = -var_r25_1460;
                var_f31_1423 += temp_f29_1442;
                var_r27_1458 += 1;
            }
            goto loop_5;
        }
        _table_sincosf(var_f30_1428, sp1C, sp18);
        _table_sincosf(var_f31_1423, spC, sp8);
        temp_f6_1504 = arg0.unkC;
        MKSetPositionF((sp1C * (spC * temp_f6_1504)) + arg0.unk0, (sp18 * temp_f6_1504) + arg0.unk4, (sp1C * (sp8 * temp_f6_1504)) + arg0.unk8);
        MKEnd();
        temp_f24_1520 = arg0.unkC;
        temp_f27_1521 = arg0.unk0;
        temp_f26_1523 = arg0.unk4;
        var_r26_1524 = 0;
        temp_f28_1525 = (f32) __fabsf(var_f28_1441);
        temp_f25_1526 = arg0.unk8;
        var_f30_1527 = temp_f28_1525;
loop_11:
        if (var_r26_1524 < arg2) {
            _table_sincosf(var_f30_1527, sp1C, sp18);
            var_f31_1534 = 0.0f;
            MKBegin(arg1 + 1);
            MKSetColorV(arg3);
            var_r25_1539 = 0;
loop_9:
            if (var_r25_1539 < (s32) (arg1 + 1)) {
                _table_sincosf(var_f31_1534, spC, sp8);
                MKSetPositionF((sp1C * (spC * temp_f24_1520)) + temp_f27_1521, (sp18 * temp_f24_1520) + temp_f26_1523, (sp1C * (sp8 * temp_f24_1520)) + temp_f25_1526);
                var_f31_1534 += temp_f29_1442;
                var_r25_1539 += 1;
                goto loop_9;
            }
            MKEnd();
            var_f30_1527 += temp_f28_1525;
            var_r26_1524 += 1;
            goto loop_11;
        }
        MKEndPrimitive();
    } else {
        MKPrimitive(0x10D, 3);
        MKSetMatrix(arg4);
        MKBegin(arg1 + 2);
        MKSetColorV(arg3);
        MKSetPositionF(arg0.unk0, arg0.unk4 + arg0.unkC, arg0.unk8);
        _table_sincosf(var_f28_1441, sp1C, sp18);
        temp_f24_1589 = arg0.unkC;
        temp_f27_1591 = arg0.unk0;
        var_r26_1592 = 0;
        temp_f26_1593 = arg0.unk4;
        temp_f25_1594 = arg0.unk8;
loop_15:
        if (var_r26_1592 < (s32) (arg1 + 1)) {
            _table_sincosf(var_f31_1423, spC, sp8);
            MKSetPositionF((sp1C * (spC * temp_f24_1589)) + temp_f27_1591, (sp18 * temp_f24_1589) + temp_f26_1593, (sp1C * (sp8 * temp_f24_1589)) + temp_f25_1594);
            var_f31_1423 += temp_f29_1442;
            var_r26_1592 += 1;
            goto loop_15;
        }
        MKEnd();
        MKBegin(arg1 + 2);
        MKSetColorV(arg3);
        MKSetPositionF(arg0.unk0, arg0.unk4 - arg0.unkC, arg0.unk8);
        _table_sincosf(3.1415927f - var_f28_1441, sp1C, sp18);
        temp_f24_1632 = arg0.unkC;
        temp_f27_1634 = arg0.unk0;
        var_r26_1635 = 0;
        temp_f26_1636 = arg0.unk4;
        temp_f25_1637 = arg0.unk8;
loop_18:
        if (var_r26_1635 < (s32) (arg1 + 1)) {
            _table_sincosf(var_f31_1423, spC, sp8);
            MKSetPositionF((sp1C * (spC * temp_f24_1632)) + temp_f27_1634, (sp18 * temp_f24_1632) + temp_f26_1636, (sp1C * (sp8 * temp_f24_1632)) + temp_f25_1637);
            var_f31_1423 += temp_f29_1442;
            var_r26_1635 += 1;
            goto loop_18;
        }
        MKEnd();
        MKEndPrimitive();
        MKPrimitive(0x10C, 3);
        MKSetMatrix(arg4);
        var_f30_1666 = var_f28_1441;
        temp_f24_1668 = arg0.unkC;
        temp_f25_1670 = arg0.unk0;
        temp_f26_1672 = arg0.unk4;
        temp_f27_1674 = arg0.unk8;
        var_r25_1675 = 0;
loop_24:
        if (var_r25_1675 < (s32) (arg2 - 1)) {
            _table_sincosf(var_f30_1666, sp1C, sp18);
            _table_sincosf(var_f30_1666 + var_f28_1441, sp14, sp10);
            MKBegin((arg1 * 2) + 2);
            MKSetColorV(arg3);
            var_r30_1690 = 0;
loop_22:
            if (var_r30_1690 < (s32) (arg1 + 1)) {
                _table_sincosf(var_f31_1423, spC, sp8);
                MKSetPositionF((sp1C * (spC * temp_f24_1668)) + temp_f25_1670, (sp18 * temp_f24_1668) + temp_f26_1672, (sp1C * (sp8 * temp_f24_1668)) + temp_f27_1674);
                MKSetPositionF((sp14 * (spC * temp_f24_1668)) + temp_f25_1670, (sp10 * temp_f24_1668) + temp_f26_1672, (sp14 * (sp8 * temp_f24_1668)) + temp_f27_1674);
                var_f31_1423 += temp_f29_1442;
                var_r30_1690 += 1;
                goto loop_22;
            }
            MKEnd();
            var_f30_1666 += var_f28_1441;
            var_r25_1675 += 1;
            goto loop_24;
        }
        MKEndPrimitive();
    }
    MKPrimitive(0x109, 3);
    MKBegin(6);
    MKSetColorF(0.0f, 1.0f, 0.0f, 1.0f);
    MKSetPositionF(arg0.unk0, (0.5f * arg0.unkC) + arg0.unk4, arg0.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetColorF(1.0f, 0.0f, 0.0f, 1.0f);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF((0.5f * arg0.unkC) + arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetColorF(0.0f, 0.0f, 1.0f, 1.0f);
    MKSetPositionF(arg0.unk0, arg0.unk4, arg0.unk8);
    MKSetPositionF(arg0.unk0, arg0.unk4, (0.5f * arg0.unkC) + arg0.unk8);
    MKEnd();
    MKEndPrimitive();
}
