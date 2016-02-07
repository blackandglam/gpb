# [IsPlayerDrifting\_precise](IsPlayerDrifting_precise.md) #

With [IsPlayerDrifting\_precise](IsPlayerDrifting_precise.md) you can get the status if the player is ACTUALLY (at the moment) drifting or not.

## The Code ##
```PAWN

native [IsPlayerDrifting_precise](playerid);```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|playerid |Integer|The player to get the Drifting info from|

|Returns|Returns player short drifting status, 1 if in drift, 0 if not|
|:------|:------------------------------------------------------------|

## Usage ##

```PAWN

public OnPlayerUpdate(playerid)
{
if(IsPlayerDrifting(playerid) == 1)
{
if([IsPlayerDrifting_precise](playerid) == 1)
{
print("player %d is in a drift and IS actually drifting!",playerid);
}
else
{
print("player %d is in a drift but IS NOT drifting!",playerid);
}
}
else
{
//player is not in a drift
}
return 1;
}
```