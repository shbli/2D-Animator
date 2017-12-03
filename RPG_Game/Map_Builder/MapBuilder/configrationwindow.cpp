#include "configrationwindow.h"
#include "ui_configrationwindow.h"

#define numberOfParts 20

ConfigrationWindow::ConfigrationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfigrationWindow)
{
    ui->setupUi(this);
    //    moving = false;
    //    setWindowFlags(Qt::MSWindowsOwnDC);
    //    move(QPoint(1200,100));
    //    svgSceneSelected = true;
    //    svgScene = 0;
    //    selectedHbox = NULL;
    //    selectedAnimationStep = NULL;
    ui->MapXMLNamelineEdit->setText(QSettings().value("xml_name").toString());
    setUpElementTypesDropDown();
    connect(ui->ElementlistWidget,SIGNAL(itemSelectionChanged()),this,SLOT(listElementChanged()));
    connect(ui->EnemylistWidget,SIGNAL(itemSelectionChanged()),this,SLOT(enemy_list_changed()));
    currentElementID = -1;
    currentEnemyID = -1;
    svgScene = 0;

    ui->ElementYDragDroppushButton->setEnabled(false);
    ui->ElementRotationDragDroppushButton->setEnabled(false);
    ui->ElementXDragDroppushButton->setEnabled(false);

    //#ifdef viewerOnly
    ////    setFixedSize(200,100);
    ////    ui->scrollArea->hide();
    ////    ui->centralWidget->layout()->addWidget(ui->XMLNamelineEdit);
    ////    ui->centralWidget->layout()->addWidget(ui->refresh);
    ////    ui->refresh->setFixedWidth(200);
    ////    ui->centralWidget->layout()->addWidget(ui->slowAnimationPushButton);
    ////    ui->slowAnimationPushButton->setFixedWidth(200);
    ////    ui->centralWidget->layout()->addWidget(ui->label);
    //#else
    //    connect(ui->loadXMLpushButton,SIGNAL(clicked()),this,SLOT(loadXML()),Qt::UniqueConnection);
    //    connect(ui->JointtreeWidget,SIGNAL(itemSelectionChanged()),this,SLOT(JointTreeSelectionChanged()),Qt::UniqueConnection);
    //    connect(ui->AnimationtreeWidget,SIGNAL(itemSelectionChanged()),this,SLOT(AnimationTreeSelectionChanged()),Qt::UniqueConnection);
    //    ui->JointXAnchlineEdit->setDisabled(1);
    //    setUpMovementsDropDown();
    //    ui->AnimationSetValuespushButton->setEnabled(0);
    //    ui->refresh->setDisabled(1);
    //#endif
    //    skeltalwidget = new skeltal_widget(this,this);
    //    disableUpdateSave = false;

    Director::sharedDirector()->mainViewWindow->close();

    QSettings configs("../config.ini",QSettings::IniFormat);

    float screenWidth = configs.value("width").toInt();
    float screenHright = configs.value("height").toInt();
    Director::sharedDirector()->sharedGraphicView()->setMinimumWidth(screenWidth);
    Director::sharedDirector()->sharedGraphicView()->setMinimumHeight(screenHright);

    Director::sharedDirector()->sharedGraphicView()->setMaximumWidth(screenWidth);
    Director::sharedDirector()->sharedGraphicView()->setMaximumHeight(screenHright);

    Director::sharedDirector()->sharedGraphicView()->setFixedWidth(screenWidth);
    Director::sharedDirector()->sharedGraphicView()->setFixedHeight(screenHright);

    Director::sharedDirector()->sharedGraphicView()->setFrameStyle(1);

    ui->Graphics_view_gridLayout->addWidget(Director::sharedDirector()->sharedGraphicView());

    ui->toolBox->setCurrentIndex(0);
}

ConfigrationWindow::~ConfigrationWindow() {
    delete ui;
}


