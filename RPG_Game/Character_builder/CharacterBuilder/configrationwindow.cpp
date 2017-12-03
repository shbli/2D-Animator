#include "configrationwindow.h"
#include "ui_configrationwindow.h"

#define numberOfParts 20

ConfigrationWindow::ConfigrationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfigrationWindow)
{
    ui->setupUi(this);
    moving = false;
    //    setWindowFlags(Qt::FramelessWindowHint);
    //    move(QPoint(1200,100));
    resize(1280,750);
    svgSceneSelected = true;
    svgScene = 0;
    selectedHbox = NULL;
    selectedAnimationStep = NULL;
    ui->XMLNamelineEdit->setText(QSettings().value("xml_name").toString());

#ifdef viewerOnly
    setFixedSize(200,100);
    ui->scrollArea->hide();
    ui->centralWidget->layout()->addWidget(ui->XMLNamelineEdit);
    ui->centralWidget->layout()->addWidget(ui->refresh);
    ui->refresh->setFixedWidth(200);
    ui->centralWidget->layout()->addWidget(ui->slowAnimationPushButton);
    ui->slowAnimationPushButton->setFixedWidth(200);
    ui->centralWidget->layout()->addWidget(ui->label);
#else
    connect(ui->loadXMLpushButton,SIGNAL(clicked()),this,SLOT(loadXML()),Qt::UniqueConnection);
    connect(ui->JointtreeWidget,SIGNAL(itemSelectionChanged()),this,SLOT(JointTreeSelectionChanged()),Qt::UniqueConnection);
    connect(ui->AnimationtreeWidget,SIGNAL(itemSelectionChanged()),this,SLOT(AnimationTreeSelectionChanged()),Qt::UniqueConnection);
    ui->JointXAnchlineEdit->setDisabled(1);
    setUpMovementsDropDown();
    ui->AnimationSetValuespushButton->setEnabled(0);
    ui->refresh->setDisabled(1);
#endif
    skeltalwidget = new skeltal_widget(this,this);
    disableUpdateSave = false;

    Director::sharedDirector()->mainViewWindow->close();
    Director::sharedDirector()->sharedGraphicView()->setMinimumWidth(origwallw/1.5);
    Director::sharedDirector()->sharedGraphicView()->setMinimumHeight(origwallh/1.25);

    Director::sharedDirector()->sharedGraphicView()->setMaximumWidth(origwallw/1.5);
    Director::sharedDirector()->sharedGraphicView()->setMaximumHeight(origwallh/1.25);

    Director::sharedDirector()->sharedGraphicView()->setFixedWidth(origwallw/1.5);
    Director::sharedDirector()->sharedGraphicView()->setFixedHeight(origwallh/1.25);

    Director::sharedDirector()->sharedGraphicView()->setFrameStyle(1);

    ui->GraphicsgridLayout->addWidget(Director::sharedDirector()->sharedGraphicView());

    if (!ui->scrollArea->horizontalScrollBar()->isHidden() || !ui->scrollArea->verticalScrollBar()->isHidden()) {
        qDebug() << "Scroll bar not hidden";
    }

    ui->toolBox->setCurrentIndex(0);
    ui->AnimationtreeWidget->setColumnWidth(0,100);
    ui->AnimationtreeWidget->setColumnWidth(2,40);
    QFont font = ui->label_23->font();
    font.setPointSize(7);
    ui->label_23->setFont(font);

    ui->keyFrameslistWidget->clear();
    key_frames_strings.clear();
    ui->keyFrameslistWidget->addItem("To show key frames, select Main from Joints list, then select animation name from Joint animation list! Make sure to click on an animation name, not time!!!");
    font = ui->keyFrameslistWidget->item(ui->keyFrameslistWidget->count()-1)->font();
    font.setBold(true);
    font.setPixelSize(14);
    ui->keyFrameslistWidget->item(ui->keyFrameslistWidget->count()-1)->setFont(font);
    ui->keyFrameslistWidget->item(ui->keyFrameslistWidget->count()-1)->setTextColor(QColor(0,190,255));
    time_diffrence = ui->KeyFramedoubleSpinBox->value();

    //    ui->toolBox->setFixedWidth(400);

}

ConfigrationWindow::~ConfigrationWindow()
{
    delete ui;delete skeltalwidget;
}

QTreeWidget *ConfigrationWindow::jointTreeWidget() {
    return ui->JointtreeWidget;
}

void ConfigrationWindow::setDragAndDropElement(skeltal_hbox *hBox) {
    svgScene->dragAndDropJoint = hBox;
}

