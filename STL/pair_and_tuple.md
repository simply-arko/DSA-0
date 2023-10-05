# Pair
- `pair` is a structure that provides for the ability to treat two objects as a single object.
- Header file: `#include<utility>`

## Creating pair
```c++
pair <int, double> p1{10, 3.14};
pair <int, string> p2;
p2 = make_pair(1, "New York");
pair <int, string> p4(p3);

// accessing pair elements:
cout<<p1.first();   //10
cout<<p1.second();  //3.14
```

## Methods of pair
- `swap()` - This function swaps the contents of one pair object with the contents of another pair object. The pairs must be of the same type. 
<br><br><br>

# Tuple
- A tuple is an object that can store a number of elements.
- The elements can be of different data-types.
- Header file: `#include<tuple>`
```c++
tuple<int, double, char> t1(1, 3.4, 'a');
tuple<int, double, char> t2;
t2 = make_tuple(2, 2.5, 'b');
tuple<int, double, char> t3(t2);

//accessing tuple elements:
cout<<get<0>(t1)<<get<1>(t1)<<get<2>(t1)
```
## Methods of tuple
- `swap()` - This function swaps the contents of one tuple object with the contents of another tuple object. The tuples must be of the same type. 