/********************************************************************************
** Form generated from reading UI file 'configrationwindow.ui'
**
** Created: Sun Sep 9 15:36:36 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGRATIONWINDOW_H
#define UI_CONFIGRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QFrame>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QScrollArea>
#include <QSpacerItem>
#include <QToolBox>
#include <QTreeWidget>
#include <QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigrationWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QToolBox *toolBox;
    QWidget *CharacterInfo;
    QGridLayout *gridLayout_4;
    QLabel *label_11;
    QLabel *label_3;
    QLineEdit *XMLNamelineEdit;
    QLabel *label_17;
    QLineEdit *SuperXMLlineEdit;
    QLabel *label_4;
    QLineEdit *NamelineEdit;
    QLabel *label_5;
    QLineEdit *TypelineEdit;
    QLabel *label_6;
    QLineEdit *SpeedlineEdit;
    QLabel *label_7;
    QLineEdit *yOffsetlineEdit;
    QLabel *label_8;
    QLineEdit *Weapon1lineEdit;
    QLabel *label_9;
    QLineEdit *HealthlineEdit;
    QLabel *label_10;
    QLineEdit *LevellineEdit;
    QSpacerItem *verticalSpacer_2;
    QWidget *Joints;
    QGridLayout *gridLayout_5;
    QTreeWidget *JointtreeWidget;
    QPushButton *AddJointpushButton;
    QPushButton *DeleteJointpushButton;
    QPushButton *JointResetAllOpacitypushButton;
    QLabel *label_23;
    QGridLayout *GraphicsgridLayout;
    QToolBox *toolBox_3;
    QWidget *JointProperties;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_12;
    QLabel *label_13;
    QCheckBox *JointW1checkBox;
    QLabel *label_14;
    QLineEdit *JointNamelineEdit;
    QLabel *label_15;
    QLineEdit *JointSVGlineEdit;
    QLabel *label_19;
    QLineEdit *JointXAnchlineEdit;
    QLabel *label_18;
    QLineEdit *JointYAnchlineEdit;
    QLabel *label_20;
    QLineEdit *JointZlineEdit;
    QPushButton *JointYDragDroppushButton;
    QLineEdit *JointYlineEdit;
    QPushButton *JointRotationDragDroppushButton;
    QLineEdit *JointRotationlineEdit;
    QSpacerItem *verticalSpacer_3;
    QWidget *AnimationSteps;
    QGridLayout *gridLayout_10;
    QLabel *label_21;
    QTreeWidget *AnimationtreeWidget;
    QToolBox *toolBox_2;
    QWidget *MainControls;
    QGridLayout *gridLayout_8;
    QLabel *label_2;
    QLineEdit *AnimationTotalTimelineEdit;
    QPushButton *AddAnimationPointpushButton;
    QPushButton *RemoveAnimationPointpushButton;
    QPushButton *AnimationSetValuespushButton;
    QLabel *label_12;
    QPushButton *ChangeAnimationPointpushButton;
    QLineEdit *AnimationChangeTimelineEdit;
    QLabel *label_16;
    QSpacerItem *verticalSpacer_4;
    QWidget *JointPositionControls;
    QGridLayout *gridLayout_9;
    QCheckBox *AnimationFireW1checkBox;
    QLabel *label_22;
    QLineEdit *AnimationTimelineEdit;
    QPushButton *AnimationYDragDroppushButton;
    QSpacerItem *verticalSpacer;
    QLineEdit *AnimationYlineEdit;
    QPushButton *AnimationRDragDroppushButton;
    QLineEdit *AnimationRotationlineEdit;
    QGridLayout *gridLayout_2;
    QPushButton *loadXMLpushButton;
    QPushButton *refresh;
    QGridLayout *gridLayout_7;
    QComboBox *AnimationcomboBox;
    QPushButton *runAnimationButton;
    QPushButton *stopAnimationButton;
    QPushButton *CharSuperpushButton;
    QPushButton *WeaponSuperpushButton;
    QPushButton *slowAnimationPushButton;
    QLabel *label;
    QGridLayout *gridLayout_13;
    QDoubleSpinBox *KeyFramedoubleSpinBox;
    QFrame *frame;
    QGridLayout *gridLayout_6;
    QLabel *label_24;
    QLabel *key_frame_label;
    QListWidget *keyFrameslistWidget;

    void setupUi(QMainWindow *ConfigrationWindow)
    {
        if (ConfigrationWindow->objectName().isEmpty())
            ConfigrationWindow->setObjectName(QString::fromUtf8("ConfigrationWindow"));
        ConfigrationWindow->setWindowModality(Qt::WindowModal);
        ConfigrationWindow->resize(1100, 797);
        ConfigrationWindow->setStyleSheet(QString::fromUtf8(""));
        ConfigrationWindow->setInputMethodHints(Qt::ImhLowercaseOnly);
        centralWidget = new QWidget(ConfigrationWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("color: rgb(218, 218, 218);\n"
"background-color: rgb(52, 52, 52);\n"
"alternate-background-color: rgb(83, 83, 83);\n"
"border-color: rgb(113, 113, 113);\n"
"selection-background-color: rgb(131, 131, 131);\n"
"selection-color: rgb(222, 222, 222);"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMaximumSize(QSize(16777215, 16777215));
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
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1090, 787));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8(" QTreeView {\n"
"     alternate-background-color: rgb(86, 86, 86);\n"
"     background: rgb(65, 65, 65);\n"
" }"));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setSpacing(5);
        gridLayout_3->setContentsMargins(2, 2, 2, 2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        toolBox = new QToolBox(scrollAreaWidgetContents);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setMinimumSize(QSize(0, 0));
        toolBox->setMaximumSize(QSize(16777215, 16777215));
        toolBox->setStyleSheet(QString::fromUtf8(""));
        toolBox->setFrameShape(QFrame::WinPanel);
        toolBox->setFrameShadow(QFrame::Sunken);
        CharacterInfo = new QWidget();
        CharacterInfo->setObjectName(QString::fromUtf8("CharacterInfo"));
        CharacterInfo->setGeometry(QRect(0, 0, 394, 449));
        gridLayout_4 = new QGridLayout(CharacterInfo);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_11 = new QLabel(CharacterInfo);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(16777215, 20));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_11, 0, 0, 1, 1);

        label_3 = new QLabel(CharacterInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);

        XMLNamelineEdit = new QLineEdit(CharacterInfo);
        XMLNamelineEdit->setObjectName(QString::fromUtf8("XMLNamelineEdit"));
        XMLNamelineEdit->setMinimumSize(QSize(100, 0));

        gridLayout_4->addWidget(XMLNamelineEdit, 2, 0, 1, 1);

        label_17 = new QLabel(CharacterInfo);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_4->addWidget(label_17, 3, 0, 1, 1);

        SuperXMLlineEdit = new QLineEdit(CharacterInfo);
        SuperXMLlineEdit->setObjectName(QString::fromUtf8("SuperXMLlineEdit"));

        gridLayout_4->addWidget(SuperXMLlineEdit, 4, 0, 1, 1);

        label_4 = new QLabel(CharacterInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 5, 0, 1, 1);

        NamelineEdit = new QLineEdit(CharacterInfo);
        NamelineEdit->setObjectName(QString::fromUtf8("NamelineEdit"));

        gridLayout_4->addWidget(NamelineEdit, 6, 0, 1, 1);

        label_5 = new QLabel(CharacterInfo);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 7, 0, 1, 1);

        TypelineEdit = new QLineEdit(CharacterInfo);
        TypelineEdit->setObjectName(QString::fromUtf8("TypelineEdit"));
        TypelineEdit->setMinimumSize(QSize(100, 0));

        gridLayout_4->addWidget(TypelineEdit, 8, 0, 1, 1);

        label_6 = new QLabel(CharacterInfo);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_4->addWidget(label_6, 9, 0, 1, 1);

        SpeedlineEdit = new QLineEdit(CharacterInfo);
        SpeedlineEdit->setObjectName(QString::fromUtf8("SpeedlineEdit"));

        gridLayout_4->addWidget(SpeedlineEdit, 10, 0, 1, 1);

        label_7 = new QLabel(CharacterInfo);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 11, 0, 1, 1);

        yOffsetlineEdit = new QLineEdit(CharacterInfo);
        yOffsetlineEdit->setObjectName(QString::fromUtf8("yOffsetlineEdit"));

        gridLayout_4->addWidget(yOffsetlineEdit, 12, 0, 1, 1);

        label_8 = new QLabel(CharacterInfo);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_4->addWidget(label_8, 13, 0, 1, 1);

        Weapon1lineEdit = new QLineEdit(CharacterInfo);
        Weapon1lineEdit->setObjectName(QString::fromUtf8("Weapon1lineEdit"));

        gridLayout_4->addWidget(Weapon1lineEdit, 14, 0, 1, 1);

        label_9 = new QLabel(CharacterInfo);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 15, 0, 1, 1);

        HealthlineEdit = new QLineEdit(CharacterInfo);
        HealthlineEdit->setObjectName(QString::fromUtf8("HealthlineEdit"));

        gridLayout_4->addWidget(HealthlineEdit, 16, 0, 1, 1);

        label_10 = new QLabel(CharacterInfo);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 17, 0, 1, 1);

        LevellineEdit = new QLineEdit(CharacterInfo);
        LevellineEdit->setObjectName(QString::fromUtf8("LevellineEdit"));

        gridLayout_4->addWidget(LevellineEdit, 18, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 19, 0, 1, 1);

        toolBox->addItem(CharacterInfo, QString::fromUtf8("Character Info"));
        Joints = new QWidget();
        Joints->setObjectName(QString::fromUtf8("Joints"));
        Joints->setGeometry(QRect(0, 0, 411, 335));
        gridLayout_5 = new QGridLayout(Joints);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        JointtreeWidget = new QTreeWidget(Joints);
        JointtreeWidget->setObjectName(QString::fromUtf8("JointtreeWidget"));
        JointtreeWidget->setFrameShape(QFrame::NoFrame);
        JointtreeWidget->setFrameShadow(QFrame::Plain);
        JointtreeWidget->setTabKeyNavigation(false);
        JointtreeWidget->setAlternatingRowColors(true);
        JointtreeWidget->setRootIsDecorated(true);
        JointtreeWidget->setAnimated(true);
        JointtreeWidget->setExpandsOnDoubleClick(false);

        gridLayout_5->addWidget(JointtreeWidget, 1, 0, 1, 1);

        AddJointpushButton = new QPushButton(Joints);
        AddJointpushButton->setObjectName(QString::fromUtf8("AddJointpushButton"));

        gridLayout_5->addWidget(AddJointpushButton, 4, 0, 1, 1);

        DeleteJointpushButton = new QPushButton(Joints);
        DeleteJointpushButton->setObjectName(QString::fromUtf8("DeleteJointpushButton"));

        gridLayout_5->addWidget(DeleteJointpushButton, 5, 0, 1, 1);

        JointResetAllOpacitypushButton = new QPushButton(Joints);
        JointResetAllOpacitypushButton->setObjectName(QString::fromUtf8("JointResetAllOpacitypushButton"));

        gridLayout_5->addWidget(JointResetAllOpacitypushButton, 3, 0, 1, 1);

        label_23 = new QLabel(Joints);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        QFont font1;
        font1.setPointSize(7);
        label_23->setFont(font1);

        gridLayout_5->addWidget(label_23, 2, 0, 1, 1);

        toolBox->addItem(Joints, QString::fromUtf8("Joints"));

        gridLayout_3->addWidget(toolBox, 1, 0, 4, 1);

        GraphicsgridLayout = new QGridLayout();
        GraphicsgridLayout->setSpacing(4);
        GraphicsgridLayout->setContentsMargins(4, 4, 4, 4);
        GraphicsgridLayout->setObjectName(QString::fromUtf8("GraphicsgridLayout"));

        gridLayout_3->addLayout(GraphicsgridLayout, 1, 1, 2, 1);

        toolBox_3 = new QToolBox(scrollAreaWidgetContents);
        toolBox_3->setObjectName(QString::fromUtf8("toolBox_3"));
        toolBox_3->setFrameShape(QFrame::Panel);
        toolBox_3->setFrameShadow(QFrame::Sunken);
        JointProperties = new QWidget();
        JointProperties->setObjectName(QString::fromUtf8("JointProperties"));
        JointProperties->setGeometry(QRect(0, 0, 396, 401));
        gridLayout_11 = new QGridLayout(JointProperties);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_13 = new QLabel(JointProperties);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(16777215, 20));
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_12->addWidget(label_13, 0, 0, 1, 1);

        JointW1checkBox = new QCheckBox(JointProperties);
        JointW1checkBox->setObjectName(QString::fromUtf8("JointW1checkBox"));

        gridLayout_12->addWidget(JointW1checkBox, 1, 0, 1, 1);

        label_14 = new QLabel(JointProperties);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_12->addWidget(label_14, 2, 0, 1, 1);

        JointNamelineEdit = new QLineEdit(JointProperties);
        JointNamelineEdit->setObjectName(QString::fromUtf8("JointNamelineEdit"));

        gridLayout_12->addWidget(JointNamelineEdit, 3, 0, 1, 1);

        label_15 = new QLabel(JointProperties);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_12->addWidget(label_15, 4, 0, 1, 1);

        JointSVGlineEdit = new QLineEdit(JointProperties);
        JointSVGlineEdit->setObjectName(QString::fromUtf8("JointSVGlineEdit"));

        gridLayout_12->addWidget(JointSVGlineEdit, 5, 0, 1, 1);

        label_19 = new QLabel(JointProperties);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_12->addWidget(label_19, 6, 0, 1, 1);

        JointXAnchlineEdit = new QLineEdit(JointProperties);
        JointXAnchlineEdit->setObjectName(QString::fromUtf8("JointXAnchlineEdit"));

        gridLayout_12->addWidget(JointXAnchlineEdit, 7, 0, 1, 1);

        label_18 = new QLabel(JointProperties);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_12->addWidget(label_18, 8, 0, 1, 1);

        JointYAnchlineEdit = new QLineEdit(JointProperties);
        JointYAnchlineEdit->setObjectName(QString::fromUtf8("JointYAnchlineEdit"));

        gridLayout_12->addWidget(JointYAnchlineEdit, 9, 0, 1, 1);

        label_20 = new QLabel(JointProperties);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_12->addWidget(label_20, 10, 0, 1, 1);

        JointZlineEdit = new QLineEdit(JointProperties);
        JointZlineEdit->setObjectName(QString::fromUtf8("JointZlineEdit"));

        gridLayout_12->addWidget(JointZlineEdit, 11, 0, 1, 1);

        JointYDragDroppushButton = new QPushButton(JointProperties);
        JointYDragDroppushButton->setObjectName(QString::fromUtf8("JointYDragDroppushButton"));
        JointYDragDroppushButton->setMaximumSize(QSize(16000000, 16777215));

        gridLayout_12->addWidget(JointYDragDroppushButton, 12, 0, 1, 1);

        JointYlineEdit = new QLineEdit(JointProperties);
        JointYlineEdit->setObjectName(QString::fromUtf8("JointYlineEdit"));

        gridLayout_12->addWidget(JointYlineEdit, 13, 0, 1, 1);

        JointRotationDragDroppushButton = new QPushButton(JointProperties);
        JointRotationDragDroppushButton->setObjectName(QString::fromUtf8("JointRotationDragDroppushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(JointRotationDragDroppushButton->sizePolicy().hasHeightForWidth());
        JointRotationDragDroppushButton->setSizePolicy(sizePolicy);
        JointRotationDragDroppushButton->setMaximumSize(QSize(16000000, 16777215));

        gridLayout_12->addWidget(JointRotationDragDroppushButton, 14, 0, 1, 1);

        JointRotationlineEdit = new QLineEdit(JointProperties);
        JointRotationlineEdit->setObjectName(QString::fromUtf8("JointRotationlineEdit"));

        gridLayout_12->addWidget(JointRotationlineEdit, 15, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_3, 16, 0, 1, 1);


        gridLayout_11->addLayout(gridLayout_12, 0, 0, 1, 1);

        toolBox_3->addItem(JointProperties, QString::fromUtf8("Joint Properties"));
        AnimationSteps = new QWidget();
        AnimationSteps->setObjectName(QString::fromUtf8("AnimationSteps"));
        AnimationSteps->setGeometry(QRect(0, 0, 396, 364));
        gridLayout_10 = new QGridLayout(AnimationSteps);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_21 = new QLabel(AnimationSteps);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMaximumSize(QSize(16777215, 20));
        label_21->setFont(font);
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_10->addWidget(label_21, 0, 0, 1, 1);

        AnimationtreeWidget = new QTreeWidget(AnimationSteps);
        AnimationtreeWidget->setObjectName(QString::fromUtf8("AnimationtreeWidget"));
        AnimationtreeWidget->setMinimumSize(QSize(0, 200));
        AnimationtreeWidget->setFrameShape(QFrame::NoFrame);
        AnimationtreeWidget->setFrameShadow(QFrame::Plain);
        AnimationtreeWidget->setAlternatingRowColors(true);
        AnimationtreeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        AnimationtreeWidget->setRootIsDecorated(true);
        AnimationtreeWidget->setAnimated(true);
        AnimationtreeWidget->setWordWrap(false);
        AnimationtreeWidget->setHeaderHidden(false);
        AnimationtreeWidget->header()->setDefaultSectionSize(40);
        AnimationtreeWidget->header()->setHighlightSections(false);
        AnimationtreeWidget->header()->setStretchLastSection(true);

        gridLayout_10->addWidget(AnimationtreeWidget, 1, 0, 1, 1);

        toolBox_2 = new QToolBox(AnimationSteps);
        toolBox_2->setObjectName(QString::fromUtf8("toolBox_2"));
        MainControls = new QWidget();
        MainControls->setObjectName(QString::fromUtf8("MainControls"));
        MainControls->setGeometry(QRect(0, 0, 141, 241));
        gridLayout_8 = new QGridLayout(MainControls);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_2 = new QLabel(MainControls);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);

        gridLayout_8->addWidget(label_2, 0, 0, 1, 1);

        AnimationTotalTimelineEdit = new QLineEdit(MainControls);
        AnimationTotalTimelineEdit->setObjectName(QString::fromUtf8("AnimationTotalTimelineEdit"));
        AnimationTotalTimelineEdit->setEnabled(false);

        gridLayout_8->addWidget(AnimationTotalTimelineEdit, 1, 0, 1, 1);

        AddAnimationPointpushButton = new QPushButton(MainControls);
        AddAnimationPointpushButton->setObjectName(QString::fromUtf8("AddAnimationPointpushButton"));
        AddAnimationPointpushButton->setEnabled(false);
        AddAnimationPointpushButton->setMinimumSize(QSize(0, 23));

        gridLayout_8->addWidget(AddAnimationPointpushButton, 2, 0, 1, 1);

        RemoveAnimationPointpushButton = new QPushButton(MainControls);
        RemoveAnimationPointpushButton->setObjectName(QString::fromUtf8("RemoveAnimationPointpushButton"));
        RemoveAnimationPointpushButton->setEnabled(false);
        RemoveAnimationPointpushButton->setMinimumSize(QSize(0, 23));

        gridLayout_8->addWidget(RemoveAnimationPointpushButton, 3, 0, 1, 1);

        AnimationSetValuespushButton = new QPushButton(MainControls);
        AnimationSetValuespushButton->setObjectName(QString::fromUtf8("AnimationSetValuespushButton"));
        AnimationSetValuespushButton->setMinimumSize(QSize(0, 23));

        gridLayout_8->addWidget(AnimationSetValuespushButton, 4, 0, 1, 1);

        label_12 = new QLabel(MainControls);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setEnabled(false);

        gridLayout_8->addWidget(label_12, 5, 0, 1, 1);

        ChangeAnimationPointpushButton = new QPushButton(MainControls);
        ChangeAnimationPointpushButton->setObjectName(QString::fromUtf8("ChangeAnimationPointpushButton"));
        ChangeAnimationPointpushButton->setEnabled(false);
        ChangeAnimationPointpushButton->setMinimumSize(QSize(0, 23));

        gridLayout_8->addWidget(ChangeAnimationPointpushButton, 8, 0, 1, 1);

        AnimationChangeTimelineEdit = new QLineEdit(MainControls);
        AnimationChangeTimelineEdit->setObjectName(QString::fromUtf8("AnimationChangeTimelineEdit"));
        AnimationChangeTimelineEdit->setEnabled(false);

        gridLayout_8->addWidget(AnimationChangeTimelineEdit, 6, 0, 1, 1);

        label_16 = new QLabel(MainControls);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setEnabled(false);
        label_16->setFont(font1);

        gridLayout_8->addWidget(label_16, 7, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_4, 9, 0, 1, 1);

        toolBox_2->addItem(MainControls, QString::fromUtf8("MainControls"));
        JointPositionControls = new QWidget();
        JointPositionControls->setObjectName(QString::fromUtf8("JointPositionControls"));
        JointPositionControls->setGeometry(QRect(0, 0, 361, 193));
        JointPositionControls->setStyleSheet(QString::fromUtf8(""));
        gridLayout_9 = new QGridLayout(JointPositionControls);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        AnimationFireW1checkBox = new QCheckBox(JointPositionControls);
        AnimationFireW1checkBox->setObjectName(QString::fromUtf8("AnimationFireW1checkBox"));

        gridLayout_9->addWidget(AnimationFireW1checkBox, 0, 0, 1, 1);

        label_22 = new QLabel(JointPositionControls);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setEnabled(false);

        gridLayout_9->addWidget(label_22, 1, 0, 1, 1);

        AnimationTimelineEdit = new QLineEdit(JointPositionControls);
        AnimationTimelineEdit->setObjectName(QString::fromUtf8("AnimationTimelineEdit"));
        AnimationTimelineEdit->setEnabled(false);

        gridLayout_9->addWidget(AnimationTimelineEdit, 2, 0, 1, 1);

        AnimationYDragDroppushButton = new QPushButton(JointPositionControls);
        AnimationYDragDroppushButton->setObjectName(QString::fromUtf8("AnimationYDragDroppushButton"));
        AnimationYDragDroppushButton->setEnabled(false);
        AnimationYDragDroppushButton->setMinimumSize(QSize(0, 23));
        AnimationYDragDroppushButton->setStyleSheet(QString::fromUtf8(""));

        gridLayout_9->addWidget(AnimationYDragDroppushButton, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout_9->addItem(verticalSpacer, 7, 0, 1, 1);

        AnimationYlineEdit = new QLineEdit(JointPositionControls);
        AnimationYlineEdit->setObjectName(QString::fromUtf8("AnimationYlineEdit"));
        AnimationYlineEdit->setEnabled(false);

        gridLayout_9->addWidget(AnimationYlineEdit, 4, 0, 1, 1);

        AnimationRDragDroppushButton = new QPushButton(JointPositionControls);
        AnimationRDragDroppushButton->setObjectName(QString::fromUtf8("AnimationRDragDroppushButton"));
        AnimationRDragDroppushButton->setEnabled(false);
        AnimationRDragDroppushButton->setMinimumSize(QSize(0, 23));

        gridLayout_9->addWidget(AnimationRDragDroppushButton, 5, 0, 1, 1);

        AnimationRotationlineEdit = new QLineEdit(JointPositionControls);
        AnimationRotationlineEdit->setObjectName(QString::fromUtf8("AnimationRotationlineEdit"));
        AnimationRotationlineEdit->setEnabled(false);

        gridLayout_9->addWidget(AnimationRotationlineEdit, 6, 0, 1, 1);

        toolBox_2->addItem(JointPositionControls, QString::fromUtf8("Joint Position Controls"));

        gridLayout_10->addWidget(toolBox_2, 2, 0, 1, 1);

        toolBox_3->addItem(AnimationSteps, QString::fromUtf8("Animation Steps"));

        gridLayout_3->addWidget(toolBox_3, 1, 2, 3, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        loadXMLpushButton = new QPushButton(scrollAreaWidgetContents);
        loadXMLpushButton->setObjectName(QString::fromUtf8("loadXMLpushButton"));

        gridLayout_2->addWidget(loadXMLpushButton, 1, 0, 1, 1);

        refresh = new QPushButton(scrollAreaWidgetContents);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setEnabled(true);
        sizePolicy.setHeightForWidth(refresh->sizePolicy().hasHeightForWidth());
        refresh->setSizePolicy(sizePolicy);
        refresh->setMinimumSize(QSize(0, 23));
        refresh->setMaximumSize(QSize(150, 16777215));
        refresh->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(refresh, 1, 1, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(1, 1, 1, 1);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        AnimationcomboBox = new QComboBox(scrollAreaWidgetContents);
        AnimationcomboBox->setObjectName(QString::fromUtf8("AnimationcomboBox"));

        gridLayout_7->addWidget(AnimationcomboBox, 1, 0, 1, 1);

        runAnimationButton = new QPushButton(scrollAreaWidgetContents);
        runAnimationButton->setObjectName(QString::fromUtf8("runAnimationButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(runAnimationButton->sizePolicy().hasHeightForWidth());
        runAnimationButton->setSizePolicy(sizePolicy1);
        runAnimationButton->setMaximumSize(QSize(1000, 16777215));

        gridLayout_7->addWidget(runAnimationButton, 1, 1, 1, 1);

        stopAnimationButton = new QPushButton(scrollAreaWidgetContents);
        stopAnimationButton->setObjectName(QString::fromUtf8("stopAnimationButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stopAnimationButton->sizePolicy().hasHeightForWidth());
        stopAnimationButton->setSizePolicy(sizePolicy2);
        stopAnimationButton->setMaximumSize(QSize(1000, 16777215));

        gridLayout_7->addWidget(stopAnimationButton, 1, 2, 1, 1);

        CharSuperpushButton = new QPushButton(scrollAreaWidgetContents);
        CharSuperpushButton->setObjectName(QString::fromUtf8("CharSuperpushButton"));

        gridLayout_7->addWidget(CharSuperpushButton, 2, 0, 1, 1);

        WeaponSuperpushButton = new QPushButton(scrollAreaWidgetContents);
        WeaponSuperpushButton->setObjectName(QString::fromUtf8("WeaponSuperpushButton"));

        gridLayout_7->addWidget(WeaponSuperpushButton, 2, 1, 1, 1);

        slowAnimationPushButton = new QPushButton(scrollAreaWidgetContents);
        slowAnimationPushButton->setObjectName(QString::fromUtf8("slowAnimationPushButton"));

        gridLayout_7->addWidget(slowAnimationPushButton, 2, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_7, 0, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout_2, 3, 1, 2, 1);

        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setPointSize(9);
        label->setFont(font2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label->setMargin(3);

        gridLayout_3->addWidget(label, 4, 2, 1, 1);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(3, 3, 3, 3);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        KeyFramedoubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        KeyFramedoubleSpinBox->setObjectName(QString::fromUtf8("KeyFramedoubleSpinBox"));
        KeyFramedoubleSpinBox->setMinimumSize(QSize(0, 40));
        KeyFramedoubleSpinBox->setMaximumSize(QSize(50, 30));
        KeyFramedoubleSpinBox->setMinimum(0.01);
        KeyFramedoubleSpinBox->setMaximum(1);
        KeyFramedoubleSpinBox->setSingleStep(0.01);
        KeyFramedoubleSpinBox->setValue(0.05);

        gridLayout_13->addWidget(KeyFramedoubleSpinBox, 0, 0, 1, 1);

        frame = new QFrame(scrollAreaWidgetContents);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMinimumSize(QSize(20, 40));
        frame->setMaximumSize(QSize(16777215, 30));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(2);
        gridLayout_6 = new QGridLayout(frame);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_24 = new QLabel(frame);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_6->addWidget(label_24, 0, 0, 1, 1);

        key_frame_label = new QLabel(frame);
        key_frame_label->setObjectName(QString::fromUtf8("key_frame_label"));
        key_frame_label->setMinimumSize(QSize(40, 0));
        key_frame_label->setMaximumSize(QSize(40, 16777215));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        key_frame_label->setFont(font3);

        gridLayout_6->addWidget(key_frame_label, 0, 1, 1, 1);


        gridLayout_13->addWidget(frame, 0, 1, 1, 1);

        keyFrameslistWidget = new QListWidget(scrollAreaWidgetContents);
        keyFrameslistWidget->setObjectName(QString::fromUtf8("keyFrameslistWidget"));
        keyFrameslistWidget->setMinimumSize(QSize(0, 40));
        keyFrameslistWidget->setMaximumSize(QSize(16777215, 30));
        QFont font4;
        font4.setPointSize(50);
        keyFrameslistWidget->setFont(font4);
        keyFrameslistWidget->setAlternatingRowColors(true);
        keyFrameslistWidget->setFlow(QListView::LeftToRight);

        gridLayout_13->addWidget(keyFrameslistWidget, 0, 2, 1, 1);


        gridLayout_3->addLayout(gridLayout_13, 0, 0, 1, 3);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 1);

        ConfigrationWindow->setCentralWidget(centralWidget);

        retranslateUi(ConfigrationWindow);

        toolBox->setCurrentIndex(1);
        toolBox_3->setCurrentIndex(1);
        toolBox_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ConfigrationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConfigrationWindow)
    {
        ConfigrationWindow->setWindowTitle(QApplication::translate("ConfigrationWindow", "ConfigrationWindow", 0));
        label_11->setText(QApplication::translate("ConfigrationWindow", "Character Info", 0));
        label_3->setText(QApplication::translate("ConfigrationWindow", "XML: ", 0));
        label_17->setText(QApplication::translate("ConfigrationWindow", "Super XML:", 0));
        label_4->setText(QApplication::translate("ConfigrationWindow", "Name: ", 0));
        label_5->setText(QApplication::translate("ConfigrationWindow", "Type: ", 0));
        label_6->setText(QApplication::translate("ConfigrationWindow", "Speed: ", 0));
        SpeedlineEdit->setText(QApplication::translate("ConfigrationWindow", "250", 0));
        label_7->setText(QApplication::translate("ConfigrationWindow", "Y Offset: ", 0));
        yOffsetlineEdit->setText(QApplication::translate("ConfigrationWindow", "80", 0));
        label_8->setText(QApplication::translate("ConfigrationWindow", "W1 XML: ", 0));
        label_9->setText(QApplication::translate("ConfigrationWindow", "Health: ", 0));
        HealthlineEdit->setText(QApplication::translate("ConfigrationWindow", "20", 0));
        label_10->setText(QApplication::translate("ConfigrationWindow", "Level: ", 0));
        LevellineEdit->setText(QApplication::translate("ConfigrationWindow", "1", 0));
        toolBox->setItemText(toolBox->indexOf(CharacterInfo), QApplication::translate("ConfigrationWindow", "Character Info", 0));
        QTreeWidgetItem *___qtreewidgetitem = JointtreeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("ConfigrationWindow", "Joint Name", 0));
        AddJointpushButton->setText(QApplication::translate("ConfigrationWindow", "Add Child", 0));
        DeleteJointpushButton->setText(QApplication::translate("ConfigrationWindow", "DeleteMe", 0));
        JointResetAllOpacitypushButton->setText(QApplication::translate("ConfigrationWindow", "Reset All Opacity", 0));
        label_23->setText(QApplication::translate("ConfigrationWindow", "Note: Double click on any joint to focus only on that one", 0));
        toolBox->setItemText(toolBox->indexOf(Joints), QApplication::translate("ConfigrationWindow", "Joints", 0));
        label_13->setText(QApplication::translate("ConfigrationWindow", "Joint properties", 0));
        JointW1checkBox->setText(QApplication::translate("ConfigrationWindow", "Contains weapon 1", 0));
        label_14->setText(QApplication::translate("ConfigrationWindow", "Name: ", 0));
        label_15->setText(QApplication::translate("ConfigrationWindow", "SVG: ", 0));
        label_19->setText(QApplication::translate("ConfigrationWindow", "X Anchor: ", 0));
        label_18->setText(QApplication::translate("ConfigrationWindow", "Y Anchor:", 0));
        label_20->setText(QApplication::translate("ConfigrationWindow", "Z: ", 0));
        JointYDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "Y/DD", 0));
        JointRotationDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "R/DD", 0));
        toolBox_3->setItemText(toolBox_3->indexOf(JointProperties), QApplication::translate("ConfigrationWindow", "Joint Properties", 0));
        label_21->setText(QApplication::translate("ConfigrationWindow", "Joint Animation", 0));
        QTreeWidgetItem *___qtreewidgetitem1 = AnimationtreeWidget->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("ConfigrationWindow", " Y ", 0));
        ___qtreewidgetitem1->setText(1, QApplication::translate("ConfigrationWindow", " R ", 0));
        ___qtreewidgetitem1->setText(0, QApplication::translate("ConfigrationWindow", "Animation", 0));
        label_2->setText(QApplication::translate("ConfigrationWindow", "Point time:", 0));
        AddAnimationPointpushButton->setText(QApplication::translate("ConfigrationWindow", "Add point", 0));
        RemoveAnimationPointpushButton->setText(QApplication::translate("ConfigrationWindow", "Del Point", 0));
        AnimationSetValuespushButton->setText(QApplication::translate("ConfigrationWindow", "SetValues", 0));
        label_12->setText(QApplication::translate("ConfigrationWindow", "Change to:", 0));
        ChangeAnimationPointpushButton->setText(QApplication::translate("ConfigrationWindow", "Change point", 0));
        label_16->setText(QApplication::translate("ConfigrationWindow", "*Use point time as from point", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(MainControls), QApplication::translate("ConfigrationWindow", "MainControls", 0));
        AnimationFireW1checkBox->setText(QApplication::translate("ConfigrationWindow", "FireW1", 0));
        label_22->setText(QApplication::translate("ConfigrationWindow", "Time: ", 0));
        AnimationYDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "Y/DD", 0));
        AnimationRDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "R/DD", 0));
        toolBox_2->setItemText(toolBox_2->indexOf(JointPositionControls), QApplication::translate("ConfigrationWindow", "Joint Position Controls", 0));
        toolBox_3->setItemText(toolBox_3->indexOf(AnimationSteps), QApplication::translate("ConfigrationWindow", "Animation Steps", 0));
        loadXMLpushButton->setText(QApplication::translate("ConfigrationWindow", "Load", 0));
        refresh->setText(QApplication::translate("ConfigrationWindow", "Refresh", 0));
        runAnimationButton->setText(QApplication::translate("ConfigrationWindow", "Run", 0));
        stopAnimationButton->setText(QApplication::translate("ConfigrationWindow", "Stop", 0));
        CharSuperpushButton->setText(QApplication::translate("ConfigrationWindow", "Char super", 0));
        WeaponSuperpushButton->setText(QApplication::translate("ConfigrationWindow", "Weapon super", 0));
        slowAnimationPushButton->setText(QApplication::translate("ConfigrationWindow", "Slow motion", 0));
        label->setText(QApplication::translate("ConfigrationWindow", "CompassGames, All rights reserved 2012", 0));
        label_24->setText(QApplication::translate("ConfigrationWindow", "Key:", 0));
        key_frame_label->setText(QApplication::translate("ConfigrationWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigrationWindow: public Ui_ConfigrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGRATIONWINDOW_H
