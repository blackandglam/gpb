# Drift\_SetBackwardsCheck #

The Drift\_SetBackwardsCheck function enables/disables (per-player or for everyone) backwards drifting.


## The Code ##
```PAWN

native Drift_SetBackwardsCheck(enabled = 1,playerid =(-1));
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|enabled  |Integer|Set the status 1 - enabled (backwards drifting not possible), 0 - disabled (backwards drifting possible)|
|playerid |Integer|The player to set it for, -1 for all players|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
Drift_SetBackwardsCheck();//will disable backwards drifts for all players
Drift_SetBackwardsCheck(0,21);//will allow playerid 21 to drift backwards
return 1;
}
```