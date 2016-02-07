# DriftGet\_DamageCheck #

With DriftGet\_DamageCheck you can get the option to check for damage while drifting.

## The Code ##
```PAWN

native DriftGet_DamageCheck(playerid = (0),&Float:MaxHealthLoose = 0.0);```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|playerid |Integer|The player to get the DamageCheck from, -1 is invalid|
|MaxHealthLoose|(Return Value)Float|Assigns a variable the max health points thay may be lost per hit|

|Returns|Returns the enabled status, 0 if disable, 1 if enabled|
|:------|:-----------------------------------------------------|

## Usage ##

```PAWN

public OnFilterScriptInit()
{
new Float:MaxLoose;
new status = DriftGet_DamageCheck(4,MaxLoose);
//gets the status of the damage check on playerid 4
//and assigns MaxLoose the maximal health that has been set
//to may loose per hit
return 1;
}
```