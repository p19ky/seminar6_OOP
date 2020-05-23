#pragma once
#include <string>


class Auto {
protected:
	double ID;  
	std::string Marke, Modell;

public:
	Auto();

	// Constructor
	Auto(double _ID, std::string _Marke, std::string _Modell);

	// Destructor
	~Auto();

	// Returns the ID of the car
	double getID() const;

	// Changes the ID of the car with the specified one
	void setID(double _ID);

	// Returns the brand of the car
	std::string getMarke() const;

	// Changes the brand of the car with the specified one
	void setMarke(std::string _Marke);

	// Returns the modell of the car
	std::string getModell() const;

	// Changes the modell of the car with the specified one
	void setModell(std::string _Modell);

	// Prints details about the car
	virtual std::string toString() const;

	// Overloading Comparsion Operators
	friend bool operator == (const Auto& a1, const Auto& a2);
	friend bool operator != (const Auto& a1, const Auto& a2);
};