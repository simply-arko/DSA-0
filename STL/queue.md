# Queue
- `Queue` is a template container adapter class that provides a restriction of funtionalities, limiting access to the front and back elements.
- Elements can be `added at the back` or `removed from the front`, and elements can be inspected at either end of the queue.
- The queue class supports `FIFO` data structure.
- `queue` can be used as an implementation of deque, list or any other sequence container that supports the operations of **back()**, **push_back()** and **pop_back()**.
- The *underlying container class* is encapsulated within the container adaptor, which exposes only the limited set of the sequence container member functions as a public interface.
- Header file: `#include <queue>`
## How to create an queue object?
```c++
queue <int> q1;
queue <int, vector<int>> q2;
queue <int, list<int>> q3;
```
## Methods of queue
- `back()` - Returns a reference to the last element of the queue.
- `front()` - Returns a reference to the first element of the queue.
- `empty()` - Returns whether the queue is empty.
- `pop()` - Deletes the first element of the queue.
- `push()` - Adds an element at the end of the queue.
- `size()` - Returns the size of the queue.
- `swap()` - Exchange the contents of two queues but the queues must be of the same data type, although sizes may differ.
- `emplace()` - Insert a new element into the queue container, the new element is added to the end of the queue.