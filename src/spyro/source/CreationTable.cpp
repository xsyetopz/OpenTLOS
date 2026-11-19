#include "spyro/source/CreationTable.h"
#include "common/Source/MKAnimScript.h"
#include "common/Source/MKHeap.h"
#include "common/Source/MKProp.h"
#include "spyro/source/Arrow.h"
#include "spyro/source/ArrowTrap.h"
#include "spyro/source/AssaultCannon.h"
#include "spyro/source/Ball.h"
#include "spyro/source/Barricade.h"
#include "spyro/source/BeetleNestSmall.h"
#include "spyro/source/BigBeetleHive.h"
#include "spyro/source/BoulderRamp.h"
#include "spyro/source/Button.h"
#include "spyro/source/Chest.h"
#include "spyro/source/Conveyor.h"
#include "spyro/source/ConveyorBucket.h"
#include "spyro/source/Crate.h"
#include "spyro/source/CynderBarracks.h"
#include "spyro/source/CynderElecAttack.h"
#include "spyro/source/CynderEnergyCrystal.h"
#include "spyro/source/CynderPortcullis.h"
#include "spyro/source/Door.h"
#include "spyro/source/DragonBust.h"
#include "spyro/source/DragonBustDoor.h"
#include "spyro/source/DropBox.h"
#include "spyro/source/Dynamite.h"
#include "spyro/source/EarthBombFX.h"
#include "spyro/source/Elevator.h"
#include "spyro/source/ExDescriptorCreatorHelper.h"
#include "spyro/source/ExPropCreatorHelper.h"
#include "spyro/source/ExplosiveBarrel.h"
#include "spyro/source/ExplosiveBarrelSpawner.h"
#include "spyro/source/FXBase.h"
#include "spyro/source/FightElevator.h"
#include "spyro/source/FightElevatorAnchor.h"
#include "spyro/source/FireBombFX.h"
#include "spyro/source/FireMolePrison.h"
#include "spyro/source/FireMolePrisonDescriptor.h"
#include "spyro/source/FireTrap.h"
#include "spyro/source/FloatingPlatform.h"
#include "spyro/source/FloatingPlatformDescriptor.h"
#include "spyro/source/FloorSwitch.h"
#include "spyro/source/FlyingChunkPS.h"
#include "spyro/source/FlyingMonkey.h"
#include "spyro/source/GameParticleEmitter.h"
#include "spyro/source/GameProp.h"
#include "spyro/source/GamePropColored.h"
#include "spyro/source/Gondola.h"
#include "spyro/source/GoopFX.h"
#include "spyro/source/GuardTower.h"
#include "spyro/source/GuardTowerDescriptor.h"
#include "spyro/source/GuardianCage.h"
#include "spyro/source/GuardianCageCrystal.h"
#include "spyro/source/HotSpit.h"
#include "spyro/source/IceBossStalactite.h"
#include "spyro/source/IceBossStomp.h"
#include "spyro/source/IceShard.h"
#include "spyro/source/IceSquirt.h"
#include "spyro/source/KDPropEx.h"
#include "spyro/source/KnifeTrap.h"
#include "spyro/source/LavaBall.h"
#include "spyro/source/LavaBubbleFX.h"
#include "spyro/source/LavaCannon.h"
#include "spyro/source/LavaDerick.h"
#include "spyro/source/LavaSmashProp.h"
#include "spyro/source/Lever.h"
#include "spyro/source/Leviathan.h"
#include "spyro/source/LightProp.h"
#include "spyro/source/LiquidFX.h"
#include "spyro/source/MagicDrain.h"
#include "spyro/source/MagicFireball.h"
#include "spyro/source/MagmaSquirt.h"
#include "spyro/source/MeleeTrails.h"
#include "spyro/source/MineCart.h"
#include "spyro/source/MineCartDoor.h"
#include "spyro/source/MobilePlatform.h"
#include "spyro/source/MoleTether.h"
#include "spyro/source/MoltenMetalBucket.h"
#include "spyro/source/Platform.h"
#include "spyro/source/PoisonBomb.h"
#include "spyro/source/PooledShatterProp.h"
#include "spyro/source/ScryingPool.h"
#include "spyro/source/Shatterable.h"
#include "spyro/source/ShatterableBoat.h"
#include "spyro/source/ShatterablePlatform.h"
#include "spyro/source/ShatterablePlatformDescriptor.h"
#include "spyro/source/SiegeTower.h"
#include "spyro/source/Sludge.h"
#include "spyro/source/SmashWall.h"
#include "spyro/source/SmashWallDescriptor.h"
#include "spyro/source/SolidSlug.h"
#include "spyro/source/SonicAttack.h"
#include "spyro/source/SpeedwayAA.h"
#include "spyro/source/SpikeTrap.h"
#include "spyro/source/SpyroUtils.h"
#include "spyro/source/SquishBoulder.h"
#include "spyro/source/SteamFireBall.h"
#include "spyro/source/SteamTrain.h"
#include "spyro/source/SteamTrainCaboose.h"
#include "spyro/source/SteamValve.h"
#include "spyro/source/Torch.h"
#include "spyro/source/TotemPolePuzzle.h"
#include "spyro/source/TrainChaseSpyro.h"
#include "spyro/source/TrainGate.h"
#include "spyro/source/WaterWheel.h"
#include "spyro/source/WobbleProp.h"
#include "spyro/source/YawPlatform.h"
#include "spyro/source/ZapArcFX.h"
#include "unplaced_templates.h"
#include <m2c_macros.h>