void ConfigrationWindow::on_refresh_clicked() {
    ui->refresh->setEnabled(0);

#ifdef viewerOnly
    Scene *scene = Scene::node();
    pngScene = new png_scene;
    scene->addChild(pngScene);
    Director::sharedDirector()->replaceScene(scene);
    pngScene->loadCharacterFromXML(ui->XMLNamelineEdit->text(),0);
#else

    submitPrevChanges();
    if (checkAnimationValues()) {
        on_SaveXML_clicked();
        Scene *scene = Scene::node();
        svgScene = new svg_scene;
        scene->addChild(svgScene);
        Director::sharedDirector()->replaceScene(scene);
        svgScene->loadCharacterFromXML(ui->XMLNamelineEdit->text(),skeltalwidget->rootBox);
    }
#endif
    ui->refresh->setEnabled(1);
}

void ConfigrationWindow::on_SaveXML_clicked() {
    if (ui->XMLNamelineEdit->text().isEmpty()) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("File name cannot be empty!");
        box.setText(messagetext);
        box.exec();
    } else {

        if (skeltalwidget->noChilds()) {
            //display appropriate error message
            //error message
            QMessageBox box;
            QString messagetext;
            messagetext = QString::fromUtf8("Canot save a file, with 0 child joints, you may need to load an older file, or create a new character");
            box.setText(messagetext);
            box.exec();

        } else {
            QSettings().setValue("xml_name",ui->XMLNamelineEdit->text());
            QSettings().sync();
            //    //creating the xml file in ram memery
            QDomDocument xmlDocument;
            QDomElement characterElement = xmlDocument.createElement("character");
            characterElement.setAttribute("name",ui->NamelineEdit->text());
            characterElement.setAttribute("type",ui->TypelineEdit->text());
            characterElement.setAttribute("circule-y-offset",ui->yOffsetlineEdit->text());
            characterElement.setAttribute("speed",ui->SpeedlineEdit->text());
            characterElement.setAttribute("w1-xml",ui->Weapon1lineEdit->text());
            characterElement.setAttribute("health",ui->HealthlineEdit->text());
            characterElement.setAttribute("level",ui->LevellineEdit->text());
            characterElement.setAttribute("super-attack-xml",ui->SuperXMLlineEdit->text());


            characterElement.appendChild(skeltalwidget->getSkeltalDomElement(&xmlDocument));
            xmlDocument.appendChild(characterElement);

            //saving actual xml content to a file

            QFile file(ui->XMLNamelineEdit->text());
            if ( ! file.open( QIODevice::WriteOnly | QIODevice::Text ) ) {
                qFatal("Cannot create XML File");
            }
            QTextStream stream(&file);
            QString xmlAsString = xmlDocument.toString();
            stream << xmlAsString;

            file.close();

            //saving actual xml content to a file in archive

            QFile file2("archive/" + ui->XMLNamelineEdit->text().remove(".xml") + "_" + QDate().currentDate().toString(Qt::ISODate) + "_" + QTime().currentTime().toString(Qt::ISODate) + ".xml");
            if ( ! file2.open( QIODevice::WriteOnly | QIODevice::Text ) ) {
                //error message
                QMessageBox box;
                QString messagetext;
                messagetext = QString::fromUtf8("Please create a new folder called archive so that the application can automatically archive old files for you!");
                box.setText(messagetext);
                box.exec();
            } else {
                QTextStream stream(&file2);
                QString xmlAsString = xmlDocument.toString();
                stream << xmlAsString;

                file2.close();
            }
        }
    }
}

void ConfigrationWindow::changeCurrentAnimationTime(int newTimeValue) {
    bool change = false;
    if (currentSettingforAnimation != ui->AnimationcomboBox->currentText()) {
        currentSettingforAnimation = ui->AnimationcomboBox->currentText();
        change = true;
    }
    svgScene->setXMLTestCharacterCurrentAnimationTime(ui->AnimationcomboBox->currentText(),newTimeValue);

}

