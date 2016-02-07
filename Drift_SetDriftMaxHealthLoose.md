# Drift\_SetDriftMaxHealthLoose #

The Drift\_SetDriftMaxHealthLoose function sets how many heal a players vehicle may loose (per-player or for everyone, per hit).


## The Code ##
```PAWN

native Drift_SetDriftMaxHealthLoose(Float:MaximalHealthLoose = 0.0,playerid = (-1));
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|MaximalHealthLoose|Float|Set the amount of health that a vehicle may loose per hit|
|playerid |Integer|The player to set it for, -1 for all players|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
Drift_SetDriftMaxHealthLoose();
//Will disallow all players to reduce the
//heal points of their car whilst drifting,
//if they do the drift will get canceled
Drift_SetDriftMaxHealthLoose(20.0,44);
//playerid 44 may loose 20 hp per hit
return 1;
}
```

**See also:**


DriftSet\_DamageCheck


OnPlayerDriftEnd