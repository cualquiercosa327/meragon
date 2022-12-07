#pragma once

#include "types.h"
#include <sead/math/seadMatrix.h>
#include <sead/math/seadVector.h>

namespace al {

enum SensorType {
    SensorType_Eye,
    SensorType_Player,
    SensorType_Npc,
    SensorType_Ride,
    SensorType_Enemy,
    SensorType_EnemyBody,
    SensorType_EnemyAttack,
    SensorType_Dossun,
    SensorType_KillerMagnum,
    SensorType_EnemySimple,
    SensorType_MapObj,
    SensorType_MapObjSimple,
    SensorType_Bindable,
    SensorType_CollisionParts,
    SensorType_KickKoura,
    SensorType_PlayerFireBall,
    SensorType_WooGanSandBody
};

class LiveActor;
class HitSensor {
    const char* mName;
    SensorType mSensorType;
    u32 _8;
    u32 _C;
    float _10;
    float _14;
    u16 mMaxSensorCount;
    u16 mSensorCount;
    HitSensor** mSensors;
    int _20;
    bool mIsValidBySystem;
    bool mIsValid;
    LiveActor* mHostActor;
    sead::Vector3f* mFollowPos;
    sead::Matrix34f* mFollowMtx;
    sead::Vector3f _34;

public:
    const char* getName() { return mName; }
    LiveActor* getHost() { return mHostActor; }

    friend class HitSensorKeeper;
};

bool isHitCylinderSensor(HitSensor*, HitSensor*, const sead::Vector3f&, float);

} // namespace al
