#include <QtGui>
#include <iostream>
#include "orge.h"
#include "warrior.h"
#include "xmlParse.h"
using namespace std;

void xmlParse::writeXML_Class_Object(mywarrior * warrior_Object, npc_orge * npc_Object)
{
    // variable setup to pass current values into xml
    QString Whp = QString::number(warrior_Object->GetWHpP());
    QString Wstr = QString::number(warrior_Object->GetWStrP());
    QString Wlvl = QString::number(warrior_Object->GetWLvlP());
    QString Xptotal = QString::number(warrior_Object->GetWXptotalP());
    QString Maxxp = QString::number(warrior_Object->GetWMaxxpP());
    QString Gold = QString::number(warrior_Object->GetWGoldP());
    QString Savings = QString::number(warrior_Object->GetWSavingsP());
    QString Weapon = QString::number(warrior_Object->GetWWeaponP());
    QString ArmorType = QString::number(warrior_Object->GetWArmorTypeP());
    QString ArmorValue = QString::number(warrior_Object->GetWArmorValueP());
    QString Attack = QString::number(warrior_Object->GetWAtkP());
    QString Defense = QString::number(warrior_Object->GetWDefP());
    QString Race = QString::fromStdString(warrior_Object->GetWRaceP());

    QString Ohp = QString::number(npc_Object->GetOHpC());
    QString Ostr = QString::number(npc_Object->GetOStrC());
    QString OLvl = QString::number(npc_Object->GetOLvlC());
    QString OAtk = QString::number(npc_Object->GetOAtkC());
    QString ODef = QString::number(npc_Object->GetODefC());
    QString OArmorValueC = QString::number(npc_Object->GetOArmorValueC());

    // pull file for use
    QString fileName = "myData.xml";

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
                    xml.writeTextElement("Hp", Whp);
                    xml.writeTextElement("Str", Wstr);
                    xml.writeTextElement("Lvl", Wlvl);
                    xml.writeTextElement("xpTotal", Xptotal);
                    xml.writeTextElement("maxXP", Maxxp);
                    xml.writeTextElement("Gold", Gold);
                    xml.writeTextElement("Savings", Savings);
                    xml.writeTextElement("Weapon", Weapon);
                    xml.writeTextElement("ArmorType", ArmorType);
                    xml.writeTextElement("ArmorValue", ArmorValue);
                    xml.writeTextElement("Attack", Attack);
                    xml.writeTextElement("Defense", Defense);
                    xml.writeTextElement("Race", Race);

                    xml.writeTextElement("OHp", Ohp);
                    xml.writeTextElement("OStr", Ostr);
                    xml.writeTextElement("OLvl", OLvl);

                    xml.writeTextElement("OAtk", OAtk);
                    xml.writeTextElement("ODef", ODef);
                    xml.writeTextElement("OArmorValueC", OArmorValueC);
                    xml.writeTextElement("Oname", "Orge_01");

                xml.writeEndElement();
        xml.writeEndElement();
    xml.writeEndDocument();
}

void xmlParse::readXML_Class_Object(mywarrior * warrior_Object)
{
    // pull file for use
    QString fileName = "myData.xml";

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
                if (xml.name() == "MyData"){

                }else if (xml.name() == "Name"){
                    QString Name = xml.readElementText();
                    warrior_Object->SetWNameP(Name.toStdString());

                }else if (xml.name() == "Hp"){
                    QString Hp = xml.readElementText();
                    warrior_Object->SetWHpP(Hp.toInt());

                }else if (xml.name() == "Str"){
                    QString Str = xml.readElementText();
                    warrior_Object->SetWStrP(Str.toInt());

                }else if (xml.name() == "Lvl"){
                    QString lvl = xml.readElementText();
                    warrior_Object->SetWLvlP(lvl.toInt());

                }else if (xml.name() == "xpTotal"){
                    QString xpTotal = xml.readElementText();
                    warrior_Object->SetWXptotalP(xpTotal.toInt());

                }else if (xml.name() == "maxXP"){
                    QString maxXP = xml.readElementText();
                    warrior_Object->SetWMaxxpP(maxXP.toInt());

                }else if (xml.name() == "Gold"){
                    QString Gold = xml.readElementText();
                    warrior_Object->SetWGoldP(Gold.toInt());

                }else if (xml.name() == "Savings"){
                    QString Savings = xml.readElementText();
                    warrior_Object->SetWSavingsP(Savings.toInt());

                }else if (xml.name() == "Weapon"){
                    QString Weapon = xml.readElementText();
                    warrior_Object->SetWWeaponP(Weapon.toInt());

                }else if (xml.name() == "ArmorType"){
                    QString ArmorType = xml.readElementText();
                    warrior_Object->SetWArmorTypeP(ArmorType.toInt());

                }else if (xml.name() == "ArmorValue"){
                    QString ArmorValue = xml.readElementText();
                    warrior_Object->SetWArmorValueP(ArmorValue.toInt());

                }else if (xml.name() == "Attack"){
                    QString Attack = xml.readElementText();
                    warrior_Object->SetWAtkP(Attack.toInt());

                }else if (xml.name() == "Defense"){
                    QString Defense = xml.readElementText();
                    warrior_Object->SetWDefP(Defense.toInt());

                }else if (xml.name() == "Race"){
                    QString Race = xml.readElementText();
                    warrior_Object->SetWRaceP(Race.toStdString());

                }else
                    xml.skipCurrentElement();
            }
        }
    }
}

void xmlParse::readXML_Class_Object(npc_orge * npc_Object)
{
    // pull file for use
    QString fileName = "myData.xml";

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
                if (xml.name() == "MyData"){

                }else if (xml.name() == "OHp"){
                    QString OHp = xml.readElementText();
                    npc_Object->SetOHpC(OHp.toInt());

                }else if (xml.name() == "OStr"){
                    QString OStr = xml.readElementText();
                    npc_Object->SetOStrC(OStr.toInt());

                }else if (xml.name() == "OLvl"){
                    QString OLvl = xml.readElementText();
                    npc_Object->SetOLvlC(OLvl.toInt());

                }else if (xml.name() == "OAtk"){
                    QString OAtk = xml.readElementText();
                    npc_Object->SetOAtkC(OAtk.toInt());

                }else if (xml.name() == "ODef"){
                    QString ODef = xml.readElementText();
                    npc_Object->SetODefC(ODef.toInt());

                }else if (xml.name() == "OArmorValueC"){
                    QString OArmorValueC = xml.readElementText();
                    npc_Object->SetOArmorValueC(OArmorValueC.toInt());

                }else if (xml.name() == "Oname"){
                    QString Oname = xml.readElementText();
                    npc_Object->SetONameC(Oname.toStdString());

                }else
                    xml.skipCurrentElement();
            }
        }
    }
}

