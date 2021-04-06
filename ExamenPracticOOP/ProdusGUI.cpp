#include "ProdusGUI.h"

void ProdusGUI::initGUI()
{
	QHBoxLayout* mainLayout = new QHBoxLayout;
	setLayout(mainLayout);

	slider->setRange(1, 100);
	slider->setOrientation(Qt::Orientation::Horizontal);

	QVBoxLayout* layoutStang = new QVBoxLayout;
	QVBoxLayout* layoutDrept = new QVBoxLayout;

	QFormLayout* formLy = new QFormLayout;
	formLy->addRow("Id Produs: ", txtID);
	formLy->addRow("Nume Produs: ", txtNume);
	formLy->addRow("Tip Produs: ", txtTip);
	formLy->addRow("Pret Produs: ", txtPret);
	formLy->addRow("Filtreaza: ", txtNr);

	QHBoxLayout* layoutButoane = new QHBoxLayout;
	layoutButoane->addWidget(butonAdauga);
	layoutButoane->addWidget(butonFiltreaza);
	layoutButoane->addWidget(butonExit);

	layoutDrept->addLayout(formLy);
	layoutDrept->addLayout(layoutButoane);

	layoutStang->addWidget(table);
	layoutStang->addWidget(slider);

	mainLayout->addLayout(layoutStang);
	mainLayout->addLayout(layoutDrept);
}

void ProdusGUI::initConnect()
{
	QObject::connect(butonExit, &QPushButton::clicked, [&]() {

		close();
		});

	QObject::connect(butonAdauga, &QPushButton::clicked, [&]() {
			
		int id = txtID->text().toInt();
		string nume = txtNume->text().toStdString();
		string tip = txtTip->text().toStdString();
		double pret = txtPret->text().toDouble();

		int erori = s.adauga(id, nume, tip, pret);
		string mesaj = "";
		if (erori != 0)
		{
			if (erori % 2 == 0)
				mesaj += "Nume vid ";
			if (erori % 3 == 0)
				mesaj += "Pret incorect ";
			if (erori % 5 == 0)
				mesaj += "Id Existent";
			QMessageBox::warning(nullptr, "Date invalide", QString::fromStdString(mesaj));
		}


		loadData(s.Sorteaza());
		model->refresh();


		});

	QObject::connect(butonFiltreaza, &QPushButton::clicked, [&]() {

		double nr = txtNr->text().toDouble();
		double ceva = slider->value();

		loadData(s.Filtreaza(ceva));
		model->refresh();

		});

}

void ProdusGUI::loadData(vector<Produs> produse)
{
	model->setProducts(produse);
}
