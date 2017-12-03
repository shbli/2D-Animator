/********************************************************************************
** Form generated from reading UI file 'configrationwindow.ui'
**
** Created: Fri Nov 16 17:42:31 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGRATIONWINDOW_H
#define UI_CONFIGRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigrationWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QGridLayout *Graphics_view_gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *refresh;
    QPushButton *slowAnimationPushButton;
    QToolBox *toolBox;
    QWidget *MapInfo;
    QGridLayout *gridLayout_4;
    QLineEdit *MapXMLNamelineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *MapNamelineEdit;
    QLineEdit *MapBackgroundlineEdit;
    QLabel *label_6;
    QLabel *label_11;
    QPushButton *loadXMLpushButton;
    QSpacerItem *verticalSpacer;
    QCheckBox *MapCheckPointcheckBox;
    QWidget *Elementproperties;
    QGridLayout *gridLayout_5;
    QListWidget *ElementlistWidget;
    QLabel *label_14;
    QLineEdit *ElementNamelineEdit;
    QLabel *label_20;
    QLineEdit *ElementZlineEdit;
    QLabel *label_15;
    QLineEdit *ElementSVGlineEdit;
    QLabel *label_2;
    QComboBox *ElementTypeComboBox;
    QPushButton *AddElementpushButton;
    QLabel *label_13;
    QPushButton *ElementXDragDroppushButton;
    QLineEdit *ElementXlineEdit;
    QPushButton *ElementYDragDroppushButton;
    QLineEdit *ElementYlineEdit;
    QPushButton *ElementRotationDragDroppushButton;
    QLineEdit *ElementRotationlineEdit;
    QLabel *label_5;
    QLineEdit *ElementXMLlineEdit;
    QPushButton *DeleteElementPushButton;
    QCheckBox *ElementFlippedcheckBox;
    QLabel *label_7;
    QComboBox *ElementRewardTypeComboBox;
    QLabel *label_8;
    QLineEdit *ElementKeylineEdit;
    QLabel *label_9;
    QLineEdit *ElementScalelineEdit;
    QWidget *EnemyProperties;
    QGridLayout *gridLayout_6;
    QCheckBox *EnemycheckBox;
    QLabel *Enemylabel;
    QLabel *EnemyLevellabel;
    QListWidget *EnemylistWidget;
    QLabel *EnemyXMLlabel;
    QPushButton *EnemyAddpushButton;
    QPushButton *EnemyDeletepushButton;
    QLineEdit *EnemyLevellineEdit;
    QLineEdit *EnemyXMLlineEdit;
    QLabel *ghostLabel;
    QLineEdit *ghostXMLlineEdit;

    void setupUi(QMainWindow *ConfigrationWindow)
    {
        if (ConfigrationWindow->objectName().isEmpty())
            ConfigrationWindow->setObjectName(QString::fromUtf8("ConfigrationWindow"));
        ConfigrationWindow->setWindowModality(Qt::WindowModal);
        ConfigrationWindow->resize(939, 719);
        ConfigrationWindow->setStyleSheet(QString::fromUtf8(""));
        ConfigrationWindow->setInputMethodHints(Qt::ImhLowercaseOnly);
        centralWidget = new QWidget(ConfigrationWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("color: rgb(218, 218, 218);\n"
"background-color: rgb(52, 52, 52);\n"
"alternate-background-color: rgb(83, 83, 83);\n"
"border-color: rgb(113, 113, 113);\n"
"selection-background-color: rgb(131, 131, 131);\n"
"selection-color: rgb(222, 222, 222);\n"
""));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label->setMargin(3);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        Graphics_view_gridLayout = new QGridLayout();
        Graphics_view_gridLayout->setSpacing(6);
        Graphics_view_gridLayout->setObjectName(QString::fromUtf8("Graphics_view_gridLayout"));

        gridLayout->addLayout(Graphics_view_gridLayout, 0, 1, 1, 1);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(600, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	color: rgb(200, 200, 200);\n"
"	border-color: rgb(173, 173, 173);\n"
"	background-color: rgb(83, 83, 83);\n"
"}\n"
"\n"
"QPushButton:disabled\n"
"{\n"
"color: rgb(90, 90, 90);\n"
"background-color: rgb(66, 66, 66);\n"
"border:0px\n"
"}\n"
"\n"
"QComboBox {\n"
"	background-color: rgb(83, 83, 83);\n"
"}\n"
"\n"
"QLineEdit {\n"
"	background-color: rgb(83, 83, 83);\n"
"	border-color: rgb(77, 77, 77);\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"	background-color: rgb(180,180,180);\n"
"}"));
        scrollArea->setFrameShape(QFrame::WinPanel);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 596, 695));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        refresh = new QPushButton(scrollAreaWidgetContents);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(refresh->sizePolicy().hasHeightForWidth());
        refresh->setSizePolicy(sizePolicy);
        refresh->setMinimumSize(QSize(0, 0));
        refresh->setMaximumSize(QSize(150, 16777215));
        refresh->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(refresh);

        slowAnimationPushButton = new QPushButton(scrollAreaWidgetContents);
        slowAnimationPushButton->setObjectName(QString::fromUtf8("slowAnimationPushButton"));
        slowAnimationPushButton->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(slowAnimationPushButton);


        gridLayout_2->addLayout(horizontalLayout, 12, 0, 1, 2);

        toolBox = new QToolBox(scrollAreaWidgetContents);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        MapInfo = new QWidget();
        MapInfo->setObjectName(QString::fromUtf8("MapInfo"));
        MapInfo->setGeometry(QRect(0, 0, 578, 557));
        gridLayout_4 = new QGridLayout(MapInfo);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        MapXMLNamelineEdit = new QLineEdit(MapInfo);
        MapXMLNamelineEdit->setObjectName(QString::fromUtf8("MapXMLNamelineEdit"));
        MapXMLNamelineEdit->setMinimumSize(QSize(100, 0));

        gridLayout_4->addWidget(MapXMLNamelineEdit, 1, 2, 1, 1);

        label_3 = new QLabel(MapInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(MapInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 4, 0, 1, 1);

        MapNamelineEdit = new QLineEdit(MapInfo);
        MapNamelineEdit->setObjectName(QString::fromUtf8("MapNamelineEdit"));

        gridLayout_4->addWidget(MapNamelineEdit, 4, 2, 1, 1);

        MapBackgroundlineEdit = new QLineEdit(MapInfo);
        MapBackgroundlineEdit->setObjectName(QString::fromUtf8("MapBackgroundlineEdit"));

        gridLayout_4->addWidget(MapBackgroundlineEdit, 5, 2, 1, 1);

        label_6 = new QLabel(MapInfo);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 5, 0, 1, 1);

        label_11 = new QLabel(MapInfo);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_11, 0, 0, 1, 4);

        loadXMLpushButton = new QPushButton(MapInfo);
        loadXMLpushButton->setObjectName(QString::fromUtf8("loadXMLpushButton"));

        gridLayout_4->addWidget(loadXMLpushButton, 2, 0, 1, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 6, 0, 1, 1);

        MapCheckPointcheckBox = new QCheckBox(MapInfo);
        MapCheckPointcheckBox->setObjectName(QString::fromUtf8("MapCheckPointcheckBox"));

        gridLayout_4->addWidget(MapCheckPointcheckBox, 3, 0, 1, 3);

        toolBox->addItem(MapInfo, QString::fromUtf8("Map Info"));
        MapXMLNamelineEdit->raise();
        label_3->raise();
        label_4->raise();
        MapNamelineEdit->raise();
        MapBackgroundlineEdit->raise();
        label_6->raise();
        label_11->raise();
        loadXMLpushButton->raise();
        MapCheckPointcheckBox->raise();
        Elementproperties = new QWidget();
        Elementproperties->setObjectName(QString::fromUtf8("Elementproperties"));
        Elementproperties->setGeometry(QRect(0, 0, 578, 557));
        gridLayout_5 = new QGridLayout(Elementproperties);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        ElementlistWidget = new QListWidget(Elementproperties);
        ElementlistWidget->setObjectName(QString::fromUtf8("ElementlistWidget"));
        ElementlistWidget->setTabKeyNavigation(false);
        ElementlistWidget->setAlternatingRowColors(true);

        gridLayout_5->addWidget(ElementlistWidget, 1, 0, 1, 5);

        label_14 = new QLabel(Elementproperties);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_5->addWidget(label_14, 3, 0, 1, 1);

        ElementNamelineEdit = new QLineEdit(Elementproperties);
        ElementNamelineEdit->setObjectName(QString::fromUtf8("ElementNamelineEdit"));

        gridLayout_5->addWidget(ElementNamelineEdit, 3, 2, 1, 1);

        label_20 = new QLabel(Elementproperties);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_5->addWidget(label_20, 4, 0, 1, 1);

        ElementZlineEdit = new QLineEdit(Elementproperties);
        ElementZlineEdit->setObjectName(QString::fromUtf8("ElementZlineEdit"));

        gridLayout_5->addWidget(ElementZlineEdit, 4, 2, 1, 1);

        label_15 = new QLabel(Elementproperties);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_5->addWidget(label_15, 5, 0, 1, 1);

        ElementSVGlineEdit = new QLineEdit(Elementproperties);
        ElementSVGlineEdit->setObjectName(QString::fromUtf8("ElementSVGlineEdit"));

        gridLayout_5->addWidget(ElementSVGlineEdit, 5, 2, 1, 1);

        label_2 = new QLabel(Elementproperties);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_5->addWidget(label_2, 6, 0, 1, 1);

        ElementTypeComboBox = new QComboBox(Elementproperties);
        ElementTypeComboBox->setObjectName(QString::fromUtf8("ElementTypeComboBox"));

        gridLayout_5->addWidget(ElementTypeComboBox, 6, 2, 1, 1);

        AddElementpushButton = new QPushButton(Elementproperties);
        AddElementpushButton->setObjectName(QString::fromUtf8("AddElementpushButton"));

        gridLayout_5->addWidget(AddElementpushButton, 2, 0, 1, 2);

        label_13 = new QLabel(Elementproperties);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(16777215, 20));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_13, 0, 0, 1, 5);

        ElementXDragDroppushButton = new QPushButton(Elementproperties);
        ElementXDragDroppushButton->setObjectName(QString::fromUtf8("ElementXDragDroppushButton"));

        gridLayout_5->addWidget(ElementXDragDroppushButton, 8, 0, 1, 1);

        ElementXlineEdit = new QLineEdit(Elementproperties);
        ElementXlineEdit->setObjectName(QString::fromUtf8("ElementXlineEdit"));

        gridLayout_5->addWidget(ElementXlineEdit, 8, 2, 1, 1);

        ElementYDragDroppushButton = new QPushButton(Elementproperties);
        ElementYDragDroppushButton->setObjectName(QString::fromUtf8("ElementYDragDroppushButton"));
        ElementYDragDroppushButton->setMaximumSize(QSize(16000000, 16777215));

        gridLayout_5->addWidget(ElementYDragDroppushButton, 9, 0, 1, 1);

        ElementYlineEdit = new QLineEdit(Elementproperties);
        ElementYlineEdit->setObjectName(QString::fromUtf8("ElementYlineEdit"));

        gridLayout_5->addWidget(ElementYlineEdit, 9, 2, 1, 1);

        ElementRotationDragDroppushButton = new QPushButton(Elementproperties);
        ElementRotationDragDroppushButton->setObjectName(QString::fromUtf8("ElementRotationDragDroppushButton"));
        sizePolicy.setHeightForWidth(ElementRotationDragDroppushButton->sizePolicy().hasHeightForWidth());
        ElementRotationDragDroppushButton->setSizePolicy(sizePolicy);
        ElementRotationDragDroppushButton->setMaximumSize(QSize(16000000, 16777215));

        gridLayout_5->addWidget(ElementRotationDragDroppushButton, 10, 0, 1, 1);

        ElementRotationlineEdit = new QLineEdit(Elementproperties);
        ElementRotationlineEdit->setObjectName(QString::fromUtf8("ElementRotationlineEdit"));

        gridLayout_5->addWidget(ElementRotationlineEdit, 10, 2, 1, 1);

        label_5 = new QLabel(Elementproperties);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 18, 0, 1, 1);

        ElementXMLlineEdit = new QLineEdit(Elementproperties);
        ElementXMLlineEdit->setObjectName(QString::fromUtf8("ElementXMLlineEdit"));

        gridLayout_5->addWidget(ElementXMLlineEdit, 18, 2, 1, 1);

        DeleteElementPushButton = new QPushButton(Elementproperties);
        DeleteElementPushButton->setObjectName(QString::fromUtf8("DeleteElementPushButton"));

        gridLayout_5->addWidget(DeleteElementPushButton, 2, 2, 1, 1);

        ElementFlippedcheckBox = new QCheckBox(Elementproperties);
        ElementFlippedcheckBox->setObjectName(QString::fromUtf8("ElementFlippedcheckBox"));

        gridLayout_5->addWidget(ElementFlippedcheckBox, 11, 0, 1, 3);

        label_7 = new QLabel(Elementproperties);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 14, 0, 1, 1);

        ElementRewardTypeComboBox = new QComboBox(Elementproperties);
        ElementRewardTypeComboBox->setObjectName(QString::fromUtf8("ElementRewardTypeComboBox"));

        gridLayout_5->addWidget(ElementRewardTypeComboBox, 14, 2, 1, 1);

        label_8 = new QLabel(Elementproperties);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_5->addWidget(label_8, 12, 0, 1, 1);

        ElementKeylineEdit = new QLineEdit(Elementproperties);
        ElementKeylineEdit->setObjectName(QString::fromUtf8("ElementKeylineEdit"));

        gridLayout_5->addWidget(ElementKeylineEdit, 12, 2, 1, 1);

        label_9 = new QLabel(Elementproperties);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_5->addWidget(label_9, 7, 0, 1, 1);

        ElementScalelineEdit = new QLineEdit(Elementproperties);
        ElementScalelineEdit->setObjectName(QString::fromUtf8("ElementScalelineEdit"));

        gridLayout_5->addWidget(ElementScalelineEdit, 7, 2, 1, 1);

        toolBox->addItem(Elementproperties, QString::fromUtf8("Element properties"));
        EnemyProperties = new QWidget();
        EnemyProperties->setObjectName(QString::fromUtf8("EnemyProperties"));
        EnemyProperties->setGeometry(QRect(0, 0, 578, 557));
        gridLayout_6 = new QGridLayout(EnemyProperties);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        EnemycheckBox = new QCheckBox(EnemyProperties);
        EnemycheckBox->setObjectName(QString::fromUtf8("EnemycheckBox"));

        gridLayout_6->addWidget(EnemycheckBox, 1, 0, 1, 1);

        Enemylabel = new QLabel(EnemyProperties);
        Enemylabel->setObjectName(QString::fromUtf8("Enemylabel"));
        Enemylabel->setEnabled(false);
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        Enemylabel->setFont(font2);
        Enemylabel->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(Enemylabel, 0, 0, 1, 6);

        EnemyLevellabel = new QLabel(EnemyProperties);
        EnemyLevellabel->setObjectName(QString::fromUtf8("EnemyLevellabel"));
        EnemyLevellabel->setEnabled(false);

        gridLayout_6->addWidget(EnemyLevellabel, 7, 0, 1, 1);

        EnemylistWidget = new QListWidget(EnemyProperties);
        EnemylistWidget->setObjectName(QString::fromUtf8("EnemylistWidget"));
        EnemylistWidget->setEnabled(false);

        gridLayout_6->addWidget(EnemylistWidget, 4, 0, 1, 6);

        EnemyXMLlabel = new QLabel(EnemyProperties);
        EnemyXMLlabel->setObjectName(QString::fromUtf8("EnemyXMLlabel"));
        EnemyXMLlabel->setEnabled(false);

        gridLayout_6->addWidget(EnemyXMLlabel, 9, 0, 1, 1);

        EnemyAddpushButton = new QPushButton(EnemyProperties);
        EnemyAddpushButton->setObjectName(QString::fromUtf8("EnemyAddpushButton"));
        EnemyAddpushButton->setEnabled(false);

        gridLayout_6->addWidget(EnemyAddpushButton, 5, 0, 1, 1);

        EnemyDeletepushButton = new QPushButton(EnemyProperties);
        EnemyDeletepushButton->setObjectName(QString::fromUtf8("EnemyDeletepushButton"));
        EnemyDeletepushButton->setEnabled(false);

        gridLayout_6->addWidget(EnemyDeletepushButton, 6, 0, 1, 1);

        EnemyLevellineEdit = new QLineEdit(EnemyProperties);
        EnemyLevellineEdit->setObjectName(QString::fromUtf8("EnemyLevellineEdit"));
        EnemyLevellineEdit->setEnabled(false);

        gridLayout_6->addWidget(EnemyLevellineEdit, 8, 0, 1, 1);

        EnemyXMLlineEdit = new QLineEdit(EnemyProperties);
        EnemyXMLlineEdit->setObjectName(QString::fromUtf8("EnemyXMLlineEdit"));
        EnemyXMLlineEdit->setEnabled(false);

        gridLayout_6->addWidget(EnemyXMLlineEdit, 10, 0, 1, 1);

        ghostLabel = new QLabel(EnemyProperties);
        ghostLabel->setObjectName(QString::fromUtf8("ghostLabel"));
        ghostLabel->setEnabled(false);

        gridLayout_6->addWidget(ghostLabel, 2, 0, 1, 1);

        ghostXMLlineEdit = new QLineEdit(EnemyProperties);
        ghostXMLlineEdit->setObjectName(QString::fromUtf8("ghostXMLlineEdit"));
        ghostXMLlineEdit->setEnabled(false);

        gridLayout_6->addWidget(ghostXMLlineEdit, 3, 0, 1, 1);

        toolBox->addItem(EnemyProperties, QString::fromUtf8("Enemy Properties"));

        gridLayout_2->addWidget(toolBox, 1, 0, 1, 2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        ConfigrationWindow->setCentralWidget(centralWidget);

        retranslateUi(ConfigrationWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigrationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConfigrationWindow)
    {
        ConfigrationWindow->setWindowTitle(QApplication::translate("ConfigrationWindow", "ConfigrationWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfigrationWindow", "CompassGames, All rights reserved 2012", 0, QApplication::UnicodeUTF8));
        refresh->setText(QApplication::translate("ConfigrationWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        slowAnimationPushButton->setText(QApplication::translate("ConfigrationWindow", "Slow Motion", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ConfigrationWindow", "XML: ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ConfigrationWindow", "Name: ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ConfigrationWindow", "Background :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ConfigrationWindow", "Map Info", 0, QApplication::UnicodeUTF8));
        loadXMLpushButton->setText(QApplication::translate("ConfigrationWindow", "Load", 0, QApplication::UnicodeUTF8));
        MapCheckPointcheckBox->setText(QApplication::translate("ConfigrationWindow", "Check Point", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(MapInfo), QApplication::translate("ConfigrationWindow", "Map Info", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("ConfigrationWindow", "Name: ", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("ConfigrationWindow", "Z: ", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("ConfigrationWindow", "SVG: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConfigrationWindow", "Type :", 0, QApplication::UnicodeUTF8));
        AddElementpushButton->setText(QApplication::translate("ConfigrationWindow", "Add Element", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("ConfigrationWindow", "Element properties", 0, QApplication::UnicodeUTF8));
        ElementXDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "X/DD", 0, QApplication::UnicodeUTF8));
        ElementYDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "Y/DD", 0, QApplication::UnicodeUTF8));
        ElementRotationDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "R/DD", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ConfigrationWindow", "Go to :", 0, QApplication::UnicodeUTF8));
        DeleteElementPushButton->setText(QApplication::translate("ConfigrationWindow", "DeleteMe", 0, QApplication::UnicodeUTF8));
        ElementFlippedcheckBox->setText(QApplication::translate("ConfigrationWindow", "Flipped", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ConfigrationWindow", "Reward type:", 0, QApplication::UnicodeUTF8));
        ElementRewardTypeComboBox->clear();
        ElementRewardTypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("ConfigrationWindow", "money", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigrationWindow", "item", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigrationWindow", "weapon", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ConfigrationWindow", "key", 0, QApplication::UnicodeUTF8)
        );
        label_8->setText(QApplication::translate("ConfigrationWindow", "Quest Key (.svg):", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ConfigrationWindow", "Scale:", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Elementproperties), QApplication::translate("ConfigrationWindow", "Element properties", 0, QApplication::UnicodeUTF8));
        EnemycheckBox->setText(QApplication::translate("ConfigrationWindow", "Enable random battle", 0, QApplication::UnicodeUTF8));
        Enemylabel->setText(QApplication::translate("ConfigrationWindow", "Enemy properties", 0, QApplication::UnicodeUTF8));
        EnemyLevellabel->setText(QApplication::translate("ConfigrationWindow", "Enemy level:", 0, QApplication::UnicodeUTF8));
        EnemyXMLlabel->setText(QApplication::translate("ConfigrationWindow", "Enemy XML:", 0, QApplication::UnicodeUTF8));
        EnemyAddpushButton->setText(QApplication::translate("ConfigrationWindow", "Add enemy", 0, QApplication::UnicodeUTF8));
        EnemyDeletepushButton->setText(QApplication::translate("ConfigrationWindow", "Delete enemy", 0, QApplication::UnicodeUTF8));
        ghostLabel->setText(QApplication::translate("ConfigrationWindow", "ghost xml :", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(EnemyProperties), QApplication::translate("ConfigrationWindow", "Enemy Properties", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigrationWindow: public Ui_ConfigrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGRATIONWINDOW_H
