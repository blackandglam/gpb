# IsPlayerDrifting #

With IsPlayerDrifting you can get the status if the player is drifting or not.

## The Code ##
```PAWN

native IsPlayerDrifting(playerid);```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|playerid |Integer|The player to get the Drifting info from|

|Returns|Returns player long drifting status, 1 if drift started, 0 if OnPlayerDriftEnd has been already called|
|:------|:-----------------------------------------------------------------------------------------------------|

## Usage ##

```PAWN

public OnPlayerUpdate(playerid)
{
if(IsPlayerDrifting(playerid) == 1)
{
print("player %d is in a drift!",playerid);
}
else
{
//player is not in a drift
}
return 1;
}
```