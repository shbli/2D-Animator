#include "configrationwindow.h"
#include "ui_configrationwindow.h"

#define numberOfParts 20

ConfigrationWindow::ConfigrationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConfigrationWindow)
{
    ui->setupUi(this);
    moving = false;
    setWindowFlags(Qt::MSWindowsOwnDC);
    move(QPoint(1200,100));
    svgSceneSelected = true;
    createPartsForms();
    superAttack = false;
    super_attack_enabler(superAttack);
    connect(ui->WeaponSuperAttackcheckBox,SIGNAL(toggled(bool)),this,SLOT(super_attack_checked_states_changed(bool)),Qt::UniqueConnection);
//    connect(ui->runAnimationButton,SIGNAL(clicked()),this,SLOT(on_runAnimationButton_clicked()));
    connect(ui->loadXMLpushButton,SIGNAL(clicked()),this,SLOT(loadXML()));
    before = new attackEffects("Before");
    before->soundFile = ui->BeforeEffectSoundFilelineEdit;
    before->listWidget = ui->BeforeAttacklistWidget;
    after = new attackEffects("After");
    after->soundFile = ui->AfterEffectSoundFilelineEdit;
    after->listWidget = ui->AfterAttacklistWidget;
    ui->WeaponXMFilelineEdit->setText(QSettings().value("xml_name").toString());
    current_selected = 0;
    current_selected_list = 0;
    currentElementID = -1;
    connect(ui->BeforeAttacklistWidget,SIGNAL(currentRowChanged(int)),this,SLOT(before_effect_selection_changed()),Qt::UniqueConnection);
    connect(ui->AfterAttacklistWidget,SIGNAL(currentRowChanged(int)),this,SLOT(after_effect_selection_changed()),Qt::UniqueConnection);
    ui->EffectBlurlineEdit->setHidden(true);
    ui->label_49->setHidden(true);

    Director::sharedDirector()->mainViewWindow->close();
    Director::sharedDirector()->sharedGraphicView()->setMinimumWidth(origwallw/1.5);
    Director::sharedDirector()->sharedGraphicView()->setMinimumHeight(origwallh/1.2);

    Director::sharedDirector()->sharedGraphicView()->setMaximumWidth(origwallw/1.5);
    Director::sharedDirector()->sharedGraphicView()->setMaximumHeight(origwallh/1.2);

    Director::sharedDirector()->sharedGraphicView()->setFixedWidth(origwallw/1.5);
    Director::sharedDirector()->sharedGraphicView()->setFixedHeight(origwallh/1.2);

    Director::sharedDirector()->sharedGraphicView()->setFrameStyle(1);

    ui->graphicsgridLayout->addWidget(Director::sharedDirector()->sharedGraphicView());

    if (!ui->scrollArea->horizontalScrollBar()->isHidden() || !ui->scrollArea->verticalScrollBar()->isHidden()) {
        qDebug() << "Scroll bar not hidden";
    }

    ui->toolBox->setCurrentIndex(0);
}

ConfigrationWindow::~ConfigrationWindow()
{
    delete ui;
}

void ConfigrationWindow::on_refresh_clicked() {
    ui->refresh->setEnabled(0);
    if (checkAnimationValues()) {
        submitPrevChanges();
        on_SaveXML_clicked();
        Scene *scene = Scene::node();
        svgScene = new svg_scene;
        scene->addChild(svgScene);
        Director::sharedDirector()->replaceScene(scene);
        svgScene->loadCharacterFromXML(ui->WeaponXMFilelineEdit->text());
    } else {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("Cannot save empty file!!! Please create something first!!!");
        box.setText(messagetext);
        box.exec();

    }
    ui->refresh->setEnabled(1);
}

