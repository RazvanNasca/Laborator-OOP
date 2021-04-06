#include "entitati.h"

int Produs::getID()
{
	return id;
}

string Produs::getNume()
{
	return nume;
}

string Produs::getTip()
{
	return tip;
}

double Produs::getPret()
{
	return pret;
}

int Produs::getVocale()
{
	int nr = 0;
	int n = getNume().size();
	for (int i = 0; i < n; i++)
		if (getNume() == string{ 'a' } || getNume() == string{ 'e' } || getNume() == string{ 'i' } || getNume() == string{ 'o' } || getNume() == string{ 'u' })
			nr++;

	return nr;
}
