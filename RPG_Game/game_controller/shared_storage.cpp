#include "shared_storage.h"

shared_storage* shared_storage::sharedStorage = 0;
QMutex shared_storage::mutex;

shared_storage *shared_storage::sharedGameStorage() {
    mutex.lock();
    if (!sharedStorage) {
        sharedStorage = new shared_storage;
        sharedStorage->sharedGameSettings = new QSettings("data.ini",QSettings::IniFormat,sharedStorage);

        if (!sharedStorage->sharedGameSettings->contains(goldAmountKey)) {
            sharedStorage->sharedGameSettings->setValue(firstCharacterKey,"warrior_tom.xml");
            sharedStorage->sharedGameSettings->setValue(QString("warrior_tom.xml") + playable_extenstion,true);
            sharedStorage->sharedGameSettings->setValue(QString("warrior_tom.xml") + level_extension,1);
            sharedStorage->sharedGameSettings->setValue(QString("warrior_tom.xml") + exprience_extension,5);

            sharedStorage->sharedGameSettings->setValue(secondCharacterKey,"ninja_mitsu.xml");
            sharedStorage->sharedGameSettings->setValue(QString("ninja_mitsu.xml") + playable_extenstion,true);
            sharedStorage->sharedGameSettings->setValue(QString("ninja_mitsu.xml") + level_extension,1);
            sharedStorage->sharedGameSettings->setValue(QString("ninja_mitsu.xml") + exprience_extension,5);


            //specify all new game settings
            sharedStorage->sharedGameSettings->setValue(goldAmountKey,0);
            sharedStorage->sharedGameSettings->setValue(silverAmountKey,0);
            sharedStorage->sharedGameSettings->setValue(redPotionAmountKey,0);
            sharedStorage->sharedGameSettings->setValue(redJewelAmountKey,0);
            sharedStorage->sharedGameSettings->setValue(QString("warrior_tom.xml") + weapon_extenstion,sharedStorage->getDefaultWeaponForCharacter("warrior_tom.xml"));
            sharedStorage->sharedGameSettings->setValue(QString("ninja_mitsu.xml") + weapon_extenstion,sharedStorage->getDefaultWeaponForCharacter("ninja_mitsu.xml"));

        }

        //load the current amount of gold the player does have
        sharedStorage->currentGold = sharedStorage->sharedGameSettings->value(goldAmountKey).toInt();
        sharedStorage->currentSilver = sharedStorage->sharedGameSettings->value(silverAmountKey).toInt();
        sharedStorage->currentRedJewel = sharedStorage->sharedGameSettings->value(redJewelAmountKey).toInt();
        sharedStorage->currentRedPotion = sharedStorage->sharedGameSettings->value(redPotionAmountKey).toInt();

    }
    mutex.unlock();

    sharedStorage->refreshWeaponsList();
    sharedStorage->refreshKeyList();

    return sharedStorage;
}

QString shared_storage::getFirstPlayer() {

    //    syncSettingsLater();
    QString first_xml = sharedGameSettings->value(firstCharacterKey).toString();
    return first_xml;
}

QString shared_storage::getSecondPlayer() {
    //    syncSettingsLater();
    QString second_xml = sharedGameSettings->value(secondCharacterKey).toString();
    return second_xml;
}

float shared_storage::getPlayerLevel(QString playerXML) {
    //default to return if player does not exist
    int player_level = -1;
    bool exist = sharedGameSettings->value(playerXML + playable_extenstion,false).toBool();
    if (exist) {
        player_level = sharedGameSettings->value(playerXML + level_extension).toFloat();
    }
    return player_level;
}

float shared_storage::getPlayerXP(QString playerXML) {
    int player_xp = -1;
    bool exist = sharedGameSettings->value(playerXML + playable_extenstion,false).toBool();
    if (exist) {
        player_xp = sharedGameSettings->value(playerXML + exprience_extension).toFloat();
    }
    return player_xp;
}

void shared_storage::setPlayerLevel(QString playerXML,float playerLevel) {
    sharedGameSettings->setValue(playerXML + level_extension,playerLevel);
}

