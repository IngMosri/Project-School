#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdio>

using namespace std;
//Variables Globales
int total = 0;

struct Nuevo_Usuario {
string Usuario_Nuevo;
    int password;
    };
    Nuevo_Usuario Cuenta_usuarios[100];

struct nodo {
  int ind;
  char producto[80];
  int pc;
  int pv;
  int exi;
  int nvlr;
  nodo * siguiente;
  nodo * anterior;
};

nodo * ptr = NULL;
nodo * inicio = NULL;
nodo * fin = NULL;
nodo * nuevo = NULL;

void Administrador();
void Ventas();
void Escritura();
void Lectura();
void Alta_usuario();
void Borrar_datos();
int main() {
  //menu

  int opcion = 0;

  {
    cout << "menu\n";
    cout << "1 Administrador\n";
    cout << "2 ventas\n";
    cout << "3 Salir\n";
    cin >> opcion;
    switch (opcion) {
    case 1:
      Administrador();
      break;
    case 2:
      Ventas();
      break;
    case 3:
      cout << "cerrando sistema";
      break;
    default:
      cout << "opcion invalida";
    }
  }
  while (opcion != 3);

  return 0;
}

void Administrador() {
  {
    int password;
    password = 1234;

    string username;
    username = "admin";
    string userinput;

    do {
      cout << "Enter username:";
      cin >> userinput;

      if (userinput == username); {
        cout << "\n";
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
  do {
    cout << "Estas en el modulo Administrador\n";
    cout << "1 Alta de producto\n";
    cout << "2  Mostar Producto" << '\n';
    cout << "3  Ventas" << '\n';
    cout << "4.  Alta de nuevos usuarios \n";
    cout << "5. Dar producto de baja \n";
    cin >> opcion;
    switch (opcion) {
    case 1:
      Escritura();
      break;
    case 2:
      Lectura();
      break;
    case 3:
      Ventas();
      break;
    case 4:
    Alta_usuario();
      break;
    case 5:    
    Borrar_datos();
      break;
        default:  
      cout << "opcion invalida";
    }
  } while (opcion != 8);
}


void Escritura() {
  ofstream ArchivoInventario("inventario1.bin", ios:: app | ios::binary);
int indice;
    char NombreProducto[80];
    int PrecioDeCompra;
    int PrecioDeVenta;
    int ExistenciaFisicas;
    int NivelDeReorden;
    if (!ArchivoInventario)
    cout<<"Error en la apertura del archivo";
    else{
        do{
            cout<<"Escriba el indice del poducto(0 para salir debe empezar en # 5 en adelante)  ";
            cin>>indice;
            if(indice!=0){
                cout<<"Escriba el nombre del prodcuto que quiere dar de alta : ";
                cin>>NombreProducto;
                fflush(stdin);//vac�a el bufer de lectura
                cout<<"Escriba el precio de compra: ";
                cin>>PrecioDeCompra;
                cout<<"Escriba el precio de venta: ";
                cin>>PrecioDeVenta;
                cout<<"Escriba las existencias fisicas del producto: ";
                cin>>ExistenciaFisicas;
                cout<<"Escriba el nivel de reorder del producto: ";
                cin>>NivelDeReorden;     //escritura en el archiv
                ArchivoInventario.write( reinterpret_cast < char * > ( & indice), sizeof(indice));
                ArchivoInventario.write(NombreProducto, 80);
                ArchivoInventario.write(reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
                ArchivoInventario.write(reinterpret_cast < char * > ( & PrecioDeVenta), sizeof(PrecioDeVenta));
                ArchivoInventario.write(reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
                ArchivoInventario.write( reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));
            }
        }while(indice!=0);
    }
    ArchivoInventario.close();

}
void Ventas() {

}
void Lectura() { // Lectura del archivo binario previamente creado
    ifstream ArchivoInventario("inventario1.bin", ios:: in | ios::binary);
    //Variables locales
    int total = 0;
    int indice;
    char NombreProducto[80];
    int PrecioDeCompra;
    int PrecioDeVenta;
    int ExistenciaFisicas;
    int NivelDeReorden;
    if (!ArchivoInventario)
      cout << "Error en la apertura del archivo";
    else {
     cout << left << setw(8) <<setprecision(8)<< "Indice" << setw(22)<<setprecision(22) << "Nombre del Producto " << setw(15)<<setprecision(15) << "Precio de Compra  " << setw(10)<<setprecision(10)<< " Precio de venta  " << setw(17)<<setprecision(17) << " Existencias " << setw(9)<<setprecision(9) <<"Nivel de Reorden " << endl;
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
        reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));
      //Primera lectura del programa y creacion de los datos a listas
      nuevo = new(nodo);
      nuevo -> ind = indice;
      strcpy(nuevo -> producto, NombreProducto); //Conversion del chart a String
      nuevo -> pc = PrecioDeCompra;
      nuevo -> pv = PrecioDeVenta;
      nuevo -> exi = ExistenciaFisicas;
      nuevo -> nvlr = NivelDeReorden;
      nuevo -> siguiente = NULL;
      inicio=nuevo;
      fin=nuevo;

      //Segunda lectura del archivo binario
      while (ArchivoInventario.eof() == false){
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & indice), sizeof(indice));
      ArchivoInventario.read(NombreProducto, 80);
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
      ArchivoInventario.read(
        reinterpret_cast <char *> ( & PrecioDeVenta), sizeof(PrecioDeVenta));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));
nuevo = new(nodo);
      nuevo -> ind = indice;
      strcpy(nuevo -> producto, NombreProducto); //Conversion del chart a String
      nuevo -> pc = PrecioDeCompra;
      nuevo -> pv = PrecioDeVenta;
      nuevo -> exi = ExistenciaFisicas;
      nuevo -> nvlr = NivelDeReorden;
      nuevo -> siguiente = NULL;
      fin -> siguiente = nuevo;
      fin = nuevo;
      }
      //Borrado del ultimo nodo porque no tiene informacion y no tiene informacion.
      ptr = inicio;
      while(ptr->siguiente !=fin)
        ptr=ptr->siguiente;
      delete(fin);
      fin=ptr;
      fin->siguiente=NULL;
       // Aqui se desplega la lista con los valores previamente agregados.
      ptr =inicio;
      while(ptr!=NULL){
        cout<< setfill('-');
        cout << left << setw(8)<<setprecision(8)<<ptr->ind<<setw(22)<<setprecision(22)<<ptr->producto<<setw(22)<<setprecision(22)<< ptr->pc<< setw(18)<<setprecision(18)<< ptr->pv<<setw(19)<<setprecision(19)<<ptr->exi<< setw(16)<<setprecision(16)<<ptr->nvlr<<endl;
        ptr=ptr->siguiente;

      }
