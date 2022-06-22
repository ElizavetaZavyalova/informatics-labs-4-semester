/********************************************************************************
** Form generated from reading UI file 'slider.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLIDER_H
#define UI_SLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Slider
{
public:
    QVBoxLayout *verticalLayout;
    QSlider *range_1;
    QSlider *range_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Slider)
    {
        if (Slider->objectName().isEmpty())
            Slider->setObjectName(QString::fromUtf8("Slider"));
        Slider->resize(400, 100);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(30);
        sizePolicy.setHeightForWidth(Slider->sizePolicy().hasHeightForWidth());
        Slider->setSizePolicy(sizePolicy);
        Slider->setMinimumSize(QSize(400, 100));
        Slider->setMaximumSize(QSize(400, 100));
        verticalLayout = new QVBoxLayout(Slider);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        range_1 = new QSlider(Slider);
        range_1->setObjectName(QString::fromUtf8("range_1"));
        range_1->setMaximum(255);
        range_1->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(range_1);

        range_2 = new QSlider(Slider);
        range_2->setObjectName(QString::fromUtf8("range_2"));
        range_2->setMaximum(255);
        range_2->setOrientation(Qt::Horizontal);
        range_2->setInvertedControls(true);

        verticalLayout->addWidget(range_2);

        pushButton = new QPushButton(Slider);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(Slider);

        QMetaObject::connectSlotsByName(Slider);
    } // setupUi

    void retranslateUi(QDialog *Slider)
    {
        Slider->setWindowTitle(QCoreApplication::translate("Slider", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Slider", "\320\276\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Slider: public Ui_Slider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLIDER_H
