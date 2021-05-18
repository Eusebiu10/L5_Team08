#include "Auto.h"
using namespace std;

Auto::Auto(string modell, string marke, int erstzulassung, int kilometer, int preis, int leistung, string treibstoff, int index)
{
	this->modell = modell;
	this->marke = marke;
	this->erstzulassung = erstzulassung;
	this->kilometer = kilometer;
	this->preis = preis;
	this->leistung = leistung;
	this->treibstoff = treibstoff;
	this->index = index;
};

string Auto::get_modell()
{
	return modell;
};

string Auto::get_marke()
{
	return marke;
};

int Auto::get_erstzulassung()
{
	return erstzulassung;
};

int Auto::get_kilometer()
{
	return kilometer;
};

int Auto::get_preis()
{
	return preis;
};

int Auto::get_leistung()
{
	return leistung;
};

string Auto::get_treibstoff()
{
	return treibstoff;
};

int Auto::get_index()
{
	return index;
};

void Auto::set_modell(string modell)
{
	this->modell = modell;
};

void Auto::set_marke(string marke)
{
	this->marke = marke;
};

void Auto::set_erstzulassung(int erstzulassung)
{
	this->erstzulassung = erstzulassung;
};

void Auto::set_kilometer(int kilometer)
{
	this->kilometer = kilometer;
};

void Auto::set_preis(int preis)
{
	this->preis = preis;
};

void Auto::set_leistung(int leistung)
{
	this->leistung = leistung;
};

void Auto::set_treibstoff(string treibstoff)
{
	this->treibstoff = treibstoff;
};

void Auto::set_index(int index)
{
	this->index = index;
};


string Auto::function_string()
{
	return "Modell: " + modell + " Marke: " + marke + " Erstzulassung: " + to_string(erstzulassung) + " Kilometer: " + to_string(kilometer) + " Preis: " + to_string(preis) + " Leistung: " + to_string(leistung) + " Treibstoff: " + treibstoff + "\n";
}

bool operator ==(const Auto& a1, const Auto& a2) {
	if (a1.modell == a2.modell && a1.marke == a2.marke && a1.erstzulassung == a2.erstzulassung && a1.kilometer == a2.kilometer && a1.preis == a2.preis && a1.leistung == a2.leistung && a1.treibstoff == a2.treibstoff)
		return true;
	else
		return false;
}