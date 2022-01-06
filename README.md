<!-- ABOUT THE PROJECT -->
#  Awesome 2D Shooter Game

<!-- A screenshot of your game would be nice here... -->
Simple 2d, dungen explorer game


Features:
The player can shoot/throw swords at enimes to kill them.
The enemies use pathfinding to tack down down the player.
Spikes that come out of ground dealing damage to both the player and the enemies
Menu system incuding - Main menu, pause menu, gameover menu.
Sound - Background track, shooting sound, and damage indicator.

## Dependencies
* SDL library
* SDL image libary
* SDL ttf libary
* SDL Mixer libary

## Target platforms
Support Windows x86/x64, GNU/Linux, OSX.

Instructions to build on Windows platforms:
1) Load .sln solution with Visual Studio;
2) Select Release configuration, and x64 Architecture;
3) Compile and run the project.

## into the future
Add in multiple levels
Add a new class to control the level changes
Add more enemy types that attck in differnt ways




## Performace profiling 

Below is a picture of the perfomace profilling off memnary used when playing the game

![image](https://user-images.githubusercontent.com/71771303/144948153-1820a5e8-dad8-40ae-91cd-6bbdb995baa9.png)

Below is a picture of the perfomace profilling off the cpu  when playing the game

![image](https://user-images.githubusercontent.com/71771303/144951472-67934d24-3485-45fc-a4e8-4ff4ca84d96c.png)

From the picture beloe you can see that the font renderer uses up the most cpu usage at the moment 

![image](https://user-images.githubusercontent.com/71771303/144953298-d31ae096-07ea-4888-af96-2772a258fd34.png)


















Your Name - James Wilson