void ConfigrationWindow::loadXML() {

    QTime timer;
    timer.start();
    //this button should be clicked on a new empty character
    QDomDocument xmlDocument;
    QFile openxml(ui->XMLNamelineEdit->text());

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("ERROR : File not found, please make sure the xml file exist in the character directory!!!");
        box.setText(messagetext);
        box.exec();
    } else {
        ui->loadXMLpushButton->setEnabled(false);
        ui->refresh->setEnabled(true);
        xmlDocument.setContent(&openxml);

        QDomElement document = xmlDocument.documentElement();

        ui->TypelineEdit->setText(document.attribute("type"));
        ui->NamelineEdit->setText(document.attribute("name"));
        ui->yOffsetlineEdit->setText(document.attribute("circule-y-offset"));
        ui->SpeedlineEdit->setText(document.attribute("speed"));
        ui->Weapon1lineEdit->setText(document.attribute("w1-xml"));
        ui->HealthlineEdit->setText(document.attribute("health"));
        ui->LevellineEdit->setText(document.attribute("level"));
        ui->SuperXMLlineEdit->setText(document.attribute("super-attack-xml"));

        QDomElement eye;


        //use the eye element to load into it the first, or root joint
        eye = document.namedItem("joint").toElement();
        skeltalwidget->loadFromQDomElement(&eye);
        ui->JointtreeWidget->expandAll();

        openxml.close();

    }

}

bool ConfigrationWindow::checkAnimationValues() {
    return skeltalwidget->checkAnimationValues();
}

void ConfigrationWindow::JointTreeSelectionChanged() {

    updateSelectedAnimationIndex();
    submitPrevChanges();
    selectedAnimationStep = NULL;
    if (svgScene != 0) {
        svgScene->setTouchEnabled(false);
        svgScene->hideLine();
    }
    selectedHbox = static_cast<skeltal_hbox*>(ui->JointtreeWidget->currentItem());
    if (selectedHbox != NULL) {
        ui->JointNamelineEdit->setText(selectedHbox->partName);
        if (!selectedHbox->skeltalSVGs.isEmpty())
            ui->JointSVGlineEdit->setText(selectedHbox->skeltalSVGs.first());
        ui->JointRotationlineEdit->setText(QString().setNum(selectedHbox->rValueBox));
        bool disableYInteraction = false;
        if (selectedHbox->containsW1Box) {
            disableYInteraction = true;
        } else {
            if (selectedHbox->skeltalSVGs.isEmpty()) {
                disableYInteraction = false;
            } else {
                if (selectedHbox->skeltalSVGs.first() == "") {
                    disableYInteraction = false;
                } else {
                    disableYInteraction = true;
                }
            }
        }
        if (!disableYInteraction) {
            ui->JointYlineEdit->setText(QString().setNum(selectedHbox->yValueBox / (origwallw/ Director::sharedDirector()->winSizeInPixels().width())));
            ui->JointYlineEdit->setEnabled(1);
            ui->JointYDragDroppushButton->setEnabled(1);

        } else {
            ui->JointYlineEdit->setText(QString().setNum(0));
            ui->JointYlineEdit->setDisabled(1);
            ui->JointYDragDroppushButton->setDisabled(1);
        }
        ui->JointXAnchlineEdit->setText(QString().setNum(selectedHbox->xAnchValueBox));
        ui->JointXAnchlineEdit->setText(QString().setNum(0.5));
        ui->JointYAnchlineEdit->setText(QString().setNum(selectedHbox->yAnchValueBox));
        ui->JointZlineEdit->setText(QString().setNum(selectedHbox->zValueBox));
        ui->JointW1checkBox->setChecked(selectedHbox->containsW1Box);
    }
    refreshAnimationTree();
    selectUpdateSelectedAnimationIndex();
}

void ConfigrationWindow::AnimationTreeSelectionChanged() {

    if (!disableUpdateSave) {
        submitPrevAnimationChanges();
    } else {
        disableUpdateSave = false;
    }
    //    qDebug() << "Test 1 " << ui->AnimationtreeWidget->currentItem() << " Index " << ui->AnimationtreeWidget->currentIndex();
    if (ui->AnimationtreeWidget->currentItem() != 0) {
        if (ui->AnimationtreeWidget->currentItem()->text(1) != "") {
            selectedAnimationStep = static_cast<animationStep*>(ui->AnimationtreeWidget->currentItem());
            if (selectedAnimationStep != NULL) {
                ui->AnimationTimelineEdit->setText(QString().setNum(selectedAnimationStep->tBox));
                ui->AnimationRotationlineEdit->setText(QString().setNum(selectedAnimationStep->rBox));
                bool disableYInteraction = false;
                if (selectedHbox->containsW1Box) {
                    disableYInteraction = true;
                } else {
                    if (selectedHbox->skeltalSVGs.isEmpty()) {
                        disableYInteraction = false;
                    } else {
                        if (selectedHbox->skeltalSVGs.first() == "") {
                            disableYInteraction = false;
                        } else {
                            disableYInteraction = true;
                        }
                    }
                }
                if (!disableYInteraction) {
                    ui->AnimationYlineEdit->setText(QString().setNum(selectedAnimationStep->yBox / (origwallw/ Director::sharedDirector()->winSizeInPixels().width())));
                    if (selectedHbox->part_type != 0) {
                        ui->AnimationYlineEdit->setEnabled(1);
                        ui->AnimationYDragDroppushButton->setEnabled(1);
                    }
                } else {
                    ui->AnimationYlineEdit->setText(QString().setNum(0));
                    ui->AnimationYlineEdit->setDisabled(1);
                    ui->AnimationYDragDroppushButton->setDisabled(1);
                }

                ui->AnimationFireW1checkBox->setChecked(selectedAnimationStep->fireW1Box);
            }
        } else {
            //a root is selected, let's refresh the key frames
            if (selectedHbox->part_type == 0) {
                refresh_key_frames();
            }
        }
    }
}

