#include <iostream>
#include <iomanip>

using namespace std;

void Administrador();
void Ventas(); /*prototipos*/
void Altas();
void Bajas();
void Consultas();
void MostarInventario();
void AdministradorDeCuentasDeUsuario();
void Modificaciones();
void CorteDecajaGeneral();
void RegresarAlMenuAnterior();
int total = 0;   //variable globales
int articulo[100]; //variable globales
string nombre[100];
int buscar(string name);
int id[100] ={2,4,1,3,5};
string producto[100]={"aceite","agua","arroz","huevo","leche","pan","refresco"};
float pc[100]={10,10,10,10,10};
float pv[100]={10,20,10,15,11};
int existencia[100]={23,20,12,20,10};
int nr[100]={5,2,7,5,3};
int st[100]={1,1,1,1,1};
int main()
{
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

void Ventas(/* arguments */) {
  /* code */
}
/* Menu de administradir */
void Administrador()
{
    int opcion = 0; //variable local
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
                case 1: Altas();
                    break;
                case 2: Bajas();
                    break;
                case 3: Consultas();
                    break;
                case 4: Modificaciones();
                        break;
                case 5: MostarInventario();
                        break;
                case 6: AdministradorDeCuentasDeUsuario();
                        break;
                case 7: CorteDecajaGeneral():
                         break;
                case 8: RegresarAlMenuAnterior();
                        break;
                default : cout << "opcion invalida";
        }
    }while(opcion != 8);
}
/*Menu de alta de productos*/
void Altas(/* arguments */)
{
  string name;
      int i= total; //variable local
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


void Bajas(/* arguments */) {
  /* code */
}
void Consultas(/* arguments */)
{
  int pos; //variable local
      string name;
      while (true) {
          int i = 0;
          cout << "Producto";
          cin>>name;
          if (name=="*")
              break;
          pos=buscar(name);
          if (pos==-1)
              cout << "No existe" << endl;
          else
              cout<<"Producto: "<<articulo[pos];

       }
}
  int buscar(string name) {
  int i = 0;
      while (i < total && nombre[i] != name)
                i++;
       if(i==total)
  return -1;
      else
return i;
}

/* Menu de Modificaciones de cuentas y productos. */
void Modificaciones(/* arguments */) {
  /* code */
}

/* Menu de constual de inventario */
void MostarInventario(/* arguments */)
{
       {
     int j;
      for (j = 0; j < total; j++)
        cout<<setw(10)<<"ID"<<setw(20)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(12)<<"Existencias"<<setw(10)<<"NR"<<setw(10)<<"ST"<<endl;
    for (j = 0; j < total; j++)
      if (st[j]==1)
        cout<<setw(10)<<id[j]<<setw(20)<< producto[j] <<setw(10)<<pc[j]<<setw(10)<<pv[j]<<setw(12)<<existencia[j]<<setw(10)<<nr[j]<<setw(10)<<st[j]<<endl;

       }

}

void AdministradorDeCuentasDeUsuario(/* arguments */) {
  /* code */
}
/* Menu de corte de caja general*/
void CorteDecajaGeneral(/* arguments */) {
  /* code */
}
void RegresarAlMenuAnterior(/* arguments */) {
  /* code */
}
