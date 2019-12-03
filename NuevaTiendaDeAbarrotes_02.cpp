
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdio>


using namespace std;
//Variables Globales
string usuarios[100];
string contrasenas[100];
int TotalUsuarios =0;
//Estructura de datos
struct producto_nodo {
  string producto;
  int pc;
  int pv;
  int exi;
  int nvlr;
  producto_nodo * siguiente;
  producto_nodo * anterior;
};

struct informacion_ticket_info{
  int cantidad_vendida;
  string producto_vendido;
  float precio_unitario;
  float subtotal_venta;
};

producto_nodo * ptr = NULL;
producto_nodo * ptr1 = NULL;
producto_nodo* lprt = NULL;
producto_nodo * inicio = NULL;
producto_nodo * fin = NULL;
producto_nodo * nuevo = NULL;

producto_nodo * inventario = NULL;

struct existencia_prod{
  bool producto_existencias;
  int producto_posicion;
};

int i, total = 0;
//producto_nodo inventario[100];
float total_ventas, total_total;

//Funciones
void Administrador();
void Ventas();
void Altas();
void Escritura();
void Lectura();
//Apartado sobre altas,bajas,muestra y modificaciones de usuarios
void Alta_Usuario();
void Baja_Usuario();
void Administrador_De_Cuentas_De_Usuario();
void Consulta_De_Usario();
void Modicacion_De_Usuario();
void guardar_inventario();
int buscar_usuario(string BuscarUsuarios);
int buscar(string);
void Modificacion_De_Usuario_Registrado(int modUs);
void Modificacion_De_Contrasena_Registrado(int modUs);
void Regresar_Al_Menu_Anterior();
//Funcion de eliminar datos del ArchivoInventario binario
void Borrar_datos();
void cargar_inventario();


