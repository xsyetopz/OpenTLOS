#ifndef UNPLACED_TEMPLATES_H
#define UNPLACED_TEMPLATES_H

// Free function templates whose original header is not yet known (tools/srcgen/tmplfuncs.py).

class CharacterBodyFX;
class DSText;
class Enemy;
class FireBossDriverGoal_Think;
class KDAnimScriptProperty;
class KDCameraHeroData;
class KDCameraHeroMoveYaw;
class KDCameraJumpTargetOffset;
class KDCameraPoint;
class KDCameraSimpleDelta;
class KDCameraStateChangeRequest;
class KDCameraStateStack;
class KDCollisionObject;
class KDGraphNode;
class KDMatrixProperty;
class KDMessageHandlerProperty;
class KDMessageStorage;
class KDModelProperty;
class KDParticleEmitter;
class KDParticleSystemProperty;
class KDPathProperty;
class KDPositionProperty;
class KDProperty;
class KDScriptProperty;
class KDSplinePathProperty;
class KDSynkerPlayer3;
class LevelButton;
class LevelSelectButtons;
class Lever;
class MCSaveScreen;
class MKMessage;
class MKProp;
class MKPropDescriptor;
class MKVector3;
class MKVector4;
class Matrix;
class MeshChunkGC;
class OptionButton;
class PromptGroup;
class ScriptButton;
class ScriptProgressBar;
class Sparx;
class SpawnPointData;
class Targetable;
class TriggerObject;
class UIButton;
class UIButtonGroup;
class UIContainer;
class UIImage;
class UIObject;
class UIScreen;
class UISystem;
class UIText;

template <class T0> void ByteReverse(T0 &);
template <class T0> T0 Clamp(const T0 &, const T0 &, const T0 &);
template <class T0> long Endian(T0 &);
template <class T0> void KDMath_CriticalDamp(const T0 &, const T0 &, const T0 &, float, float);
template <class T0> void KDMath_Dampen(const T0 &, float, float);
template <class T0> void KDMath_Smooth(const T0 &, const T0 &, float, float);
template <class T0> T0 Min(const T0 &, const T0 &);
template <int T0> void Model_RenderChunkGC(MeshChunkGC *, float *, unsigned long, const Matrix *);
template <class T0, class T1> T0 checked_cast(T1 *);
template <class T0, class T1> T0 property_cast(T1);
template <class T0, class T1> void property_cast_ptr(T0 *&, T1 *);
template <class T0> void safe_delete(T0 *&);
template <class T0, class T1> T0 ui_cast(T1);
template <class T0, class T1> void ui_cast_ptr(T0 *&, T1 *);

#endif  // UNPLACED_TEMPLATES_H
