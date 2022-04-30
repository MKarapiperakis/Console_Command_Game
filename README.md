# Console_Command_Game
A simple Console Command Game, made in C.

## Description

There is a matrix with blocks, each one represented by a color(1-9). The point is to finish all levels.To finish a level, you have to break every single block and then you move to the next level, which contains one more row and one more column with blocks.

## How to play

First of all, you have to give the initial dimensions of the table(4-10) and the number of different colours, that we are going to have. The first level is a 4x4 matrix and the final level is a 10x10 matrix, but it's not necessary to begin from the first level. It's up to you, when you choose the initial dimensions. To break a block you can use one of the following "guns":
* BOMB
  ### A bomb explodes every block around our target with range 1.
* HAMMER
  ### A hammer destroys every single block next to our target, that has the same color with it and is connected with the first one through blocks with the same color.
  
When you break a block, there is a **Gravity** feature, that makes the blocks above the broken to falling down until they meet another block, that is not broken yet.
Also, if there are empty columns, you can push all blocks to the left, or to the right. Finally there is the oportunity to add a new block, by giving the position and the color you desire.
## Available Moves

When you start the game, each time you have 4 available moves:
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

* ADD BLOCK
 ```bash
a <row>,<column> <color>
```

For example, if you want to add a new block with color: "3" in the first position of our matrix, you give the following command:
 ```bash
a 1,1 3
```

## Run the program

Our project is made in [C](https://en.wikipedia.org/wiki/C_(programming_language)#:~:text=C%20is%20an%20imperative%20procedural,all%20with%20minimal%20runtime%20support.), so you are going to need a C Compiler in case to run it. The only thing you have to do is to open a terminal, compile the code and run the executable:

```bash
gcc -o game game.c
game
```



![1](https://user-images.githubusercontent.com/80547372/166111455-6bcf1c7e-d81c-49b1-80d3-6fad28540c0f.PNG)

![2](https://user-images.githubusercontent.com/80547372/166112482-5db78a3d-61c0-4110-a4e0-beb1b027b00f.PNG)

![3](https://user-images.githubusercontent.com/80547372/166112486-cc1f7eae-fd57-4dd4-bd84-b53a716eca23.PNG)

![4](https://user-images.githubusercontent.com/80547372/166112488-c87751cf-20d0-4778-9da5-89388637810d.PNG)

