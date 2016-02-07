# Drift\_GetCheckForFlags #

The Drift\_GetCheckForFlags function gets the status of the FLAG checking for a player.


## The Code ##
```PAWN

native Drift_GetCheckForFlags(playerid = (0));
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|playerid |Integer|The player to get the FLAG CHECK status from, -1 is invalid|

|Returns|This function returns the status, enabled - 1, disabled - 0|
|:------|:----------------------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
new status = Drift_GetCheckForFlags(2);
//above code will get the Flag Check
//status of playerid 2
return 1;
}
```