void ConfigrationWindow::submitPrevChanges() {
    if (selectedHbox != NULL) {
        submitPrevAnimationChanges();
        selectedHbox->partName = ui->JointNamelineEdit->text();
        if (!selectedHbox->skeltalSVGs.isEmpty()) {
            selectedHbox->skeltalSVGs.replace(0,ui->JointSVGlineEdit->text());
        }
        selectedHbox->rValueBox = ui->JointRotationlineEdit->text().toFloat();
        selectedHbox->yValueBox = ui->JointYlineEdit->text().toFloat() * (origwallw/ Director::sharedDirector()->winSizeInPixels().width());
        selectedHbox->xAnchValueBox = ui->JointXAnchlineEdit->text().toFloat();
        selectedHbox->yAnchValueBox = ui->JointYAnchlineEdit->text().toFloat();
        selectedHbox->zValueBox = ui->JointZlineEdit->text().toFloat();
        selectedHbox->containsW1Box = ui->JointW1checkBox->isChecked();
        selectedHbox->refreshParameters();
    }
}

void ConfigrationWindow::submitPrevAnimationChanges() {
    if (selectedAnimationStep != NULL) {
        if (selectedAnimationStep->parentPartType == 0) {
        } else {
            selectedAnimationStep->tBox = ui->AnimationTimelineEdit->text().toFloat();
            selectedAnimationStep->rBox = ui->AnimationRotationlineEdit->text().toFloat();
            selectedAnimationStep->yBox = ui->AnimationYlineEdit->text().toFloat() * (origwallw/ Director::sharedDirector()->winSizeInPixels().width());
            selectedAnimationStep->fireW1Box = ui->AnimationFireW1checkBox->isChecked();
        }
        selectedAnimationStep->refreshStepParameters();
    }
}

void ConfigrationWindow::refreshAnimationTree() {
    if (selectedHbox != NULL ) {
        //this is the root selected
        if (selectedHbox->part_type == 0) {
            enableRootAnimationItems();
        } else {
            enableAnyAnimationItems();
        }
        while (ui->AnimationtreeWidget->topLevelItemCount() > 0)
            ui->AnimationtreeWidget->takeTopLevelItem(0);
        for (int i = 0; i < selectedHbox->animationsBoxes.size(); i++) {
            ui->AnimationtreeWidget->addTopLevelItem(selectedHbox->animationsBoxes.at(i));
            if (selectedAnimationStep != NULL && selectedHbox->part_type != 0) {
                if (ui->AnimationtreeWidget->topLevelItem(ui->AnimationtreeWidget->topLevelItemCount() - 1)->text(0) == selectedAnimationStep->parentAnimationBox->animationName) {
                    ui->AnimationtreeWidget->topLevelItem(ui->AnimationtreeWidget->topLevelItemCount() - 1)->setExpanded(true);
                }
            } else {
                ui->AnimationtreeWidget->topLevelItem(ui->AnimationtreeWidget->topLevelItemCount() - 1)->setExpanded(true);
            }
        }
    }
}

