# [Drift\_DeleteFLAG](Drift_DeleteFLAG.md) #

The [Drift\_DeleteFLAG](Drift_DeleteFLAG.md) function can delete an existing FLAG.


If [Drift\_AddFLAG](Drift_AddFLAG.md) was not used it is possible to recover it with [Drift\_EnableFLAG](Drift_EnableFLAG.md).


## The Code ##
```PAWN

native [Drift_DeleteFLAG](flagid);
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|flagid   |Integer|the flagid to delete|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
new MyFlag = [Drift_AddFLAG](462.283,2576.455,953.235);
[Drift_DeleteFLAG](MyFlag);
[Drift_EnableFLAG](MyFlag);//recover it
return 1;
}
```