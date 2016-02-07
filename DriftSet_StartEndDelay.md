# DriftSet\_StartEndDelay #

With DriftSet\_StartEndDelay you can set the maximal time (in ticks) to resume a drift before it is canceled.

Note: callback OnPlayerDriftEnd is called when the drift resume time is over.

<b>Warning: Keep this delay lower than the update delay (See DriftSet_UpdateDelay)!</b>

## The Code ##
```PAWN

native DriftSet_StartEndDelay(delay,playerid = (-1));```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|delay    |Integer|The amount of ticks|
|playerid |Integer|The player to set for, -1 to set for all players|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|

## Usage ##

```PAWN

public OnFilterScriptInit()
{
DriftSet_StartEndDelay(40);
//Above code will set the drifting delay
//for all players to 40 ticks

DriftSet_StartEndDelay(20,23);
//Above code will set the drifting delay
//for playerid 23 to 20 ticks
return 1;
}
```