void ConfigrationWindow::refresh_key_frames() {
    if (selectedHbox != NULL) {
        if (selectedHbox->part_type == 0) {
            if (time_diffrence >= 0.01) {
                if (ui->AnimationtreeWidget->currentItem() != 0) {
                    if (ui->AnimationtreeWidget->currentItem()->childCount() != 0) {
                        float total_time_frame = ui->AnimationtreeWidget->currentItem()->child(0)->text(0).toFloat();
                        key_animation_name = ui->AnimationtreeWidget->currentItem()->text(0);

                        ui->keyFrameslistWidget->clear();
                        key_frames_strings.clear();
                        QSet <QString> keySet;

                        float start_time = 0;
                        while (start_time <= total_time_frame) {

                            keySet.insert(QString().setNum(start_time));
                            start_time += time_diffrence;
                        }

                        int selected_animation_index = -1;
                        if (selectedHbox != NULL) {
                            for (int i = 0; i < selectedHbox->animationsBoxes.size(); i++) {
                                if (selectedHbox->animationsBoxes.at(i)->animationName == key_animation_name) {
                                    selected_animation_index = i;

                                    skeltal_hbox* to_be_parsed = 0;
                                    if (selectedHbox->part_type == 0 && selectedHbox->child_joint.size() > 0) {
                                        to_be_parsed = selectedHbox->child_joint.first();
                                    } else {
                                        to_be_parsed = selectedHbox;
                                    }
                                    if (to_be_parsed != 0) {
                                        for (int j = 0; j < to_be_parsed->animationsBoxes.at(selected_animation_index)->stepslist.size(); j++) {
                                            QSet<QString>::const_iterator i = keySet.insert(QString().setNum(to_be_parsed->animationsBoxes.at(selected_animation_index)->stepslist.at(j)->tBox));
                                            QString temp = *i;
                                            temp.append("00");
                                            keySet.remove(*i);
                                            keySet.insert(temp);
                                        }
                                    }
                                }
                            }


                            QStringList keyList = keySet.toList();
                            keyList.sort();
                            QString string_to_append;
                            bool is_key_frame = false;
                            while (!keyList.isEmpty()) {
                                string_to_append = keyList.takeFirst();
                                if (string_to_append.contains("00")) {
                                    is_key_frame = true;
                                    string_to_append.remove("00");
                                } else {
                                    is_key_frame = false;
                                }

                                key_frames_strings.append(string_to_append);
                                ui->keyFrameslistWidget->addItem("'");
                                if (is_key_frame) {
                                    QFont font = ui->keyFrameslistWidget->item(ui->keyFrameslistWidget->count()-1)->font();
                                    font.setBold(true);
                                    ui->keyFrameslistWidget->item(ui->keyFrameslistWidget->count()-1)->setFont(font);
                                    ui->keyFrameslistWidget->item(ui->keyFrameslistWidget->count()-1)->setTextColor(QColor(0,190,255));

                                }

                                QSize size = ui->keyFrameslistWidget->item(ui->keyFrameslistWidget->count()-1)->sizeHint();
                                size.setWidth(20);
                                size.setHeight(20);
                                ui->keyFrameslistWidget->item(ui->keyFrameslistWidget->count()-1)->setSizeHint(size);
                            }


                            //                            ui->keyFrameslistWidget->sortItems(Qt::AscendingOrder);



                        }
                    }
                }
            }
        }
    }
}

void ConfigrationWindow::on_runAnimationButton_clicked() {
    if (ui->AnimationcomboBox->currentText() != "") {
        if (svgScene != 0) {
            if (svgScene->xml_test_character != 0) {
                svgScene->setXMLTestCharacterCurrentAnimationTime(ui->AnimationcomboBox->currentText(),0);
                svgScene->runAnimationOnCharacter();
            }
        }
    }
}

void ConfigrationWindow::on_stopAnimationButton_clicked() {
    if (svgScene != 0) {
        if (svgScene->xml_test_character != 0) {
            svgScene->stopAnimationOnCharacter();
        }
    }
}

void ConfigrationWindow::keyPressEvent(QKeyEvent *event) {
    qDebug() << "key code " << event->key();
    if (event->key() == 16777220) {
        on_refresh_clicked();
        qDebug() << "Enter clicked";
    }
}

void ConfigrationWindow::updateSelectedAnimationIndex() {
    if (selectedHbox != NULL && selectedAnimationStep != NULL) {
        for (int i = 0; i < selectedHbox->animationsBoxes.size(); i++) {
            if (selectedHbox->animationsBoxes.at(i)->animationName == selectedAnimationStep->parentAnimationBox->animationName) {
                selectedAnimationIndex = i;
                selectedAnimationTimeLine = selectedAnimationStep->tBox;

                return;
            }
        }
    }
}

