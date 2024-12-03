/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QPushButton *pbtn_replay;
    QLabel *label_5;
    QPushButton *pbtn_down;
    QLCDNumber *lcd_Disc;
    QPushButton *pbtn_up;
    QLabel *label_2;
    QLCDNumber *lcd_turn;
    QGraphicsView *graphicsView;
    QLabel *label;
    QPushButton *pbtn_solve;
    QPushButton *pbt_exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(750, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 10, 700, 350));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        pbtn_replay = new QPushButton(widget);
        pbtn_replay->setObjectName("pbtn_replay");
        pbtn_replay->setGeometry(QRect(420, 20, 81, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setStrikeOut(false);
        font.setKerning(true);
        pbtn_replay->setFont(font);
        pbtn_replay->setMouseTracking(false);
        pbtn_replay->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(0, 255, 0);"));
        pbtn_replay->setIconSize(QSize(20, 20));
        pbtn_replay->setAutoDefault(false);
        pbtn_replay->setFlat(false);
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 310, 641, 16));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 0);"));
        pbtn_down = new QPushButton(widget);
        pbtn_down->setObjectName("pbtn_down");
        pbtn_down->setGeometry(QRect(200, 20, 51, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/icon/image/icon/down-arrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pbtn_down->setIcon(icon);
        pbtn_down->setIconSize(QSize(24, 24));
        pbtn_down->setFlat(false);
        lcd_Disc = new QLCDNumber(widget);
        lcd_Disc->setObjectName("lcd_Disc");
        lcd_Disc->setGeometry(QRect(90, 20, 41, 41));
        lcd_Disc->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lcd_Disc->setAutoFillBackground(false);
        lcd_Disc->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(68, 200, 77);"));
        lcd_Disc->setFrameShape(QFrame::Shape::WinPanel);
        lcd_Disc->setFrameShadow(QFrame::Shadow::Plain);
        lcd_Disc->setLineWidth(7);
        lcd_Disc->setMidLineWidth(1);
        lcd_Disc->setSmallDecimalPoint(false);
        lcd_Disc->setDigitCount(2);
        lcd_Disc->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        lcd_Disc->setProperty("intValue", QVariant(3));
        pbtn_up = new QPushButton(widget);
        pbtn_up->setObjectName("pbtn_up");
        pbtn_up->setGeometry(QRect(140, 20, 51, 41));
        QFont font1;
        font1.setBold(false);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        pbtn_up->setFont(font1);
        pbtn_up->setMouseTracking(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/icon/image/icon/up-arrow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pbtn_up->setIcon(icon1);
        pbtn_up->setIconSize(QSize(24, 24));
        pbtn_up->setCheckable(false);
        pbtn_up->setAutoDefault(false);
        pbtn_up->setFlat(false);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(290, 20, 51, 41));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: rgb(0, 255, 0);"));
        label_2->setFrameShape(QFrame::Shape::WinPanel);
        label_2->setTextFormat(Qt::TextFormat::AutoText);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2->setWordWrap(false);
        lcd_turn = new QLCDNumber(widget);
        lcd_turn->setObjectName("lcd_turn");
        lcd_turn->setGeometry(QRect(340, 20, 41, 41));
        lcd_turn->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        lcd_turn->setAutoFillBackground(false);
        lcd_turn->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(68, 200, 77);"));
        lcd_turn->setFrameShape(QFrame::Shape::WinPanel);
        lcd_turn->setFrameShadow(QFrame::Shadow::Plain);
        lcd_turn->setLineWidth(7);
        lcd_turn->setMidLineWidth(1);
        lcd_turn->setSmallDecimalPoint(false);
        lcd_turn->setDigitCount(2);
        lcd_turn->setSegmentStyle(QLCDNumber::SegmentStyle::Flat);
        lcd_turn->setProperty("intValue", QVariant(0));
        graphicsView = new QGraphicsView(widget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setEnabled(true);
        graphicsView->setGeometry(QRect(40, 110, 600, 220));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setStyleSheet(QString::fromUtf8("background: transparent;"));
        graphicsView->setFrameShape(QFrame::Shape::NoFrame);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        graphicsView->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 51, 41));
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"background-color: rgb(0, 255, 0);"));
        label->setFrameShape(QFrame::Shape::WinPanel);
        label->setTextFormat(Qt::TextFormat::AutoText);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setWordWrap(false);
        pbtn_solve = new QPushButton(widget);
        pbtn_solve->setObjectName("pbtn_solve");
        pbtn_solve->setGeometry(QRect(510, 20, 81, 41));
        pbtn_solve->setFont(font);
        pbtn_solve->setMouseTracking(false);
        pbtn_solve->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(0, 255, 0);"));
        pbtn_solve->setIconSize(QSize(20, 20));
        pbtn_solve->setAutoDefault(false);
        pbtn_solve->setFlat(false);
        pbt_exit = new QPushButton(widget);
        pbt_exit->setObjectName("pbt_exit");
        pbt_exit->setGeometry(QRect(620, 20, 61, 41));
        pbt_exit->setFont(font);
        pbt_exit->setMouseTracking(false);
        pbt_exit->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"background-color: rgb(0, 255, 0);"));
        pbt_exit->setIconSize(QSize(20, 20));
        pbt_exit->setAutoDefault(false);
        pbt_exit->setFlat(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 750, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        pbtn_replay->setDefault(false);
        pbtn_down->setDefault(true);
        pbtn_up->setDefault(true);
        pbtn_solve->setDefault(false);
        pbt_exit->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pbtn_replay->setText(QCoreApplication::translate("MainWindow", "Replay", nullptr));
        label_5->setText(QString());
        pbtn_down->setText(QString());
        pbtn_up->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "TURN", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "DISC", nullptr));
        pbtn_solve->setText(QCoreApplication::translate("MainWindow", "Solve", nullptr));
        pbt_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
