#include <iostream>
#include "uiGroup.h"
using namespace std;

uiGroup::uiGroup(){}

void uiGroup::Setname_tag_left_x(int ui_name_tag_left_x) { name_tag_left_x = ui_name_tag_left_x; }
void uiGroup::Setname_tag_left_y(int ui_name_tag_left_y) { name_tag_left_y = ui_name_tag_left_y; }
void uiGroup::Setname_tag_left_text(string ui_name_tag_left_text) {name_tag_left_text = ui_name_tag_left_text; }
void uiGroup::Setname_value_right_x(int ui_name_value_right_x) { name_value_right_x = ui_name_value_right_x; }
void uiGroup::Setname_value_right_y(int ui_name_value_right_y) { name_value_right_y = ui_name_value_right_y; }
void uiGroup::Setname_value_right_text(string ui_name_value_right_text) { name_value_right_text = ui_name_value_right_text; }
void uiGroup::Setlevel_tag_left_x(int ui_level_tag_left_x) { level_tag_left_x = ui_level_tag_left_x; }
void uiGroup::Setlevel_tag_left_y(int ui_level_tag_left_y) { level_tag_left_y = ui_level_tag_left_y; }
void uiGroup::Setlevel_tag_left_text(string ui_level_tag_left_text) { level_tag_left_text = ui_level_tag_left_text; }
void uiGroup::Setlevel_value_right_x(int ui_level_value_right_x) { level_value_right_x = ui_level_value_right_x; }
void uiGroup::Setlevel_value_right_y(int ui_level_value_right_y) { level_value_right_y = ui_level_value_right_y; }
void uiGroup::Setlevel_value_right_text(string ui_level_value_right_text) { level_value_right_text = ui_level_value_right_text; }
void uiGroup::Sethp_tag_left_x(int ui_hp_tag_left_x) { hp_tag_left_x = ui_hp_tag_left_x; }
void uiGroup::Sethp_tag_left_y(int ui_hp_tag_left_y) { hp_tag_left_y = ui_hp_tag_left_y; }
void uiGroup::Sethp_tag_left_text(string ui_hp_tag_left_text) { hp_tag_left_text = ui_hp_tag_left_text; }
void uiGroup::Sethp_value_right_x(int ui_hp_value_right_x) { hp_value_right_x = ui_hp_value_right_x; }
void uiGroup::Sethp_value_right_y(int ui_hp_value_right_y) { hp_value_right_y = ui_hp_value_right_y; }
void uiGroup::Sethp_bar_right_x(int ui_hp_bar_right_x) { hp_bar_right_x = ui_hp_bar_right_x; }
void uiGroup::Sethp_bar_right_y(int ui_hp_bar_right_y) { hp_bar_right_y = ui_hp_bar_right_y; }
void uiGroup::Sethp_value_right_text(string ui_hp_value_right_text) { hp_value_right_text = ui_hp_value_right_text; }
void uiGroup::Setrace_tag_left_x(int ui_race_tag_left_x) { race_tag_left_x = ui_race_tag_left_x; }
void uiGroup::Setrace_tag_left_y(int ui_race_tag_left_y) { race_tag_left_y = ui_race_tag_left_y; }
void uiGroup::Setrace_tag_left_text(string ui_race_tag_left_text) { race_tag_left_text = ui_race_tag_left_text; }
void uiGroup::Setrace_value_right_x(int ui_race_value_right_x) { race_value_right_x = ui_race_value_right_x; }
void uiGroup::Setrace_value_right_y(int ui_race_value_right_y) { race_value_right_y = ui_race_value_right_y; }
void uiGroup::Setrace_value_right_text(string ui_race_value_right_text) { race_value_right_text = ui_race_value_right_text; }
void uiGroup::Setstr_tag_left_x(int ui_str_tag_left_x) { str_tag_left_x = ui_str_tag_left_x; }
void uiGroup::Setstr_tag_left_y(int ui_str_tag_left_y) { str_tag_left_y = ui_str_tag_left_y; }
void uiGroup::Setstr_tag_left_text(string ui_str_tag_left_text) { str_tag_left_text = ui_str_tag_left_text; }
void uiGroup::Setstr_value_right_x(int ui_str_value_right_x) { str_value_right_x = ui_str_value_right_x; }
void uiGroup::Setstr_value_right_y(int ui_str_value_right_y) { str_value_right_y = ui_str_value_right_y; }
void uiGroup::Setstr_value_right_text(string ui_str_value_right_text) { str_value_right_text = ui_str_value_right_text; }
void uiGroup::Setatk_tag_left_x(int ui_atk_tag_left_x) { atk_tag_left_x = ui_atk_tag_left_x; }
void uiGroup::Setatk_tag_left_y(int ui_atk_tag_left_y) { atk_tag_left_y = ui_atk_tag_left_y; }
void uiGroup::Setatk_tag_left_text(string ui_atk_tag_left_text) { atk_tag_left_text = ui_atk_tag_left_text; }
void uiGroup::Setatk_value_right_x(int ui_atk_value_right_x) { atk_value_right_x = ui_atk_value_right_x; }
void uiGroup::Setatk_value_right_y(int ui_atk_value_right_y) { atk_value_right_y = ui_atk_value_right_y; }
void uiGroup::Setatk_value_right_text(string ui_atk_value_right_text) { atk_value_right_text = ui_atk_value_right_text; }
void uiGroup::Setdef_tag_left_x(int ui_def_tag_left_x) { def_tag_left_x = ui_def_tag_left_x; }
void uiGroup::Setdef_tag_left_y(int ui_def_tag_left_y) { def_tag_left_y = ui_def_tag_left_y; }
void uiGroup::Setdef_tag_left_text(string ui_def_tag_left_text) { def_tag_left_text = ui_def_tag_left_text; }
void uiGroup::Setdef_value_right_x(int ui_def_value_right_x) { def_value_right_x = ui_def_value_right_x; }
void uiGroup::Setdef_value_right_y(int ui_def_value_right_y) { def_value_right_y = ui_def_value_right_y; }
void uiGroup::Setdef_value_right_text(string ui_def_value_right_text) { def_value_right_text = ui_def_value_right_text; }
void uiGroup::Setarmv_tag_left_x(int ui_armv_tag_left_x) { armv_tag_left_x = ui_armv_tag_left_x; }
void uiGroup::Setarmv_tag_left_y(int ui_armv_tag_left_y) { armv_tag_left_y = ui_armv_tag_left_y; }
void uiGroup::Setarmv_tag_left_text(string ui_armv_tag_left_text) { armv_tag_left_text = ui_armv_tag_left_text; }
void uiGroup::Setarmv_value_right_x(int ui_armv_value_right_x) { armv_value_right_x = ui_armv_value_right_x; }
void uiGroup::Setarmv_value_right_y(int ui_armv_value_right_y) { armv_value_right_y = ui_armv_value_right_y; }
void uiGroup::Setarmv_value_right_text(string ui_armv_value_right_text) { armv_value_right_text = ui_armv_value_right_text; }
void uiGroup::Setgold_tag_left_x(int ui_gold_tag_left_x) { gold_tag_left_x = ui_gold_tag_left_x; }
void uiGroup::Setgold_tag_left_y(int ui_gold_tag_left_y) { gold_tag_left_y = ui_gold_tag_left_y; }
void uiGroup::Setgold_tag_left_text(string ui_gold_tag_left_text) { gold_tag_left_text = ui_gold_tag_left_text; }
void uiGroup::Setgold_value_right_x(int ui_gold_value_right_x) { gold_value_right_x = ui_gold_value_right_x; }
void uiGroup::Setgold_value_right_y(int ui_gold_value_right_y) { gold_value_right_y = ui_gold_value_right_y; }
void uiGroup::Setgold_value_right_text(string ui_gold_value_right_text) { gold_value_right_text = ui_gold_value_right_text; }
void uiGroup::Setwep_tag_left_x(int ui_wep_tag_left_x) { wep_tag_left_x = ui_wep_tag_left_x; }
void uiGroup::Setwep_tag_left_y(int ui_wep_tag_left_y) { wep_tag_left_y = ui_wep_tag_left_y; }
void uiGroup::Setwep_tag_left_text(string ui_wep_tag_left_text) { wep_tag_left_text = ui_wep_tag_left_text; }
void uiGroup::Setwep_value_right_x(int ui_wep_value_right_x) { wep_value_right_x = ui_wep_value_right_x; }
void uiGroup::Setwep_value_right_y(int ui_wep_value_right_y) { wep_value_right_y = ui_wep_value_right_y; }
void uiGroup::Setwep_value_right_text(string ui_wep_value_right_text) { wep_value_right_text = ui_wep_value_right_text; }
void uiGroup::Setarm_tag_left_x(int ui_arm_tag_left_x) { arm_tag_left_x = ui_arm_tag_left_x; }
void uiGroup::Setarm_tag_left_y(int ui_arm_tag_left_y) { arm_tag_left_y = ui_arm_tag_left_y; }
void uiGroup::Setarm_tag_left_text(string ui_arm_tag_left_text) { arm_tag_left_text = ui_arm_tag_left_text; }
void uiGroup::Setarm_value_right_x(int ui_arm_value_right_x) { arm_value_right_x = ui_arm_value_right_x; }
void uiGroup::Setarm_value_right_y(int ui_arm_value_right_y) { arm_value_right_y = ui_arm_value_right_y; }
void uiGroup::Setarm_value_right_text(string ui_arm_value_right_text) { arm_value_right_text = ui_arm_value_right_text; }
void uiGroup::Setexp_tag_left_x(int ui_exp_tag_left_x) { exp_tag_left_x = ui_exp_tag_left_x; }
void uiGroup::Setexp_tag_left_y(int ui_exp_tag_left_y) { exp_tag_left_y = ui_exp_tag_left_y; }
void uiGroup::Setexp_tag_left_text(string ui_exp_tag_left_text) { exp_tag_left_text = ui_exp_tag_left_text; }
void uiGroup::Setexp_value_right_x(int ui_exp_value_right_x) { exp_value_right_x = ui_exp_value_right_x; }
void uiGroup::Setexp_value_right_y(int ui_exp_value_right_y) { exp_value_right_y = ui_exp_value_right_y; }
void uiGroup::Setexp_value_right_text(string ui_exp_value_right_text) { exp_value_right_text = ui_exp_value_right_text; }

