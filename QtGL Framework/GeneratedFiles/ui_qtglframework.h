/********************************************************************************
** Form generated from reading UI file 'qtglframework.ui'
**
** Created: Wed Jul 10 21:55:31 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGLFRAMEWORK_H
#define UI_QTGLFRAMEWORK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGLFrameworkClass
{
public:
    QAction *mFOpenFile;
    QAction *mRFill;
    QAction *mRLine;
    QAction *mRFillWire;
    QAction *actionOpen_control_panel;
    QAction *actionClose_control_panel;
    QAction *actionExit;
    QAction *actionFull_Screen;
    QAction *mRFlat;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *glcontainter;
    QWidget *controlPanel;
    QVBoxLayout *verticalLayout;
    QGroupBox *renderGroupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *ctrPnlRFill;
    QRadioButton *ctrPnlRLine;
    QRadioButton *ctrPnlRFilewire;
    QRadioButton *ctrPnlFlat;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuWindows;
    QMenu *menuWindow;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGLFrameworkClass)
    {
        if (QtGLFrameworkClass->objectName().isEmpty())
            QtGLFrameworkClass->setObjectName(QString::fromUtf8("QtGLFrameworkClass"));
        QtGLFrameworkClass->resize(899, 650);
        mFOpenFile = new QAction(QtGLFrameworkClass);
        mFOpenFile->setObjectName(QString::fromUtf8("mFOpenFile"));
        mRFill = new QAction(QtGLFrameworkClass);
        mRFill->setObjectName(QString::fromUtf8("mRFill"));
        mRLine = new QAction(QtGLFrameworkClass);
        mRLine->setObjectName(QString::fromUtf8("mRLine"));
        mRFillWire = new QAction(QtGLFrameworkClass);
        mRFillWire->setObjectName(QString::fromUtf8("mRFillWire"));
        actionOpen_control_panel = new QAction(QtGLFrameworkClass);
        actionOpen_control_panel->setObjectName(QString::fromUtf8("actionOpen_control_panel"));
        actionOpen_control_panel->setCheckable(true);
        actionClose_control_panel = new QAction(QtGLFrameworkClass);
        actionClose_control_panel->setObjectName(QString::fromUtf8("actionClose_control_panel"));
        actionClose_control_panel->setCheckable(true);
        actionExit = new QAction(QtGLFrameworkClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionFull_Screen = new QAction(QtGLFrameworkClass);
        actionFull_Screen->setObjectName(QString::fromUtf8("actionFull_Screen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/QtGLFramework/Resources/20130710010820632_easyicon_net_256.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFull_Screen->setIcon(icon);
        mRFlat = new QAction(QtGLFrameworkClass);
        mRFlat->setObjectName(QString::fromUtf8("mRFlat"));
        centralWidget = new QWidget(QtGLFrameworkClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setAutoFillBackground(false);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        glcontainter = new QHBoxLayout();
        glcontainter->setSpacing(1);
        glcontainter->setObjectName(QString::fromUtf8("glcontainter"));

        horizontalLayout_2->addLayout(glcontainter);

        controlPanel = new QWidget(centralWidget);
        controlPanel->setObjectName(QString::fromUtf8("controlPanel"));
        verticalLayout = new QVBoxLayout(controlPanel);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        renderGroupBox = new QGroupBox(controlPanel);
        renderGroupBox->setObjectName(QString::fromUtf8("renderGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(renderGroupBox->sizePolicy().hasHeightForWidth());
        renderGroupBox->setSizePolicy(sizePolicy1);
        renderGroupBox->setMinimumSize(QSize(114, 0));
        renderGroupBox->setMaximumSize(QSize(100, 130));
        verticalLayout_2 = new QVBoxLayout(renderGroupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ctrPnlRFill = new QRadioButton(renderGroupBox);
        ctrPnlRFill->setObjectName(QString::fromUtf8("ctrPnlRFill"));
        ctrPnlRFill->setChecked(true);

        verticalLayout_2->addWidget(ctrPnlRFill);

        ctrPnlRLine = new QRadioButton(renderGroupBox);
        ctrPnlRLine->setObjectName(QString::fromUtf8("ctrPnlRLine"));

        verticalLayout_2->addWidget(ctrPnlRLine);

        ctrPnlRFilewire = new QRadioButton(renderGroupBox);
        ctrPnlRFilewire->setObjectName(QString::fromUtf8("ctrPnlRFilewire"));

        verticalLayout_2->addWidget(ctrPnlRFilewire);

        ctrPnlFlat = new QRadioButton(renderGroupBox);
        ctrPnlFlat->setObjectName(QString::fromUtf8("ctrPnlFlat"));

        verticalLayout_2->addWidget(ctrPnlFlat);


        verticalLayout->addWidget(renderGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(controlPanel);

        horizontalLayout_2->setStretch(0, 5);
        QtGLFrameworkClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGLFrameworkClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 899, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuWindows = new QMenu(menuBar);
        menuWindows->setObjectName(QString::fromUtf8("menuWindows"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        QtGLFrameworkClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(QtGLFrameworkClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setEnabled(true);
        QFont font;
        font.setPointSize(9);
        statusBar->setFont(font);
        QtGLFrameworkClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuWindows->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuFile->addAction(mFOpenFile);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuWindows->addAction(actionFull_Screen);
        menuWindows->addSeparator();
        menuWindows->addAction(mRFill);
        menuWindows->addAction(mRLine);
        menuWindows->addAction(mRFillWire);
        menuWindows->addAction(mRFlat);
        menuWindow->addAction(actionOpen_control_panel);

        retranslateUi(QtGLFrameworkClass);
        QObject::connect(actionOpen_control_panel, SIGNAL(triggered(bool)), controlPanel, SLOT(setVisible(bool)));
        QObject::connect(actionExit, SIGNAL(triggered()), QtGLFrameworkClass, SLOT(close()));

        QMetaObject::connectSlotsByName(QtGLFrameworkClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtGLFrameworkClass)
    {
        QtGLFrameworkClass->setWindowTitle(QApplication::translate("QtGLFrameworkClass", "QtGLFramework", 0, QApplication::UnicodeUTF8));
        mFOpenFile->setText(QApplication::translate("QtGLFrameworkClass", "Open File", 0, QApplication::UnicodeUTF8));
        mRFill->setText(QApplication::translate("QtGLFrameworkClass", "Fill", 0, QApplication::UnicodeUTF8));
        mRLine->setText(QApplication::translate("QtGLFrameworkClass", "Line", 0, QApplication::UnicodeUTF8));
        mRFillWire->setText(QApplication::translate("QtGLFrameworkClass", "FillWire", 0, QApplication::UnicodeUTF8));
        actionOpen_control_panel->setText(QApplication::translate("QtGLFrameworkClass", "&Open control panel", 0, QApplication::UnicodeUTF8));
        actionClose_control_panel->setText(QApplication::translate("QtGLFrameworkClass", "Close control panel", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("QtGLFrameworkClass", "Exit", 0, QApplication::UnicodeUTF8));
        actionFull_Screen->setText(QApplication::translate("QtGLFrameworkClass", "Full Screen", 0, QApplication::UnicodeUTF8));
        mRFlat->setText(QApplication::translate("QtGLFrameworkClass", "Flat", 0, QApplication::UnicodeUTF8));
        renderGroupBox->setTitle(QApplication::translate("QtGLFrameworkClass", "Render mode", 0, QApplication::UnicodeUTF8));
        ctrPnlRFill->setText(QApplication::translate("QtGLFrameworkClass", "Fill", 0, QApplication::UnicodeUTF8));
        ctrPnlRLine->setText(QApplication::translate("QtGLFrameworkClass", "Line", 0, QApplication::UnicodeUTF8));
        ctrPnlRFilewire->setText(QApplication::translate("QtGLFrameworkClass", "Fillwire", 0, QApplication::UnicodeUTF8));
        ctrPnlFlat->setText(QApplication::translate("QtGLFrameworkClass", "Flat", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("QtGLFrameworkClass", "File", 0, QApplication::UnicodeUTF8));
        menuWindows->setTitle(QApplication::translate("QtGLFrameworkClass", "Render mode", 0, QApplication::UnicodeUTF8));
        menuWindow->setTitle(QApplication::translate("QtGLFrameworkClass", "&Tool", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtGLFrameworkClass: public Ui_QtGLFrameworkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGLFRAMEWORK_H
