<?php

//translator ready
//addnews ready
//mail ready

define("ALLOW_ANONYMOUS",true);
define("OVERRIDE_FORCED_NAV",true);
define("IS_INSTALLER",true);
if (!file_exists("dbconnect.php")){
	define("DB_NODB",true);
}
require_once("common.php");
if (file_exists("dbconnect.php")){
	require("dbconnect.php");
}
$noinstallnavs=false;

tlschema("installer");

$stages=array(
	"1. Introduction",
	"2. License Agreement",
	"3. I Agree",
	"4. Database Info",
	"5. Test Database",
	"6. Examine Database",
	"7. Write dbconnect file",
	"8. Install Type",
	"9. Set Up Modules",
	"10. Build Tables",
	"11. Admin Accounts",
	"12. Done!",
);

$recommended_modules = array(
	"abigail",
	"breakin",
	"calendar",
	"cedrikspotions",
//	"cities", //I don't think this is good for most people.
	"collapse",
	"crazyaudrey",
	"crying",
	"dag",
	"darkhorse",
	"distress",
	"dragonattack",
	"drinks",
	"drunkard",
	"expbar",
	"fairy",
	"findgem",
	"findgold",
	"foilwench",
	"forestturn",
	"game_dice",
	"game_stones",
	"gardenparty",
	"ghosttown",
	"glowingstream",
	"goldmine",
	"grassyfield",
	"haberdasher",
	"healthbar",
	"innchat",
	"kitchen",
	"klutz",
	"lottery",
	"lovers",
	"oldman",
	"outhouse",
	"peerpressure",
	"petra",
	"racedwarf",
	"raceelf",
	"racehuman",
	"racetroll",
	"riddles",
	"salesman",
	"sethsong",
	"smith",
	"soulgem",
	"spa",
	"specialtydarkarts",
	"specialtymysticpower",
	"specialtythiefskills",
	"statue",
	"stocks",
	"stonehenge",
	"thieves",
	"tutor",
	"tynan",
	"waterfall",
);

