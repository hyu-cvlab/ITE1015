# Test with testcase

Testing the program is a very important process. As you progress through the assignment, you may wonder the output of test case.
So, as you progress through the assignment, you can think about the expected outcome for specific input and check that the program is working properly.

We use standard input and output in the assignment, so we can get the result by typing in the shell.

However, it is inconvenient to enter the input into the shell each time, 
so we can put the test case file as input into the program through standard IO.

You can think of how to manage test cases through the example below.

First, build the source code for `the-starry-night.cc` in week-2 assignment.

The command below creates an executable file named `a.out` using `the-starry-night.cc` source code.


```c++
$ g++ the-starry-night.cc -o a.out
```

Then, create a test file named `input-a.txt` with the following information.


```c++
3
```

And run the program with this test file as input.

If you have written the program correctly, you can get the following result.


```c++
$ ./a.out < input-a.txt
*
**
***
```

Also we can also save these results to a file named `output-a.txt` for check later.


```c++
$ ./a.out < input-a.txt > output-a.txt
```

You can also check what is written in output-a.txt with the following command.


```c++
$ cat output-a.txt
*
**
***
```

Create several test cases and check if the program is well written according to the specifications


```c++

```
