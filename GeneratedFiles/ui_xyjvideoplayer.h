/********************************************************************************
** Form generated from reading UI file 'xyjvideoplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XYJVIDEOPLAYER_H
#define UI_XYJVIDEOPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_xyjVideoPlayerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *xyjVideoPlayerClass)
    {
        if (xyjVideoPlayerClass->objectName().isEmpty())
            xyjVideoPlayerClass->setObjectName(QStringLiteral("xyjVideoPlayerClass"));
        xyjVideoPlayerClass->resize(600, 400);
        menuBar = new QMenuBar(xyjVideoPlayerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        xyjVideoPlayerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(xyjVideoPlayerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        xyjVideoPlayerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(xyjVideoPlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        xyjVideoPlayerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(xyjVideoPlayerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        xyjVideoPlayerClass->setStatusBar(statusBar);

        retranslateUi(xyjVideoPlayerClass);

        QMetaObject::connectSlotsByName(xyjVideoPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *xyjVideoPlayerClass)
    {
        xyjVideoPlayerClass->setWindowTitle(QApplication::translate("xyjVideoPlayerClass", "xyjVideoPlayer", 0));
    } // retranslateUi

};

namespace Ui {
    class xyjVideoPlayerClass: public Ui_xyjVideoPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XYJVIDEOPLAYER_H
