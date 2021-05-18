#include <iostream>
#include <fstream>
#include <assert.h>
#include "UI.h"
#include "Controller.h"
#include "Repo.h"
using namespace std;

ifstream f("File.txt");
Repo repo;

void tests()
{
	Repo repo;
	repo.populate("500", "Fiat", 2008, 168000, 3700, 69, "Benzin", 12);

	//test populate
	assert(repo.get_auto_repo().size() == 1);

	//test role
	repo.set_role("manager");
	assert(repo.get_role() == 0);

	//test add_auto
	repo.add_auto("Octavia", "Skoda", 2017, 174000, 15000, 184, "Diesel", 6);
	assert(repo.get_auto_repo().size() == 2);

	//test del_auto
	repo.del_auto("Octavia", "Skoda", 2017, 174000, 15000, 184, "Diesel", 6);
	assert(repo.get_auto_repo().size() == 1);

	//test update_Auto
	Auto a1("500", "Fiat", 2008, 168000, 3700, 69, "Benzin", 12);
	repo.update_auto(a1, 168050, 3500);
	vector <Auto> list = repo.get_auto_repo();
	assert(list[0].get_kilometer() == 168050);
	assert(list[0].get_preis() == 3500);

	//test auto_filter_preis
	repo.add_auto("Octavia", "Skoda", 2017, 174000, 15000, 184, "Diesel", 6);
	repo.add_auto("Vitara", "Suzuki", 2015, 47500, 13600, 120, "Benzin", 5);
	Auto a2("Vitara", "Suzuki", 2015, 47500, 13600, 120, "Benzin", 5);
	repo.auto_sort_preis();
	list = repo.get_auto_repo();
	assert(list[1] == a2);

	//test add_fav
	repo.add_fav(a2, 1);
	assert(repo.get_fav_autos_kunde()[0][0] == a2);

	cout << "TEST END! :) \n";
}


int main()
{
	//tests();

	int er, km, pr, le, i = 1;
	string mo, ma, tr;

	while (f >> mo)
	{
		f >> ma >> er >> km >> pr >> le >> tr;
		repo.populate(mo, ma, er, km, pr, le, tr, i);
		i++;
	}


	Controller service(repo);
	UI ui(service);
	ui.run();


	/*vector<Auto> new_stoc;
	vector<string> passwds;
	passwds.push_back("passwd1k");
	passwds.push_back("passwd2k");
	Repo repo2(new_stoc, "passwd123", passwds);
	while (f >> mo)
	{
		f >> ma >> er >> km >> pr >> le >> tr;
		repo2.populate(mo, ma, er, km, pr, le, tr);
	}
	Controller service(repo2);
	UI ui(service);
	ui.run();*/
}