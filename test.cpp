// ------------------- FILE FROM SEMINAR 3 ------------------- //
// ------------------- FILE FROM SEMINAR 3 ------------------- //
// ------------------- FILE FROM SEMINAR 3 ------------------- //
#include "LKW.h"
#include "PKW.h"
#include "Kunde.h"
#include "Rental.h"
#include <Windows.h>
#include <iostream>

using namespace std;

void test() {
	system("color 0A");

	// Ich habe alle Autos pointers gemacht um downcasting zu machen, sollten wir das machen oder nicht?
	Auto* a = new Auto{ 123, "Audi", "A4" };
	cout << a->toString();

	LKW* l = new LKW{ 321, "Volvo", "FH", 1000, "Die Volvo FH Modelle sind zwischen die beste LKWs der Welt" };
	cout << l->toString();

	PKW* p = new PKW{ 333, "Mercedes", "Sprinter", "Bluetooth" };
	cout << p->toString();

	Kunde k1{ 1111, "Paul Popescu" };
	cout << k1.toString();

	Kunde k2{ 2222, "Alexandru Mare" };
	cout << k2.toString();

	Rental r;
	r.add_auto(a);
	r.add_auto(l);
	r.add_auto(p);
	r.add_client(k1);  // Hier wird eigentlich eine Kopie des Kunde1 gebaut und diese Kopie geaddet, nicht? Und nacher diese Kopie wird zersort
	r.add_client(k2);  // Hier dieselbe Sache, aber warum werden hier zwei Kunden zerstort? Man kann im output sehen, auch in debugging, 2 Instanzen der Klasse Kunde werden zersort

	r.toString_cars();
	r.toString_clients();
	r.delete_auto(l);
	r.toString_cars();
	r.delete_client(k1);
	r.update_client(k2, 2222, "Dragos Mare");
	r.toString_clients();

	// Auch am Ende werden 3 Instanzen der Klasse Kunden zersort, ich verstehe nicht von wo 3, konnen Sie mir das bitte erklaren?

	/* 
	Ist es ok wenn ich diese pointers zu den Klassen hier losche, nicht?
	Aber ich bin nicht sicher das alles zerstort wird alles zersort ?
	*/
	delete a;
	delete l;
	delete p;
}