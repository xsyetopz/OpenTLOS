#ifndef SPYRO_SOURCE_EVENTMESSAGE_H
#define SPYRO_SOURCE_EVENTMESSAGE_H

#include <dolphin/types.h>

class EventMessage;
class MKIniLine;
class MKProp;

class EventMessage {
public:
    ~EventMessage(void);
    EventMessage(void);
    f32 Send(MKProp *);
    s32 LoadLine(MKIniLine *, const char *);
    void Deinit(void);
    void Init(void);
    EventMessage * operator=(const EventMessage &);
    /* 0x000 */ s32 unk0;
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

inline EventMessage::~EventMessage() {
    Deinit();
}

inline EventMessage::EventMessage() {
    this->unk0 = 0;
    Init();
}

#endif  // SPYRO_SOURCE_EVENTMESSAGE_H
