Rvalue reference
================

Move Semantics
--------------
[source](./move-sematics.cpp)
Move sematics can happen when
1. the object is passed as a rvalue
2. move constructor of the object is define

Perfect Forwarding
------------------
[source](./perfect-forwarding.cpp)
- No expensive and unnecessary copy construction is made.
- If argument is passed as lvalue, then it is forwarded as lvalue.
- If argument is passed as rvalue, then it is forwarded as rvalue.
