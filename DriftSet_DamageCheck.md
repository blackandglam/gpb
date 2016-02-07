# DriftSet\_DamageCheck #

With DriftSet\_DamageCheck you can set the option to check for damage while drifting.

## The Code ##
```PAWN

native DriftSet_DamageCheck(enable = 1,playerid = (-1),Float:MaxHealthLoose = 0.0);```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|enable   |Integer|1 - enabled, 0 - disabled|
|playerid |Integer|The player to set the DamageCheck, -1 means all players|
|MaxHealthLoose|Float|The max amount of heal points the car may loose per hit|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|

## Usage ##

```PAWN

public OnFilterScriptInit()
{
DriftSet_DamageCheck(1,-1,3.0);
//enables (1) damage checking for all players (second param -1)
//and players may damage their cars by max 3 heal points
//per hit

DriftSet_DamageCheck(0,-1,0.0);
//disables (0) damage checking for all players (second param -1)

DriftSet_DamageCheck(1,12,0.0);
//enables (1) damage checking for playerid 12
//players vehicle may not be damaged while drifting

return 1;
}
```

## Extra ##

Callback OnPlayerDriftEnd is called when players vehicle heal has exceeded the MaxHealthLoose variable.