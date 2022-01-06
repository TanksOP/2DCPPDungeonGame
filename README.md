<!-- ABOUT THE PROJECT -->
#  Awesome 2D Shooter Game

<!-- A screenshot of your game would be nice here... -->
Simple 2d, dungen explorer game


## Features:
* The player can shoot/throw swords at enimes to kill them.
* The enemies use pathfinding to tack down down the player.
* Spikes that come out of ground dealing damage to both the player and the enemies
* Menu system incuding - Main menu, pause menu, gameover menu.
* Sound - Background track, shooting sound, and damage indicator.

## Into the future
* Add in multiple levels
* Add a new class to control the level changes
* Add more enemy types that attck in differnt ways

## Dependencies
* SDL library
* SDL image libary
* SDL ttf libary
* SDL Mixer libary

## Target platforms
Support Windows x86/x64, GNU/Linux, OSX.

To play the game on x64
1) Go into the bin folder
2) click on the .exe file

If you want to play the game using x86
1) Go into the code directory
2) then go into th release folder 
3) Click on the .exe file to play the game






## Performace profiling 

Below is a picture showing the CPU usage of the game in it you are able to see that the font renderer uses 44%. So i changed the font that i use in my game and was able to change this to only use 30% which is shown below.

![image](https://user-images.githubusercontent.com/71771303/144953298-d31ae096-07ea-4888-af96-2772a258fd34.png)

![image](https://user-images.githubusercontent.com/71771303/148455894-719aa5bb-acc7-40d5-a113-f4d39793054e.png)

Bellow are some more pictures of code profiling of cpu uasage and memory usage. From looking at them i can see that i do not have a memory leak as the memory used by the program is not increasing as it continues.

![image](https://user-images.githubusercontent.com/71771303/148458600-4f2ea3fd-e18a-4f86-901d-3675a68a6ce6.png)
![image](https://user-images.githubusercontent.com/71771303/148459367-977dc1f5-b483-407f-9e49-9b55090ae0cb.png)


## Refrences

* Leszek_Szary (2012). shoot. Availible  at: https://freesound.org/people/Leszek_Szary/sounds/146730/ [Accessed-30/12/2021]
* mrickey13 (2020) PlayerHurt2. Availible at: https://freesound.org/people/mrickey13/sounds/515624/ [Accessed-30/12/2021]
* tonsil5 (2018). Grunt1 - Death Pain. Availible at: https://freesound.org/people/tonsil5/sounds/416839/ [Accessed-30/12/2021]
* Upbeat, Dew. oragnge-mountains. Availible at:https://uppbeat.io/t/orange-and-mountains/dew [Accessed-30/12/2021] License code: CFPWHZUODYBLNGEM

* 0x72, 16x16 DungeonTilsetII. Availible at:https://0x72.itch.io/dungeontileset-ii [Accessed-20/10/2021]











James Wilson - 201110335
