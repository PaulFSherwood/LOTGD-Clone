#include <QtGui>
#include <iostream>
#include "creature.h"
#include "uiGroup.h"
#include "player.h"
#include "xmlParse.h"
using namespace std;

void xmlParse::writeXML_Class_Object(myplayer * myPlayer_Object, mycreature * creature_Object)
{
    // variable setup to pass current values into xml
    QString PHpCap = QString::number(myPlayer_Object->GetPlayerHpCap());
    QString PHpCurrent = QString::number(myPlayer_Object->GetPlayerHpCurrent());
    QString lvl = QString::number(myPlayer_Object->GetPlayerLvlP());

    QString xpCurrent = QString::number(myPlayer_Object->GetPlayerXpCurrent());
    QString xpRequired = QString::number(myPlayer_Object->GetPlayerXpRequired());

    QString Gold = QString::number(myPlayer_Object->GetPlayerGoldP());
    QString Savings = QString::number(myPlayer_Object->GetPlayerSavingsP());
    QString Weapon = QString::number(myPlayer_Object->GetPlayerWeaponP());
    QString Armor = QString::number(myPlayer_Object->GetPlayerArmorP());

    QString Attack = QString::number(myPlayer_Object->GetPlayerAtkP());
    QString Defense = QString::number(myPlayer_Object->GetPlayerDefP());
    QString Race = QString::fromStdString(myPlayer_Object->GetPlayerRaceP());

    QString Ohp = QString::number(creature_Object->GetCreatureHpC());
    QString OLvl = QString::number(creature_Object->GetCreatureLvlC());
    QString OAtk = QString::number(creature_Object->GetCreatureAtkC());
    QString ODef = QString::number(creature_Object->GetCreatureDefC());

    // pull file for use
    QString fileName = "data/myData.xml";

    // file checking
    if (fileName.isEmpty())
        return;

    QFile file(fileName);

    // set file operations to write only
    file.open(QIODevice::WriteOnly | QFile::Text);
    QXmlStreamWriter xml(&file);

    xml.setAutoFormatting(true);

    // update xml file with current working data
    xml.writeStartDocument();
        xml.writeDTD("<!DOCTYPE xbel>");
        xml.writeStartElement("xbel");
            xml.writeAttribute("version", "1.0");

                xml.writeStartElement("MyData");
                    xml.writeTextElement("Name", "Billy");
                    xml.writeTextElement("HpCap", PHpCap);
                    xml.writeTextElement("HpCurrent", PHpCurrent);
                    xml.writeTextElement("Lvl", lvl);

                    xml.writeTextElement("xpCurrent", xpCurrent);
                    xml.writeTextElement("xpRequired", xpRequired);

                    xml.writeTextElement("Gold", Gold);
                    xml.writeTextElement("Savings", Savings);
                    xml.writeTextElement("Weapon", Weapon);
                    xml.writeTextElement("Armor", Armor);

                    xml.writeTextElement("Attack", Attack);
                    xml.writeTextElement("Defense", Defense);
                    xml.writeTextElement("Race", Race);

                    xml.writeTextElement("OHp", Ohp);
                    xml.writeTextElement("OLvl", OLvl);

                    xml.writeTextElement("OAtk", OAtk);
                    xml.writeTextElement("ODef", ODef);
                    xml.writeTextElement("Oname", "Orge_01");

                xml.writeEndElement();
        xml.writeEndElement();
    xml.writeEndDocument();
}

