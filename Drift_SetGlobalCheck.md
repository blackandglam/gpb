# Drift\_SetGlobalCheck #

The Drift\_SetGlobalCheck function can be used to temporary disable/enable the plugin so it will not count any drifts.


If the plugin is 'disabled' all natives can be still used safely.



## The Code ##
```PAWN

native Drift_SetGlobalCheck(enable = 1);```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|enable   |Integer|enable(1)/disable(0) the checking if anyone drifts|

|Returns|This function does not return a specific value|
|:------|:---------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
Drift_SetGlobalCheck();//enables the plugin
Drift_SetGlobalCheck(0);//disables the plugin
return 1;
}
```