#pragma once
#include "CrudRepository.h"
#include "Auto.h"
#include <vector>



class AutoInMemoryRepository : public CrudRepository<Auto> {
private:
    std::vector<Auto> autos_InMemory;  // Vector with all the possible cars to be booked/ordered
public:
    // Default constructor
    AutoInMemoryRepository();

    // Returns reference to the vector with cars
    std::vector<Auto>& getAutos_InMemory();

    // Searches for a car in the repository by ID
    Auto findOne(int id);

    // Returns the vector of cars
    std::vector<Auto> findAll();

    // Adds a car to the list if it doesn't exists
    Auto save(Auto entity);

    // Deletes a car from the list if it does exist
    Auto del(int id);

    // Updates the data of a car from the list
    Auto update(Auto entity);
};