int    uiGroup::Getname_tag_left_x() { return name_tag_left_x; }
int    uiGroup::Getname_tag_left_y() { return name_tag_left_y; }
string uiGroup::Getname_tag_left_text() { return name_tag_left_text; }
int    uiGroup::Getname_value_right_x() { return name_value_right_x; }
int    uiGroup::Getname_value_right_y() { return name_value_right_y; }
string uiGroup::Getname_value_right_text() { return name_value_right_text; }
int    uiGroup::Getlevel_tag_left_x() { return level_tag_left_x; }
int    uiGroup::Getlevel_tag_left_y() { return level_tag_left_y; }
string uiGroup::Getlevel_tag_left_text() { return level_tag_left_text; }
int    uiGroup::Getlevel_value_right_x() { return level_value_right_x; }
int    uiGroup::Getlevel_value_right_y() { return level_value_right_y; }
string uiGroup::Getlevel_value_right_text() { return level_value_right_text; }
int    uiGroup::Gethp_tag_left_x() { return hp_tag_left_x; }
int    uiGroup::Gethp_tag_left_y() { return hp_tag_left_y; }
string uiGroup::Gethp_tag_left_text() { return hp_tag_left_text; }
int    uiGroup::Gethp_value_right_x() { return hp_value_right_x; }
int    uiGroup::Gethp_value_right_y() { return hp_value_right_y; }
string uiGroup::Gethp_value_right_text() { return hp_value_right_text; }
int    uiGroup::Gethp_bar_right_x() { return hp_bar_right_x; }
int    uiGroup::Gethp_bar_right_y() { return hp_bar_right_y; }

