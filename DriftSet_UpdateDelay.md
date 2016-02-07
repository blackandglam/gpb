# DriftSet\_UpdateDelay #

With DriftSet\_UpdateDelay you can set the amount of ticks between drift updates.

## The Code ##
```PAWN

native DriftSet_UpdateDelay(delay);```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|delay    |Integer| The amount of ticks between each loop through players who are in vehicles as drivers|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|

## Usage ##

```PAWN

public OnFilterScriptInit()
{
DriftSet_UpdateDelay(40);
return 1;
}
```
This code will set the delay to 40 ticks.