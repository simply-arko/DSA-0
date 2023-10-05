# List
- List Class is a sequential container.
- list is based on **doubly Linked-List**.
- Header file: `#include <list>`
- list provides `bi-directional` iterator.
## How to create a list object?
```c++
list <int> l1{10, 20, 30, 40};
list <int> l2;
list <int> l3(n,0); // n size with all values 0
list <int> l3 = l1;
```
## Accessing list elements
- `Implicit Iterator`
```c++
list <int> l = {50, 40, 30, 20, 10};
for(auto x:l)
    cout<<x<<", ";
```
- `Explicit Iterator`
Iterator objects can be obtained from the following members of array class:
    - `begin()/end()` - iterator (**read/write**)
    - `cbegin()/cend()` - const_iterator (**read only**)
    - `rbegin()/rend()` - reverse_iterator (**read/write**)
    - `crbegin()/crend()` - const_reverse_iterator (**read only**)

```c++
list <int> l{10, 20, 30, 40, 50, 60};

list <int>::iterator it;
for(it=l.begin(); it!=l.end(); it++)
    cout<<*it<<", ";
//output: 10, 20, 30, 40, 50, 60

list <int>::const_iterator c_it;
for(c_it=l.cbegin(); c_it!=l.cend(); c_it++)
    cout<<*c_it<<", ";
//output: 10, 20, 30, 40, 50, 60

list <int>::reverse_iterator r_it;
for(r_it=l.rbegin(); r_it!=l.rend(); r_it++)
    cout<<*r_it<<", ";
//output: 60, 50, 40, 30, 20, 10

list <int>::const_reverse_iterator c_r_it;
for(c_r_it=l.crbegin(); c_r_it!=l.crend(); c_r_it++)
    cout<<*c_r_it<<", ";
//output: 60, 50, 40, 30, 20, 10
```

## Methods of list class
- `begin()` - returns an iterator pointing to  the first element of the list.
- `end()` - returns an iterator pointing to the theoretical last element which follows the last element.
- `back()` - returns last element.
- `front()` - returns first element.
- `empty()` - returns true or false.
- `size()` - returns number of elements in list.
- `swap()` - swap elements of two lists.
- `clear()` - erase all the elements of list.
- `merge()` - merges two sorted lists into one.
- `push_back()` – Push a new element into a at the end of the list.
- `push_front()` – Push a new element into a at the beginning of the list.
- `pop_back()` – Removes the last element of the list, and reduces the size of the list by 1.
- `pop_front()` - Removes the first element of the list, and reduces the size of the list by 1.
- `emplace()` – It extends the container by inserting new element at position
- `emplace_back()` – It is used to insert a new element into the list container, the new element is added to the end of the list.
- `emplace_front()` – It is used to insert a new element into the list container, the new element is added to the front of the list.
- `reverse()` - Reverses the list.

## **`insert()`** in list
Insert one or more elements.
- `l.insert(it, element)` - insert single element before the element specified by `it`.
- `l.insert(it, frequency, element)` - insert a element multiple times before the element specified by `it`.
- `l.insert(it, {e1, e2, e3...})` - insert few elements before the element specified by `it`.

## **`erase()`** in list
- `l.erase(it)` - erase an element of vector.
- `l.erase(it1, it2)` - erase a range of elements of vector (*it1* is inclusive and *it2* is exclusive).