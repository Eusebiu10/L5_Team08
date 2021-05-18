#include "Repo.h"
#include "Auto.h"
#include <tuple>
using namespace std;


Repo::Repo()
{
	vector<Auto> new_stoc;
	this->stoc = new_stoc;
	this->len = 0;

	this->manager = make_tuple(0, "manager");		//wenn keine passwd gegeben wird, dann ist automat das passwd manager

	vector<tuple<int, string>> new_kunde;
	new_kunde.push_back(make_tuple(1, "kunde"));   //wenn keine liste von kunden gegebn wird, dann wird nur ein geben, der das passed kunde hat
	this->kunde = new_kunde;

	this->role = -1;   //beim erstellen die rolle ist invalid

	vector<vector <Auto>> new_fav_auto_kunde;
	this->fav_autos_kunde = new_fav_auto_kunde;
	vector < Auto> fav_kunde;
	this->fav_autos_kunde.push_back(fav_kunde);

}

Repo::Repo(vector <Auto>& auto_stoc, string passwd_manager, vector <string>& passwd_kunde) {
	this->stoc = auto_stoc;
	this->len = this->stoc.size();

	this->manager = make_tuple(0, passwd_manager);

	for (int i = 0; i < passwd_kunde.size(); i++) {
		this->kunde.push_back(make_tuple(i + 1, passwd_kunde[i]));    //erstellen die liste von kunden mit den geeigneten index
	}

	this->role = -1;   //beim erstellen die rolle ist invalid

	vector<vector <Auto>> new_fav_auto_kunde;
	this->fav_autos_kunde = new_fav_auto_kunde;
	vector < Auto> fav_kunde;
	for (int i = 0; i < passwd_kunde.size(); i++) {
		this->fav_autos_kunde.push_back(fav_kunde);
	}
}

void Repo::populate(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index) {
	Auto a(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, index);
	stoc.push_back(a);
	len++;
}


void Repo::set_role(string passwd)
{
	int i;
	if (passwd == get<1>(manager)) this->role = get<0>(manager);
	else if (kunde.size() > 0) {
		for (i = 0; i < kunde.size(); i++) {
			if (passwd == get<1>(kunde[i])) {
				this->role = get<0>(kunde[i]);
				return;
			}

		}
		if (i == kunde.size()) {
			throw exception();
		}
	}
	else {
		throw exception();
	}
}

Repo::~Repo() {}

void Repo::add_auto(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index)
{
	if (role != 0) throw exception();
	else
	{
		Auto a(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, index);
		stoc.push_back(a);
		len++;
	}

}

void Repo::del_auto(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index)
{
	int i;
	if (role != 0) throw exception();
	else {
		Auto aux(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, index);
		for (i = 0; i < len; i++)
			if (aux == stoc[i]) {
				stoc.erase(stoc.begin() + i);
				this->len--;
			}
	}

}


//void Repo::edit_marke(Auto a, string m)
//{
//	a.set_Marke(m);
//}
//
//
//void Repo::edit_modell(Auto a, string m)
//{
//	a.set_Modell(m);
//}
//
//void Repo::edit_erst(Auto a, int n)
//{
//	a.set_Erstzulassung(n);
//}
//
//
//void Repo::edit_km(Auto a, int n)
//{
//	a.set_Kilometer(n);
//}
//
//void Repo::edit_preis(Auto a, int p)
//{
//	a.set_Preis(p);
//}
//
//void Repo::edit_leis(Auto a, int l)
//{
//	a.set_Leistung(l);
//}
//
//void Repo::edit_tff(Auto a, string t)
//{
//	a.set_Treibstoff(t);
//}

void Repo::update_auto(Auto x, int new_kilometer, int new_preis)
{
	int i;
	if (role != 0) throw exception();
	else {
		for (int i = 0; i < stoc.size(); i++)
		{
			if (stoc[i].get_modell() == x.get_modell() && stoc[i].get_marke() == x.get_marke() && stoc[i].get_erstzulassung() == x.get_erstzulassung() && stoc[i].get_kilometer() == x.get_kilometer() && stoc[i].get_preis() == x.get_preis() && stoc[i].get_leistung() == x.get_leistung() && stoc[i].get_treibstoff() == x.get_treibstoff())
			{
				stoc[i].set_kilometer(new_kilometer);
				stoc[i].set_preis(new_preis);
				break;
			}
		}
	}
}

vector < Auto> Repo::search(string marke, string model)
{
	vector < Auto> found_cars;
	int i, ok = 0;
	for (i = 0; i < len; i++)
		if (stoc[i].get_marke() == marke && stoc[i].get_modell() == model)
		{
			ok = 1;
			found_cars.push_back(stoc[i]);
		}
	if (ok == 0) {
		throw exception();
	}
	else {
		return found_cars;
	}
}



#include <algorithm>

void Repo::set_prod_repo(vector <Auto> a) {
	this->stoc = a;
}
void Repo::set_fav_autos_kunde(vector<vector <Auto>> kunden_a) {
	this->fav_autos_kunde = kunden_a;
}

int Repo::get_role() {
	return this->role;
}

vector <Auto> Repo::get_auto_repo() {
	return this->stoc;
}

vector<vector <Auto>> Repo::get_fav_autos_kunde() {
	return this->fav_autos_kunde;
}

vector < Auto> Repo::auto_filter_alter(int alt) {
	vector < Auto> filtered_cars;
	int ok = 0, auto_a;
	for (int i = 0; i < this->stoc.size(); i++) {
		auto_a = this->stoc[i].get_erstzulassung();
		if (2021 - auto_a <= alt) {
			ok = 1;
			filtered_cars.push_back(stoc[i]);
		}
	}
	if (ok == 0) {
		throw exception();
	}
	else {
		return filtered_cars;
	}
}

vector < Auto> Repo::auto_filter_km(int km) {
	vector < Auto> filtered_cars;
	int ok = 0, auto_km;
	for (int i = 0; i < this->stoc.size(); i++) {
		auto_km = this->stoc[i].get_kilometer();
		if (auto_km <= km) {
			ok = 1;
			filtered_cars.push_back(stoc[i]);
		}
	}
	if (ok == 0) {
		throw exception();
	}
	else {
		return filtered_cars;
	}
}

bool sort_by_price(const Auto& a1, const Auto& a2) {
	return(a1.preis < a2.preis);
}

vector <Auto> Repo::auto_sort_preis() {
	sort(this->stoc.begin(), this->stoc.end(), sort_by_price);   //wir sortieren nach den preis
	return this->stoc;
}

void Repo::add_fav(Auto a, int role) {
	int i, ok = 0;
	for (i = 0; i < len; i++)
		if (a == stoc[i]) {

			this->fav_autos_kunde[role - 1].push_back(a);
			ok = 1;
		}
	if (ok == 0) {
		throw exception();
	}

}

vector <Auto> Repo::see_fav(int role) {
	if (this->fav_autos_kunde[role - 1].size() > 0) {
		return this->fav_autos_kunde[role - 1];
	}
	else {
		throw exception();
	}

}


