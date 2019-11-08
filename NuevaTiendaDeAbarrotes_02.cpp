#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;
//Variables Globales
int total =0;
struct nodo {
    int indice;
  char producto[80];
  int pc;
  int pv;
  int exi;
  int nvlr;
    nodo *siguiente;
    nodo *anterior;
};
nodo *ptr = NULL;
nodo *inicio = NULL;
nodo *fin = NULL;
nodo *nuevo = NULL;

void Altas();
void Mostrar();
void Administrador();
void Ventas();
void Escritura();
void Lectura();
int main() {
    //menu

    int opcion = 0;

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

void Administrador(){
{
      int password;
      password = 1234;

      string username;
      username = "admin";
      string userinput;

      do
      {
          cout << "Enter username:";
          cin >> userinput;

          if (userinput == username);
          {
              cout <<"\n";
              cout << "Enter password:";
              cin >> password;

          }
      }
      while (userinput == username);

      if (password == 1234)
          cout << "Accesso concedido ...";
      if (password != 1234)
          cout << "Acceso Incorrecto.....Invalid Username/Password:";

  }
// Menu de opciones a escojer
  int opcion = 0; //variable local
  do
  {
      cout<< "Estas en el modulo Administrador\n";
      cout<< "1 Alta\n";
      cout << "2  Mostar" << '\n';
      cout << "3  Ventas" << '\n';
      cin >> opcion;
      switch (opcion)
      {
          case 1: Altas();
              break;
          case 2: Mostrar();
              break;
          case 3: Ventas();
              break;
         default : cout << "opcion invalida";
      }
  }while(opcion != 8);
}
 

    

void Altas(){
     

}
void Mostrar(){

}
void Escritura(){

}
void Ventas(){

}
void Lectura(){
    fstream ArchivoInventario("ArchivoInventario.bin",ios::in | ios::binary);
    int total = 0;
  int indice;
  char NombreProducto[80];
  int PrecioDeCompra;
  int PrecioDeVenta;
  int ExistenciaFisicas;
  int NumeroDeReorden;
if(!ArchivoInventario)
        cout<<"Error en la apertura del archivo";
    else{
        cout<<left<<setw(8)<<"Indice"<<setw(20)<<"Nombre del Producto"<<setw(10)<<"Precio de Compra"<<setw(10)<<"Precio de venta"<<setw(10)<<"Existencias"<<setw(10)<<"Numero de Reorden"<<endl;
        ArchivoInventario.read(
          reinterpret_cast < char * > ( & indice), sizeof(indice));
        ArchivoInventario.read(NombreProducto, 80);
        ArchivoInventario.read(
          reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
        ArchivoInventario.read(
          reinterpret_cast < char * > ( & PrecioDeVenta), sizeof(PrecioDeVenta));
        ArchivoInventario.read(
          reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
        ArchivoInventario.read(
          reinterpret_cast < char * > ( & NumeroDeReorden), sizeof(NumeroDeReorden));

            nuevo =new(nodo);
            strcpy(nuevo->producto,NombreProducto);
            nuevo->pc=PrecioDeCompra;
            nuevo->pv=PrecioDeVenta;
    

