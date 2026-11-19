#ifndef SPYRO_SOURCE_SCRIPTOPTIONBUTTON_H
#define SPYRO_SOURCE_SCRIPTOPTIONBUTTON_H

#include <dolphin/types.h>
#include "spyro/source/UITools.h"

class ScriptButton;
class ScriptOptionButton;

class ScriptOptionButton : public ScriptButton {  // base: vtable prefix
public:
    ScriptOptionButton(void);
};

#endif  // SPYRO_SOURCE_SCRIPTOPTIONBUTTON_H
