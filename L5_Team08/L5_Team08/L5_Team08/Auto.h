#pragma once
#include <iostream>
#include <string>
using namespace std;

class Auto
{

private:
	string modell;
	string marke;
	int erstzulassung;
	int kilometer;
	int preis;
	int leistung;
	string treibstoff;
	int index;

public:

	//Constructor
	Auto(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index);

	//Getters
	string get_modell();
	string get_marke();
	int get_erstzulassung();
	int get_kilometer();
	int get_preis();
	int get_leistung();
	string get_treibstoff();
	int get_index();


	//Setters
	void set_modell(string name);
	void set_marke(string herkunft);
	void set_erstzulassung(int erstzulassung);
	void set_kilometer(int kilometer);
	void set_preis(int preis);
	void set_leistung(int leistung);
	void set_treibstoff(string treibstoff);
	void set_index(int index);
	string function_string();

	//sorting function
	friend bool sort_by_price(const Auto& a1, const Auto& a2);

	//operators
	friend bool operator ==(const Auto& p1, const Auto& p2);
};
#pragma once
