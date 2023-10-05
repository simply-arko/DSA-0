# Forward List
- The forward list class is a *sequetial container*.
- `forward_list` is based on singly **Linked-List**.
- Header file: `#include <forward_list>`
- It provides only `forward iterator`.
## How to create a list object?
```c++
forward_list <int> l1{10, 20, 30, 40};
forward_list <int> l2;
forward_list <int> l3(n,0); // n size with all values 0
forward_list <int> l3 = l1;
```
## Accessing list elements
- `Implicit Iterator`
```c++
forward_list <int> l = {50, 40, 30, 20, 10};
for(auto x:l)
    cout<<x<<", ";
```
- `Explicit Iterator`
Iterator objects can be obtained from the following members of array class:
    - `begin()/end()` - iterator (**read/write**)
    - `cbegin()/cend()` - const_iterator (**read only**)
    - `before_begin()` - Returns an iterator that points to the position before the first element of the forward_list.
    - `cbefore_begin()` - Returns a constant  iterator which points to the position before the first element of the forward_list.

```c++
forward_list <int> l{10, 20, 30, 40, 50, 60};

forward_list <int>::iterator it;
for(it=l.begin(); it!=l.end(); it++)
    cout<<*it<<", ";
//output: 10, 20, 30, 40, 50, 60

forward_list <int>::const_iterator c_it;
for(c_it=l.cbegin(); c_it!=l.cend(); c_it++)
    cout<<*c_it<<", ";
//output: 10, 20, 30, 40, 50, 60
```

## Methods of list class
- `begin()` - returns an iterator pointing to  the first element of the list.
- `end()` - returns an iterator pointing to the theoretical last element which follows the last element.
- `back()` - returns last element.
- `front()` - returns first element.
- `empty()` - returns true or false.
- `size()` - returns number of elements in forward_list.
- `swap()` - This function swaps the content of one forward list with other. 
- `clear()` - erase all the elements of forward_list.
- `merge()` - This function is used to merge one forward list with other. If both the lists are sorted then the resultant list returned is also sorted. 
- `push_front()` – Push a new element into a at the beginning of the forward_list.
- `pop_front()` - Removes the first element of the forward_list, and reduces the size of the list by 1.
- `emplace_after(it, element)` – It is used to insert a new element into the forward_list container, the new element is added after the element spcified by *it*.
- `emplace_front(element)` – It is used to insert a new element into the forward_list container, the new element is added to the front of the list.
- `insert_after(it, element)` - It is used to insert a new element into the forward_list container, the new element is added after the element spcified by *it*.
- `reverse()` - Reverses the forward_list.
- `sort()` - sort the forward_list.