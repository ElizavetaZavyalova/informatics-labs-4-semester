/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *autor;
    QAction *about;
    QAction *blackwhite;
    QAction *inversion;
    QAction *porog;
    QAction *logorifm;
    QAction *piecewise_linear;
    QAction *power;
    QAction *equalization;
    QAction *normal;
    QAction *porog_1;
    QAction *porog_2;
    QAction *dft;
    QAction *averaged;
    QAction *median;
    QAction *Gaus;
    QAction *Loplassian;
    QAction *Derivatives_x;
    QAction *Sobel_x;
    QAction *Shahuro;
    QAction *Derivatives_y;
    QAction *Sobel_y;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QMenu *menudft;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        autor = new QAction(MainWindow);
        autor->setObjectName(QString::fromUtf8("autor"));
        about = new QAction(MainWindow);
        about->setObjectName(QString::fromUtf8("about"));
        blackwhite = new QAction(MainWindow);
        blackwhite->setObjectName(QString::fromUtf8("blackwhite"));
        inversion = new QAction(MainWindow);
        inversion->setObjectName(QString::fromUtf8("inversion"));
        porog = new QAction(MainWindow);
        porog->setObjectName(QString::fromUtf8("porog"));
        logorifm = new QAction(MainWindow);
        logorifm->setObjectName(QString::fromUtf8("logorifm"));
        piecewise_linear = new QAction(MainWindow);
        piecewise_linear->setObjectName(QString::fromUtf8("piecewise_linear"));
        power = new QAction(MainWindow);
        power->setObjectName(QString::fromUtf8("power"));
        equalization = new QAction(MainWindow);
        equalization->setObjectName(QString::fromUtf8("equalization"));
        normal = new QAction(MainWindow);
        normal->setObjectName(QString::fromUtf8("normal"));
        porog_1 = new QAction(MainWindow);
        porog_1->setObjectName(QString::fromUtf8("porog_1"));
        porog_2 = new QAction(MainWindow);
        porog_2->setObjectName(QString::fromUtf8("porog_2"));
        dft = new QAction(MainWindow);
        dft->setObjectName(QString::fromUtf8("dft"));
        averaged = new QAction(MainWindow);
        averaged->setObjectName(QString::fromUtf8("averaged"));
        median = new QAction(MainWindow);
        median->setObjectName(QString::fromUtf8("median"));
        Gaus = new QAction(MainWindow);
        Gaus->setObjectName(QString::fromUtf8("Gaus"));
        Loplassian = new QAction(MainWindow);
        Loplassian->setObjectName(QString::fromUtf8("Loplassian"));
        Derivatives_x = new QAction(MainWindow);
        Derivatives_x->setObjectName(QString::fromUtf8("Derivatives_x"));
        Sobel_x = new QAction(MainWindow);
        Sobel_x->setObjectName(QString::fromUtf8("Sobel_x"));
        Shahuro = new QAction(MainWindow);
        Shahuro->setObjectName(QString::fromUtf8("Shahuro"));
        Derivatives_y = new QAction(MainWindow);
        Derivatives_y->setObjectName(QString::fromUtf8("Derivatives_y"));
        Sobel_y = new QAction(MainWindow);
        Sobel_y->setObjectName(QString::fromUtf8("Sobel_y"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName(QString::fromUtf8("menu_5"));
        menu_6 = new QMenu(menubar);
        menu_6->setObjectName(QString::fromUtf8("menu_6"));
        menudft = new QMenu(menubar);
        menudft->setObjectName(QString::fromUtf8("menudft"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_6->menuAction());
        menubar->addAction(menudft->menuAction());
        menu->addAction(autor);
        menu->addAction(about);
        menu_2->addAction(blackwhite);
        menu_2->addAction(inversion);
        menu_2->addAction(porog_1);
        menu_2->addAction(porog_2);
        menu_3->addAction(porog);
        menu_3->addAction(logorifm);
        menu_3->addAction(piecewise_linear);
        menu_3->addAction(power);
        menu_4->addAction(equalization);
        menu_4->addAction(normal);
        menu_6->addAction(averaged);
        menu_6->addAction(median);
        menu_6->addAction(Gaus);
        menu_6->addAction(Loplassian);
        menu_6->addAction(Derivatives_x);
        menu_6->addAction(Sobel_x);
        menu_6->addAction(Shahuro);
        menu_6->addAction(Derivatives_y);
        menu_6->addAction(Sobel_y);
        menudft->addAction(dft);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        autor->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        about->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        blackwhite->setText(QCoreApplication::translate("MainWindow", "\320\247\320\265\321\200\320\275\320\276-\320\221\320\265\320\273\320\276\320\265", nullptr));
        inversion->setText(QCoreApplication::translate("MainWindow", "\320\230\320\275\320\262\320\265\321\200\321\201\320\270\321\217", nullptr));
        porog->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\320\276\320\263\320\276\320\262\320\276\320\265", nullptr));
        logorifm->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\276\321\200\320\270\321\204\320\274\320\270\321\207\320\265\321\201\320\272\320\276\320\265", nullptr));
        piecewise_linear->setText(QCoreApplication::translate("MainWindow", "\320\232\321\203\321\201\320\276\321\207\320\275\320\276-\320\233\320\270\320\275\320\265\320\271\320\275\320\276\320\265", nullptr));
        power->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\265\320\277\320\265\320\275\320\275\320\276\320\265", nullptr));
        equalization->setText(QCoreApplication::translate("MainWindow", "\320\255\320\272\320\262\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        normal->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        porog_1->setText(QCoreApplication::translate("MainWindow", " \320\237\320\276\321\200\320\276\320\263\320\276\320\262\320\260\321\217_1", nullptr));
        porog_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\321\200\320\276\320\263\320\276\320\262\320\260\321\217_2", nullptr));
        dft->setText(QCoreApplication::translate("MainWindow", "DFT", nullptr));
        averaged->setText(QCoreApplication::translate("MainWindow", "\320\243\321\201\321\200\320\265\320\264\320\275\320\265\320\275\320\275\321\213\320\271", nullptr));
        median->setText(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\264\320\270\320\260\320\275\320\275\321\213\320\271", nullptr));
        Gaus->setText(QCoreApplication::translate("MainWindow", "\320\223\320\260\321\203\321\201", nullptr));
        Loplassian->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\277\320\273\320\260\321\201\320\270\320\260\320\275", nullptr));
        Derivatives_x->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\321\213\320\265_x", nullptr));
        Sobel_x->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\261\320\265\320\273_x", nullptr));
        Shahuro->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\321\205\321\203\321\200\320\276", nullptr));
        Derivatives_y->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\275\321\213\320\265_y", nullptr));
        Sobel_y->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\261\320\265\320\273_y", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260 \320\270\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\257\321\200\320\272\320\276\321\201\321\202\321\214", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\223\320\270\321\201\321\202\320\276\320\263\321\200\320\260\320\274\320\274\320\260", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        menu_6->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\270\320\273\321\214\321\202\321\200\321\213", nullptr));
        menudft->setTitle(QCoreApplication::translate("MainWindow", "DFT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
