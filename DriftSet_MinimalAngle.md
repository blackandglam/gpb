# DriftSet\_MinimalAngle #

Note: It is recomended that you read the 'DriftingAngle' article to understand this function better.

With DriftSet\_MinimalAngle you can set the minimal needed drift angle (in degrees).

## The Code ##
```PAWN

native DriftSet_MinimalAngle(Float:MinimalAngle,playerid = (-1));```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|MinimalAngle|Float|The amount of degrees|
|playerid |Integer|The player to set for, use -1 to set for all players|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|

## Usage ##

```PAWN

public OnFilterScriptInit()
{
DriftSet_MinimalAngle(12.5);
//Above code will set the minimal drifting
//angle of 12.5 degrees for all players

DriftSet_MinimalAngle(25.0,12);
//Above code will set the minimal drifting
//angle of 25.0 degrees for player with id 12
return 1;
}
```