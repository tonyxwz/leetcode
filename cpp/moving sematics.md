
[Stack overflow]( https://stackoverflow.com/a/15704602/5575055 ) 
[Wikipedia]( https://en.wikipedia.org/wiki/Copy_elision#Return_value_optimization )

Since the introduction of move sematics in C++ 11, the prefered way to reture a
`stl:: vector` is to return value, because vectors can be moved and C++
compilers have named return value optimization (RVO).

