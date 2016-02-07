# [Drift\_DisableFLAG](Drift_DisableFLAG.md) #

The [Drift\_DisableFLAG](Drift_DisableFLAG.md) function can disable an enabled FLAG.


The flag won't be counted when somebody drifts near it.


## The Code ##
```PAWN

native [Drift_DisableFLAG](flagid);
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|flagid   |Integer|the flagid to disable|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
new MyFlag = [Drift_AddFLAG](462.283,2576.455,953.235);
[Drift_DisableFLAG](MyFlag);
return 1;
}
```