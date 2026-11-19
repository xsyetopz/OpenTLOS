#include "common/gc/MKPrimitive_GC.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKMaterial.h"
#include "common/Source/MKVector4.h"
#include "common/Source/Texture.h"
#include "common/gc/MKMaterial_GC.h"
#include <m2c_macros.h>

extern MKMaterial *gpMKWhiteMaterial;

void MKPrimitive_DeinitModule() {

}

void MKEndPrimitive() {
    do {

    } while (MKMaterial_Begin() != 0);
    MKMaterial_RenderImmediateEnd();
}

void MKEnd() {
    MKMaterial_RenderVerticesEnd();
    do {

    } while (MKMaterial_BeginInternal() != 0);
}

#if 0 // DRAFT: illegal use of incomplete struct/union/class 'MKVector3'
void MKSetPositionV(const MKVector3 &arg0) {
    MKMaterial_SetVertex4F(0, arg0.unk0, arg0.unk4, arg0.unk8, 1.0f);
}
#endif

void MKSetPositionF(float arg0, float arg1, float arg2) {
    MKMaterial_SetVertex4F(0, arg0, arg1, arg2, 1.0f);
}

void MKSetNormalF(float arg0, float arg1, float arg2) {
    MKMaterial_SetVertex4F(2, arg0, arg1, arg2, 0.0f);
}

void MKSetTexCoord1F(float arg0, float arg1) {
    MKMaterial_SetVertex4F(3, arg0, arg1, 0.0f, 1.0f);
}

void MKSetColorV(const MKVector4 &arg0) {
    MKMaterial_SetVertex4F(1, arg0.unk0, arg0.unk4, arg0.unk8, arg0.unkC);
}

void MKSetColorF(float arg0, float arg1, float arg2, float arg3) {
    MKMaterial_SetVertex4F(1, arg0, arg1, arg2, arg3);
}

void MKBegin(int arg0) {
    MKMaterial_BeginInternal();
    MKMaterial_RenderVerticesBegin(arg0);
}

void MKSetBaseColorV(const MKVector4 &arg0) {
    MKMaterial_SetGeometryColor(arg0);
}

void MKSetBaseColorF(float arg0, float arg1, float arg2, float arg3) {
    f64 sp20;
    f64 sp18;
    f32 sp14;
    f32 sp10;
    f32 spC;
    f32 sp8;

    sp8 = arg0;
    spC = arg1;
    sp10 = arg2;
    sp14 = arg3;
    sp18 = (f64) sp8;
    sp20 = (f64) sp10;
    MKMaterial_SetGeometryColor(*((MKVector4 *) &sp18));
}

void MKSetMatrix(const Matrix &arg0) {
    MKMaterial_SetLocalToWorld(&arg0, 1.0f);
}

void MKPrimitive(int arg0, int arg1) {
    s32 spC;
    s32 sp8;
    s32 temp_r3_222;

    temp_r3_222 = MKMaterialInternal_GetCurrent();
    if ((arg0 & 0x100) || ((u32) temp_r3_222 == 0U)) {
        MKMaterial_SetMaterial(gpMKWhiteMaterial);
    }
    spC = 0;
    sp8 = 1;
    MKMaterial_SetGeometryTransformInfo((GeometryTransformationInfo *) &sp8);
    MKMaterial_SetLocalToWorld(NULL, 1.0f);
    MKMaterial_SetLocalities(NULL, NULL, 1, 0);
    MKMaterial_UseLocality(0);
    if (!(arg1 & 0x100)) {
        MKMaterial_SetGeometryColor(MKVector4::one);
    }
    MKMaterial_Begin();
    MKMaterial_RenderImmediateBegin((u32) arg0, (u32) arg1);
}