M2C_UNK __construct_array(f64 *, MKAnimScript *(*)(MKAnimScript *), SpyroSoundPlayer::SpyroLoopSounds *(*)(SpyroSoundPlayer::SpyroLoopSounds *, s16), M2C_UNK, M2C_UNK, void *, M2C_UNK); /* extern */
TrainChaseSpyro *malloc(s32);                       /* extern */
extern f32 SPYRO_BOUNCE_Y_SPEED;
extern f32 SPYRO_MIN_JUMP_Y_VELOCITY;

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<TotemPolePuzzle,
GamePropDescriptor *ExDescriptorCreatorHelper<TotemPolePuzzle, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_18;

    operator new(0xE4U, NULL, 0);
    var_r4_18 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_18 != NULL) {
        var_r4_18 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_18->unk70 = 0xF0;
    return var_r4_18;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<TotemPolePiece,
GamePropDescriptor *ExDescriptorCreatorHelper<TotemPolePiece, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_42;

    operator new(0xE4U, NULL, 0);
    var_r4_42 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_42 != NULL) {
        var_r4_42 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_42->unk70 = 0xE8;
    return var_r4_42;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<DragonBust,
GamePropDescriptor *ExDescriptorCreatorHelper<DragonBust, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_66;

    operator new(0xE4U, NULL, 0);
    var_r4_66 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_66 != NULL) {
        var_r4_66 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_66->unk70 = 0x160;
    return var_r4_66;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Ball, BallDescriptor>::Create()'
BallDescriptor *ExDescriptorCreatorHelper<Ball, BallDescriptor>::Create() {
    BallDescriptor *var_r4_90;

    operator new(0x12CU, NULL, 0);
    var_r4_90 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_90 != NULL) {
        var_r4_90 = ((BallDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->BallDescriptor();
    }
    var_r4_90->unk70 = 0x2B0;
    return var_r4_90;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<GuardianCage,
GamePropDescriptor *ExDescriptorCreatorHelper<GuardianCage, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_114;

    operator new(0xE4U, NULL, 0);
    var_r4_114 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_114 != NULL) {
        var_r4_114 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_114->unk70 = 0x160;
    return var_r4_114;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<LightProp,
GamePropDescriptor *ExDescriptorCreatorHelper<LightProp, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_138;

    operator new(0xE4U, NULL, 0);
    var_r4_138 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_138 != NULL) {
        var_r4_138 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_138->unk70 = 0xE8;
    return var_r4_138;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Torch,
GamePropDescriptor *ExDescriptorCreatorHelper<Torch, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_162;

    operator new(0xE4U, NULL, 0);
    var_r4_162 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_162 != NULL) {
        var_r4_162 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_162->unk70 = 0x120;
    return var_r4_162;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<KDPropEx,
KDPropExDescriptor *ExDescriptorCreatorHelper<KDPropEx, KDPropExDescriptor>::Create() {
    KDPropExDescriptor *var_r4_186;

    operator new(0xC0U, NULL, 0);
    var_r4_186 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_186 != NULL) {
        var_r4_186 = ((KDPropExDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->KDPropExDescriptor();
    }
    var_r4_186->unk70 = 0x90;
    return var_r4_186;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<GameProp,
GamePropDescriptor *ExDescriptorCreatorHelper<GameProp, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_210;

    operator new(0xE4U, NULL, 0);
    var_r4_210 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_210 != NULL) {
        var_r4_210 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_210->unk70 = 0xC8;
    return var_r4_210;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Elevator,
GamePropDescriptor *ExDescriptorCreatorHelper<Elevator, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_234;

    operator new(0xE4U, NULL, 0);
    var_r4_234 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_234 != NULL) {
        var_r4_234 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_234->unk70 = 0x160;
    return var_r4_234;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<ConveyorBucket,
GamePropDescriptor *ExDescriptorCreatorHelper<ConveyorBucket, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_258;

    operator new(0xE4U, NULL, 0);
    var_r4_258 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_258 != NULL) {
        var_r4_258 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_258->unk70 = 0xF0;
    return var_r4_258;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Conveyor,
GamePropDescriptor *ExDescriptorCreatorHelper<Conveyor, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_282;

    operator new(0xE4U, NULL, 0);
    var_r4_282 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_282 != NULL) {
        var_r4_282 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_282->unk70 = 0x158;
    return var_r4_282;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<ZapArcFX,
GamePropDescriptor *ExDescriptorCreatorHelper<ZapArcFX, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_306;

    operator new(0xE4U, NULL, 0);
    var_r4_306 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_306 != NULL) {
        var_r4_306 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_306->unk70 = 0xD8;
    return var_r4_306;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<LavaBubbleFX,
GamePropDescriptor *ExDescriptorCreatorHelper<LavaBubbleFX, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_330;

    operator new(0xE4U, NULL, 0);
    var_r4_330 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_330 != NULL) {
        var_r4_330 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_330->unk70 = 0xD8;
    return var_r4_330;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<GameParticleEmitter,
GamePropDescriptor *ExDescriptorCreatorHelper<GameParticleEmitter, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_354;

    operator new(0xE4U, NULL, 0);
    var_r4_354 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_354 != NULL) {
        var_r4_354 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_354->unk70 = 0x118;
    return var_r4_354;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<TrainChaseSpyro,
GamePropDescriptor *ExDescriptorCreatorHelper<TrainChaseSpyro, GamePropDescriptor>::Create() {
    GamePropDescriptor *var_r4_378;

    operator new(0xE4U, NULL, 0);
    var_r4_378 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_378 != NULL) {
        var_r4_378 = ((GamePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropDescriptor();
    }
    var_r4_378->unk70 = 0x750;
    return var_r4_378;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<FireBombFX,
FireBombFXDescriptor *ExDescriptorCreatorHelper<FireBombFX, FireBombFXDescriptor>::Create() {
    FireBombFXDescriptor *var_r4_13980;

    operator new(0xF0U, NULL, 0);
    var_r4_13980 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_13980 != NULL) {
        var_r4_13980 = ((FireBombFXDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->FireBombFXDescriptor();
    }
    var_r4_13980->unk70 = 0x1E0;
    return var_r4_13980;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<LiquidFX,
LiquidFXDescriptor *ExDescriptorCreatorHelper<LiquidFX, LiquidFXDescriptor>::Create() {
    LiquidFXDescriptor *var_r4_14024;

    operator new(0xF4U, NULL, 0);
    var_r4_14024 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14024 != NULL) {
        var_r4_14024 = ((LiquidFXDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->LiquidFXDescriptor();
    }
    var_r4_14024->unk70 = 0x3F90;
    return var_r4_14024;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<MeleeTrails,
MeleeTrailsDescriptor *ExDescriptorCreatorHelper<MeleeTrails, MeleeTrailsDescriptor>::Create() {
    MeleeTrailsDescriptor *var_r4_14068;

    operator new(0x128U, NULL, 0);
    var_r4_14068 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14068 != NULL) {
        var_r4_14068 = ((MeleeTrailsDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->MeleeTrailsDescriptor();
    }
    var_r4_14068->unk70 = 0xD8;
    return var_r4_14068;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<FlyingChunkPS,
FlyingChunkPSDescriptor *ExDescriptorCreatorHelper<FlyingChunkPS, FlyingChunkPSDescriptor>::Create() {
    FlyingChunkPSDescriptor *var_r4_14112;

    operator new(0x108U, NULL, 0);
    var_r4_14112 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14112 != NULL) {
        var_r4_14112 = ((FlyingChunkPSDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->FlyingChunkPSDescriptor();
    }
    var_r4_14112->unk70 = 0xE0;
    return var_r4_14112;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<GoopFX, GoopFXDescriptor>::Create()'
GoopFXDescriptor *ExDescriptorCreatorHelper<GoopFX, GoopFXDescriptor>::Create() {
    GoopFXDescriptor *var_r4_14176;

    operator new(0x130U, NULL, 0);
    var_r4_14176 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14176 != NULL) {
        var_r4_14176 = ((GoopFXDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GoopFXDescriptor();
    }
    var_r4_14176->unk70 = 0x90;
    return var_r4_14176;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<FXBase, FXBaseDescriptor>::Create()'
FXBaseDescriptor *ExDescriptorCreatorHelper<FXBase, FXBaseDescriptor>::Create() {
    FXBaseDescriptor *var_r4_14240;

    operator new(0xE0U, NULL, 0);
    var_r4_14240 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14240 != NULL) {
        var_r4_14240 = ((FXBaseDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->FXBaseDescriptor();
    }
    var_r4_14240->unk70 = 0x90;
    return var_r4_14240;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<EarthBombFX,
EarthBombFXDescriptor *ExDescriptorCreatorHelper<EarthBombFX, EarthBombFXDescriptor>::Create() {
    EarthBombFXDescriptor *var_r4_14264;

    operator new(0xF0U, NULL, 0);
    var_r4_14264 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14264 != NULL) {
        var_r4_14264 = ((EarthBombFXDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->EarthBombFXDescriptor();
    }
    var_r4_14264->unk70 = 0x1A8;
    return var_r4_14264;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Button, ButtonDescriptor>::Create()'
ButtonDescriptor *ExDescriptorCreatorHelper<Button, ButtonDescriptor>::Create() {
    ButtonDescriptor *var_r4_14308;

    operator new(0xF4U, NULL, 0);
    var_r4_14308 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14308 != NULL) {
        var_r4_14308 = ((ButtonDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ButtonDescriptor();
    }
    var_r4_14308->unk70 = 0xF0;
    return var_r4_14308;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Crate, CrateDescriptor>::Create()'
CrateDescriptor *ExDescriptorCreatorHelper<Crate, CrateDescriptor>::Create() {
    CrateDescriptor *var_r4_14372;

    operator new(0x1CCU, NULL, 0);
    var_r4_14372 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14372 != NULL) {
        var_r4_14372 = ((CrateDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->CrateDescriptor();
    }
    var_r4_14372->unk70 = 0x1E8;
    return var_r4_14372;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<DragonBustDoor,
DoorDescriptor *ExDescriptorCreatorHelper<DragonBustDoor, DoorDescriptor>::Create() {
    DoorDescriptor *var_r4_14416;

    operator new(0xF8U, NULL, 0);
    var_r4_14416 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14416 != NULL) {
        var_r4_14416 = ((DoorDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->DoorDescriptor();
    }
    var_r4_14416->unk70 = 0x108;
    return var_r4_14416;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<LavaSmashProp,
LavaSmashPropDescriptor *ExDescriptorCreatorHelper<LavaSmashProp, LavaSmashPropDescriptor>::Create() {
    LavaSmashPropDescriptor *var_r4_14460;

    operator new(0x188U, NULL, 0);
    var_r4_14460 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14460 != NULL) {
        var_r4_14460 = ((LavaSmashPropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->LavaSmashPropDescriptor();
    }
    var_r4_14460->unk70 = 0x208;
    return var_r4_14460;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<LavaDerick,
LavaDerickDescriptor *ExDescriptorCreatorHelper<LavaDerick, LavaDerickDescriptor>::Create() {
    LavaDerickDescriptor *var_r4_14524;

    operator new(0x16CU, NULL, 0);
    var_r4_14524 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14524 != NULL) {
        var_r4_14524 = ((LavaDerickDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->LavaDerickDescriptor();
    }
    var_r4_14524->unk70 = 0x1A8;
    return var_r4_14524;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<MineCart,
MineCartDescriptor *ExDescriptorCreatorHelper<MineCart, MineCartDescriptor>::Create() {
    MineCartDescriptor *var_r4_14636;

    operator new(0xF0U, NULL, 0);
    var_r4_14636 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14636 != NULL) {
        var_r4_14636 = ((MineCartDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->MineCartDescriptor();
    }
    var_r4_14636->unk70 = 0x1A8;
    return var_r4_14636;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<MineCartDoor,
MineCartDoorDescriptor *ExDescriptorCreatorHelper<MineCartDoor, MineCartDoorDescriptor>::Create() {
    MineCartDoorDescriptor *var_r4_14680;

    operator new(0xF4U, NULL, 0);
    var_r4_14680 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14680 != NULL) {
        var_r4_14680 = ((MineCartDoorDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->MineCartDoorDescriptor();
    }
    var_r4_14680->unk70 = 0xD0;
    return var_r4_14680;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<MoltenMetalBucket,
MoltenMetalBucketDescriptor *ExDescriptorCreatorHelper<MoltenMetalBucket, MoltenMetalBucketDescriptor>::Create() {
    MoltenMetalBucketDescriptor *var_r4_14724;

    operator new(0x128U, NULL, 0);
    var_r4_14724 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14724 != NULL) {
        var_r4_14724 = ((MoltenMetalBucketDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->MoltenMetalBucketDescriptor();
    }
    var_r4_14724->unk70 = 0x1D8;
    return var_r4_14724;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SteamValve,
SteamValveDescriptor *ExDescriptorCreatorHelper<SteamValve, SteamValveDescriptor>::Create() {
    SteamValveDescriptor *var_r4_14768;

    operator new(0xE8U, NULL, 0);
    var_r4_14768 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14768 != NULL) {
        var_r4_14768 = ((SteamValveDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SteamValveDescriptor();
    }
    var_r4_14768->unk70 = 0xE0;
    return var_r4_14768;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<ExplosiveBarrel,
ExplosiveBarrelDescriptor *ExDescriptorCreatorHelper<ExplosiveBarrel, ExplosiveBarrelDescriptor>::Create() {
    ExplosiveBarrelDescriptor *var_r4_14812;

    operator new(0x17CU, NULL, 0);
    var_r4_14812 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14812 != NULL) {
        var_r4_14812 = ((ExplosiveBarrelDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ExplosiveBarrelDescriptor();
    }
    var_r4_14812->unk70 = 0x1C0;
    return var_r4_14812;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SteamTrain,
SteamTrainDescriptor *ExDescriptorCreatorHelper<SteamTrain, SteamTrainDescriptor>::Create() {
    SteamTrainDescriptor *var_r4_14856;

    operator new(0xFCU, NULL, 0);
    var_r4_14856 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14856 != NULL) {
        var_r4_14856 = ((SteamTrainDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SteamTrainDescriptor();
    }
    var_r4_14856->unk70 = 0x3F8;
    return var_r4_14856;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SteamTrainCaboose,
SteamTrainCabooseDescriptor *ExDescriptorCreatorHelper<SteamTrainCaboose, SteamTrainCabooseDescriptor>::Create() {
    SteamTrainCabooseDescriptor *var_r4_14900;

    operator new(0xF8U, NULL, 0);
    var_r4_14900 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14900 != NULL) {
        var_r4_14900 = ((SteamTrainCabooseDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SteamTrainCabooseDescriptor();
    }
    var_r4_14900->unk70 = 0x168;
    return var_r4_14900;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<TrainGate,
TrainGateDescriptor *ExDescriptorCreatorHelper<TrainGate, TrainGateDescriptor>::Create() {
    TrainGateDescriptor *var_r4_14944;

    operator new(0xF0U, NULL, 0);
    var_r4_14944 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14944 != NULL) {
        var_r4_14944 = ((TrainGateDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->TrainGateDescriptor();
    }
    var_r4_14944->unk70 = 0xD8;
    return var_r4_14944;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Lever, LeverDescriptor>::Create()'
LeverDescriptor *ExDescriptorCreatorHelper<Lever, LeverDescriptor>::Create() {
    LeverDescriptor *var_r4_14988;

    operator new(0xFCU, NULL, 0);
    var_r4_14988 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_14988 != NULL) {
        var_r4_14988 = ((LeverDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->LeverDescriptor();
    }
    var_r4_14988->unk70 = 0x108;
    return var_r4_14988;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<WobbleProp,
WobblePropDescriptor *ExDescriptorCreatorHelper<WobbleProp, WobblePropDescriptor>::Create() {
    WobblePropDescriptor *var_r4_15032;

    operator new(0xF0U, NULL, 0);
    var_r4_15032 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15032 != NULL) {
        var_r4_15032 = ((WobblePropDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->WobblePropDescriptor();
    }
    var_r4_15032->unk70 = 0xF0;
    return var_r4_15032;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<MobilePlatform,
MobilePlatformDescriptor *ExDescriptorCreatorHelper<MobilePlatform, MobilePlatformDescriptor>::Create() {
    MobilePlatformDescriptor *var_r4_15076;

    operator new(0x150U, NULL, 0);
    var_r4_15076 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15076 != NULL) {
        var_r4_15076 = ((MobilePlatformDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->MobilePlatformDescriptor();
    }
    var_r4_15076->unk70 = 0x260;
    return var_r4_15076;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Platform,
PlatformDescriptor *ExDescriptorCreatorHelper<Platform, PlatformDescriptor>::Create() {
    PlatformDescriptor *var_r4_15140;

    operator new(0x124U, NULL, 0);
    var_r4_15140 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15140 != NULL) {
        var_r4_15140 = ((PlatformDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->PlatformDescriptor();
    }
    var_r4_15140->unk70 = 0x180;
    return var_r4_15140;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Shatterable,
ShatterableDescriptor *ExDescriptorCreatorHelper<Shatterable, ShatterableDescriptor>::Create() {
    ShatterableDescriptor *var_r4_15164;

    operator new(0x16CU, NULL, 0);
    var_r4_15164 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15164 != NULL) {
        var_r4_15164 = ((ShatterableDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ShatterableDescriptor();
    }
    var_r4_15164->unk70 = 0x1A8;
    return var_r4_15164;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<FloatingPlatform,
FloatingPlatformDescriptor *ExDescriptorCreatorHelper<FloatingPlatform, FloatingPlatformDescriptor>::Create() {
    FloatingPlatformDescriptor *var_r4_15188;

    operator new(0x124U, NULL, 0);
    var_r4_15188 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15188 != NULL) {
        var_r4_15188 = ((FloatingPlatformDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->FloatingPlatformDescriptor();
    }
    var_r4_15188->unk70 = 0x1C8;
    return var_r4_15188;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<PooledShatterProp,
ShatterableDescriptor *ExDescriptorCreatorHelper<PooledShatterProp, ShatterableDescriptor>::Create() {
    ShatterableDescriptor *var_r4_15232;

    operator new(0x16CU, NULL, 0);
    var_r4_15232 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15232 != NULL) {
        var_r4_15232 = ((ShatterableDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ShatterableDescriptor();
    }
    var_r4_15232->unk70 = 0x1A8;
    return var_r4_15232;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SteamFireBall,
SteamFireBallDescriptor *ExDescriptorCreatorHelper<SteamFireBall, SteamFireBallDescriptor>::Create() {
    SteamFireBallDescriptor *var_r4_15256;

    operator new(0xF4U, NULL, 0);
    var_r4_15256 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15256 != NULL) {
        var_r4_15256 = ((SteamFireBallDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SteamFireBallDescriptor();
    }
    var_r4_15256->unk70 = 0x190;
    return var_r4_15256;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<GuardianCageCrystal,
GuardianCageCrystalDescriptor *ExDescriptorCreatorHelper<GuardianCageCrystal, GuardianCageCrystalDescriptor>::Create() {
    GuardianCageCrystalDescriptor *var_r4_15320;

    operator new(0x170U, NULL, 0);
    var_r4_15320 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15320 != NULL) {
        var_r4_15320 = ((GuardianCageCrystalDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GuardianCageCrystalDescriptor();
    }
    var_r4_15320->unk70 = 0x210;
    return var_r4_15320;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<MagmaSquirt,
MagmaSquirtDescriptor *ExDescriptorCreatorHelper<MagmaSquirt, MagmaSquirtDescriptor>::Create() {
    MagmaSquirtDescriptor *var_r4_15364;

    operator new(0xF0U, NULL, 0);
    var_r4_15364 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15364 != NULL) {
        var_r4_15364 = ((MagmaSquirtDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->MagmaSquirtDescriptor();
    }
    var_r4_15364->unk70 = 0x1C8;
    return var_r4_15364;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<IceSquirt,
IceSquirtDescriptor *ExDescriptorCreatorHelper<IceSquirt, IceSquirtDescriptor>::Create() {
    IceSquirtDescriptor *var_r4_15408;

    operator new(0xF0U, NULL, 0);
    var_r4_15408 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15408 != NULL) {
        var_r4_15408 = ((IceSquirtDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->IceSquirtDescriptor();
    }
    var_r4_15408->unk70 = 0x1C0;
    return var_r4_15408;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<GamePropColored,
GamePropColoredDescriptor *ExDescriptorCreatorHelper<GamePropColored, GamePropColoredDescriptor>::Create() {
    GamePropColoredDescriptor *var_r4_15474;

    operator new(0xE8U, NULL, 0);
    var_r4_15474 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15474 != NULL) {
        var_r4_15474 = ((GamePropColoredDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GamePropColoredDescriptor();
    }
    var_r4_15474->unk70 = 0xD8;
    return var_r4_15474;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<MoleTether,
MoleTetherDescriptor *ExDescriptorCreatorHelper<MoleTether, MoleTetherDescriptor>::Create() {
    MoleTetherDescriptor *var_r4_15498;

    operator new(0x170U, NULL, 0);
    var_r4_15498 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15498 != NULL) {
        var_r4_15498 = ((MoleTetherDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->MoleTetherDescriptor();
    }
    var_r4_15498->unk70 = 0x200;
    return var_r4_15498;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<ExplosiveBarrelSpawner,
ExplosiveBarrelSpawnerDescriptor *ExDescriptorCreatorHelper<ExplosiveBarrelSpawner, ExplosiveBarrelSpawnerDescriptor>::Create() {
    ExplosiveBarrelSpawnerDescriptor *var_r4_15542;

    operator new(0xE8U, NULL, 0);
    var_r4_15542 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15542 != NULL) {
        var_r4_15542 = ((ExplosiveBarrelSpawnerDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ExplosiveBarrelSpawnerDescriptor();
    }
    var_r4_15542->unk70 = 0xD0;
    return var_r4_15542;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<GuardTower,
GuardTowerDescriptor *ExDescriptorCreatorHelper<GuardTower, GuardTowerDescriptor>::Create() {
    GuardTowerDescriptor *var_r4_15586;

    operator new(0x188U, NULL, 0);
    var_r4_15586 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15586 != NULL) {
        var_r4_15586 = ((GuardTowerDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GuardTowerDescriptor();
    }
    var_r4_15586->unk70 = 0x210;
    return var_r4_15586;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<FireMolePrison,
FireMolePrisonDescriptor *ExDescriptorCreatorHelper<FireMolePrison, FireMolePrisonDescriptor>::Create() {
    FireMolePrisonDescriptor *var_r4_15630;

    operator new(0x170U, NULL, 0);
    var_r4_15630 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15630 != NULL) {
        var_r4_15630 = ((FireMolePrisonDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->FireMolePrisonDescriptor();
    }
    var_r4_15630->unk70 = 0x218;
    return var_r4_15630;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<BeetleNestSmall,
BeetleNestSmallDescriptor *ExDescriptorCreatorHelper<BeetleNestSmall, BeetleNestSmallDescriptor>::Create() {
    BeetleNestSmallDescriptor *var_r4_15694;

    operator new(0x17CU, NULL, 0);
    var_r4_15694 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15694 != NULL) {
        var_r4_15694 = ((BeetleNestSmallDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->BeetleNestSmallDescriptor();
    }
    var_r4_15694->unk70 = 0x210;
    return var_r4_15694;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<BigBeetleHive,
BigBeetleHiveDescriptor *ExDescriptorCreatorHelper<BigBeetleHive, BigBeetleHiveDescriptor>::Create() {
    BigBeetleHiveDescriptor *var_r4_15738;

    operator new(0x184U, NULL, 0);
    var_r4_15738 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15738 != NULL) {
        var_r4_15738 = ((BigBeetleHiveDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->BigBeetleHiveDescriptor();
    }
    var_r4_15738->unk70 = 0x1F0;
    return var_r4_15738;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<AssaultCannon,
AssaultCannonDescriptor *ExDescriptorCreatorHelper<AssaultCannon, AssaultCannonDescriptor>::Create() {
    AssaultCannonDescriptor *var_r4_15782;

    operator new(0x1ACU, NULL, 0);
    var_r4_15782 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15782 != NULL) {
        var_r4_15782 = ((AssaultCannonDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->AssaultCannonDescriptor();
    }
    var_r4_15782->unk70 = 0x368;
    return var_r4_15782;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<IceBossStalactite,
IceBossStalactiteDescriptor *ExDescriptorCreatorHelper<IceBossStalactite, IceBossStalactiteDescriptor>::Create() {
    IceBossStalactiteDescriptor *var_r4_15846;

    operator new(0x170U, NULL, 0);
    var_r4_15846 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15846 != NULL) {
        var_r4_15846 = ((IceBossStalactiteDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->IceBossStalactiteDescriptor();
    }
    var_r4_15846->unk70 = 0x248;
    return var_r4_15846;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<DropBox,
DropBoxDescriptor *ExDescriptorCreatorHelper<DropBox, DropBoxDescriptor>::Create() {
    DropBoxDescriptor *var_r4_15890;

    operator new(0x178U, NULL, 0);
    var_r4_15890 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15890 != NULL) {
        var_r4_15890 = ((DropBoxDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->DropBoxDescriptor();
    }
    var_r4_15890->unk70 = 0x220;
    return var_r4_15890;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Gondola,
GondolaDescriptor *ExDescriptorCreatorHelper<Gondola, GondolaDescriptor>::Create() {
    GondolaDescriptor *var_r4_15934;

    operator new(0x140U, NULL, 0);
    var_r4_15934 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15934 != NULL) {
        var_r4_15934 = ((GondolaDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->GondolaDescriptor();
    }
    var_r4_15934->unk70 = 0x250;
    return var_r4_15934;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<CynderBarracks,
CynderBarracksDescriptor *ExDescriptorCreatorHelper<CynderBarracks, CynderBarracksDescriptor>::Create() {
    CynderBarracksDescriptor *var_r4_15998;

    operator new(0x188U, NULL, 0);
    var_r4_15998 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_15998 != NULL) {
        var_r4_15998 = ((CynderBarracksDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->CynderBarracksDescriptor();
    }
    var_r4_15998->unk70 = 0x240;
    return var_r4_15998;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<CynderPortcullis,
CynderPortcullisDescriptor *ExDescriptorCreatorHelper<CynderPortcullis, CynderPortcullisDescriptor>::Create() {
    CynderPortcullisDescriptor *var_r4_16042;

    operator new(0x100U, NULL, 0);
    var_r4_16042 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16042 != NULL) {
        var_r4_16042 = ((CynderPortcullisDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->CynderPortcullisDescriptor();
    }
    var_r4_16042->unk70 = 0x150;
    return var_r4_16042;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SiegeTower,
SiegeTowerDescriptor *ExDescriptorCreatorHelper<SiegeTower, SiegeTowerDescriptor>::Create() {
    SiegeTowerDescriptor *var_r4_16086;

    operator new(0x1A0U, NULL, 0);
    var_r4_16086 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16086 != NULL) {
        var_r4_16086 = ((SiegeTowerDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SiegeTowerDescriptor();
    }
    var_r4_16086->unk70 = 0x330;
    return var_r4_16086;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SmashWall,
SmashWallDescriptor *ExDescriptorCreatorHelper<SmashWall, SmashWallDescriptor>::Create() {
    SmashWallDescriptor *var_r4_16130;

    operator new(0x16CU, NULL, 0);
    var_r4_16130 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16130 != NULL) {
        var_r4_16130 = ((SmashWallDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SmashWallDescriptor();
    }
    var_r4_16130->unk70 = 0x1A8;
    return var_r4_16130;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<YawPlatform,
PlatformDescriptor *ExDescriptorCreatorHelper<YawPlatform, PlatformDescriptor>::Create() {
    PlatformDescriptor *var_r4_16174;

    operator new(0x124U, NULL, 0);
    var_r4_16174 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16174 != NULL) {
        var_r4_16174 = ((PlatformDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->PlatformDescriptor();
    }
    var_r4_16174->unk70 = 0x188;
    return var_r4_16174;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<WaterWheel,
PlatformDescriptor *ExDescriptorCreatorHelper<WaterWheel, PlatformDescriptor>::Create() {
    PlatformDescriptor *var_r4_16198;

    operator new(0x124U, NULL, 0);
    var_r4_16198 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16198 != NULL) {
        var_r4_16198 = ((PlatformDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->PlatformDescriptor();
    }
    var_r4_16198->unk70 = 0x1C8;
    return var_r4_16198;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<BarricadeProp,
ShatterableDescriptor *ExDescriptorCreatorHelper<BarricadeProp, ShatterableDescriptor>::Create() {
    ShatterableDescriptor *var_r4_16222;

    operator new(0x16CU, NULL, 0);
    var_r4_16222 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16222 != NULL) {
        var_r4_16222 = ((ShatterableDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ShatterableDescriptor();
    }
    var_r4_16222->unk70 = 0x1B0;
    return var_r4_16222;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<FightElevator,
FightElevatorDescriptor *ExDescriptorCreatorHelper<FightElevator, FightElevatorDescriptor>::Create() {
    FightElevatorDescriptor *var_r4_16246;

    operator new(0x134U, NULL, 0);
    var_r4_16246 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16246 != NULL) {
        var_r4_16246 = ((FightElevatorDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->FightElevatorDescriptor();
    }
    var_r4_16246->unk70 = 0x2C0;
    return var_r4_16246;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<FightElevatorAnchor,
ShatterableDescriptor *ExDescriptorCreatorHelper<FightElevatorAnchor, ShatterableDescriptor>::Create() {
    ShatterableDescriptor *var_r4_16290;

    operator new(0x16CU, NULL, 0);
    var_r4_16290 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16290 != NULL) {
        var_r4_16290 = ((ShatterableDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ShatterableDescriptor();
    }
    var_r4_16290->unk70 = 0x1B0;
    return var_r4_16290;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SolidSlug,
SolidSlugDescriptor *ExDescriptorCreatorHelper<SolidSlug, SolidSlugDescriptor>::Create() {
    SolidSlugDescriptor *var_r4_16314;

    operator new(0xF8U, NULL, 0);
    var_r4_16314 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16314 != NULL) {
        var_r4_16314 = ((SolidSlugDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SolidSlugDescriptor();
    }
    var_r4_16314->unk70 = 0x150;
    return var_r4_16314;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<IceShard,
IceShardDescriptor *ExDescriptorCreatorHelper<IceShard, IceShardDescriptor>::Create() {
    IceShardDescriptor *var_r4_16358;

    operator new(0xF0U, NULL, 0);
    var_r4_16358 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16358 != NULL) {
        var_r4_16358 = ((IceShardDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->IceShardDescriptor();
    }
    var_r4_16358->unk70 = 0x150;
    return var_r4_16358;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SpeedwayAA,
SpeedwayAADescriptor *ExDescriptorCreatorHelper<SpeedwayAA, SpeedwayAADescriptor>::Create() {
    SpeedwayAADescriptor *var_r4_16402;

    operator new(0xF0U, NULL, 0);
    var_r4_16402 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16402 != NULL) {
        var_r4_16402 = ((SpeedwayAADescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SpeedwayAADescriptor();
    }
    var_r4_16402->unk70 = 0x150;
    return var_r4_16402;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<CynderElecAttack,
CynderElecAttackDescriptor *ExDescriptorCreatorHelper<CynderElecAttack, CynderElecAttackDescriptor>::Create() {
    CynderElecAttackDescriptor *var_r4_16446;

    operator new(0xF4U, NULL, 0);
    var_r4_16446 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16446 != NULL) {
        var_r4_16446 = ((CynderElecAttackDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->CynderElecAttackDescriptor();
    }
    var_r4_16446->unk70 = 0x168;
    return var_r4_16446;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<PoisonBomb,
PoisonBombDescriptor *ExDescriptorCreatorHelper<PoisonBomb, PoisonBombDescriptor>::Create() {
    PoisonBombDescriptor *var_r4_16490;

    operator new(0xF8U, NULL, 0);
    var_r4_16490 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16490 != NULL) {
        var_r4_16490 = ((PoisonBombDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->PoisonBombDescriptor();
    }
    var_r4_16490->unk70 = 0x1D8;
    return var_r4_16490;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<ShatterablePlatform,
ShatterablePlatformDescriptor *ExDescriptorCreatorHelper<ShatterablePlatform, ShatterablePlatformDescriptor>::Create() {
    ShatterablePlatformDescriptor *var_r4_16534;

    operator new(0x16CU, NULL, 0);
    var_r4_16534 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16534 != NULL) {
        var_r4_16534 = ((ShatterablePlatformDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ShatterablePlatformDescriptor();
    }
    var_r4_16534->unk70 = 0x218;
    return var_r4_16534;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<CynderEnergyCrystal,
CynderEnergyCrystalDescriptor *ExDescriptorCreatorHelper<CynderEnergyCrystal, CynderEnergyCrystalDescriptor>::Create() {
    CynderEnergyCrystalDescriptor *var_r4_16558;

    operator new(0x130U, NULL, 0);
    var_r4_16558 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16558 != NULL) {
        var_r4_16558 = ((CynderEnergyCrystalDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->CynderEnergyCrystalDescriptor();
    }
    var_r4_16558->unk70 = 0x5F0;
    return var_r4_16558;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SquishBoulder,
SquishBoulderDescriptor *ExDescriptorCreatorHelper<SquishBoulder, SquishBoulderDescriptor>::Create() {
    SquishBoulderDescriptor *var_r4_16602;

    operator new(0x174U, NULL, 0);
    var_r4_16602 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16602 != NULL) {
        var_r4_16602 = ((SquishBoulderDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SquishBoulderDescriptor();
    }
    var_r4_16602->unk70 = 0x2A0;
    return var_r4_16602;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<ShatterableBoat,
ShatterableBoatDescriptor *ExDescriptorCreatorHelper<ShatterableBoat, ShatterableBoatDescriptor>::Create() {
    ShatterableBoatDescriptor *var_r4_16646;

    operator new(0x174U, NULL, 0);
    var_r4_16646 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16646 != NULL) {
        var_r4_16646 = ((ShatterableBoatDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ShatterableBoatDescriptor();
    }
    var_r4_16646->unk70 = 0x370;
    return var_r4_16646;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Leviathan,
PlatformDescriptor *ExDescriptorCreatorHelper<Leviathan, PlatformDescriptor>::Create() {
    PlatformDescriptor *var_r4_16690;

    operator new(0x124U, NULL, 0);
    var_r4_16690 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16690 != NULL) {
        var_r4_16690 = ((PlatformDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->PlatformDescriptor();
    }
    var_r4_16690->unk70 = 0x1E8;
    return var_r4_16690;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<MagicDrain,
MagicDrainDescriptor *ExDescriptorCreatorHelper<MagicDrain, MagicDrainDescriptor>::Create() {
    MagicDrainDescriptor *var_r4_16714;

    operator new(0xF0U, NULL, 0);
    var_r4_16714 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16714 != NULL) {
        var_r4_16714 = ((MagicDrainDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->MagicDrainDescriptor();
    }
    var_r4_16714->unk70 = 0x1C0;
    return var_r4_16714;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<ScryingPool,
ScryingPoolDescriptor *ExDescriptorCreatorHelper<ScryingPool, ScryingPoolDescriptor>::Create() {
    ScryingPoolDescriptor *var_r4_16758;

    operator new(0xC8U, NULL, 0);
    var_r4_16758 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16758 != NULL) {
        var_r4_16758 = ((ScryingPoolDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ScryingPoolDescriptor();
    }
    var_r4_16758->unk70 = 0xC0;
    return var_r4_16758;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Arrow, ArrowDescriptor>::Create()'
ArrowDescriptor *ExDescriptorCreatorHelper<Arrow, ArrowDescriptor>::Create() {
    ArrowDescriptor *var_r4_16802;

    operator new(0xE4U, NULL, 0);
    var_r4_16802 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16802 != NULL) {
        var_r4_16802 = ((ArrowDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ArrowDescriptor();
    }
    var_r4_16802->unk70 = 0xF0;
    return var_r4_16802;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<ArrowTrap,
ArrowTrapDescriptor *ExDescriptorCreatorHelper<ArrowTrap, ArrowTrapDescriptor>::Create() {
    ArrowTrapDescriptor *var_r4_16846;

    operator new(0xE4U, NULL, 0);
    var_r4_16846 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16846 != NULL) {
        var_r4_16846 = ((ArrowTrapDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ArrowTrapDescriptor();
    }
    var_r4_16846->unk70 = 0xE0;
    return var_r4_16846;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<BoulderRamp,
BoulderRampDescriptor *ExDescriptorCreatorHelper<BoulderRamp, BoulderRampDescriptor>::Create() {
    BoulderRampDescriptor *var_r4_16890;

    operator new(0xF0U, NULL, 0);
    var_r4_16890 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16890 != NULL) {
        var_r4_16890 = ((BoulderRampDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->BoulderRampDescriptor();
    }
    var_r4_16890->unk70 = 0x120;
    return var_r4_16890;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Chest, ChestDescriptor>::Create()'
ChestDescriptor *ExDescriptorCreatorHelper<Chest, ChestDescriptor>::Create() {
    ChestDescriptor *var_r4_16934;

    operator new(0xF0U, NULL, 0);
    var_r4_16934 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16934 != NULL) {
        var_r4_16934 = ((ChestDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->ChestDescriptor();
    }
    var_r4_16934->unk70 = 0xF0;
    return var_r4_16934;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Door, DoorDescriptor>::Create()'
DoorDescriptor *ExDescriptorCreatorHelper<Door, DoorDescriptor>::Create() {
    DoorDescriptor *var_r4_16978;

    operator new(0xF8U, NULL, 0);
    var_r4_16978 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_16978 != NULL) {
        var_r4_16978 = ((DoorDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->DoorDescriptor();
    }
    var_r4_16978->unk70 = 0xE8;
    return var_r4_16978;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<FireTrap,
FireTrapDescriptor *ExDescriptorCreatorHelper<FireTrap, FireTrapDescriptor>::Create() {
    FireTrapDescriptor *var_r4_17002;

    operator new(0xE4U, NULL, 0);
    var_r4_17002 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17002 != NULL) {
        var_r4_17002 = ((FireTrapDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->FireTrapDescriptor();
    }
    var_r4_17002->unk70 = 0xE8;
    return var_r4_17002;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<FloorSwitch,
FloorSwitchDescriptor *ExDescriptorCreatorHelper<FloorSwitch, FloorSwitchDescriptor>::Create() {
    FloorSwitchDescriptor *var_r4_17046;

    operator new(0x10CU, NULL, 0);
    var_r4_17046 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17046 != NULL) {
        var_r4_17046 = ((FloorSwitchDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->FloorSwitchDescriptor();
    }
    var_r4_17046->unk70 = 0x130;
    return var_r4_17046;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<KnifeTrap,
KnifeTrapDescriptor *ExDescriptorCreatorHelper<KnifeTrap, KnifeTrapDescriptor>::Create() {
    KnifeTrapDescriptor *var_r4_17090;

    operator new(0xE4U, NULL, 0);
    var_r4_17090 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17090 != NULL) {
        var_r4_17090 = ((KnifeTrapDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->KnifeTrapDescriptor();
    }
    var_r4_17090->unk70 = 0xE0;
    return var_r4_17090;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<LavaCannon,
LavaCannonDescriptor *ExDescriptorCreatorHelper<LavaCannon, LavaCannonDescriptor>::Create() {
    LavaCannonDescriptor *var_r4_17134;

    operator new(0x1BCU, NULL, 0);
    var_r4_17134 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17134 != NULL) {
        var_r4_17134 = ((LavaCannonDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->LavaCannonDescriptor();
    }
    var_r4_17134->unk70 = 0x268;
    return var_r4_17134;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SpikeTrap,
SpikeTrapDescriptor *ExDescriptorCreatorHelper<SpikeTrap, SpikeTrapDescriptor>::Create() {
    SpikeTrapDescriptor *var_r4_17178;

    operator new(0xF4U, NULL, 0);
    var_r4_17178 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17178 != NULL) {
        var_r4_17178 = ((SpikeTrapDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SpikeTrapDescriptor();
    }
    var_r4_17178->unk70 = 0xF0;
    return var_r4_17178;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<LavaBall,
LavaBallDescriptor *ExDescriptorCreatorHelper<LavaBall, LavaBallDescriptor>::Create() {
    LavaBallDescriptor *var_r4_17222;

    operator new(0xF4U, NULL, 0);
    var_r4_17222 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17222 != NULL) {
        var_r4_17222 = ((LavaBallDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->LavaBallDescriptor();
    }
    var_r4_17222->unk70 = 0x158;
    return var_r4_17222;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Dynamite,
DynamiteDescriptor *ExDescriptorCreatorHelper<Dynamite, DynamiteDescriptor>::Create() {
    DynamiteDescriptor *var_r4_17266;

    operator new(0xF8U, NULL, 0);
    var_r4_17266 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17266 != NULL) {
        var_r4_17266 = ((DynamiteDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->DynamiteDescriptor();
    }
    var_r4_17266->unk70 = 0x1A8;
    return var_r4_17266;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<Sludge, SludgeDescriptor>::Create()'
SludgeDescriptor *ExDescriptorCreatorHelper<Sludge, SludgeDescriptor>::Create() {
    SludgeDescriptor *var_r4_17310;

    operator new(0xF4U, NULL, 0);
    var_r4_17310 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17310 != NULL) {
        var_r4_17310 = ((SludgeDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SludgeDescriptor();
    }
    var_r4_17310->unk70 = 0x160;
    return var_r4_17310;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<HotSpit,
HotSpitDescriptor *ExDescriptorCreatorHelper<HotSpit, HotSpitDescriptor>::Create() {
    HotSpitDescriptor *var_r4_17354;

    operator new(0xF4U, NULL, 0);
    var_r4_17354 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17354 != NULL) {
        var_r4_17354 = ((HotSpitDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->HotSpitDescriptor();
    }
    var_r4_17354->unk70 = 0x160;
    return var_r4_17354;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<MagicFireball,
MagicFireballDescriptor *ExDescriptorCreatorHelper<MagicFireball, MagicFireballDescriptor>::Create() {
    MagicFireballDescriptor *var_r4_17398;

    operator new(0xF4U, NULL, 0);
    var_r4_17398 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17398 != NULL) {
        var_r4_17398 = ((MagicFireballDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->MagicFireballDescriptor();
    }
    var_r4_17398->unk70 = 0x190;
    return var_r4_17398;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<IceBossStomp,
IceBossStompDescriptor *ExDescriptorCreatorHelper<IceBossStomp, IceBossStompDescriptor>::Create() {
    IceBossStompDescriptor *var_r4_17442;

    operator new(0x100U, NULL, 0);
    var_r4_17442 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17442 != NULL) {
        var_r4_17442 = ((IceBossStompDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->IceBossStompDescriptor();
    }
    var_r4_17442->unk70 = 0x178;
    return var_r4_17442;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<SonicAttack,
SonicAttackDescriptor *ExDescriptorCreatorHelper<SonicAttack, SonicAttackDescriptor>::Create() {
    SonicAttackDescriptor *var_r4_17486;

    operator new(0xF0U, NULL, 0);
    var_r4_17486 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17486 != NULL) {
        var_r4_17486 = ((SonicAttackDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->SonicAttackDescriptor();
    }
    var_r4_17486->unk70 = 0x170;
    return var_r4_17486;
}
#endif

#if 0 // DRAFT: identifier 'ExDescriptorCreatorHelper<FlyingMonkey,
FlyingMonkeyDescriptor *ExDescriptorCreatorHelper<FlyingMonkey, FlyingMonkeyDescriptor>::Create() {
    FlyingMonkeyDescriptor *var_r4_17530;

    operator new(0x10CU, NULL, 0);
    var_r4_17530 = M2C_ERROR(/* Read from unset register $r3 */);
    if (var_r4_17530 != NULL) {
        var_r4_17530 = ((FlyingMonkeyDescriptor *) (M2C_ERROR(/* Read from unset register $r3 */)))->FlyingMonkeyDescriptor();
    }
    var_r4_17530->unk70 = 0x150;
    return var_r4_17530;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<TrainChaseSpyro,
TrainChaseSpyro *ExPropCreatorHelper<TrainChaseSpyro, GamePropDescriptor>::Create(MKPropDescriptor *TrainChaseSpyro) {
    MKHeap *temp_r3_17571;
    MKHeap *temp_r3_17573;
    TrainChaseSpyro *var_r3_17580;
    s32 temp_r31_17572;

    temp_r3_17571 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_17572 = temp_r3_17571->unk80;
    temp_r3_17573 = temp_r3_17571->Current();
    if (temp_r3_17573 != NULL) {
        var_r3_17580 = ((MKHeap *) (temp_r3_17573->Current()))->Alloc(temp_r31_17572, NULL, 0);
    } else {
        var_r3_17580 = malloc(temp_r31_17572);
    }
    if (var_r3_17580 != NULL) {
        var_r3_17580->TrainChaseSpyro();
    }
    return var_r3_17580;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<FireBombFX,
FireBombFX *ExPropCreatorHelper<FireBombFX, FireBombFXDescriptor>::Create(MKPropDescriptor *FireBombFX) {
    MKHeap *temp_r3_17739;
    MKHeap *temp_r3_17741;
    TrainChaseSpyro *var_r3_17748;
    s32 temp_r31_17740;

    temp_r3_17739 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_17740 = temp_r3_17739->unk80;
    temp_r3_17741 = temp_r3_17739->Current();
    if (temp_r3_17741 != NULL) {
        var_r3_17748 = ((MKHeap *) (temp_r3_17741->Current()))->Alloc(temp_r31_17740, NULL, 0);
    } else {
        var_r3_17748 = malloc(temp_r31_17740);
    }
    if (var_r3_17748 != NULL) {
        var_r3_17748->FireBombFX();
    }
    return (FireBombFX *) var_r3_17748;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<GameParticleEmitter,
GameParticleEmitter *ExPropCreatorHelper<GameParticleEmitter, GamePropDescriptor>::Create(MKPropDescriptor *GameParticleEmitter) {
    MKHeap *temp_r3_17802;
    MKHeap *temp_r3_17804;
    TrainChaseSpyro *var_r3_17811;
    s32 temp_r31_17803;

    temp_r3_17802 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_17803 = temp_r3_17802->unk80;
    temp_r3_17804 = temp_r3_17802->Current();
    if (temp_r3_17804 != NULL) {
        var_r3_17811 = ((MKHeap *) (temp_r3_17804->Current()))->Alloc(temp_r31_17803, NULL, 0);
    } else {
        var_r3_17811 = malloc(temp_r31_17803);
    }
    if (var_r3_17811 != NULL) {
        var_r3_17811->GameParticleEmitter();
    }
    return (GameParticleEmitter *) var_r3_17811;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<LavaBubbleFX,
LavaBubbleFX *ExPropCreatorHelper<LavaBubbleFX, GamePropDescriptor>::Create(MKPropDescriptor *LavaBubbleFX) {
    MKHeap *temp_r3_17857;
    MKHeap *temp_r3_17859;
    TrainChaseSpyro *var_r3_17866;
    s32 temp_r31_17858;

    temp_r3_17857 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_17858 = temp_r3_17857->unk80;
    temp_r3_17859 = temp_r3_17857->Current();
    if (temp_r3_17859 != NULL) {
        var_r3_17866 = ((MKHeap *) (temp_r3_17859->Current()))->Alloc(temp_r31_17858, NULL, 0);
    } else {
        var_r3_17866 = malloc(temp_r31_17858);
    }
    if (var_r3_17866 != NULL) {
        var_r3_17866->LavaBubbleFX();
    }
    return (LavaBubbleFX *) var_r3_17866;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<LiquidFX,
LiquidFX *ExPropCreatorHelper<LiquidFX, LiquidFXDescriptor>::Create(MKPropDescriptor *LiquidFX) {
    MKHeap *temp_r3_17912;
    MKHeap *temp_r3_17914;
    TrainChaseSpyro *var_r3_17921;
    s32 temp_r31_17913;

    temp_r3_17912 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_17913 = temp_r3_17912->unk80;
    temp_r3_17914 = temp_r3_17912->Current();
    if (temp_r3_17914 != NULL) {
        var_r3_17921 = ((MKHeap *) (temp_r3_17914->Current()))->Alloc(temp_r31_17913, NULL, 0);
    } else {
        var_r3_17921 = malloc(temp_r31_17913);
    }
    if (var_r3_17921 != NULL) {
        var_r3_17921->LiquidFX();
    }
    return (LiquidFX *) var_r3_17921;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<ZapArcFX,
ZapArcFX *ExPropCreatorHelper<ZapArcFX, GamePropDescriptor>::Create(MKPropDescriptor *ZapArcFX) {
    MKHeap *temp_r3_17973;
    MKHeap *temp_r3_17975;
    TrainChaseSpyro *var_r3_17982;
    s32 temp_r31_17974;

    temp_r3_17973 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_17974 = temp_r3_17973->unk80;
    temp_r3_17975 = temp_r3_17973->Current();
    if (temp_r3_17975 != NULL) {
        var_r3_17982 = ((MKHeap *) (temp_r3_17975->Current()))->Alloc(temp_r31_17974, NULL, 0);
    } else {
        var_r3_17982 = malloc(temp_r31_17974);
    }
    if (var_r3_17982 != NULL) {
        var_r3_17982->ZapArcFX();
    }
    return (ZapArcFX *) var_r3_17982;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<MeleeTrails,
MeleeTrails *ExPropCreatorHelper<MeleeTrails, MeleeTrailsDescriptor>::Create(MKPropDescriptor *MeleeTrails) {
    MKHeap *temp_r3_18028;
    MKHeap *temp_r3_18030;
    TrainChaseSpyro *var_r3_18037;
    s32 temp_r31_18029;

    temp_r3_18028 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18029 = temp_r3_18028->unk80;
    temp_r3_18030 = temp_r3_18028->Current();
    if (temp_r3_18030 != NULL) {
        var_r3_18037 = ((MKHeap *) (temp_r3_18030->Current()))->Alloc(temp_r31_18029, NULL, 0);
    } else {
        var_r3_18037 = malloc(temp_r31_18029);
    }
    if (var_r3_18037 != NULL) {
        var_r3_18037->MeleeTrails();
    }
    return (MeleeTrails *) var_r3_18037;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<FlyingChunkPS,
FlyingChunkPS *ExPropCreatorHelper<FlyingChunkPS, FlyingChunkPSDescriptor>::Create(MKPropDescriptor *FlyingChunkPS) {
    MKHeap *temp_r3_18083;
    MKHeap *temp_r3_18085;
    TrainChaseSpyro *var_r3_18092;
    s32 temp_r31_18084;

    temp_r3_18083 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18084 = temp_r3_18083->unk80;
    temp_r3_18085 = temp_r3_18083->Current();
    if (temp_r3_18085 != NULL) {
        var_r3_18092 = ((MKHeap *) (temp_r3_18085->Current()))->Alloc(temp_r31_18084, NULL, 0);
    } else {
        var_r3_18092 = malloc(temp_r31_18084);
    }
    if (var_r3_18092 != NULL) {
        var_r3_18092->FlyingChunkPS();
    }
    return (FlyingChunkPS *) var_r3_18092;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<GoopFX,
GoopFX *ExPropCreatorHelper<GoopFX, GoopFXDescriptor>::Create(MKPropDescriptor *GoopFX) {
    MKHeap *temp_r3_18186;
    MKHeap *temp_r3_18188;
    TrainChaseSpyro *var_r3_18195;
    s32 temp_r31_18187;

    temp_r3_18186 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18187 = temp_r3_18186->unk80;
    temp_r3_18188 = temp_r3_18186->Current();
    if (temp_r3_18188 != NULL) {
        var_r3_18195 = ((MKHeap *) (temp_r3_18188->Current()))->Alloc(temp_r31_18187, NULL, 0);
    } else {
        var_r3_18195 = malloc(temp_r31_18187);
    }
    if (var_r3_18195 != NULL) {
        var_r3_18195->GoopFX();
    }
    return (GoopFX *) var_r3_18195;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<FXBase,
FXBase *ExPropCreatorHelper<FXBase, FXBaseDescriptor>::Create(MKPropDescriptor *FXBase) {
    MKHeap *temp_r3_18297;
    MKHeap *temp_r3_18299;
    TrainChaseSpyro *var_r3_18306;
    s32 temp_r31_18298;

    temp_r3_18297 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18298 = temp_r3_18297->unk80;
    temp_r3_18299 = temp_r3_18297->Current();
    if (temp_r3_18299 != NULL) {
        var_r3_18306 = ((MKHeap *) (temp_r3_18299->Current()))->Alloc(temp_r31_18298, NULL, 0);
    } else {
        var_r3_18306 = malloc(temp_r31_18298);
    }
    if (var_r3_18306 != NULL) {
        var_r3_18306->FXBase();
    }
    return (FXBase *) var_r3_18306;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<EarthBombFX,
EarthBombFX *ExPropCreatorHelper<EarthBombFX, EarthBombFXDescriptor>::Create(MKPropDescriptor *EarthBombFX) {
    MKHeap *temp_r3_18332;
    MKHeap *temp_r3_18334;
    TrainChaseSpyro *var_r3_18341;
    s32 temp_r31_18333;

    temp_r3_18332 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18333 = temp_r3_18332->unk80;
    temp_r3_18334 = temp_r3_18332->Current();
    if (temp_r3_18334 != NULL) {
        var_r3_18341 = ((MKHeap *) (temp_r3_18334->Current()))->Alloc(temp_r31_18333, NULL, 0);
    } else {
        var_r3_18341 = malloc(temp_r31_18333);
    }
    if (var_r3_18341 != NULL) {
        var_r3_18341->EarthBombFX();
    }
    return (EarthBombFX *) var_r3_18341;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Button,
Button *ExPropCreatorHelper<Button, ButtonDescriptor>::Create(MKPropDescriptor *Button) {
    MKHeap *temp_r3_18390;
    MKHeap *temp_r3_18392;
    TrainChaseSpyro *var_r3_18399;
    s32 temp_r31_18391;

    temp_r3_18390 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18391 = temp_r3_18390->unk80;
    temp_r3_18392 = temp_r3_18390->Current();
    if (temp_r3_18392 != NULL) {
        var_r3_18399 = ((MKHeap *) (temp_r3_18392->Current()))->Alloc(temp_r31_18391, NULL, 0);
    } else {
        var_r3_18399 = malloc(temp_r31_18391);
    }
    if (var_r3_18399 != NULL) {
        var_r3_18399->Button();
    }
    return (Button *) var_r3_18399;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Conveyor,
Conveyor *ExPropCreatorHelper<Conveyor, GamePropDescriptor>::Create(MKPropDescriptor *Conveyor) {
    MKHeap *temp_r3_18522;
    MKHeap *temp_r3_18524;
    TrainChaseSpyro *var_r3_18531;
    s32 temp_r31_18523;

    temp_r3_18522 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18523 = temp_r3_18522->unk80;
    temp_r3_18524 = temp_r3_18522->Current();
    if (temp_r3_18524 != NULL) {
        var_r3_18531 = ((MKHeap *) (temp_r3_18524->Current()))->Alloc(temp_r31_18523, NULL, 0);
    } else {
        var_r3_18531 = malloc(temp_r31_18523);
    }
    if (var_r3_18531 != NULL) {
        var_r3_18531->Conveyor();
    }
    return (Conveyor *) var_r3_18531;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<ConveyorBucket,
ConveyorBucket *ExPropCreatorHelper<ConveyorBucket, GamePropDescriptor>::Create(MKPropDescriptor *ConveyorBucket) {
    MKHeap *temp_r3_18584;
    MKHeap *temp_r3_18586;
    TrainChaseSpyro *var_r3_18593;
    s32 temp_r31_18585;

    temp_r3_18584 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18585 = temp_r3_18584->unk80;
    temp_r3_18586 = temp_r3_18584->Current();
    if (temp_r3_18586 != NULL) {
        var_r3_18593 = ((MKHeap *) (temp_r3_18586->Current()))->Alloc(temp_r31_18585, NULL, 0);
    } else {
        var_r3_18593 = malloc(temp_r31_18585);
    }
    if (var_r3_18593 != NULL) {
        var_r3_18593->ConveyorBucket();
    }
    return (ConveyorBucket *) var_r3_18593;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Crate,
Crate *ExPropCreatorHelper<Crate, CrateDescriptor>::Create(MKPropDescriptor *Crate) {
    MKHeap *temp_r3_18639;
    MKHeap *temp_r3_18641;
    TrainChaseSpyro *var_r3_18648;
    s32 temp_r31_18640;

    temp_r3_18639 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18640 = temp_r3_18639->unk80;
    temp_r3_18641 = temp_r3_18639->Current();
    if (temp_r3_18641 != NULL) {
        var_r3_18648 = ((MKHeap *) (temp_r3_18641->Current()))->Alloc(temp_r31_18640, NULL, 0);
    } else {
        var_r3_18648 = malloc(temp_r31_18640);
    }
    if (var_r3_18648 != NULL) {
        var_r3_18648->Crate();
    }
    return (Crate *) var_r3_18648;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<DragonBustDoor,
DragonBustDoor *ExPropCreatorHelper<DragonBustDoor, DoorDescriptor>::Create(MKPropDescriptor *DragonBustDoor) {
    MKHeap *temp_r3_18708;
    MKHeap *temp_r3_18710;
    TrainChaseSpyro *var_r3_18717;
    s32 temp_r31_18709;

    temp_r3_18708 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18709 = temp_r3_18708->unk80;
    temp_r3_18710 = temp_r3_18708->Current();
    if (temp_r3_18710 != NULL) {
        var_r3_18717 = ((MKHeap *) (temp_r3_18710->Current()))->Alloc(temp_r31_18709, NULL, 0);
    } else {
        var_r3_18717 = malloc(temp_r31_18709);
    }
    if (var_r3_18717 != NULL) {
        var_r3_18717->DragonBustDoor();
    }
    return (DragonBustDoor *) var_r3_18717;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Elevator,
Elevator *ExPropCreatorHelper<Elevator, GamePropDescriptor>::Create(MKPropDescriptor *Elevator) {
    MKHeap *temp_r3_18817;
    MKHeap *temp_r3_18819;
    TrainChaseSpyro *var_r3_18826;
    s32 temp_r31_18818;

    temp_r3_18817 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18818 = temp_r3_18817->unk80;
    temp_r3_18819 = temp_r3_18817->Current();
    if (temp_r3_18819 != NULL) {
        var_r3_18826 = ((MKHeap *) (temp_r3_18819->Current()))->Alloc(temp_r31_18818, NULL, 0);
    } else {
        var_r3_18826 = malloc(temp_r31_18818);
    }
    if (var_r3_18826 != NULL) {
        var_r3_18826->Elevator();
    }
    return (Elevator *) var_r3_18826;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<GameProp,
GameProp *ExPropCreatorHelper<GameProp, GamePropDescriptor>::Create(MKPropDescriptor *GameProp) {
    MKHeap *temp_r3_18872;
    MKHeap *temp_r3_18874;
    TrainChaseSpyro *var_r3_18881;
    s32 temp_r31_18873;

    temp_r3_18872 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18873 = temp_r3_18872->unk80;
    temp_r3_18874 = temp_r3_18872->Current();
    if (temp_r3_18874 != NULL) {
        var_r3_18881 = ((MKHeap *) (temp_r3_18874->Current()))->Alloc(temp_r31_18873, NULL, 0);
    } else {
        var_r3_18881 = malloc(temp_r31_18873);
    }
    if (var_r3_18881 != NULL) {
        var_r3_18881->GameProp();
    }
    return (GameProp *) var_r3_18881;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<LavaSmashProp,
LavaSmashProp *ExPropCreatorHelper<LavaSmashProp, LavaSmashPropDescriptor>::Create(MKPropDescriptor *LavaSmashProp) {
    MKHeap *temp_r3_18907;
    MKHeap *temp_r3_18909;
    TrainChaseSpyro *var_r3_18916;
    s32 temp_r31_18908;

    temp_r3_18907 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_18908 = temp_r3_18907->unk80;
    temp_r3_18909 = temp_r3_18907->Current();
    if (temp_r3_18909 != NULL) {
        var_r3_18916 = ((MKHeap *) (temp_r3_18909->Current()))->Alloc(temp_r31_18908, NULL, 0);
    } else {
        var_r3_18916 = malloc(temp_r31_18908);
    }
    if (var_r3_18916 != NULL) {
        var_r3_18916->LavaSmashProp();
    }
    return (LavaSmashProp *) var_r3_18916;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<LavaDerick,
LavaDerick *ExPropCreatorHelper<LavaDerick, LavaDerickDescriptor>::Create(MKPropDescriptor *LavaDerick) {
    MKHeap *temp_r3_19092;
    MKHeap *temp_r3_19094;
    TrainChaseSpyro *var_r3_19101;
    s32 temp_r31_19093;

    temp_r3_19092 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19093 = temp_r3_19092->unk80;
    temp_r3_19094 = temp_r3_19092->Current();
    if (temp_r3_19094 != NULL) {
        var_r3_19101 = ((MKHeap *) (temp_r3_19094->Current()))->Alloc(temp_r31_19093, NULL, 0);
    } else {
        var_r3_19101 = malloc(temp_r31_19093);
    }
    if (var_r3_19101 != NULL) {
        var_r3_19101->LavaDerick();
    }
    return (LavaDerick *) var_r3_19101;
}
#endif

#if 0 // DRAFT: undefined identifier 'unk0'
void ExPropCreatorHelper<KDPropEx, KDPropExDescriptor>::Create(MKPropDescriptor *KDPropEx) {
    MKHeap *temp_r3_19149;
    MKHeap *temp_r3_19151;
    TrainChaseSpyro *var_r3_19158;
    s32 temp_r31_19150;

    temp_r3_19149 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19150 = temp_r3_19149->unk80;
    temp_r3_19151 = temp_r3_19149->Current();
    if (temp_r3_19151 != NULL) {
        var_r3_19158 = ((MKHeap *) (temp_r3_19151->Current()))->Alloc(temp_r31_19150, NULL, 0);
    } else {
        var_r3_19158 = malloc(temp_r31_19150);
    }
    if (var_r3_19158 != NULL) {
        var_r3_19158->__vptr = &__vt;
        var_r3_19158->__vptr = &__vt;
        var_r3_19158->__vptr = &__vt;
    }
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<MineCart,
MineCart *ExPropCreatorHelper<MineCart, MineCartDescriptor>::Create(MKPropDescriptor *MineCart) {
    MKHeap *temp_r3_19190;
    MKHeap *temp_r3_19192;
    TrainChaseSpyro *var_r3_19199;
    s32 temp_r31_19191;

    temp_r3_19190 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19191 = temp_r3_19190->unk80;
    temp_r3_19192 = temp_r3_19190->Current();
    if (temp_r3_19192 != NULL) {
        var_r3_19199 = ((MKHeap *) (temp_r3_19192->Current()))->Alloc(temp_r31_19191, NULL, 0);
    } else {
        var_r3_19199 = malloc(temp_r31_19191);
    }
    if (var_r3_19199 != NULL) {
        var_r3_19199->MineCart();
    }
    return (MineCart *) var_r3_19199;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<MineCartDoor,
MineCartDoor *ExPropCreatorHelper<MineCartDoor, MineCartDoorDescriptor>::Create(MKPropDescriptor *MineCartDoor) {
    MKHeap *temp_r3_19247;
    MKHeap *temp_r3_19249;
    TrainChaseSpyro *var_r3_19256;
    s32 temp_r31_19248;

    temp_r3_19247 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19248 = temp_r3_19247->unk80;
    temp_r3_19249 = temp_r3_19247->Current();
    if (temp_r3_19249 != NULL) {
        var_r3_19256 = ((MKHeap *) (temp_r3_19249->Current()))->Alloc(temp_r31_19248, NULL, 0);
    } else {
        var_r3_19256 = malloc(temp_r31_19248);
    }
    if (var_r3_19256 != NULL) {
        var_r3_19256->MineCartDoor();
    }
    return (MineCartDoor *) var_r3_19256;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<MoltenMetalBucket,
MoltenMetalBucket *ExPropCreatorHelper<MoltenMetalBucket, MoltenMetalBucketDescriptor>::Create(MKPropDescriptor *MoltenMetalBucket) {
    MKHeap *temp_r3_19302;
    MKHeap *temp_r3_19304;
    TrainChaseSpyro *var_r3_19311;
    s32 temp_r31_19303;

    temp_r3_19302 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19303 = temp_r3_19302->unk80;
    temp_r3_19304 = temp_r3_19302->Current();
    if (temp_r3_19304 != NULL) {
        var_r3_19311 = ((MKHeap *) (temp_r3_19304->Current()))->Alloc(temp_r31_19303, NULL, 0);
    } else {
        var_r3_19311 = malloc(temp_r31_19303);
    }
    if (var_r3_19311 != NULL) {
        var_r3_19311->MoltenMetalBucket();
    }
    return (MoltenMetalBucket *) var_r3_19311;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SteamValve,
SteamValve *ExPropCreatorHelper<SteamValve, SteamValveDescriptor>::Create(MKPropDescriptor *SteamValve) {
    MKHeap *temp_r3_19362;
    MKHeap *temp_r3_19364;
    TrainChaseSpyro *var_r3_19371;
    s32 temp_r31_19363;

    temp_r3_19362 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19363 = temp_r3_19362->unk80;
    temp_r3_19364 = temp_r3_19362->Current();
    if (temp_r3_19364 != NULL) {
        var_r3_19371 = ((MKHeap *) (temp_r3_19364->Current()))->Alloc(temp_r31_19363, NULL, 0);
    } else {
        var_r3_19371 = malloc(temp_r31_19363);
    }
    if (var_r3_19371 != NULL) {
        var_r3_19371->SteamValve();
    }
    return (SteamValve *) var_r3_19371;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<ExplosiveBarrel,
ExplosiveBarrel *ExPropCreatorHelper<ExplosiveBarrel, ExplosiveBarrelDescriptor>::Create(MKPropDescriptor *ExplosiveBarrel) {
    MKHeap *temp_r3_19417;
    MKHeap *temp_r3_19419;
    TrainChaseSpyro *var_r3_19426;
    s32 temp_r31_19418;

    temp_r3_19417 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19418 = temp_r3_19417->unk80;
    temp_r3_19419 = temp_r3_19417->Current();
    if (temp_r3_19419 != NULL) {
        var_r3_19426 = ((MKHeap *) (temp_r3_19419->Current()))->Alloc(temp_r31_19418, NULL, 0);
    } else {
        var_r3_19426 = malloc(temp_r31_19418);
    }
    if (var_r3_19426 != NULL) {
        var_r3_19426->ExplosiveBarrel();
    }
    return (ExplosiveBarrel *) var_r3_19426;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SteamTrain,
SteamTrain *ExPropCreatorHelper<SteamTrain, SteamTrainDescriptor>::Create(MKPropDescriptor *SteamTrain) {
    MKHeap *temp_r3_19476;
    MKHeap *temp_r3_19478;
    TrainChaseSpyro *var_r3_19485;
    s32 temp_r31_19477;

    temp_r3_19476 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19477 = temp_r3_19476->unk80;
    temp_r3_19478 = temp_r3_19476->Current();
    if (temp_r3_19478 != NULL) {
        var_r3_19485 = ((MKHeap *) (temp_r3_19478->Current()))->Alloc(temp_r31_19477, NULL, 0);
    } else {
        var_r3_19485 = malloc(temp_r31_19477);
    }
    if (var_r3_19485 != NULL) {
        var_r3_19485->SteamTrain();
    }
    return (SteamTrain *) var_r3_19485;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SteamTrainCaboose,
SteamTrainCaboose *ExPropCreatorHelper<SteamTrainCaboose, SteamTrainCabooseDescriptor>::Create(MKPropDescriptor *SteamTrainCaboose) {
    MKHeap *temp_r3_19545;
    MKHeap *temp_r3_19547;
    TrainChaseSpyro *var_r3_19554;
    s32 temp_r31_19546;

    temp_r3_19545 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19546 = temp_r3_19545->unk80;
    temp_r3_19547 = temp_r3_19545->Current();
    if (temp_r3_19547 != NULL) {
        var_r3_19554 = ((MKHeap *) (temp_r3_19547->Current()))->Alloc(temp_r31_19546, NULL, 0);
    } else {
        var_r3_19554 = malloc(temp_r31_19546);
    }
    if (var_r3_19554 != NULL) {
        var_r3_19554->SteamTrainCaboose();
    }
    return (SteamTrainCaboose *) var_r3_19554;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<TrainGate,
TrainGate *ExPropCreatorHelper<TrainGate, TrainGateDescriptor>::Create(MKPropDescriptor *TrainGate) {
    MKHeap *temp_r3_19611;
    MKHeap *temp_r3_19613;
    TrainChaseSpyro *var_r3_19620;
    s32 temp_r31_19612;

    temp_r3_19611 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19612 = temp_r3_19611->unk80;
    temp_r3_19613 = temp_r3_19611->Current();
    if (temp_r3_19613 != NULL) {
        var_r3_19620 = ((MKHeap *) (temp_r3_19613->Current()))->Alloc(temp_r31_19612, NULL, 0);
    } else {
        var_r3_19620 = malloc(temp_r31_19612);
    }
    if (var_r3_19620 != NULL) {
        var_r3_19620->TrainGate();
    }
    return (TrainGate *) var_r3_19620;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Lever,
Lever *ExPropCreatorHelper<Lever, LeverDescriptor>::Create(MKPropDescriptor *Lever) {
    MKHeap *temp_r3_19670;
    MKHeap *temp_r3_19672;
    TrainChaseSpyro *var_r3_19679;
    s32 temp_r31_19671;

    temp_r3_19670 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19671 = temp_r3_19670->unk80;
    temp_r3_19672 = temp_r3_19670->Current();
    if (temp_r3_19672 != NULL) {
        var_r3_19679 = ((MKHeap *) (temp_r3_19672->Current()))->Alloc(temp_r31_19671, NULL, 0);
    } else {
        var_r3_19679 = malloc(temp_r31_19671);
    }
    if (var_r3_19679 != NULL) {
        var_r3_19679->Lever();
    }
    return (Lever *) var_r3_19679;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<WobbleProp,
WobbleProp *ExPropCreatorHelper<WobbleProp, WobblePropDescriptor>::Create(MKPropDescriptor *WobbleProp) {
    MKHeap *temp_r3_19740;
    MKHeap *temp_r3_19742;
    TrainChaseSpyro *var_r3_19749;
    s32 temp_r31_19741;

    temp_r3_19740 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19741 = temp_r3_19740->unk80;
    temp_r3_19742 = temp_r3_19740->Current();
    if (temp_r3_19742 != NULL) {
        var_r3_19749 = ((MKHeap *) (temp_r3_19742->Current()))->Alloc(temp_r31_19741, NULL, 0);
    } else {
        var_r3_19749 = malloc(temp_r31_19741);
    }
    if (var_r3_19749 != NULL) {
        var_r3_19749->WobbleProp();
    }
    return (WobbleProp *) var_r3_19749;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<MobilePlatform,
MobilePlatform *ExPropCreatorHelper<MobilePlatform, MobilePlatformDescriptor>::Create(MKPropDescriptor *MobilePlatform) {
    MKHeap *temp_r3_19795;
    MKHeap *temp_r3_19797;
    TrainChaseSpyro *var_r3_19804;
    s32 temp_r31_19796;

    temp_r3_19795 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19796 = temp_r3_19795->unk80;
    temp_r3_19797 = temp_r3_19795->Current();
    if (temp_r3_19797 != NULL) {
        var_r3_19804 = ((MKHeap *) (temp_r3_19797->Current()))->Alloc(temp_r31_19796, NULL, 0);
    } else {
        var_r3_19804 = malloc(temp_r31_19796);
    }
    if (var_r3_19804 != NULL) {
        var_r3_19804->MobilePlatform();
    }
    return (MobilePlatform *) var_r3_19804;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Platform,
Platform *ExPropCreatorHelper<Platform, PlatformDescriptor>::Create(MKPropDescriptor *Platform) {
    MKHeap *temp_r3_19964;
    MKHeap *temp_r3_19966;
    TrainChaseSpyro *var_r3_19973;
    s32 temp_r31_19965;

    temp_r3_19964 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_19965 = temp_r3_19964->unk80;
    temp_r3_19966 = temp_r3_19964->Current();
    if (temp_r3_19966 != NULL) {
        var_r3_19973 = ((MKHeap *) (temp_r3_19966->Current()))->Alloc(temp_r31_19965, NULL, 0);
    } else {
        var_r3_19973 = malloc(temp_r31_19965);
    }
    if (var_r3_19973 != NULL) {
        var_r3_19973->Platform();
    }
    return (Platform *) var_r3_19973;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Shatterable,
Shatterable *ExPropCreatorHelper<Shatterable, ShatterableDescriptor>::Create(MKPropDescriptor *Shatterable) {
    MKHeap *temp_r3_19999;
    MKHeap *temp_r3_20001;
    TrainChaseSpyro *var_r3_20008;
    s32 temp_r31_20000;

    temp_r3_19999 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20000 = temp_r3_19999->unk80;
    temp_r3_20001 = temp_r3_19999->Current();
    if (temp_r3_20001 != NULL) {
        var_r3_20008 = ((MKHeap *) (temp_r3_20001->Current()))->Alloc(temp_r31_20000, NULL, 0);
    } else {
        var_r3_20008 = malloc(temp_r31_20000);
    }
    if (var_r3_20008 != NULL) {
        var_r3_20008->Shatterable();
    }
    return (Shatterable *) var_r3_20008;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<FloatingPlatform,
FloatingPlatform *ExPropCreatorHelper<FloatingPlatform, FloatingPlatformDescriptor>::Create(MKPropDescriptor *FloatingPlatform) {
    MKHeap *temp_r3_20034;
    MKHeap *temp_r3_20036;
    TrainChaseSpyro *var_r3_20043;
    s32 temp_r31_20035;

    temp_r3_20034 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20035 = temp_r3_20034->unk80;
    temp_r3_20036 = temp_r3_20034->Current();
    if (temp_r3_20036 != NULL) {
        var_r3_20043 = ((MKHeap *) (temp_r3_20036->Current()))->Alloc(temp_r31_20035, NULL, 0);
    } else {
        var_r3_20043 = malloc(temp_r31_20035);
    }
    if (var_r3_20043 != NULL) {
        var_r3_20043->FloatingPlatform();
    }
    return (FloatingPlatform *) var_r3_20043;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Torch,
Torch *ExPropCreatorHelper<Torch, GamePropDescriptor>::Create(MKPropDescriptor *Torch) {
    MKHeap *temp_r3_20095;
    MKHeap *temp_r3_20097;
    TrainChaseSpyro *var_r3_20104;
    s32 temp_r31_20096;

    temp_r3_20095 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20096 = temp_r3_20095->unk80;
    temp_r3_20097 = temp_r3_20095->Current();
    if (temp_r3_20097 != NULL) {
        var_r3_20104 = ((MKHeap *) (temp_r3_20097->Current()))->Alloc(temp_r31_20096, NULL, 0);
    } else {
        var_r3_20104 = malloc(temp_r31_20096);
    }
    if (var_r3_20104 != NULL) {
        var_r3_20104->Torch();
    }
    return (Torch *) var_r3_20104;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<PooledShatterProp,
PooledShatterProp *ExPropCreatorHelper<PooledShatterProp, ShatterableDescriptor>::Create(MKPropDescriptor *PooledShatterProp) {
    MKHeap *temp_r3_20150;
    MKHeap *temp_r3_20152;
    TrainChaseSpyro *var_r3_20159;
    s32 temp_r31_20151;

    temp_r3_20150 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20151 = temp_r3_20150->unk80;
    temp_r3_20152 = temp_r3_20150->Current();
    if (temp_r3_20152 != NULL) {
        var_r3_20159 = ((MKHeap *) (temp_r3_20152->Current()))->Alloc(temp_r31_20151, NULL, 0);
    } else {
        var_r3_20159 = malloc(temp_r31_20151);
    }
    if (var_r3_20159 != NULL) {
        var_r3_20159->PooledShatterProp();
    }
    return (PooledShatterProp *) var_r3_20159;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<LightProp,
LightProp *ExPropCreatorHelper<LightProp, GamePropDescriptor>::Create(MKPropDescriptor *LightProp) {
    MKHeap *temp_r3_20207;
    MKHeap *temp_r3_20209;
    TrainChaseSpyro *var_r3_20216;
    s32 temp_r31_20208;

    temp_r3_20207 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20208 = temp_r3_20207->unk80;
    temp_r3_20209 = temp_r3_20207->Current();
    if (temp_r3_20209 != NULL) {
        var_r3_20216 = ((MKHeap *) (temp_r3_20209->Current()))->Alloc(temp_r31_20208, NULL, 0);
    } else {
        var_r3_20216 = malloc(temp_r31_20208);
    }
    if (var_r3_20216 != NULL) {
        var_r3_20216->LightProp();
    }
    return (LightProp *) var_r3_20216;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SteamFireBall,
SteamFireBall *ExPropCreatorHelper<SteamFireBall, SteamFireBallDescriptor>::Create(MKPropDescriptor *SteamFireBall) {
    MKHeap *temp_r3_20262;
    MKHeap *temp_r3_20264;
    TrainChaseSpyro *var_r3_20271;
    s32 temp_r31_20263;

    temp_r3_20262 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20263 = temp_r3_20262->unk80;
    temp_r3_20264 = temp_r3_20262->Current();
    if (temp_r3_20264 != NULL) {
        var_r3_20271 = ((MKHeap *) (temp_r3_20264->Current()))->Alloc(temp_r31_20263, NULL, 0);
    } else {
        var_r3_20271 = malloc(temp_r31_20263);
    }
    if (var_r3_20271 != NULL) {
        var_r3_20271->SteamFireBall();
    }
    return (SteamFireBall *) var_r3_20271;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<GuardianCageCrystal,
GuardianCageCrystal *ExPropCreatorHelper<GuardianCageCrystal, GuardianCageCrystalDescriptor>::Create(MKPropDescriptor *GuardianCageCrystal) {
    MKHeap *temp_r3_20365;
    MKHeap *temp_r3_20367;
    TrainChaseSpyro *var_r3_20374;
    s32 temp_r31_20366;

    temp_r3_20365 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20366 = temp_r3_20365->unk80;
    temp_r3_20367 = temp_r3_20365->Current();
    if (temp_r3_20367 != NULL) {
        var_r3_20374 = ((MKHeap *) (temp_r3_20367->Current()))->Alloc(temp_r31_20366, NULL, 0);
    } else {
        var_r3_20374 = malloc(temp_r31_20366);
    }
    if (var_r3_20374 != NULL) {
        var_r3_20374->GuardianCageCrystal();
    }
    return (GuardianCageCrystal *) var_r3_20374;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<GuardianCage,
GuardianCage *ExPropCreatorHelper<GuardianCage, GamePropDescriptor>::Create(MKPropDescriptor *GuardianCage) {
    MKHeap *temp_r3_20424;
    MKHeap *temp_r3_20426;
    TrainChaseSpyro *var_r3_20433;
    s32 temp_r31_20425;

    temp_r3_20424 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20425 = temp_r3_20424->unk80;
    temp_r3_20426 = temp_r3_20424->Current();
    if (temp_r3_20426 != NULL) {
        var_r3_20433 = ((MKHeap *) (temp_r3_20426->Current()))->Alloc(temp_r31_20425, NULL, 0);
    } else {
        var_r3_20433 = malloc(temp_r31_20425);
    }
    if (var_r3_20433 != NULL) {
        var_r3_20433->GuardianCage();
    }
    return (GuardianCage *) var_r3_20433;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<MagmaSquirt,
MagmaSquirt *ExPropCreatorHelper<MagmaSquirt, MagmaSquirtDescriptor>::Create(MKPropDescriptor *MagmaSquirt) {
    MKHeap *temp_r3_20489;
    MKHeap *temp_r3_20491;
    TrainChaseSpyro *var_r3_20498;
    s32 temp_r31_20490;

    temp_r3_20489 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20490 = temp_r3_20489->unk80;
    temp_r3_20491 = temp_r3_20489->Current();
    if (temp_r3_20491 != NULL) {
        var_r3_20498 = ((MKHeap *) (temp_r3_20491->Current()))->Alloc(temp_r31_20490, NULL, 0);
    } else {
        var_r3_20498 = malloc(temp_r31_20490);
    }
    if (var_r3_20498 != NULL) {
        var_r3_20498->MagmaSquirt();
    }
    return (MagmaSquirt *) var_r3_20498;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<IceSquirt,
IceSquirt *ExPropCreatorHelper<IceSquirt, IceSquirtDescriptor>::Create(MKPropDescriptor *IceSquirt) {
    MKHeap *temp_r3_20546;
    MKHeap *temp_r3_20548;
    TrainChaseSpyro *var_r3_20555;
    s32 temp_r31_20547;

    temp_r3_20546 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20547 = temp_r3_20546->unk80;
    temp_r3_20548 = temp_r3_20546->Current();
    if (temp_r3_20548 != NULL) {
        var_r3_20555 = ((MKHeap *) (temp_r3_20548->Current()))->Alloc(temp_r31_20547, NULL, 0);
    } else {
        var_r3_20555 = malloc(temp_r31_20547);
    }
    if (var_r3_20555 != NULL) {
        var_r3_20555->IceSquirt();
    }
    return (IceSquirt *) var_r3_20555;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Ball,
Ball *ExPropCreatorHelper<Ball, BallDescriptor>::Create(MKPropDescriptor *Ball) {
    MKHeap *temp_r3_20603;
    MKHeap *temp_r3_20605;
    TrainChaseSpyro *var_r3_20612;
    s32 temp_r31_20604;

    temp_r3_20603 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20604 = temp_r3_20603->unk80;
    temp_r3_20605 = temp_r3_20603->Current();
    if (temp_r3_20605 != NULL) {
        var_r3_20612 = ((MKHeap *) (temp_r3_20605->Current()))->Alloc(temp_r31_20604, NULL, 0);
    } else {
        var_r3_20612 = malloc(temp_r31_20604);
    }
    if (var_r3_20612 != NULL) {
        var_r3_20612->Ball();
    }
    return (Ball *) var_r3_20612;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<DragonBust,
DragonBust *ExPropCreatorHelper<DragonBust, GamePropDescriptor>::Create(MKPropDescriptor *DragonBust) {
    MKHeap *temp_r3_20681;
    MKHeap *temp_r3_20683;
    TrainChaseSpyro *var_r3_20690;
    s32 temp_r31_20682;

    temp_r3_20681 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20682 = temp_r3_20681->unk80;
    temp_r3_20683 = temp_r3_20681->Current();
    if (temp_r3_20683 != NULL) {
        var_r3_20690 = ((MKHeap *) (temp_r3_20683->Current()))->Alloc(temp_r31_20682, NULL, 0);
    } else {
        var_r3_20690 = malloc(temp_r31_20682);
    }
    if (var_r3_20690 != NULL) {
        var_r3_20690->DragonBust();
    }
    return (DragonBust *) var_r3_20690;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<GamePropColored,
GamePropColored *ExPropCreatorHelper<GamePropColored, GamePropColoredDescriptor>::Create(MKPropDescriptor *GamePropColored) {
    MKHeap *temp_r3_20743;
    MKHeap *temp_r3_20745;
    TrainChaseSpyro *var_r3_20752;
    s32 temp_r31_20744;

    temp_r3_20743 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20744 = temp_r3_20743->unk80;
    temp_r3_20745 = temp_r3_20743->Current();
    if (temp_r3_20745 != NULL) {
        var_r3_20752 = ((MKHeap *) (temp_r3_20745->Current()))->Alloc(temp_r31_20744, NULL, 0);
    } else {
        var_r3_20752 = malloc(temp_r31_20744);
    }
    if (var_r3_20752 != NULL) {
        var_r3_20752->GamePropColored();
    }
    return (GamePropColored *) var_r3_20752;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<MoleTether,
MoleTether *ExPropCreatorHelper<MoleTether, MoleTetherDescriptor>::Create(MKPropDescriptor *MoleTether) {
    MKHeap *temp_r3_20778;
    MKHeap *temp_r3_20780;
    TrainChaseSpyro *var_r3_20787;
    s32 temp_r31_20779;

    temp_r3_20778 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20779 = temp_r3_20778->unk80;
    temp_r3_20780 = temp_r3_20778->Current();
    if (temp_r3_20780 != NULL) {
        var_r3_20787 = ((MKHeap *) (temp_r3_20780->Current()))->Alloc(temp_r31_20779, NULL, 0);
    } else {
        var_r3_20787 = malloc(temp_r31_20779);
    }
    if (var_r3_20787 != NULL) {
        var_r3_20787->MoleTether();
    }
    return (MoleTether *) var_r3_20787;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<ExplosiveBarrelSpawner,
ExplosiveBarrelSpawner *ExPropCreatorHelper<ExplosiveBarrelSpawner, ExplosiveBarrelSpawnerDescriptor>::Create(MKPropDescriptor *ExplosiveBarrelSpawner) {
    MKHeap *temp_r3_20837;
    MKHeap *temp_r3_20839;
    TrainChaseSpyro *var_r3_20846;
    s32 temp_r31_20838;

    temp_r3_20837 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20838 = temp_r3_20837->unk80;
    temp_r3_20839 = temp_r3_20837->Current();
    if (temp_r3_20839 != NULL) {
        var_r3_20846 = ((MKHeap *) (temp_r3_20839->Current()))->Alloc(temp_r31_20838, NULL, 0);
    } else {
        var_r3_20846 = malloc(temp_r31_20838);
    }
    if (var_r3_20846 != NULL) {
        var_r3_20846->ExplosiveBarrelSpawner();
    }
    return (ExplosiveBarrelSpawner *) var_r3_20846;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<GuardTower,
GuardTower *ExPropCreatorHelper<GuardTower, GuardTowerDescriptor>::Create(MKPropDescriptor *GuardTower) {
    MKHeap *temp_r3_20892;
    MKHeap *temp_r3_20894;
    TrainChaseSpyro *var_r3_20901;
    s32 temp_r31_20893;

    temp_r3_20892 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20893 = temp_r3_20892->unk80;
    temp_r3_20894 = temp_r3_20892->Current();
    if (temp_r3_20894 != NULL) {
        var_r3_20901 = ((MKHeap *) (temp_r3_20894->Current()))->Alloc(temp_r31_20893, NULL, 0);
    } else {
        var_r3_20901 = malloc(temp_r31_20893);
    }
    if (var_r3_20901 != NULL) {
        var_r3_20901->GuardTower();
    }
    return (GuardTower *) var_r3_20901;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<FireMolePrison,
FireMolePrison *ExPropCreatorHelper<FireMolePrison, FireMolePrisonDescriptor>::Create(MKPropDescriptor *FireMolePrison) {
    MKHeap *temp_r3_20987;
    MKHeap *temp_r3_20989;
    TrainChaseSpyro *var_r3_20996;
    s32 temp_r31_20988;

    temp_r3_20987 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_20988 = temp_r3_20987->unk80;
    temp_r3_20989 = temp_r3_20987->Current();
    if (temp_r3_20989 != NULL) {
        var_r3_20996 = ((MKHeap *) (temp_r3_20989->Current()))->Alloc(temp_r31_20988, NULL, 0);
    } else {
        var_r3_20996 = malloc(temp_r31_20988);
    }
    if (var_r3_20996 != NULL) {
        var_r3_20996->FireMolePrison();
    }
    return (FireMolePrison *) var_r3_20996;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<BeetleNestSmall,
BeetleNestSmall *ExPropCreatorHelper<BeetleNestSmall, BeetleNestSmallDescriptor>::Create(MKPropDescriptor *BeetleNestSmall) {
    MKHeap *temp_r3_21121;
    MKHeap *temp_r3_21123;
    TrainChaseSpyro *var_r3_21130;
    s32 temp_r31_21122;

    temp_r3_21121 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21122 = temp_r3_21121->unk80;
    temp_r3_21123 = temp_r3_21121->Current();
    if (temp_r3_21123 != NULL) {
        var_r3_21130 = ((MKHeap *) (temp_r3_21123->Current()))->Alloc(temp_r31_21122, NULL, 0);
    } else {
        var_r3_21130 = malloc(temp_r31_21122);
    }
    if (var_r3_21130 != NULL) {
        var_r3_21130->BeetleNestSmall();
    }
    return (BeetleNestSmall *) var_r3_21130;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<BigBeetleHive,
BigBeetleHive *ExPropCreatorHelper<BigBeetleHive, BigBeetleHiveDescriptor>::Create(MKPropDescriptor *BigBeetleHive) {
    MKHeap *temp_r3_21178;
    MKHeap *temp_r3_21180;
    TrainChaseSpyro *var_r3_21187;
    s32 temp_r31_21179;

    temp_r3_21178 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21179 = temp_r3_21178->unk80;
    temp_r3_21180 = temp_r3_21178->Current();
    if (temp_r3_21180 != NULL) {
        var_r3_21187 = ((MKHeap *) (temp_r3_21180->Current()))->Alloc(temp_r31_21179, NULL, 0);
    } else {
        var_r3_21187 = malloc(temp_r31_21179);
    }
    if (var_r3_21187 != NULL) {
        var_r3_21187->BigBeetleHive();
    }
    return (BigBeetleHive *) var_r3_21187;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<AssaultCannon,
AssaultCannon *ExPropCreatorHelper<AssaultCannon, AssaultCannonDescriptor>::Create(MKPropDescriptor *AssaultCannon) {
    MKHeap *temp_r3_21235;
    MKHeap *temp_r3_21237;
    TrainChaseSpyro *var_r3_21244;
    s32 temp_r31_21236;

    temp_r3_21235 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21236 = temp_r3_21235->unk80;
    temp_r3_21237 = temp_r3_21235->Current();
    if (temp_r3_21237 != NULL) {
        var_r3_21244 = ((MKHeap *) (temp_r3_21237->Current()))->Alloc(temp_r31_21236, NULL, 0);
    } else {
        var_r3_21244 = malloc(temp_r31_21236);
    }
    if (var_r3_21244 != NULL) {
        var_r3_21244->AssaultCannon();
    }
    return (AssaultCannon *) var_r3_21244;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<IceBossStalactite,
IceBossStalactite *ExPropCreatorHelper<IceBossStalactite, IceBossStalactiteDescriptor>::Create(MKPropDescriptor *IceBossStalactite) {
    MKHeap *temp_r3_21376;
    MKHeap *temp_r3_21378;
    TrainChaseSpyro *var_r3_21385;
    s32 temp_r31_21377;

    temp_r3_21376 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21377 = temp_r3_21376->unk80;
    temp_r3_21378 = temp_r3_21376->Current();
    if (temp_r3_21378 != NULL) {
        var_r3_21385 = ((MKHeap *) (temp_r3_21378->Current()))->Alloc(temp_r31_21377, NULL, 0);
    } else {
        var_r3_21385 = malloc(temp_r31_21377);
    }
    if (var_r3_21385 != NULL) {
        var_r3_21385->IceBossStalactite();
    }
    return (IceBossStalactite *) var_r3_21385;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<DropBox,
DropBox *ExPropCreatorHelper<DropBox, DropBoxDescriptor>::Create(MKPropDescriptor *DropBox) {
    MKHeap *temp_r3_21433;
    MKHeap *temp_r3_21435;
    TrainChaseSpyro *var_r3_21442;
    s32 temp_r31_21434;

    temp_r3_21433 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21434 = temp_r3_21433->unk80;
    temp_r3_21435 = temp_r3_21433->Current();
    if (temp_r3_21435 != NULL) {
        var_r3_21442 = ((MKHeap *) (temp_r3_21435->Current()))->Alloc(temp_r31_21434, NULL, 0);
    } else {
        var_r3_21442 = malloc(temp_r31_21434);
    }
    if (var_r3_21442 != NULL) {
        var_r3_21442->DropBox();
    }
    return (DropBox *) var_r3_21442;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Gondola,
Gondola *ExPropCreatorHelper<Gondola, GondolaDescriptor>::Create(MKPropDescriptor *Gondola) {
    MKHeap *temp_r3_21494;
    MKHeap *temp_r3_21496;
    TrainChaseSpyro *var_r3_21503;
    s32 temp_r31_21495;

    temp_r3_21494 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21495 = temp_r3_21494->unk80;
    temp_r3_21496 = temp_r3_21494->Current();
    if (temp_r3_21496 != NULL) {
        var_r3_21503 = ((MKHeap *) (temp_r3_21496->Current()))->Alloc(temp_r31_21495, NULL, 0);
    } else {
        var_r3_21503 = malloc(temp_r31_21495);
    }
    if (var_r3_21503 != NULL) {
        var_r3_21503->Gondola();
    }
    return (Gondola *) var_r3_21503;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<TotemPolePiece,
TotemPolePiece *ExPropCreatorHelper<TotemPolePiece, GamePropDescriptor>::Create(MKPropDescriptor *TotemPolePiece) {
    MKHeap *temp_r3_21581;
    MKHeap *temp_r3_21583;
    TrainChaseSpyro *var_r3_21590;
    s32 temp_r31_21582;

    temp_r3_21581 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21582 = temp_r3_21581->unk80;
    temp_r3_21583 = temp_r3_21581->Current();
    if (temp_r3_21583 != NULL) {
        var_r3_21590 = ((MKHeap *) (temp_r3_21583->Current()))->Alloc(temp_r31_21582, NULL, 0);
    } else {
        var_r3_21590 = malloc(temp_r31_21582);
    }
    if (var_r3_21590 != NULL) {
        var_r3_21590->TotemPolePiece();
    }
    return (TotemPolePiece *) var_r3_21590;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<TotemPolePuzzle,
TotemPolePuzzle *ExPropCreatorHelper<TotemPolePuzzle, GamePropDescriptor>::Create(MKPropDescriptor *TotemPolePuzzle) {
    MKHeap *temp_r3_21643;
    MKHeap *temp_r3_21645;
    TrainChaseSpyro *var_r3_21652;
    s32 temp_r31_21644;

    temp_r3_21643 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21644 = temp_r3_21643->unk80;
    temp_r3_21645 = temp_r3_21643->Current();
    if (temp_r3_21645 != NULL) {
        var_r3_21652 = ((MKHeap *) (temp_r3_21645->Current()))->Alloc(temp_r31_21644, NULL, 0);
    } else {
        var_r3_21652 = malloc(temp_r31_21644);
    }
    if (var_r3_21652 != NULL) {
        var_r3_21652->TotemPolePuzzle();
    }
    return (TotemPolePuzzle *) var_r3_21652;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<CynderBarracks,
CynderBarracks *ExPropCreatorHelper<CynderBarracks, CynderBarracksDescriptor>::Create(MKPropDescriptor *CynderBarracks) {
    MKHeap *temp_r3_21702;
    MKHeap *temp_r3_21704;
    TrainChaseSpyro *var_r3_21711;
    s32 temp_r31_21703;

    temp_r3_21702 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21703 = temp_r3_21702->unk80;
    temp_r3_21704 = temp_r3_21702->Current();
    if (temp_r3_21704 != NULL) {
        var_r3_21711 = ((MKHeap *) (temp_r3_21704->Current()))->Alloc(temp_r31_21703, NULL, 0);
    } else {
        var_r3_21711 = malloc(temp_r31_21703);
    }
    if (var_r3_21711 != NULL) {
        var_r3_21711->CynderBarracks();
    }
    return (CynderBarracks *) var_r3_21711;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<CynderPortcullis,
CynderPortcullis *ExPropCreatorHelper<CynderPortcullis, CynderPortcullisDescriptor>::Create(MKPropDescriptor *CynderPortcullis) {
    MKHeap *temp_r3_21782;
    MKHeap *temp_r3_21784;
    TrainChaseSpyro *var_r3_21791;
    s32 temp_r31_21783;

    temp_r3_21782 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21783 = temp_r3_21782->unk80;
    temp_r3_21784 = temp_r3_21782->Current();
    if (temp_r3_21784 != NULL) {
        var_r3_21791 = ((MKHeap *) (temp_r3_21784->Current()))->Alloc(temp_r31_21783, NULL, 0);
    } else {
        var_r3_21791 = malloc(temp_r31_21783);
    }
    if (var_r3_21791 != NULL) {
        var_r3_21791->CynderPortcullis();
    }
    return (CynderPortcullis *) var_r3_21791;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SiegeTower,
SiegeTower *ExPropCreatorHelper<SiegeTower, SiegeTowerDescriptor>::Create(MKPropDescriptor *SiegeTower) {
    MKHeap *temp_r3_21860;
    MKHeap *temp_r3_21862;
    TrainChaseSpyro *var_r3_21869;
    s32 temp_r31_21861;

    temp_r3_21860 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21861 = temp_r3_21860->unk80;
    temp_r3_21862 = temp_r3_21860->Current();
    if (temp_r3_21862 != NULL) {
        var_r3_21869 = ((MKHeap *) (temp_r3_21862->Current()))->Alloc(temp_r31_21861, NULL, 0);
    } else {
        var_r3_21869 = malloc(temp_r31_21861);
    }
    if (var_r3_21869 != NULL) {
        var_r3_21869->SiegeTower();
    }
    return (SiegeTower *) var_r3_21869;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SmashWall,
SmashWall *ExPropCreatorHelper<SmashWall, SmashWallDescriptor>::Create(MKPropDescriptor *SmashWall) {
    MKHeap *temp_r3_21944;
    MKHeap *temp_r3_21946;
    TrainChaseSpyro *var_r3_21953;
    s32 temp_r31_21945;

    temp_r3_21944 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_21945 = temp_r3_21944->unk80;
    temp_r3_21946 = temp_r3_21944->Current();
    if (temp_r3_21946 != NULL) {
        var_r3_21953 = ((MKHeap *) (temp_r3_21946->Current()))->Alloc(temp_r31_21945, NULL, 0);
    } else {
        var_r3_21953 = malloc(temp_r31_21945);
    }
    if (var_r3_21953 != NULL) {
        var_r3_21953->SmashWall();
    }
    return (SmashWall *) var_r3_21953;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<YawPlatform,
YawPlatform *ExPropCreatorHelper<YawPlatform, PlatformDescriptor>::Create(MKPropDescriptor *YawPlatform) {
    MKHeap *temp_r3_22001;
    MKHeap *temp_r3_22003;
    TrainChaseSpyro *var_r3_22010;
    s32 temp_r31_22002;

    temp_r3_22001 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22002 = temp_r3_22001->unk80;
    temp_r3_22003 = temp_r3_22001->Current();
    if (temp_r3_22003 != NULL) {
        var_r3_22010 = ((MKHeap *) (temp_r3_22003->Current()))->Alloc(temp_r31_22002, NULL, 0);
    } else {
        var_r3_22010 = malloc(temp_r31_22002);
    }
    if (var_r3_22010 != NULL) {
        var_r3_22010->YawPlatform();
    }
    return (YawPlatform *) var_r3_22010;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<WaterWheel,
WaterWheel *ExPropCreatorHelper<WaterWheel, PlatformDescriptor>::Create(MKPropDescriptor *WaterWheel) {
    MKHeap *temp_r3_22056;
    MKHeap *temp_r3_22058;
    TrainChaseSpyro *var_r3_22065;
    s32 temp_r31_22057;

    temp_r3_22056 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22057 = temp_r3_22056->unk80;
    temp_r3_22058 = temp_r3_22056->Current();
    if (temp_r3_22058 != NULL) {
        var_r3_22065 = ((MKHeap *) (temp_r3_22058->Current()))->Alloc(temp_r31_22057, NULL, 0);
    } else {
        var_r3_22065 = malloc(temp_r31_22057);
    }
    if (var_r3_22065 != NULL) {
        var_r3_22065->WaterWheel();
    }
    return (WaterWheel *) var_r3_22065;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<BarricadeProp,
BarricadeProp *ExPropCreatorHelper<BarricadeProp, ShatterableDescriptor>::Create(MKPropDescriptor *BarricadeProp) {
    MKHeap *temp_r3_22113;
    MKHeap *temp_r3_22115;
    TrainChaseSpyro *var_r3_22122;
    s32 temp_r31_22114;

    temp_r3_22113 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22114 = temp_r3_22113->unk80;
    temp_r3_22115 = temp_r3_22113->Current();
    if (temp_r3_22115 != NULL) {
        var_r3_22122 = ((MKHeap *) (temp_r3_22115->Current()))->Alloc(temp_r31_22114, NULL, 0);
    } else {
        var_r3_22122 = malloc(temp_r31_22114);
    }
    if (var_r3_22122 != NULL) {
        var_r3_22122->BarricadeProp();
    }
    return (BarricadeProp *) var_r3_22122;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<FightElevator,
FightElevator *ExPropCreatorHelper<FightElevator, FightElevatorDescriptor>::Create(MKPropDescriptor *FightElevator) {
    MKHeap *temp_r3_22170;
    MKHeap *temp_r3_22172;
    TrainChaseSpyro *var_r3_22179;
    s32 temp_r31_22171;

    temp_r3_22170 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22171 = temp_r3_22170->unk80;
    temp_r3_22172 = temp_r3_22170->Current();
    if (temp_r3_22172 != NULL) {
        var_r3_22179 = ((MKHeap *) (temp_r3_22172->Current()))->Alloc(temp_r31_22171, NULL, 0);
    } else {
        var_r3_22179 = malloc(temp_r31_22171);
    }
    if (var_r3_22179 != NULL) {
        var_r3_22179->FightElevator();
    }
    return (FightElevator *) var_r3_22179;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<FightElevatorAnchor,
FightElevatorAnchor *ExPropCreatorHelper<FightElevatorAnchor, ShatterableDescriptor>::Create(MKPropDescriptor *FightElevatorAnchor) {
    MKHeap *temp_r3_22236;
    MKHeap *temp_r3_22238;
    TrainChaseSpyro *var_r3_22245;
    s32 temp_r31_22237;

    temp_r3_22236 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22237 = temp_r3_22236->unk80;
    temp_r3_22238 = temp_r3_22236->Current();
    if (temp_r3_22238 != NULL) {
        var_r3_22245 = ((MKHeap *) (temp_r3_22238->Current()))->Alloc(temp_r31_22237, NULL, 0);
    } else {
        var_r3_22245 = malloc(temp_r31_22237);
    }
    if (var_r3_22245 != NULL) {
        var_r3_22245->FightElevatorAnchor();
    }
    return (FightElevatorAnchor *) var_r3_22245;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SolidSlug,
SolidSlug *ExPropCreatorHelper<SolidSlug, SolidSlugDescriptor>::Create(MKPropDescriptor *SolidSlug) {
    MKHeap *temp_r3_22293;
    MKHeap *temp_r3_22295;
    TrainChaseSpyro *var_r3_22302;
    s32 temp_r31_22294;

    temp_r3_22293 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22294 = temp_r3_22293->unk80;
    temp_r3_22295 = temp_r3_22293->Current();
    if (temp_r3_22295 != NULL) {
        var_r3_22302 = ((MKHeap *) (temp_r3_22295->Current()))->Alloc(temp_r31_22294, NULL, 0);
    } else {
        var_r3_22302 = malloc(temp_r31_22294);
    }
    if (var_r3_22302 != NULL) {
        var_r3_22302->SolidSlug();
    }
    return (SolidSlug *) var_r3_22302;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<IceShard,
IceShard *ExPropCreatorHelper<IceShard, IceShardDescriptor>::Create(MKPropDescriptor *IceShard) {
    MKHeap *temp_r3_22348;
    MKHeap *temp_r3_22350;
    TrainChaseSpyro *var_r3_22357;
    s32 temp_r31_22349;

    temp_r3_22348 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22349 = temp_r3_22348->unk80;
    temp_r3_22350 = temp_r3_22348->Current();
    if (temp_r3_22350 != NULL) {
        var_r3_22357 = ((MKHeap *) (temp_r3_22350->Current()))->Alloc(temp_r31_22349, NULL, 0);
    } else {
        var_r3_22357 = malloc(temp_r31_22349);
    }
    if (var_r3_22357 != NULL) {
        var_r3_22357->IceShard();
    }
    return (IceShard *) var_r3_22357;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SpeedwayAA,
SpeedwayAA *ExPropCreatorHelper<SpeedwayAA, SpeedwayAADescriptor>::Create(MKPropDescriptor *SpeedwayAA) {
    MKHeap *temp_r3_22403;
    MKHeap *temp_r3_22405;
    TrainChaseSpyro *var_r3_22412;
    s32 temp_r31_22404;

    temp_r3_22403 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22404 = temp_r3_22403->unk80;
    temp_r3_22405 = temp_r3_22403->Current();
    if (temp_r3_22405 != NULL) {
        var_r3_22412 = ((MKHeap *) (temp_r3_22405->Current()))->Alloc(temp_r31_22404, NULL, 0);
    } else {
        var_r3_22412 = malloc(temp_r31_22404);
    }
    if (var_r3_22412 != NULL) {
        var_r3_22412->SpeedwayAA();
    }
    return (SpeedwayAA *) var_r3_22412;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<CynderElecAttack,
CynderElecAttack *ExPropCreatorHelper<CynderElecAttack, CynderElecAttackDescriptor>::Create(MKPropDescriptor *CynderElecAttack) {
    MKHeap *temp_r3_22458;
    MKHeap *temp_r3_22460;
    TrainChaseSpyro *var_r3_22467;
    s32 temp_r31_22459;

    temp_r3_22458 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22459 = temp_r3_22458->unk80;
    temp_r3_22460 = temp_r3_22458->Current();
    if (temp_r3_22460 != NULL) {
        var_r3_22467 = ((MKHeap *) (temp_r3_22460->Current()))->Alloc(temp_r31_22459, NULL, 0);
    } else {
        var_r3_22467 = malloc(temp_r31_22459);
    }
    if (var_r3_22467 != NULL) {
        var_r3_22467->CynderElecAttack();
    }
    return (CynderElecAttack *) var_r3_22467;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<PoisonBomb,
PoisonBomb *ExPropCreatorHelper<PoisonBomb, PoisonBombDescriptor>::Create(MKPropDescriptor *PoisonBomb) {
    MKHeap *temp_r3_22513;
    MKHeap *temp_r3_22515;
    TrainChaseSpyro *var_r3_22522;
    s32 temp_r31_22514;

    temp_r3_22513 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22514 = temp_r3_22513->unk80;
    temp_r3_22515 = temp_r3_22513->Current();
    if (temp_r3_22515 != NULL) {
        var_r3_22522 = ((MKHeap *) (temp_r3_22515->Current()))->Alloc(temp_r31_22514, NULL, 0);
    } else {
        var_r3_22522 = malloc(temp_r31_22514);
    }
    if (var_r3_22522 != NULL) {
        var_r3_22522->PoisonBomb();
    }
    return (PoisonBomb *) var_r3_22522;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<ShatterablePlatform,
ShatterablePlatform *ExPropCreatorHelper<ShatterablePlatform, ShatterablePlatformDescriptor>::Create(MKPropDescriptor *ShatterablePlatform) {
    MKHeap *temp_r3_22575;
    MKHeap *temp_r3_22577;
    TrainChaseSpyro *var_r3_22584;
    s32 temp_r31_22576;

    temp_r3_22575 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22576 = temp_r3_22575->unk80;
    temp_r3_22577 = temp_r3_22575->Current();
    if (temp_r3_22577 != NULL) {
        var_r3_22584 = ((MKHeap *) (temp_r3_22577->Current()))->Alloc(temp_r31_22576, NULL, 0);
    } else {
        var_r3_22584 = malloc(temp_r31_22576);
    }
    if (var_r3_22584 != NULL) {
        var_r3_22584->ShatterablePlatform();
    }
    return (ShatterablePlatform *) var_r3_22584;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<CynderEnergyCrystal,
CynderEnergyCrystal *ExPropCreatorHelper<CynderEnergyCrystal, CynderEnergyCrystalDescriptor>::Create(MKPropDescriptor *CynderEnergyCrystal) {
    MKHeap *temp_r3_22610;
    MKHeap *temp_r3_22612;
    TrainChaseSpyro *var_r3_22619;
    s32 temp_r31_22611;

    temp_r3_22610 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22611 = temp_r3_22610->unk80;
    temp_r3_22612 = temp_r3_22610->Current();
    if (temp_r3_22612 != NULL) {
        var_r3_22619 = ((MKHeap *) (temp_r3_22612->Current()))->Alloc(temp_r31_22611, NULL, 0);
    } else {
        var_r3_22619 = malloc(temp_r31_22611);
    }
    if (var_r3_22619 != NULL) {
        var_r3_22619->CynderEnergyCrystal();
    }
    return (CynderEnergyCrystal *) var_r3_22619;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SquishBoulder,
SquishBoulder *ExPropCreatorHelper<SquishBoulder, SquishBoulderDescriptor>::Create(MKPropDescriptor *SquishBoulder) {
    MKHeap *temp_r3_22668;
    MKHeap *temp_r3_22670;
    TrainChaseSpyro *var_r3_22677;
    s32 temp_r31_22669;

    temp_r3_22668 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22669 = temp_r3_22668->unk80;
    temp_r3_22670 = temp_r3_22668->Current();
    if (temp_r3_22670 != NULL) {
        var_r3_22677 = ((MKHeap *) (temp_r3_22670->Current()))->Alloc(temp_r31_22669, NULL, 0);
    } else {
        var_r3_22677 = malloc(temp_r31_22669);
    }
    if (var_r3_22677 != NULL) {
        var_r3_22677->SquishBoulder();
    }
    return (SquishBoulder *) var_r3_22677;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<ShatterableBoat,
ShatterableBoat *ExPropCreatorHelper<ShatterableBoat, ShatterableBoatDescriptor>::Create(MKPropDescriptor *ShatterableBoat) {
    MKHeap *temp_r3_22758;
    MKHeap *temp_r3_22760;
    TrainChaseSpyro *var_r3_22767;
    s32 temp_r31_22759;

    temp_r3_22758 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22759 = temp_r3_22758->unk80;
    temp_r3_22760 = temp_r3_22758->Current();
    if (temp_r3_22760 != NULL) {
        var_r3_22767 = ((MKHeap *) (temp_r3_22760->Current()))->Alloc(temp_r31_22759, NULL, 0);
    } else {
        var_r3_22767 = malloc(temp_r31_22759);
    }
    if (var_r3_22767 != NULL) {
        var_r3_22767->ShatterableBoat();
    }
    return (ShatterableBoat *) var_r3_22767;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Leviathan,
Leviathan *ExPropCreatorHelper<Leviathan, PlatformDescriptor>::Create(MKPropDescriptor *Leviathan) {
    MKHeap *temp_r3_22822;
    MKHeap *temp_r3_22824;
    TrainChaseSpyro *var_r3_22831;
    s32 temp_r31_22823;

    temp_r3_22822 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22823 = temp_r3_22822->unk80;
    temp_r3_22824 = temp_r3_22822->Current();
    if (temp_r3_22824 != NULL) {
        var_r3_22831 = ((MKHeap *) (temp_r3_22824->Current()))->Alloc(temp_r31_22823, NULL, 0);
    } else {
        var_r3_22831 = malloc(temp_r31_22823);
    }
    if (var_r3_22831 != NULL) {
        var_r3_22831->Leviathan();
    }
    return (Leviathan *) var_r3_22831;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<MagicDrain,
MagicDrain *ExPropCreatorHelper<MagicDrain, MagicDrainDescriptor>::Create(MKPropDescriptor *MagicDrain) {
    MKHeap *temp_r3_22884;
    MKHeap *temp_r3_22886;
    TrainChaseSpyro *var_r3_22893;
    s32 temp_r31_22885;

    temp_r3_22884 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22885 = temp_r3_22884->unk80;
    temp_r3_22886 = temp_r3_22884->Current();
    if (temp_r3_22886 != NULL) {
        var_r3_22893 = ((MKHeap *) (temp_r3_22886->Current()))->Alloc(temp_r31_22885, NULL, 0);
    } else {
        var_r3_22893 = malloc(temp_r31_22885);
    }
    if (var_r3_22893 != NULL) {
        var_r3_22893->MagicDrain();
    }
    return (MagicDrain *) var_r3_22893;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<ScryingPool,
ScryingPool *ExPropCreatorHelper<ScryingPool, ScryingPoolDescriptor>::Create(MKPropDescriptor *ScryingPool) {
    MKHeap *temp_r3_22941;
    MKHeap *temp_r3_22943;
    TrainChaseSpyro *var_r3_22950;
    s32 temp_r31_22942;

    temp_r3_22941 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22942 = temp_r3_22941->unk80;
    temp_r3_22943 = temp_r3_22941->Current();
    if (temp_r3_22943 != NULL) {
        var_r3_22950 = ((MKHeap *) (temp_r3_22943->Current()))->Alloc(temp_r31_22942, NULL, 0);
    } else {
        var_r3_22950 = malloc(temp_r31_22942);
    }
    if (var_r3_22950 != NULL) {
        var_r3_22950->ScryingPool();
    }
    return (ScryingPool *) var_r3_22950;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Arrow,
Arrow *ExPropCreatorHelper<Arrow, ArrowDescriptor>::Create(MKPropDescriptor *Arrow) {
    MKHeap *temp_r3_22996;
    MKHeap *temp_r3_22998;
    TrainChaseSpyro *var_r3_23005;
    s32 temp_r31_22997;

    temp_r3_22996 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_22997 = temp_r3_22996->unk80;
    temp_r3_22998 = temp_r3_22996->Current();
    if (temp_r3_22998 != NULL) {
        var_r3_23005 = ((MKHeap *) (temp_r3_22998->Current()))->Alloc(temp_r31_22997, NULL, 0);
    } else {
        var_r3_23005 = malloc(temp_r31_22997);
    }
    if (var_r3_23005 != NULL) {
        var_r3_23005->Arrow();
    }
    return (Arrow *) var_r3_23005;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<ArrowTrap,
ArrowTrap *ExPropCreatorHelper<ArrowTrap, ArrowTrapDescriptor>::Create(MKPropDescriptor *ArrowTrap) {
    MKHeap *temp_r3_23053;
    MKHeap *temp_r3_23055;
    TrainChaseSpyro *var_r3_23062;
    s32 temp_r31_23054;

    temp_r3_23053 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23054 = temp_r3_23053->unk80;
    temp_r3_23055 = temp_r3_23053->Current();
    if (temp_r3_23055 != NULL) {
        var_r3_23062 = ((MKHeap *) (temp_r3_23055->Current()))->Alloc(temp_r31_23054, NULL, 0);
    } else {
        var_r3_23062 = malloc(temp_r31_23054);
    }
    if (var_r3_23062 != NULL) {
        var_r3_23062->ArrowTrap();
    }
    return (ArrowTrap *) var_r3_23062;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<BoulderRamp,
BoulderRamp *ExPropCreatorHelper<BoulderRamp, BoulderRampDescriptor>::Create(MKPropDescriptor *BoulderRamp) {
    MKHeap *temp_r3_23110;
    MKHeap *temp_r3_23112;
    TrainChaseSpyro *var_r3_23119;
    s32 temp_r31_23111;

    temp_r3_23110 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23111 = temp_r3_23110->unk80;
    temp_r3_23112 = temp_r3_23110->Current();
    if (temp_r3_23112 != NULL) {
        var_r3_23119 = ((MKHeap *) (temp_r3_23112->Current()))->Alloc(temp_r31_23111, NULL, 0);
    } else {
        var_r3_23119 = malloc(temp_r31_23111);
    }
    if (var_r3_23119 != NULL) {
        var_r3_23119->BoulderRamp();
    }
    return (BoulderRamp *) var_r3_23119;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Chest,
Chest *ExPropCreatorHelper<Chest, ChestDescriptor>::Create(MKPropDescriptor *Chest) {
    MKHeap *temp_r3_23182;
    MKHeap *temp_r3_23184;
    TrainChaseSpyro *var_r3_23191;
    s32 temp_r31_23183;

    temp_r3_23182 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23183 = temp_r3_23182->unk80;
    temp_r3_23184 = temp_r3_23182->Current();
    if (temp_r3_23184 != NULL) {
        var_r3_23191 = ((MKHeap *) (temp_r3_23184->Current()))->Alloc(temp_r31_23183, NULL, 0);
    } else {
        var_r3_23191 = malloc(temp_r31_23183);
    }
    if (var_r3_23191 != NULL) {
        var_r3_23191->Chest();
    }
    return (Chest *) var_r3_23191;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Door,
Door *ExPropCreatorHelper<Door, DoorDescriptor>::Create(MKPropDescriptor *Door) {
    MKHeap *temp_r3_23239;
    MKHeap *temp_r3_23241;
    TrainChaseSpyro *var_r3_23248;
    s32 temp_r31_23240;

    temp_r3_23239 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23240 = temp_r3_23239->unk80;
    temp_r3_23241 = temp_r3_23239->Current();
    if (temp_r3_23241 != NULL) {
        var_r3_23248 = ((MKHeap *) (temp_r3_23241->Current()))->Alloc(temp_r31_23240, NULL, 0);
    } else {
        var_r3_23248 = malloc(temp_r31_23240);
    }
    if (var_r3_23248 != NULL) {
        var_r3_23248->Door();
    }
    return (Door *) var_r3_23248;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<FireTrap,
FireTrap *ExPropCreatorHelper<FireTrap, FireTrapDescriptor>::Create(MKPropDescriptor *FireTrap) {
    MKHeap *temp_r3_23274;
    MKHeap *temp_r3_23276;
    TrainChaseSpyro *var_r3_23283;
    s32 temp_r31_23275;

    temp_r3_23274 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23275 = temp_r3_23274->unk80;
    temp_r3_23276 = temp_r3_23274->Current();
    if (temp_r3_23276 != NULL) {
        var_r3_23283 = ((MKHeap *) (temp_r3_23276->Current()))->Alloc(temp_r31_23275, NULL, 0);
    } else {
        var_r3_23283 = malloc(temp_r31_23275);
    }
    if (var_r3_23283 != NULL) {
        var_r3_23283->FireTrap();
    }
    return (FireTrap *) var_r3_23283;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<FloorSwitch,
FloorSwitch *ExPropCreatorHelper<FloorSwitch, FloorSwitchDescriptor>::Create(MKPropDescriptor *FloorSwitch) {
    MKHeap *temp_r3_23331;
    MKHeap *temp_r3_23333;
    TrainChaseSpyro *var_r3_23340;
    s32 temp_r31_23332;

    temp_r3_23331 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23332 = temp_r3_23331->unk80;
    temp_r3_23333 = temp_r3_23331->Current();
    if (temp_r3_23333 != NULL) {
        var_r3_23340 = ((MKHeap *) (temp_r3_23333->Current()))->Alloc(temp_r31_23332, NULL, 0);
    } else {
        var_r3_23340 = malloc(temp_r31_23332);
    }
    if (var_r3_23340 != NULL) {
        var_r3_23340->FloorSwitch();
    }
    return (FloorSwitch *) var_r3_23340;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<KnifeTrap,
KnifeTrap *ExPropCreatorHelper<KnifeTrap, KnifeTrapDescriptor>::Create(MKPropDescriptor *KnifeTrap) {
    MKHeap *temp_r3_23396;
    MKHeap *temp_r3_23398;
    TrainChaseSpyro *var_r3_23405;
    s32 temp_r31_23397;

    temp_r3_23396 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23397 = temp_r3_23396->unk80;
    temp_r3_23398 = temp_r3_23396->Current();
    if (temp_r3_23398 != NULL) {
        var_r3_23405 = ((MKHeap *) (temp_r3_23398->Current()))->Alloc(temp_r31_23397, NULL, 0);
    } else {
        var_r3_23405 = malloc(temp_r31_23397);
    }
    if (var_r3_23405 != NULL) {
        var_r3_23405->KnifeTrap();
    }
    return (KnifeTrap *) var_r3_23405;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<LavaCannon,
LavaCannon *ExPropCreatorHelper<LavaCannon, LavaCannonDescriptor>::Create(MKPropDescriptor *LavaCannon) {
    MKHeap *temp_r3_23453;
    MKHeap *temp_r3_23455;
    TrainChaseSpyro *var_r3_23462;
    s32 temp_r31_23454;

    temp_r3_23453 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23454 = temp_r3_23453->unk80;
    temp_r3_23455 = temp_r3_23453->Current();
    if (temp_r3_23455 != NULL) {
        var_r3_23462 = ((MKHeap *) (temp_r3_23455->Current()))->Alloc(temp_r31_23454, NULL, 0);
    } else {
        var_r3_23462 = malloc(temp_r31_23454);
    }
    if (var_r3_23462 != NULL) {
        var_r3_23462->LavaCannon();
    }
    return (LavaCannon *) var_r3_23462;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SpikeTrap,
SpikeTrap *ExPropCreatorHelper<SpikeTrap, SpikeTrapDescriptor>::Create(MKPropDescriptor *SpikeTrap) {
    MKHeap *temp_r3_23510;
    MKHeap *temp_r3_23512;
    TrainChaseSpyro *var_r3_23519;
    s32 temp_r31_23511;

    temp_r3_23510 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23511 = temp_r3_23510->unk80;
    temp_r3_23512 = temp_r3_23510->Current();
    if (temp_r3_23512 != NULL) {
        var_r3_23519 = ((MKHeap *) (temp_r3_23512->Current()))->Alloc(temp_r31_23511, NULL, 0);
    } else {
        var_r3_23519 = malloc(temp_r31_23511);
    }
    if (var_r3_23519 != NULL) {
        var_r3_23519->SpikeTrap();
    }
    return (SpikeTrap *) var_r3_23519;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<LavaBall,
LavaBall *ExPropCreatorHelper<LavaBall, LavaBallDescriptor>::Create(MKPropDescriptor *LavaBall) {
    MKHeap *temp_r3_23575;
    MKHeap *temp_r3_23577;
    TrainChaseSpyro *var_r3_23584;
    s32 temp_r31_23576;

    temp_r3_23575 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23576 = temp_r3_23575->unk80;
    temp_r3_23577 = temp_r3_23575->Current();
    if (temp_r3_23577 != NULL) {
        var_r3_23584 = ((MKHeap *) (temp_r3_23577->Current()))->Alloc(temp_r31_23576, NULL, 0);
    } else {
        var_r3_23584 = malloc(temp_r31_23576);
    }
    if (var_r3_23584 != NULL) {
        var_r3_23584->LavaBall();
    }
    return (LavaBall *) var_r3_23584;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Dynamite,
Dynamite *ExPropCreatorHelper<Dynamite, DynamiteDescriptor>::Create(MKPropDescriptor *Dynamite) {
    MKHeap *temp_r3_23630;
    MKHeap *temp_r3_23632;
    TrainChaseSpyro *var_r3_23639;
    s32 temp_r31_23631;

    temp_r3_23630 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23631 = temp_r3_23630->unk80;
    temp_r3_23632 = temp_r3_23630->Current();
    if (temp_r3_23632 != NULL) {
        var_r3_23639 = ((MKHeap *) (temp_r3_23632->Current()))->Alloc(temp_r31_23631, NULL, 0);
    } else {
        var_r3_23639 = malloc(temp_r31_23631);
    }
    if (var_r3_23639 != NULL) {
        var_r3_23639->Dynamite();
    }
    return (Dynamite *) var_r3_23639;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<Sludge,
Sludge *ExPropCreatorHelper<Sludge, SludgeDescriptor>::Create(MKPropDescriptor *Sludge) {
    MKHeap *temp_r3_23692;
    MKHeap *temp_r3_23694;
    TrainChaseSpyro *var_r3_23701;
    s32 temp_r31_23693;

    temp_r3_23692 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23693 = temp_r3_23692->unk80;
    temp_r3_23694 = temp_r3_23692->Current();
    if (temp_r3_23694 != NULL) {
        var_r3_23701 = ((MKHeap *) (temp_r3_23694->Current()))->Alloc(temp_r31_23693, NULL, 0);
    } else {
        var_r3_23701 = malloc(temp_r31_23693);
    }
    if (var_r3_23701 != NULL) {
        var_r3_23701->Sludge();
    }
    return (Sludge *) var_r3_23701;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<HotSpit,
HotSpit *ExPropCreatorHelper<HotSpit, HotSpitDescriptor>::Create(MKPropDescriptor *HotSpit) {
    MKHeap *temp_r3_23747;
    MKHeap *temp_r3_23749;
    TrainChaseSpyro *var_r3_23756;
    s32 temp_r31_23748;

    temp_r3_23747 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23748 = temp_r3_23747->unk80;
    temp_r3_23749 = temp_r3_23747->Current();
    if (temp_r3_23749 != NULL) {
        var_r3_23756 = ((MKHeap *) (temp_r3_23749->Current()))->Alloc(temp_r31_23748, NULL, 0);
    } else {
        var_r3_23756 = malloc(temp_r31_23748);
    }
    if (var_r3_23756 != NULL) {
        var_r3_23756->HotSpit();
    }
    return (HotSpit *) var_r3_23756;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<MagicFireball,
MagicFireball *ExPropCreatorHelper<MagicFireball, MagicFireballDescriptor>::Create(MKPropDescriptor *MagicFireball) {
    MKHeap *temp_r3_23802;
    MKHeap *temp_r3_23804;
    TrainChaseSpyro *var_r3_23811;
    s32 temp_r31_23803;

    temp_r3_23802 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23803 = temp_r3_23802->unk80;
    temp_r3_23804 = temp_r3_23802->Current();
    if (temp_r3_23804 != NULL) {
        var_r3_23811 = ((MKHeap *) (temp_r3_23804->Current()))->Alloc(temp_r31_23803, NULL, 0);
    } else {
        var_r3_23811 = malloc(temp_r31_23803);
    }
    if (var_r3_23811 != NULL) {
        var_r3_23811->MagicFireball();
    }
    return (MagicFireball *) var_r3_23811;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<IceBossStomp,
IceBossStomp *ExPropCreatorHelper<IceBossStomp, IceBossStompDescriptor>::Create(MKPropDescriptor *IceBossStomp) {
    MKHeap *temp_r3_23859;
    MKHeap *temp_r3_23861;
    TrainChaseSpyro *var_r3_23868;
    s32 temp_r31_23860;

    temp_r3_23859 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23860 = temp_r3_23859->unk80;
    temp_r3_23861 = temp_r3_23859->Current();
    if (temp_r3_23861 != NULL) {
        var_r3_23868 = ((MKHeap *) (temp_r3_23861->Current()))->Alloc(temp_r31_23860, NULL, 0);
    } else {
        var_r3_23868 = malloc(temp_r31_23860);
    }
    if (var_r3_23868 != NULL) {
        var_r3_23868->IceBossStomp();
    }
    return (IceBossStomp *) var_r3_23868;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<SonicAttack,
SonicAttack *ExPropCreatorHelper<SonicAttack, SonicAttackDescriptor>::Create(MKPropDescriptor *SonicAttack) {
    MKHeap *temp_r3_23914;
    MKHeap *temp_r3_23916;
    TrainChaseSpyro *var_r3_23923;
    s32 temp_r31_23915;

    temp_r3_23914 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23915 = temp_r3_23914->unk80;
    temp_r3_23916 = temp_r3_23914->Current();
    if (temp_r3_23916 != NULL) {
        var_r3_23923 = ((MKHeap *) (temp_r3_23916->Current()))->Alloc(temp_r31_23915, NULL, 0);
    } else {
        var_r3_23923 = malloc(temp_r31_23915);
    }
    if (var_r3_23923 != NULL) {
        var_r3_23923->SonicAttack();
    }
    return (SonicAttack *) var_r3_23923;
}
#endif

#if 0 // DRAFT: identifier 'ExPropCreatorHelper<FlyingMonkey,
FlyingMonkey *ExPropCreatorHelper<FlyingMonkey, FlyingMonkeyDescriptor>::Create(MKPropDescriptor *FlyingMonkey) {
    MKHeap *temp_r3_23969;
    MKHeap *temp_r3_23971;
    TrainChaseSpyro *var_r3_23978;
    s32 temp_r31_23970;

    temp_r3_23969 = checked_cast<KDPropExDescriptor *, MKPropDescriptor>(&this->unk0);
    temp_r31_23970 = temp_r3_23969->unk80;
    temp_r3_23971 = temp_r3_23969->Current();
    if (temp_r3_23971 != NULL) {
        var_r3_23978 = ((MKHeap *) (temp_r3_23971->Current()))->Alloc(temp_r31_23970, NULL, 0);
    } else {
        var_r3_23978 = malloc(temp_r31_23970);
    }
    if (var_r3_23978 != NULL) {
        var_r3_23978->FlyingMonkey();
    }
    return (FlyingMonkey *) var_r3_23978;
}
#endif

#if 0 // DRAFT: identifier 'checked_cast<...>(T1 *)' redeclared
void checked_cast<KDPropExDescriptor *, MKPropDescriptor>(MKPropDescriptor *arg0) {

}
#endif

void CreationTable_cpp::__sinit() {
    f32 temp_f0_24561;
    f64 temp_f1_24542;
    f64 temp_f1_24550;
    f64 temp_f3_24530;
    f64 temp_f4_24539;
    f64 temp_f4_24547;
    f64 temp_f8_24532;

    temp_f3_24530 = __frsqrte(2014000.0);
    temp_f8_24532 = __frsqrte(380000.0);
    temp_f4_24539 = 0.5 * temp_f3_24530 * -((2014000.0 * (temp_f3_24530 * temp_f3_24530)) - 3.0);
    temp_f1_24542 = 0.5 * temp_f8_24532 * -((380000.0 * (temp_f8_24532 * temp_f8_24532)) - 3.0);
    temp_f4_24547 = 0.5 * temp_f4_24539 * -((2014000.0 * (temp_f4_24539 * temp_f4_24539)) - 3.0);
    temp_f1_24550 = 0.5 * temp_f1_24542 * -((380000.0 * (temp_f1_24542 * temp_f1_24542)) - 3.0);
    temp_f0_24561 = (f32) (380000.0 * (0.5 * temp_f1_24550 * -((380000.0 * (temp_f1_24550 * temp_f1_24550)) - 3.0)));
    SPYRO_BOUNCE_Y_SPEED = (f32) (2014000.0 * (0.5 * temp_f4_24547 * -((2014000.0 * (temp_f4_24547 * temp_f4_24547)) - 3.0)));
    SPYRO_MIN_JUMP_Y_VELOCITY = temp_f0_24561;
}
