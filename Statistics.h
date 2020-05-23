#pragma once
#include "Rental.h"
#include "Reservierung.h"
#include <vector>

class Statistics{
public:
	// Returns the car with most reservations made
	Auto most_popular_auto(std::vector<Reservierung> orders);

	// Returns the average of all the reservations number of days
	int average_rent_days(std::vector<Reservierung> orders);
};

