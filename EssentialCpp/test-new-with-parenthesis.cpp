#include <iostream>

int main() {
  using namespace std;
  int *a = new int[10]();

  for (int i = 0; i < 10; i++)
    cout << a[i] << endl;
  delete[] a;
}
