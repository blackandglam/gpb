# Drift\_GetPlayerCheck #

The Drift\_GetPlayerCheck function gets the status of the checking for player drifts.


## The Code ##
```PAWN

native Drift_GetPlayerCheck(playerid = (0));
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|playerid |Integer|The player to get the drift checking status from, -1 is invalid|

|Returns|This function returns the status, enabled - 1, disabled - 0|
|:------|:----------------------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
new status = Drift_GetPlayerCheck(4);
//above code will get the Drift Check
//status of playerid 4
return 1;
}
```