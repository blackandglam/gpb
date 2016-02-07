# GPS Plugin a.k.a. RouteConnector #

With the help of this plugin you can manage routes on the roades easily, and also manipulate the information.
This plugin is a recommended 'must have' for RP and trucking servers.

## Pre-Definitions ##
```PAWN

#define MAX_NODES					(32768)

#define MAX_CONNECTIONS				(5)


#define CONNECT_TYPE_BOTH			(0)//used for 2-way connecting of nodes

#define CONNECT_TYPE_One_To_Two		(1)//used for directional connecting of nodes
```

## Functions ##

```PAWN
 native AddNode(Float:X,Float:Y,Float:Z,AddToPathFinder = 0);```<pre>
Function:<br>
AddNode<br>
Description:<br>
Adds a node into the memory of the plugin,<br>
This node will be unavailable in route calculations.<br>
Parameters:<br>
Position as X Y Z<br>
AddToPathFinder - if set to 1 it will also make sure the graph will be updated so when searching for a route it will be added to the list.<br>
Returns the added nodeID, -1 if failed.<br>
Note:<br>
NEVER EVER set AddToPathFinder to 1 when a calculation is in progress! THAT IS YOUR OWN RESPOSIBILITY IF IT HAPPENS.<br>
<br>
</pre>```PAWN
 native AddNodeEx(ID,Float:X,Float:Y,Float:Z,AddToPathFinder = 0);```<pre>
Function:<br>
AddNodeEx<br>
Description:<br>
The only difference with AddNode is that you can specify your own NodeID here.<br>
Gaps may now be present.<br>
Parameters:<br>
ID as Custom NodeID<br>
Position as X Y Z<br>
AddToPathFinder - if set to 1 it will also make sure the graph will be updated so when searching for a route it will be added to the list.<br>
Returns the added nodeID, -1 if failed.<br>
Note:<br>
NEVER EVER set AddToPathFinder to 1 when a calculation is in progress! THAT IS YOUR OWN RESPOSIBILITY IF IT HAPPENS.<br>
</pre>


```PAWN
 native ConnectNodes(NodeID_one,NodeID_two,AddToPathFinder = 0,direction = 0);```<pre>

Function:<br>
ConnectNodes<br>
Description:<br>
This will connect two nodes stored in memory, same rules as for AddNode(Ex), it won't be available in path calculations.<br>
When you connect NodeID_one with NodeID_two it will automaticly connect the opposite, no distance suplying is needed as the XYZ are supplied at node creation.<br>
Parameters:<br>
NodeID_one and NodeID_two as NodeID's<br>
AddToPathFinder - if set to 1 it will also make sure the graph will be updated so when searching for a route it will be added to the list.<br>
direction - you can choose to only connect nodeID one with nodeID two (One_To_Two = 1) or to connect them together (BOTH = 0)<br>
Returns:<br>
<br>
Anything above or equal to 0 means success (the NodeOne[connectid] is retuned), else failure.<br>
Note:<br>
NEVER EVER set AddToPathFinder to 1 when a calculation is in progress! THAT IS YOUR OWN RESPOSIBILITY IF IT HAPPENS.<br>
<br>
</pre>```PAWN
 native NearestPlayerNode(playerid,Float:MaxDist=9999.99,IgnoreNodeID=(-1));```<pre>

Function:<br>
NearestPlayerNode<br>
Description:<br>
This function will get the closest player node, if you used AddNode(Ex) this nodes will also be considered.<br>
Parameters:<br>
playerid - the playerid to count from<br>
MaxDist - the maximal distance to search from the player<br>
IgnoreNodeID - this node ID will not be returned as the closest one, it will be ignored in the search.<br>
Returns the closest nodeID, -1 if no node Id is found in range<br>
<br>
</pre>```PAWN
 native NearestNodeFromPoint(Float:X,Float:Y,Float:Z,Float:MaxDist=9999.99,IgnoreNodeID=(-1));```<pre>

Function:<br>
NearestNodeFromPoint<br>
Description:<br>
Same as NearestPlayerNode, but here you can supply an point instead of an playerid<br>
Parameters:<br>
XYZ - the position of the point to search from<br>
MaxDist - the maximal distance to search from the player<br>
IgnoreNodeID - this node ID will not be returned as the closest one, it will be ignored in the search.<br>
Returns the closest nodeID, -1 if no node Id is found in range<br>
<br>
</pre>```PAWN
 native WriteNodesToFile(filename[]);```<pre>

