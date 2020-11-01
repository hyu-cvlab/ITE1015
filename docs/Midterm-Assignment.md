# Creative Software Programming Midterm Assignment

**Due Oct 27, 2020**

## Cube

You are trapped in a space connected by tons of cubes. Each cube has an up, down, left and right passage, and each passage leads to another cube. You want to draw a map based on the path you have taken to get out of this cube. Read the following examples and restrictions carefully and implement them accordingly.

Initially, the cube's information is entered. In the first line, the number of cubes ($N$) is entered, the name of the cube from the next line to the $N$ line, and the name of the cube connected up, down, left and right (if cube is not connected, 0 is given). If you try to move in a direction where there is no passage, it will come back into place.

After then you are given $M$ actions. Up, down, left, right or cube status update information is given during the next $M$ lines.

You starts with the first given cube name. Up, down, left, and right means that you moved up and down, left and right cube. Cube update is given the cube name, and the up, down, left and right cube name is given again. After this line is executed, it means the cube structure has changed. 

After then, Just print the name of cubes you have passed in reverse order.  (No need to print on the line where the cube was updated)

*Cubes are a strange dimensional space. So, You may not be able to go back the way you came*

**Assignment Structure**
- midterm
    - cube.cc
    - report.pdf (or something readable format)

**Write the code and explain the structure, write a report explaining how you approached it. (1-3 page with codes)**

**Input Example**

```
3
A B C D 0
B C D 0 0
C E F 0 0
4
up        // now your in B, because A's up is B
up        // now your in C, because B's up is C
C A B C D // change C's up, down, left and right as A, B, C, D
up        // now your in A, because C's up is updated to A (origin is E)
```

**Output Example**

```
A
C
B
```

First from A, it is B when it goes up, and C when it goes up again. There, the state of C has changed to up,down,left,right = A,B,C,D, so if you go up again, it will return to A.

Since we have passed A->B->C->A, we need to print A, C, B in reverse order. (Excluding starting point A)


```python
#include <iostream>
#include <string>

class Cube {
public:
    std::string name;
    Cube *up, *down, *left, *right;

    Cube()
    : up(nullptr), down(nullptr), left(nullptr), right(nullptr) {

    }
};

int main() {

    return 0;
}
```