void xmlParse::readXML_Class_Object(myplayer * myPlayer_Object)
{
    // pull file for use
    QString fileName = "data/myData.xml";

    // file checking
    if (fileName.isEmpty())
        return;

    // set file operations to read only
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        printf("Error opening file\n");
        return;
    }

    // cycle through xml file and pull out and assign data to variables
    QXmlStreamReader xml(&file);
    while(!xml.atEnd())
    {
        xml.readNext();
        if(xml.isStartElement())
        {
            // Read the tag name.
            while (xml.readNextStartElement()) {
                if (xml.name().toString().contains("MyData")){

                }else if (xml.name().toString().contains("Name")){
                    QString Name = xml.readElementText();
                    myPlayer_Object->SetPlayerNameP(Name.toStdString());

                }else if (xml.name().toString().contains("HpCap")){
                    QString hpCap = xml.readElementText();
                    myPlayer_Object->SetPlayerHpCap(hpCap.toInt());

                }else if (xml.name().toString().contains("HpCurrent")){
                    QString hpCurrent = xml.readElementText();
                    myPlayer_Object->SetPlayerHpCurrent(hpCurrent.toInt());

                }else if (xml.name().toString().contains("Lvl")){
                    QString lvl = xml.readElementText();
                    myPlayer_Object->SetPlayerLvlP(lvl.toInt());


                }else if (xml.name().toString().contains("xpCurrent")){
                    QString xpCurrent = xml.readElementText();
                    myPlayer_Object->SetPlayerXpCurrent(xpCurrent.toInt());

                }else if (xml.name().toString().contains("xpRequired")){
                    QString xpRequired = xml.readElementText();
                    myPlayer_Object->SetPlayerXpRequired(xpRequired.toInt());


                }else if (xml.name().toString().contains("Gold")){
                    QString Gold = xml.readElementText();
                    myPlayer_Object->SetPlayerGoldP(Gold.toInt());

                }else if (xml.name().toString().contains("Savings")){
                    QString Savings = xml.readElementText();
                    myPlayer_Object->SetPlayerSavingsP(Savings.toInt());

                }else if (xml.name().toString().contains("Weapon")){
                    QString Weapon = xml.readElementText();
                    myPlayer_Object->SetPlayerWeaponP(Weapon.toInt());

                }else if (xml.name().toString().contains("Armor")){
                    QString Armor = xml.readElementText();
                    myPlayer_Object->SetPlayerArmorP(Armor.toInt());


                }else if (xml.name().toString().contains("Attack")){
                    QString Attack = xml.readElementText();
                    myPlayer_Object->SetPlayerAtkP(Attack.toInt());

                }else if (xml.name().toString().contains("Defense")){
                    QString Defense = xml.readElementText();
                    myPlayer_Object->SetPlayerDefP(Defense.toInt());

                }else if (xml.name().toString().contains("Race")){
                    QString Race = xml.readElementText();
                    myPlayer_Object->SetPlayerRaceP(Race.toStdString());

                }else
                    xml.skipCurrentElement();
            }
        }
    }
}

void xmlParse::readXML_Class_Object(mycreature * creature_Object)
{
    // pull file for use
    QString fileName = "data/myData.xml";

    // file checking
    if (fileName.isEmpty())
        return;

    // set file operations to read only
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        printf("Error opening file\n");
        return;
    }

    // cycle through xml file and pull out and assign data to variables
    QXmlStreamReader xml(&file);
    while(!xml.atEnd())
    {
        xml.readNext();
        if(xml.isStartElement())
        {
            // Read the tag name.
            while (xml.readNextStartElement()) {
                if (xml.name().toString().contains("MyData")){

                }else if (xml.name().toString().contains("OHp")){
                    QString OHp = xml.readElementText();
                    creature_Object->SetCreatureHpC(OHp.toInt());

                }else if (xml.name().toString().contains("OLvl")){
                    QString OLvl = xml.readElementText();
                    creature_Object->SetCreatureLvlC(OLvl.toInt());

                }else if (xml.name().toString().contains("OAtk")){
                    QString OAtk = xml.readElementText();
                    creature_Object->SetCreatureAtkC(OAtk.toInt());

                }else if (xml.name().toString().contains("ODef")){
                    QString ODef = xml.readElementText();
                    creature_Object->SetCreatureDefC(ODef.toInt());

                }else if (xml.name().toString().contains("Oname")){
                    QString Oname = xml.readElementText();
                    creature_Object->SetCreatureNameC(Oname.toStdString());

                }else
                    xml.skipCurrentElement();
            }
        }
    }
}

