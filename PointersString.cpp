#include <iostream>
#include <cstring>
using namespace std;
int main(){
  int lista[5] = {10, 20, 30, 40, 50};
  int *p;
  char cad[15];
  char *q;
  p = &lista[3]; // ’p’ almacena la direcci´on de la posici´on 3 del arreglo
  p = lista + 3; // Instrucci´on equivalente a la anterior
  cout << lista[2]; // Imprime 30;
  cout << *(lista+2); // Instrucci´on equivalente a la anterior
  strcpy(cad, "Programando");
  for (q = cad; *q != '\0'; q++)
  cout << q;
return 0;
