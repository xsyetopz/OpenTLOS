#include "spyro/source/UIObject.h"
#include "spyro/source/UIText.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

#if 0 // DRAFT: identifier 'ui_cast<...>(T1)' redeclared
UIText *ui_cast<UIText *, UIObject *>(UIObject *arg0) {
    UIText *sp8;

    sp8 = NULL;
    ui_cast_ptr<UIText, UIObject>(sp8, arg0);
    return sp8;
}
#endif

#if 0 // DRAFT: identifier 'ui_cast_ptr<...>(T0 *&, T1 *)' redeclared
void ui_cast_ptr<UIText, UIObject>(UIText *&arg0, UIObject *arg1) {
    u8 var_r0_42;
    void *var_r5_37;

    if (arg1 != NULL) {
        var_r5_37 = arg1->unk8;
loop_2:
        if (var_r5_37 == &descriptor) {
            var_r0_42 = 1;
        } else {
            var_r5_37 = M2C_FIELD(var_r5_37, void **, 4);
            if (var_r5_37 == NULL) {
                var_r0_42 = 0;
            } else {
                goto loop_2;
            }
        }
        if (var_r0_42 != 0) {
            &arg0 = checked_cast<UIText *, UIObject>(arg1);
        }
    }
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<UIText *, UIObject>(UIObject *arg0) {

}
#endif
