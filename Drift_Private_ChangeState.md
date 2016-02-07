<div>
<div>Note:</div>
<table cellpadding='6' cellspacing='0' border='0' width='100%'>
<tr>
<td>
<div>This function has been removed in <a href='https://code.google.com/p/gpb/source/detail?r=21'>revision 21</a></div>

</td>
</tr>
</table>
<h1>Drift_Private_ChangeState</h1>

The Drift_Private_ChangeState function is used internally by the plugin to update the vector list of players,<br>
<br>
it is not recomended to use this function on your own except if you know what you are doing.<br>
<br>
<h2>The Code</h2>
<pre><code><br>
native Drift_Private_ChangeState(playerid,newstate);</code></pre>

<h2>Syntax</h2>
<table><thead><th>Parameter</th><th>Type</th><th>Description</th></thead><tbody>
<tr><td>playerid </td><td>Integer</td><td>The playerid who changed state</td></tr>
<tr><td>newstate </td><td>Integer</td><td>The new state of the player</td></tr></tbody></table>

<table><thead><th>Returns</th><th>This function returns values from -1 to 3 depending on failure/success</th></thead><tbody>