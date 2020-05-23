#include "UI.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using std::cout; using std::cin;
using std::endl;
using std::string;


UI::UI(AutoController* c, Sort_Method_Type type) {
	ac = c;
	ac->setSort_Method(Sort_Method::Create(type));
}

UI::~UI() {
}

void UI::choose_menu() {
	while (true) {
		string instructions = "\n0 - Exit\n1 - SEMINAR4 Menu\n2 - SEMINAR5+6 Menu\n";
		cout << instructions;

		cout << "\nChoose option:\nYour option: ";
		char option;
		cin >> option;

		if (option == '0')
			exit(0);
		else if (option == '1')
			SEMINAR4_menu();
		else if (option == '2')
			SEMINAR5_menu();
	}
	
}

void UI::show_clients_and_cars() {
	// Shows all cars available in the repository
	cout << "Autos:\n";
	for (size_t i = 0; i < ac->getRepository().getAutos_InMemory().size(); i++) {
		sleep_for(nanoseconds(300000000));
		cout << ac->getRepository().getAutos_InMemory()[i].toString();
	}
		

	// Shows all clients that are listed
	cout << "\nClients:\n";
	for (size_t i = 0; i < ac->getRental().getClients().size(); i++) {
		sleep_for(nanoseconds(300000000));
		cout << ac->getRental().getClients()[i].toString();
	}
		

	cout << endl;
}


void UI::build_menu_v1() {
	 string instructions = "\nOptions\n0 - Exit\n1 - Find Auto by ID\n2 - Find All\n"
		 "3 - Save Auto to Client\n4 - Update Auto for a client\n5 - Delete Auto from a client\n6 - Show Orders\n";
	 cout << instructions;
}


void UI::build_menu_v2() {
	string instructions = "\n0 - Exit\n1 - Reserve a car\n2 - Delete an order\n3 - Show all orders\n"
		"4 - Add a client\n5 - Delete a client\n6 - Add a new auto for renting\n7 - Delete a car from repository"
		"\n8 - Show a list will all the cars in the repository\n9 - Shows most popular auto\n10 - Shows the average rent days";
	cout << instructions;
}


void UI::SEMINAR4_menu() {
	while (true) {
		build_menu_v1();
		cout << "\nChoose option:\nYour option: ";
		char option;
		cin >> option;

		if (option == '1') {
			int id;
			cout << "\nEnter Auto ID to be found: ";
			cin >> id;

			Auto a;

			a = ac->findAutoById(id);

			cout << a.toString();
		}
		if (option == '2') {
			// Goes trough the repository and print every car found in the list
			cout << "\nList of Autos:\n";
			for (size_t i = 0; i < ac->getRepository().getAutos_InMemory().size(); i++) {
				sleep_for(nanoseconds(300000000));
				cout << ac->getRepository().getAutos_InMemory()[i].toString();
			}

		}
		if (option == '3') {
			show_clients_and_cars();

			sleep_for(seconds(1));

			int id;
			int id_car;

			cout << "Give client ID: ";
			cin >> id;

			cout << "Give car ID: ";
			cin >> id_car;

			Auto a;
			for (size_t i = 0; i < ac->getRepository().getAutos_InMemory().size(); i++)
				if (id_car == ac->getRepository().getAutos_InMemory()[i].getID())
					a = ac->getRepository().getAutos_InMemory()[i];

			Kunde k;
			for (size_t i = 0; i < ac->getRental().getClients().size(); i++)
				if (id == ac->getRental().getClients()[i].getID())
					k = ac->getRental().getClients()[i];

			ac->saveAuto(a, k);
		}
		if (option == '4') {
			ac->getRental().show_orders();

			int id;
			int id_car1;
			int id_car2;

			cout << "Give client ID: ";
			cin >> id;

			cout << "Give client car ID: ";
			cin >> id_car1;

			cout << "Give update car ID: ";
			cin >> id_car2;

			Auto a1;
			for (size_t i = 0; i < ac->getRepository().getAutos_InMemory().size(); i++)
				if (id_car1 == ac->getRepository().getAutos_InMemory()[i].getID())
					a1 = ac->getRepository().getAutos_InMemory()[i];
			Auto a2;
			for (size_t i = 0; i < ac->getRepository().getAutos_InMemory().size(); i++)
				if (id_car2 == ac->getRepository().getAutos_InMemory()[i].getID())
					a2 = ac->getRepository().getAutos_InMemory()[i];

			Kunde k;
			for (size_t i = 0; i < ac->getRental().getClients().size(); i++)
				if (id == ac->getRental().getClients()[i].getID())
					k = ac->getRental().getClients()[i];

			ac->updateAuto(a1, a2, k);
		}
		if (option == '5') {
			int id;
			int id_car;

			cout << "Give client ID: ";
			cin >> id;

			cout << "Give car ID: ";
			cin >> id_car;

			Auto a;
			for (size_t i = 0; i < ac->getRepository().getAutos_InMemory().size(); i++)
				if (id == ac->getRepository().getAutos_InMemory()[i].getID())
					a = ac->getRepository().getAutos_InMemory()[i];

			Kunde k;
			for (size_t i = 0; i < ac->getRental().getClients().size(); i++)
				if (id_car == ac->getRental().getClients()[i].getID())
					k = ac->getRental().getClients()[i];

			ac->deleteAuto(a, k);
		}
		if (option == '0') {
			break;
		}
		if (option == '6') {
			ac->getRental().show_orders();
		}

		sleep_for(nanoseconds(1000000000));
	}


	
}


