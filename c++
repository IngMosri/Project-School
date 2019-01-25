#include <iostream>

using namespace std;

void Administrador();
void ventas(); /*prototipos*/

int main(){
    int opcion = 0;
    do{
    cout<< "menu\n";
    cout<< "1 Administrador\n";
    cout<< "2 ventas\n";
    cout<< "3 Salir\n";
    cin>> opcion;
    switch (opcion)
    {
        case 1: Administrador();
            break;
        case 2: ventas();
            break;
        case 3: cout<< "cerrando sistema";
            break;
        default : cout << "opcion invalida";
    }
    }while(opcion != 3);
return 0;
}
void Administrador();
{
  int opcion = 0;
  do{
  cout<< "Estas en el modulo Administrador\n";
  cout<< "1 Alta\n";
  std::cout << "2  bajas" << '\n';
  std::cout << "3  Bajas" << '\n';
  std::cout << "4  Consultas" << '\n';
  std::cout << "5  Mostrar inventario" << '\n';
  std::cout << "6  Administrador de cuentas" << '\n';
  std::cout << "7  Regresar al menu principal" << '\n';
  std::cout << "8 Salir" << '\n';
  std::cin >> opcion;
  switch (opcion)
  {
          case 1: Alta();
               break;
          case 2: Bajas();
               break;
          case 3: Bajas();
               break;
          case 4: Consultas();
               break;
          case 5: Mostrar inventario();
                break;
          case 6: Administrador de cuentas();
                break;
          case 7: Regresar al menu principal();
                break;
          case 8: Salir();
                break;
          default : cout << "opcion invalida";
        }while(opcion != 8);
  }
return 0;
}
