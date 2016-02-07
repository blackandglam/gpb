# Drift\_GetDriftMaxHealthLoose #

The Drift\_GetDriftMaxHealthLoose function gets the amount of max health that a vehicle may loose per hit per player.


## The Code ##
```PAWN

native Drift_GetDriftMaxHealthLoose(&Float:MaximalHealthLoose,playerid = (0));
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|MaximalHealthLoose|(Return Value)Float|The amount of health that may be lost|
|playerid |Integer|The playerid to get the info from|

|Returns|This function returns the status, enabled - 1 (backwars drifting not allowed), disabled - 0 (backwards drifting allowed)|
|:------|:-----------------------------------------------------------------------------------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
new Float:MaxLoose;
Drift_GetDriftMaxHealthLoose(MaxLoose,35);
//Above code will assign to MaxLoose the maximal
//heal that the car of playerid 35 may loose
//per hit
return 1;
}
```