void ConfigrationWindow::on_refresh_clicked() {
    ui->refresh->setEnabled(0);

#ifdef viewerOnly
//    Scene *scene = Scene::node();
//    pngScene = new png_scene;
//    scene->addChild(pngScene);
//    Director::sharedDirector()->replaceScene(scene);
//    pngScene->loadCharacterFromXML(ui->XMLNamelineEdit->text(),0);
#else

    submitPrevChanges();
    on_SaveXML_clicked();
    if (svgScene != 0) {
        disconnect(svgScene,SIGNAL(signal_new_postion(float,float)),this,SLOT(on_position_element_changed(float,float)));
        disconnect(svgScene,SIGNAL(signal_new_rotation(float)),this,SLOT(on_rotation_element_changed(float)));
    }
    Scene *scene = Scene::node();
    svgScene = new svg_scene;
    scene->addChild(svgScene);
    Director::sharedDirector()->replaceScene(scene);
    svgScene->loadMapFromXML(ui->MapXMLNamelineEdit->text());
    //    svgScene->loadCharacterFromXML();
    if (svgScene != 0) {
        connect(svgScene,SIGNAL(signal_new_postion(float,float)),this,SLOT(on_position_element_changed(float,float)),Qt::UniqueConnection);
        connect(svgScene,SIGNAL(signal_new_rotation(float)),this,SLOT(on_rotation_element_changed(float)),Qt::UniqueConnection);
    }
    ui->ElementYDragDroppushButton->setEnabled(true);
    ui->ElementRotationDragDroppushButton->setEnabled(true);
    ui->ElementXDragDroppushButton->setEnabled(true);
    svgScene->setTouchEnabled(false);

#endif

    ui->refresh->setEnabled(true);
    ui->ElementlistWidget->clearSelection();
    currentElementID = -1;
    clearElementProperties();
}

void ConfigrationWindow::on_SaveXML_clicked() {
    if (ui->MapXMLNamelineEdit->text().isEmpty()) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("File name cannot be empty!");
        box.setText(messagetext);
        box.exec();
    } else {

        if (ui->ElementlistWidget->count() == 0) {
            //display appropriate error message
            //error message
            QMessageBox box;
            QString messagetext;
            messagetext = QString::fromUtf8("Canot save a file, with 0 elements, you may need to load an older file, or create a new elements");
            box.setText(messagetext);
            box.exec();

        } else {
            QSettings().setValue("xml_name",ui->MapXMLNamelineEdit->text());
            QSettings().sync();
            //creating the xml file in ram memery
            QDomDocument xmlDocument;
            QDomElement mainmapElement = xmlDocument.createElement("map");
            QDomElement mapElement = xmlDocument.createElement("all-map-emlemnts");
            mainmapElement.setAttribute("name",ui->MapNamelineEdit->text());
            mainmapElement.setAttribute("background",ui->MapBackgroundlineEdit->text());
            mainmapElement.setAttribute("checkpoint",ui->MapCheckPointcheckBox->isChecked());


            for (int i = 0; i < mapElements.size(); i++) {
                QDomElement oneMapElement = xmlDocument.createElement("map-element");
                oneMapElement.setAttribute("name",mapElements.at(i).name);
                oneMapElement.setAttribute("type",mapElements.at(i).type);
                oneMapElement.setAttribute("reward-type",mapElements.at(i).rewardType);
                oneMapElement.setAttribute("quest-key",mapElements.at(i).key);
                oneMapElement.setAttribute("svg",mapElements.at(i).elementSprite);
                oneMapElement.setAttribute("to-xml",mapElements.at(i).toXML);
                oneMapElement.setAttribute("x",QString().setNum(mapElements.at(i).x));
                oneMapElement.setAttribute("y",QString().setNum(mapElements.at(i).y));
                oneMapElement.setAttribute("r",QString().setNum(mapElements.at(i).r));
                oneMapElement.setAttribute("z",QString().setNum(mapElements.at(i).Z));
                oneMapElement.setAttribute("scale",QString().setNum(mapElements.at(i).scale));
                if (mapElements.at(i).flipped) {
                    oneMapElement.setAttribute("xscale",QString().setNum(-1));
                } else {
                    oneMapElement.setAttribute("xscale",QString().setNum(1));
                }
                mapElement.appendChild(oneMapElement);
            }


            QDomElement enemyElement = xmlDocument.createElement("enemies");
            enemyElement.setAttribute("contains_random_battle",ui->EnemycheckBox->isChecked());

            if (ui->EnemycheckBox->isChecked()) {
                enemyElement.setAttribute("ghost_skeltal_xml",ui->ghostXMLlineEdit->text());

                for (int i = 0; i < enemyElements.size(); i++) {
                    QDomElement one_enemy_element = xmlDocument.createElement("enemy-element");
                    one_enemy_element.setAttribute("skeltal_xml",enemyElements.at(i).enemy_xml);
                    one_enemy_element.setAttribute("enemy_level",QString().setNum(enemyElements.at(i).enemey_level));
                    enemyElement.appendChild(one_enemy_element);
                }
            }

            mainmapElement.appendChild(enemyElement);
            mainmapElement.appendChild(mapElement);
            xmlDocument.appendChild(mainmapElement);

            //saving actual xml content to a file

            QFile file(ui->MapXMLNamelineEdit->text().toAscii());
            if ( ! file.open( QIODevice::WriteOnly | QIODevice::Text ) ) {
                qFatal("Cannot create XML File");
            }
            QTextStream stream(&file);
            QString xmlAsString = xmlDocument.toString().toAscii();
            stream << xmlAsString;

            file.close();

            //saving actual xml content to a file in archive

            QFile file2("archive/" + ui->MapXMLNamelineEdit->text().remove(".xml").toAscii() + "_" + QDate().currentDate().toString(Qt::ISODate) + "_" + QTime().currentTime().toString(Qt::ISODate) + ".xml");
            if ( ! file2.open( QIODevice::WriteOnly | QIODevice::Text ) ) {
                //error message
                QMessageBox box;
                QString messagetext;
                messagetext = QString::fromUtf8("Please create a new folder called archive so that the application can automatically archive old files for you!");
                box.setText(messagetext);
                box.exec();
            } else {
                QTextStream stream(&file2);
                QString xmlAsString = xmlDocument.toString().toAscii();
                stream << xmlAsString;

                file2.close();
            }
        }
    }
}



