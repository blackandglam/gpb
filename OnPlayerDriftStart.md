# OnPlayerDriftStart #

The OnPlayerDriftStart callback is called when a player meets all requirements`*` to start a drift.

## The Code ##
```PAWN

forward OnPlayerDriftStart(playerid);```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|playerid |Integer|The playerid who starts drifting|

|Returns|This callback does not return a specific value|
|:------|:---------------------------------------------|

## Usage ##

```PAWN

public OnPlayerDriftStart(playerid)
{
SendClientMessage(playerid,0xFFFFFFFF,"You started drifting!");
return 1;
}
```


`*` Please see:

DriftSet\_MinimalAngle

DriftSet\_MinimalSpeed