#ifndef COMMON_SOURCE_TRANSLATION_H
#define COMMON_SOURCE_TRANSLATION_H

#include <dolphin/types.h>
#include "unplaced_enums.h"

void Translation_GetLanguageCode(TranslationLanguage);
void Translation_GetLanguageLocalName(TranslationLanguage);
void Translation_GetLanguageName(TranslationLanguage);
u8 Translation_IsLanguageAvailable(TranslationLanguage);
void Translation_SetLanguage(TranslationLanguage);
s32 Translation_GetDefaultLanguage(void);
s32 Translation_GetLanguage(void);
void Translation_DeinitModule(void);
void Translation_InitModule(void);
extern void * gpTranslation_StringArray;
#endif  // COMMON_SOURCE_TRANSLATION_H