$sql_upgrade_statements = array(
	"-1"=>array(), //needed just as a placeholder for new installs.
	"0.9"=>array(

		"INSERT INTO " . db_prefix("creatures") . " VALUES (1,'Thieving Kender',1,'Whirling Hoopak','You only wish you could pickpocket your money back from the thief.',NULL,36,14,10,1,1,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (2,'Rude Student',1,'Worn Textbook','You have sent this student to permanent detention',NULL,36,14,10,1,1,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (3,'Baby Unicorn',1,'Blunt Horn','You feel like a real jerk killing something so pretty',NULL,36,14,10,1,1,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (4,'Small Purple Mouse',1,'Lashing pink tail','It is written in black and white: this strange technicolor mouse is no more',NULL,36,14,10,1,1,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (5,'Grunting Piggy',1,'Wiggly Snout','Mmm...Bacon',NULL,36,14,10,1,1,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (6,'Dumb Old Eyesore',2,'Nagging complaints','All she ever did was nag...nag...nag...',NULL,97,24,21,3,3,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (7,'Pygmy Marmoset',2,'Pieces of treebark','The strange little monkey falls from the trees and lies still.',NULL,97,24,21,3,3,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (8,'Burly Man',15,'Amazing Absorbency','Fantasize, fantasize about Burly ...Eeeh, Eeeh, Eeeh!',NULL,531,189,155,29,21,14,'Bluspring', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (9,'Screaming Banshee',2,'Hauntingly Beautiful Voice','You plunge your weapon into her breast, silencing her song',NULL,97,24,21,3,3,14,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (10,'Ursus Minor',2,'Twinkling Lights','After an astronomical battle, Ursus Minor is the one seeing stars',NULL,97,24,21,3,3,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (11,'Stone Troll',2,'Gaping  Maw','That troll is stone cold ugly.',NULL,97,24,21,3,3,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (12,'Slithering asp',2,'Hypnotic eyes','You break the deadly gaze of the snake to save your own life',NULL,97,24,21,3,3,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (13,'Windan The Barbarian',2,'Feathered Spear','He really was just a feather-weight',NULL,97,24,21,3,3,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (14,'Studious young sorceror',2,'Newly memorized spells','Perhaps she should have studied harder.',NULL,97,24,21,3,3,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (15,'Four and Twenty Blackbirds',3,'Freshly Baked Pies','Now isn\'t this a dainty dish to set before a king?',NULL,148,34,32,5,4,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (16,'Amazon',3,'Bow and Arrow','The beautiful warrior lass has lost a battle for the first time.',NULL,148,34,32,5,4,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (17,'Overbearing mother',3,'9pm Curfew','With one fell swoop you save your social life!',NULL,148,34,32,5,4,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (18,'Huge Bald Programmer',3,'Shining Forehead','You feel as if you have seen this man before in the village',NULL,148,34,32,5,4,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (19,'Someone\'s Grandfather',3,'Stories that go nowhere','This reminds you of the time you needed a new heel for your shoe',NULL,148,34,32,5,4,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (20,'Juvenile Delinquent',3,'Poor Attitude','With a satisfying thump, you knock the smirk right off his face',NULL,148,34,32,5,4,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (21,'Beautiful Woodland Sprite',3,'Kindness and tranquility','You really cut that wood sprite down to size',NULL,148,34,32,5,4,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (22,'Society Belle',3,'Southern Charm','Now she will never be on time for the ball!',NULL,148,34,32,5,4,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (23,'Giant Goldfish Cracker',3,'Annoying Commercial Jingles','Now *there* is a fish that smiled till you bit his head off.',NULL,148,34,32,5,4,14,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (24,'Angry Mob',4,'Torches','There is no justice for an angry mob',NULL,162,45,43,7,6,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (25,'Polar Bear',4,'Terrible claws','That bear really needed an attitude adjustment',NULL,162,45,43,7,6,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (26,'Decaying Skeleton',4,'Rusty Sword','His leg ought to make a good toy for your dog.',NULL,162,45,43,7,6,15,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (27,'Willie the Wonder Hampster',4,'Nuclear Sunflower Seeds','You smile a grim smile at Willie and quietly munch on some seeds',NULL,162,45,43,7,6,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (28,'Winged Demon Of Death',4,'Red Glare','You cut off the Demon\'s head, to be sure of its death.',NULL,162,45,43,7,6,15,'foilwench', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (29,'Small Dragon',4,'Hot air','For one moment you thought THIS was the Green Dragon, but alas not.',NULL,162,45,43,7,6,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (30,'Monstrous Dustbunny',4,'Sneezing fits','You sweep the poor bunny under the rug when no one is looking',NULL,162,45,43,7,6,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (31,'Small Rabbit',4,'Sharp Pointy Teeth','To think you almost ran away!',NULL,162,45,43,7,6,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (32,'Mature Unicorn',5,'Powerful Horn','A unicorn is a thing of beauty, even in death',NULL,198,55,53,9,7,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (33,'Gnome Necromancer',5,'Skeleton Familiar','Once you killed its familiar that Gnome was really weak.',NULL,198,55,53,9,7,15,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (34,'Purple Dinosaur',5,'Helpful Nature','There seems to be a person inside that strange dino.  You wonder why.',NULL,198,55,53,9,7,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (35,'Orc Emmisary',5,'Diplomacy','You never were the diplomatic type.',NULL,198,55,53,9,7,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (36,'Dark Spiritling',5,'Dark Magic','The spiritling gasps a final breath as you end its pitiful life',NULL,198,55,53,9,7,15,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (37,'Enchanted Toilet',5,'Ninja Flushing Action','That was just weird',NULL,198,55,53,9,7,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (38,'Giant Water Elemental',5,'Torrential Downpours','The giant creature is reduced a meager spring shower',NULL,198,55,53,9,7,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (39,'Violins',5,'Off-Key notes','Won\'t someone PLEASE stop the violins?',NULL,198,55,53,9,7,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (40,'Whirled Peas',5,'Green Slime','We should all pray for whirled peas.',NULL,198,55,53,9,7,15,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (41,'Magic Mushroom',6,'Swirling Colors','Guess you don\'t need to go ask Alice now',NULL,234,66,64,11,8,16,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (42,'Invisible Man',6,'Something Invisible and Sharp','You really aren\'t sure if it is dead, or just hiding...after all it is invisible',NULL,234,66,64,11,8,16,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (43,'Clown Of Death',6,'Balloon Animals from Beyond','You give the clown\'s nose a honk just for fun before you leave',NULL,234,66,64,11,8,16,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (44,'Heart of Stone',6,'Unromantic Thoughts','Aww, now look, you broke its heart!',NULL,234,66,64,11,8,16,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (45,'Troll Warrior',6,'Steel Broadsword','Wow, he smelled bad enough alive, can you imagine how he\'ll smell tomorrow?',NULL,234,66,64,11,8,16,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (46,'Bettie the Amazing Kung-Fu Butterfly',6,'Stupendous Kung-Fu Wings','You survived a battle to the death with a butterfly.  You must be so proud.',NULL,234,66,64,11,8,16,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (47,'Golden Goose',6,'14 Karat Gold Eggs','You have slain the goose but it is too heavy to take back to town.  All that wealth wasted.',NULL,234,66,64,11,8,16,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (48,'Black Tiger',6,'Claws','You ponder the tiger\'s body thinking what a good rug it might make',NULL,234,66,64,11,8,16,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (49,'Lambert the Sheepish Lion',6,'Timid Growling','You marched in like a lion and he died like a lamb',NULL,234,66,64,11,8,16,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (50,'Marsha of the Jungle',7,'Trained Monkeys','Poor Marsha, she thought those monkeys were better trained',NULL,268,77,74,13,10,17,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (51,'Moe',7,'Two Knives','Maybe those knives weren\'t so great',NULL,268,77,74,13,10,17,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (52,'Coffin',7,'Terrifying Premonitions','Best way to get rid of the coffin is Robitussin.',NULL,268,77,74,13,10,17,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (53,'Green Alligator',7,'Crushing Jaws','Crikey!  That thing could have killed you!',NULL,268,77,74,13,10,17,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (54,'Lindsey, Daughter of Erin the Ninja Squirrel',7,'A peanut shooter','All these squirrels are nuts.',NULL,268,77,74,13,10,17,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (55,'Wizarding School Senior Student',7,'Memory Charm','Drat!  He took your memory before you killed him.  Who are you anyway?',NULL,268,77,74,13,10,17,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (56,'Enchanted Laundry Basket',7,'Stinky Socks of Terror','So that\'s what happens to lost socks!',NULL,268,77,74,13,10,17,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (57,'Carrot Top',7,'Phone Company Slogans','That has got to be the most satisfying kill you ever made.',NULL,268,77,74,13,10,17,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (58,'Macintosh Computer',7,'Amazingly Bright Colors','So THAT\'S what happens when you right-click a Mac.',NULL,268,77,74,13,10,17,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (59,'Interior Designer',8,'Color-coordinating Sword and Shield','You didn\'t like his style',NULL,302,89,84,15,11,19,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (60,'Daughter of the Devil',8,'Sinfully Good Looks','She is the girl your mom always warned you about.',NULL,302,89,84,15,11,19,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (61,'Wild Horses',8,'Dragging','I guess the saying is true, Wild Horse can\'t drag you away',NULL,302,89,84,15,11,19,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (62,'Steam Elemental',8,'Scalding jets of air','There was just enough steam left to make an espresso',NULL,302,89,84,15,11,19,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (63,'Gordon the Cheese Eater',8,'Odiferous Nature','You sure cut that cheese....eater',NULL,302,89,84,15,11,19,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (64,'Narcoleptic',8,'Drowsiness','This narcoleptic won\'t be waking up anytime soon',NULL,302,89,84,15,11,19,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (65,'Swarm of Bees',8,'Stinging','You feel like a pincushion, but you are alive',NULL,302,89,84,15,11,19,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (66,'Halfling Mage',8,'Painful Spells','That fight wasn\'t half as difficult as you thought it would be',NULL,302,89,84,15,11,19,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (67,'Citizen of Eythgim Village',9,'Slurs','Geeze, what did you ever do to him?',NULL,336,101,94,17,13,21,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (68,'Old Hag',9,'Red red rose','It is her turn to sleep an enchanted sleep',NULL,336,101,94,17,13,21,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (69,'Charging Buffalo',9,'Stampeding Hoofs','Do you know how to stop a charging buffalo?  Take away his credit card!',NULL,336,101,94,17,13,21,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (70,'Pawn',9,'Simple tactics','Well, that was a bad move',NULL,336,101,94,17,13,21,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (71,'Romulan',9,'Wrong-Genre Confusion','You think to yourself they look tougher on TV',NULL,336,101,94,17,13,21,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (72,'Large Griffon',9,'Beak and Claws','The mythical creature is no more',NULL,336,101,94,17,13,21,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (73,'Cliche Bond Movie Villian',9,'Cell-phone of Death','Well, really, who throws a cell phone?  I mean, that really, really hurt!',NULL,336,101,94,17,13,21,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (74,'Fuzzy Ferret',9,'Disarming Cuteness','Who knew ferrets were so violent!',NULL,336,101,94,17,13,21,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (75,'Starving Artist',9,'Pointy Paintbrushes','This guy really painted himself into a corner',NULL,336,101,94,17,13,21,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (76,'Guard from Eythgim Village',10,'Rapier','The people from that village seem angry!',NULL,369,114,105,19,14,24,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (77,'Garden Gnome',10,'Painful Tackiness','Stupid garden gnomes, what are they doing in the forest anyway',NULL,369,114,105,19,14,24,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (78,'Chicken',10,'Squawking','Good fortune smiles upon you- you will eat well tonight',NULL,369,114,105,19,14,24,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (79,'Marksman',10,'Deadly Aim','He took so long to aim, you just walked up and kicked him',NULL,369,114,105,19,14,24,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (80,'Enchanted Tissue Box',10,'Cold Germs','You pick up the box and put it in your pocket.  You never know when a tissue might come in handy',NULL,369,114,105,19,14,24,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (81,'Ghostly Woodsman',10,'Phantom Axe','You aren\'t sure how you did it, but you killed something that was already dead.  Good for you.',NULL,369,114,105,19,14,24,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (82,'Zombie',10,'Rotting Flesh','He really went to pieces, didn\'t he?',NULL,369,114,105,19,14,24,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (83,'Fortula the Plains Cat',10,'Claws and Teeth','That plains cat is now plain dead',NULL,369,114,105,19,14,24,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (84,'Erin the Ninja Squirrel',10,'Acorn tossing madness','That squirrel was a little crazy',NULL,369,114,105,19,14,24,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (85,'Bluebird of Happiness',11,'Uplifting Melody','Happiness is over-rated anyway',NULL,402,127,115,21,15,27,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (86,'Potato Newscaster',11,'Personal Opinions','It\'s ok, he was just a common \'tater',NULL,402,127,115,21,15,27,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (87,'Pygmy Dragon',11,'Fire Breath','You hope he wasn\'t a relative of the Green Dragon',NULL,402,127,115,21,15,27,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (88,'Zealous Photographer',11,'Flashing Lights','The things beautiful people have to put up with.',NULL,402,127,115,21,15,27,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (89,'Gary Larson',11,'Strange Cartoons','You still don\'t get it.',NULL,402,127,115,21,15,27,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (90,'Soldier from Eythgim Village',11,'Battle Cry','Eythgim seems to be waging a personal war with you',NULL,402,127,115,21,15,27,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (91,'80\'s Glam Rocker',11,'Blinding Makeup','You know your motto, Live and let die.',NULL,402,127,115,21,15,27,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (92,'Vigilante',11,'Sack of Doorknobs','This carnage disgusts you',NULL,402,127,115,21,15,27,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (93,'The Devil',11,'Eternal Damnation','For being the Devil, he really wasn\'t so hot.',NULL,402,127,115,21,15,27,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (94,'Mercenary',12,'Blood-chilling stare','You could use an ale',NULL,435,141,125,23,17,31,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (95,'Magic Mirror',12,'Flattering Remarks','Mirror, Mirror, on the Ground, it is your death that you have found.',NULL,435,141,125,23,17,31,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (96,'Broadway Extra',12,'Memorable Showtunes','This extra is really on her own now',NULL,435,141,125,23,17,31,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (97,'Butter the Sprite',12,'Magic Pixie Dust','Butter?  What kind of a name is Butter?',NULL,435,141,125,23,17,31,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (98,'Father Time',12,'Old Age','Your victory is not comforting, you know he will still catch up to you',NULL,435,141,125,23,17,31,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (99,'Eythgim Village Archers',12,'Flaming Arrows','The tree is  burning, you\'d better try to put it out.',NULL,435,141,125,23,17,31,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (100,'Animate Stormcloud',12,'Lightning','The storm is no more, you can see the light of day peeking through the last of the clouds',NULL,435,141,125,23,17,31,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (101,'Three Toed Sloth',12,'Slow responses','Your swift moves were too fast for this sloth',NULL,435,141,125,23,17,31,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (102,'Death',12,'Cold Grasp','There it is!  Death!!!!!',NULL,435,141,125,23,17,31,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (103,'Cerberus',13,'Three drooling maws','Each one\'s breath was worse than the last',NULL,467,156,135,25,18,36,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (104,'Man from the deep deep, dark dark, deep dark wood',13,'Snarling and biting','Now the creature from the deep, deep, dark, dark, deep, dark woods is finally dead',NULL,467,156,135,25,18,36,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (105,'Devil in a blue dress',13,'Alluring Promises','You really prefer black dresses anyway.',NULL,467,156,135,25,18,36,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (106,'Giant',13,'Smashing Club','Geeze, he almost fell on you!',NULL,467,156,135,25,18,36,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (107,'Commander of the Eythgim Army',13,'Winning Tactics','You have bested their army by killing its master.',NULL,467,156,135,25,18,36,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (108,'Ice Dragon',13,'Frost Breath','You defeated him, but caught a cold.',NULL,467,156,135,25,18,36,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (109,'Pushmi Pullyew',13,'Conflictory Arguments','That strange creature couldn\'t tell if it was coming or going.',NULL,467,156,135,25,18,36,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (110,'Whale',13,'Tail','You know Violet isn\'t going to believe a Whale attacked you in the forest',NULL,467,156,135,25,18,36,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (111,'Gorma The Leper',13,'Contagious Disease','It looks like the leper\'s fighting strategy has fallen apart...',NULL,467,156,135,25,18,36,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (112,'Samurai Master',14,'Daisho','You bow to the fallen master before you walk away',NULL,499,172,145,27,20,42,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (113,'Bartender',14,'Duck','That\'s not a Duck!  It\'s a Chicken!',NULL,499,172,145,27,20,42,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (114,'Prince of Eythgim Village',14,'Bribes of gold','You are not easily bribed, and he was a mortal enemy',NULL,499,172,145,27,20,42,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (115,'Loch Ness Monster',14,'Shocking appearance','Why in the world would that monster be in this forest.  You must have been dreaming!',NULL,499,172,145,27,20,42,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (116,'Fuzzie Wuzzie',14,'Male Pattern Baldness','Fuzzie Wuzzie wasn\'t very fuzzie, was he?',NULL,499,172,145,27,20,42,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (117,'Princess of Eythgim Village',15,'Beguiling Words','She tried to tempt you, but you resisted.',NULL,531,189,155,29,21,42,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (118,'Ugly Harpy',14,'Poisonus Breath','Her breath was worse than her bite',NULL,499,172,145,27,20,42,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (119,'Field Mouse',14,'Chewing','That was some powerful mouse!',NULL,499,172,145,27,20,42,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (120,'Monarch of Eythgim Village',16,'Royal Commands','I guess this makes you king of their Village.',NULL,563,207,166,31,22,49,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (121,'Cyclops Warrior',15,'Fire Eye','The dead Cyclops\' one eye stares at you blankly.',NULL,531,189,155,29,21,49,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (122,'Cupid',15,'Pink Arrows of Love','You have slain Cupid, you shall never find true love',NULL,531,189,155,29,21,49,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (123,'Tabloid Writer',15,'Far-fetched stories','If you ask me, SHE was the six-armed alien who gave birth to the world\'s largest infant Elvis impersonator',NULL,531,189,155,29,21,49,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (124,'Evil Wizard',15,'Tormented Souls','You have set the tortured souls free',NULL,531,189,155,29,21,49,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (125,'Artemis, Goddess of the Hunt',15,'Winged Stags','The moon itself shall weep for the slain Artemis',NULL,531,189,155,29,21,49,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (126,'Centaur Archer',15,'Deadly marksmanship','The twisted man-beast lies still',NULL,531,189,155,29,21,49,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (127,'Mime',15,'Something imaginary','His death is a rather sad charade',NULL,531,189,155,29,21,49,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (128,'Chili Chef',15,'Insanity Peppers','Man, that\'s good chili',NULL,531,189,155,29,21,49,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (129,'Brownie',16,'Minuscule weapons','The tiny warrior dies with a faint squeal',NULL,563,207,166,31,22,57,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (130,'Darkness',16,'Self-induced terror','You are afraid of the dark no longer',NULL,563,207,166,31,22,57,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (131,'Mountain King',16,'God-like fury','The King has died, long live the King',NULL,563,207,166,31,22,57,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (134,'Loneliness',17,'Silence','What is the sound of one hand clapping?','What is the sound of one hand clapping?',36,0,1,0,0,0,NULL, 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (135,'Loneliness',18,'Silence','What is the sound of one hand clapping?','What is the sound of one hand clapping?',0,0,1,0,25,0,NULL, 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (136,'Le Chat dans le chapeau',15,'Rhyming Nonsense','In spanish El Gato en el sombrero','',531,189,155,29,21,0,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (138,'Whopper With Cheese',8,'Abundant Cholesterol','This is one whopper that won\'t show up on your hips tomorrow.',NULL,302,89,84,15,11,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (139,'Swarming Ladybugs',3,'Stinking Residue','Those Ladybugs weren\'t very ladylike.',NULL,148,34,32,5,4,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (140,'Football Fan',6,'Raucous Cheers','This fan doesn\'t have much to cheer about.',NULL,234,66,64,11,8,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (141,'King Agrippa',13,'Flaming Wingnuts','As you stare at his smoking corpse, you marvel at the ineffectiveness of flaming wingnuts.',NULL,467,156,135,25,18,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (142,'Cherubically Charming Child',1,'Curious Questions','You think it was the alliteration that did him in.',NULL,36,14,10,1,1,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (143,'Haberdasher',5,'Heavy Hat','Hats have gone out of style anyway.',NULL,198,55,53,9,7,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (144,'Rush Hour Driver',11,'Road Rage','It was a no-win situation, speeding on these forest paths.  The driver had it coming.',NULL,402,127,115,21,15,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (145,'Sorority Girl in Nightie',7,'Pillow Fighting Action','It\'s too bad she\'s dead . . . you liked her action.',NULL,268,77,74,13,10,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (146,'Ulysses WÃ¶lfgang',14,'Ridiculous Lies','Death to lies!  Death to Ulysses WÃ¶lfgang',NULL,499,172,145,27,20,NULL,'Joe', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (147,'Crazy Audrey',9,'Ravenous Kittens','With a well placed stomp, Audrey and the kittens are no more.',NULL,336,101,94,17,13,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (148,'Shining Happy People',5,'Hand Holding Terror','They just wanted to be your friend.  You meanie.',NULL,198,55,53,9,7,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (149,'Elsabutt',8,'Gravitational Pull','This is indeed a grave situation',NULL,302,89,84,15,11,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (150,'Mr. Bear',2,'Overwhelming Sleepiness','Mr. Bear was too tired to finish playing with you and went back to napping',NULL,97,24,21,3,3,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (151,'Everquest Junkie',12,'1337 Sp34k','D00d U pwned that guy!',NULL,435,141,125,23,17,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (152,'Little Cocobean',4,'Her Special Roast','She really made your heart race and pound, but now she has crumbled to the ground',NULL,162,45,43,7,6,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (153,'Humongous Hairball',5,'Incredible Drain-Clogging Power','The hairball and all its accompanying gook have been washed out to sea!',NULL,198,55,53,9,7,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (154,'Iron Chef',4,'Sizzling Eel Flambe!','You have rendered the Chef Ironless!  He\'s now simply a copper/tin alloy!',NULL,162,45,43,7,6,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (155,'The Government',7,'Taxes','That\'s a tax return you\'ll be taking to the bank!',NULL,268,77,74,13,10,NULL,'Bluspring', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (156,'Bar Fly',1,'Alcoholism','Good thing you got him before cirrhosis did!',NULL,36,14,10,1,1,NULL,'Bluspring', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (157,'Methane Man',7,'Unfriendly Gasses','Must have been that bean he ate!',NULL,268,77,74,13,10,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (158,'Wooly Mammoth',8,'Wildebeest Sidekick','You climb atop the Mammoth\'s remains and declare yourself king (or queen) for a day!',NULL,302,89,84,15,11,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (159,'Nasty Nevin',10,'Bossy Mom','Wrecked\'em?  Darn near killed \'em!',NULL,369,114,105,19,14,NULL,'Joe', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (160,'the Gar Man',3,'Jar of Cotton Balls','There is but one Gar Man!  And now he\'s just fluff!',NULL,148,34,32,5,4,NULL,'foilwench', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (161,'Hiker',1,'Walking Stick','His last words were \"...I must protect the dragon\"',NULL,36,14,10,1,1,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (162,'Camper',2,'Marshmallow-roasting Stick','With her dying breath she gasps \"...and I never saw the dragon.\"',NULL,97,24,21,3,3,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (163,'Forest Ranger',3,'Hunting Rifle','In his pack you find a copy of \"Dragon Seeking for Dummies\"',NULL,148,34,32,5,4,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (164,'Tree-Hugger',4,'Propaganda Leaflets','The leaflett reads \"Who Will Protect The Helpless Dragon?\"',NULL,162,45,43,7,6,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (165,'Forest Dwelling Hermit',5,'Hand-Made Sling','He speaks only these words as he dies: \"You must leave the Dragon\'s Forest.\"',NULL,198,55,53,9,7,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (166,'Member of Dragon Lovers Anonymous',6,'Stuffed Dragon Toy','When one wears a pin saying \"Dragon Lovers Anonymous\" they really are not as anonomous as they might think',NULL,234,66,64,11,8,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (167,'Initiate Dragon Watcher',7,'Binoculars','All he could say was \"Shhh, you are scaring the dragons!\"',NULL,268,77,74,13,10,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (168,'Dragon Watcher, Junior Class',8,'Annoyance','You find a dragon-watching textbook in his backpack.',NULL,302,89,84,15,11,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (169,'Dragon-watcher Senior Class',9,'Spelunking Equipment','You find a copy of \"Cave-Dwelling Dragons, and Where to Find Them.\" in his pack',NULL,336,101,94,17,13,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (170,'Master Dragon Watcher',10,'Stealth','You wonder who watches the watchers',NULL,369,114,105,19,14,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (171,'Initiate Dragon Tamer',11,'10-foot dragon pole','Good thing for you that pole only works on 10-foot dragons!',NULL,402,127,115,21,15,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (172,'Junior Dragon Tamer',12,'Large Whip','If he cannot tell the difference between you and a dragon, he has much work to do',NULL,435,141,125,23,17,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (173,'Senior Dragon Tamer',13,'Very Large Hoop','You regret killing him, you wanted to see him make a dragon jump through that hoop',NULL,467,156,135,25,18,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (174,'Master Dragon Tamer',14,'Tame Dragon','Once you killed the master, the dragon ran away',NULL,499,172,145,27,20,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (175,'Dragon Rider in Training',15,'Mechanical Bull','They learn to ride dragons using a mechanical bull?',NULL,531,189,155,29,21,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (176,'Dragon Rider',16,'Flying Dragon','A well-aimed strike grounds the flying dragon and his rider',NULL,563,207,166,31,22,NULL,'Appleshiner', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (177,'Batling',1,'Tiny flapping wings','Silly batling',NULL,36,14,10,1,1,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (178,'Small Bat',2,'Slightly venomous fangs','The small mammal falls to the ground',NULL,97,24,21,3,3,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (179,'Medium Sized Bat',3,'Screeching Cries','You killed it just to shut it up.',NULL,148,34,32,5,4,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (180,'Large Bat',4,'Guano','You feel the need to take a bath',NULL,162,45,43,7,6,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (181,'Giant Bat',5,'Clinging and Biting','Why do movie bats always fly at people\'s hair?',NULL,198,55,53,9,7,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (182,'Vampire Batling',6,'Pricking teeth','He resembled a mosquito more than a vampire bat',NULL,234,66,64,11,8,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (183,'Small Vampire Bat',7,'Deadly Fangs','You kick at the annoying pest as it lies on the ground',NULL,268,77,74,13,10,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (184,'Medium Sized Vampire Bat',8,'Echoing Sounds','Who decides that this bat is a \"Medium\"?  Maybe he is a giant bat who hasn\'t bloomed yet.',NULL,302,89,84,15,11,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (185,'Huge Vampire Bat',9,'Blood-Sucking','You gave more blood to the Red Cross',NULL,336,101,94,17,13,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (186,'Vampire in Bat Form',10,'Bad Romanian Accent','\"I vant to suk your blooood!\"',NULL,369,114,105,19,14,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (187,'Vampire-Bat Prince',11,'Death Grip','You thought bats were republicans.',NULL,402,127,115,21,15,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (188,'Vampire Bat King',12,'Red Eyes','You decide to leave before the rest of the bats come to find their king',NULL,435,141,125,23,17,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (189,'Sorcerous Vampire',13,'Petrifying Spells','A cold shiver goes down your spine.  You would rather be with Violet',NULL,467,156,135,25,18,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (221,'Vampirus,the Bat God',16,'Godly Power','You are even more god-like then he',NULL,563,207,166,31,22,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (220,'Frenzied vampire bats',15,'Numerous attacks','Why are there so many darn bats in this forest?',NULL,531,189,155,29,21,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (219,'Seductive Vampiress',14,'Sultry Moves','It was a shame to kill her.',NULL,499,172,145,27,20,NULL,'Appleshiner', 1, 1)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (1,'Mireraband',1,'Small Dagger','Well done %w`&, I should have guessed you\'d grown some.','As I thought, %w`^, your skills are no match for my own!',NULL,NULL,12,2,2)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (2,'Fie',2,'Short Sword','Well done %w`&, you really know how to use your %x.','You should have known you were no match for my %X',NULL,NULL,22,4,4)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (3,'Glynyc',3,'Hugely Spiked Mace','Aah, defeated by the likes of you!  Next thing you know, Mireraband will be hunting me down!','Haha, maybe you should go back to Mireraband\'s class.',NULL,NULL,33,6,6)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (4,'Guth',4,'Spiked Club','Ha!  Hahaha, excellent fight %w`&!  Haven\'t had a battle like that since I was in the RAF!','Back in the RAF, we\'d have eaten the likes of you alive!  Go work on your skills some old boy!',NULL,NULL,44,8,8)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (5,'Unélith',5,'Thought Control','Your mind is greater than mine.  I concede defeat.','Your mental powers are lacking.  Meditate on this failure and perhaps some day you will defeat me.',NULL,NULL,55,10,10)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (6,'Adwares',6,'Dwarven Battle Axe','Ach!  Y\' do hold yer %x with skeel!','Har!  Y\' do be needin moore praktise y\' wee cub!',NULL,NULL,66,12,12)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (7,'Gerrard',7,'Battle Bow','Hmm, mayhaps I underestimated you.','As I thought.',NULL,NULL,77,14,14)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (8,'Ceiloth',8,'Orkos Broadsword','Well done %w`&, I can see that great things lie in the future for you!','You are becoming powerful, but not yet that powerful.',NULL,NULL,88,16,16)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (9,'Dwiredan',9,'Twin Swords','Perhaps I should have considered your %x...','Perhaps you\'ll reconsider my twin swords before you try that again?',NULL,NULL,99,18,18)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (10,'Sensei Noetha',10,'Martial Arts Skills','Your style was superior, your form greater.  I bow to you.','Learn to adapt your style, and you shal prevail.',NULL,NULL,110,20,20)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (11,'Celith',11,'Throwing Halos','Wow, how did you dodge all those halos?','Watch out for that last halo, it\'s coming back this way!',NULL,NULL,121,22,22)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (12,'Gadriel the Elven Ranger',12,'Elven Long Bow','I can accept that you defeated me, because after all elves are immortal while you are not, so the victory will be mine.','Do not forget that elves are immortal.  Mortals will likely never defeat one of the fey.',NULL,NULL,132,24,24)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (13,'Adoawyr',13,'Gargantuan Broad Sword','If I could have picked up this sword, I probably would have done better!','Haha, I couldn\'t even pick the sword UP and I still won!',NULL,NULL,143,26,26)",
		"INSERT INTO " . db_prefix("masters") . " VALUES (14,'Yoresh',14,'Death Touch','Well, you evaded my touch.  I salute you!','Watch out for my touch next time!',NULL,NULL,154,28,28)",

		"INSERT INTO " . db_prefix("news") . " VALUES (1,'`^A strange awakening takes place in the world.`0',now(), 0, '')",	
	),
	"0.9.1"=>array(
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6Just wait for my revenge, `4%W`6. It will be swift!`5\" %w declares.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6I\'m really going to enjoy this new `4%x`6 that %w`6 had,`5\" exclaimed %W.','joe')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6Aah, so `bthat\'s`b what `4%X`6 is for!`5\" exclaimed %W','joe')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6Oh man!  I didn\'t think you had it in you, `5%W`6,`5\" %w exclaims.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5%W was overheard saying, \"`6%p `4%x`6 was no match for my `4%X`6!`5\"','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6You know, you really shouldn\'t have a `4%x`6 unless you know how to use it,`5\" suggested %W.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6`bARRRGGGGGGG`b!!`5\" %w screams in frustration.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6How could I be so feeble?`5\" %w laments.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6I must not be as sturdy as I thought...!`5\" %w concedes.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6Watch your back, `4%W`6, I am coming for you!`5\" %w warns.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6This both sucks and blows!`5\" wails %w.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6I see London, I see France, I see `4%w\'s`6, underpants!`5\" reveals %W.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6The Healer\'s Hut can\'t help you now, `4%w`6!`5\" chides %W.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5%W smiles.  \"`6You are too slow.  You are too weak.`5\"','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5%w bangs %p head against a stone...\"`6Stupid, stupid, stupid!`5\" %o was heard to say.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6My ego can\'t take much more of this bruising!`5\" exclaims %w.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6Why didn\'t I become a successful doctor like my father suggested?`5\" wonders %w aloud.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6Maybe `bnext`b time you won\'t be so cocky!`5\" laughs %W','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6A baby could wield a `4%x `6better than that!`5\" %W proclaims.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6You should have just stayed in bed,`5\" %W suggests.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6Well isn\'t that a kick in the crotch?!`5\" %w observes.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6Come back when you learn how to fight,`5\" %W scoffs.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6Next time, eat your Wheaties,`5\" %W suggests.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5 \"`6You are dishonorable, `4%W`6!`5\" %w cries.','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`4%w`6, your lack of posture is a disgrace,`5\" %W states. ','Bluspring')",
		"INSERT INTO " . db_prefix("taunts") . " VALUES (0,'`5\"`6You know, `4%w`6 really had it coming to %s after all those things `bI`b said about `b%p`b mom`5,\" commented %W.','Joe')",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Rake',48,1,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Trowel',225,2,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spade',585,3,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Adze',990,4,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Gardening Hoe',1575,5,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Torch',2250,6,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Pitchfork',2790,7,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Shovel',3420,8,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Hedge Trimmers',4230,9,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Hatchet',5040,10,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Carving Knife',5850,11,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Rusty Iron Wood-Chopping Axe',6840,12,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Dull Steel Wood-chopping Axe',8010,13,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Sharp Steel Wood-chopping Axe',9000,14,0)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Woodsman\'s Axe',10350,15,0)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Fuzzy Slippers',48,1,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Flannel Pajamas',225,2,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Homespun Longjohns',585,3,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Homespun Undershirt',990,4,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Knitted Socks',1575,5,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Knitted Gloves',2250,6,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Old Leather Boots',2790,7,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Homespun Pants',3420,8,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Homespun Tunic',4230,9,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Gypsy Cape',5040,10,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Old Leather Cap',5850,11,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Old Leather Bracers',6840,12,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Traveler\'s Shield',8010,13,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Old Leather Pants',9000,14,0)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Old Leather Tunic',10350,15,0)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Pebbles',48,1,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Stones',225,2,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Rocks',585,3,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Small Treebranch',990,4,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Large Treebranch',1575,5,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Thickly Padded Sparring Pole',2250,6,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Thinly Padded Sparring Pole',2790,7,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Wooden Stave',3420,8,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Wooden Practice Sword',4230,9,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Blunt Bronze Short Sword',5040,10,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Well Crafted Bronze Short Sword',5850,11,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Rusty Steel Short Sword',6840,12,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Dull Steel Short Sword',8010,13,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Sharp Steel Short Sword',9000,14,1)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Pages\'s Short Sword',10350,15,1)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Flip-Flops',48,1,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Swimsuit and Towel',225,2,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Cotton Undershirt',585,3,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wool Socks',990,4,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wool Gloves',1575,5,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Leather Boots',2250,6,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Leather Cap',2790,7,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Leather Bracers',3420,8,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Leather Leggings',4230,9,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Leather Tunic',5040,10,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Hooded Leather Cape',5850,11,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Deerskin Leggings',6840,12,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Deerskin Belt',8010,13,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Deerskin Tunic',9000,14,1)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Small Rawhide Shield',10350,15,1)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Dull Bronze Sword',48,1,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Bronze Sword',225,2,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Well Crafted Bronze Sword',585,3,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Dull Iron Sword',990,4,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Iron Sword',1575,5,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Enchanted Sword',9000,14,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Well Crafted Iron Sword',2250,6,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Rusty Steel Sword',2790,7,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Dull Steel Sword',3420,8,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Well Crafted Steel Sword',4230,9,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Engraved Steel Sword',5040,10,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Steel Sword with Jeweled Hilt',5850,11,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Golden Hilted Sword',6840,12,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Platinum Hilted Sword',8010,13,2)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Adept\'s Sword',10350,15,2)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Workboots',48,1,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Overalls',225,2,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Sturdy Leather Gloves',585,3,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Sturdy Leather Bracers',990,4,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Sturdy Leather Boots',1575,5,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Sturdy Leather Helm',2250,6,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Sturdy Leather Pants',2790,7,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Sturdy Leather Tunic',3420,8,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Sturdy Leather Cloak',4230,9,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Woodsman\'s Helm',5040,10,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Woodsman\'s Gauntlets',5850,11,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Woodsman\'s Bracers',6840,12,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Woodsman\'s Greaves',8010,13,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Woodsman\'s Tunic',9000,14,2)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Woodsman\'s Kite Shield',10350,15,2)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Steel Longsword',48,1,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Etched Steel Longsword',585,3,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Polished Steel Longsword',225,2,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Well Balanced Steel Longsword',990,4,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Perfectly Balanced Steel Longsword',1575,5,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Engraved Steel Longsword',2250,6,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Longsword with Silver-plated Hilt',2790,7,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Longsword with Gold-plated Hilt',3420,8,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Longsword with Solid Gold Hilt',4230,9,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Longsword with Solid Platinum Hilt',5040,10,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Moonsilver Longsword',5850,11,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Autumngold Longsword',6840,12,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Elfsilver Longsword',8010,13,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Enchanted Longsword',9000,14,3)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Wolfmaster\'s Longsword',10350,15,3)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Showercap and Towel',48,1,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Bathrobe',225,2,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfskin Gloves',585,3,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfskin-lined Boots',990,4,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfskin Bracers',1575,5,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfskin Pants',2250,6,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfskin Tunic',2790,7,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Hooded Wolfskin Cape',3420,8,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfmaster\'s Bracers',4230,9,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfmaster\'s Gauntlets',5040,10,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfmasters Helm',5850,11,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfmaster\'s Leggings',6840,12,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfmaster\'s Belted Jerkin',8010,13,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Wolfhide Cape',9000,14,3)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Shield of the Wolf Master',10350,15,3)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Poorly Balanced Bastard Sword',48,1,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Tarnished Bastard Sword',225,2,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Iron Bastard Sword',585,3,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Steel Bastard Sword',990,4,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Well Balanced Steel Bastard Sword',1575,5,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Perfectly Balanced Bastard Sword',2250,6,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Rune-etched Bastard Sword',2790,7,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Bronze-inlay Bastard Sword',3420,8,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Silver-inlay Bastard Sword',4230,9,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Gold-inlay Bastard Sword',5040,10,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Nightsilver Bastard Sword',5850,11,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Morning-gold Bastard Sword',6840,12,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Truesplendor Bastard Sword',8010,13,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Enchanted Elfgold Bastard Sword',9000,14,4)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Noble\'s Bastard Sword',10350,15,4)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Sweat Pants',48,1,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Sweat Shirt',225,2,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Studded Leather Helm',585,3,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Studded Leather Gauntlets',990,4,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Hardened Leather Boots',1575,5,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Studded Leather Leggings',2250,6,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Studded Leather Tunic',2790,7,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Tanner\'s Cape',3420,8,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Rusty Chainmail Helm',4230,9,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Rusty Chainmail Gauntlets',5040,10,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Rusty Chainmail Bracers',5850,11,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Rusty Chainmail Boots',6840,12,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Rusty Chainmail Greaves',8010,13,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Rusty Chainmail Tunic',9000,14,4)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Large Iron Buckler',10350,15,4)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Tarnished Iron Claymore',48,1,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Polished Iron Claymore',225,2,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Rusty Steel Claymore',585,3,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Steel Claymore',990,4,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Finely Crafted Steel Claymore',1575,5,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Scottish Broadsword',2250,6,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Viking War Sword',2790,7,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Barbarian\'s Sword',3420,8,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Scottish Basket-Hilt Claymore',4230,9,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Agincourt Steel Sword',5040,10,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Celtic Combat Sword',5850,11,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Norseman\'s Sword',6840,12,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Knight\'s Sword',8010,13,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Heraldic Lion Claymore',9000,14,5)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Dragon Soldier\'s Claymore',10350,15,5)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Bunny Slippers',48,1,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Feety Pajamas',225,2,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Comfortable Leather Undergarments',585,3,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Heavy Chainmail Helm',990,4,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Heavy Chainmail Gauntlets',1575,5,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Heavy Chainmail Bracers',2250,6,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Heavy Chainmail Boots',2790,7,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Heavy Chainmail Greaves',3420,8,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Heavy Chainmail Tunic',4230,9,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Soldier\'s Bracers',5040,10,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Soldier\'s Gauntlets',5850,11,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Soldier\'s Boots',6840,12,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Soldier\'s Greaves',8010,13,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Soldier\'s Chestplate',9000,14,5)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Soldier\'s Shield',10350,15,5)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Two Broken Short Swords',48,1,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Two Short Swords',225,2,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Iron Scimitars',585,3,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Balanced Scimitars',990,4,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Tarnished Steel Scimitars',1575,5,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Rusty Steel Scimitars',2250,6,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Steel Scimitars',2790,7,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Bronze Hilted Steel Scimitars',3420,8,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Gold Hilted Steel Scimitars',4230,9,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Platinum Hilted Steel Scimitars',5040,10,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Well Crafted Adamantite Scimitars',5850,11,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Perfectly Crafted Adamantite Scimitars',6840,12,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Enchanted Scimitars',8010,13,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Drow Crafted Scimitars',9000,14,6)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Unicorn Blood-Forged Scimitars',10350,15,6)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Bluejeans',48,1,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Flannel Shirt',225,2,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Well Crafted Bronze Helm',585,3,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Well Crafted Bronze Gauntlets',990,4,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Well Crafted Bronze Bracers',1575,5,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Well Crafted Bronze Boots',2250,6,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Well Crafted Bronze Greaves',2790,7,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Well Crafted Bronze Chestplate',3420,8,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Bronze Helm',4230,9,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Bronze Gauntlets',5040,10,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Bronze Bracers',5850,11,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Bronze Boots',6840,12,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Bronze Greaves',8010,13,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Bronze Chestplate',9000,14,6)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Hooded Unicorn Skin Cloak',10350,15,6)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Chipped Iron Axe',48,1,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Iron Axe',225,2,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Rusty Steel Axe',585,3,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Fine Steel Axe',990,4,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Lumberjack\'s Axe',1575,5,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Low Quality Battle Axe',2250,6,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Medium Quality Battle Axe',2790,7,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'High Quality Battle Axe',3420,8,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Double Bladed Axe',4230,9,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Double Bladed Battle Axe',5040,10,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Gold Plated Battle Axe',5850,11,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Platinum Hilted Battle Axe',6840,12,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Enchanted Battle Axe',8010,13,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Dwarf Smith\'s Battle Axe',9000,14,7)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Dwarf Warrior\'s Battle Axe',10350,15,7)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Barrel',48,1,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Lampshade',225,2,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Perfectly Crafted Steel Helm',585,3,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Perfectly Crafted Steel Gauntlets',990,4,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Perfectly Crafted Steel Boots',1575,5,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Perfectly Crafted Steel Bracers',2250,6,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Perfectly Crafted Steel Greaves',2790,7,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Perfectly Crafted Steel Chestplate',3420,8,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Griffon-Feather Cloak',4230,9,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dwarven Chainmail Helm',5040,10,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dwarven Chainmail Gauntlets',5850,11,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dwarven Chainmail Boots',6840,12,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dwarven Chainmail Bracers',8010,13,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dwarven Chainmail Greaves',9000,14,7)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dwarven Chainmail Chestplate',10350,15,7)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Broken Iron Mace',48,1,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Tarnished Iron Mace',225,2,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Polished Iron Mace',585,3,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Well Crafted Iron Mace',990,4,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Polished Steel Mace',1575,5,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Well Crafted Steel Mace',2250,6,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Poorly Balanced Double Mace',2790,7,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Well Balanced Double Mace',3420,8,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Battle Mace',4230,9,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'War Chieftain\'s Battle Mace',5040,10,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'War Chieftain\'s Morning Star',5850,11,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Adamantite Morning Star',6840,12,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Dwarf Crafted Morning Star',8010,13,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Dwarf Warlord\'s Morning Star',9000,14,8)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Enchanted Morning Star',10350,15,8)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Fig Leaf',48,1,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Kilt',225,2,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Majestic Gold Helm',585,3,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Majestic Gold Gauntlets',990,4,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Majestic Gold Boots',1575,5,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Bracers',2250,6,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Majestic Gold Greaves',2790,7,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Majestic Gold Chestplate',3420,8,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Majestic Gold Shield',4230,9,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Gold-Threaded Cloak',5040,10,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Ruby Ring',5850,11,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Sapphire Ring',6840,12,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Jade Ring',8010,13,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Amethyst Ring',9000,14,8)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Enchanted Diamond Ring',10350,15,8)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Boot Knife',48,1,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Target Knife',225,2,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Blackjack',585,3,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Throwing Star',990,4,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Hira-Shuriken',1575,5,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Throwing Spike',2250,6,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Atlatl',2790,7,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Qilamitautit Bolo',3420,8,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'War Quoait',4230,9,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Cha Kran',5040,10,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Fei Piau',5850,11,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Jen Piau',6840,12,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Gau dim Piau',8010,13,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Enchanted Throwing Axe',9000,14,9)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Teksolo\'s Ninja Stars',10350,15,9)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Button',48,1,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Elven Silk Nightclothes',225,2,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Elven Silk Gloves',585,3,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Elven Silk Slippers',990,4,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Elven Silk Wristband',1575,5,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Leggings',2250,6,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Elven Silk Tunic',2790,7,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Elven Silk Cloak',3420,8,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Ring of Night',4230,9,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Ring of Day',5040,10,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Ring of Solitude',5850,11,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Ring of Peace',6840,12,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Ring of Courage',8010,13,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Ring of Virtue',9000,14,9)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Ring of Life',10350,15,9)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Farmer\'s Bow & Wooden Arrows',48,1,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Farmer\'s Bow & Stone Tipped Arrows',225,2,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Farmer\'s Bow & Steel Tipped Arrows',585,3,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Hunter\'s Bow & Wooden Arrows',990,4,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Hunter\'s Bow & Stone Tipped Arrows',1575,5,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Hunter\'s Bow & Steel Tipped Arrows',2250,6,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Ranger\'s Bow & Wooden Arrows',2790,7,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Ranger\'s Bow & Stone Tipped Arrows',3420,8,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Ranger\'s Bow & Steel Tipped Arrows',4230,9,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Longbow',5040,10,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Crossbow',5850,11,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Elvish Longbow',6840,12,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Elvish Longbow & Flame Tipped Arrows',8010,13,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Elvish Longbow & Enchanted Arrows',9000,14,10)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Longbow of the Elf King',10350,15,10)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Hooded Cloak',5040,10,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Chestplate',4230,9,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Greaves',3420,8,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Boots',2790,7,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Gorget',2250,6,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Bracers',1575,5,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Gauntlets',990,4,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Helm',585,3,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Platform Shoes',225,2,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Leisure Suit',48,1,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus Feather Pendant',5850,11,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus Feather Belt',6840,12,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Emblazoned Shield',8010,13,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Emblazoned Ring',9000,14,10)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pegasus\' Emblazoned Crown',10350,15,10)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Long Sword',225,2,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Short Sword',48,1,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Bastard Sword',585,3,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Scimitars',990,4,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Battle Axe',1575,5,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Throwing Hammer',2250,6,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Morning Star',2790,7,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Compound Bow',3420,8,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Rapier',4230,9,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Sabre',5040,10,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Light Sabre',5850,11,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Wakizashi',6840,12,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s 2-Handed War Sword',8010,13,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s 2-handed War Axe',9000,14,11)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'MightyE\'s Claymore',10350,15,11)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'New Clothes',48,1,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Chicken Suit',225,2,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Gauntlets of Grace',585,3,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Bracer of Beauty',990,4,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Helm of Health',1575,5,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Greaves of Good Fortune',2250,6,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Boots of Bravery',2790,7,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Tunic of Tolerance',3420,8,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Cloak of Confidence',4230,9,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Ring of Righteousness',5040,10,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Necklace of Narcissism',5850,11,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Pendant of Power',6840,12,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Breastplate of Benevolence',8010,13,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Shield of Superiority',9000,14,11)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Scepter of Strength',10350,15,11)",

		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Fire',48,1,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Earthquake',225,2,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Flood',585,3,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Hurricane',990,4,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Mind Control',1575,5,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Lightning',2250,6,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Weakness',2790,7,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Fear',3420,8,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Poison',4230,9,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Spirit Possession',5040,10,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Despair',5850,11,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Bat Summoning',6840,12,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Wolf Summoning',8010,13,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Unicorn Summoning',9000,14,12)",
		"INSERT INTO " . db_prefix("weapons") . " VALUES (0,'Spell of Dragon Summoning',10350,15,12)",

		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Skin Leather Helm',48,1,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Skin Leather Gauntlets',225,2,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Skin Leather Boots',585,3,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Skin Leather Bracers',990,4,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Skin Leather Leggings',1575,5,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Skin Leather Tunic',2250,6,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Skin Leather Cloak',2790,7,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Scale Helm',3420,8,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Scale Gauntlets',4230,9,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Scale Boots',5040,10,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Scale Bracers',5850,11,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Scale Greaves',6840,12,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Scale Chestplate',8010,13,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Scale Cloak',9000,14,12)",
		"INSERT INTO " . db_prefix("armor") . " VALUES (0,'Dragon Talon Shield',10350,15,12)",
	),
	"0.9.2"=>array(
	),
	"0.9.3"=>array(),
	"0.9.4"=>array(),
	"0.9.5"=>array(),
	"0.9.6"=>array(
	),
	"0.9.7"=>array(
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Old Man Winter', 9, 'Bitter Cold', 'You shake your fist over his dead, pathetic corpse.', NULL, 336, 101, 94, 17, 13, NULL, NULL, 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Deranged Gnome', 1, 'A Cloth Draped Mirror', 'What happens when I do THIS?', NULL, 36, 14, 10, 1, 1, NULL, NULL, 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Water Sprite', 1, 'Burst of Water', 'That was refreshing.', NULL, 36, 14, 10, 1, 1, NULL, NULL, 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Water Nymph', 3, 'A torrent of water', 'I didn\'t need a bath, thank you.', NULL, 148, 34, 32, 5, 4, NULL, NULL, 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Lady of the Lake', 10, 'Excalibur', 'Take that, you watery tart!', NULL, 369, 114, 105, 19, 14, NULL, NULL, 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Cunning Sapling', 1, 'Arrrr!', 'Ah Ha! A toothpick!', NULL, 36, 14, 10, 1, 1, NULL, NULL, 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Pirate Tree', 5, 'A loud ARRRRR!', 'Arrrrrr! indeed.', NULL, 198, 55, 53, 9, 7, NULL, NULL, 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Undead Centurion', 5, 'Bronze Spear', 'Hmm Not too good at combat the second time around, either.', NULL, 198, 55, 53, 9, 7, NULL, NULL, 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Insane Bard', 2, 'Iambic Pentameter', 'Slings and Arrows of outrageous fortune? Nope.  Just the can o\' Whoopass.', NULL, 97, 24, 21, 3, 3, NULL, NULL, 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Twig Man', 1, 'Brambles and Briars', 'I snapped him like a.. well, twig.', NULL, 36, 14, 10, 1, 1, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Rabid Mouse', 1, 'Little Bitty Teeth', 'Those little teeth HURT!', NULL, 36, 14, 10, 1, 1, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Stray Cat', 1, 'A Midnight Serenade', 'Finally! Peace in the night!', NULL, 36, 14, 10, 1, 1, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Big Hairy Spider', 1, 'Sticky stringy webs.', 'I *HATE* spiders!', NULL, 36, 14, 10, 1, 1, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Goblin Lackey', 1, 'Dull Knife', 'Who knew goblins had lackeys?', NULL, 36, 14, 10, 1, 1, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Crazy Chihuahua', 1, 'Fast food cravings', 'Here taco taco taco..', NULL, 36, 14, 10, 1, 1, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Looney Rabbit', 1, 'Wisecracks', 'Th- Th- That\'s all folks!', NULL, 36, 14, 10, 1, 1, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Undead Oarsman', 1, 'Rotten Oar', 'Funny.. I didn\'t see any water around here..', NULL, 36, 14, 10, 1, 1, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Lost Ghostling', 2, 'Sad Weeping', 'Well, im sure that helped him on his way...', NULL, 97, 24, 21, 3, 3, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Angry Titmouse', 2, 'Incessant chattering', 'You swat the little bird out of the air with little effort.', NULL, 97, 24, 21, 3, 3, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Fabianist Youth Member', 2, 'Marxist Doctrine', 'Socialize THAT.', NULL, 97, 24, 21, 3, 3, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Little Bogeyman', 2, 'Noises in the Dark', 'Hmm not so scary when you have grown up...', NULL, 97, 24, 21, 3, 3, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Big Bogeyman', 3, 'Fingers poking you as you sleep..', 'Ok.. that was weird.  But not scary.. Nope not at all.. I think ill leave the light on at the inn tonight though.', NULL, 148, 34, 32, 5, 4, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Coblynau', 2, 'Ill tempered tricks', 'Maybe I better leave him part of my lunch next time..', NULL, 97, 24, 21, 3, 3, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Jack O\'Lantern', 2, 'Eternal Wandering', 'The light has gone out of his life.', NULL, 97, 24, 21, 3, 3, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Fresh Ghoul', 2, 'Long Pointed Nails', 'You leave him to the mercies of the other ghouls..', NULL, 97, 24, 21, 3, 3, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Dry Skeleton', 2, 'a Rusty Dagger', 'The skeleton crumbles into a pile of dust.', NULL, 97, 24, 21, 3, 3, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Newly Dead Zombie', 2, 'Fists', 'Maybe now it can rest in peace.', NULL, 97, 24, 21, 3, 3, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Faerie hound', 2, 'Glowing Eyes', 'The embers in the eye sockets dim and sputter out.', NULL, 97, 24, 21, 3, 3, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Apprentice Necromancer', 3, 'Life Draining Spells', 'He gasps a final breath and melts into a tarry liquid.', NULL, 148, 34, 32, 5, 4, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Doppleganger', 3, 'Shape changing', 'You kill the doppleganger and he returns to his true form.', NULL, 148, 34, 32, 5, 4, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Forest Thief', 3, 'Poisoned Short Sword', 'His pockets were almost empty, I guess he wasn\'t much of a thief.', NULL, 148, 34, 32, 5, 4, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Mouldy Skeleton', 3, 'Rotten Fists', 'Heeeeey, didn\'t you see him in town last week?', NULL, 148, 34, 32, 5, 4, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Angry Fairy', 3, 'Furious Fairy Dust', 'He disappears in a cloud of fairy dust.', NULL, 148, 34, 32, 5, 4, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Goblin Hunter', 3, 'a Shortbow', 'Only one? Don\'t they usually travel in packs?', NULL, 148, 34, 32, 5, 4, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Bobcat Cub', 3, 'Sharp Claws', 'Even the cute fuzzy kittens are evil in this place.', NULL, 148, 34, 32, 5, 4, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Animate Junkheap', 3, 'Stench of 1000 rotten potatos.', 'Just call you the De-Animator!', NULL, 148, 34, 32, 5, 4, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Necromancer', 4, 'a Strength Draining Touch', 'In a cloud of black smoke, his body wafts away on the breeze.', NULL, 162, 45, 43, 7, 6, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Reed Golem', 4, 'Fists of Thorns', 'The only thing left was a tiny bale of hay.', NULL, 162, 45, 43, 7, 6, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Goblin Shaman', 4, 'Primitive Magic', '\"Oooga Booga,\" indeed.', NULL, 162, 45, 43, 7, 6, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Steam Spirit', 4, 'Scalding Steam', 'Not so hot now, eh?', NULL, 162, 45, 43, 7, 6, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Restless Zombie', 4, 'Broken Longsword', 'Finally he is at peace.', NULL, 162, 45, 43, 7, 6, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Zombie Soldier', 4, 'Rusted Spear', 'His final orders were to march to hell..', NULL, 162, 45, 43, 7, 6, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Dark Imp', 4, 'Nagging Doubts', 'The imp implodes in a ball of flame.', NULL, 162, 45, 43, 7, 6, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Giant Spider', 4, 'Fangs that glisten with poison', 'I really really hate spiders.', NULL, 162, 45, 43, 7, 6, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Undead Kitten', 4, 'Mews of Doom', 'Another evil cat sent to hell C.O.D.', NULL, 162, 45, 43, 7, 6, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Flying Dagger', 4, 'Sharpened Steel Point', 'The dagger shatters when it hits the ground.', NULL, 162, 45, 43, 7, 6, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Goblin Warrior', 5, 'Bent Short Sword', 'Gone.. and forgotten.', NULL, 198, 55, 53, 9, 7, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Experienced Necromancer', 5, 'a small group of Zombies', 'The necromancer turns into a pile of black sand and blows away.', NULL, 198, 55, 53, 9, 7, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Flame Sprite', 5, 'Searing Flame', 'You cooled him off in a hurry...', NULL, 198, 55, 53, 9, 7, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Mud Man', 5, 'Enchanted Mud', 'Defeated, the Mud Man dries up in the warm sun.', NULL, 198, 55, 53, 9, 7, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Lupe the Hypnotic Chihuahua', 5, 'The stare of doom', 'You manage to break free of those deep hypnotic eyes...', NULL, 198, 55, 53, 9, 7, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Ghoul', 5, 'Hunger for Flesh', 'The ghoul falls to the ground, a bit of flesh between his teeth.', NULL, 198, 55, 53, 9, 7, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Seedy Cutthroat', 5, 'Sharpened Daggers', 'One more bandit removed from this forest.', NULL, 198, 55, 53, 9, 7, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Ogre', 5, 'Broken treebranch', 'Boy, thats a face not even a mother could love.', NULL, 198, 55, 53, 9, 7, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Crazy Woodsman', 5, 'Dull axe', 'Chopped him down to size...', NULL, 198, 55, 53, 9, 7, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Flying Drakeling', 5, 'a Lashing Tail', 'You swat the small, majestic beast out of the air.', NULL, 198, 55, 53, 9, 7, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Forest Cat', 6, 'Menacing Claws', 'Here kitty kitty kitty', NULL, 234, 66, 64, 11, 8, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Journeyman Necromancer', 6, 'An undead Giant', 'The necromancer drifts away on a cloud of black smoke.', NULL, 234, 66, 64, 11, 8, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Frigid Skeleton', 6, 'The Cold of the Grave', 'I\'ll bet one of these guys could cool ale at the inn', NULL, 234, 66, 64, 11, 8, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Frost Spirit', 6, 'Bone Chilling Cold', 'Puttin down another cold one', NULL, 234, 66, 64, 11, 8, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Dragon Slayer\'s ghost', 6, 'Warnings of Doom', 'Everybody wondered what happened to him.', NULL, 234, 66, 64, 11, 8, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Ettin Mage', 6, 'Double threat spells', 'Two heads are not better than one in this case.  Just more to lop off', NULL, 234, 66, 64, 11, 8, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Insane Brownie', 6, 'Faerie spells', 'This one\'s nuts!', NULL, 234, 66, 64, 11, 8, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Ghostly Wolfpack', 6, 'Ghostly Howls', 'Quiet settles in around you.  Finally.', NULL, 234, 66, 64, 11, 8, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Wood Golem', 6, 'Oaken Fists', 'The truth gave you life and the truth set you free', NULL, 234, 66, 64, 11, 8, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Diseased Ent', 6, 'Twisted Branches', 'There must be fifty ways to cut your lumber (Groan)', NULL, 234, 66, 64, 11, 8, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Dark Druid', 7, 'Corrupted Nature', 'He lost me at the corrupt it to save it part.', NULL, 268, 77, 74, 13, 10, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Lizard Man Scout', 7, 'Marginal Archery', 'I know where I can get him made into a nice pair of boots', NULL, 268, 77, 74, 13, 10, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Diabolic Footman', 7, 'A Demon Forged Mace', 'His armor sizzles and he melts as he crumples to the ground.', NULL, 268, 77, 74, 13, 10, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Gargantuan Tree Spider', 7, 'Projectile Webbing', 'After you lop him in half, you realize he\'s not so big.', NULL, 268, 77, 74, 13, 10, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Flaming Zombie', 7, 'Fists covered in Flame', 'You extinguish the flame of life and the zombie falls to the ground, smoking.', NULL, 268, 77, 74, 13, 10, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Eldritch Wizard', 7, 'Spells of Darkness', 'You slice him in two only to watch his body disappear, leaving an empty robe behind.', NULL, 268, 77, 74, 13, 10, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Master Necromancer', 7, 'An Army of the Dead', 'You kill the necromancer and his minions disintegrate before your eyes.', NULL, 268, 77, 74, 13, 10, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Animate Darkness', 7, 'The Darkness of a Thousand Nights', 'Light Slowly returns to this part of the forest', NULL, 268, 77, 74, 13, 10, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Temple Guardian Statue', 7, 'Marble Fists', 'So, where\'s the temple?', NULL, 268, 77, 74, 13, 10, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Owlbear', 7, 'Claws and a bearhug', 'I don\'t even want to know how they breed these', NULL, 268, 77, 74, 13, 10, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'The Man In Black', 8, 'Necromantic Spells', 'Finally, I got my chance to kill him', NULL, 302, 89, 84, 15, 11, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Gnome Illusionist', 8, 'Fearsome Illusions', 'It was all in his head', NULL, 302, 89, 84, 15, 11, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Demon Skeleton', 8, 'Diabolic Runes', 'The spirits of its victims drag the skeleton back to hell', NULL, 302, 89, 84, 15, 11, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Insane Master Druid', 8, 'The land Itself', 'His evil laughter dies with him.', NULL, 302, 89, 84, 15, 11, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Water Elementalist', 8, 'Water Based Spells', 'He\'s all wet.', NULL, 302, 89, 84, 15, 11, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Earth Elementalist', 8, 'Earth Based Spells', 'He Fought kind of Dirty.', NULL, 302, 89, 84, 15, 11, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Ettin Warrior', 8, 'Two Clubs of Iron', 'They did all right until they hit each other.', NULL, 302, 89, 84, 15, 11, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Forest Giant', 8, 'An Uprooted Tree', 'Ho, Ho, Ho that, green man.', NULL, 302, 89, 84, 15, 11, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Demoniac Knight', 8, 'A Diabolic Lance', 'Good Night Sir Knight.', NULL, 302, 89, 84, 15, 11, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Giant Zombie', 8, 'Gigantic Fists', 'They DO smell worse when they are bigger!', NULL, 302, 89, 84, 15, 11, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Frost Spectre', 9, 'The Chill Touch of the Grave', 'As you recover from the fight, the Spectre melts away into the shadows.', NULL, 336, 101, 94, 17, 13, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Small Forest Dragon', 9, 'Snapping Jaws', 'Dragon.. Check. Green... Check.  Huge.. Nope.', NULL, 336, 101, 94, 17, 13, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'A Pack of Carnivorous Lemurs', 9, 'Hoots and Howls', 'What the heck is a Lemur??', NULL, 336, 101, 94, 17, 13, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Albino Crypt Bear', 9, 'Foul Stench and Claws', 'You dispatch the bear and wonder if there are more lurking about.', NULL, 336, 101, 94, 17, 13, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Black Knight of The Vale', 9, 'Ebony Sword', 'As he dies, he curses you and tells you that you will never defeat the dragon.', NULL, 336, 101, 94, 17, 13, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Elmearian Spy', 9, 'Small Dagger', 'He eats his information before he dies, so you learn nothing from him.', NULL, 336, 101, 94, 17, 13, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Stalking Shadow', 9, 'Fingers of Darkness', 'You send the ceature back to where it came from.', NULL, 336, 101, 94, 17, 13, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Necromantic Archmagus', 9, 'Screams of a Thousand Souls', 'With his dying breath he explodes into a pillar of black flame!', NULL, 336, 101, 94, 17, 13, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Iron Golem', 9, 'Rusted Fists', 'The golem siezes up and you push him over.', NULL, 336, 101, 94, 17, 13, NULL, 'Hank', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'A Hell Hound', 9, 'Fiery Breath', 'He bursts into flames and is sucked into the earth.', NULL, 336, 101, 94, 17, 13, NULL, 'Hank', 1, 1)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'Corporate Lackey', 7, 'Buzzwords', 'Well, you sure reprioritized his downsizing.', NULL, 268, 77, 74, 13, 10, NULL, 'Moonchilde', 1, 0)",
		"INSERT INTO " . db_prefix("creatures") . " VALUES (0, 'SCO Lawyer', 8, 'Court Papers', 'There\'s one lawyer who\'ll never trouble you again!', NULL, 302, 89, 84, 15, 11, NULL, 'Moonchilde', 1, 1)",
		'INSERT INTO ' . db_prefix("nastywords") . ' VALUES ("*damn* *dyke *fuck* *nigger* *phuck* *shit* amcik andskota arschloch arse* ass asshole atouche ayir bastard bitch* boiolas bollock* buceta butt* butt-pirate cabron cawk cazzo chink chraa chuj cipa clit cock* cum cunt* dago daygo dego dick* dike dildo dirsa dupa dziwka ejaculate ejackulate ekrem* ekto enculer faen fag* fanculo fanny fatass fcuk feces feg felcher ficken fitta fitte flikker foreskin phuck fuk* fut futkretzn fuxor gay gook guiena hell helvete hoer* honkey honky hor hore huevon hui injun jism jizz kanker* kawk kike klootzak knulle kraut kuk kuksuger kurac kurwa kusi* kyrpä* leitch lesbian lesbo mamhoon masturbat* merd merde mibun monkleigh mouliewop muie mulkku muschi nazis nepesaurio nigga* nigger nutsack orospu paska* pendejo penis perse phuck picka pierdol* pillu* pimmel pimpis piss* pizda poontsee poop porn preteen preud prick pron pula pule pusse pussy puta puto qahbeh queef* queer* qweef rautenberg schaffer scheiss* scheisse schlampe schmuck screw scrotum sharmuta sharmute shemale shipal shiz skribz skurwysyn slut smut sphencter shpincter spic spierdalaj splooge suka teets teez testicle tits titties titty twat twaty vittu votze wank* wetback* whoar whore wichser woose wop yed zabourah", "nasty")',
		"INSERT INTO " . db_prefix("mounts") . " VALUES (1, 'Pony', 'This docile beast is young yet.', 'Horses', 'a:5:{s:4:\"name\";s:13:\"`&Pony Attack\";s:8:\"roundmsg\";s:26:\"Your pony fights with you!\";s:6:\"rounds\";s:2:\"20\";s:6:\"atkmod\";s:3:\"1.2\";s:8:\"activate\";s:7:\"offense\";}', 6, 0, 1, 1, 'You strap your {weapon} to your pony\'s saddle bags, and head out for some adventure!', '`&Remembering that is has been quite some time since you last fed your pony, you decide this is a perfect time to relax and allow it to graze the field a bit. You doze off enjoying this peaceful serenity.`0', '`&You dismount in the field to allow your pony to graze for a moment even though it has recently been fully fed.  As you lean back in the grass to watch the clouds, your pony whickers softly and trots off into the underbrush.  You search for a while before returning to the fields hoping that it\'ll return.  A short time later, your pony trots back into the clearing holding its head high, looking much more energized and with a very equine grin on its face.`0', 20, 'all', 0)",
		"INSERT INTO " . db_prefix("mounts") . " VALUES (2, 'Gelding', 'This powerful beast is fiercely loyal.', 'Horses', 'a:5:{s:4:\"name\";s:16:\"`&Gelding Attack\";s:8:\"roundmsg\";s:29:\"Your gelding fights with you!\";s:6:\"rounds\";s:2:\"40\";s:6:\"atkmod\";s:3:\"1.2\";s:8:\"activate\";s:7:\"offense\";}', 10, 0, 1, 2, 'You strap your {weapon} to your gelding\'s saddle bags, and head out for some adventure!', '`&Remembering that is has been quite some time since you last fed your gelding, you decide this is a perfect time to relax and allow it to graze the field a bit. You doze off enjoying this peaceful serenity.`0', '`&You dismount in the field to allow your gelding to graze for a moment even though it has recently been fully fed.  As you lean back in the grass to watch the clouds, your gelding whickers softly and trots off into the underbrush.  You search for a while before returning to the fields hoping that it\'ll return.  A short time later, your gelding trots back into the clearing holding its head high, looking much more energized and with a very equine grin on its face.`n`nAnd here you thought geldings weren\'t equipped that way any longer!`0', 25, 'all', 0)",
		"INSERT INTO " . db_prefix("mounts") . " VALUES (3, 'Stallion', 'This noble beast is huge and powerful!', 'Horses', 'a:5:{s:4:\"name\";s:17:\"`&Stallion Attack\";s:8:\"roundmsg\";s:30:\"Your stallion fights with you!\";s:6:\"rounds\";s:2:\"60\";s:6:\"atkmod\";s:3:\"1.2\";s:8:\"activate\";s:7:\"offense\";}', 16, 0, 1, 3, 'You strap your {weapon} to your stallion\'s saddle bags, and head out for some adventure!', '`&Remembering that is has been quite some time since you last fed your stallion, you decide this is a perfect time to relax and allow it to graze the field a bit. You doze off enjoying this peaceful serenity.`0', '`&You dismount in the field to allow your stallion to graze for a moment even though it has recently been fully fed.  As you lean back in the grass to watch the clouds, your stallion whickers softly and trots off into the underbrush.  You search for a while before returning to the fields hoping that it\'ll return.  A short time later, your stallion trots back into the clearing holding its head high, looking much more energized and with a very equine grin on its face.`0', 30, 'all', 0)",	
	),
	"0.9.8-prerelease.1"=>array(
		"UPDATE " . db_prefix("petitions") . " SET closedate = date WHERE status=2",
		"UPDATE " . db_prefix("masters") . " SET creaturewin='Learn to adapt your style, and you shall prevail.' WHERE creaturename='Sensei Noetha'",
		"UPDATE " . db_prefix("logdnet") . " SET lastping=lastupdate",
		"UPDATE " . db_prefix("accounts") . " SET attack=attack-1,race=\"Troll\" WHERE race='1'",
		"UPDATE " . db_prefix("accounts") . " SET defense=defense-1,race=\"Elf\" WHERE race='2'",
		"UPDATE " . db_prefix("accounts") . " SET race=\"Human\" WHERE race='3'",
		"UPDATE " . db_prefix("accounts") . " SET race=\"Dwarf\" WHERE race='4'",
		"UPDATE " . db_prefix("accounts") . " SET race=\"Horrible Gelatinous Blob\" WHERE race='0'",
		"UPDATE " . db_prefix("accounts") . " SET location=\"The Boar's Head Inn\" WHERE location='1'",
		"UPDATE " . db_prefix("accounts") . " SET location=\"Degolburg\" WHERE location='0'",
		"UPDATE " . db_prefix("accounts") . " SET password=md5(password) WHERE length(password) < 32",
		"UPDATE " . db_prefix("accounts") . " SET password=md5(password)",
		"UPDATE " . db_prefix("nastywords") . " SET type='nasty'",
	),
	"0.9.8-prerelease.2"=>array(),
	"0.9.8-prerelease.3"=>array(),
	"0.9.8-prerelease.4"=>array(),
	"0.9.8-prerelease.5"=>array(),
	"0.9.8-prerelease.6"=>array(
		"REPLACE INTO " . db_prefix("masters") . " VALUES (1,'Mireraband',1,'Small Dagger','Well done %w`&, I should have guessed you\'d grown some.','As I thought, %w`^, your skills are no match for my own!',NULL,NULL,12,2,2)",
		"REPLACE INTO " . db_prefix("masters") . " VALUES (2,'Fie',2,'Short Sword','Well done %w`&, you really know how to use your %x.','You should have known you were no match for my %X',NULL,NULL,22,4,4)",
		"REPLACE INTO " . db_prefix("masters") . " VALUES (4,'Guth',4,'Spiked Club','Ha!  Hahaha, excellent fight %w`&!  Haven\'t had a battle like that since I was in the RAF!','Back in the RAF, we\'d have eaten the likes of you alive!  Go work on your skills some old boy!',NULL,NULL,44,8,8)",
		"REPLACE INTO " . db_prefix("masters") . " VALUES (6,'Adwares',6,'Dwarven Battle Axe','Ach!  Y\' do hold yer %x with skeel!','Har!  Y\' do be needin moore praktise y\' wee cub!',NULL,NULL,66,12,12)",
		"REPLACE INTO " . db_prefix("masters") . " VALUES (8,'Ceiloth',8,'Orkos Broadsword','Well done %w`&, I can see that great things lie in the future for you!','You are becoming powerful, but not yet that powerful.',NULL,NULL,88,16,16)",
		"REPLACE INTO " . db_prefix("masters") . " VALUES (9,'Dwiredan',9,'Twin Swords','Perhaps I should have considered your %x...','Perhaps you\'ll reconsider my twin swords before you try that again?',NULL,NULL,99,18,18)",
	),
	"0.9.8-prerelease.7"=>array(),
	"0.9.8-prerelease.8"=>array(),
	"0.9.8-prerelease.9"=>array(),
	"0.9.8-prerelease.10"=>array(),
	"0.9.8-prerelease.11"=>array(
		"UPDATE " . db_prefix("accounts") . " SET specialty='' WHERE specialty='0'",
	),
	"0.9.8-prerelease.12"=>array(
		"1|UPDATE " . db_prefix("creatures") . " SET forest=1",
		"1|UPDATE " . db_prefix("creatures") . " SET graveyard=1 where location=1",
	),
	"0.9.8-prerelease.13"=>array(),
	"0.9.8-prerelease.14"=>array(),
	"0.9.8-prerelease.14a"=>array(
		"INSERT INTO " . db_prefix("titles") . " VALUES (1, 0, '', 'Farmboy', 'Farmgirl')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (2, 1, '', 'Page', 'Page')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (3, 2, '', 'Squire', 'Squire')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (4, 3, '', 'Gladiator', 'Gladiatrix')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (5, 4, '', 'Legionnaire', 'Legioness')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (6, 5, '', 'Centurion', 'Centurioness')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (7, 6, '', 'Sir', 'Madam')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (8, 7, '', 'Reeve', 'Reeve')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (9, 8, '', 'Steward', 'Steward')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (10, 9, '', 'Mayor', 'Mayoress')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (11, 10, '', 'Baron', 'Baroness')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (12, 11, '', 'Count', 'Countess')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (13, 12, '', 'Viscount', 'Viscountess')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (14, 13, '', 'Marquis', 'Marchioness')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (15, 14, '', 'Chancellor', 'Chancelloress')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (16, 15, '', 'Prince', 'Princess')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (17, 16, '', 'King', 'Queen')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (18, 17, '', 'Emperor', 'Empress')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (19, 18, '', 'Angel', 'Angel')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (20, 19, '', 'Archangel', 'Archangel')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (21, 20, '', 'Principality', 'Principality')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (22, 21, '', 'Power', 'Power')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (23, 22, '', 'Virtue', 'Virtue')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (24, 23, '', 'Dominion', 'Dominion')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (25, 24, '', 'Throne', 'Throne')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (26, 25, '', 'Cherub', 'Cherub')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (27, 26, '', 'Seraph', 'Seraph')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (28, 27, '', 'Demigod', 'Demigoddess')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (29, 28, '', 'Titan', 'Titaness')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (30, 29, '', 'Archtitan', 'Archtitaness')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (31, 30, '', 'Undergod', 'Undergoddess')",
		"INSERT INTO " . db_prefix("titles") . " VALUES (32, 31, '', 'God', 'Goddess')",
	),
	"1.0.0"=>array(),
);


