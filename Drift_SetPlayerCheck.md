# Drift\_SetPlayerCheck #

The Drift\_SetPlayerCheck function enables/disables (per-player or for everyone) checking if somebody drifts.


If you disabled it for somebody, his drifts won't be counted.


## The Code ##
```PAWN

native Drift_SetPlayerCheck(playerid = (-1),enable = 1);
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|enabled  |Integer|Set the status 1 - enabled, 0 - disabled|
|playerid |Integer|The player to set it for, -1 for all players|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
Drift_SetPlayerCheck();//will enable the drift checking on all players
Drift_SetPlayerCheck(55,0);//will disable cheking playerid 55 for drifts
return 1;
}
```

#### NOTE ####