void ConfigrationWindow::on_SaveXML_clicked() {
    if (ui->WeaponXMFilelineEdit->text().isEmpty()) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("File name cannot be empty!");
        box.setText(messagetext);
        box.exec();
    } else {

        //saving a file name for next time load
        QSettings().setValue("xml_name",ui->WeaponXMFilelineEdit->text());
        QSettings().sync();

        //creating the xml file in ram memery
        QDomDocument xmlDocument;
        QDomElement weaponElement;
        if (superAttack) {
            weaponElement = xmlDocument.createElement("super-attack");
        } else {
            weaponElement = xmlDocument.createElement("weapon");
        }
        weaponElement.setAttribute("power",ui->WeaponPowerlineEdit->text());

        if (superAttack) {
            //saving the check boxes
            weaponElement.setAttribute("affect-all",ui->SuperAffectsAllcheckBox->isChecked());
            weaponElement.setAttribute("hp--",ui->SuperHPDecreasecheckBox->isChecked());
            weaponElement.setAttribute("freeze",ui->SuperAttackFreezecheckBox->isChecked());
            weaponElement.setAttribute("slow-down",ui->SuperAttackSlowDowncheckBox->isChecked());
            weaponElement.setAttribute("shake-screen",ui->SuperAttackShakeScreencheckBox->isChecked());
            weaponElement.setAttribute("provoke",ui->SuperAttackProvokecheckBox->isChecked());

            //saving the line edits
            weaponElement.setAttribute("button-svg",ui->SuperAttackSVGButtonlineEdit->text());
            weaponElement.setAttribute("reset-seconds",ui->SuperAttackResetSecondslineEdit->text());
            weaponElement.setAttribute("hp-reduction",ui->SuperHPDescreaselineEdit->text());
            weaponElement.setAttribute("hp-reduction-timout",ui->SuperAttackHPDeductionTimelineEdit->text());
            weaponElement.setAttribute("freeze-timeout",ui->SuperAttackFreezeTimelineEdit->text());
            weaponElement.setAttribute("slow-down-timeout",ui->SuperAttackSlowDownTimelineEdit->text());
            weaponElement.setAttribute("shake-screen-timeout",ui->SuperAttackShakeScreenTimelineEdit->text());
        } else {
            weaponElement.setAttribute("name",ui->weaponNamelineEdit->text());
            weaponElement.setAttribute("type",ui->WeaponTypelineEdit->text());
            weaponElement.setAttribute("svg",ui->WeaponSVGlineEdit->text());
            weaponElement.setAttribute("fireFromFarAway",ui->WeaponLongRangecheckBox->isChecked());
            weaponElement.setAttribute("x-anch",ui->WeaponxAnchorlineEdit->text());
            weaponElement.setAttribute("y-anch",ui->WeaponyAnchorlineEdit->text());
            weaponElement.setAttribute("super-attack-xml",ui->WeaponSuperAttackXMLlineEdit->text());
        }

        //adding before and after effects elements

        weaponElement.appendChild(before->effectsDomElement(&xmlDocument));

        weaponElement.appendChild(after->effectsDomElement(&xmlDocument));

        xmlDocument.appendChild(weaponElement);

        //saving actual xml content to a file

        QFile file(ui->WeaponXMFilelineEdit->text().toAscii());
        if ( ! file.open( QIODevice::WriteOnly | QIODevice::Text ) ) {
            qFatal("Cannot create XML File");
        }
        QTextStream stream(&file);
        QString xmlAsString = xmlDocument.toString().toAscii();
        stream << xmlAsString;

        file.close();

        //saving actual xml content to a file in archive

        QFile file2("archive/" + ui->WeaponXMFilelineEdit->text().remove(".xml").toAscii() + "_" + QDate().currentDate().toString(Qt::ISODate) + "_" + QTime().currentTime().toString(Qt::ISODate) + ".xml");
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

void ConfigrationWindow::changeCurrentAnimationTime(int newTimeValue) {
}

void ConfigrationWindow::createPartsForms() {
}



void ConfigrationWindow::loadXML() {


    //this button should be clicked on a new empty character
    QDomDocument xmlDocument;
    QFile openxml(ui->WeaponXMFilelineEdit->text());

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("Cannot find the xml file, please make sure the file is under weapon directory!!!");
        box.setText(messagetext);
        box.exec();
    } else {

        ui->loadXMLpushButton->setEnabled(0);

        xmlDocument.setContent(&openxml);

        QDomElement document = xmlDocument.documentElement();

        if (document.tagName() == "super-attack") {
            superAttack = true;
        } else {
            superAttack = false;
        }

        ui->WeaponSuperAttackcheckBox->setChecked(superAttack);
        super_attack_enabler(superAttack);

        ui->WeaponPowerlineEdit->setText(document.attribute("power"));


        if (superAttack) {
            //loading the check boxes
            ui->SuperAffectsAllcheckBox->setChecked(document.attribute("affect-all").toInt());
            ui->SuperHPDecreasecheckBox->setChecked(document.attribute("hp--").toInt());
            ui->SuperAttackFreezecheckBox->setChecked(document.attribute("freeze").toInt());
            ui->SuperAttackSlowDowncheckBox->setChecked(document.attribute("slow-down").toInt());
            ui->SuperAttackShakeScreencheckBox->setChecked(document.attribute("shake-screen").toInt());
            ui->SuperAttackProvokecheckBox->setChecked(document.attribute("provoke").toInt());


            //loading the line edits
            ui->SuperAttackSVGButtonlineEdit->setText(document.attribute("button-svg"));
            ui->SuperAttackResetSecondslineEdit->setText(document.attribute("reset-seconds"));
            ui->SuperHPDescreaselineEdit->setText(document.attribute("hp-reduction"));
            ui->SuperAttackHPDeductionTimelineEdit->setText(document.attribute("hp-reduction-timout"));
            ui->SuperAttackFreezeTimelineEdit->setText(document.attribute("freeze-timeout"));
            ui->SuperAttackSlowDownTimelineEdit->setText(document.attribute("slow-down-timeout"));
            ui->SuperAttackShakeScreenTimelineEdit->setText(document.attribute("shake-screen-timeout"));
        } else {
            ui->WeaponTypelineEdit->setText(document.attribute("type"));
            ui->weaponNamelineEdit->setText(document.attribute("name"));
            ui->WeaponSVGlineEdit->setText(document.attribute("svg"));
            ui->WeaponLongRangecheckBox->setChecked(document.attribute("fireFromFarAway").toInt());
            ui->WeaponxAnchorlineEdit->setText(document.attribute("x-anch"));
            ui->WeaponyAnchorlineEdit->setText(document.attribute("y-anch"));
            ui->WeaponSuperAttackXMLlineEdit->setText(document.attribute("super-attack-xml"));
        }


        before->loadeffectsDomElement(&document.namedItem("Before").toElement());

        after->loadeffectsDomElement(&document.namedItem("After").toElement());

        openxml.close();

    }
}

