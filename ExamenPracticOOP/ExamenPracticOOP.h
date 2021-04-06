#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ExamenPracticOOP.h"

class ExamenPracticOOP : public QMainWindow
{
    Q_OBJECT

public:
    ExamenPracticOOP(QWidget *parent = Q_NULLPTR);

private:
    Ui::ExamenPracticOOPClass ui;
};
