#pragma once
#include <string>

using namespace std;

class Produs {

private:
	int id;
	string nume;
	string tip;
	double pret;

public:

	Produs(int id, string nume, string tip, double pret): id{id}, nume{nume}, tip{tip}, pret{pret}{}

	/// returneaza id-ul
	int getID();

	/// returneaza numele
	string getNume();

	/// returneaza tipul
	string getTip();

	/// returneaza pretul
	double getPret();

	/// returneaza nr de vocale
	int getVocale();

};
