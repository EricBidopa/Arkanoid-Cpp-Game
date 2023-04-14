# Arkanoid C++ Game
Getting started with C++ Portfolio Games:)


Arkanoid Game

This is a simple implementation of the classic Arkanoid game using the SFML library in C++. 
The game consists of a paddle that the player moves horizontally to bounce a ball up towards a wall of bricks.
 The player must destroy all the bricks to complete the level and move on to the next one. The ball bounces off 
 the bricks and the walls, and the paddle can be used to control the angle at which the ball bounces.

# How to Play

Move the paddle left and right using the arrow keys.
Try to hit the ball with the paddle to keep it bouncing up towards the bricks.
Destroy all the bricks to complete the level.
If the ball falls off the bottom of the screen, you lose a life. You have three lives to start with.
After losing a life, the ball and the bricks reset to their starting positions.
If you lose all your lives, the game is over.


# How to Build

To build the game, you will need to have the SFML library installed on your system. Follow the
 instructions on the SFML website to install the library for your platform.

Then, clone the repository and navigate to the directory containing the source code. Compile the code using a 
C++ compiler, linking against the SFML library. For example, using g++:

Run main.cpp with g++ main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
./main  after SFML is completely install.

then finally run the executable with ./main

### More upgrades incoming..