int main() {
  //menu
  int opcion = 0;
  cargar_inventario();
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
    cout << "1. Alta de producto\n";
    cout << "2. Mostar Producto\n";
    cout << "3.Guardar inventario\n";
    cout << "4.Subir inventario\n";
    cout << "5. Adminstracion de cuentas de usuario\n";
    cout << "6. Dar producto de baja \n";
    cout << "7. Regresar al Menu Anterior \n";
    cin >> opcion;
    switch (opcion) {
    case 1:
      Altas();
      break;
    case 2:
      Lectura();
      break;
      case 3:
      Escritura();
      break;
    case 6:
    Borrar_datos();
      break;
    case 7:
    Administrador_De_Cuentas_De_Usuario();
      break;
    case 8:
    Borrar_datos();
      break;
    case 9:
    Regresar_Al_Menu_Anterior();
      break;

      cout << "opcion invalida";
    }
  } while (opcion != 8);
}
void cargar_inventario(){
  ifstream ArchivoInventario("inventario1.bin", ios:: in | ios::binary);
    //Variables locales

    int indice;
    char NombreProducto[80];
    int PrecioDeCompra;
    int PrecioDeVenta;
    int ExistenciaFisicas;
    int NivelDeReorden;
    if (!ArchivoInventario)
      cout << "Error en la apertura del ArchivoInventario";
    else {
      ArchivoInventario.read(NombreProducto, 80);
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & PrecioDeVenta), sizeof(PrecioDeVenta));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));
        string str(NombreProducto);

      //Primera lectura del programa y creacion de los datos a listas
      nuevo = new(producto_nodo);
      (nuevo ->producto = NombreProducto); //Conversion del chart a String
      nuevo -> pc = PrecioDeCompra;
      nuevo -> pv = PrecioDeVenta;
      nuevo -> exi = ExistenciaFisicas;
      nuevo -> nvlr = NivelDeReorden;
      nuevo -> siguiente = NULL;
      inicio=nuevo;
      fin=nuevo;
      inventario = nuevo;
      //Segunda lectura del ArchivoInventario binario
      while (ArchivoInventario.eof() == false){
      ArchivoInventario.read(NombreProducto, 80);
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
      ArchivoInventario.read(
        reinterpret_cast <char *> ( & PrecioDeVenta), sizeof(PrecioDeVenta));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));

      nuevo = new(producto_nodo);
      nuevo -> producto = NombreProducto; //Conversion del chart a String
      nuevo -> pc = PrecioDeCompra;
      nuevo -> pv = PrecioDeVenta;
      nuevo -> exi = ExistenciaFisicas;
      nuevo -> nvlr = NivelDeReorden;
      nuevo -> siguiente = NULL;
      fin -> siguiente = nuevo;
      fin = nuevo;
      }
      //Borrado del ultimo nodo porque no tiene informacion
      ptr = inicio;
      while(ptr->siguiente !=fin)
        ptr=ptr->siguiente;
      delete(fin);
      fin=ptr;
      fin->siguiente=NULL;
       // Aqui se desplega la lista con los valores previamente agregados.
      ptr =inicio;
      ArchivoInventario.close();
    }

}
void Altas(){
  // Declaracion de variables
int i;
existencia_prod producto_alta;
int posProducto;
string producto_referencia;
i = total;

do{
    cout<< "Ingresa el producto que se quiere dar de alta"<< endl;
    cin>>producto_referencia;
    if( producto_referencia != "*"){
        posProducto = buscar(producto_referencia);
        if(posProducto == -1){
            nuevo = new(producto_nodo);

            nuevo ->producto =producto_referencia;

            cout<<"ingrese el precio de compra"<<endl;
            cin>>nuevo->pc;

            cout<<"ingrese el precio de venta"<<endl;
            cin>>nuevo ->pv;
            while (nuevo ->pv<inventario->pc)
            {
                cout<< "Precio de venta es menor que precio de compra vuelva a capturar los valores correctos"<<endl;
                cin>> nuevo->pv;
            }

            cout<< "ingrese las existencias"<<endl;
            cin>>nuevo ->exi;

            cout<< "ingrese el nivel de reorder"<<endl;
            cin>>nuevo ->nvlr;
            while (nuevo -> exi < nuevo-> nvlr)
          {
            cout<< "Nivel de reorder es mayor que las exitencia vuelva a capturar"<<endl;
            cin>>nuevo -> nvlr;
          }
            ptr = fin;
            fin -> siguiente = nuevo;
            fin = nuevo;
            fin ->siguiente =NULL;
            fin->anterior = ptr;
            i++;
        }else
              cout<<"producto ya ha sido dado de alta"<<endl;
      }
      }while (producto_referencia != "*");

        total++;

}

