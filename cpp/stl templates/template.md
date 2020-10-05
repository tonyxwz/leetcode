# C++模板

模板是C++和其他编程静态类型编程语言的重要功能。在其他程序设计语言如rust中这一功能也被称为泛型编程（generics）或者元编程（metaprogramming）。
模板的实现有有很多不同的方式，但是这世界上没有银弹。模板也是有代价的。
模板的初衷是只需要一次编写，设计的类或者函数就能自动适应不同的数据类型。这一泛型的实现是在compile time。也就是说，指定的数据类型在编译时必须确定。
C++模板主要是在编译的时候进行类型关键字替换，即为每一个实例化的模板提供一个实现方式。具体可参见https://godbolt.org/。当使用不同的数据类型调用不同的函数模板时，生成的汇编代码为不同数据类型提供了不同版本。

From C++ Primer:
> Both object-oriented programming (OOP) and generic programming deal with types that are not known at the time the program is written. The distinction between the two is that OOP deals with types that are not known until run time, whereas in generic programming the types become known during compilation.

对于模板，对任意类型的支持是通过模板替换实现的。但是很明显C++语言的多态，如通过父类的指针操作子类的对象是动态类型的实现，不能简单的当作是对C语言编译器的扩充。有时间我会研究一下这个问题（TODO）。

用整型和浮点型实例化统一模板的汇编代码：
```cpp
template<typename T>
T square(T num) {
    return num * num;
}

int main(){
    int s = square<int>(5);
    float p = square<float>(9.0);
}
```

```assembly
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 16
        mov     edi, 5
        call    int square<int>(int)
        mov     DWORD PTR [rbp-4], eax
        movss   xmm0, DWORD PTR .LC0[rip]
        call    float square<float>(float)
        movd    eax, xmm0
        mov     DWORD PTR [rbp-8], eax
        mov     eax, 0
        leave
        ret
int square<int>(int):
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
        mov     eax, DWORD PTR [rbp-4]
        imul    eax, eax
        pop     rbp
        ret
float square<float>(float):
        push    rbp
        mov     rbp, rsp
        movss   DWORD PTR [rbp-4], xmm0
        movss   xmm0, DWORD PTR [rbp-4]
        mulss   xmm0, xmm0
        pop     rbp
        ret
.LC0:
        .long   1091567616
```


## 定义模板

C++中模板主要有两种，类模板和函数模板。

### 函数模板

为了使同一个函数支持不同的数据类型，我们首先可以选择函数重载。同一函数名有不同的函数签名就可以用到不同的数据类型上。但是这个方法需要重复写很多代码。使用模板可以解决这个问题。

```cpp
template<typename Tr, typename Ti>
Tr myfunction(Ti t1, Ti t2) {

}

// inline function template
template<typename T> inline T min(const T& a, const T& b) { ... }

// constexpr
tempalte<typename T> constexpr unsigned int sizeofx(const T& s) {return sizeofx(s);}

```

- `template`关键字
- `<>` 包含用`,`隔开的模板参数
- 模板参数
  - 类型参数：表示一个类型在模板中需要被替换的地方，关键字typename或者class。二者完全相同，旧编译器可能会不支持typename。
  - 非类型模板参数：（non-type template parameters）即在尖括号内不使用typename关键字声明的参数，必须是常量表达式（值而非类）。这类参数可以像不同函数参数一样被调用，但不同点在于这些参数模板在编译时是确定的，所以可以被用来构建不同的模板实力。
- 内联函数模板。相似的声明语法（上例）。
- 泛型编程的两个重要原则
  - 函数模板的函数参数是const引用，这样做可以是模板被用于不能被拷贝的类型如unique_ptr上。
  - 最小化对类型的要求，如使用<而不使用>，我们的函数模板仅仅需要类型重载了operator<()。
- 函数模板和类模板成员函数的定义通常都放在头文件中（很多库声称自己是header only，大概率是通过模板实现的，如eigen）。

对于函数模板，本章实现了一个排序算法库，可以作为对STL的补充。

### 类模板
- 定义：`template<typename T> class Queue {};
- 类模板必须提供参数，不能省略。因为不能推断。
- 类成员函数可以定义在类内和类外，在类定义内定义的函数隐式内联（inline）
- 类外成员函数定义同样需要以template关键字开头
- 类模板成员函数也是模板，仅仅当函数被使用时才会被实例化，这样做允许使用一些不支持某些操作的类型来实例化类模板。
- 模板的友元
  - 非模板友元
  - 模板友元
    - one-one friendship
    - general and specific friendship

```cpp
// 定义一个描述内存中的一块线性区域的类
template<typename T> class Blob {
public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;
  Blob();
  Blob(std::initilizer_list<T> il);
  size_type size() const;
  bool empty() const();
  void push_back(const T &t);
  void push_back(const T&& t);
  void pop_back();
  T& back();
  T& operator[](size_type i);

private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type i, const std::string &msg) const;
}

// 在类模板外定义类成员函数
template<typename T>
void Blob<T>::push_back(const T& t) {
  ...
}
```

C++11, 对自身的友元
```cpp
template <typename Type> class Bar {
  friend Type;
}
```
typedef of generics
```cpp
typedef Blob<string> StrBlob;
template <typename T> using twin = pair<T, T>;
...
twin<int> ti;
twin<double> td;
```

类模板的静态成员也是按类型实例化的，Blob<string>和Blob<int>即使有相同名字的静态成员他们也是属于不同实例的。

#### using class members that are types
```cpp
template<typename S>
typename S::iterator getIterator(S s) {
  ...
}
```

本章实现了一个二叉树模板。（from Essetial C++)

### 类型推导
```cpp
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
  return strcmp(p1, p2);
}
// https://stackoverflow.com/questions/63981325/type-deduction-of-function-template-in-c
// the compiler will use the size of the literals to instantiate the template
compare("hh", "ddd");
```

## References:
1. Essential C++ Addison Wesley, Chapter 6. Programming With Templates
2. C++ Primer, Chapter 16. Templates and Generic Programming
3. http://www.cplusplus.com/doc/tutorial/functions2/
4. https://github.com/applenob/Cpp_Primer_Practice/blob/master/notes/ch16.md
