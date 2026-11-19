#ifndef SPYRO_SOURCE_CREATIONTABLE_H
#define SPYRO_SOURCE_CREATIONTABLE_H

#include <dolphin/types.h>
#include "common/Source/MKBaseParticleSystem.h"
#include "common/Source/MKProp.h"
#include "spyro/source/KDProp.h"
#include "spyro/source/SplineProp.h"
#include "spyro/source/TriggerProp.h"

class ChunkPropDescriptor;
class ConsolePropDescriptor;
class CrashMistPSDescriptor;
class CrashSparkPSDescriptor;
class CreationTable_cpp;
class CreditsPropDescriptor;
class CrittersDescriptor;
class EnvironmentFXDescriptor;
class GunPowderFuseDescriptor;
class KDPropDescriptor;
class MKBaseParticleSystemDescriptor;
class MKPropDescriptor;
class ScriptPropDescriptor;
class SparkleEffectDescriptor;
class SparxPathDescriptor;
class SplinePropDescriptor;
class TriggerBoxPropDescriptor;
class TriggerPropDescriptor;
class VolcanoRumbleDescriptor;

class ChunkPropDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
};

class ConsolePropDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
};

class CrashMistPSDescriptor : public MKBaseParticleSystemDescriptor {  // base: vtable prefix
public:
};

class CrashSparkPSDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
};

class CreationTable_cpp {
public:
    void __sinit(void);
};

class CreditsPropDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
};

class CrittersDescriptor : public KDPropDescriptor {  // base: ctor/dtor vtable stores
public:
};

class EnvironmentFXDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
};

class GunPowderFuseDescriptor : public SplinePropDescriptor {  // base: vtable prefix
public:
};

class ScriptPropDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
};

class SparkleEffectDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
};

class SparxPathDescriptor : public SplinePropDescriptor {  // base: vtable prefix
public:
};

class TriggerBoxPropDescriptor : public TriggerPropDescriptor {  // base: ctor/dtor vtable stores
public:
};

class VolcanoRumbleDescriptor : public MKPropDescriptor {  // base: vtable prefix
public:
};

extern u8 gCreationTable[0xeb8];
#endif  // SPYRO_SOURCE_CREATIONTABLE_H
