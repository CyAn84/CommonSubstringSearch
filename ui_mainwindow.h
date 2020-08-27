/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionGenerate;
    QAction *actionSearch;
    QAction *actionPaste;
    QAction *actionOpenFile;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidgetResult;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QListWidget *listWidgetResult;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(825, 607);
        MainWindow->setMinimumSize(QSize(810, 605));
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/quit.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/icons/system-log-out.png"), QSize(), QIcon::Normal, QIcon::On);
        actionQuit->setIcon(icon);
        actionGenerate = new QAction(MainWindow);
        actionGenerate->setObjectName(QStringLiteral("actionGenerate"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/format-justify-left.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral(":/icons/generate.png"), QSize(), QIcon::Normal, QIcon::On);
        actionGenerate->setIcon(icon1);
        actionSearch = new QAction(MainWindow);
        actionSearch->setObjectName(QStringLiteral("actionSearch"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/search.png"), QSize(), QIcon::Normal, QIcon::On);
        actionSearch->setIcon(icon2);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/icons/paste.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPaste->setIcon(icon3);
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName(QStringLiteral("actionOpenFile"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/icons/open.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpenFile->setIcon(icon4);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/icons/help.png"), QSize(), QIcon::Normal, QIcon::On);
        actionAbout->setIcon(icon5);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(10);
        textEdit->setFont(font);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 825, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setAllowedAreas(Qt::AllToolBarAreas);
        mainToolBar->setIconSize(QSize(32, 32));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidgetResult = new QDockWidget(MainWindow);
        dockWidgetResult->setObjectName(QStringLiteral("dockWidgetResult"));
        dockWidgetResult->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listWidgetResult = new QListWidget(dockWidgetContents);
        listWidgetResult->setObjectName(QStringLiteral("listWidgetResult"));
        listWidgetResult->setFont(font);

        gridLayout_2->addWidget(listWidgetResult, 0, 0, 1, 1);

        dockWidgetResult->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidgetResult);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpenFile);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionGenerate);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionSearch);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionGenerate);
        mainToolBar->addAction(actionOpenFile);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addAction(actionSearch);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionQuit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        actionGenerate->setText(QApplication::translate("MainWindow", "Generate Strings", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionGenerate->setStatusTip(QApplication::translate("MainWindow", "Generate strings randomly", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionGenerate->setShortcut(QApplication::translate("MainWindow", "Alt+G", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSearch->setText(QApplication::translate("MainWindow", "Search Common Substrings", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionSearch->setStatusTip(QApplication::translate("MainWindow", "Search the common strings", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionSearch->setShortcut(QApplication::translate("MainWindow", "Alt+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste From Clipboard", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionPaste->setStatusTip(QApplication::translate("MainWindow", "Paste strings from the clipboard", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpenFile->setText(QApplication::translate("MainWindow", "Open File...", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        actionOpenFile->setStatusTip(QApplication::translate("MainWindow", "Get strings from a text file", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        actionOpenFile->setShortcut(QApplication::translate("MainWindow", "Alt+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "About", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", Q_NULLPTR));
        mainToolBar->setWindowTitle(QApplication::translate("MainWindow", "Toolbar", Q_NULLPTR));
        dockWidgetResult->setWindowTitle(QApplication::translate("MainWindow", "Results", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