void ConfigrationWindow::selectUpdateSelectedAnimationIndex() {
    if (selectedHbox != NULL) {
        if (selectedAnimationIndex >= 0 && selectedAnimationIndex < selectedHbox->animationsBoxes.size()) {
            for (int i = 0; i < selectedHbox->animationsBoxes.at(selectedAnimationIndex)->stepslist.size(); i++) {
                if (selectedHbox->animationsBoxes.at(selectedAnimationIndex)->stepslist.at(i)->tBox == selectedAnimationTimeLine) {
                    disableUpdateSave = true;
                    ui->AnimationtreeWidget->setCurrentItem(selectedHbox->animationsBoxes.at(selectedAnimationIndex)->stepslist.at(i));
                }
            }
        }
    }
}

void ConfigrationWindow::setUpMovementsDropDown() {
    QDomDocument xmlDocument;
    QFile openxml("movements_types.xml");

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("File movements_types.xml must be in the character directory, application will now close");
        box.setText(messagetext);
        box.exec();
        qFatal("Cannot read xml file!!");
    }
    xmlDocument.setContent(&openxml);

    openxml.close();

    QDomElement animationtypes = xmlDocument.documentElement();
    QDomNode animationNode = animationtypes.firstChild();
    while (!animationNode.isNull()) {
        ui->AnimationcomboBox->addItem(animationNode.nodeName());
        animationNode = animationNode.nextSibling();
    }
}

void ConfigrationWindow::enableRootAnimationItems() {
    if (!ui->label_2->isEnabled()) {
        setRootAnimationEnabled(true);
    }
}

void ConfigrationWindow::enableAnyAnimationItems() {
    if (!ui->label_22->isEnabled()) {
        setRootAnimationEnabled(false);
    }
}

void ConfigrationWindow::setRootAnimationEnabled(bool enable) {
    if (enable) {
        ui->toolBox_2->setCurrentIndex(0);
    } else {
        ui->toolBox_2->setCurrentIndex(1);
    }
    ui->label_2->setEnabled(enable);
    ui->AnimationSetValuespushButton->setEnabled(enable);
    ui->AnimationChangeTimelineEdit->setEnabled(enable);
    ui->ChangeAnimationPointpushButton->setEnabled(enable);
    ui->label_12->setEnabled(enable);
    ui->label_16->setEnabled(enable);
    ui->AnimationTotalTimelineEdit->setEnabled(enable);
    ui->AddAnimationPointpushButton->setEnabled(enable);
    ui->RemoveAnimationPointpushButton->setEnabled(enable);
    ui->AnimationTimelineEdit->setEnabled(!enable);
    ui->AnimationRotationlineEdit->setEnabled(!enable);
    ui->AnimationRDragDroppushButton->setEnabled(!enable);
    ui->AnimationFireW1checkBox->setEnabled(!enable);
    ui->AnimationYDragDroppushButton->setEnabled(!enable);
    ui->AnimationYlineEdit->setEnabled(!enable);
    ui->label_22->setEnabled(!enable);
}

void ConfigrationWindow::disableWholeAnimationSection() {
    bool enable = true;
    ui->label_2->setEnabled(!enable);
    ui->AnimationTotalTimelineEdit->setEnabled(!enable);
    ui->AddAnimationPointpushButton->setEnabled(!enable);
    ui->RemoveAnimationPointpushButton->setEnabled(!enable);
    ui->AnimationTimelineEdit->setEnabled(!enable);
    ui->AnimationRotationlineEdit->setEnabled(!enable);
    ui->AnimationRDragDroppushButton->setEnabled(!enable);
    ui->AnimationFireW1checkBox->setEnabled(!enable);
    ui->AnimationYDragDroppushButton->setEnabled(!enable);
    ui->AnimationYlineEdit->setEnabled(!enable);
    ui->label_22->setEnabled(!enable);
}

void ConfigrationWindow::on_setValuesPushButton_clicked() {
    if (svgScene != 0) {
        svgScene->update(0.5);
    }
}

void ConfigrationWindow::on_AddAnimationPointpushButton_clicked() {
    if (selectedHbox != NULL) {
        if (selectedAnimationStep != NULL) {
            for (int i = 0; i < selectedHbox->animationsBoxes.size(); i++) {
                if (selectedHbox->animationsBoxes.at(i)->animationName == selectedAnimationStep->parentAnimationBox->animationName) {
                    selectedHbox->animationsBoxes.at(i)->addNewStep(ui->AnimationTotalTimelineEdit->text().toFloat(),i);
                    selectedAnimationStep->refreshStepParameters();
                    return;
                }
            }
        }
    }
}