void xmlParse::readXML_ui_Class_Object(uiGroup * uiObject)
{
    // pull file for use
    QString fileName = "data/uiData.xml";

    // file checking
    if (fileName.isEmpty())
        return;

    // set file operations to read only
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        printf("Error opening file\n");
        return;
    }

    // cycle through xml file and pull out and assign data to variables
    QXmlStreamReader xml(&file);
    while(!xml.atEnd())
    {
        xml.readNext();
        if(xml.isStartElement())
        {
            // Read the tag name.
            while (xml.readNextStartElement()) {
                if (xml.name().toString().contains("uiData")){

                }else if (xml.name().toString().contains("name_tag_left_x")){
                    QString name_tag_left_x = xml.readElementText();
                    uiObject->Setname_tag_left_x(name_tag_left_x.toInt());

                }else if (xml.name().toString().contains("name_tag_left_y")){
                    QString name_tag_left_y = xml.readElementText();
                    uiObject->Setname_tag_left_y(name_tag_left_y.toInt());

                }else if (xml.name().toString().contains("name_tag_left_text")){
                    QString name_tag_left_text = xml.readElementText();
                    uiObject->Setname_tag_left_text(name_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("name_value_right_x")){
                    QString name_value_right_x = xml.readElementText();
                    uiObject->Setname_value_right_x(name_value_right_x.toInt());

                }else if (xml.name().toString().contains("name_value_right_y")){
                    QString name_value_right_y = xml.readElementText();
                    uiObject->Setname_value_right_y(name_value_right_y.toInt());

                }else if (xml.name().toString().contains("name_value_right_text")){
                    QString name_value_right_text = xml.readElementText();
                    uiObject->Setname_value_right_text(name_value_right_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("level_tag_left_x")){
                    QString level_tag_left_x = xml.readElementText();
                    uiObject->Setlevel_tag_left_x(level_tag_left_x.toInt());

                }else if (xml.name().toString().contains("level_tag_left_y")){
                    QString level_tag_left_y = xml.readElementText();
                    uiObject->Setlevel_tag_left_y(level_tag_left_y.toInt());

                }else if (xml.name().toString().contains("level_tag_left_text")){
                    QString level_tag_left_text = xml.readElementText();
                    uiObject->Setlevel_tag_left_text(level_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("level_value_right_x")){
                    QString level_value_right_x = xml.readElementText();
                    uiObject->Setlevel_value_right_x(level_value_right_x.toInt());

                }else if (xml.name().toString().contains("level_value_right_y")){
                    QString level_value_right_y = xml.readElementText();
                    uiObject->Setlevel_value_right_y(level_value_right_y.toInt());

                }else if (xml.name().toString().contains("level_value_right_text")){
                    QString level_value_right_text = xml.readElementText();
                    uiObject->Setlevel_value_right_text(level_value_right_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("hp_tag_left_x")){
                    QString hp_tag_left_x = xml.readElementText();
                    uiObject->Sethp_tag_left_x(hp_tag_left_x.toInt());

                }else if (xml.name().toString().contains("hp_tag_left_y")){
                    QString hp_tag_left_y = xml.readElementText();
                    uiObject->Sethp_tag_left_y(hp_tag_left_y.toInt());

                }else if (xml.name().toString().contains("hp_tag_left_text")){
                    QString hp_tag_left_text = xml.readElementText();
                    uiObject->Sethp_tag_left_text(hp_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("hp_value_right_x")){
                    QString hp_value_right_x = xml.readElementText();
                    uiObject->Sethp_value_right_x(hp_value_right_x.toInt());

                }else if (xml.name().toString().contains("hp_value_right_y")){
                    QString hp_value_right_y = xml.readElementText();
                    uiObject->Sethp_value_right_y(hp_value_right_y.toInt());

                }else if (xml.name().toString().contains("hp_value_right_text")){
                    QString hp_value_right_text = xml.readElementText();
                    uiObject->Sethp_value_right_text(hp_value_right_text.toStdString());

                }else if (xml.name().toString().contains("hp_bar_right_x")){
                    QString hp_bar_right_x = xml.readElementText();
                    uiObject->Sethp_bar_right_x(hp_bar_right_x.toInt());

                }else if (xml.name().toString().contains("hp_bar_right_y")){
                    QString hp_bar_right_y = xml.readElementText();
                    uiObject->Sethp_bar_right_y(hp_bar_right_y.toInt());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("race_tag_left_x")){
                    QString race_tag_left_x = xml.readElementText();
                    uiObject->Setrace_tag_left_x(race_tag_left_x.toInt());

                }else if (xml.name().toString().contains("race_tag_left_y")){
                    QString race_tag_left_y = xml.readElementText();
                    uiObject->Setrace_tag_left_y(race_tag_left_y.toInt());

                }else if (xml.name().toString().contains("race_tag_left_text")){
                    QString race_tag_left_text = xml.readElementText();
                    uiObject->Setrace_tag_left_text(race_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("race_value_right_x")){
                    QString race_value_right_x = xml.readElementText();
                    uiObject->Setrace_value_right_x(race_value_right_x.toInt());

                }else if (xml.name().toString().contains("race_value_right_y")){
                    QString race_value_right_y = xml.readElementText();
                    uiObject->Setrace_value_right_y(race_value_right_y.toInt());

                }else if (xml.name().toString().contains("race_value_right_text")){
                    QString race_value_right_text = xml.readElementText();
                    uiObject->Setrace_value_right_text(race_value_right_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("str_tag_left_x")){
                    QString str_tag_left_x = xml.readElementText();
                    uiObject->Setstr_tag_left_x(str_tag_left_x.toInt());

                }else if (xml.name().toString().contains("str_tag_left_y")){
                    QString str_tag_left_y = xml.readElementText();
                    uiObject->Setstr_tag_left_y(str_tag_left_y.toInt());

                }else if (xml.name().toString().contains("str_tag_left_text")){
                    QString str_tag_left_text = xml.readElementText();
                    uiObject->Setstr_tag_left_text(str_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("str_value_right_x")){
                    QString str_value_right_x = xml.readElementText();
                    uiObject->Setstr_value_right_x(str_value_right_x.toInt());

                }else if (xml.name().toString().contains("str_value_right_y")){
                    QString str_value_right_y = xml.readElementText();
                    uiObject->Setstr_value_right_y(str_value_right_y.toInt());

                }else if (xml.name().toString().contains("str_value_right_text")){
                    QString str_value_right_text = xml.readElementText();
                    uiObject->Setstr_value_right_text(str_value_right_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("atk_tag_left_x")){
                    QString atk_tag_left_x = xml.readElementText();
                    uiObject->Setatk_tag_left_x(atk_tag_left_x.toInt());

                }else if (xml.name().toString().contains("atk_tag_left_y")){
                    QString atk_tag_left_y = xml.readElementText();
                    uiObject->Setatk_tag_left_y(atk_tag_left_y.toInt());

                }else if (xml.name().toString().contains("atk_tag_left_text")){
                    QString atk_tag_left_text = xml.readElementText();
                    uiObject->Setatk_tag_left_text(atk_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("atk_value_right_x")){
                    QString atk_value_right_x = xml.readElementText();
                    uiObject->Setatk_value_right_x(atk_value_right_x.toInt());

                }else if (xml.name().toString().contains("atk_value_right_y")){
                    QString atk_value_right_y = xml.readElementText();
                    uiObject->Setatk_value_right_y(atk_value_right_y.toInt());

                }else if (xml.name().toString().contains("atk_value_right_text")){
                    QString atk_value_right_text = xml.readElementText();
                    uiObject->Setatk_value_right_text(atk_value_right_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("def_tag_left_x")){
                    QString def_tag_left_x = xml.readElementText();
                    uiObject->Setdef_tag_left_x(def_tag_left_x.toInt());

                }else if (xml.name().toString().contains("def_tag_left_y")){
                    QString def_tag_left_y = xml.readElementText();
                    uiObject->Setdef_tag_left_y(def_tag_left_y.toInt());

                }else if (xml.name().toString().contains("def_tag_left_text")){
                    QString def_tag_left_text = xml.readElementText();
                    uiObject->Setdef_tag_left_text(def_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("def_value_right_x")){
                    QString def_value_right_x = xml.readElementText();
                    uiObject->Setdef_value_right_x(def_value_right_x.toInt());

                }else if (xml.name().toString().contains("def_value_right_y")){
                    QString def_value_right_y = xml.readElementText();
                    uiObject->Setdef_value_right_y(def_value_right_y.toInt());

                }else if (xml.name().toString().contains("def_value_right_text")){
                    QString def_value_right_text = xml.readElementText();
                    uiObject->Setdef_value_right_text(def_value_right_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("gold_tag_left_x")){
                    QString gold_tag_left_x = xml.readElementText();
                    uiObject->Setgold_tag_left_x(gold_tag_left_x.toInt());

                }else if (xml.name().toString().contains("gold_tag_left_y")){
                    QString gold_tag_left_y = xml.readElementText();
                    uiObject->Setgold_tag_left_y(gold_tag_left_y.toInt());

                }else if (xml.name().toString().contains("gold_tag_left_text")){
                    QString gold_tag_left_text = xml.readElementText();
                    uiObject->Setgold_tag_left_text(gold_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("gold_value_right_x")){
                    QString gold_value_right_x = xml.readElementText();
                    uiObject->Setgold_value_right_x(gold_value_right_x.toInt());

                }else if (xml.name().toString().contains("gold_value_right_y")){
                    QString gold_value_right_y = xml.readElementText();
                    uiObject->Setgold_value_right_y(gold_value_right_y.toInt());

                }else if (xml.name().toString().contains("gold_value_right_text")){
                    QString gold_value_right_text = xml.readElementText();
                    uiObject->Setgold_value_right_text(gold_value_right_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("wep_tag_left_x")){
                    QString wep_tag_left_x = xml.readElementText();
                    uiObject->Setwep_tag_left_x(wep_tag_left_x.toInt());

                }else if (xml.name().toString().contains("wep_tag_left_y")){
                    QString wep_tag_left_y = xml.readElementText();
                    uiObject->Setwep_tag_left_y(wep_tag_left_y.toInt());

                }else if (xml.name().toString().contains("wep_tag_left_text")){
                    QString wep_tag_left_text = xml.readElementText();
                    uiObject->Setwep_tag_left_text(wep_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("wep_value_right_x")){
                    QString wep_value_right_x = xml.readElementText();
                    uiObject->Setwep_value_right_x(wep_value_right_x.toInt());

                }else if (xml.name().toString().contains("wep_value_right_y")){
                    QString wep_value_right_y = xml.readElementText();
                    uiObject->Setwep_value_right_y(wep_value_right_y.toInt());

                }else if (xml.name().toString().contains("wep_value_right_text")){
                    QString wep_value_right_text = xml.readElementText();
                    uiObject->Setwep_value_right_text(wep_value_right_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("arm_tag_left_x")){
                    QString arm_tag_left_x = xml.readElementText();
                    uiObject->Setarm_tag_left_x(arm_tag_left_x.toInt());

                }else if (xml.name().toString().contains("arm_tag_left_y")){
                    QString arm_tag_left_y = xml.readElementText();
                    uiObject->Setarm_tag_left_y(arm_tag_left_y.toInt());

                }else if (xml.name().toString().contains("arm_tag_left_text")){
                    QString arm_tag_left_text = xml.readElementText();
                    uiObject->Setarm_tag_left_text(arm_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("arm_value_right_x")){
                    QString arm_value_right_x = xml.readElementText();
                    uiObject->Setarm_value_right_x(arm_value_right_x.toInt());

                }else if (xml.name().toString().contains("arm_value_right_y")){
                    QString arm_value_right_y = xml.readElementText();
                    uiObject->Setarm_value_right_y(arm_value_right_y.toInt());

                }else if (xml.name().toString().contains("arm_value_right_text")){
                    QString arm_value_right_text = xml.readElementText();
                    uiObject->Setarm_value_right_text(arm_value_right_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("exp_tag_left_x")){
                    QString exp_tag_left_x = xml.readElementText();
                    uiObject->Setexp_tag_left_x(exp_tag_left_x.toInt());

                }else if (xml.name().toString().contains("exp_tag_left_y")){
                    QString exp_tag_left_y = xml.readElementText();
                    uiObject->Setexp_tag_left_y(exp_tag_left_y.toInt());

                }else if (xml.name().toString().contains("exp_tag_left_text")){
                    QString exp_tag_left_text = xml.readElementText();
                    uiObject->Setexp_tag_left_text(exp_tag_left_text.toStdString());
                    ///////////////////////////////////////////////////////////////
                }else if (xml.name().toString().contains("exp_value_right_x")){
                    QString exp_value_right_x = xml.readElementText();
                    uiObject->Setexp_value_right_x(exp_value_right_x.toInt());

                }else if (xml.name().toString().contains("exp_value_right_y")){
                    QString exp_value_right_y = xml.readElementText();
                    uiObject->Setexp_value_right_y(exp_value_right_y.toInt());

                }else if (xml.name().toString().contains("exp_value_right_text")){
                    QString exp_value_right_text = xml.readElementText();
                    uiObject->Setexp_value_right_text(exp_value_right_text.toStdString());
                    ///////////////////////////////////////////////////////////////
               }else
                    xml.skipCurrentElement();
            }
        }
    }
}

void xmlParse::readXML_Fight_Data(mycreature * myCreature)
{
    // pull file for use
    QString fileName = "data/fightData.xml";

    // file checking
    if (fileName.isEmpty())
        return;

    // set file operations to read only
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        printf("Error opening file\n");
        return;
    }

    int vectorSizeCounter = 0;

    // cycle through xml file and pull out and assign data to variables
    QXmlStreamReader xml(&file);
    while(!xml.atEnd())
    {
        xml.readNext();
        if(xml.isStartElement())
        {
            // Read the tag name.
            while (xml.readNextStartElement()) {
                if (xml.name().toString().contains("fightData")){

                }else if (xml.name().toString().contains("Name")){
                    QString Name = xml.readElementText();
                    vectorSizeCounter += 1;
                    myCreature->SetFightVectorCounter(vectorSizeCounter);
                    myCreature->SetFightVectorData(Name.toStdString(), vectorSizeCounter);

                }else if (xml.name().toString().contains("Weapon")){
                    QString Weapon = xml.readElementText();
                    vectorSizeCounter += 1;
                    myCreature->SetFightVectorCounter(vectorSizeCounter);
                    myCreature->SetFightVectorData(Weapon.toStdString(), vectorSizeCounter);

                }else if (xml.name().toString().contains("Death")){
                    QString Death = xml.readElementText();
                    vectorSizeCounter += 1;
                    myCreature->SetFightVectorCounter(vectorSizeCounter);
                    myCreature->SetFightVectorData(Death.toStdString(), vectorSizeCounter);

               }else
                    xml.skipCurrentElement();
            }
        }
    }
}
