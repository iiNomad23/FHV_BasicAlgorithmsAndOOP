/*
	hashtable

	Author: Marco Prescher
	Created on: 22.04.2021
*/

#pragma once

#include "person.h"

typedef struct Map Map_t;

Map_t* map_create(int size);
void map_destroy(Map_t** ppMap);
int map_set(Map_t* pMap, Person_t* pPers);
Person_t* map_get(Map_t* pMap, int key);
int map_has(Map_t* pMap, Person_t* pPers);

int map_print(Map_t* pMap);