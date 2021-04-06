#pragma once
#include <qwidget.h>
#include <qpainter.h>

class HistogramGUI : public QWidget, public Observer {

	Ret& ret;

public:
	
	HistogramGUI(Ret& ret) : ret{ ret } {
	
		ret.addObserver(this);
	
	}

	void update() override {
		repaint();
	}

	void paintEvent(QPaintEvent* ev) override{
		QPainter p {this};

		int x = 10;
		for (auto u : ret.getAllReteta())
		{
			p.drawRect(x, 0, 20, u.getPret() * 10);
			x += 40;
		}

	}

};