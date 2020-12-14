# Creative Software Programming Assignment#14 (week-14)

This assignment:
- **Handed out Dec 05, 2020**
- **Due Dec 17, 2020**

This assignment is to create a simple game named `2048`.

Initially, two integers $H$ and $W$ are given. These are the height and width respectively. ($1 \leq H, W \leq 100$)

If you can't move any more (any action looks the same as before), exit and print the score. The score is equal to the sum of all blocks currently stacked. (Print only one integer per line.)


**The game proceeds as follows**:

First, 2 is created in the top left corner.
Next, according to the input (up/down/left/right), the blocks move up/down/left/right. (See examples below)
After the block is moved as an input, a 2 is generated at a random location. (Use `Screen::create()`.)
After random create, print the current blocks. (Use `Screen::draw()`)
It repeats until the game is over.
Or, if a key other than `W A S D` (up/down/left/right) is input, print the current score and the program ends.

**Use the given skeleton code.**

**Examples**

*For easy understanding, 2 randomly generated removed after each action.*

In case of 
```
2,0,2,
2,4,0,
0,0,0,
```

after W inputed

```
4,4,2,
0,0,0,
0,0,0,
```

after D inputed

```
0,8,2,
0,0,0,
0,0,0,
```


```c++

```
