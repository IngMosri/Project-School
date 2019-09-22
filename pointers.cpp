#include <iostream>
using namespace std;
int main(){
  int x = 25;
  int *ptr1; // Apuntador a un dato de tipo entero (int)
  int *ptr2;
  cout << "La direccion de x es: " << &x << endl;
  ptr1=&x;
  ptr2=ptr1;
  cout<<x<<endl;
  cout<<ptr1<<endl;
  cout<<*ptr1<<endl;
  return 0;
}
