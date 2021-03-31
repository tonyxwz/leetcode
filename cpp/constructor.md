# Constructor initialization list

## Use case

- initialization of non-static const member (const)
- initialization of reference member (int&)
- initialization of member without default constructor
- initialization of base class members (call the base class constructor in
  initialization list)
- argument name is the same as the member name (either use `this` pointer or
  initialization list)
- it's always advised to use initilization list when possible.
