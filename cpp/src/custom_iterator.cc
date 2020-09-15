/*
  C++中如何实现自定义类型的迭代器
  https://blog.csdn.net/XiaoHeiBlack/article/details/77014626
 */

#include <iostream>
#include <iterator>
#include <algorithm>


template<class T> class MyIterator :
  public std::iterator<std::input_iterator_tag, T>
{
    public:
        MyIterator(T* p){
            _ptr = p;
    }
    //赋值
    MyIterator& operator = (const MyIterator &iter)
    {
        _ptr = iter._ptr;
    }
    //不等于
    bool operator != (const MyIterator &iter)
    {
        return _ptr!= iter._ptr;
    }
    //等于
    bool operator == (const MyIterator &iter)
    {
        return _ptr == iter._ptr;
    }
    //前缀自加
    MyIterator& operator ++ ()
    {
        _ptr++;
        return *this;
    }
    //后缀自加
    MyIterator operator ++ (int)
    {
        MyIterator tmp= *this;
        _ptr++;
        return tmp;
    }
    //取值
    T& operator * ()
    {
        return *_ptr;
    }

    private:
    T* _ptr;//实际的内容指针，通过该指针跟容器连接
};


template<typename T>
class myVector {
private:
  T* _selfElems;
  int _count;
  // private resize functions

public:
  // embedded class
  typedef MyIterator<T> iterator;
  myVector() {
    _selfElems = new T[32];
    _count = 32;
    init();
  }

  myVector(int n) {
    _selfElems = new T[n];
    _count = n;
    init();
  }

  void init() {
    // memset byte
    memset(_selfElems, 0, sizeof(T)*_count);
  }
  
  T& operator[](int i) {
    return _selfElems[i];
  }

  iterator begin() {
    return iterator(_selfElems);
  }


  iterator end() {
    return iterator(_selfElems + _count);
  }

  int size() {
    return _count;
  }
};


bool eq_10(int x) {
  return x == 10;
}



int main() {
  myVector<int> mv(10);
  mv[3] = 10;
  mv[9] = 10;
  mv[4] = 10;
  myVector<int>::iterator it = mv.begin();
  std::cout << "mv" << std::endl;
  while (it != mv.end())
    std::cout << *(it++) << " ";
  std::cout << std::endl;

  std::cout << std::count_if(mv.begin(), mv.end(), eq_10) << std::endl;
  return 0;
}