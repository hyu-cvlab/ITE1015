# Creative Software Programming Practice (week-13-1)

Every assignment will be announced on **Thursday** and should be sumitted by next **Thursday**.

We have practice classes on Wednesdays and Thursdays. 
The contents of the practice class are different from the assignments and aim to be completed on the same day.

Assignments will be publish on Thursday and must be submitted by the next Tuesday.

In this week **Handed out will be Nov 26, 2020, Due Dec 3, 2020**

This exercise consists of several quizzes. Guess the results before running.

You should be able to explain why you are getting such a result.


```c++
// p1.cc
#include <iostream>

template <typename T>
void f(T a) {
    std::cout << "template function call" << std::endl;
}

void f(int a) {
    std::cout << "int function call" << std::endl;
}

void f(size_t a) {
    std::cout << "size_t function call" << std::endl;
}

void f(float a) {
    std::cout << "float function call" << std::endl;
}

int main() {
    f("3");
    f(3.f);
    f(3.0);
    f(3);
    f(static_cast<size_t>(3));
}
```


```c++
// p2.cc
#include <iostream>

void f(char*&&) { std::cout << 1 << std::endl; }
void f(char*&) { std::cout << 2 << std::endl; }

int main() {
   char c = 'a';
   f(&c);
}
```


```c++
// p3.cc
#include <iostream>

void f(unsigned int) { std::cout << "u" << std::endl; }
void f(int)          { std::cout << "i" << std::endl; }
void f(char)         { std::cout << "c" << std::endl; }

int main() {
    char x = 1;
    char y = 2;
    f(x + y);
}
```


```c++
// p4.cc (difficulty)
#include <iostream>

template<typename T>
void f(T) {
    std::cout << "Template called" << std::endl;;
}

struct S {
};


template<typename T>
void call_f(T t) {
  f(S());
  f(t);
}

void f(S) {
  std::cout << "Struct called" << std::endl;;
}

int main () {
  call_f(S());
}
```


```c++
// p5.cc
#include <iostream>
struct X {
    virtual void f() const {
        std::cout << "X called" << std::endl;
    }
};

struct Y : public X {
    void f() const {
        std::cout << "Y called" << std::endl;
    }
};

void print(const X &x) {
    x.f();
}

int main() {
  X arr[1];
  Y y1;
  arr[0] = y1;
  print(y1);
  print(arr[0]);
}
```


```c++

```