Function:<br>
WriteNodesToFile<br>
Description:<br>
Write all nodes, connections, contents of the memory into an loadable file,<br>
can be used by ReadNodesFromFile later.<br>
Parameters:<br>
filename -	the "path/filename.extension" to store the information in,<br>
note that if you want to make a file in the scriptfiles folder you need to supply:<br>
WriteNodesToFile("scriptfiles/your.file.name");<br>
Returns 1 on success, 0 on failure.<br>
<br>
</pre>```PAWN
 native ReadNodesFromFile(filename[]);```<pre>

Function:<br>
ReadNodesFromFile<br>
Description:<br>
Read all nodes, connections, contents of the file into the memory,<br>
This function will automaticly create nodes, connect them, create the virtual graph to search paths on<br>
after it has been loaded into the memory.<br>
Parameters:<br>
filename -	the "path/filename.extension" to read the information from,<br>
note that if you want to read a file in the scriptfiles folder you need to supply:<br>
ReadNodesFromFile("scriptfiles/your.file.name");<br>
Warning:<br>
It is not recommended to use this funcion, use at your own risk.<br>
The plugin calls this function only at server startup, however I have included it for you.<br>
You still can make aditional nodes with it (if you analyse the project source code correctly, you will know what I mean)<br>
Returns 1 on success, 0 on failure.<br>
<br>
</pre>```PAWN
 native GetNodePos(NodeID,&Float:X,&Float:Y,&Float:Z);```<pre>

Function:<br>
GetNodePos<br>
Description:<br>
Get the XYZ position of the supplied NodeID<br>
Parameters:<br>
NodeID - The NodeID to get the XYZ from<br>
(returns) X Y Z - The XYZ positions.<br>
Returns 0 on failure (Out Of Range?), -1 if node doesn't exist, 1 on success.<br>
<br>
</pre>```PAWN
 native CalculatePath(Start,End,routeID = 0);```<pre>//Threaded calculating, everything done here will be added to an Queue<br>
<br>
Function:<br>
CalculatePath<br>
Description:<br>
Get the XYZ position of the supplied NodeID<br>
Parameters:<br>
Start - The start NodeID<br>
End - the destination NodeID<br>
routeID (optional) - [custom integer supply] Here you can specify an integer value that will be passed<br>
to the callback, along with the calculated path information, for example the PlayerID.<br>
Note:<br>
if you will be using the routeID parameter for recognizing routes, make sure they all are unique,<br>
once started route search cannot be aborted and will just be queued and the callback will still be called.<br>
<br>
This function is Threaded, this means that if the CalculatePath search takes 3 seconds, it won't lagg your server.<br>
Your server will continue to work normally.<br>
<br>
Only the callback in the script which calls the plugin will get executed with this, if you do CalculatePath in Script1,<br>
and have your callback in Script2 then it won't get executed<br>
<br>
Returns always 1.<br>
<br>
</pre>```PAWN
 native IsNodeIntersection(NodeID);```<pre>

Function:<br>
IsNodeIntersection<br>
Description:<br>
Check if a node has 3 or more connections<br>
Parameters:<br>
NodeID - The ID of the node<br>
Return 1 if true, 0 if false, -1 if node doesn't exist.<br>
<br>
</pre>```PAWN
 native Float:GetAngleBetweenNodes(NodeID_one,NodeID_middle_aka_two,NodeID_three);```<pre>

Function:<br>
GetAngleBetweenNodes (Returns Float)<br>
Description:<br>
Gets the angle between 3 nodes (2 connections/lines).<br>
Parameters:<br>
NodeID* - The ID of the node<br>
Return 0.0 if one of the three nodes doesn't exist<br>
<br>
</pre>```PAWN
 native GetConnectedNodes(NodeID);```<pre>

Function:<br>
GetConnectedNodes<br>
Description:<br>
returns the amount of other nodes that are connected to this node, max is 5<br>
Parameters:<br>
NodeID* - The ID of the node<br>
Returns amount of nodes connected (0 to 5), on failure -1.<br>
<br>
</pre>```PAWN
 native GetNextEmptyNodeID();```<pre>

