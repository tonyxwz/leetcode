#include "movable_array.hpp"
void
printSize(MovableArray a)
{
  /* for (int i = 0; i < a.size(); ++i) */
  /*   std::cout << a[i] << "\t"; */
  /* std::cout << std::endl; */

  std::cout << "Size of array is " << a.size() << std::endl;
}

MovableArray
createArray(int size)
{
  auto ret = MovableArray(size);
  return ret;
}

int
main()
{
  MovableArray a{ 20 };
  // copied
  printSize(a);
  // explicitly moved
  printSize(std::move(a));
  // implicitly moved, why not working? TODO
  printSize(MovableArray(30));
  // implicitly moved
  // need to be compile with option 
  //     -fno-elide-constructors
  printSize(createArray(40));
}