int shared_storage::getCurrentGold() {
    return currentGold;
}

shared_storage::shared_storage(QObject *parent) {
    to_be_synced = false;
}

void shared_storage::syncSettingsLater() {
    if (!to_be_synced) {
        to_be_synced = true;
        QTimer::singleShot(1000,this,SLOT(sync_settings()));
    }
}

QString shared_storage::getDefaultWeaponForCharacter(QString character_file_name) {

    QString defaultWeapon;
    QDomDocument xmlDocument;
    QFile openxml(character_file_name);

    if (! openxml.open( QIODevice::ReadOnly | QIODevice::Text)) {
        //error message
        QMessageBox box;
        QString messagetext;
        messagetext = QString::fromUtf8("Error, can't read") + character_file_name + " Please contact us with a screen shot, or a copy of this error message";
        box.setText(messagetext);
        box.exec();
    } else {
        xmlDocument.setContent(&openxml);

        QDomElement document = xmlDocument.documentElement();

        defaultWeapon = document.attribute("w1-xml");

        openxml.close();
    }


    return defaultWeapon;
}

QString shared_storage::getWeaponForCharacter(QString characterXML) {
    return sharedGameSettings->value(characterXML + weapon_extenstion).toString();
}

void shared_storage::setWeaponForCharacter(QString characterXML, QString weaponXML) {
    sharedGameSettings->setValue(characterXML + weapon_extenstion,weaponXML);
}

void shared_storage::saveWeapons() {
    sharedGameSettings->setValue(weaponsKey,weapons);
}

void shared_storage::refreshWeaponsList() {
    weapons = sharedGameSettings->value(weaponsKey).toStringList();
}

void shared_storage::saveKeys() {
    sharedGameSettings->setValue(keysKey,keys_list);
}

void shared_storage::refreshKeyList() {
    keys_list = sharedGameSettings->value(keysKey).toStringList();
}

QString shared_storage::replaceCharacterWeapon(QString characterXML, int newWeaponID) {
    QString currentCharacterWeapon = getWeaponForCharacter(characterXML);
    refreshWeaponsList();
    QString newWeapon = weapons.at(newWeaponID);
    weapons.replace(newWeaponID,currentCharacterWeapon);
    saveWeapons();
    refreshWeaponsList();
    setWeaponForCharacter(characterXML,newWeapon);
    return newWeapon;

}

int shared_storage::weaponsCount() {
    return weapons.count();
}


QString shared_storage::getWeaponXMLAt(int weaponID) {
    return weapons.at(weaponID);
}

void shared_storage::sync_settings() {
    to_be_synced = false;
    sharedGameSettings->sync();
}

void shared_storage::increaseGoldBy(int amount) {
    currentGold += amount;
    if (currentGold > 999) {
        currentGold = 999;
    }
    if (currentGold < 0) {
        currentGold = 0;
    }

    sharedGameSettings->setValue(goldAmountKey,currentGold);
}

void shared_storage::decreaseGoldBy(int amount) {
    currentGold -= amount;
    if (currentGold > 999) {
        currentGold = 999;
    }
    if (currentGold < 0) {
        currentGold = 0;
    }

    sharedGameSettings->setValue(goldAmountKey,currentGold);
}

void shared_storage::addNewWeapon(QString weaponXML) {
    refreshWeaponsList();
    weapons.append(weaponXML);
    saveWeapons();
    refreshWeaponsList();
}

void shared_storage::removeOneWeapon(int weaponID) {
    refreshWeaponsList();
    weapons.removeAt(weaponID);
    saveWeapons();
    refreshWeaponsList();
}

void shared_storage::decreaseRedJewel(int amount) {
    currentRedJewel -= amount;
    if (currentRedJewel > 999) {
        currentRedJewel = 999;
    }
    if (currentRedJewel < 0) {
        currentRedJewel = 0;
    }

    sharedGameSettings->setValue(redJewelAmountKey,currentRedJewel);
}

