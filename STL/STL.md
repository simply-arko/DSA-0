# What is STL?
`Standard Template Library (STL)` is a software library originally designed by Alexander Stepanov for the C++ programming language that influenced many parts of the C++ Standard Library.
- STL provides a set of common classes for c++ such as `containers` and `associative arrays`, that can be used with any built-in type & with any user-defined type.
- **STL Algorithms** are independent of containers which significantly reduces the complexity of the library. STL Algorithms directly do not interact with the containers themselves but rather with **iterators**.
- STL achieves its results through the use of **templates**.
- STL provides 3 types of components:
    * Containers
    * Iterators
    * Algorithms

## Containers:
- STL provides various type-safe containers for storing collection of related objects.
- The containers are class templates.
- When you declare a container variable, you specify the type of elements that the container 'll hold.
- Containers can be constructed with initializer lists. They have member functions for adding elements, removing elements and doing other operations.
- One can iterate over the elements of a container, and access the individual elements using `iterators`.
- One can use the iterators explicitly by using their member functions and operators & global functions.
- One can also use them implicitly, e.g. by using a **range-for-loop**.
### Types of Containers:
- **`Sequence Containers`** maintain the ordering of inserted elements that you specify.
    - `vector` - Dynamic Arrays.
    - `array` - not resizable.
    - `deque` - Doubly ended queue.
    - `list` - Doubly ended List.
    - `forward list` - Single Linked-List.
- In **`Assoicative Containers`** the elements are inserted in pre-defined order. *Eg*, as sorted ascending. Un-ordered associative containers are also available.
    - `set` - RBT (Red-Black tree)
    - `map` - RBT (Red-Black tree)
    - `multiset` - RBT (Red-Black tree)
    - `multimap` - RBT (Red-Black tree)
    - `unordered_set` - Hashtable
    - `unordered_map` - Hashtable
    - `unordered_multiset` - Hashtable
    - `unordered_multimap` - Hashtable
    - A `map` is somtimes reffered to as dictionary, consists of key-value pair. The key is used to order the sequence & the value associated with that key.
    - A `set` is just like an ascending container of unique elements. Here the **key = value**.
    - In `multimap` & `multiset`, duplicate keys are allowed.
    - `Ordered` map and set supports **Bi-directional** iterators.
- **`Container Adapters`** <`stack`, `queue`, `priority_queue`> is variation of sequence containers that restricts the interface for simplicity and clarity. Container adapters do not support adapters, as a result of which the cannot be used with STL Algorithms.

## Iterators:
- An `iterator` is an object that can iterate over the elements in a container and provide access to individual elements.
- Types of Iterators:
    - `input iterators` - only reading.
    - `output iterators` - only writing.
    - `Forward iterators` - read & write, move forward only.
    - `Bidirectional iterators` - read & write, move forward & backward.
    - `random access iterators` - read & write, move freely any no. of steps.
## Funtors
Also known as function objects.
- `Functors` is any type that implements `operator ()`.
- `()` is called call operator.
- STL uses function objects primarily as sorting criteria for containers and in Algorithms.
```c++
class Funtor{
    public:
        int operator()(int a, int b){
            return a>b;
        }
};
int main(){
    Funtor F;
    cout<<F(5,7);   // It looks like a function call but it is an object calling the operator().

    return 0;
}
```
- Advantages:
    - It is an object, therefore it may contain state.
    - It is a type, therefore it can be used as a template parameter.
    