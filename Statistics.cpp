#include "Statistics.h"
#include <algorithm>


Auto Statistics::most_popular_auto(std::vector<Reservierung> orders) {
	if (orders.size() == 0)  // If there are no orders yet, return DUMMY Auto
		return Auto();

	int* count = new int[std::size(orders)];  
	for (size_t i = 0; i < orders.size(); i++) {  // nested loops wo mark for each car the number of appearences
		int ct = 0;
		for (size_t j = 0; j < orders.size(); j++)
			if (orders[j].getCar() == orders[i].getCar())
				ct++;
		count[i] = ct;
	}
	
	int max = count[0];
	int pos = 0;
	for (size_t i = 0; i < orders.size(); i++)  // Finding the max number of appearnces
		if (count[i] > max) {
			max = count[i];
			pos = i;
		}

	return orders[pos].getCar();  // Return the car from the position with max number of appearences
}


int Statistics::average_rent_days(std::vector<Reservierung> orders) {
	if (orders.size() != 0) {  // If there are orders in the list
		int sum = 0; 
		for (size_t i = 0; i < orders.size(); i++)  // Sum all the days
			sum += orders[i].getDays(); 
		return sum / orders.size(); 
	}
	return 0;
}