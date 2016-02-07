# Drift\_GetGlobalCheck #

The Drift\_GetGlobalCheck function returns info on if the plugin is enabled or disabled.



## The Code ##
```PAWN

native Drift_GetGlobalCheck();```

## Syntax ##
|Parameter|Type|Description|
|:--------|:---|:----------|
|This function has no parameters|    |           |

|Returns|1 if the plugin is enabled or 0 when the plugin is disable|
|:------|:---------------------------------------------------------|


## Usage ##


```PAWN

public OnFilterScriptInit()
{
if(Drift_SetGlobalCheck() == 0)//checks if the plugin is disabled
{
Drift_SetGlobalCheck();//enables the plugin
}
return 1;
}
```