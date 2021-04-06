#pragma once
#include "entitati.h"
#include <vector>
#include <iostream>
#include <fstream>

class RepoException {

private:
	string msg;

public:

	RepoException(string msg): msg{msg}{}

	string getMessage()
	{
		return msg;
	}

};

class Repo {

private:
	vector <Produs> produse;
	string filename;
public:

	Repo(string filename) : filename{ filename } { loadFromFile(); }

	/// adauga un produs in lista
	void adauga(const Produs& p);

	/// returneaza toate produsele
	vector <Produs> getAll();

	/// cauta un produs dupa id
	int cauta(Produs p);

	/// returneaza numarul de vocale
	int vocale(Produs p);

	/// incarca din fisier
	void loadFromFile();

	/// incarca in fisier
	void storeToFile();
};
