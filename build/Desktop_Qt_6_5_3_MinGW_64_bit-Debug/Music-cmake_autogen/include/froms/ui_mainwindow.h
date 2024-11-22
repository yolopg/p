/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget_online;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QListWidget *listWidget_mymusic;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_6;
    QListWidget *listWidget_4;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QListWidget *listWidget_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_top;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter_4;
    QSplitter *splitter_2;
    QPushButton *page_last;
    QPushButton *page_next;
    QSplitter *splitter_3;
    QLineEdit *lineEdit;
    QPushButton *bnt_serach;
    QPushButton *bnt_addsong;
    QPushButton *pushButton_next_2;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QVBoxLayout *verticalLayout_4;
    QWidget *mylovewidget;
    QWidget *musicplayerwidget;
    QVBoxLayout *verticalLayout_5;
    QTableView *tableView;
    QWidget *page2;
    QLabel *label_4;
    QWidget *page3;
    QLabel *label_5;
    QWidget *widget_bottom;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bnt_last;
    QPushButton *bnt_stop;
    QPushButton *bnt_next;
    QLabel *labelMylove;
    QHBoxLayout *horizontalLayout_4;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1135, 909);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setMinimumSize(QSize(200, 0));
        scrollArea->setMaximumSize(QSize(300, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 298, 761));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName("label");
        label->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(label);

        groupBox = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(0, 250));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        listWidget_online = new QListWidget(groupBox);
        new QListWidgetItem(listWidget_online);
        new QListWidgetItem(listWidget_online);
        new QListWidgetItem(listWidget_online);
        new QListWidgetItem(listWidget_online);
        listWidget_online->setObjectName("listWidget_online");
        listWidget_online->setFocusPolicy(Qt::NoFocus);
        listWidget_online->setFrameShape(QFrame::NoFrame);

        gridLayout_3->addWidget(listWidget_online, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents_2);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(0, 300));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName("gridLayout_4");
        listWidget_mymusic = new QListWidget(groupBox_2);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget_mymusic);
        __qlistwidgetitem->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QListWidgetItem(listWidget_mymusic);
        new QListWidgetItem(listWidget_mymusic);
        new QListWidgetItem(listWidget_mymusic);
        new QListWidgetItem(listWidget_mymusic);
        listWidget_mymusic->setObjectName("listWidget_mymusic");
        listWidget_mymusic->setFocusPolicy(Qt::NoFocus);
        listWidget_mymusic->setFrameShape(QFrame::NoFrame);

        gridLayout_4->addWidget(listWidget_mymusic, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        tabWidget = new QTabWidget(scrollAreaWidgetContents_2);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_6 = new QGridLayout(tab);
        gridLayout_6->setObjectName("gridLayout_6");
        listWidget_4 = new QListWidget(tab);
        listWidget_4->setObjectName("listWidget_4");

        gridLayout_6->addWidget(listWidget_4, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setObjectName("gridLayout_5");
        listWidget_3 = new QListWidget(tab_2);
        listWidget_3->setObjectName("listWidget_3");

        gridLayout_5->addWidget(listWidget_3, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        groupBox_2->raise();
        tabWidget->raise();
        groupBox->raise();
        label->raise();
        splitter->addWidget(scrollArea);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName("layoutWidget");
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_top = new QWidget(layoutWidget);
        widget_top->setObjectName("widget_top");
        widget_top->setMinimumSize(QSize(0, 60));
        widget_top->setMaximumSize(QSize(1000, 60));
        horizontalLayout = new QHBoxLayout(widget_top);
        horizontalLayout->setObjectName("horizontalLayout");
        splitter_4 = new QSplitter(widget_top);
        splitter_4->setObjectName("splitter_4");
        splitter_4->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(splitter_4);
        splitter_2->setObjectName("splitter_2");
        splitter_2->setOrientation(Qt::Horizontal);
        page_last = new QPushButton(splitter_2);
        page_last->setObjectName("page_last");
        page_last->setMinimumSize(QSize(25, 25));
        page_last->setMaximumSize(QSize(25, 25));
        splitter_2->addWidget(page_last);
        page_next = new QPushButton(splitter_2);
        page_next->setObjectName("page_next");
        page_next->setMinimumSize(QSize(25, 25));
        page_next->setMaximumSize(QSize(25, 25));
        splitter_2->addWidget(page_next);
        splitter_4->addWidget(splitter_2);
        splitter_3 = new QSplitter(splitter_4);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Horizontal);
        lineEdit = new QLineEdit(splitter_3);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMinimumSize(QSize(110, 25));
        lineEdit->setMaximumSize(QSize(110, 25));
        splitter_3->addWidget(lineEdit);
        bnt_serach = new QPushButton(splitter_3);
        bnt_serach->setObjectName("bnt_serach");
        bnt_serach->setMinimumSize(QSize(25, 25));
        bnt_serach->setMaximumSize(QSize(25, 25));
        splitter_3->addWidget(bnt_serach);
        splitter_4->addWidget(splitter_3);

        horizontalLayout->addWidget(splitter_4);

        bnt_addsong = new QPushButton(widget_top);
        bnt_addsong->setObjectName("bnt_addsong");
        bnt_addsong->setMinimumSize(QSize(60, 30));
        bnt_addsong->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(bnt_addsong);

        pushButton_next_2 = new QPushButton(widget_top);
        pushButton_next_2->setObjectName("pushButton_next_2");
        pushButton_next_2->setMinimumSize(QSize(25, 25));
        pushButton_next_2->setMaximumSize(QSize(25, 25));

        horizontalLayout->addWidget(pushButton_next_2);


        verticalLayout->addWidget(widget_top);

        stackedWidget = new QStackedWidget(layoutWidget);
        stackedWidget->setObjectName("stackedWidget");
        page1 = new QWidget();
        page1->setObjectName("page1");
        verticalLayout_4 = new QVBoxLayout(page1);
        verticalLayout_4->setObjectName("verticalLayout_4");
        mylovewidget = new QWidget(page1);
        mylovewidget->setObjectName("mylovewidget");
        mylovewidget->setMinimumSize(QSize(0, 120));
        mylovewidget->setMaximumSize(QSize(16777215, 120));

        verticalLayout_4->addWidget(mylovewidget);

        musicplayerwidget = new QWidget(page1);
        musicplayerwidget->setObjectName("musicplayerwidget");
        verticalLayout_5 = new QVBoxLayout(musicplayerwidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        tableView = new QTableView(musicplayerwidget);
        tableView->setObjectName("tableView");

        verticalLayout_5->addWidget(tableView);


        verticalLayout_4->addWidget(musicplayerwidget);

        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName("page2");
        label_4 = new QLabel(page2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(180, 150, 54, 16));
        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName("page3");
        label_5 = new QLabel(page3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(230, 170, 54, 16));
        stackedWidget->addWidget(page3);

        verticalLayout->addWidget(stackedWidget);

        splitter->addWidget(layoutWidget);

        verticalLayout_2->addWidget(splitter);

        widget_bottom = new QWidget(centralwidget);
        widget_bottom->setObjectName("widget_bottom");
        widget_bottom->setMinimumSize(QSize(0, 40));
        widget_bottom->setMaximumSize(QSize(16777215, 80));
        gridLayout_2 = new QGridLayout(widget_bottom);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(-1, -1, -1, 5);
        horizontalSpacer_3 = new QSpacerItem(306, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(305, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 2, 1, 1);

        widget = new QWidget(widget_bottom);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(-1, -1, -1, 0);
        horizontalSpacer_2 = new QSpacerItem(140, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        bnt_last = new QPushButton(widget);
        bnt_last->setObjectName("bnt_last");
        bnt_last->setMinimumSize(QSize(25, 25));
        bnt_last->setMaximumSize(QSize(25, 25));

        horizontalLayout_2->addWidget(bnt_last);

        bnt_stop = new QPushButton(widget);
        bnt_stop->setObjectName("bnt_stop");
        bnt_stop->setMinimumSize(QSize(25, 25));
        bnt_stop->setMaximumSize(QSize(25, 25));

        horizontalLayout_2->addWidget(bnt_stop);

        bnt_next = new QPushButton(widget);
        bnt_next->setObjectName("bnt_next");
        bnt_next->setMinimumSize(QSize(25, 25));
        bnt_next->setMaximumSize(QSize(25, 25));

        horizontalLayout_2->addWidget(bnt_next);


        gridLayout->addLayout(horizontalLayout_2, 1, 2, 1, 1);

        labelMylove = new QLabel(widget);
        labelMylove->setObjectName("labelMylove");
        labelMylove->setMinimumSize(QSize(30, 30));
        labelMylove->setMaximumSize(QSize(30, 30));

        gridLayout->addWidget(labelMylove, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMinimumSize(QSize(450, 0));
        horizontalSlider->setMaximumSize(QSize(900, 16777215));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(141, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);


        gridLayout_2->addWidget(widget, 0, 1, 1, 1);


        verticalLayout_2->addWidget(widget_bottom);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1135, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "    \345\234\250\347\272\277\351\237\263\344\271\220", nullptr));

        const bool __sortingEnabled = listWidget_online->isSortingEnabled();
        listWidget_online->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_online->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\216\250\350\215\220", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_online->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "\344\271\220\351\246\206", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_online->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_online->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "\351\233\267\350\276\276", nullptr));
        listWidget_online->setSortingEnabled(__sortingEnabled);

        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "    \346\210\221\347\232\204\351\237\263\344\271\220", nullptr));

        const bool __sortingEnabled1 = listWidget_mymusic->isSortingEnabled();
        listWidget_mymusic->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem4 = listWidget_mymusic->item(0);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "\345\226\234\346\254\242", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = listWidget_mymusic->item(1);
        ___qlistwidgetitem5->setText(QCoreApplication::translate("MainWindow", "\346\234\200\350\277\221\346\222\255\346\224\276", nullptr));
        QListWidgetItem *___qlistwidgetitem6 = listWidget_mymusic->item(2);
        ___qlistwidgetitem6->setText(QCoreApplication::translate("MainWindow", "\346\234\254\345\234\260\345\222\214\344\270\213\350\275\275", nullptr));
        QListWidgetItem *___qlistwidgetitem7 = listWidget_mymusic->item(3);
        ___qlistwidgetitem7->setText(QCoreApplication::translate("MainWindow", "\345\267\262\350\264\255\351\237\263\344\271\220", nullptr));
        QListWidgetItem *___qlistwidgetitem8 = listWidget_mymusic->item(4);
        ___qlistwidgetitem8->setText(QCoreApplication::translate("MainWindow", "\350\257\225\345\220\254\345\210\227\350\241\250", nullptr));
        listWidget_mymusic->setSortingEnabled(__sortingEnabled1);

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\350\207\252\345\273\272\346\255\214\345\215\225", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\346\224\266\350\227\217\346\255\214\345\215\225", nullptr));
        page_last->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        page_next->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        bnt_serach->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        bnt_addsong->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        pushButton_next_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "xixi", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "hehe", nullptr));
        bnt_last->setText(QString());
        bnt_stop->setText(QString());
        bnt_next->setText(QString());
        labelMylove->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
