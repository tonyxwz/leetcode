Inheritance and polymorphism
============================

Data access control
-------------------

- public: can be access from outside as well as inside the class and derived
    classes
- protected: can be access inside class and subclasses
- private: can only be access from this class, not even the subclasses


Inheritance level control
-------------------------

- public: inherit as it is
- protected:
- private:

Points
------

Only the interfaces declared in the base case could be accessed through a base
class pointer or reference. The virtual function invoked through base class
pointer is the implementation in the derived class.

It is not required to write keyword `virtual` in the derived class. Imaging you
need to add a virtual function interface for the base class. From this base
class have we derived many sub-classes. Then we need to add the keyword `virtual`
for every derived class, which could be a lot of work.

**how to choose between reference and pointer**
Reference vs. Pointers: reference can never be empty, so we don't need to
check empty elements. A reference member must be initialized in the constructor
function. Once initialized, it cannot be changed to refer to something else.

It is usually necessary to declare a **virtual destructor** for base classes so that
base class pointer or reference to subclasses will also manage the resources of
the derived classes.

Since a abstract class (a class with more than 1 pure virtual function) cannot
be initialized on its own, the constructor should be declared as `protected`.

The initialization of a derived class consists of the invocation of the base
class constructor followed by the derived class constructor.

Base class whose constructor asks for non-trivial arguments must be invoked
like this, otherwise the compiler will complain.
```cpp
inline Fibonacci::
Fibonacci(int len, int beg_pos)
    : num_sequence(len, beg_pos, &_elems)
{}
```
Alternatively, we could give the base class constructor some default parameters,
then if the derived class constructor doesn't invoke the base class constructor
explicitly, it is still invoked implicitly. However, we need to change the
reference to pointer and guard `nullptr` every time we access it.

Overriding a virtual function, the function signatures must match exactly, that
is the return type, arguments and cv-specifiers. It is recommended to add
`override` keyword when overriding a virtual function so that the compiler know
you intention well.

**Run-time type information (RTTI)**
```cpp
#include <typeinfo>
typeid(*this).name();  // no guarantees regarding the name
```

TODO
has-a, is-a relationship