bool ConfigrationWindow::checkAnimationValues() {
    if (!superAttack) {
        return (ui->weaponNamelineEdit->text() != "");
    } else {
        return true;
    }
}

void ConfigrationWindow::on_runAnimationButton_clicked() {
    svgScene->animation();
}

void ConfigrationWindow::on_stopAnimationButton_clicked() {
//    svgScene->stopAnimationOnCharacter();
}

void ConfigrationWindow::keyPressEvent(QKeyEvent *event) {
    qDebug() << "key code " << event->key();
    if (event->key() == 16777220) {
        on_refresh_clicked();
        qDebug() << "Enter clicked";
    }
}

void ConfigrationWindow::super_attack_checked_states_changed(bool isChecked) {
    superAttack = isChecked;
    super_attack_enabler(superAttack);
}



void ConfigrationWindow::super_attack_enabler(bool isSuper) {
    //disable if it is a super
    ui->WeaponSuperAttackXMLlineEdit->setEnabled(!isSuper);
    ui->WeaponSVGlineEdit->setEnabled(!isSuper);
    ui->WeaponxAnchorlineEdit->setEnabled(!isSuper);
    ui->WeaponyAnchorlineEdit->setEnabled(!isSuper);
    ui->weaponNamelineEdit->setEnabled(!isSuper);
    ui->WeaponTypelineEdit->setEnabled(!isSuper);
    ui->WeaponLongRangecheckBox->setEnabled(!isSuper);

    //enable if it is a super
    ui->SuperAffectsAllcheckBox->setEnabled(isSuper);
    ui->SuperAttackFreezecheckBox->setEnabled(isSuper);
    ui->SuperAttackFreezeTimelineEdit->setEnabled(isSuper);
    ui->SuperAttackHPDeductionTimelineEdit->setEnabled(isSuper);
    ui->SuperAttackResetSecondslineEdit->setEnabled(isSuper);
    ui->SuperAttackSlowDowncheckBox->setEnabled(isSuper);
    ui->SuperAttackProvokecheckBox->setEnabled(isSuper);
    ui->SuperAttackSlowDownTimelineEdit->setEnabled(isSuper);
    ui->SuperAttackShakeScreenTimelineEdit->setEnabled(isSuper);
    ui->SuperAttackShakeScreencheckBox->setEnabled(isSuper);
    ui->SuperAttackSVGButtonlineEdit->setEnabled(isSuper);
    ui->SuperHPDecreasecheckBox->setEnabled(isSuper);
    ui->SuperHPDescreaselineEdit->setEnabled(isSuper);
}

