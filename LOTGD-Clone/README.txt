Compiled with Qt Creator 2.4.1.


Legend of the Green Dragon Clone

classes for characters need to be created.

todo:

Change how the npc get there stats

started: Add dbus for graphics front end
-- not using dbus as the sdl seems to work
++++- pull out the test version of sdl from main
+++-- The player warrior_objects and npc_objects need to be all renamed and cleaned up. it looks like hell
      This will effect every file so it will name some time to convert.  Should i use npc or creature. leaning to npc.
++++- Complie a list of creature/npc names to use.
++++- Compile a list of npc weapon names to use.
+++++ Find a better way to get npc stats.  May need to add base stats if i havent already to player and npc then i can work with that.
+++-- rewrite the display class
----- make maps
----- add functions to XML to load maps
++++- add options to the readXML to pull out the option for the HUD

Add zone to travel through

structure will be somethting like this
Init(); 	// handles loading of data, textures, maps, npcs
Event(); 	// handles input events mouse, keyboard
Loop();		// handles data updates npc's moving decrese hp bar...
Render();	// handles updating/rendering what shows up on the screen
Cleanup();	// cleans up resources Quits the game

