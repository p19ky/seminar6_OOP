#include "BubbleSort.h"
#include <iostream>

void swap(Auto& a1, Auto& a2) {
	Auto aux = a1;
	a1 = a2;
	a2 = aux;
}

void BubbleSort::sort_authos(std::vector <Auto>& autos) {
	// Sorts the list of cars from the repository lexicographic with Bubblesort
	std::cout << "\n\t\tSorting with Bubblesort\n";
	std::string copy1, copy2;
	for (size_t i = 0; i < autos.size() - 1; i++)
		// Last i elements are already in place  
		for (size_t j = 0; j < autos.size() - i - 1; j++) {
			// Make all character from Brand string Uppercase
			copy1 = autos[j].getMarke();
			copy2 = autos[j + 1].getMarke();
			for (auto& c : copy1) c = toupper(c);
			for (auto& c : copy2) c = toupper(c);

			// Compares brands, both brands are now Uppercase
			if (copy1 > copy2)
				swap(autos[j], autos[j + 1]);
		}
}