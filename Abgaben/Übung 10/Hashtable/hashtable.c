/*
	hashtable

	Author: Marco Prescher
	Created on: 22.04.2021
*/

#include <stdio.h>
#include "hashtable.h"

// 0 = Lineare Kollisionsstrategie
// 1 = Quadratische Kollisionsstrategie
// 2 = Doppelhashing
#define MODE 2

// forward declarations --------------------------------------------------------------------------------------------------------
typedef struct Map {
	int size;
	Person_t** values;
} Map_t;

static int getFinalHashValue(int mode, int key, int mapSize, int i);
static int getHash_h(int key, int m);
static int getHash_p(int key, int m);
// -----------------------------------------------------------------------------------------------------------------------------

// function definitions --------------------------------------------------------------------------------------------------------
Map_t* map_create(int size) {
	Map_t* pMap = malloc(sizeof(Map_t));

	if (pMap != NULL) {
		pMap->size = size;
		pMap->values = malloc(sizeof(Person_t*) * size);

		if (pMap->values == NULL) {
			free(pMap);
			pMap = NULL;
		}
		else {
			for (int i = 0; i < size; i++) {
				pMap->values[i] = NULL;
			}
		}
	}

	return pMap;
}
void map_destroy(Map_t** ppMap) {
	if ((*ppMap) != NULL) {
		if ((*ppMap)->values != NULL) {
			free((*ppMap)->values);
			(*ppMap)->values = NULL;
		}

		free((*ppMap));
		(*ppMap) = NULL;
	}
}
int map_set(Map_t* pMap, Person_t* pPers) {
	if (pMap != NULL && pPers != NULL) {
		int key = pPers->niNumber;
		int mapSize = pMap->size;

		int i = 0;
		do
		{
			int hashValue = getFinalHashValue(MODE, key, mapSize, i);

			if (pMap->values[hashValue] == NULL) {
				printf("\nInsert %s at %d\n", pPers->name, hashValue);
				pMap->values[hashValue] = pPers;

				return 1;
			}
			else {
				printf("\nCollision at %d", hashValue);
			}

			i++;
		} while (i < mapSize);
	}

	return 0;
}

Person_t* map_get(Map_t* pMap, int key) {
	return pMap->values[key];
}

int map_has(Map_t* pMap, Person_t* pPers) {
	if (pMap != NULL && pPers != NULL) {
		int key = pPers->niNumber;
		int mapSize = pMap->size;

		int i = 0;
		do {
			int hashValue = getFinalHashValue(MODE, key, mapSize, i);

			if (pMap->values[hashValue] == pPers) {
				return 1;
			}

			i++;
		} while (i < mapSize);
	}

	return 0;
}

int map_print(Map_t* pMap) {
	printf("\n\nMap contains: \n\n");

	if (pMap != NULL) {
		for (int i = 0; i < pMap->size; i++) {
			if (pMap->values[i] != NULL) {
				printf("Key: %d\t Value: %s\n", i, pMap->values[i]->name);
			}
		}
	}
}

// intern functions --------------------------------
static int getHash_h(int key, int mapSize) {
	return key % mapSize;

}
static int getHash_p(int key, int mapSize) {
	return 1 + (key % (mapSize - 1));
}
static int getFinalHashValue(int mode, int key, int mapSize, int i) {
	int h = getHash_h(key, mapSize);

	if (mode == 0) {
		return (h + i) % mapSize;
	}
	else if (mode == 1) {
		return (h + (i * i)) % mapSize;
	}
	else {
		int p = getHash_p(key, mapSize);

		return (h + i * p) % mapSize;
	}
}
// -----------------------------------------------------------------------------------------------------------------------------