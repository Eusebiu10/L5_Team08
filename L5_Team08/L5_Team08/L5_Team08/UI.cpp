#include "UI.h"
#include "Controller.h"
#include <tuple>
#include <iostream>
using namespace std;
//aici preiau date de la utilizator si le trimit in controller care este ca un service ca sa fie procesate

UI::UI(Controller& service) : service(service)
{
}

void UI::display_benutzer()
{
    string passwd;
    cout << "Willkommen!" << endl;
    cout << "Fugen sie ihrer Password: ";
    cin >> passwd;
    try {
        service.set_role(passwd);    //die rolle wird zu den geeingenete index gestezt
    }
    catch (exception&) {
        cout << "Invalid passwd \n";
        display_benutzer();
    }

}

void UI::display_menu1()
{
    cout << endl;
    cout << "Willkommen, Manager !" << endl;
    cout << "Diese ist unsere Liste mit der derzeit verfugbaren Autos : " << endl;
    cout << "Menu fur Optionen: (drucken Sie die hingewiesenen Zahlen)" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Auto hinzufugen" << endl;
    cout << "2. Auto loschen" << endl;
    cout << "3. Auto aktualisieren" << endl;
    cout << "4. Autos nach Modell/Marke suchen" << endl;
    cout << "5. Autos nach Alter/Kilometer suchen " << endl;
    cout << "6. Nach Preis aufsteigend sortierte Autos" << endl;
}

void UI::display_menu2()
{
    cout << endl;
    cout << "Willkommen, Benutzer !" << endl;
    cout << "Diese ist unsere Liste mit der derzeit verfugbaren Autos : " << endl;
    cout << "Menu fur Optionen: (drucken Sie die hingewiesenen Zahlen)" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Autos nach Modell/Marke suchen" << endl;
    cout << "2. Autos nach Alter/Kilometer suchen " << endl;
    cout << "3. Nach Preis aufsteigend sortierte Autos" << endl;
    cout << "4. Auto bei der Favoriten hinzufugen" << endl;
    cout << "5. Liste der Favoriten" << endl;
}

void UI::populare_vector()
{
    service.populate("CR-V", "Honda", 2014, 200000, 10000, 150, "Benzin", 1);
    service.populate("X1", "BMW", 2020, 18000, 41000, 190, "Diesel", 2);
    service.populate("Vitara", "Suzuki", 2015, 47500, 13600, 120, "Benzin", 3);
    service.populate("Octavia", "Skoda", 2017, 174000, 15000, 184, "Diesel", 4);
    service.populate("500", "Fiat", 2008, 168000, 3700, 69, "Benzin", 5);
    service.populate("Cayenne", "Porsche", 2016, 185000, 42900, 441, "Benzin", 6);
    service.populate("Astra", "Opel", 2010, 207200, 4780, 125, "Diesel", 7);
    service.populate("T-ROC", "Volkswagen", 2019, 16800, 28600, 150, "Diesel", 8);
    service.populate("Megane", "Renault", 2012, 193000, 5000, 110, "Diesel", 9);
    service.populate("GLE", "Mercedes-Benz", 2020, 14364, 70600, 367, "Benzin", 10);
}


