#include "Auto.h"
#include <sstream>
#include <iostream>

using namespace std;

Auto::Auto() {
	ID = 0;;
	Marke = "";
	Modell = "";
}

Auto::Auto(double _ID, std::string _Marke, std::string _Modell) {
	ID = _ID;
	Marke = _Marke;
	Modell = _Modell;

	//cout << "Auto wurde gebaut" << endl;
}

Auto::~Auto() {
	//cout << "Auto wurde zerstort" << endl;
}

double Auto::getID() const {
	return this->ID;
}

void Auto::setID(double _ID) {
	this->ID = _ID;
}

std::string Auto::getMarke() const {
	return this->Marke;
}

void Auto::setMarke(std::string _Marke) {
	this->Marke = _Marke;
}

std::string Auto::getModell() const {
	return this->Modell;
}

void Auto::setModell(std::string _Modell) {
	this->Modell = _Modell;
}

std::string Auto::toString() const {
	stringstream out;
	out << "Auto \n\tID: " << this->ID << endl << "\tMarke: " << this->Marke << endl << "\tModell: " << this->Modell << endl << endl;
	return out.str();
}

bool operator == (const Auto& a1, const Auto& a2) {
	return ((a1.getID() == a2.getID()) && (a1.getMarke() == a2.getMarke()) && (a1.getModell() == a2.getModell()));
}
bool operator != (const Auto& a1, const Auto& a2) {
	return !(a1 == a2);
 }