#include "service.h"

int Service::adauga(int id, string nume, string tip, double pret)
{
	Produs p{ id, nume, tip, pret };
	int valid = v.validare(p);
	int caut = r.cauta(p);
	int erori = 1;
	if (caut == 1)
	{
		erori *= 5;
		erori *= valid;
		return erori;
	}
	else
	{
		if (valid == 1)
		{
			r.adauga(p);
			r.storeToFile();
			return 0;
		}
		else
			return valid; /// 2 - nume vid, 3 - pret incorect, 6 - ambele
	}
}

vector<Produs> Service::Filtreaza(double val)
{
	vector <Produs> toate = Sorteaza();
	vector <Produs> rez;

	for (auto& it : rez)
		if (it.getPret() <= val)
			rez.push_back(it);

	return rez;

}

vector<Produs> Service::Sorteaza()
{
	vector <Produs> toate = r.getAll();
	int n = toate.size();

	for(int i = 0; i < n - 1; i++)
		for(int j = i+1; j < n; j++)
			if (toate[i].getPret() > toate[j].getPret())
			{
				Produs aux = toate[i];
				toate[i] = toate[j];
				toate[j] = aux;
			}

	return toate;
}
