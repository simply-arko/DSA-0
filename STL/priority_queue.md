# Priority Queue
- `priority_queue` is a template adaptor class that provides a restriction of funtionality limiting access to the top element of some underlying container type, which is always the largest or the highest priority.
- New elements can be added to the priority_queue and the `top element` of the priority_queue can be *inspected* or *removed*.
- Suitable container classes for priority queue includes deque class, `vector class (by default)` or any other sequence container that supports the operations of **front()**, **push_back()** and **pop_back()** and a **random access iterator**.
- The `underlying container class` is encapsulated within the container adaptor, which exposes only the limited set of sequence container member functions as a public interface.
- Header file: `#include <queue>`

## How to create an priority_queue object?
```c++
priority_queue <int> q1;
priority_queue <int, vector<int>> q2;
priority_queue <int, list<int>> q3;
```
## Methods of priority_queue
- `empty()` - Returns whether the queue is empty.
- `size()` - Returns the size of the queue.
- `top()` - Returns a reference to the topmost element of the queue.
- `push()` - Adds an element according to its priority in the priority queue.
- `pop()` - Deletes the first element of the queue.
- `swap()` - Used to swap the contents of two queues provided the queues must be of the same type, although sizes may differ.
- `swap()` - Used to insert a new element into the priority queue container.
- `emplace` - Used to insert a new element into the priority queue container (according to its priority).
- `value_type` - Represents the type of object stored as an element in a priority_queue. It acts as a synonym for the template parameter.

## NOTE:
- By default declaration of priority_queue it's a `max Heap`.
- Syntax to create a `min Heap`:<br>
```c++
priority_queue <int, vector<int>, greater<int>> pq;
```
- For non-primitive data types `comparators` are needed to be passed as argument while declaring priority_queue.
- This is achieved by `Functor` class.

## How to create prioriity_queue for non-primitive type?
```c++
class Employee{
    private:
        int emp_id;
        string name;
        float salary;
    public:
        Employee(int emp_id, string name, float salary):emp_id(emp_id), name(name), salary(salary){}
        float getSalary(){return this->salary;}
};

class compareSalary{
    public:
        bool operator()(Employee &e1, Employee &e2){
            return e1.getSalary()<e2.getSalary();   //max_heap
        }
};

int main(){

    priority_queue<Employee, vector<Employee>, compareSalary> pq;
    
}
```