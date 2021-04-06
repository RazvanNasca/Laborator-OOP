#include <QtWidgets/QApplication>
#include "service.h"
#include "ProdusGUI.h"

int main(int argc, char *argv[])
{

    Repo r{ "produse.txt" };
    Valid v;
    Service s{r,v};
    
    QApplication a(argc, argv);

    ProdusGUI* g = new ProdusGUI{s};
    g->show();

    return a.exec();
}
