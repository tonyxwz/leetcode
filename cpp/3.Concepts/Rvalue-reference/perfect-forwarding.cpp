#include "movable_array.hpp"

void
foo(MovableArray a);

template<typename T>
void
relay(T arg)
{
  // this is not perfect forwarding because arg because if arg is passed as
  // rvalue, foo(arg) is passed as lvalue.
  foo(arg);
}

// Solution is add && to template argument and usd std::forward
template<typename T>
void
relay(T&& arg)
{
  foo(std::forward<T>(arg));
}

/* =============================================================================
 *                        Reference collapsing rules
 * 1. T& &   => T&
 * 2. T&& &  => T&
 * 3. T& &&  => T&
 * 4. T&& && => T&&
 *
 * conclusion: single & is infectious.
 *
 * T&& is called by Scott Meyers as universal reference in template.
 * Note that in template programing, if a template is instantiated with
 * reference type, then `T` is `int&`. T& becomes reference to reference.
 * conditions:
 * 1. T is a template type
 * 2. Type deduction happens to T (T is in function template).
 *
 */
