//MultiDimensionalArrayAccess From C++ In PAWN
/*
* Default Includes
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <assert.h>
/*
* AMX Includes
*/
#include "./SDK/amx/amx.h"
#include "./SDK/plugincommon.h"

extern void * pAMXFunctions;

using namespace std;  

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() 
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load( void **ppData ) 
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];

	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload( )
{

}

/*
Analytic data

[dimension 1][dimension 2][dimension 3]->information headers{header 1, header 2}
[2][2]->2{8,12}
[2][3]->2{8,16}
[2][4]->2{8,20}
[2][5]->2{8,24}
[2][6]->2{8,28}
[2][7]->2{8,32}

[3][2]->3{12,16,20}
[3][3]->3{12,20,28}
[3][4]->3{12,24,36}
[3][5]->3{12,28,44}
[3][6]->3{12,32,52}
[3][7]->3{12,36,60}

[2][2][2]->6{8,12,16,20,24,28}
[2][2][3]->6{8,12,16,24,32,40}
[2][2][4]->6{8,12,16,28,40,52}

[2][3][2]->8{8,16,24,28,32,36,40,44}
[2][3][3]->8{8,16,24,32,40,48,56,64}
[2][3][4]->8{8,16,24,36,48,60,72,84}

[3][2][2]->9{12,16,20,24,28,32,36,40,44}
[3][2][3]->9{12,16,20,24,32,40,48,56,64}
[3][2][4]->9{12,16,20,24,36,48,60,72,84}

[3][3][2]->12{12,20,28,36,40,44,48,52,56,60,64,68}
[3][3][3]->12{12,20,28,36,44,52,60,68,76,84,92,100}
[3][3][4]->12{12,20,28,36,48,60,72,84,96,108,120,132}

conclusion:

tabbing:
[m][n]->|m|{m*sizeof(cell) bytes}|{array data[m*n*sizeof(cell) bytes]}|
[m][n][o]->|m*n+n|{m*sizeof(cell)+m*n*sizeof(cell) bytes}|{array data[m*n*o*sizeof(cell) bytes]}|
*/

class PawnArray1D
{
private:
	cell * _address;
	size_t _size;
public:
	PawnArray1D(cell * address, size_t size)
	{
		_address = address;
		_size = size;
	}
	PawnArray1D(AMX* amx, cell& param_array, size_t size)
	{
		amx_GetAddr(amx, param_array, &_address);
		_size = size;
	}
	~PawnArray1D(){}

	size_t GetSize()
	{
		return _size;
	}
	cell &operator()(size_t i)
	{
		return _address[i];
	}
	cell &operator[](size_t index)
	{
		return _address[index];
	}
};

class PawnArray2D 
{
private:
	cell * _address;
	size_t _size[2];
public:
	PawnArray2D(cell * address, size_t size_x, size_t size_y)
	{
		_address = address;
		_size[0] = size_x;
		_size[1] = size_y;
	}
	PawnArray2D(AMX* amx, cell& param_array, size_t size_x, size_t size_y)
	{
		amx_GetAddr(amx, param_array, &_address);
		_size[0] = size_x;
		_size[1] = size_y;
	}
	~PawnArray2D(){}

	size_t GetSize(size_t dimension)
	{
		return _size[dimension];
	}

	cell &operator()(size_t i, size_t j)
	{
		return PawnArray1D((_address + _size[0]) + i*_size[1], _size[1])(j);
		//return *((_address+_size[0])+i*_size[1]+j);
	}
	PawnArray1D &operator[](size_t index)
	{
		return PawnArray1D((_address + _size[0]) + index*_size[1], _size[1]);
	}
};

class PawnArray3D
{
private:
	cell * _address;
	size_t _size[3];
public:
	PawnArray3D(cell * address, size_t size_x, size_t size_y, size_t size_z)
	{
		_address = (cell*)address;
		_size[0] = size_x;
		_size[1] = size_y;
		_size[2] = size_z;
	}
	PawnArray3D(AMX* amx, cell& param_array, size_t size_x, size_t size_y, size_t size_z)
	{
		amx_GetAddr(amx, param_array, &_address);
		_size[0] = size_x;
		_size[1] = size_y;
		_size[2] = size_z;
	}
	~PawnArray3D(){}

	size_t GetSize(size_t dimension)
	{
		return _size[dimension];
	}
	cell &operator()(size_t i, size_t j, size_t k)
	{
		return PawnArray2D((_address + (_size[0] * _size[1]) + ((_size[1]*_size[2])*i)), _size[0], _size[2])(j, k);
		//return *((_address+_size[0])+i*_size[1]+j);
	}
	PawnArray2D &operator[](size_t index)
	{
		return PawnArray2D((_address + (_size[0] * _size[1]) + ((_size[1] * _size[2])*index)), _size[0], _size[2]);
	}
};

static cell AMX_NATIVE_CALL n_TestMultiDimensionalArray1(AMX* amx, cell* params)
{
	printf("TestMultiDimensionalArray1\r\n\tparams[2]-> %d\r\n", params[2]);

	PawnArray1D pawn_array(amx, params[1], params[2]);

	for (int i = 0; i < pawn_array.GetSize(); ++i)
	{
		printf("\t\tarray1[%d] -> %08x\r\n", i, pawn_array[i]);
		pawn_array[i] = 5;
	}
	return 1;
}

static cell AMX_NATIVE_CALL n_TestMultiDimensionalArray2(AMX* amx, cell* params)
{
	printf("TestMultiDimensionalArray2\r\n\tparams[2]-> %d\r\n\tparams[3]-> %d\r\n", params[2], params[3]);
	cell *dest = NULL;
	amx_GetAddr(amx, params[1], &dest);
	PawnArray2D pawn_array(dest, params[2], params[3]);

	for (int i = 0; i < pawn_array.GetSize(0); ++i)
	{
		for (int j = 0; j < pawn_array.GetSize(1); ++j)
		{
			printf("\t\tarray2[%d][%d] -> %08x\r\n", i, j, pawn_array[i][j]);
			pawn_array[i][j] = 5;
		}
	}
	return 2;
}

static cell AMX_NATIVE_CALL n_TestMultiDimensionalArray3(AMX* amx, cell* params)
{
	printf("TestMultiDimensionalArray3\r\n\tparams[2]-> %d\r\n\tparams[3]-> %d\r\n\tparams[4]-> %d\r\n", params[2], params[3], params[4]);
	
	cell *dest = NULL;
	amx_GetAddr(amx, params[1], &dest);
	PawnArray3D pawn_array(dest, params[2], params[3], params[4]);

	for (int i = 0; i < pawn_array.GetSize(0); ++i)
	{
		for (int j = 0; j < pawn_array.GetSize(1); ++j)
		{
			for (int k = 0; k < pawn_array.GetSize(2); ++k)
			{
				printf("\t\tarray3[%d][%d][%d] -> %08x\r\n", i, j, k, pawn_array[i][j][k]);
				pawn_array[i][j][k] = 5;
			}
		}
	}
	return 3;
}

AMX_NATIVE_INFO AMXNatives[ ] =
{
	{ "TestMultiDimensionalArray1", n_TestMultiDimensionalArray1 },
	{ "TestMultiDimensionalArray2", n_TestMultiDimensionalArray2 },
	{ "TestMultiDimensionalArray3", n_TestMultiDimensionalArray3 }
};


PLUGIN_EXPORT int PLUGIN_CALL AmxLoad( AMX *amx ) 
{
	return amx_Register( amx, AMXNatives, -1 );
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload( AMX *amx ) 
{
	return AMX_ERR_NONE;
}