# [Drift\_ClearModelList](Drift_ClearModelList.md) #

With [Drift\_ClearModelList](Drift_ClearModelList.md) you can disable the drifting for all models at once.

## The Code ##
```PAWN

native [Drift_ClearModelList]();```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|This function has no parameters|    | |

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|

## Usage ##

```PAWN

public OnFilterScriptInit()
{
[Drift_ClearModelList]();
//will disable all model ids to drift
Drift_AllowModel(411);
//will allow the vehicle model 411 (infernus) to drift,
//all other vehicles won't be able to drift
return 1;
}
```