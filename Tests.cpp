#include "Tests.h"
#include "CrudRepository.h"
#include "AutoInMemoryRepository.h"
#include "Auto.h"
#include <vector>
#include <iostream>
#include "Rental.h"
#include "PKW.h"
#include "LKW.h"
#include "AutoController.h"
#include "UI.h"
#include <cassert>

using namespace std;

AutoController* AutoController::instance = 0;

// ------------------- TEST FROM SEMINAR 4 ------------------- //
void Tests::test_AutoInMemoryRepository() {
	CrudRepository<Auto>* p = new AutoInMemoryRepository;

	p->findAll();

	Auto a1{ 1,"Dacia","Logan" };
	p->save(a1);
	Auto a2{ 2,"Ferrari","Enzo" };
	p->save(a2);
	Auto a3{ 3,"Renault","Megane" };
	p->save(a3);
	Auto a4{ 4,"Daewoo","Matiz" };
	p->save(a4);

	/*vector<Auto> aux;
	aux = p->findAll();
	for (int i = 0; i < 4; i++)
		cout << aux[i] << '\n';

	p->update(Auto(1, "Ferrari", "Spyder"));

	p->del(2);
	aux = p->findAll();

	cout << '\n';
	for (int i = 0; i < aux.size(); i++)
		cout << aux[i] << '\n';



	/*
	vector<Auto> lista = { a1,a2,a3,a4 };
	p->setVehicles(lista);
	*/

	delete p;
}


// ------------------- TEST FROM SEMINAR 4 ------------------- //
void Tests::TestUI_SEMINAR4() {
	cout << "\nMenu\n";

	Rental r;

	Kunde k1(1, "client1");
	Kunde k2(2, "client2");
	Kunde k3(3, "client3");

	Auto a1(1, "bemveu", "seria3");
	Auto a2(12, "audi", "deSmecheri");
	PKW p1(2, "pekaveu69", "exemplu", "sonderausstattungen");
	PKW p2(22, "Bus420", "exemplu", "sonderausstattungen");
	LKW l1(3, "elkaveu", "exemplu", 1000, "bezeichnung");
	LKW l2(32, "tirmare", "exemplu", 1000, "bezeichnung");

	AutoInMemoryRepository repository;
	r.getRepository().save(a1);
	r.getRepository().save(a2);
	r.getRepository().save(p1);
	r.getRepository().save(p2);
	r.getRepository().save(l1);
	r.getRepository().save(l2);

	r.add_client(k1);
	r.add_client(k2);
	r.add_client(k3);

	AutoController* controller = controller->getInstance();
	controller->setRental(r);
	controller->getSort_Method()->sort_authos(controller->getRepository().getAutos_InMemory());

	UI ui(controller, Sort_Method_Type::Library_Sort);

	ui.SEMINAR4_menu();

	controller->resetInstance();
	delete controller->getSort_Method();
}

// ------------------- TEST FROM SEMINAR 4 ------------------- //
void Tests::TestController() {
	cout << "Test Controller\n";

	Rental r;

	Kunde k1(1, "client1");
	Kunde k2(2, "client2");
	Kunde k3(3, "client3");

	Auto a1(1, "bemveu", "seria3");
	PKW p1(2, "pekaveu69", "exemplu", "sonderausstattungen");
	LKW l1(3, "elkaveu", "exemplu", 1000, "bezeichnung");

	AutoInMemoryRepository repository;
	r.getRepository().save(a1);
	r.getRepository().save(p1);
	r.getRepository().save(l1);

	r.add_client(k1);
	r.add_client(k2);
	r.add_client(k3);

	AutoController* controller = controller->getInstance();
	controller->setRental(r);

	controller->saveAuto(a1, k1);
	controller->saveAuto(l1, k1);
	assert(controller->getRental().getClients()[0].getComenzi()[0] == a1);
	assert(controller->getRental().getClients()[0].getComenzi()[1] == l1);
	
	controller->updateAuto(a1, p1, k1);
	assert(controller->getRental().getClients()[0].getComenzi()[1] == p1);

	controller->deleteAuto(a1, k1);
	controller->deleteAuto(p1, k1);
	assert(controller->getRental().getClients()[0].getComenzi()[0] == l1);

	controller->resetInstance();
}

// ------------------- TEST FROM SEMINAR 4 ------------------- //
void Tests::TestActions() {
	cout << "Test Actions\n";

	Rental r;

	Kunde k1(1, "client1");
	Kunde k2(2, "client2");
	Kunde k3(3, "client3");

	Auto a1(1, "bemveu", "seria3");
	PKW p1(2, "pekaveu69", "exemplu", "sonderausstattungen");
	LKW l1(3, "elkaveu", "exemplu", 1000, "bezeichnung");

	AutoInMemoryRepository repository;
	r.getRepository().save(a1);
	r.getRepository().save(p1);
	r.getRepository().save(l1);

	r.add_client(k1);
	r.add_client(k2);
	r.add_client(k3);

	l1.load();
	l1.load();
	assert(l1.getGesamtgewicht() == 1002);
	l1.unload();
	assert(l1.getGesamtgewicht() == 1001);
	l1.load();
	assert(l1.getGesamtgewicht() == 1002);
}

// ------------------- SEMINAR 6 ------------------- //
// ------------------- SEMINAR 6 ------------------- //
// ------------------- SEMINAR 6 ------------------- //
void Tests::TestUI_SEMINAR5(Sort_Method_Type type) {
	cout << "\nMenu\n";

	Rental r;

	Kunde k1(1, "client1");
	Kunde k2(2, "client2");
	Kunde k3(3, "client3");

	Auto a1(1, "bemveu", "seria3");
	Auto a2(12, "audi", "deSmecheri");
	PKW p1(2, "pekaveu69", "exemplu", "sonderausstattungen");
	PKW p2(22, "Bus420", "exemplu", "sonderausstattungen");
	LKW l1(3, "elkaveu", "exemplu", 1000, "bezeichnung");
	LKW l2(32, "tirmare", "exemplu", 1000, "bezeichnung");

	AutoInMemoryRepository repository;
	r.getRepository().save(a1);
	r.getRepository().save(a2);
	r.getRepository().save(p1);
	r.getRepository().save(p2);
	r.getRepository().save(l1);
	r.getRepository().save(l2);

	r.add_client(k1);
	r.add_client(k2);
	r.add_client(k3);

	AutoController* controller = controller->getInstance();
	controller->setRental(r);

	UI ui(controller, type);
	controller->getSort_Method()->sort_authos(controller->getRepository().getAutos_InMemory());
	ui.choose_menu();

	controller->resetInstance();
}