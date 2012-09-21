#ifndef UIGROUP_H
#define UIGROUP_H

#include <iostream>
#include "includes.h"
using namespace std;

class uiGroup
{
public:
    uiGroup();

    void Setname_tag_left_x(int ui_name_tag_left_x);
    void Setname_tag_left_y(int ui_name_tag_left_y);
    void Setname_tag_left_text(string ui_name_tag_left_text);
    void Setname_value_right_x(int ui_name_value_right_x);
    void Setname_value_right_y(int ui_name_value_right_y);
    void Setname_value_right_text(string ui_name_value_right_text);
    void Setlevel_tag_left_x(int ui_level_tag_left_x);
    void Setlevel_tag_left_y(int ui_level_tag_left_y);
    void Setlevel_tag_left_text(string ui_level_tag_left_text);
    void Setlevel_value_right_x(int ui_level_value_right_x);
    void Setlevel_value_right_y(int ui_level_value_right_y);
    void Setlevel_value_right_text(string ui_level_value_right_text);
    void Sethp_tag_left_x(int ui_hp_tag_left_x);
    void Sethp_tag_left_y(int ui_hp_tag_left_y);
    void Sethp_tag_left_text(string ui_hp_tag_left_text);
    void Sethp_value_right_x(int ui_hp_value_right_x);
    void Sethp_value_right_y(int ui_hp_value_right_y);
    void Sethp_value_right_text(string ui_hp_value_right_text);
    void Setrace_tag_left_x(int ui_race_tag_left_x);
    void Setrace_tag_left_y(int ui_race_tag_left_y);
    void Setrace_tag_left_text(string ui_race_tag_left_text);
    void Setrace_value_right_x(int ui_race_value_right_x);
    void Setrace_value_right_y(int ui_race_value_right_y);
    void Setrace_value_right_text(string ui_race_value_right_text);
    void Setstr_tag_left_x(int ui_str_tag_left_x);
    void Setstr_tag_left_y(int ui_str_tag_left_y);
    void Setstr_tag_left_text(string ui_str_tag_left_text);
    void Setstr_value_right_x(int ui_str_value_right_x);
    void Setstr_value_right_y(int ui_str_value_right_y);
    void Setstr_value_right_text(string ui_str_value_right_text);
    void Setatk_tag_left_x(int ui_atk_tag_left_x);
    void Setatk_tag_left_y(int ui_atk_tag_left_y);
    void Setatk_tag_left_text(string ui_atk_tag_left_text);
    void Setatk_value_right_x(int ui_atk_value_right_x);
    void Setatk_value_right_y(int ui_atk_value_right_y);
    void Setatk_value_right_text(string ui_atk_value_right_text);
    void Setdef_tag_left_x(int ui_def_tag_left_x);
    void Setdef_tag_left_y(int ui_def_tag_left_y);
    void Setdef_tag_left_text(string ui_def_tag_left_text);
    void Setdef_value_right_x(int ui_def_value_right_x);
    void Setdef_value_right_y(int ui_def_value_right_y);
    void Setdef_value_right_text(string ui_def_value_right_text);
    void Setarmv_tag_left_x(int ui_armv_tag_left_x);
    void Setarmv_tag_left_y(int ui_armv_tag_left_y);
    void Setarmv_tag_left_text(string ui_armv_tag_left_text);
    void Setarmv_value_right_x(int ui_armv_value_right_x);
    void Setarmv_value_right_y(int ui_armv_value_right_y);
    void Setarmv_value_right_text(string ui_armv_value_right_text);
    void Setgold_tag_left_x(int ui_gold_tag_left_x);
    void Setgold_tag_left_y(int ui_gold_tag_left_y);
    void Setgold_tag_left_text(string ui_gold_tag_left_text);
    void Setgold_value_right_x(int ui_gold_value_right_x);
    void Setgold_value_right_y(int ui_gold_value_right_y);
    void Setgold_value_right_text(string ui_gold_value_right_text);
    void Setwep_tag_left_x(int ui_wep_tag_left_x);
    void Setwep_tag_left_y(int ui_wep_tag_left_y);
    void Setwep_tag_left_text(string ui_wep_tag_left_text);
    void Setwep_value_right_x(int ui_wep_value_right_x);
    void Setwep_value_right_y(int ui_wep_value_right_y);
    void Setwep_value_right_text(string ui_wep_value_right_text);
    void Setarm_tag_left_x(int ui_arm_tag_left_x);
    void Setarm_tag_left_y(int ui_arm_tag_left_y);
    void Setarm_tag_left_text(string ui_arm_tag_left_text);
    void Setarm_value_right_x(int ui_arm_value_right_x);
    void Setarm_value_right_y(int ui_arm_value_right_y);
    void Setarm_value_right_text(string ui_arm_value_right_text);
    void Setexp_tag_left_x(int ui_exp_tag_left_x);
    void Setexp_tag_left_y(int ui_exp_tag_left_y);
    void Setexp_tag_left_text(string ui_exp_tag_left_text);
    void Setexp_value_right_x(int ui_exp_value_right_x);
    void Setexp_value_right_y(int ui_exp_value_right_y);
    void Setexp_value_right_text(string ui_exp_value_right_text);

