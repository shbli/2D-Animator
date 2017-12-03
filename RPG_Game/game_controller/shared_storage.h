#ifndef SHARED_STORAGE_H
#define SHARED_STORAGE_H

/*

  This is a singleton class, that controlls the game, it contains many static instances, for all the objects to contact

*/

#include <QObject>
#include <QMutex>
#include "character_base.h"
#include "game_engine.h"

#define firstCharacterKey "first_charactetr_xml_file_key"
#define secondCharacterKey "second_charactetr_xml_file_key"

#define level_extension "/playerLevel"
#define exprience_extension "/playerExp"
#define playable_extenstion "/playable"
#define weapon_extenstion "/weapon_in_hand"

#define goldAmountKey "current_gold_amount"
#define silverAmountKey "current_silver_amount"
#define redPotionAmountKey "current_red_poition_amount"
#define redJewelAmountKey "current_red_jewel_amount"
#define weaponsKey "player_weapons_list"
#define keysKey "player_keys_list"
#define checkPointKey "check_point_key"

#define xpToLevelMultiplier 10

class map;

class shared_storage : public QObject
{
    Q_OBJECT
public:
    static shared_storage* sharedGameStorage();

    //players methode
    QString getFirstPlayer();
    QString getSecondPlayer();
    float getPlayerLevel(QString playerXML);
    float getPlayerXP(QString playerXML);
    void setPlayerLevel(QString playerXML,float playerLevel);
    int getCurrentGold();
    void increaseGoldBy(int amount);
    void decreaseGoldBy(int amount);


    int getCurrentSilver();
    void increaseSilverBy(int amount);
    void decreaseSilverBy(int amount);


    int getCurrentRedPoition();
    void increaseRedPotion(int amount);
    void decreaseRedPotion(int amount);



    int getCurrentRedJewel();
    void increaseRedJewel(int amount);
    void decreaseRedJewel(int amount);


    void addNewWeapon(QString weaponXML);
    void removeOneWeapon(int weaponID);
    int weaponsCount();



    void addNewKey(QString key);
    void removeOneKey(QString key);
    int keyCount();
    bool isKeyAvailable(QString key);
    QStringList getKeysCopy();


    QString getWeaponXMLAt(int weaponID);
    QString replaceCharacterWeapon(QString characterXML,int newWeaponID);
    QString getWeaponForCharacter(QString characterXML);

    void setDropDisable(QString dropKey);
    bool isDropEnabled(QString dropKey);

    void setCheckPoint(QString checkPoint);
    QString getCheckPoint();

    //this returns true if the level has increased
    bool increaseXPby(QString player,int value);
    int getMaxXPforPlayer(QString player);

private:
    explicit shared_storage(QObject *parent = 0);
    static shared_storage* sharedStorage;
    static QMutex mutex;
    QSettings *sharedGameSettings;
    void syncSettingsLater();
    bool to_be_synced;

    int currentGold;
    int currentSilver;
    int currentRedPotion;
    int currentRedJewel;

    QStringList weapons;
    QStringList keys_list;
    QString getDefaultWeaponForCharacter(QString characterXML);
    void setWeaponForCharacter(QString characterXML,QString weaponXML);
    void saveWeapons();
    void refreshWeaponsList();
    void saveKeys();
    void refreshKeyList();

signals:
    
public slots:
    void sync_settings();
};

#endif // SHARED_STORAGE_H