Function:<br>
GetNextEmptyNodeID<br>
Description:<br>
returns the closest empty node ID (closest starting from 0 to up);<br>
Note:<br>
Example:<br>
<br>
new id = GetNextEmptyNodeID();<br>
if(id != -1)AddNodeEx(id,X,Y,Z);<br>
<br>
However this example results in:<br>
<br>
AddNode(X,Y,Z);<br>
Returns -1 if no more available node slots.<br>
<br>
</pre>```PAWN
 native GetQueueSize();```<pre>

Function:<br>
GetQueueSize<br>
Description:<br>
gets the size of all queued path calculations to do.<br>
Returns -1 if the vector was locked when tried to access (Threading crash prevention), else it returns the vector size.<br>
<br>
</pre>```PAWN
 native GetConnectedNodeID(NodeID,ConnectID);```<pre>

Function:<br>
GetConnectedNodeID<br>
Description:<br>
gets the ID of an connection to NodeID, -1 if ConnectID has no connection, connectid must be between 0 and (MAX_CONNECTIONS-1), however there is OFB prevention check.<br>
<br>
</pre>```PAWN
 native Float:GetConnectedNodeDistance(NodeID,ConnectID);```<pre>

Function:<br>
GetConnectedNodeDistance (Returns Float)<br>
Description:<br>
gets the distance to a connected node (ConnectID) from the selected node (NodeID).<br>
<br>
</pre>```PAWN
 native Float:GetDistanceBetweenNodes(NodeID_one,NodeID_two);```<pre>

Function:<br>
GetDistanceBetweenNodes (Returns Float)<br>
Description:<br>
gets the distance between the two nodes (NOT VIA OTHER NODES, THIS JUST DOES THE X Y Z POSITION CALCULATION).<br>
<br>
</pre>```PAWN
 native IsNodeInPathFinder(NodeID);```<pre>

Function:<br>
IsNodeInPathFinder<br>
Description:<br>
Checks if NodeID is added to the routecalculator.<br>
Returns -1 if the NodeID is invalid and 0 if node is not in the route calculator, 1 if yes.<br>
<br>
</pre>```PAWN
 native GetRouteArray(ID,destination[],size = sizeof(destination));```<pre>

Function:<br>
GetRouteArray<br>
Description:<br>
Stores an saved array with assigned ID to destination[]<br>
Returns the amount of nodes in array at ID, Returns 0 if array is empty or ID doesn't exist.<br>
<br>
</pre>```PAWN
 native GetRouteAtPos(ID,Array_Pos,&amount_of_nodes=0);```<pre>

Function:<br>
GetRouteAtPos<br>
Description:<br>
Returns the NodeID in array[Array_Pos] at ID.<br>
Optionally you can specify an variable to store the amount of nodes in it.<br>
<br>
</pre>```PAWN
 native StoreRouteArray(amount_of_nodes,array[]);```<pre>

Function:<br>
StoreRouteArray<br>
Description:<br>
Stores an array to the plugins vector memory, returns the ID you can use in GetRouteArray or DeleteArray.<br>
<br>
</pre>```PAWN
 native DeleteArray(ID);```<pre>

Function:<br>
DeleteArray<br>
Description:<br>
Remove contents of the memory at ID.<br>
<br>
</pre>```PAWN
 native AddExistingNodeToPathFinder(NodeID);```<pre>

Function:<br>
AddExistingNodeToPathFinder<br>
Description:<br>
Adds an created node to the routecalculator.<br>
Returns -1 if the NodeID is invalid and 0 if node id does not exist or is already added, 1 on success.<br>
<br>
</pre>```PAWN
 native RemoveNode(NodeID);```<pre>

Function:<br>
RemoveNode<br>
Description:<br>
Deletes an node from the memory, to use in Write data, nodes loaded into the calculator won't be deleted, connections too.<br>
Returns -1 if the NodeID is invalid and 0 if node id does not exist, 1 on success.<br>
<br>
</pre>```PAWN
 native DisconnectNodeFromNode(NodeIDOne,NodeIDTwo);```<pre>

Function:<br>
DisconnectNodeFromNode<br>
Description:<br>
Disconnects Node ID One from Two, please see RemoveNode for information about the calculator memory.<br>
Returns -1 if the NodeID is invalid and 0 if node id does not exist, 1 on success.<br>
<br>
</pre>```PAWN
 native DisconnectAllFromNode(NodeID);```<pre>

Function:<br>
DisconnectAllFromNode<br>
Description:<br>
Disconnects all other nodes from NodeID, and NodeID from them.<br>
Returns -1 if the NodeID is invalid and 0 if node id does not exist, 1 on success.<br>
<br>
</pre>```PAWN
 native DeleteNodeSystemAtNode(NodeID,array[],size = sizeof(array));```<pre>

