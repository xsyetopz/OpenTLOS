#ifndef SPYRO_SOURCE_HEROINTERFACE_H
#define SPYRO_SOURCE_HEROINTERFACE_H

#include <dolphin/types.h>

class HeroInterface;
class SpeedWaySpyro;

class HeroInterface {
public:
    virtual void pure_slot0() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot1() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot2() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot3() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot4() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot5() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot6() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot7() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot8() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot9() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot10() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot11() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot12() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot13() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot14() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot15() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot16() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot17() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot18() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot19() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot20() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot21() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot22() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot23() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot24() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot25() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot26() = 0;  // name unknown: no descendant fills this slot
    virtual void pure_slot27() = 0;  // name unknown: no descendant fills this slot
    void * GetPosPtr(void);
    void GetXZDir(void);
    void GetDir(void);
    void GetPos(void);
    /* 0x004 */ SpeedWaySpyro* unk4;
    /* 0x008 */ f64 unk8;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#include <m2c_macros.h>

#if 0 // DRAFT: undefined identifier '__vptr'
inline void *HeroInterface::GetPosPtr() {
    return M2C_FIELD(M2C_FIELD(this->__vptr, void * (**)(HeroInterface *), 0xC)(this), s32 *, 8) + 0x30;
}
#endif

#if 0 // DRAFT: illegal use of abstract class ('HeroInterface::pure_slot0()')
inline void HeroInterface::GetXZDir() {
    f64 sp58;
    f64 sp50;
    HeroInterface sp40;
    HeroInterface sp30;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 sp18;
    f32 sp14;
    f32 sp10;
    f32 sp8;
    f32 var_f4_585;
    f32 var_f5_600;
    f64 temp_f1_605;
    f64 temp_f1_611;
    f64 temp_f1_615;
    s32 temp_r3_634;
    s32 var_r0_644;

    sp30.GetDir();
    sp40.GetDir();
    var_f4_585 = 0.0f;
    sp10 = M2C_BITWISE(f32, sp40);
    sp14 = 0.0f;
    sp18 = (f32) sp30.unk8;
    sp50 = (f64) sp10;
    sp58 = (f64) sp18;
    var_f5_600 = ((f32) sp58 * (f32) sp58) + (((f32) sp50 * (f32) sp50) + (unksp54 * unksp54));
    if (var_f5_600 > 1e-12f) {
        if (var_f5_600 > 0.0f) {
            temp_f1_605 = __frsqrte(var_f5_600);
            temp_f1_611 = 0.5 * temp_f1_605 * -(((f64) var_f5_600 * (temp_f1_605 * temp_f1_605)) - 3.0);
            temp_f1_615 = 0.5 * temp_f1_611 * -(((f64) var_f5_600 * (temp_f1_611 * temp_f1_611)) - 3.0);
            var_f5_600 = (f32) ((f64) var_f5_600 * (0.5 * temp_f1_615 * -(((f64) var_f5_600 * (temp_f1_615 * temp_f1_615)) - 3.0)));
        } else if (var_f5_600 < M2C_BITWISE(f32, 0.0)) {
            var_f5_600 = __float_nan;
        } else {
            sp8 = var_f5_600;
            temp_r3_634 = M2C_BITWISE(s32, sp8) & 0x7F800000;
            switch (temp_r3_634) {                  /* irregular */
            case 0x7F800000:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_644 = 1;
                } else {
                    var_r0_644 = 2;
                }
                break;
            case 0x0:
                if (M2C_BITWISE(s32, sp8) & 0x7FFFFF) {
                    var_r0_644 = 5;
                } else {
                    var_r0_644 = 3;
                }
                break;
            default:
                var_r0_644 = 4;
                break;
            }
            if (var_r0_644 == 1) {
                var_f5_600 = __float_nan;
            }
        }
        var_f4_585 = 1.0f / var_f5_600;
    }
    sp24 = unksp54 * var_f4_585;
    sp20 = (f32) sp50 * var_f4_585;
    sp28 = (f32) sp58 * var_f4_585;
    M2C_FIELD(this, f64 *, 0) = (f64) sp20;
    this->unk8 = (f64) sp28;
}
#endif

#if 0 // DRAFT: pointer/array required
inline void HeroInterface::GetDir() {
    f32 sp10;
    f32 spC;
    f32 sp8;
    void *temp_r3_701;

    temp_r3_701 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r4 */), void *(**)(M2C_UNK), 0xC)(M2C_ERROR(/* Read from unset register $r4 */)), void **, 8);
    sp8 = -M2C_FIELD(temp_r3_701, f32 *, 0x20);
    spC = -M2C_FIELD(temp_r3_701, f32 *, 0x24);
    sp10 = -M2C_FIELD(temp_r3_701, f32 *, 0x28);
    M2C_FIELD(this, f64 *, 0) = (f64) sp8;
    this->unk8 = (f64) sp10;
}
#endif

#if 0 // DRAFT: pointer/array required
inline void HeroInterface::GetPos() {
    void *temp_r3_387;

    temp_r3_387 = M2C_FIELD(M2C_FIELD(*M2C_ERROR(/* Read from unset register $r4 */), void *(**)(M2C_UNK), 0xC)(M2C_ERROR(/* Read from unset register $r4 */)), void **, 8);
    M2C_FIELD(this, f64 *, 0) = (f64) M2C_FIELD(temp_r3_387, f64 *, 0x30);
    this->unk8 = M2C_FIELD(temp_r3_387, f64 *, 0x38);
}
#endif

#endif  // SPYRO_SOURCE_HEROINTERFACE_H
