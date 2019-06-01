/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit;
    QComboBox *comboBox_2;
    QPushButton *pushButton;
    QLabel *label2;
    QPushButton *pushButton_2;
    QLabel *label_2;
    QFrame *frame_4;
    QLabel *label_20;
    QLineEdit *lineEdit_2;
    QLabel *label_19;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QFrame *frame_2;
    QLabel *label_3;
    QComboBox *comboBoxEInicial;
    QLabel *label_4;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QComboBox *comboBoxEFinal;
    QPushButton *pushButtonEFinales;
    QListWidget *listWidget;
    QLabel *label_10;
    QFrame *frame_3;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLabel *label_7;
    QPushButton *pushButton_4;
    QLabel *label_15;
    QListWidget *listWidget_2;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QListWidget *listWidgetEIniciales;
    QListWidget *listWidgetEFinales;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1077, 642);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 551, 451));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        comboBox = new QComboBox(frame);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(150, 110, 211, 32));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 10, 541, 61));
        label->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(frame);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 120, 101, 20));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 160, 66, 20));
        label_13 = new QLabel(frame);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 200, 111, 20));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(150, 150, 211, 31));
        comboBox_2 = new QComboBox(frame);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(150, 190, 211, 32));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 240, 211, 30));
        label2 = new QLabel(frame);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(180, 280, 141, 51));
        label2->setFrameShape(QFrame::NoFrame);
        label2->setScaledContents(false);
        label2->setAlignment(Qt::AlignCenter);
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 410, 231, 30));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(520, 10, 16, 20));
        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(380, 120, 161, 131));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        label_20 = new QLabel(frame_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(30, 20, 101, 21));
        lineEdit_2 = new QLineEdit(frame_4);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(40, 50, 111, 31));
        label_19 = new QLabel(frame_4);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(20, 50, 21, 31));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_19->setFont(font);
        pushButton_5 = new QPushButton(frame_4);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 90, 86, 28));
        pushButton_7 = new QPushButton(frame_4);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(110, 90, 41, 30));
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 450, 551, 171));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 181, 51));
        label_3->setAlignment(Qt::AlignCenter);
        comboBoxEInicial = new QComboBox(frame_2);
        comboBoxEInicial->setObjectName(QString::fromUtf8("comboBoxEInicial"));
        comboBoxEInicial->setGeometry(QRect(220, 20, 131, 32));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 191, 31));
        label_4->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(520, 10, 16, 20));
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 130, 301, 30));
        comboBoxEFinal = new QComboBox(frame_2);
        comboBoxEFinal->setObjectName(QString::fromUtf8("comboBoxEFinal"));
        comboBoxEFinal->setGeometry(QRect(220, 60, 131, 31));
        pushButtonEFinales = new QPushButton(frame_2);
        pushButtonEFinales->setObjectName(QString::fromUtf8("pushButtonEFinales"));
        pushButtonEFinales->setGeometry(QRect(370, 60, 171, 27));
        listWidget = new QListWidget(centralWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(560, 170, 131, 441));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(560, 130, 141, 51));
        label_10->setAlignment(Qt::AlignCenter);
        frame_3 = new QFrame(centralWidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(550, 0, 531, 131));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        lineEdit_3 = new QLineEdit(frame_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(90, 20, 381, 28));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 30, 81, 21));
        label_5->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(500, 10, 16, 20));
        pushButton_4 = new QPushButton(frame_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 70, 151, 30));
        label_15 = new QLabel(frame_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(180, 69, 291, 31));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy);
        label_15->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        listWidget_2 = new QListWidget(centralWidget);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(700, 170, 211, 441));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(700, 140, 211, 31));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(920, 150, 151, 16));
        label_17->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(920, 210, 151, 16));
        label_18->setAlignment(Qt::AlignCenter);
        listWidgetEIniciales = new QListWidget(centralWidget);
        listWidgetEIniciales->setObjectName(QString::fromUtf8("listWidgetEIniciales"));
        listWidgetEIniciales->setGeometry(QRect(920, 170, 151, 31));
        listWidgetEFinales = new QListWidget(centralWidget);
        listWidgetEFinales->setObjectName(QString::fromUtf8("listWidgetEFinales"));
        listWidgetEFinales->setGeometry(QRect(920, 230, 151, 381));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QApplication::translate("MainWindow", "Nuevo estado", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "q0", nullptr));

        label->setText(QApplication::translate("MainWindow", "Ingrese Transici\303\263n", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Estado partida", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "S\303\255mbolo", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Estado llegada", nullptr));
        comboBox_2->setItemText(0, QString());
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", "Nuevo estado", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MainWindow", "q0", nullptr));

        pushButton->setText(QApplication::translate("MainWindow", "Ingresar transici\303\263n", nullptr));
        label2->setText(QApplication::translate("MainWindow", "Transici\303\263n Exitosa", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Terminar de ingresar transiciones", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "Nuevo estado", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "q", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "Aceptar", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "X", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Seleccionar estado inicial", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Ingresar estado(s) final(es)", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "2", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Terminar de elegir estado inical y final(es)", nullptr));
        pushButtonEFinales->setText(QApplication::translate("MainWindow", "Ingresar estado final", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "q0", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Estados disponibles</p></body></html>", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Palabra", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "3", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Comprobar Palabra", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "No ha ingresado palabra", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "Transiciones", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "Estado inicial", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Estado(s) final(es)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