Function:<br>
DeleteNodeSystemAtNode<br>
Description:<br>
Get ALL nodeIDs that are CONNECTED IN ANY WAY, ALSO VIA OTHER NODES to NodeID into the array[].<br>
Usefull for deleting big-not-connected chunks of nodes.<br>
Returns 0 on failure, the array size on success.<br>
<br>
</pre>```PAWN
 native GetNodeDirectionToConnect(NodeID,ConnectID);```<pre>

Function:<br>
GetNodeDirectionToConnect<br>
Description:<br>
Get the direction this node[connectid] is connected in,<br>
0 means that :<br>
connectid is connected to nodeid<br>
nodeid is connected to connectid<br>
1 means that:<br>
nodeid is connected to connectid<br>
connectid is NOT connected to nodeid<br>
2 means that:<br>
nodeid is NOT connected to connectid<br>
connectid is connected to nodeid<br>
Note:<br>
Usefull for making 'left and right' road sides.<br>
Returns -1 on failure.<br>
<br>
</pre>```PAWN
 native SetNodeDirectionToConnect(NodeID,ConectID,Direction);```<pre>

Function:<br>
SetNodeDirectionToConnect<br>
Description:<br>
See GetNodeDirectionToConnect, this SETS the direction manually.<br>
It automaticly get the nodeID of 'ConectID' and sets the connection_direction to the good value.<br>
Returns 0 on failure, 1 on success.<br>
<br>
</pre>```PAWN
 native NodeExists(NodeID);```<pre>

Function:<br>
NodeExists<br>
Description:<br>
Checks if the given nodeID exists in the memory.<br>
Returns 0 if not, 1 if yes, -1 on failure.<br>
<br>
</pre>```PAWN
 native RemoveAllRouteIDFromQueue(routeid);```<pre>

Function:<br>
RemoveAllRouteIDFromQueue<br>
Description:<br>
Removes all pending calculations with 'routeid' from the queue.<br>
Returns -1 if the Queue is locked/accessed, else it returns the amount of entries deleted.<br>
<br>
</pre>```PAWN
 forward GPS_WhenRouteIsCalculated(routeid,node_id_array[],amount_of_nodes,distance);>//Every processed Queue will be called here
```<pre>
Called when a path finding calculation is done.<br>
<br>
routeid - the id you specified for recognition of calls<br>
node_id_array -	this array is up to 1792 cells long<br>
it is build from the following information:<br>
<br>
node_id_array[0] ... node_id_array[1791] -<br>
all points (Node ID's) on the route<br>
in following order:<br>
from start, to end<br>
amount_of_nodes - this is the amount of nodes the total path is, is set to 0 when it's impossible to calculate the route.<br>
distance - the total distance all nodes take, rounded to an integer, is -1 if it's impossible to calculate the route.<br>
so you can do:<br>
public GPS_WhenRouteIsCalculated(routeid,node_id_array[],amount_of_nodes,distance)<br>
{<br>
for(new i = 0; i < amount_of_nodes; ++i)<br>
{<br>
printf("Point(%d)=NodeID(%d)",i,node_id_array[i]);<br>
}<br>
return 1;<br>
}<br>
<br>
</pre>```PAWN
forward OnPlayerClosestNodeIDChange(playerid,old_NodeID,new_NodeID);```<pre>

Called when a player's closest nodeID changes.<br>
<br>
playerid - the id of the player<br>
old_NodeID and new_NodeID - the node ID's, old and new.<br>
new_NodeID is 'now' the closest node ID.<br>
<br>
<br>
</pre>```PAWN
 native GetGPSdatVersion();```<pre>

Function:<br>
GetGPSdatVersion<br>
Description:<br>
Gets the file version of GPS.dat<br>
Returns -1 if getting the GPS.dat version failed, else it returns the version number, this function is only available since package 162<br>
<br>
</pre>```PAWN
 native GetPluginVersion();```<pre>

Function:<br>
GetPluginVersion<br>
Description:<br>
Gets the plugin version<br>
Returns the plugin version, this function is only available since package 162<br>
<br>
</pre>```PAWN
 stock GetIncludeVersion();```<pre>

Function:<br>
GetIncludeVersion<br>
Description:<br>
Gets the include file version<br>
Returns the inclde file version, this function is only available since package 162<br>
</pre>