void ConfigrationWindow::loadXML() {

    //this button should be clicked on a new empty character
    QDomDocument xmlDocument;
    QFile openxml(ui->MapXMLNamelineEdit->text());

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

        ui->MapNamelineEdit->setText(document.attribute("name"));
        ui->MapBackgroundlineEdit->setText(document.attribute("background"));
        ui->MapCheckPointcheckBox->setChecked(document.attribute("checkpoint").toInt());

        QDomNode mapElementsNode = document.namedItem("all-map-emlemnts");
        mapElementsNode = mapElementsNode.firstChild();
        while (!mapElementsNode.isNull()) {
            if (mapElementsNode.isElement()) {
                QDomElement mapElement = mapElementsNode.toElement();
                map_element newElement;

                newElement.x = mapElement.attribute("x").toFloat();
                newElement.y = mapElement.attribute("y").toFloat();
                newElement.r = mapElement.attribute("r").toFloat();
                newElement.name = mapElement.attribute("name");
                newElement.Z = mapElement.attribute("z").toInt();
                newElement.scale = mapElement.attribute("scale").toFloat();
                newElement.type = mapElement.attribute("type");
                newElement.rewardType = mapElement.attribute("reward-type");
                newElement.key = mapElement.attribute("quest-key");
                newElement.toXML = mapElement.attribute("to-xml");
                newElement.elementSprite = mapElement.attribute("svg");
                if (mapElement.attribute("xscale").toFloat() == -1) {
                    //the element is flipped
                    newElement.flipped = true;
                } else {
                    //the element is not flipped
                    newElement.flipped = false;
                }
                mapElements.append(newElement);
                ui->ElementlistWidget->addItem(newElement.name);
            }
            mapElementsNode = mapElementsNode.nextSibling();
        }

        QDomNode enemyElementsNode = document.namedItem("enemies");

        bool elementChecked = enemyElementsNode.toElement().attribute("contains_random_battle").toInt();
        if (elementChecked) {
            ui->EnemycheckBox->setChecked(true);
            ui->ghostXMLlineEdit->setText(enemyElementsNode.toElement().attribute("ghost_skeltal_xml"));
            enemyElementsNode = enemyElementsNode.firstChild();
            while (!enemyElementsNode.isNull()) {
                if (enemyElementsNode.isElement()) {
                    QDomElement enemyElement = enemyElementsNode.toElement();
                    enemey_element newElement;

                    newElement.enemey_level = enemyElement.attribute("enemy_level").toInt();
                    newElement.enemy_xml = enemyElement.attribute("skeltal_xml");
                    enemyElements.append(newElement);
                    ui->EnemylistWidget->addItem(newElement.enemy_xml);
                }
                enemyElementsNode = enemyElementsNode.nextSibling();
            }
        }

//        QDomElement enemyElement = xmlDocument.createElement("enemy");
//        enemyElement.setAttribute("contains_random_battle",ui->EnemycheckBox->isChecked());

//        if (ui->EnemycheckBox->isChecked()) {
//            enemyElement.setAttribute("ghost_skeltal_xml",ui->ghostXMLlineEdit->text());

//            for (int i = 0; i < enemyElements.size(); i++) {
//                QDomElement one_enemy_element = xmlDocument.createElement("enemy-element");
//                one_enemy_element.setAttribute("skeltal_xml",enemyElements.at(i).enemy_xml);
//                one_enemy_element.setAttribute("enemy_level",QString().setNum(enemyElements.at(i).enemey_level));
//                enemyElement.appendChild(one_enemy_element);
//            }
//        }

//        xmlDocument.appendChild(enemyElement);



        openxml.close();

    }

}

