/********************************************************************************
** Form generated from reading UI file 'configrationwindow.ui'
**
** Created: Sat Aug 4 00:35:42 2012
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
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigrationWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
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
    QLabel *label_21;
    QHBoxLayout *horizontalLayout;
    QPushButton *refresh;
    QComboBox *AnimationcomboBox;
    QPushButton *runAnimationButton;
    QPushButton *stopAnimationButton;
    QPushButton *slowAnimationPushButton;
    QTreeWidget *AnimationtreeWidget;
    QLineEdit *NamelineEdit;
    QLabel *label_4;
    QLineEdit *XMLNamelineEdit;
    QPushButton *loadXMLpushButton;
    QLabel *label_11;
    QLabel *label_19;
    QLineEdit *JointXAnchlineEdit;
    QCheckBox *AnimationFireW1checkBox;
    QPushButton *AnimationSetValuespushButton;
    QPushButton *AddAnimationPointpushButton;
    QPushButton *RemoveAnimationPointpushButton;
    QLineEdit *AnimationTotalTimelineEdit;
    QLabel *label_22;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label_2;
    QLineEdit *JointYlineEdit;
    QPushButton *AddJointpushButton;
    QLineEdit *JointRotationlineEdit;
    QTreeWidget *JointtreeWidget;
    QPushButton *JointYDragDroppushButton;
    QPushButton *JointRotationDragDroppushButton;
    QLineEdit *JointZlineEdit;
    QLabel *label_20;
    QLineEdit *JointYAnchlineEdit;
    QLabel *label_18;
    QCheckBox *JointW1checkBox;
    QLabel *label_13;
    QLineEdit *JointSVGlineEdit;
    QLineEdit *JointNamelineEdit;
    QLabel *label_15;
    QLabel *label_14;
    QPushButton *DeleteJointpushButton;
    QLabel *label_12;
    QLineEdit *AnimationChangeTimelineEdit;
    QLabel *label_16;
    QPushButton *ChangeAnimationPointpushButton;
    QLineEdit *AnimationTimelineEdit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *AnimationRDragDroppushButton;
    QPushButton *AnimationYDragDroppushButton;
    QLineEdit *AnimationYlineEdit;
    QLineEdit *AnimationRotationlineEdit;

    void setupUi(QMainWindow *ConfigrationWindow)
    {
        if (ConfigrationWindow->objectName().isEmpty())
            ConfigrationWindow->setObjectName(QString::fromUtf8("ConfigrationWindow"));
        ConfigrationWindow->setWindowModality(Qt::WindowModal);
        ConfigrationWindow->resize(778, 681);
        ConfigrationWindow->setStyleSheet(QString::fromUtf8(""));
        ConfigrationWindow->setInputMethodHints(Qt::ImhLowercaseOnly);
        centralWidget = new QWidget(ConfigrationWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
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

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 778, 664));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 1, 0, 1, 1);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 2, 0, 1, 1);

        TypelineEdit = new QLineEdit(scrollAreaWidgetContents);
        TypelineEdit->setObjectName(QString::fromUtf8("TypelineEdit"));
        TypelineEdit->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(TypelineEdit, 2, 1, 1, 1);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 2, 2, 1, 1);

        SpeedlineEdit = new QLineEdit(scrollAreaWidgetContents);
        SpeedlineEdit->setObjectName(QString::fromUtf8("SpeedlineEdit"));

        gridLayout_3->addWidget(SpeedlineEdit, 2, 3, 1, 1);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 2, 4, 1, 2);

        yOffsetlineEdit = new QLineEdit(scrollAreaWidgetContents);
        yOffsetlineEdit->setObjectName(QString::fromUtf8("yOffsetlineEdit"));

        gridLayout_3->addWidget(yOffsetlineEdit, 2, 6, 1, 1);

        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 3, 0, 1, 1);

        Weapon1lineEdit = new QLineEdit(scrollAreaWidgetContents);
        Weapon1lineEdit->setObjectName(QString::fromUtf8("Weapon1lineEdit"));

        gridLayout_3->addWidget(Weapon1lineEdit, 3, 1, 1, 1);

        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 3, 2, 1, 1);

        HealthlineEdit = new QLineEdit(scrollAreaWidgetContents);
        HealthlineEdit->setObjectName(QString::fromUtf8("HealthlineEdit"));

        gridLayout_3->addWidget(HealthlineEdit, 3, 3, 1, 1);

        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 3, 4, 1, 2);

        LevellineEdit = new QLineEdit(scrollAreaWidgetContents);
        LevellineEdit->setObjectName(QString::fromUtf8("LevellineEdit"));

        gridLayout_3->addWidget(LevellineEdit, 3, 6, 1, 1);

        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_21->setFont(font1);
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_21, 16, 2, 1, 5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setContentsMargins(20, 20, 20, 20);
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

        AnimationcomboBox = new QComboBox(scrollAreaWidgetContents);
        AnimationcomboBox->setObjectName(QString::fromUtf8("AnimationcomboBox"));

        horizontalLayout->addWidget(AnimationcomboBox);

        runAnimationButton = new QPushButton(scrollAreaWidgetContents);
        runAnimationButton->setObjectName(QString::fromUtf8("runAnimationButton"));
        runAnimationButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(runAnimationButton);

        stopAnimationButton = new QPushButton(scrollAreaWidgetContents);
        stopAnimationButton->setObjectName(QString::fromUtf8("stopAnimationButton"));
        stopAnimationButton->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(stopAnimationButton);

        slowAnimationPushButton = new QPushButton(scrollAreaWidgetContents);
        slowAnimationPushButton->setObjectName(QString::fromUtf8("slowAnimationPushButton"));

        horizontalLayout->addWidget(slowAnimationPushButton);


        gridLayout_3->addLayout(horizontalLayout, 27, 2, 1, 5);

        AnimationtreeWidget = new QTreeWidget(scrollAreaWidgetContents);
        AnimationtreeWidget->setObjectName(QString::fromUtf8("AnimationtreeWidget"));
        AnimationtreeWidget->setMinimumSize(QSize(0, 200));
        AnimationtreeWidget->setAlternatingRowColors(true);
        AnimationtreeWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        AnimationtreeWidget->setAnimated(true);
        AnimationtreeWidget->setWordWrap(false);
        AnimationtreeWidget->setHeaderHidden(false);
        AnimationtreeWidget->header()->setDefaultSectionSize(40);
        AnimationtreeWidget->header()->setHighlightSections(false);
        AnimationtreeWidget->header()->setStretchLastSection(true);

        gridLayout_3->addWidget(AnimationtreeWidget, 15, 0, 13, 2);

        NamelineEdit = new QLineEdit(scrollAreaWidgetContents);
        NamelineEdit->setObjectName(QString::fromUtf8("NamelineEdit"));

        gridLayout_3->addWidget(NamelineEdit, 1, 6, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 1, 4, 1, 2);

        XMLNamelineEdit = new QLineEdit(scrollAreaWidgetContents);
        XMLNamelineEdit->setObjectName(QString::fromUtf8("XMLNamelineEdit"));
        XMLNamelineEdit->setMinimumSize(QSize(100, 0));

        gridLayout_3->addWidget(XMLNamelineEdit, 1, 1, 1, 1);

        loadXMLpushButton = new QPushButton(scrollAreaWidgetContents);
        loadXMLpushButton->setObjectName(QString::fromUtf8("loadXMLpushButton"));

        gridLayout_3->addWidget(loadXMLpushButton, 1, 2, 1, 1);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(16777215, 20));
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_11, 1, 3, 1, 1);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_3->addWidget(label_19, 10, 2, 1, 1);

        JointXAnchlineEdit = new QLineEdit(scrollAreaWidgetContents);
        JointXAnchlineEdit->setObjectName(QString::fromUtf8("JointXAnchlineEdit"));

        gridLayout_3->addWidget(JointXAnchlineEdit, 10, 3, 1, 1);

        AnimationFireW1checkBox = new QCheckBox(scrollAreaWidgetContents);
        AnimationFireW1checkBox->setObjectName(QString::fromUtf8("AnimationFireW1checkBox"));

        gridLayout_3->addWidget(AnimationFireW1checkBox, 23, 2, 2, 1);

        AnimationSetValuespushButton = new QPushButton(scrollAreaWidgetContents);
        AnimationSetValuespushButton->setObjectName(QString::fromUtf8("AnimationSetValuespushButton"));

        gridLayout_3->addWidget(AnimationSetValuespushButton, 23, 3, 2, 1);

        AddAnimationPointpushButton = new QPushButton(scrollAreaWidgetContents);
        AddAnimationPointpushButton->setObjectName(QString::fromUtf8("AddAnimationPointpushButton"));
        AddAnimationPointpushButton->setEnabled(false);

        gridLayout_3->addWidget(AddAnimationPointpushButton, 19, 4, 1, 2);

        RemoveAnimationPointpushButton = new QPushButton(scrollAreaWidgetContents);
        RemoveAnimationPointpushButton->setObjectName(QString::fromUtf8("RemoveAnimationPointpushButton"));
        RemoveAnimationPointpushButton->setEnabled(false);

        gridLayout_3->addWidget(RemoveAnimationPointpushButton, 19, 6, 1, 1);

        AnimationTotalTimelineEdit = new QLineEdit(scrollAreaWidgetContents);
        AnimationTotalTimelineEdit->setObjectName(QString::fromUtf8("AnimationTotalTimelineEdit"));
        AnimationTotalTimelineEdit->setEnabled(false);

        gridLayout_3->addWidget(AnimationTotalTimelineEdit, 19, 3, 1, 1);

        label_22 = new QLabel(scrollAreaWidgetContents);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_3->addWidget(label_22, 21, 2, 2, 1);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(0, 2));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 6, 0, 1, 7);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(0, 2));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 14, 0, 1, 7);

        line_3 = new QFrame(scrollAreaWidgetContents);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMinimumSize(QSize(0, 2));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_3, 26, 2, 1, 5);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);

        gridLayout_3->addWidget(label_2, 19, 2, 1, 1);

        JointYlineEdit = new QLineEdit(scrollAreaWidgetContents);
        JointYlineEdit->setObjectName(QString::fromUtf8("JointYlineEdit"));

        gridLayout_3->addWidget(JointYlineEdit, 10, 6, 1, 1);

        AddJointpushButton = new QPushButton(scrollAreaWidgetContents);
        AddJointpushButton->setObjectName(QString::fromUtf8("AddJointpushButton"));

        gridLayout_3->addWidget(AddJointpushButton, 13, 2, 1, 2);

        JointRotationlineEdit = new QLineEdit(scrollAreaWidgetContents);
        JointRotationlineEdit->setObjectName(QString::fromUtf8("JointRotationlineEdit"));

        gridLayout_3->addWidget(JointRotationlineEdit, 11, 6, 2, 1);

        JointtreeWidget = new QTreeWidget(scrollAreaWidgetContents);
        JointtreeWidget->setObjectName(QString::fromUtf8("JointtreeWidget"));
        JointtreeWidget->setTabKeyNavigation(false);
        JointtreeWidget->setAlternatingRowColors(true);

        gridLayout_3->addWidget(JointtreeWidget, 7, 0, 7, 2);

        JointYDragDroppushButton = new QPushButton(scrollAreaWidgetContents);
        JointYDragDroppushButton->setObjectName(QString::fromUtf8("JointYDragDroppushButton"));
        JointYDragDroppushButton->setMaximumSize(QSize(16000000, 16777215));

        gridLayout_3->addWidget(JointYDragDroppushButton, 10, 4, 1, 2);

        JointRotationDragDroppushButton = new QPushButton(scrollAreaWidgetContents);
        JointRotationDragDroppushButton->setObjectName(QString::fromUtf8("JointRotationDragDroppushButton"));
        sizePolicy.setHeightForWidth(JointRotationDragDroppushButton->sizePolicy().hasHeightForWidth());
        JointRotationDragDroppushButton->setSizePolicy(sizePolicy);
        JointRotationDragDroppushButton->setMaximumSize(QSize(16000000, 16777215));

        gridLayout_3->addWidget(JointRotationDragDroppushButton, 11, 4, 2, 2);

        JointZlineEdit = new QLineEdit(scrollAreaWidgetContents);
        JointZlineEdit->setObjectName(QString::fromUtf8("JointZlineEdit"));

        gridLayout_3->addWidget(JointZlineEdit, 9, 6, 1, 1);

        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_3->addWidget(label_20, 9, 4, 1, 2);

        JointYAnchlineEdit = new QLineEdit(scrollAreaWidgetContents);
        JointYAnchlineEdit->setObjectName(QString::fromUtf8("JointYAnchlineEdit"));

        gridLayout_3->addWidget(JointYAnchlineEdit, 9, 3, 1, 1);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_3->addWidget(label_18, 9, 2, 1, 1);

        JointW1checkBox = new QCheckBox(scrollAreaWidgetContents);
        JointW1checkBox->setObjectName(QString::fromUtf8("JointW1checkBox"));

        gridLayout_3->addWidget(JointW1checkBox, 8, 4, 1, 3);

        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(16777215, 20));
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_13, 7, 2, 1, 5);

        JointSVGlineEdit = new QLineEdit(scrollAreaWidgetContents);
        JointSVGlineEdit->setObjectName(QString::fromUtf8("JointSVGlineEdit"));

        gridLayout_3->addWidget(JointSVGlineEdit, 11, 3, 2, 1);

        JointNamelineEdit = new QLineEdit(scrollAreaWidgetContents);
        JointNamelineEdit->setObjectName(QString::fromUtf8("JointNamelineEdit"));

        gridLayout_3->addWidget(JointNamelineEdit, 8, 3, 1, 1);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 11, 2, 2, 1);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_3->addWidget(label_14, 8, 2, 1, 1);

        DeleteJointpushButton = new QPushButton(scrollAreaWidgetContents);
        DeleteJointpushButton->setObjectName(QString::fromUtf8("DeleteJointpushButton"));

        gridLayout_3->addWidget(DeleteJointpushButton, 13, 4, 1, 3);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setEnabled(false);

        gridLayout_3->addWidget(label_12, 20, 2, 1, 1);

        AnimationChangeTimelineEdit = new QLineEdit(scrollAreaWidgetContents);
        AnimationChangeTimelineEdit->setObjectName(QString::fromUtf8("AnimationChangeTimelineEdit"));
        AnimationChangeTimelineEdit->setEnabled(false);

        gridLayout_3->addWidget(AnimationChangeTimelineEdit, 20, 3, 1, 1);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setEnabled(false);
        QFont font2;
        font2.setPointSize(7);
        label_16->setFont(font2);

        gridLayout_3->addWidget(label_16, 20, 4, 1, 1);

        ChangeAnimationPointpushButton = new QPushButton(scrollAreaWidgetContents);
        ChangeAnimationPointpushButton->setObjectName(QString::fromUtf8("ChangeAnimationPointpushButton"));
        ChangeAnimationPointpushButton->setEnabled(false);

        gridLayout_3->addWidget(ChangeAnimationPointpushButton, 20, 6, 1, 1);

        AnimationTimelineEdit = new QLineEdit(scrollAreaWidgetContents);
        AnimationTimelineEdit->setObjectName(QString::fromUtf8("AnimationTimelineEdit"));

        gridLayout_3->addWidget(AnimationTimelineEdit, 21, 3, 2, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 17, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 15, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 25, 2, 1, 1);

        AnimationRDragDroppushButton = new QPushButton(scrollAreaWidgetContents);
        AnimationRDragDroppushButton->setObjectName(QString::fromUtf8("AnimationRDragDroppushButton"));

        gridLayout_3->addWidget(AnimationRDragDroppushButton, 23, 4, 2, 2);

        AnimationYDragDroppushButton = new QPushButton(scrollAreaWidgetContents);
        AnimationYDragDroppushButton->setObjectName(QString::fromUtf8("AnimationYDragDroppushButton"));

        gridLayout_3->addWidget(AnimationYDragDroppushButton, 21, 4, 2, 2);

        AnimationYlineEdit = new QLineEdit(scrollAreaWidgetContents);
        AnimationYlineEdit->setObjectName(QString::fromUtf8("AnimationYlineEdit"));

        gridLayout_3->addWidget(AnimationYlineEdit, 21, 6, 2, 1);

        AnimationRotationlineEdit = new QLineEdit(scrollAreaWidgetContents);
        AnimationRotationlineEdit->setObjectName(QString::fromUtf8("AnimationRotationlineEdit"));

        gridLayout_3->addWidget(AnimationRotationlineEdit, 23, 6, 2, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        ConfigrationWindow->setCentralWidget(centralWidget);

        retranslateUi(ConfigrationWindow);

        QMetaObject::connectSlotsByName(ConfigrationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConfigrationWindow)
    {
        ConfigrationWindow->setWindowTitle(QApplication::translate("ConfigrationWindow", "ConfigrationWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfigrationWindow", "CompassGames, All rights reserved 2012", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ConfigrationWindow", "XML: ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ConfigrationWindow", "Type: ", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ConfigrationWindow", "Speed: ", 0, QApplication::UnicodeUTF8));
        SpeedlineEdit->setText(QApplication::translate("ConfigrationWindow", "250", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ConfigrationWindow", "Y Offset: ", 0, QApplication::UnicodeUTF8));
        yOffsetlineEdit->setText(QApplication::translate("ConfigrationWindow", "80", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ConfigrationWindow", "W1 XML: ", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ConfigrationWindow", "Health: ", 0, QApplication::UnicodeUTF8));
        HealthlineEdit->setText(QApplication::translate("ConfigrationWindow", "20", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ConfigrationWindow", "Level: ", 0, QApplication::UnicodeUTF8));
        LevellineEdit->setText(QApplication::translate("ConfigrationWindow", "1", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("ConfigrationWindow", "Joint Animation", 0, QApplication::UnicodeUTF8));
        refresh->setText(QApplication::translate("ConfigrationWindow", "Refresh", 0, QApplication::UnicodeUTF8));
        runAnimationButton->setText(QApplication::translate("ConfigrationWindow", "Run", 0, QApplication::UnicodeUTF8));
        stopAnimationButton->setText(QApplication::translate("ConfigrationWindow", "Stop", 0, QApplication::UnicodeUTF8));
        slowAnimationPushButton->setText(QApplication::translate("ConfigrationWindow", "Slow motion", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = AnimationtreeWidget->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("ConfigrationWindow", " Y ", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("ConfigrationWindow", " R ", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("ConfigrationWindow", "Animation", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ConfigrationWindow", "Name: ", 0, QApplication::UnicodeUTF8));
        loadXMLpushButton->setText(QApplication::translate("ConfigrationWindow", "Load", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ConfigrationWindow", "Character Info", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("ConfigrationWindow", "X Anchor: ", 0, QApplication::UnicodeUTF8));
        AnimationFireW1checkBox->setText(QApplication::translate("ConfigrationWindow", "FireW1", 0, QApplication::UnicodeUTF8));
        AnimationSetValuespushButton->setText(QApplication::translate("ConfigrationWindow", "SetValues", 0, QApplication::UnicodeUTF8));
        AddAnimationPointpushButton->setText(QApplication::translate("ConfigrationWindow", "Add point", 0, QApplication::UnicodeUTF8));
        RemoveAnimationPointpushButton->setText(QApplication::translate("ConfigrationWindow", "Del Point", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("ConfigrationWindow", "Time: ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConfigrationWindow", "Point time:", 0, QApplication::UnicodeUTF8));
        AddJointpushButton->setText(QApplication::translate("ConfigrationWindow", "Add Child", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = JointtreeWidget->headerItem();
        ___qtreewidgetitem1->setText(0, QApplication::translate("ConfigrationWindow", "Joint Name", 0, QApplication::UnicodeUTF8));
        JointYDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "Y/DD", 0, QApplication::UnicodeUTF8));
        JointRotationDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "R/DD", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("ConfigrationWindow", "Z: ", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("ConfigrationWindow", "Y Anchor:", 0, QApplication::UnicodeUTF8));
        JointW1checkBox->setText(QApplication::translate("ConfigrationWindow", "Contains weapon 1", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("ConfigrationWindow", "Joint properties", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("ConfigrationWindow", "SVG: ", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("ConfigrationWindow", "Name: ", 0, QApplication::UnicodeUTF8));
        DeleteJointpushButton->setText(QApplication::translate("ConfigrationWindow", "DeleteMe", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("ConfigrationWindow", "Change to:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("ConfigrationWindow", "*Use above as from point", 0, QApplication::UnicodeUTF8));
        ChangeAnimationPointpushButton->setText(QApplication::translate("ConfigrationWindow", "Change point", 0, QApplication::UnicodeUTF8));
        AnimationRDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "R/DD", 0, QApplication::UnicodeUTF8));
        AnimationYDragDroppushButton->setText(QApplication::translate("ConfigrationWindow", "Y/DD", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigrationWindow: public Ui_ConfigrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGRATIONWINDOW_H