if ((int)httpget("stage")>0) 
	$stage = (int)httpget("stage");
else
	$stage = 0;
if (!isset($session['stagecompleted'])) $session['stagecompleted']=-1;
if ($stage > $session['stagecompleted']+1) $stage = $session['stagecompleted'];
if (!isset($session['dbinfo'])) $session['dbinfo']=array("DB_HOST"=>"","DB_USER"=>"","DB_PASS"=>"","DB_NAME"=>"");
if (file_exists("dbconnect.php") && (
	$stage==3 || 
	$stage==4 || 
	$stage==5
	)){
		output("`%This stage was completed during a previous installation.");
		output("`2If you wish to perform stages 4 through 6 again, please delete the file named \"dbconnect.php\" from your site.`n`n");
		$stage=6;
	}
if ($stage > $session['stagecompleted']) $session['stagecompleted'] = $stage;

page_header("LoGD Installer &#151; {$stages[$stage]}");
if ($stage==0){
	output("`@`c`bWelcome to Legend of the Green Dragon`b`c`0");
	output("`2This is the installer script for Legend of the Green Dragon, by Eric Stevens & JT Traub.`n");
	output("`nIn order to install and use Legend of the Green Dragon (LoGD), you must agree to the license under which it is deployed.`n");
	output("`n`&This game is a small project into which we have invested a tremendous amount of personal effort, and we provide this to you absolutely free of charge.`2");
	output("Please understand that if you modify our copyright, or otherwise violate the license, you are not only breaking international copyright law (which includes penalties which are defined in whichever country you live), but you're also defeating the spirit of open source, and ruining any good faith which we have demonstrated by providing our blood, sweat, and tears to you free of charge.  You should also know that by breaking the license even one time, it is within our rights to require you to permanently cease running LoGD forever.`n");
	output("`nPlease note that in order to use the installer, you must have cookies enabled in your browser.`n");
	if (DB_CHOSEN){
		$sql = "SELECT count(*) AS c FROM accounts WHERE superuser & ".SU_MEGAUSER;
		$result = db_query($sql);
		$row = db_fetch_assoc($result);
		if ($row['c'] == 0){
			$needsauthentication = false;
		}
		if (httppost("username")>""){
			$sql = "SELECT * FROM ".db_prefix("accounts")." WHERE login='".httppost("username")."' AND password='".md5(md5(stripslashes(httppost("password"))))."' AND superuser & ".SU_MEGAUSER;
			$result = db_query($sql);
			if (db_num_rows($result) > 0){
				$row = db_fetch_assoc($result);
				// Okay, we have a username with megauser, now we need to do
				// some hackery with the password.
				$needsauthentication=true;
				$p = stripslashes(httppost("password"));
				$p1 = md5($p);
				$p2 = md5($p1);

				if (getsetting("installer_version", "-1") == "-1") {
					// Okay, they are upgrading from 0.9.7  they will have
					// either a non-encrypted password, or an encrypted singly
					// password.
					if (strlen($row['password']) == 32 &&
							$row['password'] == $p1) {
						$needsauthentication = false;
					} elseif ($row['password'] == $p) {
						$needsauthentication = false;
					}
				} elseif ($row['password'] == $p2) {
					$needsauthentication = false;
				}
				if ($needsauthentication === false) {
					redirect("installer.php?stage=1");
				}
				output("`\$That username / password was not found, or is not an account with sufficient privileges to perform the upgrade.`n");
			}else{
				$needsauthentication=true;
				output("`\$That username / password was not found, or is not an account with sufficient privileges to perform the upgrade.`n");
			}
		}else{
			$sql = "SELECT count(*) AS c FROM ".db_prefix("accounts")." WHERE superuser & ".SU_MEGAUSER;
			$result = db_query($sql);
			$row = db_fetch_assoc($result);
			if ($row['c']>0){
				$needsauthentication=true;
			}else{
				$needsauthentication=false;
			}
		}
	}else{
		$needsauthentication=false;
	}
	//if a user with appropriate privs is already logged in, let's let them past.
	if ($session['user']['superuser'] & SU_MEGAUSER) $needsauthentication=false;
	if ($needsauthentication){
		$session['stagecompleted']=-1;
		rawoutput("<form action='installer.php?stage=0' method='POST'>");
		output("`%In order to upgrade this LoGD installation, you will need to provide the username and password of a superuser account with the MEGAUSER privilege`n");
		output("`^Username: `0");
		rawoutput("<input name='username'><br>");
		output("`^Password: `0");
		rawoutput("<input type='password' name='password'><br>");
		$submit = translate_inline("Submit");
		rawoutput("<input type='submit' value='$submit' class='button'>");
		rawoutput("</form>");
	}else{
		output("`nPlease continue on to the next page, \"License Agreement.\"");
	}
}elseif ($stage==1){
 	require_once("lib/pullurl.php");
 	$license = join("",pullurl("http://creativecommons.org/licenses/by-nc-sa/2.0/legalcode"));
 	$license = str_replace("\n","",$license);
 	$license = str_replace("\r","",$license);
 	$shortlicense=array();
 	preg_match_all("'<body[^>]*>(.*)</body>'",$license,$shortlicense);
 	$license = $shortlicense[1][0];
 	output("`@`c`bLicense Agreement`b`c`0");
 	output("`2Before continuing, you must read and understand the following license agreement.`0`n`n");
 	if (md5($license)=="484d213db9a69e79321feafb85915ff1"){
	 	rawoutput("<div style='width: 100%; height; 350px; max-height: 350px; overflow: auto; color: #FFFFFF; background-color: #000000; padding: 10px;'>");
	 	rawoutput("<base href='http://creativecommons.org/licenses/by-nc-sa/2.0/legalcode'>");
	 	rawoutput("<base target='_blank'>");
 		rawoutput($license);
	 	rawoutput("</div>");
	 	rawoutput("<base href='http://".$_SERVER["HTTP_HOST"].$_SERVER["REQUEST_URI"]."'>");
	 	rawoutput("<base target='_self'>");
	}else{
	 	output("`^Warning, the Creative Commons license has changed, or could not be retrieved from the Creative Commons server.");
	 	output("You should check with the game authors to ensure that the below license agrees with the license under which it was released.");
	 	output("The license may be referenced at <a target='_blank' href='http://creativecommons.org/licenses/by-nc-sa/2.0/legalcode'>the Creative Commons site</a>.",true);
	}
 	$license = join("",file("LICENSE.txt"));
	$license = preg_replace("/[^\na-zA-Z0-9!?.,;:'\"\/\\()@ -\]\[]/","",$license);
	$licensemd5="fb4f8510a17c2e14241d129e32e55dd3";
 	if (md5($license)==$licensemd5){
		// Reload it so we get the right line breaks, etc.
		//$license = file("LICENSE.txt");
 		$license = htmlentities($license);
 		$license = nl2br($license);
 		//$license = preg_replace("/<br[^>]*>\s+<br[^>]*>/i","<p>",$license);
 		//$license = preg_replace("/<br[^>]*>/i","",$license);
 		output("`n`n`b`@Plain Text:`b`n`7");
 		rawoutput($license);
	}else{
		output("`^The license file (LICENSE.txt) has been modified.  Please obtain a new copy of the game's code, this file has been tampered with.");
		output("Expected MD5 $licensemd5, but got ".md5($license));
		$stage=-1;
		$session['stagecompleted']=-1;
	}
}elseif ($stage==2){
	output("`#By continuing with this installation, you indicate your agreement with the terms of the license found on the previous page (License Agreement).");
}elseif ($stage==3){
 	rawoutput("<form action='installer.php?stage=4' method='POST'>");
 	output("`@`c`bDatabase Connection Information`b`c`2");
 	output("In order to run Legend of the Green Dragon, your server must have access to a MySQL database.");
 	output("If you are not sure if you meet this need, talk to server's Internet Service Provider (ISP), and make sure they offer MySQL databases.");
 	output("If you are running on your own machine or a server under your control, you can download and install MySQL from <a href='http://www.mysql.com/' target='_blank'>the MySQL website</a> for free.`n",true);
 	if (file_exists("dbconnect.php")){
		output("There appears to already be a database setup file (dbconnect.php) in your site root, you can proceed to the next step.");
	}else{
		output("`nIt looks like this is a new install of Legend of the Green Dragon.");
		output("First, thanks for installing LoGD!");
		output("In order to connect to the database server, I'll need the following information.");
		output("`iIf you are unsure of the answer to any of these questions, please check with your server's ISP, or read the documentation on MySQL`i`n");

		output("`nWhat is the address of your database server?`n");
		rawoutput("<input name='DB_HOST' value=\"".htmlentities($session['dbinfo']['DB_HOST'])."\">");
		tip("If you are running LoGD from the same server as your database, use 'localhost' here.  Otherwise, you will have to find out what the address is of your database server.  Your server's ISP might be able to provide this information.");

		output("`nWhat is the username you use to connect to the database server?`n");
		rawoutput("<input name='DB_USER' value=\"".htmlentities($session['dbinfo']['DB_USER'])."\">");
		tip("This username does not have to be the same one you use to connect to the database server for administrative reasons.  However, in order to use this installer, and to install some of the modules, the account you provide here must have the ability to create, modify, and drop tables.  If you want the installer to create a new database for LoGD, the account will also have to have the ability to create databases.  Finally, to run the game, this account must at a minimum be able to select, insert, update, and delete records, and be able to lock tables.  If you're uncertain, grant the account the following privileges: SELECT, INSERT, UPDATE, DELETE, CREATE, DROP, INDEX, and ALTER.");
		
		output("`nWhat is the password for this username?`n");
		rawoutput("<input name='DB_PASS' value=\"".htmlentities($session['dbinfo']['DB_PASS'])."\">");
		tip("The password is necessary here in order for the game to successfully connect to the database server.  This information is not shared with anyone, it is simply used to configure the game.");
		
		output("`nWhat is the name of the database you wish to install LoGD in?`n");
		rawoutput("<input name='DB_NAME' value=\"".htmlentities($session['dbinfo']['DB_NAME'])."\">");
		tip("Database servers such as MySQL can control many different databases.  This is very useful if you have many different programs each needing their own database.  Each database has a unique name.  Provide the name you wish to use for LoGD in this field.");
		
		/*
		$yes = translate_inline("Yes");
		$no = translate_inline("No");
		output("`nShould I attempt to create this database if it does not exist?`n");
		rawoutput("<select name='DB_CREATE'><option value='1'>$yes</option><option value='0'>$no</option></select>");
		tip("If this database doesn't exist, I'll try to create it for you if you like.");
		*/
		$submit="Test this connection information.";
		output_notl("`n`n<input type='submit' value='$submit' class='button'>",true);
	}
 	rawoutput("</form>");
}elseif ($stage==4){
	if (httppostisset("DB_HOST")) {
	 	$session['dbinfo']['DB_HOST']=httppost("DB_HOST");
	 	$session['dbinfo']['DB_USER']=httppost("DB_USER");
	 	$session['dbinfo']['DB_PASS']=httppost("DB_PASS");
	 	$session['dbinfo']['DB_NAME']=httppost("DB_NAME");
	}
	output("`@`c`bTesting the Database Connection`b`c`2");
	output("Trying to establish a connection with the database:`n");
	ob_start();
	$link = mysql_connect($session['dbinfo']['DB_HOST'], $session['dbinfo']['DB_USER'], $session['dbinfo']['DB_PASS']);
	$error = ob_get_contents();
	ob_end_clean();
	if (!$link){
		output("`\$Blast!  I wasn't able to connect to the database server with the information you provided!");
		output("`2This means that either the database server address, database username, or database password you provided were wrong, or else the database server isn't running.");
		output("The specific error the database returned was:");
		rawoutput("<blockquote>".$error."</blockquote>");
		output("If you believe you provided the correct information, make sure that the database server is running (check documentation for how to determine this).");
		output("Otherwise, you should return to the previous step, \"Database Info\" and double-check that the information provided there is accurate.");
		$session['stagecompleted']=3;
	}else{
		output("`^Yahoo, I was able to connect to the database server!");
		output("`2This means that the database server address, database username, and database password you provided were probably accurate, and that your database server is running and accepting connections.`n");
		output("`nI'm now going to attempt to connect to the LoGD database you provided.`n");
		if (httpget("op")=="trycreate"){
		 	create_db($session['dbinfo']['DB_NAME']);
		}
		if (!mysql_select_db($session['dbinfo']['DB_NAME'])){
			output("`\$Rats!  I was not able to connect to the database.");
			$error = mysql_error();
			if ($error=="Unknown database '{$session['dbinfo']['DB_NAME']}'"){
				output("`2It looks like the database for LoGD hasn't been created yet.");
				output("I can attempt to create it for you if you like, but in order for that to work, the account you provided has to have permissions to create a new database.");
				output("If you're not sure what this means, it's safe to try to create this database, but you should double check that you've typed the name correctly by returning to the previous stage before you try it.`n");
				output("`nTo try to create the database, <a href='installer.php?stage=4&op=trycreate'>click here</a>.`n",true);
			}else{
				output("`2This is probably because the username and password you provided doesn't have permission to connect to the database.`n");
			}
			output("`nThe exact error returned from the database server was:");
			rawoutput("<blockquote>$error</blockquote>");
 			$session['stagecompleted']=3;
		}else{
			output("`n`^Excellent, I was able to connect to the database!`n");
			output("`n`@Tests`2`n");
			output("I'm now going to run a series of tests to determine what the permissions of this account are.`n");
			$issues = array();
			output("`n`^Test: `#Creating a table`n");
			//try to destroy the table if it's already here.
			$sql = "DROP TABLE IF EXISTS logd_environment_test";
			db_query($sql,false);
			$sql = "CREATE TABLE logd_environment_test (a int(11) unsigned not null)";
			mysql_query($sql);
			if ($error=mysql_error()){
	 			output("`2Result: `\$Fail`n");
	 			rawoutput("<blockquote>$error</blockquote>");
	 			array_push($issues,"`^Warning:`2 The installer will not be able to create the tables necessary to install LoGD.  If these tables already exist, or you have created them manually, then you can ignore this.  Also, many modules rely on being able to create tables, so you will not be able to use these modules.");
			}else{
	 			output("`2Result: `@Pass`n");
			}

			output("`n`^Test: `#Modifying a table`n");
			$sql = "ALTER TABLE logd_environment_test CHANGE a b varchar(50) not null";
			mysql_query($sql);
			if ($error=mysql_error()){
	 			output("`2Result: `\$Fail`n");
	 			rawoutput("<blockquote>$error</blockquote>");
	 			array_push($issues,"`^Warning:`2 The installer will not be able to modify existing tables (if any) to line up with new configurations.  Also, many modules rely on table modification permissions, so you will not be able to use these modules.");
			}else{
	 			output("`2Result: `@Pass`n");
			}

			output("`n`^Test: `#Creating an index`n");
			$sql = "ALTER TABLE logd_environment_test ADD INDEX(b)";
			mysql_query($sql);
			if ($error=mysql_error()){
	 			output("`2Result: `\$Fail`n");
	 			rawoutput("<blockquote>$error</blockquote>");
	 			array_push($issues,"`^Warning:`2 The installer will not be able to create indices on your tables.  Indices are extremely important for an active server, but can be done without on a small server.");
			}else{
	 			output("`2Result: `@Pass`n");
			}

			output("`n`^Test: `#Inserting a row`n");
			$sql = "INSERT INTO logd_environment_test (b) VALUES ('testing')";
			mysql_query($sql);
			if ($error=mysql_error()){
	 			output("`2Result: `\$Fail`n");
	 			rawoutput("<blockquote>$error</blockquote>");
	 			array_push($issues,"`\$Critical:`2 The game will not be able to function with out the ability to insert rows.");
	 			$session['stagecompleted']=3;
			}else{
	 			output("`2Result: `@Pass`n");
			}
			
			output("`n`^Test: `#Selecting a row`n");
			$sql = "SELECT * FROM logd_environment_test";
			mysql_query($sql);
			if ($error=mysql_error()){
	 			output("`2Result: `\$Fail`n");
	 			rawoutput("<blockquote>$error</blockquote>");
	 			array_push($issues,"`\$Critical:`2 The game will not be able to function with out the ability to select rows.");
	 			$session['stagecompleted']=3;
			}else{
	 			output("`2Result: `@Pass`n");
			}

			output("`n`^Test: `#Updating a row`n");
			$sql = "UPDATE logd_environment_test SET b='MightyE'";
			mysql_query($sql);
			if ($error=mysql_error()){
	 			output("`2Result: `\$Fail`n");
	 			rawoutput("<blockquote>$error</blockquote>");
	 			array_push($issues,"`\$Critical:`2 The game will not be able to function with out the ability to update rows.");
	 			$session['stagecompleted']=3;
			}else{
	 			output("`2Result: `@Pass`n");
			}
			
			output("`n`^Test: `#Deleting a row`n");
			$sql = "DELETE FROM logd_environment_test";
			mysql_query($sql);
			if ($error=mysql_error()){
	 			output("`2Result: `\$Fail`n");
	 			rawoutput("<blockquote>$error</blockquote>");
	 			array_push($issues,"`\$Critical:`2 The game database will grow very large with out the ability to delete rows.");
	 			$session['stagecompleted']=3;
			}else{
	 			output("`2Result: `@Pass`n");
			}
		
			output("`n`^Test: `#Deleting a table`n");
			$sql = "DROP TABLE logd_environment_test";
			mysql_query($sql);
			if ($error=mysql_error()){
	 			output("`2Result: `\$Fail`n");
	 			rawoutput("<blockquote>$error</blockquote>");
	 			array_push($issues,"`^Warning:`2 The installer will not be able to delete old tables (if any).  Also, many modules need to be able to delete the tables they put in place when they are uninstalled.  Although the game will function, you may end up with a lot of old data sitting around.");
			}else{
	 			output("`2Result: `@Pass`n");
			}
			output("`n`^Overall results:`2`n");
			if (count($issues)==0){
				output("You've passed all the tests, you're ready for the next stage.");
			}else{
				rawoutput("<ul>");
				output("<li>".join("</li>\n<li>",$issues)."</li>",true);
				rawoutput("</ul>");
				output("Even if all of the above issues are merely warnings, you will probably periodically see database errors as a result of them.");
				output("It would be a good idea to resolve these permissions issues before attempting to run this game.");
				output("For you technical folk, the specific permissions suggested are: SELECT, INSERT, UPDATE, DELETE, CREATE, DROP, INDEX, and ALTER.");
				output("I'm sorry, this is not something I can do for you.");
			}
		}
	}
}elseif ($stage=="5"){
	if (httppostisset("DB_PREFIX") > ""){
		$session['dbinfo']['DB_PREFIX'] = httppost("DB_PREFIX");
	}
	if ($session['dbinfo']['DB_PREFIX'] > "" && substr($session['dbinfo']['DB_PREFIX'],-1)!="_")
		$session['dbinfo']['DB_PREFIX'] .= "_";
		
	$descriptors = descriptors($session['dbinfo']['DB_PREFIX']);
	$unique=0;
	$game=0;
	$missing=0;
	$conflict = array();
	
	$link = mysql_connect($session['dbinfo']['DB_HOST'],$session['dbinfo']['DB_USER'],$session['dbinfo']['DB_PASS']);
	mysql_select_db($session['dbinfo']['DB_NAME']);
	$sql = "SHOW TABLES";
	$result = mysql_query($sql);
	while ($row = mysql_fetch_assoc($result)){
	 	list($key,$val)=each($row);
		if (isset($descriptors[$val])){
			$game++;
			array_push($conflict,$val);
		}else{
			$unique++;
		}
	}
	$missing = count($descriptors)-$game;
	if ($missing*10 < $game){
		//looks like an upgrade
		$upgrade=true;
	}else{
	 	$upgrade=false;
	}
	if (httpget("type")=="install") $upgrade=false;
	if (httpget("type")=="upgrade") $upgrade=true;
	$session['dbinfo']['upgrade']=$upgrade;
	
	if ($upgrade){
		output("`@This looks like a game upgrade.");
		output("`^If this is not an upgrade from a previous version of LoGD, <a href='installer.php?stage=5&type=install'>click here</a>.",true);
		output("`2Otherwise, continue on to the next step.");
	}else{
		//looks like a clean install
		$upgrade=false;
		output("`@This looks like a fresh install.");
		output("`2If this is not a fresh install, but rather an upgrade from a previous version of LoGD, chances are that you installed LoGD with a table prefix.  If that's the case, enter the prefix below.  If you are still getting this message, it's possible that I'm just spooked by how few tables are common to the current version, and in which case, I can try an upgrade if you <a href='installer.php?stage=5&type=upgrade'>click here</a>.`n",true);
		if (count($conflict)>0){
			output("`n`n`\$There are table conflicts.`2");
			output("If you continue with an install, the following tables will be overwritten with the game's tables.  If the listed tables belong to LoGD, they will be upgraded, otherwise all existing data in those tables will be destroyed.  Once this is done, this cannot be undone unless you have a backup!`n");
			output("`nThese tables conflict: `^".join(", ",$conflict)."`2`n");
			if (httpget("op")=="confirm_overwrite") $session['sure i want to overwrite the tables']=true;
			if (!$session['sure i want to overwrite the tables']){
				$session['stagecompleted']=4;
				output("`nIf you are sure that you wish to overwrite these tables, <a href='installer.php?stage=5&op=confirm_overwrite'>click here</a>.`n",true);
			}
		}
		output("`nYou can avoid table conflicts with other applications in the same database by providing a table name prefix.");
		output("This prefix will get put on the name of every table in the database.");
	}
	rawoutput("<form action='installer.php?stage=5' method='POST'>");
	output("`nTo provide a table prefix, enter it here.");
	output("If you don't know what this means, you should either leave it blank, or enter an intuitive value such as \"logd\".`n");
	rawoutput("<input name='DB_PREFIX' value=\"".htmlentities($session['dbinfo']['DB_PREFIX'])."\"><br>");
	$submit = translate_inline("Submit your prefix.");
	rawoutput("<input type='submit' value='$submit' class='button'>");
	rawoutput("</form>");
	if (count($conflict)==0){
		output("`^It looks like you can probably safely skip this step if you don't know what it means.");
	}
	output("`n`n`@Once you have submitted your prefix, you will be returned to this page to select the next step.");
	output("If you don't need a prefix, just select the next step now.");
}elseif ($stage==6){
 	if (file_exists("dbconnect.php")){
 		$success=true;
	}else{
		output("`@`c`bWriting your dbconnect.php file`b`c");
		output("`2I'm attempting to write a file named 'dbconnect.php' to your site root.");
		output("This file tells LoGD how to connect to the database, and is necessary to continue installation.`n");
		$dbconnect = 
			"<?php\n"
			."//This file automatically created by installer.php on ".date("M d, Y h:i a")."\n"
			."\$DB_HOST = \"{$session['dbinfo']['DB_HOST']}\";\n"
			."\$DB_USER = \"{$session['dbinfo']['DB_USER']}\";\n"
			."\$DB_PASS = \"{$session['dbinfo']['DB_PASS']}\";\n"
			."\$DB_NAME = \"{$session['dbinfo']['DB_NAME']}\";\n"
			."\$DB_PREFIX = \"{$session['dbinfo']['DB_PREFIX']}\";\n"
			."?>\n";
		$fp = @fopen("dbconnect.php","w+");
		if ($fp){
			if (fwrite($fp,
				$dbconnect
				)!==false){
				output("`n`@Success!`2  I was able to write your dbconnect.php file, you can continue on to the next step.");
			}else{
				$failure=true;
			}
			fclose($fp);
		}else{
			$failure=true;
		}
		if ($failure){
			output("`n`\$Unfortunately, I was not able to write your dbconnect.php file.");
			output("`2You will have to create this file yourself, and upload it to your web server.");
			output("The contents of this file should be as follows:`3");
			rawoutput("<blockquote><pre>".htmlentities($dbconnect)."</pre></blockquote>");
			output("`2Create a new file, past the entire contents from above into it (everything from and including `3<?php`2 up to and including `3?>`2 ).");
			output("When you have that done, save the file as 'dbconnect.php' and upload this to the location you have LoGD at.");
			output("You can refresh this page to see if you were successful.");
		}else{
			$success=true;
		}
	}
	if ($success){
		output("`n`^You are ready for the next step.");
	}else{
		$session['stagecompleted']=5;
	}
}elseif ($stage == 7){
	if (httppost("type")>""){
 	 	if (httppost("type")=="install") {
 	 	 	$session['fromversion']="-1";
 	 	 	$session['dbinfo']['upgrade']=false;
		}else{
			$session['fromversion']=httppost("version");
 	 	 	$session['dbinfo']['upgrade']=true;
		}
	}

 	if (!isset($session['fromversion']) || $session['fromversion']==""){
 	 	output("`@`c`bConfirmation`b`c");
 	 	output("`2Please confirm the following:`0`n");
 	 	rawoutput("<form action='installer.php?stage=7' method='POST'>");
 	 	rawoutput("<table border='0' cellpadding='0' cellspacing='0'><tr><td valign='top'>");
 	 	output("`2I should:`0");
 	 	rawoutput("</td><td>");
 	 	$version = getsetting("installer_version","-1");
		if ($version != "-1") $session['dbinfo']['upgrade']=true;
 	 	rawoutput("<input type='radio' value='upgrade' name='type'".($session['dbinfo']['upgrade']?" checked":"").">");
 	 	output(" `2Perform an upgrade from ");
 	 	if ($version=="-1") $version="0.9.7";
 	 	reset($sql_upgrade_statements);
 	 	rawoutput("<select name='version'>");
 	 	while(list($key,$val)=each($sql_upgrade_statements)){
 	 		if ($key!="-1"){
 	 			rawoutput("<option value='$key'".($version==$key?" selected":"").">$key</option>");
			}
		}
		rawoutput("</select>");
 	 	rawoutput("<br><input type='radio' value='install' name='type'".($session['dbinfo']['upgrade']?"":" checked").">");
 	 	output(" `2Perform a clean install.");
 	 	rawoutput("</td></tr></table>");
 	 	$submit=translate_inline("Submit");
 	 	rawoutput("<input type='submit' value='$submit' class='button'>");
 	 	rawoutput("</form>");
 		if ($session['dbinfo']['upgrade']){
 		 
		}
		$session['stagecompleted']=$stage - 1;
	}else{
		header("Location: installer.php?stage=".($stage+1));
		exit();
	}
}elseif ($stage==8){
	if (array_key_exists('modules',$_POST)){
		$session['moduleoperations'] = $_POST['modules'];
		$session['stagecompleted'] = $stage;
		header("Location: installer.php?stage=".($stage+1));
		exit();
	}elseif (array_key_exists('moduleoperations',$session) && is_array($session['moduleoperations'])){
		$session['stagecompleted'] = $stage;
	}else{
		$session['stagecompleted'] = $stage - 1;
	}
	output("`@`c`bManage Modules`b`c");
	output("Legend of the Green Dragon supports an extensive module system.");
	output("Modules are small self-contained files that perform a specific function or event within the game.");
	output("For the most part, modules are independant of each other, meaning that on module can be installed, uninstalled, activated, and deactivated without negative impact on the rest of the game.");
	output("Not all modules are ideal for all sites, for example, there's a module called 'Multiple Cities,' which is intended only for large sites with many users online at the same time.");
	output("`n`n`^If you are not familiar with Legend of the Green Dragon, and how the game is played, it is probably wisest to choose the default set of modules to be installed.");
	output("`n`n`@There is an extensive community of users who write modules for LoGD at <a href='http://mod.lotgd.net/'>http://mod.lotgd.net/</a>.",true);
	$submit = translate_inline("Save Module Settings");
	$install = translate_inline("Select Recommended Modules");
	$reset = translate_inline("Reset Values");
	$all_modules = array();
	$sql = "SELECT category,modulename,formalname,moduleauthor,active FROM ".db_prefix("modules")." ORDER BY category,active DESC,formalname";
	$result = @db_query($sql);
	if ($result!==false){
		while ($row = db_fetch_assoc($result)){
			if (!array_key_exists($row['category'],$all_modules)){
				$all_modules[$row['category']] = array();
			}
			$row['installed']=true;
			$all_modules[$row['category']][$row['modulename']] = $row;
		}
	}
	$install_status = get_module_install_status();
	
	$uninstalled = $install_status['uninstalledmodules'];
	reset($uninstalled);
	while (list($key,$modulename) = each($uninstalled)){
		$row = array();
		$moduleinfo = get_module_info($modulename);
		$row['installed'] = false;
		$row['active'] = false;
		$row['category'] = $moduleinfo['category'];
		$row['modulename'] = $modulename;
		$row['formalname'] = $moduleinfo['name'];
		$row['moduleauthor'] = $moduleinfo['author'];
		if (!array_key_exists($row['category'],$all_modules)){
			$all_modules[$row['category']] = array();
		}
		$all_modules[$row['category']][$row['modulename']] = $row;
	}
	output_notl("`0");
	rawoutput("<form action='installer.php?stage=".$stage."' method='POST'>");
	rawoutput("<input type='submit' value='$submit' class='button'>");
	rawoutput("<input type='button' onClick='chooseRecommendedModules();' class='button' value='$install' class='button'>");
	rawoutput("<input type='reset' value='$reset' class='button'><br>");
	rawoutput("<table cellpadding='1' cellspacing='1'>");
	ksort($all_modules);
	reset($all_modules);
	$x=0;
	while (list($categoryName,$categoryItems)=each($all_modules)){
		rawoutput("<tr class='trhead'><td colspan='6'>".tl($categoryName)."</td></tr>");
		rawoutput("<tr class='trhead'><td>".tl("Uninstalled")."</td><td>".tl("Installed")."</td><td>".tl("Activated")."</td><td>".tl("Recommended")."</td><td>".tl("Module Name")."</td><td>".tl("Author")."</td></tr>");
		reset($categoryItems);
		while (list($modulename,$moduleinfo)=each($categoryItems)){
			$x++;
			//if we specified things in a previous hit on this page, let's update the modules array here as we go along.
			$moduleinfo['realactive'] = $moduleinfo['active'];
			$moduleinfo['realinstalled'] = $moduleinfo['installed'];
			if (array_key_exists('moduleoperations',$session) && is_array($session['moduleoperations']) && array_key_exists($modulename,$session['moduleoperations'])){
				$ops = explode(",",$session['moduleoperations'][$modulename]);
				reset($ops);
				while (list($trash,$op) = each($ops)){
					switch($op){
					case "uninstall":
						$moduleinfo['installed'] = false;
						$moduleinfo['active'] = false;
						break;
					case "install":
						$moduleinfo['installed'] = true;
						$moduleinfo['active'] = false;
						break;
					case "activate":
						$moduleinfo['installed'] = true;
						$moduleinfo['active'] = true;
						break;
					case "deactivate":
						$moduleinfo['installed'] = true;
						$moduleinfo['active'] = false;
						break;
					case "donothing":
						break;
					}
				}
			}
			rawoutput("<tr class='".($x%2?"trlight":"trdark")."'>");
			if ($moduleinfo['realactive']){
				$uninstallop = "uninstall";
				$installop = "deactivate";
				$activateop = "donothing";
			}elseif ($moduleinfo['realinstalled']){
				$uninstallop = "uninstall";
				$installop = "donothing";
				$activateop = "activate";
			}else{
				$uninstallop = "donothing";
				$installop = "install";
				$activateop = "install,activate";
			}
			$uninstallcheck = false;
			$installcheck = false;
			$activatecheck = false;
			if ($moduleinfo['active']){
				$activatecheck = true;
			}elseif ($moduleinfo['installed']){
				//echo "<font color='red'>$modulename is installed but not active.</font><br>";
				$installcheck = true;
			}else{
				//echo "$modulename is uninstalled.<br>";
				$uninstallcheck = true;
			}
			rawoutput("<td><input type='radio' name='modules[$modulename]' id='uninstall-$modulename' value='$uninstallop'".($uninstallcheck?" checked":"")."></td>");
			rawoutput("<td><input type='radio' name='modules[$modulename]' id='install-$modulename' value='$installop'".($installcheck?" checked":"")."></td>");
			rawoutput("<td><input type='radio' name='modules[$modulename]' id='activate-$modulename' value='$activateop'".($activatecheck?" checked":"")."></td>");
			output_notl("<td>".(array_search($modulename,$recommended_modules)?tl("`^Yes`0"):tl("`\$No`0"))."</td>",true);
			rawoutput("<td>");
			output_notl("`@");
			output($moduleinfo['formalname']);
			output_notl(" [`%$modulename`@]`0");
			rawoutput("</td><td>");
			output_notl("`#{$moduleinfo['moduleauthor']}`0");
			rawoutput("</td>");
			rawoutput("</tr>");
		}
	}
	rawoutput("</table>");
	rawoutput("<br><input type='submit' value='$submit' class='button'>");
	rawoutput("<input type='button' onClick='chooseRecommendedModules();' class='button' value='$install' class='button'>");
	rawoutput("<input type='reset' value='$reset' class='button'>");
	rawoutput("</form>");
	rawoutput("<script language='JavaScript'>
	function chooseRecommendedModules(){
		var thisItem;
		var selectedCount = 0;
	");
	reset($recommended_modules);
	while (list($key,$val)=each($recommended_modules)){
		rawoutput("thisItem = document.getElementById('activate-$val'); ");
		rawoutput("if (!thisItem.checked) { selectedCount++; thisItem.checked=true; }\n");
	}
	rawoutput("
		alert('I selected '+selectedCount+' modules that I recommend, but which were not already selected.');
	}");
	if (!$session['dbinfo']['upgrade']){
		rawoutput("
		chooseRecommendedModules();");
	}
	rawoutput("
	</script>");
}elseif ($stage==9){
 	if (0){
	}else{
		output("`@`c`bBuilding the Tables`b`c");
		output("`2I'm now going to build the tables.");
		output("If this is an upgrade, your current tables will be brought in line with the current version.");
		output("If it's an install, the necessary tables will be placed in your database.`n");
		output("`n`@Table Synchronization Logs:`n");
		rawoutput("<div style='width: 100%; height: 150px; max-height: 150px; overflow: auto;'>");
		$descriptors = descriptors($DB_PREFIX);
		include_once("lib/tabledescriptor.php");
		reset($descriptors);
		while (list($tablename,$descriptor)=each($descriptors)){
			output("`3Synchronizing table `#$tablename`3..`n");
			synctable($tablename,$descriptor,true);
			if ($session['dbinfo']['upgrade']==false){
				//on a clean install, destroy all old data.
				db_query("TRUNCATE TABLE $tablename");
			}
		}
		rawoutput("</div>");
		output("`n`2The tables now have new fields and columns added, I'm going to begin importing data now.`n");
		rawoutput("<div style='width: 100%; height: 150px; max-height: 150px; overflow: auto;'>");
		$dosql = false;
		reset($sql_upgrade_statements);
		while (list($key,$val)=each($sql_upgrade_statements)){
		 	if ($dosql){
		 		output("`3Version `#%s`3: %s SQL statements...`n",$key,count($val));
		 		if (count($val)>0){
			 		output("`^Doing: `6");
			 		reset($val);
			 		$count=0;
			 		while (list($id,$sql)=each($val)){
						$onlyupgrade = 0;
						if (substr($sql, 0, 2) == "1|") {
							$sql = substr($sql, 2);
							$onlyupgrade = 1;
						}
						// Skip any statements that should only be run during
						// upgrades from previous versions.
						if (!$session['dbinfo']['upgrade'] && $onlyupgrade) {
							continue;
						}
			 		 	$count++;
			 			if ($count%10==0 && $count!=count($val))
							output_notl("`6$count...");
						if (!db_query($sql)) {
							output("`n`\$Error: `^'%s'`7 executing `#'%s'`7.`n",
									db_error(), $sql);
						}
					}
					output("$count.`n");
				}
			}
			if ($key == $session['fromversion'] ||
					$session['dbinfo']['upgrade'] == false) $dosql=true;
		}
		rawoutput("</div>");
		
		/*
		output("`n`2Now I'll install the recommended modules.");
		output("Please note that these modules will be installed, but not activated.");
		output("Once installation is complete, you should use the Module Manager found in the superuser grotto to activate those modules you wish to use.");
		reset($recommended_modules);
		rawoutput("<div style='width: 100%; height: 150px; max-height: 150px; overflow: auto;'>");
		while (list($key,$modulename)=each($recommended_modules)){
		 	output("`3Installing `#$modulename`\$`n");
			install_module($modulename, false);
		}
		rawoutput("</div>");
		*/
		output("`n`2Now I'll install and configure your modules.");
		reset($session['moduleoperations']);
		rawoutput("<div style='width: 100%; height: 150px; max-height: 150px; overflow: auto;'>");
		while (list($modulename,$val) = each($session['moduleoperations'])){
			$ops = explode(",",$val);
			reset($ops);
			while (list($trash,$op) = each($ops)){
				switch($op){
				case "uninstall":
					output("`3Uninstalling `#$modulename`3: ");
					if (uninstall_module($modulename)){
						output("`@OK!`0`n");
					}else{
						output("`\$Failed!`0`n");
					}
					break;
				case "install":
					output("`3Installing `#$modulename`3: ");
					if (install_module($modulename)){
						output("`@OK!`0`n");
					}else{
						output("`\$Failed!`0`n");
					}
					install_module($modulename);
					break;
				case "activate":
					output("`3Activating `#$modulename`3: ");
					if (activate_module($modulename)){
						output("`@OK!`0`n");
					}else{
						output("`\$Failed!`0`n");
					}
					break;
				case "deactivate":
					output("`3Deactivating `#$modulename`3: ");
					if (deactivate_module($modulename)){
						output("`@OK!`0`n");
					}else{
						output("`\$Failed!`0`n");
					}
					break;
				case "donothing":
					break;
				}
			}
			$session['moduleoperations'][$modulename] = "donothing";
		}
		rawoutput("</div>");
		
		output("`n`2Finally, I'll clean up old data.`n");
		rawoutput("<div style='width: 100%; height: 150px; max-height: 150px; overflow: auto;'>");
		reset($descriptors);
		while (list($tablename,$descriptor)=each($descriptors)){
			output("`3Cleaning up `#$tablename`3...`n");
			synctable($tablename,$descriptor);
		}
		rawoutput("</div>");
		output("`n`n`^You're ready for the next step.");
	}
}elseif ($stage==10){
	output("`@`c`bSuperuser Accounts`b`c");
	$sql = "SELECT login, password FROM ".db_prefix("accounts")." WHERE superuser & ".SU_MEGAUSER;
	$result = db_query($sql);
	if (db_num_rows($result)==0){
	 	if (httppost("name")>""){
	 	 	$showform=false;
	 		if (httppost("pass1")!=httppost("pass2")){
	 			output("`\$Oops, your passwords don't match.`2`n");
	 			$showform=true;
			}elseif (strlen(httppost("pass1"))<6){
				output("`\$Whoa, that's a short password, you really should make it longer.`2`n");
				$showform=true;
			}else{
				// Give the superuser a decent set of privs so they can
				// do everything needed without having to first go into
				// the user editor and give themselves privs.
				$su = SU_MEGAUSER | SU_EDIT_MOUNTS | SU_EDIT_CREATURES |
					SU_EDIT_PETITIONS | SU_EDIT_COMMENTS | SU_EDIT_DONATIONS |
					SU_EDIT_USERS | SU_EDIT_CONFIG | SU_INFINITE_DAYS |
					SU_EDIT_EQUIPMENT | SU_EDIT_PAYLOG | SU_DEVELOPER |
					SU_POST_MOTD | SU_MODERATE_CLANS | SU_EDIT_RIDDLES |
					SU_MANAGE_MODULES | SU_AUDIT_MODERATION | SU_RAW_SQL |
					SU_VIEW_SOURCE | SU_NEVER_EXPIRE;
				$name = httppost("name");
				$pass = md5(md5(stripslashes(httppost("pass1"))));
				$sql = "DELETE FROM ".db_prefix("accounts")." WHERE login='$name'";
				db_query($sql);
				$sql = "INSERT INTO " .db_prefix("accounts") ." (login,password,superuser,name,ctitle) VALUES('$name','$pass',$su,'`%Admin `&$name`0','`%Admin')";
				db_query($sql);
				output("`^Your superuser account has been created as `%Admin `&$name`^!");
			}
		}else{
			$showform=true;
		}
		if ($showform){
			rawoutput("<form action='installer.php?stage=$stage' method='POST'>");
			output("Enter a name for your superuser account:");
			rawoutput("<input name='name' value=\"".htmlentities(httppost("name"))."\">");
			output("`nEnter a password: ");
			rawoutput("<input name='pass1' type='password'>");
			output("`nConfirm your password: ");
			rawoutput("<input name='pass2' type='password'>");
			$submit = translate_inline("Create");
			rawoutput("<br><input type='submit' value='$submit' class='button'>");
			rawoutput("</form>");
		}
	}else{
		output("`#You already have a superuser account set up on this server.");
	}
}else{
	output("`@`c`bAll Done!`b`c");
	output("Your install of Legend of the Green Dragon has been completed!`n");
	output("`nRemember us when you have hundreds of users on your server, enjoying the game.");
	output("Eric, JT, and a lot of others put a lot of work into this world, so please don't disrespect that by violating the license.");
	if ($session['user']['loggedin']){
		addnav("Continue",$session['user']['restorepage']);
	}else{
		addnav("Login Screen","./");
	}
	savesetting("installer_version",$logd_version);
	$noinstallnavs=true;
}


if (!$noinstallnavs){
	if ($session['user']['loggedin']) addnav("Back to the game",$session['user']['restorepage']);
	addnav("Install Stages");
	
	for ($x=0; $x<=min(count($stages)-1,$session['stagecompleted']+1); $x++){
		if ($x == $stage) $stages[$x]="`^{$stages[$x]} <----";
		addnav($stages[$x],"installer.php?stage=$x");
	}
}
page_footer();

function create_db($dbname){
 	output("`n`2Attempting to create your database...`n");
	$sql = "CREATE DATABASE $dbname";
	mysql_query($sql);
	$error = mysql_error();
	if ($error == ""){
		if (mysql_select_db($dbname)){
			output("`@Success!`2  I was able to create the database and connect to it!`n");
		}else{
			output("`\$It seems I was not successful.`2  I didn't get any errors trying to create the database, but I was not able to connect to it.");
			output("I'm not sure what would have caused this error, you might try asking around in <a href='http://lotgd.net/forum/' target='_blank'>the LotGD.net forums</a>.");
		}
	}else{
		output("`\$It seems I was not successful.`2 ");
		output("The error returned by the database server was:");
		rawoutput("<blockquote>$error</blockquote>");
	}
	
}

$tipid=0;
function tip(){
 	global $tipid;
 	$tip = translate_inline("Tip");
 	output_notl("<div style='cursor: pointer; cursor: hand; display: inline;' onMouseOver=\"tip$tipid.style.visibility='visible'; tip$tipid.style.display='inline';\" onMouseOut=\"tip$tipid.style.visibility='hidden'; tip$tipid.style.display='none';\">`i[ `b{$tip}`b ]`i",true);
	rawoutput("<div class='debug' id='tip$tipid' style='position: absolute; width: 200px; max-width: 200px; float: right;'>");
	$args = func_get_args();
	call_user_func_array("output",$args);
	rawoutput("</div></div>");
	rawoutput("<script language='JavaScript'>var tip$tipid = document.getElementById('tip$tipid'); tip$tipid.style.visibility='hidden'; tip$tipid.style.display='none';</script>");
	$tipid++;	
}
	
function descriptors($prefix=""){
	include_once("lib/all_tables.php");
	$array = get_all_tables();
	$out = array();
	while (list($key,$val)=each($array)){
		$out[$prefix.$key]=$val;
	}
	return $out;
}

?>