void ConfigrationWindow::submitPrevChanges() {
    if ((currentElementID) >= 0 && (currentElementID) < mapElements.size()) {
        //we are safe to save the info for that element
        map_element newElement;
        newElement.x = ui->ElementXlineEdit->text().toFloat();
        newElement.y = ui->ElementYlineEdit->text().toFloat();
        newElement.r = ui->ElementRotationlineEdit->text().toFloat();
        newElement.name = ui->ElementNamelineEdit->text();
        newElement.Z = ui->ElementZlineEdit->text().toFloat();
        newElement.scale = ui->ElementScalelineEdit->text().toFloat();
        newElement.type = ui->ElementTypeComboBox->currentText();
        newElement.key = ui->ElementKeylineEdit->text();
        newElement.rewardType = ui->ElementRewardTypeComboBox->currentText();
        newElement.toXML = ui->ElementXMLlineEdit->text();
        newElement.elementSprite = ui->ElementSVGlineEdit->text();
        newElement.flipped = ui->ElementFlippedcheckBox->isChecked();
        mapElements.replace(currentElementID,newElement);
        ui->ElementlistWidget->item(currentElementID)->setText(newElement.name);
    }
}

void ConfigrationWindow::submit_prev_enemy_changes() {
    if (currentEnemyID >= 0 && currentEnemyID < enemyElements.size()) {
        enemey_element newEnemy;
        newEnemy.enemy_xml = ui->EnemyXMLlineEdit->text();
        newEnemy.enemey_level = ui->EnemyLevellineEdit->text().toInt();
        enemyElements.replace(currentEnemyID,newEnemy);
        ui->EnemylistWidget->item(currentEnemyID)->setText(newEnemy.enemy_xml);
    }
}

void ConfigrationWindow::listElementChanged() {
    if (svgScene != 0) {

        svgScene->setTouchEnabled(false);
        submitPrevChanges();
        currentElementID = ui->ElementlistWidget->currentRow();

        if (currentElementID >= 0 && currentElementID < mapElements.size()) {

            svgScene->set_un_transparent();
            svgScene->elementID = ui->ElementlistWidget->currentRow();
            svgScene->set_transparent();

            //we are safe to save the info for that element
            map_element newElement = mapElements.at(currentElementID);
            ui->ElementXlineEdit->setText(QString().setNum(newElement.x));
            ui->ElementYlineEdit->setText(QString().setNum(newElement.y));
            ui->ElementZlineEdit->setText(QString().setNum(newElement.Z));
            ui->ElementScalelineEdit->setText(QString().setNum(newElement.scale));
            ui->ElementRotationlineEdit->setText(QString().setNum(newElement.r));
            ui->ElementNamelineEdit->setText(newElement.name);
            ui->ElementXMLlineEdit->setText(newElement.toXML);
            ui->ElementSVGlineEdit->setText(newElement.elementSprite);
            ui->ElementFlippedcheckBox->setChecked(newElement.flipped);
            ui->ElementKeylineEdit->setText(newElement.key);
            int elementTypeID = ui->ElementTypeComboBox->findText(newElement.type);
            if (elementTypeID != -1) {
                ui->ElementTypeComboBox->setCurrentIndex(elementTypeID);
            }

            elementTypeID = ui->ElementRewardTypeComboBox->findText(newElement.rewardType);
            if (elementTypeID != -1) {
                ui->ElementRewardTypeComboBox->setCurrentIndex(elementTypeID);
            }
        }
    }
}

