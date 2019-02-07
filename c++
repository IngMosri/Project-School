#include <iostream>

using namespace std;

void Administrador();
void Ventas(); /*prototipos*/
void Alta();
void Baja();
void Consultas();
void MostarInventario();
void AdministradorDeCuentas();
void Regresar();
void Salir();
int total = 0;   //variables globales
string nombre[100];
int main()
{
int opcion = 0;

        do
    {
        cout<< "menu\n";
        cout<< "1 Administrador\n";
        cout<< "2 ventas\n";
        cout<< "3 Salir\n";
        cin>> opcion;
        switch (opcion)
        {
            case 1: Administrador();
                break;
            case 2: Ventas();
                break;
            case 3: cout<< "cerrando sistema";
                break;
            default : cout << "opcion invalida";
        }
    }while(opcion != 3);
    return 0;
 }

void Ventas(/* arguments */) {
  /* code */
}

void Administrador()
{
    int opcion = 0;
    do
    {
        cout<< "Estas en el modulo Administrador\n";
        cout<< "1 Alta\n";
        cout << "2  Baja" << '\n';
        cout << "3  Consultas" << '\n';
        cout << "4  Mostrar inventario" << '\n';
        cout << "5  Administrador de cuentas" << '\n';
        cout << "6  Regresar al menu principal" << '\n';
        cout << "7 Salir" << '\n';
        cin >> opcion;
        switch (opcion)
        {
                case 1: Alta();
                    break;
                case 2: Baja();
                    break;
                case 3: Consultas();
                    break;
                case 4: MostarInventario();
                        break;
                case 5: AdministradorDeCuentas();
                        break;
                case 6: Regresar();
                        break;
                case 8: Salir();
                        break;
                default : cout << "opcion invalida";
        }
    }while(opcion != 8);
}

void Alta(/* arguments */)
{
  string name;
      int i= total;
      while (true)
      {

          cout << "Ingrese el Producto deseado: ";
          cin>>name;
          if (name == "*")
              break;
          nombre[i] = name;
          cout << "Bienvenido " << name << endl;
          i++;
      }
      total =i;
  }


void Baja(/* arguments */) {
  /* code */
}
void Consultas(/* arguments */)
{

}
void MostarInventario(/* arguments */)
{
          int j;
          for (j = 0; j < total; j++)
          cout << nombre[j]<<"\n";
}

void AdministradorDeCuentas(/* arguments */) {
  /* code */
}
void Regresar(/* arguments */) {
  /* code */
}
void Salir(/* arguments */) {
  /* code */
}
