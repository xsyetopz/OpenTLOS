f32 MKWidget_GetMetricF(int arg0) {
    return *(f32 *) (gMKWidgetMetrics + (arg0 * 0x10));
}