void ConfigrationWindow::on_rotation_element_changed(float chagedR) {
    ui->ElementRotationlineEdit->setText(QString().setNum(chagedR));
}

void ConfigrationWindow::on_position_element_changed(float changedX, float changedY) {
    ui->ElementXlineEdit->setText(QString().setNum(changedX));
    ui->ElementYlineEdit->setText(QString().setNum(changedY));
}


void ConfigrationWindow::on_loadXMLpushButton_clicked()
{
    loadXML();
}

void ConfigrationWindow::setUpElementTypesDropDown() {
    QDomDocument xmlDocument;
    QFile openxml("map_elements_types.xml");

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("File map_elements_types.xml must be in the character directory, application will now close");
        box.setText(messagetext);
        box.exec();
        qFatal("Cannot read xml file!!");
    }
    xmlDocument.setContent(&openxml);

    openxml.close();

    QDomElement animationtypes = xmlDocument.documentElement();
    QDomNode animationNode = animationtypes.firstChild();
    while (!animationNode.isNull()) {
        ui->ElementTypeComboBox->addItem(animationNode.nodeName());
        animationNode = animationNode.nextSibling();
    }
}



void ConfigrationWindow::on_AddElementpushButton_clicked() {
    map_element newElement;
    newElement.x = 0;
    newElement.y = 0;
    newElement.r = 0;
    newElement.name = "New element";
    newElement.Z = 0;
    newElement.scale = 1;
    newElement.type = "";
    newElement.rewardType = "";
    newElement.key = "";
    newElement.toXML = "";
//    mapElements.append(newElement);
//    ui->ElementlistWidget->addItem(newElement.name);

    if (currentElementID >= 0 && currentElementID < mapElements.size()) {
        newElement.x = mapElements.at(currentElementID).x + 20;
        newElement.y = mapElements.at(currentElementID).y + 20;
        newElement.Z = mapElements.at(currentElementID).Z;
        newElement.scale = mapElements.at(currentElementID).scale;
        newElement.name = mapElements.at(currentElementID).name;

        if (mapElements.at(currentElementID).name.at(mapElements.at(currentElementID).name.count() - 2) == '_') {
            qDebug() << "Going inside";
            QString number = newElement.name.at(newElement.name.count()-1);
            newElement.name.remove(number);
            int num = number.toInt();
            num++;
            number.setNum(num);
            newElement.name += number;
        } else {
            newElement.name += "_1";
        }
        newElement.toXML = mapElements.at(currentElementID).toXML;
        newElement.type = mapElements.at(currentElementID).type;
        newElement.rewardType = mapElements.at(currentElementID).rewardType;
        newElement.key = mapElements.at(currentElementID).key;
        newElement.elementSprite = mapElements.at(currentElementID).elementSprite;
        newElement.r = mapElements.at(currentElementID).r;
        newElement.flipped = mapElements.at(currentElementID).flipped;
    }

    mapElements.append(newElement);
    ui->ElementlistWidget->addItem(newElement.name);

    ui->ElementYDragDroppushButton->setEnabled(false);
    ui->ElementRotationDragDroppushButton->setEnabled(false);
    ui->ElementXDragDroppushButton->setEnabled(false);

    svgScene->setTouchEnabled(false);

}

void ConfigrationWindow::on_DeleteElementPushButton_clicked() {

    disconnect(ui->ElementlistWidget,SIGNAL(itemSelectionChanged()),this,SLOT(listElementChanged()));
    currentElementID = -1;
    int toBeDeletedcurrentElementID = ui->ElementlistWidget->currentRow();

    if (toBeDeletedcurrentElementID >= 0 && toBeDeletedcurrentElementID < mapElements.size()) {
        qDebug() << "Element at list name " << ui->ElementlistWidget->item(toBeDeletedcurrentElementID)->text() << " and equvilant item at list is " << mapElements.at(toBeDeletedcurrentElementID).name << " id is " << toBeDeletedcurrentElementID;
        delete ui->ElementlistWidget->takeItem(toBeDeletedcurrentElementID);
        mapElements.removeAt(toBeDeletedcurrentElementID);
    }

    ui->ElementYDragDroppushButton->setEnabled(false);
    ui->ElementRotationDragDroppushButton->setEnabled(false);
    ui->ElementXDragDroppushButton->setEnabled(false);

    svgScene->setTouchEnabled(false);
    connect(ui->ElementlistWidget,SIGNAL(itemSelectionChanged()),this,SLOT(listElementChanged()),Qt::UniqueConnection);
}