void ConfigrationWindow::on_RemoveAnimationPointpushButton_clicked() {
    if (selectedHbox != NULL) {
        if (selectedAnimationStep != NULL) {
            for (int i = 0; i < selectedHbox->animationsBoxes.size(); i++) {
                if (selectedHbox->animationsBoxes.at(i)->animationName == selectedAnimationStep->parentAnimationBox->animationName) {
                    selectedHbox->animationsBoxes.at(i)->removeStep(ui->AnimationTotalTimelineEdit->text().toFloat(),i);
                    submitPrevAnimationChanges();
                    return;
                }
            }
        }
    }
}

void ConfigrationWindow::on_AddJointpushButton_clicked() {
    if (selectedHbox != NULL) {
        selectedHbox->addJoint_button();
        //add animation for that child too
        for (int i = 0; i < selectedHbox->animationsBoxes.size(); i++) {
            for (int j = 0; j < selectedHbox->animationsBoxes.at(i)->stepslist.size(); j++) {
                selectedHbox->child_joint.last()->animationsBoxes.at(i)->addNewStep(selectedHbox->animationsBoxes.at(i)->stepslist.at(j)->tBox,i);
            }
        }
    }
}

void ConfigrationWindow::on_DeleteJointpushButton_clicked() {
    if (selectedHbox != NULL) {
        selectedHbox->removeJoint_button();
    }
}

void ConfigrationWindow::on_JointYDragDroppushButton_clicked() {
    if (selectedHbox != NULL) {
        if (selectedHbox->partPointer != 0) {
            if (svgScene != 0) {
                svgScene->setTouchEnabled(true);
            }
            svgScene->dragAndDropJoint = selectedHbox;
            svgScene->dragDropLineEdit = ui->JointYlineEdit;
            svgScene->rotation = false;
            svgScene->updateJointSelection();

        }
    }
}

void ConfigrationWindow::on_JointRotationDragDroppushButton_clicked() {
    if (selectedHbox != NULL) {
        if (selectedHbox->partPointer != 0) {
            if (svgScene != 0) {
                svgScene->setTouchEnabled(true);
            }
            svgScene->dragAndDropJoint = selectedHbox;
            svgScene->dragDropLineEdit = ui->JointRotationlineEdit;
            svgScene->rotation = true;
            svgScene->updateJointSelection();

        }
    }
}

void ConfigrationWindow::on_AnimationRDragDroppushButton_clicked() {
    if (selectedHbox != NULL) {
        if (selectedHbox->partPointer != 0) {
            if (svgScene != 0) {
                svgScene->setTouchEnabled(true);
            }
            svgScene->dragAndDropJoint = selectedHbox;
            svgScene->dragDropLineEdit = ui->AnimationRotationlineEdit;
            svgScene->rotation = true;
            svgScene->updateJointSelection();
        }
    }
}

void ConfigrationWindow::on_AnimationYDragDroppushButton_clicked()
{
    if (selectedHbox != NULL) {
        if (selectedHbox->partPointer != 0) {
            if (svgScene != 0) {
                svgScene->setTouchEnabled(true);
            }
            svgScene->dragAndDropJoint = selectedHbox;
            svgScene->dragDropLineEdit = ui->AnimationYlineEdit;
            svgScene->rotation = false;
            svgScene->updateJointSelection();
        }
    }
}

void ConfigrationWindow::on_AnimationSetValuespushButton_clicked() {
    if (skeltalwidget->rootBox != 0) {
        if (selectedHbox != 0) {
            if (selectedAnimationStep != 0) {
                for (int i = 0; i < selectedHbox->animationsBoxes.size(); i++) {
                    if (selectedHbox->animationsBoxes.at(i)->animationName == selectedAnimationStep->parentAnimationBox->animationName) {
                        skeltalwidget->rootBox->setPartValues(ui->AnimationTotalTimelineEdit->text().toFloat(),i);
                        svgScene->update(0);
                        return;
                    }
                }
            }
        }
    }
}

void ConfigrationWindow::on_JointXDragDroppushButton_clicked() {
    if (selectedHbox != NULL) {
        if (selectedHbox->partPointer != 0) {
            svgScene->dragAndDropJoint = selectedHbox;
            svgScene->dragDropLineEdit = ui->JointYlineEdit;
            svgScene->rotation = false;
        }
    }
}

