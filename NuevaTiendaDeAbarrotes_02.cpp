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
  int ind;
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
struct existencia_prod{
  bool producto_existencias;
  int producto_posicion;
};

int i, total;
producto_nodo inventario[100];
float total_ventas, total_total;

//Funciones
void Administrador();
void Ventas();
void Altas();
void Escritura();
void Lectura();
void Ordenar();
//Apartado sobre altas,bajas,muestra y modificaciones de usuarios
void Alta_Usuario();
void Baja_Usuario();
void Administrador_De_Cuentas_De_Usuario();
void Consulta_De_Usario();
void Modicacion_De_Usuario();
void guardar_inventario();
int buscar_usuario(string BuscarUsuarios);
existencia_prod buscar(string);
void Modificacion_De_Usuario_Registrado(int modUs);
void Modificacion_De_Contrasena_Registrado(int modUs);
void Regresar_Al_Menu_Anterior();
//Funcion de eliminar datos del ArchivoInventario binario
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
    guardar_inventario();
      break;
    case 5:
      Ordenar();
        break;
    case 6:
    Escritura();
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

void Altas(){
  // Declaracion de variables
int i;
existencia_prod producto_alta;
string producto_referencia;
i = total;

do{
    cout<< "Ingresa el producto que se quiere dar de alta"<< endl;
    cin>>producto_referencia;
    if( producto_referencia != "*"){
        producto_alta = buscar(producto_referencia);

        int j = producto_alta.producto_posicion;
        if(producto_alta.producto_existencias == false){

            cout<< "Ingrese el ID del producto apartir de 5"<<endl;
            cin >>inventario[i].ind;

            inventario[i].producto = producto_referencia;

            cout<<"ingrese el precio de compra"<<endl;
            cin>>inventario[i].pc;

            cout<<"ingrese el precio de venta"<<endl;
            cin>>inventario[i].pv;
            while (inventario[i].pv<inventario[i].pc)
            {
                cout<< "Precio de venta es menor que precio de compra vuelva a capturar los valores correctos"<<endl;
                cin>> inventario[i].pv;
            }

            cout<< "ingrese las existencias"<<endl;
            cin>>inventario[i].exi;

            cout<< "ingrese el nivel de reorder"<<endl;
            cin>>inventario[i].nvlr;
            while (inventario[i].exi<inventario[i].nvlr)
          {
            cout<< "Nivel de reorder es mayor que las exitencia vuelva a capturar"<<endl;
            cin>>inventario[i].nvlr;
          }

            i++;
        }else
              cout<<"producto ya ha sido dado de alta"<<endl;
      }
      }while (producto_referencia != "*");

        total = i;


}

//Apartado de escritura y alta de nuevos ArchivoInventarios en el inventario
void Escritura() {
  ofstream ArchivoInventario("inventario1.bin", ios:: app | ios::binary);
int indice;
    char NombreProducto[80];
    int PrecioDeCompra;
    int PrecioDeVenta;
    int ExistenciaFisicas;
    int NivelDeReorden;
    if (!ArchivoInventario)
    cout<<"Error en la apertura del ArchivoInventario";
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
                cin>>NivelDeReorden;

                   //escritura en el ArchivoInventario
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
        string str(NombreProducto);

      //Primera lectura del programa y creacion de los datos a listas
      nuevo = new(producto_nodo);
      nuevo -> ind = indice;
      (nuevo ->producto = NombreProducto); //Conversion del chart a String
      nuevo -> pc = PrecioDeCompra;
      nuevo -> pv = PrecioDeVenta;
      nuevo -> exi = ExistenciaFisicas;
      nuevo -> nvlr = NivelDeReorden;
      nuevo -> siguiente = NULL;
      inicio=nuevo;
      fin=nuevo;
      //Segunda lectura del ArchivoInventario binario
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

      nuevo = new(producto_nodo);
      nuevo -> ind = indice;
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
        cout << left << setw(8)<<setprecision(8)<<ptr->ind<<setw(22)<<setprecision(22)<<ptr->producto<<setw(22)<<setprecision(22)<< ptr->pc<< setw(18)<<setprecision(18)<< ptr->pv<<setw(19)<<setprecision(19)<<ptr->exi<< setw(16)<<setprecision(16)<<ptr->nvlr<<endl;
        ptr=ptr->siguiente;

      }
ArchivoInventario.close();
    }
  }


