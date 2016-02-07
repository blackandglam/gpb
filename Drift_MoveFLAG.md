# [Drift\_MoveFLAG](Drift_MoveFLAG.md) #

The [Drift\_MoveFLAG](Drift_MoveFLAG.md) function moves an existing FLAG to a new position.


## The Code ##
```PAWN

native [Drift_MoveFLAG](flagid,Float:X,Float:Y,Float:Z);
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|flagid   |Integer|the flagid to move|
|X        |Float|The new X position|
|Y        |Float|The new Y position|
|Z        |Float|The new Z position|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
new MyFlag = [Drift_AddFLAG](462.283,2576.455,953.235);
[Drift_MoveFLAG](MyFlag,765.353,9876.343,12.34586);
return 1;
}
```