void ConfigrationWindow::on_slowAnimationPushButton_clicked() {
    if (game_controller::sharedGameController()->playerSpeed == 1.0) {
        //this is slow motion
        game_controller::sharedGameController()->playerSpeed = 0.05;
        game_controller::sharedGameController()->enemySpeed = 0.05;
        ui->slowAnimationPushButton->setText("Normal");
    } else {
        //this is slow motion
        game_controller::sharedGameController()->playerSpeed = 1.0;
        game_controller::sharedGameController()->enemySpeed = 1.0;
        ui->slowAnimationPushButton->setText("Slow motion");
    }
}

void ConfigrationWindow::on_ChangeAnimationPointpushButton_clicked() {
    if (selectedHbox != NULL) {
        if (selectedAnimationStep != NULL) {
            for (int i = 0; i < selectedHbox->animationsBoxes.size(); i++) {
                if (selectedHbox->animationsBoxes.at(i)->animationName == selectedAnimationStep->parentAnimationBox->animationName) {
                    selectedHbox->animationsBoxes.at(i)->changeAStep(ui->AnimationTotalTimelineEdit->text().toFloat(),ui->AnimationChangeTimelineEdit->text().toFloat(),i);
                    selectedAnimationStep->refreshStepParameters();
                    return;
                }
            }
        }
    }
}

void ConfigrationWindow::on_WeaponSuperpushButton_clicked() {
    if (svgScene != 0) {
        svgScene->run_sample_super_weapon();
    }
}

void ConfigrationWindow::on_CharSuperpushButton_clicked() {
    if (svgScene != 0) {
        svgScene->run_sample_super_char();
    }
}

void ConfigrationWindow::on_JointtreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column) {
    //activate super focus on that item
    if (selectedHbox != NULL) {
        if (!selectedHbox->partPointer->svgsList.isEmpty() || selectedHbox->partPointer->containsW1) {
            skeltalwidget->rootBox->dim_all_svgs();
            selectedHbox->show_current_one();
        }
    }
}

void ConfigrationWindow::on_JointResetAllOpacitypushButton_clicked() {
    skeltalwidget->rootBox->un_dim_all_svgs();
}

void ConfigrationWindow::on_keyFrameslistWidget_itemClicked(QListWidgetItem *item)
{
    int row = ui->keyFrameslistWidget->currentRow();
    ui->key_frame_label->setText(key_frames_strings.at(row));

    if (selectedHbox != NULL) {
        for (int i = 0; i < selectedHbox->animationsBoxes.size(); i++) {
            if (selectedHbox->animationsBoxes.at(i)->animationName == key_animation_name) {
                selectedAnimationIndex = i;
            }
        }
    }

    if (svgScene != 0) {
        svgScene->set_key_point_on_character(key_animation_name,key_frames_strings.at(row).toFloat());

        if (ui->keyFrameslistWidget->currentItem()->font().bold()) {
            selectedAnimationTimeLine = key_frames_strings.at(row).toFloat();
            selectUpdateSelectedAnimationIndex();
        }
    }
}

void ConfigrationWindow::on_keyFrameslistWidget_itemPressed(QListWidgetItem *item)
{

}

void ConfigrationWindow::on_keyFrameslistWidget_itemSelectionChanged()
{
    on_keyFrameslistWidget_itemClicked(ui->keyFrameslistWidget->currentItem());
}

void ConfigrationWindow::on_KeyFramedoubleSpinBox_valueChanged(double arg1){
    time_diffrence = arg1;
    refresh_key_frames();
}

void ConfigrationWindow::on_keyFrameslistWidget_itemDoubleClicked(QListWidgetItem *item) {
    //    int row = ui->keyFrameslistWidget->currentRow();
    //    ui->keyFrameslistWidget->setEnabled(false);
    //    if (item->font().bold()) {
    //        //we need to remove that point
    //        skeltalwidget->rootBox->animationsBoxes.at(selectedAnimationIndex)->removeStep(key_frames_strings.at(row).toFloat(),selectedAnimationIndex);

    //        QFont font = item->font();
    //        font.setBold(false);
    //        item->setFont(font);
    //        item->setTextColor(QColor(255,255,255));

    //    } else {
    //        //we need to add a new point for that point
    //        skeltalwidget->rootBox->animationsBoxes.at(selectedAnimationIndex)->addNewStep(key_frames_strings.at(row).toFloat(),selectedAnimationIndex,true);

    //        QFont font = item->font();
    //        font.setBold(true);
    //        item->setFont(font);
    //        item->setTextColor(QColor(0,190,255));

    //    }

    //    ui->keyFrameslistWidget->setEnabled(true);
    //    refresh_key_frames();

}
