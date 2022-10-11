/*
	insertSort

	Author: Marco Prescher
	Created on: 06.04.2021
*/

#include <stdio.h>
#include "sortings.h"

/*
	Günstigster Fall: (korrekt sortierte Liste)
		Anzahl der Vergleiche = 2 * (n - 1) -> O(n)
		Anzahl der Zuweisungen = 2 * (n - 1) -> O(n)

	Ungünstigster Fall: (umgekehrt sortierte Liste)
		Anzahl der Vergleiche = (n - 1) * (n / 2) -> O(n^2)
		Anzahl der Zuweisungen = (n - 1) * (n / 2) -> O(n^2)
*/
int insertSort(int* values, int valLen) {
	int nrOfSteps = 0;

	if (valLen > 1) {
		for (int i = 1; i < valLen; i++) {
			int x = values[i];
			nrOfSteps++;

			int j = i;
			while (j > 0 && values[j - 1] > x) {
				values[j] = values[j - 1];

				nrOfSteps += 3;
				j--;
			}

			values[j] = x;
			nrOfSteps++;
		}
	}

	return nrOfSteps;
}