int    uiGroup::Getrace_tag_left_x() { return race_tag_left_x; }
int    uiGroup::Getrace_tag_left_y() { return race_tag_left_y; }
string uiGroup::Getrace_tag_left_text() { return race_tag_left_text; }
int    uiGroup::Getrace_value_right_x() { return race_value_right_x; }
int    uiGroup::Getrace_value_right_y() { return race_value_right_y; }
string uiGroup::Getrace_value_right_text() { return race_value_right_text; }
int    uiGroup::Getstr_tag_left_x() { return str_tag_left_x; }
int    uiGroup::Getstr_tag_left_y() { return str_tag_left_y; }
string uiGroup::Getstr_tag_left_text() { return str_tag_left_text; }
int    uiGroup::Getstr_value_right_x() { return str_value_right_x; }
int    uiGroup::Getstr_value_right_y() { return str_value_right_y; }
string uiGroup::Getstr_value_right_text() { return str_value_right_text; }
int    uiGroup::Getatk_tag_left_x() { return atk_tag_left_x; }
int    uiGroup::Getatk_tag_left_y() { return atk_tag_left_y; }
string uiGroup::Getatk_tag_left_text() { return atk_tag_left_text; }
int    uiGroup::Getatk_value_right_x() { return atk_value_right_x; }
int    uiGroup::Getatk_value_right_y() { return atk_value_right_y; }
string uiGroup::Getatk_value_right_text() { return atk_value_right_text; }
int    uiGroup::Getdef_tag_left_x() { return def_tag_left_x; }
int    uiGroup::Getdef_tag_left_y() { return def_tag_left_y; }
string uiGroup::Getdef_tag_left_text() { return def_tag_left_text; }
int    uiGroup::Getdef_value_right_x() { return def_value_right_x; }
int    uiGroup::Getdef_value_right_y() { return def_value_right_y; }
string uiGroup::Getdef_value_right_text() { return def_value_right_text; }
int    uiGroup::Getarmv_tag_left_x() { return armv_tag_left_x; }
int    uiGroup::Getarmv_tag_left_y() { return armv_tag_left_y; }
string uiGroup::Getarmv_tag_left_text() { return armv_tag_left_text; }
int    uiGroup::Getarmv_value_right_x() { return armv_value_right_x; }
int    uiGroup::Getarmv_value_right_y() { return armv_value_right_y; }
string uiGroup::Getarmv_value_right_text() { return armv_value_right_text; }
int    uiGroup::Getgold_tag_left_x() { return gold_tag_left_x; }
int    uiGroup::Getgold_tag_left_y() { return gold_tag_left_y; }
string uiGroup::Getgold_tag_left_text() { return gold_tag_left_text; }
int    uiGroup::Getgold_value_right_x() { return gold_value_right_x; }
int    uiGroup::Getgold_value_right_y() { return gold_value_right_y; }
string uiGroup::Getgold_value_right_text() { return gold_value_right_text; }
int    uiGroup::Getwep_tag_left_x() { return wep_tag_left_x; }
int    uiGroup::Getwep_tag_left_y() { return wep_tag_left_y; }
string uiGroup::Getwep_tag_left_text() { return wep_tag_left_text; }
int    uiGroup::Getwep_value_right_x() { return wep_value_right_x; }
int    uiGroup::Getwep_value_right_y() { return wep_value_right_y; }
string uiGroup::Getwep_value_right_text() { return wep_value_right_text; }
int    uiGroup::Getarm_tag_left_x() { return arm_tag_left_x; }
int    uiGroup::Getarm_tag_left_y() { return arm_tag_left_y; }
string uiGroup::Getarm_tag_left_text() { return arm_tag_left_text; }
int    uiGroup::Getarm_value_right_x() { return arm_value_right_x; }
int    uiGroup::Getarm_value_right_y() { return arm_value_right_y; }
string uiGroup::Getarm_value_right_text() { return arm_value_right_text; }
int    uiGroup::Getexp_tag_left_x() { return exp_tag_left_x; }
int    uiGroup::Getexp_tag_left_y() { return exp_tag_left_y; }
string uiGroup::Getexp_tag_left_text() { return exp_tag_left_text; }
int    uiGroup::Getexp_value_right_x() { return exp_value_right_x; }
int    uiGroup::Getexp_value_right_y() { return exp_value_right_y; }
string uiGroup::Getexp_value_right_text() { return exp_value_right_text; }