//Baja de productos directamente del ArchivoInventario
void Borrar_datos()
{
//variables
  int pos, flag = 0;
  int indice;
  char NombreProducto[80];
  int PrecioDeCompra;
  int PrecioDeVenta;
  int ExistenciaFisicas;
  int NivelDeReorden;
	cout<<"Ingrese la posicion del indice que desea eliminar del inventario :";
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



void Ordenar(){
  int opcion = 0; //variable local
    cout << "Tecle el # 1 para ordenar por ID\n";
    cin >> opcion;
    switch (opcion) {
      case 1:
        int swapped;
        /* Checking for empty list */
        if (inicio == NULL)
          break;
        do
        {
          swapped = 0;
          ptr1 = inicio;
          while (ptr1->siguiente != lprt)
          {
            cout << ptr1->ind << " "<< ptr1->siguiente->ind<<endl;
            if (ptr1->ind > ptr1->siguiente->ind)
            {
              swap(ptr1->ind, ptr1->siguiente->ind);
              swapped = 1;
              cout << ptr1->ind << " "<< ptr1->siguiente->ind<<endl;
            }
            ptr1 = ptr1->siguiente;
          }
          lprt = ptr1;
        }while(swapped);
         ptr1 = inicio;
        for(int i = 0; i<4; i++){
            cout<< ptr1->ind<<endl;
            ptr1 = ptr1->siguiente;
        }

        break;
    }

}
existencia_prod buscar(string producto_referencia){


 existencia_prod producto_encontrado;
  int i = 0;
  do{

     if(producto_referencia == inventario[i].producto){
       producto_encontrado.producto_posicion = i;
       producto_encontrado.producto_existencias = true;
       return producto_encontrado;
      }else

       i++;

     }while( i <=total);
     producto_encontrado.producto_existencias = false;
     return producto_encontrado;


}


void guardar_inventario(){
    ofstream ArchivoInventario("inventario1.bin", ios::out | ios::binary);
 

        char upload_inv[100];
        int i = 0;

        if (!ArchivoInventario) cout << "Error en la apertura del Archivo";

        else {
            do {
                if (inventario[i].ind ==NULL ) {
                    fflush(stdin); // vacia el buffer de la lectura
                    //escritura en el ArchivoInventario
                    ArchivoInventario.write( reinterpret_cast < char * > ( & inventario[i].ind), sizeof(inventario[i].ind));
                    ArchivoInventario.write( reinterpret_cast < char * > ( & inventario[i].producto), sizeof(inventario[i].producto));
                    ArchivoInventario.write(reinterpret_cast < char * > ( & inventario[i].pc), sizeof(inventario[i].pc));
                    ArchivoInventario.write(reinterpret_cast < char * > ( & inventario[i].pv), sizeof(inventario[i].pv));
                    ArchivoInventario.write(reinterpret_cast < char * > ( & inventario[i].exi), sizeof(inventario[i].exi));
                    ArchivoInventario.write( reinterpret_cast < char * > ( &inventario[i].nvlr), sizeof(inventario[i].nvlr));



                    i++;

                } else
                    i++;

            } while (i <= total);
        }


        ArchivoInventario.close();

        cout << "Se guardo el inventario" << endl;


}

void Ventas(){

    string producto_compra;
    existencia_prod producto_venta;
    int cantidad_vendida, i, resultado_compra, j;
    float total;

    j =0;
    total =0;

    informacion_ticket_info ticket_info[100];

	    do{

                cout << "Ingrese el producto que sea vender: ";
	        cin >> producto_compra;

	        if (producto_compra != "*" ) {
	            producto_venta = buscar(producto_compra);
	            i = producto_venta.producto_posicion;

	            if (producto_venta.producto_existencias) {

	                cout << "Cantidad: ";
	                cin >> cantidad_vendida;

                        if(inventario[i].exi == 0 ){
                            cout << "Producto agotado " << endl;
                        }
	                else if (cantidad_vendida > inventario[i].exi) {

	                    cout << "La cantidad solicitada excede el número de existencias" << endl;

	                    cout << "Desea comprar: " << inventario[i].exi<< " ? \n 1. Sí \n 2.No \n";
	                    cin >> resultado_compra;

	                    if (resultado_compra == 1) {
	                        cantidad_vendida = inventario[i].exi;
                                inventario[i].exi =0;

	                        ticket_info[j].cantidad_vendida= cantidad_vendida;
	                        ticket_info[j].producto_vendido= inventario[i].producto;
	                        ticket_info[j].precio_unitario = inventario[i].pv;
	                        ticket_info[j].subtotal_venta = ticket_info[j].precio_unitario*ticket_info[j].cantidad_vendida;
	                        total += ticket_info[j].subtotal_venta;

                                cout << "Producto" << inventario[i].producto<< " agotado" << endl;

	                        j++;

	                    }
					}else {

			                ticket_info[j].cantidad_vendida = cantidad_vendida;
                                        inventario[i].exi -= cantidad_vendida;
			                ticket_info[j].producto_vendido = inventario[i].producto;
			                ticket_info[j].precio_unitario = inventario[i].pv;
			                ticket_info[j].subtotal_venta = ticket_info[j].precio_unitario  * ticket_info[j].cantidad_vendida;
			                total += ticket_info[j].subtotal_venta;

                                        if (inventario[i].exi <= inventario[i].nvlr){
                                            cout << "Ordenar " << inventario[i].producto<< endl;
                                        }
			                j++;
	               		 }
				}else
	                cout << "El producto no existe" << endl;
	    	}

	    }while( producto_compra != "*" );

					total_ventas += total;


				    cout << setw(20) <<  "ticket_info"<< endl;
				    cout << "Cantidad: " << setw(10)<< " Producto: " << setw(10) << " PU: " << setw(10)  << " Sub: "<< endl;

				    for (int k=0; k<j; k++){

				        cout <<  ticket_info[k].cantidad_vendida  << setw(15) << ticket_info[k].producto_vendido << setw(15)  << ticket_info[k].precio_unitario<< setw(15)  << ticket_info[k].subtotal_venta << endl;

					}
				    cout << "" << endl;
				    cout << "" << endl;
				    cout << setw(30) <<"Total: " << total << endl;

				    j=0;


}