void ConfigrationWindow::before_effect_selection_changed() {
    submitPrevChanges();
    current_selected = before;
    current_selected_list = ui->BeforeAttacklistWidget;
    list_element_changed();
}

void ConfigrationWindow::after_effect_selection_changed() {
    submitPrevChanges();
    current_selected = after;
    current_selected_list = ui->AfterAttacklistWidget;
    list_element_changed();
}

void ConfigrationWindow::list_element_changed() {
    currentElementID = current_selected_list->currentRow();

    if (currentElementID >= 0 && currentElementID < current_selected->size()) {
        //we are safe to save display info for that element
        attack_animation_part* animationPart = current_selected->attackParts->at(currentElementID);
        ui->EffectSVGlineEdit->setText(animationPart->svgBox);
        ui->EffectBlurlineEdit->setText(animationPart->blurBox);
        ui->EffectXAnchorlineEdit->setText(animationPart->xAnchBox);
        ui->EffectyAnchorlineEdit->setText(animationPart->yAnchBox);

        //setting opacity
        ui->Effect1OpacitylineEdit->setText(animationPart->step1->opaLineEdit);
        ui->Effect1OpacitylineEdit_2->setText(animationPart->step2->opaLineEdit);
        ui->Effect1OpacitylineEdit_3->setText(animationPart->step3->opaLineEdit);

        //setting x
        ui->Effect1XlineEdit->setText(animationPart->step1->xLineEdit);
        ui->Effect1XlineEdit_2->setText(animationPart->step2->xLineEdit);
        ui->Effect1XlineEdit_3->setText(animationPart->step3->xLineEdit);

        //setting y
        ui->Effect1YlineEdit->setText(animationPart->step1->yLineEdit);
        ui->Effect1YlineEdit_2->setText(animationPart->step2->yLineEdit);
        ui->Effect1YlineEdit_3->setText(animationPart->step3->yLineEdit);


        //setting scalex
        ui->Effect1ScaleXlineEdit->setText(animationPart->step1->sxLineEdit);
        ui->Effect1ScaleXlineEdit_2->setText(animationPart->step2->sxLineEdit);
        ui->Effect1ScaleXlineEdit_3->setText(animationPart->step3->sxLineEdit);

        //setting scaley
        ui->Effect1ScaleYlineEdit->setText(animationPart->step1->syLineEdit);
        ui->Effect1ScaleYlineEdit_2->setText(animationPart->step2->syLineEdit);
        ui->Effect1ScaleYlineEdit_3->setText(animationPart->step3->syLineEdit);


        //setting rotation
        ui->Effect1RotationlineEdit->setText(animationPart->step1->rLineEdit);
        ui->Effect1RotationlineEdit_2->setText(animationPart->step2->rLineEdit);
        ui->Effect1RotationlineEdit_3->setText(animationPart->step3->rLineEdit);


        //setting time, special case, t1 is 0, non visible
        ui->Effect1TimelineEdit->setText(animationPart->step1->tLineEdit);
        ui->Effect1TimelineEdit_2->setText(animationPart->step2->tLineEdit);
        ui->Effect1TimelineEdit_3->setText(animationPart->step3->tLineEdit);

    }
}

