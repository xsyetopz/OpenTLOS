void XFONTPrintf(short arg0, short arg1, char *arg2, ...) {
    va_list args;
    char buf[0x104];
    s16 x;
    s16 y;

    x = arg0;
    y = arg1;
    va_start(args, arg2);
    vsprintf(buf, arg2, args);
    va_end(args);
    XFONTputString(&x, &y, buf, &XFontBitmap);
}
