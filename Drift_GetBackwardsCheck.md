# Drift\_GetBackwardsCheck #

The Drift\_GetBackwardsCheck function gets the status of allowed backwards drifts for player.


## The Code ##
```PAWN

native Drift_GetBackwardsCheck(playerid = 0);
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|playerid |Integer|The player to get the backwards checking status from, -1 is invalid|

|Returns|This function returns the status, enabled - 1 (backwars drifting not allowed), disabled - 0 (backwards drifting allowed)|
|:------|:-----------------------------------------------------------------------------------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
new status = Drift_GetBackwardsCheck(98);
//above code will get the Backwards Drifting Check
//status of playerid 98
return 1;
}
```