ArchivoInventario.close();
    }
  }

void Alta_usuario(){


string usuario_temp;
    int i =0;
    while(true){
        cout<<"Nombre: ";
        cin>>usuario_temp;
        if(usuario_temp=="*")
            break;
            Cuenta_usuarios[i].Usuario_Nuevo=usuario_temp;
            cout<<"Ingrese su Password(Solamente con numeros y no mas de 4 digitos ): ";
            cin>>Cuenta_usuarios[i].password;
            i++;

    }
}
void Borrar_datos()
{

  int pos, flag = 0; 
  int indice;
  char NombreProducto[80];
  int PrecioDeCompra;
  int PrecioDeVenta;
  int ExistenciaFisicas;
  int NivelDeReorden;
	cout<<"Enter Position that should be Deleted :";
  cin>>pos; 
	ofstream o("temp.bin", ios:: app | ios::binary | ios::out);
  ifstream ifs("inventario1.bin", ios::binary | ios::in);
  

	if(!ifs)
	{
		cout<<"File not Found";
		exit(0);
	}

	else
	{
     while (!ifs.eof()) 
     {
          ifs.read(
            reinterpret_cast < char * > ( & indice), sizeof(indice));
          ifs.read(NombreProducto, 80);
          ifs.read(
            reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
          ifs.read(
            reinterpret_cast < char * > ( & PrecioDeVenta), sizeof(PrecioDeVenta));
          ifs.read(
            reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
          ifs.read(
            reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));
        
        //Es el que quieres borrar
        if(indice == pos)
        {
            flag = 1;
        }
        //Si no es el que quieres borrar
        else
        {
            o.write( reinterpret_cast < char * > ( & indice), sizeof(indice));
            o.write(NombreProducto, 80);
            o.write(reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
            o.write(reinterpret_cast < char * > ( & PrecioDeVenta), sizeof(PrecioDeVenta));
            o.write(reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
            o.write( reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));
        }
     }
     o.close();
     ifs.close();
     remove("inventario1.bin");

     rename("temp.bin", "inventario1.bin"); 

     if (flag == 1) 
        cout << "\nrecord successfully deleted \n"; 
    else
        cout << "\nrecord not found \n";
  }
}		








