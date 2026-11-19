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

#endif  // SPYRO_SOURCE_HEROINTERFACE_H
