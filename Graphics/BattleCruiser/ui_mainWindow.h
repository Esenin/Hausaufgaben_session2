/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created: Mon 18. Feb 20:44:01 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *mainLayout;
    QGroupBox *groupBoxBottom;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelAngle;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPower;
    QLCDNumber *lcdNumber;
    QGroupBox *groupBoxStat;
    QPushButton *pushButtonRestart;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLCDNumber *lcdNumberTimer;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLCDNumber *lcdNumberHitsCount;
    QLabel *label_3;
    QLCDNumber *lcdNumberShotsCount;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(561, 478);
        MainWindow->setMinimumSize(QSize(550, 475));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 551, 431));
        mainLayout = new QVBoxLayout(layoutWidget);
        mainLayout->setSpacing(6);
        mainLayout->setContentsMargins(5, 5, 5, 5);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setSizeConstraint(QLayout::SetMinimumSize);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        groupBoxBottom = new QGroupBox(layoutWidget);
        groupBoxBottom->setObjectName(QString::fromUtf8("groupBoxBottom"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBoxBottom->sizePolicy().hasHeightForWidth());
        groupBoxBottom->setSizePolicy(sizePolicy);
        groupBoxBottom->setMinimumSize(QSize(500, 121));
        groupBoxBottom->setMaximumSize(QSize(800, 121));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(11);
        font.setKerning(false);
        font.setStyleStrategy(QFont::PreferDefault);
        groupBoxBottom->setFont(font);
        groupBoxBottom->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        layoutWidget1 = new QWidget(groupBoxBottom);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 493, 107));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, 5);
        labelAngle = new QLabel(layoutWidget1);
        labelAngle->setObjectName(QString::fromUtf8("labelAngle"));
        labelAngle->setMinimumSize(QSize(50, 20));
        labelAngle->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(labelAngle);

        progressBar = new QProgressBar(layoutWidget1);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMinimumSize(QSize(20, 40));
        progressBar->setMinimum(0);
        progressBar->setMaximum(95);
        progressBar->setValue(45);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar->setTextVisible(true);
        progressBar->setOrientation(Qt::Vertical);
        progressBar->setInvertedAppearance(false);

        horizontalLayout->addWidget(progressBar);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 2);
        labelPower = new QLabel(layoutWidget1);
        labelPower->setObjectName(QString::fromUtf8("labelPower"));
        labelPower->setMinimumSize(QSize(50, 20));

        horizontalLayout_2->addWidget(labelPower);

        lcdNumber = new QLCDNumber(layoutWidget1);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setMinimumSize(QSize(40, 40));
        lcdNumber->setFrameShape(QFrame::Panel);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setNumDigits(2);
        lcdNumber->setDigitCount(2);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(50));

        horizontalLayout_2->addWidget(lcdNumber);

        groupBoxStat = new QGroupBox(layoutWidget1);
        groupBoxStat->setObjectName(QString::fromUtf8("groupBoxStat"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBoxStat->sizePolicy().hasHeightForWidth());
        groupBoxStat->setSizePolicy(sizePolicy1);
        groupBoxStat->setMinimumSize(QSize(270, 0));
        QFont font1;
        font1.setPointSize(11);
        groupBoxStat->setFont(font1);
        groupBoxStat->setAutoFillBackground(false);
        groupBoxStat->setFlat(false);
        pushButtonRestart = new QPushButton(groupBoxStat);
        pushButtonRestart->setObjectName(QString::fromUtf8("pushButtonRestart"));
        pushButtonRestart->setGeometry(QRect(180, 20, 75, 23));
        layoutWidget2 = new QWidget(groupBoxStat);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 159, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lcdNumberTimer = new QLCDNumber(layoutWidget2);
        lcdNumberTimer->setObjectName(QString::fromUtf8("lcdNumberTimer"));
        lcdNumberTimer->setSmallDecimalPoint(false);
        lcdNumberTimer->setNumDigits(3);
        lcdNumberTimer->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberTimer->setProperty("value", QVariant(0));
        lcdNumberTimer->setProperty("intValue", QVariant(0));

        horizontalLayout_3->addWidget(lcdNumberTimer);

        layoutWidget3 = new QWidget(groupBoxStat);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 50, 236, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        lcdNumberHitsCount = new QLCDNumber(layoutWidget3);
        lcdNumberHitsCount->setObjectName(QString::fromUtf8("lcdNumberHitsCount"));
        lcdNumberHitsCount->setDigitCount(3);
        lcdNumberHitsCount->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_4->addWidget(lcdNumberHitsCount);

        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lcdNumberShotsCount = new QLCDNumber(layoutWidget3);
        lcdNumberShotsCount->setObjectName(QString::fromUtf8("lcdNumberShotsCount"));
        lcdNumberShotsCount->setDigitCount(3);
        lcdNumberShotsCount->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout_4->addWidget(lcdNumberShotsCount);


        horizontalLayout_2->addWidget(groupBoxStat);


        gridLayout->addLayout(horizontalLayout_2, 0, 1, 1, 1);


        mainLayout->addWidget(groupBoxBottom);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 561, 21));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName(QString::fromUtf8("menuGame"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGame->menuAction());
        menuGame->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BattleCruiser Game", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        groupBoxBottom->setTitle(QApplication::translate("MainWindow", "Game state", 0, QApplication::UnicodeUTF8));
        labelAngle->setText(QApplication::translate("MainWindow", "Gun \n"
" angle:", 0, QApplication::UnicodeUTF8));
        labelPower->setText(QApplication::translate("MainWindow", "Gun \n"
" Power:", 0, QApplication::UnicodeUTF8));
        groupBoxStat->setTitle(QApplication::translate("MainWindow", "Statistics", 0, QApplication::UnicodeUTF8));
        pushButtonRestart->setText(QApplication::translate("MainWindow", "Restart", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Time remaining:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Hits:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Shot count:", 0, QApplication::UnicodeUTF8));
        menuGame->setTitle(QApplication::translate("MainWindow", "Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
