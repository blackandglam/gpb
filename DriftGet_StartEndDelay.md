# DriftGet\_StartEndDelay #

With DriftGet\_StartEndDelay you can get the maximal time (in ticks) to resume a drift before it is canceled.

## The Code ##
```PAWN

native DriftGet_StartEndDelay(playerid = (0));```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|playerid |Integer|The playerid to get his StartEndDelay, -1 is invalid here|

|Returns|Returns the amount of ticks for the players StartEndDelay|
|:------|:--------------------------------------------------------|

## Usage ##

```PAWN

public OnFilterScriptInit()
{
new playerdelay = 0;
playerdelay = DriftGet_StartEndDelay(0);
//Above code will get the drifting delay
//for playerid 0and store it in 'playerdelay'
return 1;
}
```