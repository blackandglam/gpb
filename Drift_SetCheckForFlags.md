# Drift\_SetCheckForFlags #

The Drift\_SetCheckForFlags function enables/disables (per-player or for everyone) the checking if somebody drifts near a FLAG.


## The Code ##
```PAWN

native Drift_SetCheckForFlags(enabled = 1,playerid =(-1));
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
Drift_SetCheckForFlags();//will enable the checking for plags for all players
Drift_SetCheckForFlags(0,22);//will disable FLAG checking for playerid 22
return 1;
}
```