# Array
- One of the basic clases implemented by the STL is array class.
- The `array` is a collection of homogeneous objects and this array container is defined for constant size arrays or (static size).
- `array` is based on array data-structure.
- Header file: `#include <array>`.
- The `array` class is a part of the `std namespace`.
- Size needs to be mentioned during creation and it cannot be changed.
## How to create an array object?
```c++
array <int, 3> a1 = {10, 20, 30};
array <int, 3> a2;  // contains garbage values
array <int, 3> a3 = a1;
array <int, 5> a5 = {11, 12, 13}; // Remaining elements are 0
```
## Accessing array elements
- `[]` - no bound checking.
- `at()` - bound checking.
```c++
array <int, 5> a1 = {50, 40, 30, 20, 10};
cout<<a1[5];    // prints garbage
cout<<a1.at(5)  // throws an exception of out_of_range
```
- `Implicit Iterator`
```c++
array <int, 5> a1 = {50, 40, 30, 20, 10};
for(auto x:a1)
    cout<<x<<", ";
```
- `Explicit Iterator`
Iterator objects can be obtained from the following members of array class:
    - `begin()/end()` - iterator (**read/write**)
    - `cbegin()/cend()` - const_iterator (**read only**)
    - `rbegin()/rend()` - reverse_iterator (**read/write**)
    - `crbegin()/crend()` - const_reverse_iterator (**read only**)
<br><br>
<img src="./Pics/begin_end.png" width="300" height="130">
<img src="./Pics/rbegin_rend.png" width="300" height="130">
<br><br>

```c++
array <int, 6> a1 = {10, 20, 30, 40, 50, 60};

    array <int, 6>::iterator it;
    for(it=a1.begin(); it!=a1.end(); it++)
        cout<<*it<<", ";
    //output: 10, 20, 30, 40, 50, 60

    array <int, 6>::const_iterator c_it;
    for(c_it=a1.cbegin(); c_it!=a1.cend(); c_it++)
        cout<<*c_it<<", ";
    //output: 10, 20, 30, 40, 50, 60

    array <int, 6>::reverse_iterator r_it;
    for(r_it=a1.rbegin(); r_it!=a1.rend(); r_it++)
        cout<<*r_it<<", ";
    //output: 60, 50, 40, 30, 20, 10

    array <int, 6>::const_reverse_iterator c_r_it;
    for(c_r_it=a1.crbegin(); c_r_it!=a1.crend(); c_r_it++)
        cout<<*c_r_it<<", ";
    //output: 60, 50, 40, 30, 20, 10
```
## Other Important methods of array class
- `fill(<data>)` - specially used to initialize or fill all the indexes of the array with a similar value.
- `back()` - returns last element.
- `front()` - returns first element.
- `empty()` - returns true or false.
- `data()` - returns a direct pointer to the memory array used internally by the array to store its owned elements.
- `size()` - returns number of elements in array.
- `sizeof()` - returns total size of array in bytes.
- `swap()` - swap the elements of two arrays.
