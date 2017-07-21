#

- Efficiency through algrithms
- Performance through data structure

```cpp
vector<X> f(int n) {
  vector<X> result; // bug
   // result.reserve(n);
  for (int i = 0; i < n; ++i) {
	result.push_back(X(...));
  return result;
  }
}
```

```cpp 
X * getX(string key, unordered_map<string, unique_ptr<X>> &cache) {
  if (cache[key])
    return cache[key].get();
  cache[key] = make_unqiue<X>(...);
  return cache[key].get();
}

X * getX(string key, unordered_map<string, unique_ptr<X>> &cache) {
  unqiue_ptr<X> &entry = cache[key];
  if (entry)
    return entry.get();
  entry = make_unqiue<X>(...);
  return entry.get();
}
```

### discontinugous data structures are the root of all performance evil
- just say no to linked lists
- std::List Only use this when you rarely traverse the list, but very frequently update the list
- stack -- Just use vector. 
- queue -- if the queue can have a total upper bound and/or is short-lived, consider using a vector
           with an index into the front
- using std::map is an exercise in slowing down code
- std::unordered_map
  - essentially required to be implemented with buckets of key-value pairs for each hash entry
  - there buckets are linked lists
  - you essentiallly always have some pointer chasing
  - A good hash table design
    - no buckets! use open addressing into a table of the key-value pairs
	- table stored as contiguous range of memeory
	- use local probing on collisions to find an open slot in the same cache line
	- keep both key and vlaues samll
- worse is better: bubble sort and cuckoo hashing
  - bubble sort is best alg when size is small
  
# High Performance code 201: Hybrid Data structures
```cpp
template <typename T, int N>
class SmallVector {
  T *Begin, *End;
  size_t Capacity;
  char Buffer[sizeof(T) * N];
  
 public:
  SmallVector() : Begin((T *)Buffer), End((T *)Buffer), Capacity(N) {}
  // ...
}
```



