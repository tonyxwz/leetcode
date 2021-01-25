# Throw an exception

## What happens
exception happens
    -> program suspended
    -> exception handling mechanism started
    -> finished handling
    -> resume the program

## What to throw
simplest case: number string
complicated: an object of a certain exception class hierarchy


## Catch an exception
`catch` keyword only handles the exception matching its type

```cpp
catch (int errno) {
    // do something regarding exception of int type
}
catch (const char* str) {
    // do something regarding cstring type
}
catch (OverflowException &ofe) {
    // cannot handle this exception, passing it to the next level
    // throw with no arguments could only appear inside of catch
    throw;
}
```

catch any type
```cpp
catch (...) {
}
```

## Try
catch needs to be consumed with try

```cpp
try {

} catch () {

}
```

## C++ exception
C++ exception is differenct from hardware exceptions such as segmentation fault
of bus error.


## local resource management
resource acquisition is initialization

Resource acquisition should happen only in the constructor function. Resource
releasing should happen in destructor functions. This could simplify automatic
resource management.

Resources (memory, file descriptor, sockets and etc) should be managed by
classes. One class should only handle one resource.

## class `exception` from `<exception>`

There're also predefined exceptions in `<stdexcept>`
- `logic_error`
- `invalid_argument`
- `domain_error`
- `out_of_range`
...
https://en.cppreference.com/w/cpp/header/stdexcept

These are used massively in standard library.

Inherit from std::exception

Benefit: custom exceptions could be caught by any catch block targetting std::
exception.

```cpp
#include <exception>
class iterator_overflow: public: std::exception
{
public:
    iterator_overflow(int index, int max)
    : _index(index), _max(max)
    {}

    const char* what() const override;
private:
    int _index;
    int _max;
}

const char*
iterator_overflow::
what() const override {
    std::ostringstream oss;
    static string msg; // because we need to return by pointer
    oss << "Internal Error: current index: " << _index 
        << "exceeds maximum bound: " << _max;
    msg = oss.str();
    return msg.c_str(); 
    // no problem because msg is static member of which
    memory is persistent after function exits
}
```
