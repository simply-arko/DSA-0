# Stack
- `stack` is template container adapter class that provides a restriction of functionality limiting access to the element most recently added to some *underlying container type*.
- The stack class is used when it is important to be clear that only stack operations are being performed on the container.
- Stack can be used as an implementation of `deque (default)`, list, vector, or any other sequence container that supports the operations of **push_back()** and **pop_back()**.
- The underlying container class is **encapsulated** within the container adapter, which exposes only the limited set of sequence container member functions as a public interface.
- Header file: `#include<stack>`
- **No support of iterators**.
## How to create an stack object?
```c++
stack <int> s1; //by default deque.
stack <int, vector<int>> s2;
stack <int, list<int>> s3;
```

## Methods of Stack
- `empty()` - Returns whether the stack is empty.
- `size()` – Returns the size of the stack.
- `top()` – Returns a reference to the top most element of the stack.
- `push(element)` – Adds the element at the top of the stack.
- `pop()` – Deletes the most recent/top-most element of the stack.
- `swap()` - swap the contents of one stack with another stack of same type but the size may vary.
- `emplace()` - insert a new element into the stack container, the new element is added on top of the stack.