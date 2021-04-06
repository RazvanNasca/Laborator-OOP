#pragma once
#include "service.h"
#include <QAbstractTableModel>

class TableModel : public QAbstractTableModel {

private:

	vector <Produs> produse;

public:

	TableModel(vector<Produs> produse): produse{produse}{}

	int rowCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return produse.size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return 5;
	}

	QVariant data(const QModelIndex& index, int role) const override
	{
		if (role == Qt::DisplayRole)
		{
			Produs p = produse[index.row()];
			if (index.column() == 0)
				return QString::number(p.getID());
			if (index.column() == 1)
				return QString::fromStdString(p.getNume());
			if (index.column() == 2)
				return QString::fromStdString(p.getTip());
			if (index.column() == 3)
				return QString::number(p.getPret());
			if (index.column() == 4)
				return QString::number(p.getVocale());
		}
		return QVariant();
	}

	void setProducts(const vector<Produs>& prod)
	{
		produse = prod;
		auto topLeft = createIndex(0, 0);
		auto bottomRight = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, bottomRight);
	}

	void refresh()
	{
		emit layoutChanged();
	}

	QVariant headerData(int section, Qt::Orientation orientaion, int role) const
	{
		if (role == Qt::DisplayRole && orientaion == Qt::Horizontal)
		{
			if (section == 0)
				return "ID";
			if (section == 1)
				return "NUME";
			if (section == 2)
				return "TIP";
			if (section == 3)
				return "Pret";
			if (section == 4)
				return "Nr. VOCALE";
		}
		return QVariant();
	}

};