void ConfigrationWindow::on_ElementXDragDroppushButton_clicked() {
    if (currentElementID != -1) {
        svgScene->setTouchEnabled(true);
        svgScene->elementID = ui->ElementlistWidget->currentRow();
        svgScene->rotation = false;
    }
}

void ConfigrationWindow::on_ElementYDragDroppushButton_clicked() {
    on_ElementXDragDroppushButton_clicked();
}

void ConfigrationWindow::on_ElementRotationDragDroppushButton_clicked() {
    if (currentElementID != -1) {
        svgScene->setTouchEnabled(true);
        svgScene->elementID = ui->ElementlistWidget->currentRow();
        svgScene->rotation = true;
    }
}

void ConfigrationWindow::print_all_elements(int elemtid) {
    if (elemtid == -1) {
        for (int i = 0; i < mapElements.size(); i++) {
            qDebug() << "Map element ID : " << i << " element name " << mapElements.at(i).name << " list name " << ui->ElementlistWidget->item(i)->text();
        }
    }
    else {
        qDebug() << "Map element ID : " << elemtid << " element name " << mapElements.at(elemtid).name << " list name " << ui->ElementlistWidget->item(elemtid)->text();
    }

}

void ConfigrationWindow::on_EnemycheckBox_toggled(bool checked) {
    ui->ghostLabel->setEnabled(checked);
    ui->ghostXMLlineEdit->setEnabled(checked);
    ui->EnemylistWidget->setEnabled(checked);
    ui->Enemylabel->setEnabled(checked);
    ui->EnemyLevellabel->setEnabled(checked);
    ui->EnemyXMLlabel->setEnabled(checked);
    ui->EnemyLevellineEdit->setEnabled(checked);
    ui->EnemyXMLlineEdit->setEnabled(checked);
    ui->EnemyAddpushButton->setEnabled(checked);
    ui->EnemyDeletepushButton->setEnabled(checked);
}

void ConfigrationWindow::on_EnemyAddpushButton_clicked() {
    enemey_element newEnemy;
    newEnemy.enemey_level = 1;
    newEnemy.enemy_xml = "enemy_xml.xml";
    if (currentEnemyID >= 0 && currentEnemyID < enemyElements.size() ) {
        newEnemy.enemy_xml = enemyElements.at(currentEnemyID).enemy_xml;
        newEnemy.enemey_level = enemyElements.at(currentElementID).enemey_level;
    }

    enemyElements.append(newEnemy);
    ui->EnemylistWidget->addItem(newEnemy.enemy_xml);
}

void ConfigrationWindow::on_EnemyDeletepushButton_clicked() {
    currentEnemyID = ui->EnemylistWidget->currentRow();

    if (currentEnemyID >= 0 && currentEnemyID < enemyElements.size()) {
        delete ui->EnemylistWidget->takeItem(currentEnemyID);
        mapElements.takeAt(currentEnemyID - 1);
    }
}

void ConfigrationWindow::clearElementProperties() {
    ui->ElementNamelineEdit->clear();
    ui->ElementRotationlineEdit->clear();
    ui->ElementSVGlineEdit->clear();
    ui->ElementXlineEdit->clear();
    ui->ElementYlineEdit->clear();
    ui->ElementXMLlineEdit->clear();
    ui->ElementZlineEdit->clear();
    ui->ElementScalelineEdit->clear();
}

void ConfigrationWindow::enemy_list_changed() {

    submit_prev_enemy_changes();

    currentEnemyID = ui->EnemylistWidget->currentRow();

    if (currentEnemyID >= 0 && currentEnemyID < enemyElements.size()) {
        //we are safe to save the info for that element
        enemey_element newElement = enemyElements.at(currentEnemyID);
        ui->EnemyLevellineEdit->setText(QString().setNum(newElement.enemey_level));
        ui->EnemyXMLlineEdit->setText(newElement.enemy_xml);
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
