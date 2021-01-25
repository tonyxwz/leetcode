# Why rust

Type safety is the problem solved by rust without introducing reference counting and garbage collection.

## Reading Rust

Rust's special syntax or patterns

1. Generics, similar to templates in C++ and generics in Java
2. Enumeration
3. Traits

## Memory Safety

Rust memory safety is guaranteed at compile time. At run time, the program just use raw pointers just like in C++. The rust compiler does all kinds of checking before compiling the program. (part of the reason why it is slow)

### No `nullptr`

`nullptr` is considered a flaw in the rust's pattern, though very useful. Null is mainly used to represent something that doesn't not exist, such as file descriptors, number returned by a function & etc. Rust separates the concept of a pointer and an optional value, using `Option` and `Result` enums.

P.S. rust macro `try` is replaced by the `?` operator. Use that instead. The reason why we could return "different" types of `io::Error` is that `?` operator wraps `io::Error` with `Err` (`Err(io::Error)`), which is a variant of enum `io::Result`.

### No dangling pointers

Dangling pointers are pointers pointing to invalid resource (e.g. freed heap data).

> Rust introduces three rules the specify when each value is freed, and ensure that all the pointers to it are gone by that point.

#### Rule 1
 
> Every value has a single owner at any given time. You can move a value from one owner to another, but when a value’s owner goes away, the value is freed along with it.

Similar to C++ where resources are managed by class, in rust the resource could only have one owner at one time. Hence, when the owner goes out of the scope, the resource that is managed by it is dropped. Assignment moves the value rather than copying. This is also made possible in C++ 11 where the move sematic is introduced. This solved the problem of determining when to drop the resources. It is still possible, though, to share the resources between two variable, as long as only one of them owns the data. The other one only borrows the data. Rust also have auto-dereferencing, which simplifies the notation is a value is borrowed many many times (no need to write * like in C++). In Rust, types are divided into two categories
   1. those copied on assignment
   2. those moved
New user defined structs are required to implement `Copy` trait if it should be copied on assignment. `impl Copy for MyCopyStruct {}`

#### Rule 2

> You can borrow a reference to a value, so long as the reference doesn’t outlive the value (or equivalently, its owner). Borrowed references are temporary pointers; they allow you to operate on values you don’t own.

Rule 1 explains the value's lifetime, Rule 2 constrains borrowed reference from outliving the value itself.

#### Rule 3

> You can only modify a value when you have exclusive access to it.

This means that:
1. While you borrow a shared reference to a value, nothing can modify it or cause it to be dropped.
2. While you borrow a mutable reference to a value, the mutable reference is the only way to modify the value.

Fix: specify lifetime explicitly

Lifetime of reference
1. reference *type* with inferred lifetime: `&i32`
2. reference *type* with explicit lifetime: `&'a i32`, `&'b mut i32`

```rust
fn firsts<'a, 'b>(x: &'a Vec<i32>, y, &'b Vec<i32>) -> (&'a i32, &'b i32) {
 ......
}
```
This means that function `first` is **generic** on any pairs of lifetime.

### Fearless concurrency

Rust's three ownership and lifetime principles also helps to make it easier to write concurrent code. 


1. std::sync::mpsc::channel
2. std::thread::spawn
3. std::thread::scoped -> is removed from rust 2018 for being not safe to use, there are third party libraries supporting this.

*Continue*: the rust book, fearless concurrency