void UI::run()
{
    int role;
    int option = -1;
    this->display_benutzer();
    role = service.get_repo().get_role();
    while (option != 0)
    {
        if (role == 0)
        {
            display_menu1();

            cin >> option;
            if (option == 0)
            {
                cout << "Auf Wiedersehen!" << endl;
                break;
            }
            else if (option == 1)
            {
                string modell;
                string marke;
                int erstzulassung;
                int kilometer;
                int preis;
                int leistung, index;
                string treibstoff;
                cout << "Modell : "; cin >> modell;
                cout << "Marke : "; cin >> marke;
                cout << "Erstzulassung : "; cin >> erstzulassung;
                cout << "Kilometer : "; cin >> kilometer;
                cout << "Preis in Euro : "; cin >> preis;
                cout << "Leistung : "; cin >> leistung;
                cout << "Treibstoff : "; cin >> treibstoff;
                cout << "index : "; cin >> index;
                try {
                    service.addFunction(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, index);
                }
                catch (exception&) {
                    cout << "Funktion nicht verfugbar";
                }
            }
            else if (option == 2)
            {
                string modell;
                string marke;
                int erstzulassung;
                int kilometer;
                int preis;
                int leistung, index;
                string treibstoff;
                cout << "Modell : "; cin >> modell;
                cout << "Marke : "; cin >> marke;
                cout << "Erstzulassung : "; cin >> erstzulassung;
                cout << "Kilometer : "; cin >> kilometer;
                cout << "Preis in Euro : "; cin >> preis;
                cout << "Leistung : "; cin >> leistung;
                cout << "Treibstoff : "; cin >> treibstoff;
                cout << "index : "; cin >> index;
                try {
                    service.removeFunction(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, index);

                }
                catch (exception&) {
                    cout << "Funktion nicht verfugbar";
                }
            }
            else if (option == 3)
            {
                string modell;
                string marke;
                int erstzulassung;
                int kilometer;
                int preis;
                int new_kilometer;
                int new_preis;
                int leistung, index;
                string treibstoff;
                cout << "Modell : "; cin >> modell;
                cout << "Marke : "; cin >> marke;
                cout << "Erstzulassung : "; cin >> erstzulassung;
                cout << "Kilometer : "; cin >> kilometer;
                cout << "Preis in Euro : "; cin >> preis;
                cout << "Leistung : "; cin >> leistung;
                cout << "Treibstoff : "; cin >> treibstoff;


                cout << "New kilometer : "; cin >> new_kilometer;
                cout << "New preis in Euro : "; cin >> new_preis;
                cout << "index : "; cin >> index;
                try {
                    service.updateFunction(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, new_kilometer, new_preis, index);
                }
                catch (exception&) {
                    cout << "Funktion nicht verfugbar";
                }
            }
            else if (option == 4)
            {
                vector < Auto> found_cars;
                string marke, modell;
                cout << "Marke : "; cin >> marke;
                cout << "Modell : "; cin >> modell;
                try {
                    found_cars = service.serachNachMarkeModell(marke, modell);
                    for (int i = 0; i < found_cars.size(); i++) {
                        cout << found_cars[i].function_string();
                    }
                }
                catch (exception&) {
                    cout << "Keine Autos gefunden \n";
                }
            }
            else if (option == 5)
            {
                vector < Auto> filtered_cars;
                int alter, km;
                cout << "Alter : "; cin >> alter;
                cout << "Kilometer : "; cin >> km;
                cout << "Liste gefiltert nach dem Alter :" << endl;
                try {
                    filtered_cars = service.filterNachAlter(alter);
                    for (int i = 0; i < filtered_cars.size(); i++) {
                        cout << filtered_cars[i].function_string();
                    }
                }
                catch (exception&) {
                    cout << "Keine Autos gefunden \n";
                }

                cout << endl << "Liste gefiltert nach den Kilometern :" << endl;
                try {
                    filtered_cars = service.filterNachKm(km);
                    for (int i = 0; i < filtered_cars.size(); i++) {
                        cout << filtered_cars[i].function_string();
                    }
                }
                catch (exception&) {
                    cout << "Keine Autos gefunden \n";
                }

            }
            else if (option == 6)
            {
                vector <Auto> stoc_sorted;
                stoc_sorted = service.sortierenFunction();
                for (int i = 0; i < stoc_sorted.size(); i++) {
                    cout << stoc_sorted[i].function_string();
                }
            }
            else
            {
                cout << "Invalid option." << endl;
            }
        }

        else
        {
            display_menu2();
            cin >> option;
            if (option == 0)
            {
                cout << "Auf Wiedersehen!" << endl;
                break;
            }

            else if (option == 1)
            {
                vector < Auto> found_cars;
                string marke, modell;
                cout << "Marke : "; cin >> marke;
                cout << "Modell : "; cin >> modell;
                try {
                    found_cars = service.serachNachMarkeModell(marke, modell);
                    for (int i = 0; i < found_cars.size(); i++) {
                        cout << found_cars[i].function_string();
                    }
                }
                catch (exception&) {
                    cout << "Keine Autos gefunden \n";
                }
            }
            else if (option == 2)
            {
                vector < Auto> filtered_cars;
                int alter, km;
                cout << "Alter : "; cin >> alter;
                cout << "Kilometer : "; cin >> km;
                cout << "Liste gefiltert nach dem Alter :" << endl;
                try {
                    filtered_cars = service.filterNachAlter(alter);
                    for (int i = 0; i < filtered_cars.size(); i++) {
                        cout << filtered_cars[i].function_string();
                    }
                }
                catch (exception&) {
                    cout << "Keine Autos gefunden \n";
                }

                cout << endl << "Liste gefiltert nach den Kilometern :" << endl;
                try {
                    filtered_cars = service.filterNachKm(km);
                    for (int i = 0; i < filtered_cars.size(); i++) {
                        cout << filtered_cars[i].function_string();
                    }
                }
                catch (exception&) {
                    cout << "Keine Autos gefunden \n";
                }
            }
            else if (option == 3)
            {
                vector <Auto> stoc_sorted;
                stoc_sorted = service.sortierenFunction();
                for (int i = 0; i < stoc_sorted.size(); i++) {
                    cout << stoc_sorted[i].function_string();
                }
            }

            else if (option == 4)
            {
                string modell;
                string marke;
                int erstzulassung;
                int kilometer;
                int preis;
                int new_kilometer;
                int new_preis;
                int leistung, index;
                string treibstoff;
                cout << "Modell : "; cin >> modell;
                cout << "Marke : "; cin >> marke;
                cout << "Erstzulassung : "; cin >> erstzulassung;
                cout << "Kilometer : "; cin >> kilometer;
                cout << "Preis in Euro : "; cin >> preis;
                cout << "Leistung : "; cin >> leistung;
                cout << "Treibstoff : "; cin >> treibstoff;
                cout << "index : "; cin >> index;
                try {
                    service.add_favorite(modell, marke, erstzulassung, kilometer, preis, leistung, treibstoff, role, index);
                }
                catch (exception&) {
                    cout << "Die Auto existiert nicht \n";
                }
            }

            else if (option == 5)
            {
                vector <Auto> fav_liste;
                try {
                    fav_liste = service.see_fav(role);
                    for (int i = 0; i < fav_liste.size(); i++) {
                        cout << fav_liste[i].function_string();
                    }
                }
                catch (exception&) {
                    cout << "Keine Autos in favoriten \n";
                }

            }

            else
            {
                cout << "Invalid option." << endl;
            }
        }

    }
}

