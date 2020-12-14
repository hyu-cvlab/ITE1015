# Creative Software Programming Assignment#12 (week-12)

Every assignment will be announced on **Thursday** and should be sumitted by next **Thursday**.

In this week **Handed out will be Nov 20, 2020, Due Nov 26, 2020**

- week-12
    - vector.h
    - main.cc (is optional, for your own debug)
    - report.pdf (or something readable format)
        - Describe what considerations you have made while implementing the code and why.

This assignment is to implement vector without `std::vector`.

You must implement below method and operators similar to `std::vector`.
It doesn't matter how different the actual vector container works. The methods just need to work.

- capacity
- size
- empty
- clear
- insert
- erase
- push_back
- pop_back
- resize
- operator[]

And optional operator (you can search about ostream and istream)
- operator <<
    - stream out the element with comma(,)
    - `friend ostream& operator<<(ostream& out, Vector<T>& vector);`
- operator >>
    - stream in push_back to Vector
    - `friend istream& operator<<(istream& out, Vector<T>& vector);`


Additionally, you get extra points by implementing a method like a real vector container. See also [cppreference page](https://en.cppreference.com/w/cpp/container/vector)

- iterator
- const_iterator
- reverse_iterator
- const_reverse_iterator
- reference
- const reference
- opeerator=
- assign
- begin/end
- cbegin/cend
- rbegin/rend
- crbegin/crend



```c++
// vector.h
template <typename T>
class Vector {
private:
    T* elements;

public:
    Vector()
    : elements(nullptr) {}
    ~Vector();
}
```


```c++

```
