#pragma once
#include "Sort_Method.h"
#include "AutoInMemoryRepository.h"
#include "Rental.h"


/**
This class has a Singleton pattern, only one instance of this class can be build.
To build another class, the resetInstance() method needs to be called after exiting the scope of the last instance
*/
class AutoController {
private:
	Rental rental;  // Rental class, where the clients with their orders and all the available cars are stored
	AutoController();
	static AutoController* instance;  // Instance of the class, attributte used for the Singleton pattern

	Sort_Method* sort_method; 
public:
	// Method used to deny this class having more than 1 instance
	static AutoController* getInstance();

	// Resests the instance, if scope kills the instans another one can be built
	static void resetInstance();
	
	// Searches for a car in the repository by ID
	Auto findAutoById(int id);

	// Returns all cars from the repository
	std::vector <Auto> findAll();

	// Adds a car to the orders list of the client
	Kunde saveAuto(Auto car, Kunde client);

	// Changes the data about car1 with car2 from clients orderlist
	Kunde updateAuto(Auto car1, Auto car2, Kunde& client);

	// Deletes a car from clients orderlist
	Kunde deleteAuto(Auto car, Kunde& client);
	
	// Returns reference to the rental class
	Rental& getRental();

	// Returns reference to the repository
	AutoInMemoryRepository& getRepository();

	// Sets Rental 
	void setRental(Rental _rental);

	// Returns the pointer to the object Sort Method
	Sort_Method* getSort_Method() const;

	// Sets the Sort Method
	void setSort_Method(Sort_Method* _method);
};

