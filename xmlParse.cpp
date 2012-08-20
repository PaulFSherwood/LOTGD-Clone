#include <QtGui>
#include <iostream>
#include "xmlParse.h"
using namespace std;

player warrior;
npc orge;

void xmlParse::readXML(struct player &warrior, struct npc &orge)
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
                    warrior.WNameP = Name.toStdString();

                }else if (xml.name() == "Hp"){
                    QString Hp = xml.readElementText();
                    warrior.WHpP = Hp.toInt();

                }else if (xml.name() == "Str"){
                    QString Str = xml.readElementText();
                    warrior.WStrP = Str.toInt();

                }else if (xml.name() == "Lvl"){
                    QString lvl = xml.readElementText();
                    warrior.WLvlP = lvl.toInt();
                }else if (xml.name() == "xpTotal"){
                    QString xpTotal = xml.readElementText();
                    warrior.WXptotalP = xpTotal.toInt();

                }else if (xml.name() == "maxXP"){
                    QString maxXP = xml.readElementText();
                    warrior.WMaxxpP = maxXP.toInt();

                }else if (xml.name() == "Gold"){
                    QString Gold = xml.readElementText();
                    warrior.WGoldP = Gold.toInt();

                }else if (xml.name() == "Savings"){
                    QString Savings = xml.readElementText();
                    warrior.WSavingsP = Savings.toInt();

                }else if (xml.name() == "Weapon"){
                    QString Weapon = xml.readElementText();
                    warrior.WWeaponP = Weapon.toInt();

                }else if (xml.name() == "Armor"){
                    QString Armor = xml.readElementText();
                    warrior.WArmorP = Armor.toInt();

                }else if (xml.name() == "Attack"){
                    QString Attack = xml.readElementText();
                    warrior.WAtkP = Attack.toInt();

                }else if (xml.name() == "Defense"){
                    QString Defense = xml.readElementText();
                    warrior.WDefP = Defense.toInt();

                }else if (xml.name() == "Race"){
                    QString Race = xml.readElementText();
                    warrior.WRaceP = Race.toStdString();

                }else if (xml.name() == "OHp"){
                    QString Ohp = xml.readElementText();
                    orge.OHpC = Ohp.toInt();

                }else if (xml.name() == "OStr"){
                    QString Ostr = xml.readElementText();
                    orge.OStrC = Ostr.toInt();

                }else if (xml.name() == "Oname"){
                    QString Oname = xml.readElementText();
                    orge.ONameC = Oname.toStdString();

                }else if (xml.name() == "OLvl"){
                    QString OLvl = xml.readElementText();
                    orge.OLvlC = OLvl.toInt();

                }else
                    xml.skipCurrentElement();
            }
        }
    }
}


void xmlParse::writeXML(struct player &warrior, struct npc &orge)
{
    // variable setup to pass current values into xml
    QString Whp = QString::number(warrior.WHpP);
    QString Wstr = QString::number(warrior.WStrP);
    QString Wlvl = QString::number(warrior.WLvlP);
    QString Xptotal = QString::number(warrior.WXptotalP);
    QString Maxxp = QString::number(warrior.WMaxxpP);
    QString Gold = QString::number(warrior.WGoldP);
    QString Savings = QString::number(warrior.WSavingsP);
    QString Weapon = QString::number(warrior.WWeaponP);
    QString Armor = QString::number(warrior.WArmorP);
    QString Attack = QString::number(warrior.WAtkP);
    QString Defense = QString::number(warrior.WDefP);
    QString Race = QString::fromStdString(warrior.WRaceP);

    QString Ohp = QString::number(orge.OHpC);
    QString Ostr = QString::number(orge.OStrC);
    QString OLvl = QString::number(orge.OLvlC);

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
                    xml.writeTextElement("Armor", Armor);
                    xml.writeTextElement("Attack", Attack);
                    xml.writeTextElement("Defense", Defense);
                    xml.writeTextElement("Race", Race);

                    xml.writeTextElement("OHp", Ohp);
                    xml.writeTextElement("OStr", Ostr);
                    xml.writeTextElement("Oname", "Orge_01");
                    xml.writeTextElement("OLvl", OLvl);

                xml.writeEndElement();
        xml.writeEndElement();
    xml.writeEndDocument();
}
