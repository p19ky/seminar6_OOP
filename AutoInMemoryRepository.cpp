#include "AutoInMemoryRepository.h"
#define NULL_AUTO Auto()


AutoInMemoryRepository::AutoInMemoryRepository() {

}


std::vector<Auto>& AutoInMemoryRepository::getAutos_InMemory() {
    return autos_InMemory;
}


Auto AutoInMemoryRepository::findOne(int id) {
    // Searches the car by ID
    for (size_t i = 0; i < autos_InMemory.size(); i++)
        if (autos_InMemory[i].getID() == id)
            return autos_InMemory[i];

    return NULL_AUTO;
}


std::vector<Auto> AutoInMemoryRepository::findAll() {
    return autos_InMemory;
}


Auto AutoInMemoryRepository::save(Auto entity) {
    bool already_exists = false;
    
    // Checks if the car already exists in the repository
    for (size_t i = 0; i < autos_InMemory.size(); i++)
        if (autos_InMemory[i].getID() == entity.getID()) {
            already_exists = true;
            break;
        }
    
    // If not, adds it to the list with cars
    if(already_exists == false)
        autos_InMemory.push_back(entity);

    return entity;
}


Auto AutoInMemoryRepository::del(int id) {
    // Checks if the car exists in the repository
    for (size_t i = 0; i < autos_InMemory.size(); i++)
        if (autos_InMemory[i].getID() == id) {  // If found, car will be deleted and returned
            Auto aux = autos_InMemory[i];
            autos_InMemory.erase(autos_InMemory.begin() + i);
            return aux;
        }

    return NULL_AUTO;
}


Auto AutoInMemoryRepository::update(Auto entity) {
    // Checks if the car exists in the repository
    for (size_t i = 0; i < autos_InMemory.size(); i++)
        if (autos_InMemory[i].getID() == entity.getID()) {  // If found, sets the old car to the new one
            autos_InMemory[i] = entity;

            return NULL_AUTO;
        }
    return entity;
}