void UI::SEMINAR5_menu() {
	while (true) {
		build_menu_v2();
		cout << "\nChoose option:\nYour option: ";
		int option;
		cin >> option;

		ac->getSort_Method()->sort_authos(ac->getRepository().getAutos_InMemory());

		if (option == 0)
			break;
		if (option == 1) {
			cout << "Um eine Auto zu reservieren, geben sie ein Auto, ein Kunde und Anzahl der Tagen\n";
			
			show_clients_and_cars();

			int id, id_car, days;
			cout << "Give client ID: ";  cin >> id;
			cout << "Give car ID: ";  cin >> id_car;
			cout << "Give number of days: "; cin >> days;

			ac->getRental().reserve_auto(id, id_car, days);
		}
		if (option == 2) {
			cout << "Um eine Reservierung zu loschen, geben sie ID des Autos und ID des Kundes\n";
			ac->getRental().show_reservierungen();

			int id, id_car;
			cout << "Give client ID: ";  cin >> id;
			cout << "Give car ID: ";  cin >> id_car;

			ac->getRental().delete_reservierung(id, id_car);
		}
		if (option == 3)
			ac->getRental().show_reservierungen();
		if (option == 4) {
			cout << "Um ein Kunde zu einfugen, geben sie Name und ID des Kundes\n";
			string name;
			double id;
			bool already_exists = false;
			cout << "Give client Name: ";  cin >> name;
			cout << "Give client id: ";  cin >> id;

			ac->getRental().add_client(Kunde(id, name));
		}
		if (option == 5) {
			cout << "Um ein Kunde zu losche, geben sie Name und ID des Kundes\n";
			string name;
			double id;
			cout << "Give client Name: ";  cin >> name;
			cout << "Give client id: ";  cin >> id;
			
			ac->getRental().delete_client(Kunde(id, name));
		}
		if (option == 6) {
			cout << "Was wollen sie einfugen?\n1 - Auto\n2 - LKW\n3 - PKW\n: ";
			cout << "\nChoose option:\nYour option: ";
			char option_auto;  cin >> option_auto;
			double _ID, _Gesamtgewicht;
			std::string _Marke, _Modell, _Bezeichnung, _Sonderausstattungen;
			cout << "Give car ID: ";  cin >> _ID;
			cout << "Give car brand:";  cin >> _Marke;
			cout << "Give car model:";  cin >> _Modell;
			switch (option_auto) {
			case '1':
				ac->getRepository().save(Auto(_ID, _Marke, _Modell));
				break;
			case '2':
				cout << "Give Autos Gesamtgewicht: ";  cin >> _Gesamtgewicht;
				cout << "Give Autos Bezeichnung:";  cin >> _Bezeichnung;
				ac->getRepository().save(LKW(_ID, _Marke, _Modell, _Gesamtgewicht, _Bezeichnung));
				break;
			case '3':
				cout << "Give Autos Sonderausstattungen: ";  cin >> _Sonderausstattungen;
				ac->getRepository().save(PKW(_ID, _Marke, _Modell, _Sonderausstattungen));
				break;
			default:
				break;
			}
		}
		if (option == 7) {
			cout << "Um ein Auto zu losche, geben sie ID des Autos\n";
			int _ID;
			cout << "Give car ID: ";  cin >> _ID;
			ac->getRepository().del(_ID);
		}
		if (option == 8) {
			// Shows all cars available in the repository
			cout << "Autos:\n";
			for (size_t i = 0; i < ac->getRepository().getAutos_InMemory().size(); i++) {
				sleep_for(nanoseconds(300000000));
				cout << ac->getRepository().getAutos_InMemory()[i].toString();
			}
		}
		if (option == 9) {
			Auto a = stats.most_popular_auto(ac->getRental().getOrders());
			Auto b;
			if (a == b)
				cout << "\nNo reservations made yet\n";
			else
				cout << "\nMost popular car is: " << a.toString();
		}
			
		if (option == 10)
			cout << "\nAverage rent days: " << stats.average_rent_days(ac->getRental().getOrders()) << "\n";
	}
}