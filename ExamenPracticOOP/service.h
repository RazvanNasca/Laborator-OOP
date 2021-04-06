#pragma once
#include "repo.h"
#include "validare.h"

class Service {

private:

	Repo& r;
	Valid& v;

public:

	Service(Repo& r, Valid& v): r{r}, v{v}{}

	/// adauga in lista daca datele sunt valide
	int adauga(int id, string nume, string tip, double pret);

	/// filtreaza dupa o valoare
	vector <Produs> Filtreaza(double val);

	/// sorteaza dupa pret produsele
	vector <Produs> Sorteaza();

};
