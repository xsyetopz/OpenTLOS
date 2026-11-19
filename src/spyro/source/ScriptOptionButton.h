#ifndef SPYRO_SOURCE_SCRIPTOPTIONBUTTON_H
#define SPYRO_SOURCE_SCRIPTOPTIONBUTTON_H

#include <dolphin/types.h>
#include "spyro/source/UITools.h"

class OptionButton;
class ScriptOptionButton;

class ScriptOptionButton : public OptionButton {  // base: base ctor call
public:
    ScriptOptionButton(void);
    static u8 descriptor[0x14];
};

// Inline member definitions: weak copies MWCC emitted out of line (tools/srcgen/inlines.py).

#if 0 // DRAFT: illegal return value in void/constructor/destructor function
inline ScriptOptionButton::ScriptOptionButton() {
    return this;
}
#endif

#endif  // SPYRO_SOURCE_SCRIPTOPTIONBUTTON_H