//Apartado de escritura y alta de nuevos ArchivoInventarios en el inventario
void Escritura() {
  ofstream ArchivoInventario("inventario1.bin",ios::out | ios::binary);

  char inv[80];
  int i = 0;
  int PrecioDeCompra;
  int PrecioDeVenta;
  int ExistenciaFisicas;
  int NumeroDeReorden;

  ptr = inventario;

  if (!ArchivoInventario) cout << "Error en la apertura del Archivo";
  else {
      do {
          if (ptr != NULL ) {
              PrecioDeCompra = ptr -> pc;
              PrecioDeVenta = ptr -> pv;
              ExistenciaFisicas = ptr ->exi;
              NumeroDeReorden = ptr -> nvlr;

              fflush(stdin); // vacia el buffer de la lectura
              //escritura en el ArchivoInventario
              strcpy(inv, ptr -> producto.c_str());
              //ArchivoInventario.write(reinterpret_cast < char * > ( & ptr -> producto), sizeof(ptr -> producto));
             ArchivoInventario.write(inv,80);
             ArchivoInventario.write(
              reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
            ArchivoInventario.write(
              reinterpret_cast < char * > ( & PrecioDeVenta), sizeof(PrecioDeVenta));
            ArchivoInventario.write(
              reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
            ArchivoInventario.write(
              reinterpret_cast < char * > ( & NumeroDeReorden), sizeof(NumeroDeReorden));
                  ptr  = ptr->siguiente;

          }
      } while (ptr != NULL);
  }


  ArchivoInventario.close();

  cout << "Se guardo el inventario" << endl;

}


//Apartado de lectura de los ArchivoInventarios
void Lectura() { // Lectura del ArchivoInventario binario previamente creado
    ifstream ArchivoInventario("inventario1.bin", ios:: in | ios::binary);
    //Variables locales
    int indice;
    char NombreProducto[80];
    int PrecioDeCompra;
    int PrecioDeVenta;
    int ExistenciaFisicas;
    int NivelDeReorden;
    if (!ArchivoInventario)
        cout << "Error en la apertura del ArchivoInventario";
    else {
          cout << left <<setw(22)<<setprecision(22) << "Nombre del Producto " << setw(15)<<setprecision(15) << "Precio de Compra  " << setw(10)<<setprecision(10)<< " Precio de venta  " << setw(17)<<setprecision(17) << " Existencias " << setw(9)<<setprecision(9) <<"Nivel de Reorden " << endl;

      ArchivoInventario.read(NombreProducto, 80);
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & PrecioDeVenta), sizeof(PrecioDeVenta));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
      ArchivoInventario.read(
        reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));
        string str(NombreProducto);

      //Primera lectura del programa y creacion de los datos a listas
      nuevo = new(producto_nodo);
      (nuevo ->producto = NombreProducto); //Conversion del chart a String
      nuevo -> pc = PrecioDeCompra;
      nuevo -> pv = PrecioDeVenta;
      nuevo -> exi = ExistenciaFisicas;
      nuevo -> nvlr = NivelDeReorden;
      nuevo -> siguiente = NULL;
      inicio=nuevo;
      fin=nuevo;
      inventario = nuevo;
      //Segunda lectura del ArchivoInventario binario
      while (ArchivoInventario.eof() == false){
              ArchivoInventario.read(NombreProducto, 80);
              ArchivoInventario.read(
                reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
              ArchivoInventario.read(
                reinterpret_cast <char *> ( & PrecioDeVenta), sizeof(PrecioDeVenta));
              ArchivoInventario.read(
                reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
              ArchivoInventario.read(
                reinterpret_cast < char * > ( & NivelDeReorden), sizeof(NivelDeReorden));

      nuevo = new(producto_nodo);
      nuevo -> producto = NombreProducto; //Conversion del chart a String
      nuevo -> pc = PrecioDeCompra;
      nuevo -> pv = PrecioDeVenta;
      nuevo -> exi = ExistenciaFisicas;
      nuevo -> nvlr = NivelDeReorden;
      nuevo -> siguiente = NULL;
      fin -> siguiente = nuevo;
      fin = nuevo;
      }
      //Borrado del ultimo nodo porque no tiene informacion
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
            cout << left <<setw(22)<<setprecision(22)<<ptr->producto<<setw(22)<<setprecision(22)<< ptr->pc<< setw(18)<<setprecision(18)<< ptr->pv<<setw(19)<<setprecision(19)<<ptr->exi<< setw(16)<<setprecision(16)<<ptr->nvlr<<endl;
            ptr=ptr->siguiente;

      }
ArchivoInventario.close();
    }
  }