void shared_storage::increaseRedJewel(int amount) {
    currentRedJewel += amount;
    if (currentRedJewel > 99) {
        currentRedJewel = 99;
    }
    if (currentRedJewel < 0) {
        currentRedJewel = 0;
    }

    sharedGameSettings->setValue(redJewelAmountKey,currentRedJewel);
}

int shared_storage::getCurrentRedJewel() {
    return currentRedJewel;
}

void shared_storage::decreaseRedPotion(int amount) {
    currentRedPotion -= amount;
    if (currentRedPotion > 99) {
        currentRedPotion = 99;
    }
    if (currentRedPotion < 0) {
        currentRedPotion = 0;
    }

    sharedGameSettings->setValue(redPotionAmountKey,currentRedPotion);
}

void shared_storage::increaseRedPotion(int amount) {
    currentRedPotion += amount;
    if (currentRedPotion > 99) {
        currentRedPotion = 99;
    }
    if (currentRedPotion < 0) {
        currentRedPotion = 0;
    }

    sharedGameSettings->setValue(redPotionAmountKey,currentRedPotion);
}

int shared_storage::getCurrentRedPoition() {
    return currentRedPotion;
}

void shared_storage::decreaseSilverBy(int amount) {
    currentSilver -= amount;
    if (currentSilver > 999) {
        currentSilver = 999;
    }
    if (currentSilver < 0) {
        currentSilver = 0;
    }

    sharedGameSettings->setValue(silverAmountKey,currentSilver);
}

void shared_storage::increaseSilverBy(int amount) {
    currentSilver += amount;
    while (currentSilver > 999) {
        currentSilver -= 999;
        currentGold += 1;
    }
    if (currentSilver < 0) {
        currentSilver = 0;
    }

    sharedGameSettings->setValue(silverAmountKey,currentSilver);
    increaseGoldBy(0);
}

int shared_storage::getCurrentSilver() {
    return currentSilver;
}

void shared_storage::addNewKey(QString key) {
    refreshKeyList();
    keys_list.append(key);
    saveKeys();
    refreshKeyList();
}

bool shared_storage::isKeyAvailable(QString key) {
    return keys_list.contains(key,Qt::CaseInsensitive);
}

QStringList shared_storage::getKeysCopy() {
    QStringList anotherList = keys_list;
    return anotherList;
}

int shared_storage::keyCount() {
    return keys_list.count();
}

void shared_storage::removeOneKey(QString key) {
    refreshKeyList();
    keys_list.removeOne(key);
    saveKeys();
    refreshKeyList();
}


void shared_storage::setDropDisable(QString dropKey) {
    sharedGameSettings->setValue(dropKey,false);
}
bool shared_storage::isDropEnabled(QString dropKey) {
    if (!sharedGameSettings->contains(dropKey)) {
        sharedGameSettings->setValue(dropKey,true);
    }
    return sharedGameSettings->value(dropKey).toBool();
}

void shared_storage::setCheckPoint(QString checkPoint) {
    sharedGameSettings->setValue(checkPointKey,checkPoint);
}

QString shared_storage::getCheckPoint() {
    return sharedGameSettings->value(checkPointKey).toString();
}

bool shared_storage::increaseXPby(QString player, int value) {

    bool levelIncreased = false;
    int playerLevel = sharedStorage->sharedGameSettings->value(player + level_extension).toInt();
    int currentXPLevel = sharedStorage->sharedGameSettings->value(player + exprience_extension).toInt();

    int maxExp = getMaxXPforPlayer(player);

    while (currentXPLevel + value > maxExp) {
        value -= (maxExp - currentXPLevel);
        currentXPLevel = 0;
        playerLevel += 1;
        levelIncreased = true;
        maxExp = 10 + (playerLevel * xpToLevelMultiplier);
    }

    currentXPLevel += value;


    sharedStorage->sharedGameSettings->setValue(player + level_extension,playerLevel);
    sharedStorage->sharedGameSettings->setValue(player + exprience_extension,currentXPLevel);

    return levelIncreased;
}

int shared_storage::getMaxXPforPlayer(QString player) {
    int playerLevel = sharedStorage->sharedGameSettings->value(player + level_extension).toInt();
    return 10 + (playerLevel * xpToLevelMultiplier);
}
