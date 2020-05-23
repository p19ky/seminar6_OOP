#include "AutoController.h"
#include "CrudRepository.h"
#include "AutoInMemoryRepository.h"
#include <iostream>
#include <vector>
#include <algorithm>
#define NULL_KUNDE Kunde()


AutoController::AutoController() {

}

AutoController* AutoController::getInstance() {
	// Checks if has already been initiated
	if (!instance) {  // If not, create a new instance of the class
		instance = new AutoController;
		return instance;
	}
}

void AutoController::resetInstance() {
	delete instance;
	instance = NULL;
}

Rental& AutoController::getRental() {
	return rental;
}

AutoInMemoryRepository& AutoController::getRepository() {
	return rental.getRepository();
}

void AutoController::setRental(Rental _rental) {
	rental = _rental;
}

Sort_Method* AutoController::getSort_Method() const {
	return sort_method;
}

void AutoController::setSort_Method(Sort_Method* _method) {
	sort_method = _method;
}

Auto AutoController::findAutoById(int id) {
	return rental.getRepository().findOne(id);
}

std::vector <Auto> AutoController::findAll() {
	return rental.getRepository().findAll();
}


Kunde AutoController::saveAuto(Auto car, Kunde client) {
	int gasit_client = -1;
	int gasit_masina = -1;
	
	// Checks if the client exists
	for (size_t i = 0; i < rental.getClients().size() ; i++)
		if (rental.getClients()[i].getID() == client.getID())
			gasit_client = i;

	// Checks if the car exists in clients order list
	for (size_t i = 0; i < rental.getRepository().getAutos_InMemory().size(); i++)
		if (rental.getRepository().getAutos_InMemory()[i].getID() == car.getID())
			gasit_masina = i;

	// If both exist -> add the car to the clients orders list and return the client
	if (gasit_client != -1 and gasit_masina != -1) {
		rental.getClients()[gasit_client].getComenzi().push_back(car);
		return client;
	}

	return NULL_KUNDE;
}


Kunde AutoController::updateAuto(Auto car1, Auto car2, Kunde& client) {
	int gasit_client = -1;
	int gasit_masina = -1;

	// Checks if the client exists
	for (size_t i = 0; i < rental.getClients().size(); i++)
		if (rental.getClients()[i].getID() == client.getID())
			gasit_client = i;

	// Checks if the car exists in clients order list
	for (size_t i = 0; i < rental.getRepository().getAutos_InMemory().size(); i++)
		if (rental.getRepository().getAutos_InMemory()[i].getID() == car2.getID())
			gasit_masina = i;

	if (gasit_client != -1 and gasit_masina != -1) {
		// Checks if the new car exists in the clients orders list
		for (size_t i = 0; i < rental.getClients()[gasit_client].getComenzi().size(); i++)
			if (rental.getClients()[gasit_client].getComenzi()[i].getID() == car1.getID()) {  // If found, deletes the old car and adds the new one
				rental.getClients()[gasit_client].getComenzi().erase(rental.getClients()[gasit_client].getComenzi().begin() + i);
				rental.getClients()[gasit_client].getComenzi().push_back(car2);
				return client;
			}
	}

	return NULL_KUNDE;
}

Kunde AutoController::deleteAuto(Auto car, Kunde& client) {
	int gasit_client = -1;

	// Checks if the client exists
	for (size_t i = 0; i < rental.getClients().size(); i++)
		if (rental.getClients()[i].getID() == client.getID())
			gasit_client = i;

	// If the client exists
	if (gasit_client != -1) {
		// Checks if the car to be deleted exists in the clients orders list
		for (size_t i = 0; i < rental.getClients()[gasit_client].getComenzi().size(); i++)
			if (rental.getClients()[gasit_client].getComenzi()[i].getID() == car.getID()) {  // If found, car will be deleted from oders list
				rental.getClients()[gasit_client].getComenzi().erase(rental.getClients()[gasit_client].getComenzi().begin() + i);
				return client;
			}

	}

	return NULL_KUNDE;
}