//Baja de productos directamente del ArchivoInventario
void Borrar_datos()
{
//variables
  string pos;
  int flag = 0;
  int indice;
  char NombreProducto[80];
  int PrecioDeCompra;
  int PrecioDeVenta;
  int ExistenciaFisicas;
  int NivelDeReorden;
  
	cout<<"Ingrese el producto que desea eliminar del inventario :";
  cin>>pos;
  //Crea un ArchivoInventario temporal y lee el previamente ya hecho
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
        if(NombreProducto == pos)
        {
            flag = 1;
        }
        //Si no es el que quieres borrar
        else
        {
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

void Administrador_De_Cuentas_De_Usuario(){
int opcion = 0; //variable local
    do
    {
        cout<< "Estas en el modulo Administrador de cuentas de usuario \n";
        cout<< "1 Alta de usuario \n";
        cout << "2  Baja de usuario " << '\n';
        cout << "3  Consultas usuario " << '\n';
        cout << "4  Modificaciones de usuario "<< '\n';
        cout << "5  Mostrar cuenta de usuario " << '\n';
        cout << "6  Regresar al menu principal" << '\n';
        cin >> opcion;
        switch (opcion)
        {
            case 1: Alta_Usuario();
                break;
            case 2: Baja_Usuario();
                break;
            case 3: Consulta_De_Usario();
                break;
            case 4: Modicacion_De_Usuario();
                break;
            case 5: Administrador_De_Cuentas_De_Usuario();
                break;
            case 6: Regresar_Al_Menu_Anterior();
                break;
            default : cout << "opcion invalida";\
            }
    }while(opcion != 6);

}
void Alta_Usuario(/* arguments */) {

    string usuario,contrasena;

    int i = TotalUsuarios;

    while (true)
    {

        cout << "Ingrese nombre del nuevo usuario : ";
        cin >> usuario;

        if (usuario == "*")
            break;
            cout << "Ingrese contrasena";
            cin >> contrasena;

            usuarios[TotalUsuarios] = usuario;
            contrasenas[TotalUsuarios] = contrasena;

        i++;
        TotalUsuarios=i;
    }

}

void Baja_Usuario(/* arguments */) {
    string usuarios;
    int i,pos;
    while (true) {
        std::cout << "Usuario que se quiere dar de baja" << '\n';
        std::cin >> usuarios;
        if(usuarios=="*")
            break;
        pos= buscar_usuario(usuarios);
        if(pos== -1)
            std::cout << "Usuario no existe" << '\n';
        else{
            i = pos;
            if(usuarios[i]==0)
                std::cout << "No existe" << '\n';
            else
                usuarios[i]=0;
        }
    }
}
void Consulta_De_Usario(/* arguments */) {
    std::cout << "Los usuarios registrados son: " << '\n';
    for (int h = 0; h < TotalUsuarios; h++)
        std::cout <<usuarios[h]<< '\n';
}
int buscar_usuario(string BuscarUsuarios) {

}
void Modicacion_De_Usuario(/* arguments */) {
    int modUs;
    int opcion =0;
    string modicacionUsuario;
    while (true)
    {
        std::cout << "Escriba el nombre de usuario que quiere modificar" << '\n';
        std::cin >> modicacionUsuario;
        if(modicacionUsuario=="*")
            break;
        modUs=buscar_usuario(modicacionUsuario);
        if(modUs==-1)
            std::cout << "Este Usuario no Existe" << '\n';
        else
        {
            do{
                std::cout << "1.  modificar nombre de usuario" << '\n';
                std::cout << "2. modificar contrasena" << '\n';
                std::cout << "3. Salir" << '\n';
                cin>> opcion;
                switch (opcion)
                {

                    case 1:Modificacion_De_Usuario_Registrado(modUs);
                        break;
                    case 2:Modificacion_De_Contrasena_Registrado(modUs);
                        break;
                }
            }while (opcion !=2);
            return Administrador_De_Cuentas_De_Usuario();
        }

    }
}

void Modificacion_De_Usuario_Registrado(int modUs) {
    int NuevoUsuario;
    std::cout << "Ingrese el nuevo usuario" << '\n';
    std::cin >> NuevoUsuario;
    usuarios[modUs] = NuevoUsuario;

}
void Modificacion_De_Contrasena_Registrado(int modUs) {
    int NuevaContrasena;
    std::cout << "Ingrese nueva contrasena" << '\n';
    std::cin >> NuevaContrasena;
    contrasenas[modUs] = NuevaContrasena;

}
void Regresar_Al_Menu_Anterior(){
  int opcion = 0; //variable local
    do{
        std::cout << "1. Menu administrador" << '\n';
        std::cout << "2. Menu ventas" << '\n';
        cin >> opcion;
        switch (opcion)
        {

            case 1: Administrador();
                break;
            case 2: Ventas();
                break;
        }
      }         while(opcion != 6);
}




int buscar(string producto_referencia){
 producto_nodo *ptr = inventario;
  int i = 0;
  while (ptr != NULL)
  {
     if(producto_referencia == ptr->producto){
       return i;
      }else
      {
       ptr = ptr->siguiente;
       i++;
      }
  }
     return -1;
}

void Ventas(){

    string producto_compra;
    int cantidad_vendida, i, resultado_compra, numero_producto, j;
    float total;

    j =0;
    total =0;
    ptr = inventario;


    informacion_ticket_info ticket_info[100];

	    do{

                cout << "Ingrese el producto que sea vender: ";
	        cin >> producto_compra;

	        if (producto_compra != "*" ) {
	         numero_producto = buscar(producto_compra);
           if( numero_producto != -1)
           {
             for(i = 0;i<numero_producto;i++)
             {
              ptr = ptr -> siguiente;
             }

	            if (producto_compra == producto_compra) {

	                cout << "Cantidad: ";
	                cin >> cantidad_vendida;

                        if(ptr ->exi == 0 ){
                            cout << "Producto agotado " << endl;
                        }
	                else if (cantidad_vendida > ptr ->exi ) {

	                    cout << "La cantidad solicitada excede el número de existencias" << endl;

	                    cout << "Desea comprar: " << ptr ->exi << " ? \n 1. Sí \n 2.No \n";
	                    cin >> resultado_compra;

	                    if (resultado_compra == 1) {
	                        cantidad_vendida = ptr ->exi;
                                ptr ->exi =0;

	                        ticket_info[j].cantidad_vendida = cantidad_vendida;
	                        ticket_info[j].producto_vendido = ptr ->producto;
	                        ticket_info[j].precio_unitario = ptr ->pv;
	                        ticket_info[j].subtotal_venta = ticket_info[j].precio_unitario*ticket_info[j].cantidad_vendida;
	                        total += ticket_info[j].subtotal_venta;

                                cout << "Producto" << ptr ->producto<< " agotado" << endl;

	                        j++;

	                    }
					}else {

			                ticket_info[j].cantidad_vendida = cantidad_vendida;
                                        ptr-> exi -= cantidad_vendida;
			                ticket_info[j].producto_vendido = ptr ->producto;
			                ticket_info[j].precio_unitario = ptr ->pv;
			                ticket_info[j].subtotal_venta = ticket_info[j].precio_unitario  * ticket_info[j].cantidad_vendida;
			                total += ticket_info[j].subtotal_venta;

                                        if (ptr ->exi <= ptr ->nvlr){
                                            cout << "Ordenar " << inventario[i].producto<< endl;
                                        }
			                j++;
	               		 }
				}else
	                cout << "El producto no existe" << endl;
	    	}
          }

	    }while( producto_compra != "*" );

					total_ventas += total;


				    cout << setw(20) <<  "Informacion de la Venta realizada "<< endl;
				    cout << "Cantidad: " << setw(10)<< "Producto: " << setw(10) << " Precio: " << setw(10)  << " Total: "<< endl;

				    for (int k=0; k<j; k++){

				        cout <<  ticket_info[k].cantidad_vendida  << setw(15) << ticket_info[k].producto_vendido << setw(15)  << ticket_info[k].precio_unitario<< setw(15)  << ticket_info[k].subtotal_venta << endl;

					}
				    cout << "" << endl;
				    cout << "" << endl;
				    cout << setw(30) <<"Total vendido es: " << total << endl;

				    j=0;


}