    int Getname_tag_left_x();
    int Getname_tag_left_y();
    string Getname_tag_left_text();
    int Getname_value_right_x();
    int Getname_value_right_y();
    string Getname_value_right_text();
    int Getlevel_tag_left_x();
    int Getlevel_tag_left_y();
    string Getlevel_tag_left_text();
    int Getlevel_value_right_x();
    int Getlevel_value_right_y();
    string Getlevel_value_right_text();
    int Gethp_tag_left_x();
    int Gethp_tag_left_y();
    string Gethp_tag_left_text();
    int Gethp_value_right_x();
    int Gethp_value_right_y();
    string Gethp_value_right_text();
    int Getrace_tag_left_x();
    int Getrace_tag_left_y();
    string Getrace_tag_left_text();
    int Getrace_value_right_x();
    int Getrace_value_right_y();
    string Getrace_value_right_text();
    int Getstr_tag_left_x();
    int Getstr_tag_left_y();
    string Getstr_tag_left_text();
    int Getstr_value_right_x();
    int Getstr_value_right_y();
    string Getstr_value_right_text();
    int Getatk_tag_left_x();
    int Getatk_tag_left_y();
    string Getatk_tag_left_text();
    int Getatk_value_right_x();
    int Getatk_value_right_y();
    string Getatk_value_right_text();
    int Getdef_tag_left_x();
    int Getdef_tag_left_y();
    string Getdef_tag_left_text();
    int Getdef_value_right_x();
    int Getdef_value_right_y();
    string Getdef_value_right_text();
    int Getarmv_tag_left_x();
    int Getarmv_tag_left_y();
    string Getarmv_tag_left_text();
    int Getarmv_value_right_x();
    int Getarmv_value_right_y();
    string Getarmv_value_right_text();
    int Getgold_tag_left_x();
    int Getgold_tag_left_y();
    string Getgold_tag_left_text();
    int Getgold_value_right_x();
    int Getgold_value_right_y();
    string Getgold_value_right_text();
    int Getwep_tag_left_x();
    int Getwep_tag_left_y();
    string Getwep_tag_left_text();
    int Getwep_value_right_x();
    int Getwep_value_right_y();
    string Getwep_value_right_text();
    int Getarm_tag_left_x();
    int Getarm_tag_left_y();
    string Getarm_tag_left_text();
    int Getarm_value_right_x();
    int Getarm_value_right_y();
    string Getarm_value_right_text();
    int Getexp_tag_left_x();
    int Getexp_tag_left_y();
    string Getexp_tag_left_text();
    int Getexp_value_right_x();
    int Getexp_value_right_y();
    string Getexp_value_right_text();


private:
    int name_tag_left_x;
    int name_tag_left_y;
    string name_tag_left_text;
    int name_value_right_x;
    int name_value_right_y;
    string name_value_right_text;

    int level_tag_left_x;
    int level_tag_left_y;
    string level_tag_left_text;
    int level_value_right_x;
    int level_value_right_y;
    string level_value_right_text;

    int hp_tag_left_x;
    int hp_tag_left_y;
    string hp_tag_left_text;
    int hp_value_right_x;
    int hp_value_right_y;
    string hp_value_right_text;

    int race_tag_left_x;
    int race_tag_left_y;
    string race_tag_left_text;
    int race_value_right_x;
    int race_value_right_y;
    string race_value_right_text;

    int str_tag_left_x;
    int str_tag_left_y;
    string str_tag_left_text;
    int str_value_right_x;
    int str_value_right_y;
    string str_value_right_text;

    int atk_tag_left_x;
    int atk_tag_left_y;
    string atk_tag_left_text;
    int atk_value_right_x;
    int atk_value_right_y;
    string atk_value_right_text;

    int def_tag_left_x;
    int def_tag_left_y;
    string def_tag_left_text;
    int def_value_right_x;
    int def_value_right_y;
    string def_value_right_text;

    int armv_tag_left_x;
    int armv_tag_left_y;
    string armv_tag_left_text;
    int armv_value_right_x;
    int armv_value_right_y;
    string armv_value_right_text;

    int gold_tag_left_x;
    int gold_tag_left_y;
    string gold_tag_left_text;
    int gold_value_right_x;
    int gold_value_right_y;
    string gold_value_right_text;

    int wep_tag_left_x;
    int wep_tag_left_y;
    string wep_tag_left_text;
    int wep_value_right_x;
    int wep_value_right_y;
    string wep_value_right_text;

    int arm_tag_left_x;
    int arm_tag_left_y;
    string arm_tag_left_text;
    int arm_value_right_x;
    int arm_value_right_y;
    string arm_value_right_text;

    int exp_tag_left_x;
    int exp_tag_left_y;
    string exp_tag_left_text;
    int exp_value_right_x;
    int exp_value_right_y;
    string exp_value_right_text;
};

#endif // UIGROUP_H
