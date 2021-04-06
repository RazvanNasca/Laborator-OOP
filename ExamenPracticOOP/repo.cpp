#include "repo.h"

void Repo::adauga(const Produs& p)
{
	produse.push_back(p);
}

vector<Produs> Repo::getAll()
{
	return produse;
}

int Repo::cauta(Produs p)
{
	int id_cautat = p.getID();
	auto& prods = getAll();
	for (auto& it : prods)
		if (it.getID() == id_cautat)
			return 1;
	return 0;
}

int Repo::vocale(Produs p)
{
	int nr = 0;
	int n = p.getNume().size();
	for (int i = 0; i < n; i++)
		if (p.getNume() == string{ 'a' } || p.getNume() == string{ 'e' } || p.getNume() == string{ 'i' } || p.getNume() == string{ 'o' } || p.getNume() == string{ 'u' })
			nr++;

	return nr;
}

void Repo::loadFromFile()
{
	std::ifstream fin(filename);
	if (!fin.is_open())
		throw RepoException("Fisierul nu poate fi deschis!");

	while (!fin.eof())
	{
		int id;
		string nume, tip;
		double pret;
		fin >> id >> nume >> tip >> pret;

		Produs p{ id, nume, tip, pret };
		adauga(p);

		if (fin.eof())
			break;
	}
	fin.close();
}

void Repo::storeToFile()
{
	std::ofstream fout(filename);
	if (!fout.is_open())
		throw RepoException("Fisierul nu poate fi deschis!");

	auto& rez = getAll();

	for (auto& it : rez)
	{
		fout << it.getID() << "\n";
		fout << it.getNume() << "\n";
		fout << it.getTip() << "\n";
		fout << it.getPret() << "\n";
	}
	fout.close();
}
