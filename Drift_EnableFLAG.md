# [Drift\_EnableFLAG](Drift_EnableFLAG.md) #

The [Drift\_EnableFLAG](Drift_EnableFLAG.md) function can enable an disabled FLAG.


## The Code ##
```PAWN

native [Drift_EnableFLAG](flagid);
```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|flagid   |Integer|the flagid to enable|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
new MyFlag = [Drift_AddFLAG](462.283,2576.455,953.235);
[Drift_DisableFLAG](MyFlag);
[Drift_EnableFLAG](MyFlag);
return 1;
}
```