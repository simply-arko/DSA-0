# Deque
- The deque class is a *sequential Container*.
- `deque` is based on **doubly-ended queue**.
- Header file: `#include <deque>`.
- `deque` provides **random access iterator**.
## How to create an vector object?
```c++
deque <int> d1{10, 20, 30};
deque <int> d2;  // capacity is 0
deque <int> d3(n, 0);  // n size with all values 0
deque <int> d4 = d2;
```
## Accessing deque elements
- `[]` - no bound checking.
- `at()` - bound checking.
```c++
deque <int> d1 = {50, 40, 30, 20, 10};
cout<<d1[5];    // prints garbage
cout<<d1.at(5)  // throws an exception of out_of_range
```
- `Implicit Iterator`
```c++
deque <int> d = {50, 40, 30, 20, 10};
for(auto x:d)
    cout<<x<<", ";
```
- `Explicit Iterator`
Iterator objects can be obtained from the following members of array class:
    - `begin()/end()` - iterator (**read/write**)
    - `cbegin()/cend()` - const_iterator (**read only**)
    - `rbegin()/rend()` - reverse_iterator (**read/write**)
    - `crbegin()/crend()` - const_reverse_iterator (**read only**)

```c++
deque <int> d{10, 20, 30, 40, 50, 60};

deque <int>::iterator it;
for(it=d.begin(); it!=d.end(); it++)
    cout<<*it<<", ";
//output: 10, 20, 30, 40, 50, 60

deque <int>::const_iterator c_it;
for(c_it=d.cbegin(); c_it!=d.cend(); c_it++)
    cout<<*c_it<<", ";
//output: 10, 20, 30, 40, 50, 60

deque <int>::reverse_iterator r_it;
for(r_it=d.rbegin(); r_it!=d.rend(); r_it++)
    cout<<*r_it<<", ";
//output: 60, 50, 40, 30, 20, 10

deque <int>::const_reverse_iterator c_r_it;
for(c_r_it=d.crbegin(); c_r_it!=d.crend(); c_r_it++)
    cout<<*c_r_it<<", ";
//output: 60, 50, 40, 30, 20, 10
```
## Methods of deque class
- `begin()` - returns an iterator pointing to  the first element of the list.
- `end()` - returns an iterator pointing to the theoretical last element which follows the last element.
- `back()` - returns last element.
- `front()` - returns first element.
- `empty()` - returns true or false.
- `size()` - returns number of elements in deque.
- `push_back()` – It pushes the elements into a deque from the back.
- `emplace_back()` – It is used to insert a new element into the deque container, the new element is added to the end of the deque.
- `push_front()` - It pushes the elements into a deque from the front.
- `emplace_back()` – It is used to insert a new element into the deque container, the new element is added to the front of the deque.
- `pop_back()` – It pops or remove elements from a vector from the back.
- `emplace()` – It extends the container by inserting new element at position.
- `insert()` - Insert elements in same fashion as vectors.
- `erase()` - Erase elements in same fashion as vectors.
- `clear()` - remove all the elements of the deque container, thus making its size 0.
