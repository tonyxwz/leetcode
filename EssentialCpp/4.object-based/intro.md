# Object-based vs. Object-oriented

object-based: just everything is a object.
object-oriented: relations such as inheritance

## Things to remember

### initialization

brace initialization doesn't allow narrowing (https://stackoverflow.com/a/18222927). Values won't get implicit converted if target cannot hold its value.

member initialization_list: the comma separated list after `:` at the definition of constructor function. Use it because you don't want to wait until the members are initialized. at the moment when the initialization list is handled, the object is not initialized yet.

default member-wise initialization
  not enough for class managing resources (heap)
explicit -> copy constructor

rule of three (pre-Cpp11)
- destructor
- copy assignment operator
- copy constructor

rule of five (post-cpp11)
- move constructor
- move assignment operator

### mutable and const

const can appear in the definition of class member function
```cpp
ClassName {
  void method(int a, int b) const;
}
...
void ClassName::method(int a, int b) const {
  ...
}
```
tells the compiler that this member method won't change the object at all, the compiler will check for it. If it is not true, will raise compiler error.
This is because the `this` pointer in a `const` member function is a const pointer.

const object / reference / pointer could only call const methods.

**mutable**: some helper member variable are not essential to the class. changing them logically doesn't change the const'ness of the object. We mark these variables as `mutable` so that they can be changed via const reference.

### Static class member

static class member only have one entity in the whole program. It must have a clear definition somewhere in the code.

```cpp
class SomeClass {
public:
    // declaration
    static vector<int> a_static_vector;
private:
    static vector<int> a_static_private_vector;
    // c++ 11 (otherwise, error: non-const static member must be initialized out of line)
    inline static vector<int> second_static_vector(100, 0);
}


static vector<int> SomeClass::a_static_member;
static vector<int> SomeClass::a_static_private_vector;

```

Static member function can only use the static member variables in the class.

When defining the static member funciton / variables, the static keyword is not
required.

