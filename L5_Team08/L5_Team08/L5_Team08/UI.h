#pragma once

#include "Controller.h"
#include <iostream>
#include <vector>
using namespace std;

class UI
{
private:
	Controller service;
public:
	UI(Controller& service);
	void display_benutzer();
	void display_menu1();
	void display_menu2();
	void populare_vector();
	void run();
};