void ConfigrationWindow::submitPrevChanges() {
    if (current_selected != 0) {
        if ((currentElementID) >= 0 && (currentElementID) < current_selected->size()) {
            //we are safe to save the info for that element
            attack_animation_part* animationPart = current_selected->attackParts->at(currentElementID);
            animationPart->svgBox = ui->EffectSVGlineEdit->text();
            animationPart->blurBox = ui->EffectBlurlineEdit->text();
            animationPart->xAnchBox = ui->EffectXAnchorlineEdit->text();
            animationPart->yAnchBox = ui->EffectyAnchorlineEdit->text();

            //setting opacity
            animationPart->step1->opaLineEdit = ui->Effect1OpacitylineEdit->text();
            animationPart->step2->opaLineEdit = ui->Effect1OpacitylineEdit_2->text();
            animationPart->step3->opaLineEdit = ui->Effect1OpacitylineEdit_3->text();

            //setting x
            animationPart->step1->xLineEdit = ui->Effect1XlineEdit->text();
            animationPart->step2->xLineEdit = ui->Effect1XlineEdit_2->text();
            animationPart->step3->xLineEdit = ui->Effect1XlineEdit_3->text();

            //setting y
            animationPart->step1->yLineEdit = ui->Effect1YlineEdit->text();
            animationPart->step2->yLineEdit = ui->Effect1YlineEdit_2->text();
            animationPart->step3->yLineEdit = ui->Effect1YlineEdit_3->text();


            //setting scalex
            animationPart->step1->sxLineEdit = ui->Effect1ScaleXlineEdit->text();
            animationPart->step2->sxLineEdit = ui->Effect1ScaleXlineEdit_2->text();
            animationPart->step3->sxLineEdit = ui->Effect1ScaleXlineEdit_3->text();

            //setting scaley
            animationPart->step1->syLineEdit = ui->Effect1ScaleYlineEdit->text();
            animationPart->step2->syLineEdit = ui->Effect1ScaleYlineEdit_2->text();
            animationPart->step3->syLineEdit = ui->Effect1ScaleYlineEdit_3->text();


            //setting rotation
            animationPart->step1->rLineEdit = ui->Effect1RotationlineEdit->text();
            animationPart->step2->rLineEdit = ui->Effect1RotationlineEdit_2->text();
            animationPart->step3->rLineEdit = ui->Effect1RotationlineEdit_3->text();


            //setting time, special case, t1 is 0, non visible
            animationPart->step1->tLineEdit = ui->Effect1TimelineEdit->text();
            animationPart->step2->tLineEdit = ui->Effect1TimelineEdit_2->text();
            animationPart->step3->tLineEdit = ui->Effect1TimelineEdit_3->text();

            current_selected_list->item(currentElementID)->setText(animationPart->svgBox);
        }
    }
}

void ConfigrationWindow::on_AddBeforeEffectpushButton_clicked() {
    before->on_add_button();
    ui->BeforeAttacklistWidget->addItem(before->attackParts->last()->svgBox);
}

void ConfigrationWindow::on_RemoveBeforeEffectpushButton_clicked() {
    int currentRow = ui->BeforeAttacklistWidget->currentRow();
    if ((currentRow) >= 0 && (currentRow) < before->size()) {
        before->attackParts->takeAt(currentRow)->deleteLater();
        delete ui->BeforeAttacklistWidget->takeItem(currentRow);
    }
}

void ConfigrationWindow::on_AddAfterEffectpushButton_clicked() {
    after->on_add_button();
    ui->AfterAttacklistWidget->addItem(after->attackParts->last()->svgBox);
}

void ConfigrationWindow::on_RemoveAfterEffectpushButton_clicked() {
    int currentRow = ui->AfterAttacklistWidget->currentRow();
    if ((currentRow) >= 0 && (currentRow) < after->size()) {
        after->attackParts->takeAt(currentRow)->deleteLater();
        delete ui->AfterAttacklistWidget->takeItem(currentRow);
    }
}
