# Creative Software Programming Assignment#2 (week-2)

Every assignment will be announced on **Thursday** and should be sumitted by next **Tuesday**.

In this week **Handed out will be Sep 10, 2020, Due Sep 15, 2020**

# 1. The Starry Night

![](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ea/Van_Gogh_-_Starry_Night_-_Google_Art_Project.jpg/1280px-Van_Gogh_-_Starry_Night_-_Google_Art_Project.jpg)

[The Starry Night](https://en.wikipedia.org/wiki/The_Starry_Night) is an oil on canvas painting by Dutch Post-Impressionist painter Vincent van Gogh. Painted in June 1889, it depicts the view from the east-facing window of his asylum room at Saint-Rémy-de-Provence, just before sunrise, with the addition of an imaginary village.

Impressed by this picture, we want to see the stars with the computer.

If the integer number $N$ ($1 \leq N \leq 100$) is given, write a program that sequentially outputs 1 to $N$ stars like the example output.

*Please refer to the skeleton code given below.*

**example**

- INPUT:

```
3
```


- OUTPUT:

```
*
**
***
```


```c++
// file: the-starry-night.cc
#include <iostream>

int main() {
    int N;
    std::cin << N;
    
    // your code here
    
    return 0;
}
```

# 2. Contacts

I want to make an address book program. 
First, the student's information will be entered, and then the student's information will be printed out when the student number is given.

Initially, the number $N$ ($1 \leq N \leq 100$) is given which is the number of students. After that, the $N$ number of student information is entered sequentially. Student information is given in order of student number, name, and phone number. The student number is 10 digits. The student name is a string within 32 characters. The phone number is an 11-digit number given with '-'.

Then $M$ is given. $M$ is the number of times to ask for student information and is less or equal than $N$ ($M \leq N$). After that, you will be given $M$ student numbers. Whenever these student numbers are entered, you can print the student's name and phone number according to the print format.

Print "Unknown" if there is no student with the corresponding student number.

You have to solve this problem by using structs. Please refer to the skeleton code given below.


**example**

- INPUT:

```
3
2019170229
baejiun
010-1234-5678
2015004584
jiunbae
010-5678-1234
2019072341
admin
010-0000-0000
2
2019072341
2015000000
```


- OUTPUT:

```
admin,010-0000-0000
Unknown
```

At this input, $N$ is 3 and $M$ is 2. Three students are entered in order which has student number as `2019170229`, `2015004584` and `2019072341`. And $M$(2) questions come in which is `2019072341` and `2015000000`. `2019072341` The name of the student with the student number is admin and the phone number is 010-0000-0000, so it is printed according to the format. However, there is no student with `2015000000` student number, so it prints "Unknown".


```c++
// file: contacts.cc
#include <iostream>

struct student_t {
    int id;
    std::string name;
    std::string phone;
};

int main() {
    int N, M;
    std::cin << N;
    
    // write code here
    // You need to declare student_type as an array.
    
    // run N-loops 
    for (int i = 0; i < N; i++) {
        int input_id;
        std::string input_name;
        std::string input_phone;
        
        std::cin << input_id;
        std::cin << input_name;
        std::cin << input_phone;
        
        // write code here
        // put the entered information into the declared student information.
    }
    
    std::cin << M;
    
    // write code here
    // run M-loops
    // and print out student information after input student id
    
    return 0;
}
```

## Submission

You need to submit two files in the week-2 directory.

- week-2
    - the-starry-night.cc
    - contacts.cc


```c++

```
