# DriftGet\_Divider #

With DriftGet\_Divider you can get the points divider for OnPlayerDriftUpdate and OnPlayerDriftEnd.

## The Code ##
```PAWN

native DriftGet_Divider(playerid = (0));```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|playerid |Integer|The player to get the divider from, -1 is invalid|

|Returns|Returns the divider|
|:------|:------------------|

## Usage ##

```PAWN

public OnFilterScriptInit()
{
new divider = DriftGet_Divider(0);
//The above code will get the divider
//of playerid 0
return 1;
}
```