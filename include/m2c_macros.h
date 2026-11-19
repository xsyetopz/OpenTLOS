#ifndef M2C_MACROS_H
#define M2C_MACROS_H

/*
 * Scaffolding for first-draft sources converted from m2c output
 * (tools/srcgen/cxxconv.py). Each use marks code that is not yet real
 * source: an unknown type, an unresolved field, or an instruction m2c could
 * not express. A TU is done when it no longer includes this header.
 */

#include <dolphin/types.h>
#include <string.h>

typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;

/* A field the headers do not declare yet. */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_SYNC() (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#define M2C_MEMCPY_ALIGNED memcpy
#define M2C_MEMCPY_UNALIGNED memcpy
#define M2C_STRUCT_COPY memcpy

#endif  // M2C_MACROS_H
