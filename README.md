# The Project 3 for the Program Design 2016
The code is clone from the TA's [source code]:https://github.com/ncku-pd2/Example-code-for-Project-3)
And most of code is refer to :[BBTAN-on-Qt](https://github.com/kevinbird61/BBTAN-on-Qt)



I modify/add something:
* The mainwindow Icon;
[icon_source](http://mepopedia.com/~web103-c/hw05/hw05-1025445108/images/2010090218139_4.gif)
* The mainwindow Title;
* The background picture(at the start list);
[bgpic_source](http://wallpaperscraft.ru/image/angry_birds_seasons_angry_birds_ptitsy_svini_yajtsa_piknik_97830_960x544.jpg)
* Add background music;
[bgm_source](https://www.youtube.com/watch?v=MOZky11wmwI)
background music cut from the 0:00 to 1:10
* Add the button for control the game(start/exit and its img);
(but the control doesn't complete)

* The time elasped(not yet adding)
* The scroe board(not yet adding)


The following is TA original ReadMe.md
# AngryThings
Final project of 2016 Spring Class

# How to use
We have provided you :
* Basic Window (Basic control of game , world of box2D have been created.)
* Basic GameItem (For everything's parent)
* Basic event control (You can extend from here)

###### Warning : 
###### This version is compiling with Box2D's library on Linux , so if your OS is windows , you should replace the libBox2D.a with the one in "Library/Windows".

# About Directory 
* src : main program all in here. (Open Qt creator , and load .pro file for open)
  * Box2D : box2D's header file.
  * image : store the image we use.
* Library : provide with different library for OS.
  * Windows : Box2D library for Windows.

# UML Diagram
![alt text][figure_lab2]

[figure_lab2]:https://github.com/ncku-pd2/Example-code-for-Project-3/blob/master/UML%20diagram/UML_diagram.png

# Reference 
[box2D](http://box2d.org/)
