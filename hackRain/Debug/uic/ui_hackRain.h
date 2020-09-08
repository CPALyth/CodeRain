/********************************************************************************
** Form generated from reading UI file 'hackRain.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HACKRAIN_H
#define UI_HACKRAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hackRainClass
{
public:

    void setupUi(QWidget *hackRainClass)
    {
        if (hackRainClass->objectName().isEmpty())
            hackRainClass->setObjectName(QString::fromUtf8("hackRainClass"));
        hackRainClass->resize(600, 400);

        retranslateUi(hackRainClass);

        QMetaObject::connectSlotsByName(hackRainClass);
    } // setupUi

    void retranslateUi(QWidget *hackRainClass)
    {
        hackRainClass->setWindowTitle(QCoreApplication::translate("hackRainClass", "hackRain", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hackRainClass: public Ui_hackRainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HACKRAIN_H
