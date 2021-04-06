#pragma once
#include "service.h"
#include "TableModel.h"
#include <qpushbutton.h>
#include <qtableview.h>
#include <qslider.h>
#include <qlineedit.h>
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qmessagebox.h>
#include <qpushbutton.h>
#include <qobject.h>
#include <qwidget.h>

class ProdusGUI: public QWidget {

private:

	Service& s;
	QTableView* table = new QTableView;
	TableModel* model;

	QSlider* slider = new QSlider;

	/// text fields
	QLineEdit* txtID = new QLineEdit;
	QLineEdit* txtNume = new QLineEdit;
	QLineEdit* txtTip = new QLineEdit;
	QLineEdit* txtPret = new QLineEdit;
	QLineEdit* txtNr = new QLineEdit;

	/// butoane
	QPushButton* butonAdauga = new QPushButton{ "&Adauga" };
	QPushButton* butonFiltreaza = new QPushButton{ "&Filtreaza" };
	QPushButton* butonExit = new QPushButton{ "&Exit" };

	void initGUI();
	void initConnect();
	void loadData(vector<Produs> produse);

public:

	ProdusGUI(Service& s) : s{ s }
	{
		initGUI();
		model = new TableModel{ s.Sorteaza() };
		table->setModel(model);
		loadData(s.Sorteaza());
		initConnect();
	}

};