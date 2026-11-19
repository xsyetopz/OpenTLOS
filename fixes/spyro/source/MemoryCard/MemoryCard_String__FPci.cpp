s8 *MemoryCard_String(char *arg0, int arg1) {
    s32 digit = 0;
    s8 *dst = (s8 *) arg0;
    s8 *src = *(s8 **) ((s8 *) gpTranslation_StringArray + arg1 * 4);

    for (; *src != 0; src++) {
        s8 c = *src;
        if (c == '<' && (src[1] == 'P' || src[1] == 'p') && src[3] == '>') {
            digit = src[2] - 0x30;
        }
        if (c == '\\') {
            src++;
            if (*src == 'n') {
                *dst++ = 0x0A;
            } else if (*src == 'r') {
                *dst++ = 0x0D;
            } else if (*src == '\\') {
                *dst++ = 0x5C;
            }
        } else if (c == '%' && digit == 0) {
            s8 t;

            src++;
            t = *src;
            if (t == 't') {
                if (src[1] == '2') {
                    dst += sprintf((char *) dst, "%s", *(char **) gpTranslation_StringArray);
                    src++;
                } else {
                    s8 *p = *(s8 **) ((s8 *) gpTranslation_StringArray + 0xC);
                    for (;;) {
                        s8 ch = *p++;
                        *dst = ch;
                        if (ch == 0) {
                            break;
                        }
                        if (ch == '\\' && *p == 'n') {
                            *dst = ' ';
                            p++;
                        }
                        dst++;
                    }
                }
            } else if (t == 's') {
                s8 *str = NULL;
                void *card = *(void **) MemoryCardScreen::selectedCard;

                if (card != NULL) {
                    str = *(s8 **) ((s8 *) gpTranslation_StringArray + (*(s32 *) card * 4) + 0x11C);
                }
                if (str != NULL) {
                    s8 ch;
                    do {
                        ch = *str++;
                        *dst++ = ch;
                    } while (ch != 0);
                    dst--;
                }
            } else if (t == 'x') {
                dst += sprintf((char *) dst, "%d", MemoryCard_GetSaveGameBlockSize());
            } else if (t == 'y') {
                dst += sprintf((char *) dst, "%d", 1);
            } else if (t == '%') {
                *dst++ = '%';
            }
        } else {
            *dst++ = c;
        }
    }
    *dst = 0;
    return (s8 *) arg0;
}
