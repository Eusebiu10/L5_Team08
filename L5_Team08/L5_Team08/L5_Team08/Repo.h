#pragma once
#include <string>
#include <tuple>
#include "Auto.h"

using namespace std;

#include <vector>
#include <iostream>

class Repo
{
private:
	int len;
	int role;
	tuple <int, string> manager;
	vector <tuple<int, string> > kunde;
	vector <Auto> stoc;
	vector<vector <Auto>> fav_autos_kunde;

public:
	//Constructor
	Repo();
	Repo(vector <Auto>& auto_stoc, string passwd_manager, vector <string>& passwd_kunde);

	void populate(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index);

	//F1 
	void set_role(string passwd);

	//F2
	void add_auto(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index);
	void del_auto(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index);
	void update_auto(Auto x, int new_kilometer, int new_preis);
	/*void edit_marke(Auto a, string m);
	void edit_modell(Auto a, string m);
	void edit_erst(Auto a, int n);
	void edit_km(Auto a, int n);
	void edit_preis(Auto a, int p);
	void edit_leis(Auto a, int l);
	void edit_tff(Auto a, string t);*/


	//F3
	vector < Auto> search(string mark, string model);


	//Destructor
	~Repo();



	//getter
	int get_role();
	vector <Auto> get_auto_repo();
	vector<vector <Auto>> get_fav_autos_kunde();

	//setter
	void set_prod_repo(vector <Auto> a);
	void set_fav_autos_kunde(vector<vector <Auto>> kunden_a);

	//es gibt zuruck die liste der Autos mit den gegebene wert als Alter
	vector < Auto> auto_filter_alter(int alt);

	//es gibt zuruck die liste der Autos mit den kilometer-zahl weniger als den gegebene wert
	vector < Auto> auto_filter_km(int km);

	//es gibt zuruck eine Liste der Autos nach Preis aufsteigend sortiert
	//TODO: afisare in UI
	vector <Auto> auto_sort_preis();

	//es fugt eine Auto zu den personliche Favoriten-Liste der Kunde
	//TODO: 
	void add_fav(Auto a, int role);

	//es gibt zuruck den personliche Favoriten-Liste der Kunde
	vector <Auto> see_fav(int role);
};
