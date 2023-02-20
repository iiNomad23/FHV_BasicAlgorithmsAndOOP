/*
	hashtable

	Author: Marco Prescher
	Created on: 22.04.2021
*/

#include <stdio.h>

#include "hashtable.h"
#include "person.h"

// forward declarations --------------------------------------------------------------------------------------------------------
int test_hashTable();
// -----------------------------------------------------------------------------------------------------------------------------

int main(int argc, char* argv[]) {
	Person_t hugo = {1, "Hugo"};
	Person_t maria = {4, "Maria"};
	Person_t daisy = {3, "Daisy"};
	Person_t donald = {6, "Donald"};
	Person_t bob = {6, "Bob"};

	Map_t* pMap = map_create(10);

	printf("Set: %s %s\n", hugo.name, (map_set(pMap, &hugo) ? "added" : "not added"));
	printf("Set: %s %s\n", maria.name, (map_set(pMap, &maria) ? "added" : "not added"));
	printf("Set: %s %s\n", daisy.name, (map_set(pMap, &daisy) ? "added" : "not added"));
	printf("Set: %s %s\n", donald.name, (map_set(pMap, &donald) ? "added" : "not added"));
	printf("Set: %s %s\n", bob.name, (map_set(pMap, &bob) ? "added" : "not added"));

	printf("\n\n");

	printf("Search: %s %s\n", daisy.name, (map_has(pMap, &daisy) ? "found" : "not found"));
	printf("Search: %s %s\n", donald.name, (map_has(pMap, &donald) ? "found" : "not found"));

	map_print(pMap);

	map_destroy(&pMap);

	if (pMap == NULL) {
		printf("pMap == NULL");
	}

	printf("\n\n");

	return 0;
}

// function definitions --------------------------------------------------------------------------------------------------------
int test_hashTable() {
	return 0;
}
// -----------------------------------------------------------------------------------------------------------------------------