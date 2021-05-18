#pragma once

#include<iostream>
#include<string>
#include<tuple>
#include<vector>
#include "Repo.h"
using namespace std;

class Controller {

private:
	Repo repo;
public:
	// fucntii
	Controller(Repo& repo);
	Repo get_repo();
	void populate(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index);
	void set_role(string passwd);
	void addFunction(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index);
	void removeFunction(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index);
	void updateFunction(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int new_kilometer, int new_preis, int index);
	vector < Auto> serachNachMarkeModell(string marke, string modell);
	vector < Auto> filterNachAlter(int alter);
	vector < Auto> filterNachKm(int km);
	vector <Auto> sortierenFunction();
	void add_favorite(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int role, int index);
	vector <Auto> see_fav(int role);
	void create_Autos_File();
	void update_Autos_File();
	void delete_Autos_File();
	//void read_csv();
};