# Consol_Command_Game
A simple console command Game made in C.

## Description

There is a matrix with blocks, each one represented by a color. The point is to finish all levels.To finish a level, you have to break every single block and then you move to the next level, which contains one more row and one more column with blocks.

## How to play

First of all, you have to give the initial dimensions of the table(4-10) and the number of different colours, that we are going to have. The first level is a 4x4 matrix and the final level is a 10x10 matrix, but it's not necessary to begin from the first level. It's up to you, when you choose the initial dimensions. To break a block you can use one of the following "guns":
* BOMB
  ### A bomb explodes every block around our target with range 1.
* HAMMER
  ### A hammer destroys every single block next to our target, that has the same color with it.
  
When you break a block, there is a **Gravity** feature, that makes the blocks above the broken to falling down until they meet another block, that is not broken yet.
Also, if there are empty columns, you can push all blocks to the left, or to the right.
## Available Moves

When you start the game, each time you have 3 available moves:
* BOMB
 ```bash
b <row>,<column>
```
For example, if you want to place a bomb in the first element of our matrix, you give the following command:
 ```bash
b 1,1
```

* HAMMER
 ```bash
h <row>,<column>
```

For example, if you want to use a hammer in the first element of our matrix, you give the following command:
 ```bash
h 1,1
```

* PUSH LEFT/RIGHT
```bash
pl
pr
```
## Run the program

Our project is made in [C](https://en.wikipedia.org/wiki/C_(programming_language)#:~:text=C%20is%20an%20imperative%20procedural,all%20with%20minimal%20runtime%20support.), so you are going to need a C Compiler in case to run it. The only thing you have to do is to open a terminal, compile the code and run the executable:

```bash
gcc -o game game.c
game
```





