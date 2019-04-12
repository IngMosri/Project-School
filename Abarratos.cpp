#include <iostream>
#include <iomanip>
#include <string>
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
void MostrarCuentasDeUsuarios();
void AltaUsuario();
void BajaUsuario();
void ModicacionDeUsuario();
void ConsultaDeUsario();
void ModificacionPC(int mod);
void ModificacionesDePV(int mod);
void ModificacionExistencias(int mod);
void ModificacionNR(int mod);
void ModificacionDeUsuarioRegistrado(int modUs);
void ModificacionDeContrasenaRegistrado(int modUs);
void TicketDeventa();
int VentaTotal=0;
int CantidadTotal;
int total = 5;   //variable globales
int TotalUsuarios =0;
int cantidad_v[100];
string prod[100];
int Subtotal = 0;
int Importe=0;
int buscar(string BuscarProducto);
string UsuarioVenta[100];
int id[100] ={2,4,1,3,5};
string producto[100]={"Leche","Pan","Agua","Huevos","Refresco"};
float pc[100]={10,10,10,10,10};
float pv[100]={10,20,10,15,11};
int existencia[100]={23,20,12,20,10};
int nr[100]={5,2,8,5,3};
int st[100]={1,1,1,1,1};
string usuarios[100];
string contrasenas[100];
string corteTicket[100];
int corteTicketInt[100];
int v;
int k=1;
int h=0;
int u=0;
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

void Ventas(/* arguments */){
    string productos;
    int pos;
    int i;
    int j;
    int z;
    int y=VentaTotal;
    string VentaUsuario, Ventacontrasena;
    int x=CantidadTotal;
    int opcion; //variable local
    string Vendedor;

    cout << "Estas Accediendo al apartado de ventas " << endl;
    std::cout << "Introduce usuario y contrasena " << endl;
    cin>>VentaUsuario;
    cin>>Ventacontrasena;
    for(z=0; z<TotalUsuarios; z++){
        if(VentaUsuario==usuarios[z]){
            if(Ventacontrasena==contrasenas[z]){
                UsuarioVenta[z] = VentaUsuario;
                std::cout << "Bienvenido Usuario   "<<UsuarioVenta[z] << '\n';
            }
        }

    }
    while (true) {
        cout << "Ingrese el producto que desea Vender :  ";
        cin >> productos;
        if (productos== "**")
            return Administrador();
        else {
            if (productos == "*")
                return TicketDeventa();
            {
                int buscar(string BuscarProducto);
                pos = buscar(productos);
                if (pos == -1)

                    cout << "Producto no se encuentra en el inventario " << endl;
                else {
                    i = pos;
                    prod[y]=productos;
                    if (st[i] == 0)
                        cout << "Producto no exite " << endl;
                    else {
                        if (existencia[i] == 0)
                            cout << "Ya no queda"<< productos[i]<<endl;
                        else {
                            cout << "Cantidad:  ";
                            cin >> cantidad_v[y];
                            if (cantidad_v[y] > existencia[i]) {
                                cout << "No tenemos lo suficiente : " << cantidad_v << " solo tenemos la siguiente cantidad : " << existencia[i] << endl;
                                cout << "Aun asi desea continuar con la venta?" << endl << "1. si" << endl << "2. No" << endl;
                                cin >> opcion;
                                if (opcion == 1)
                                    cantidad_v[y] = existencia[i];
                                existencia[i] = 0;
                            }
                            else {
                                existencia[i] -= cantidad_v[y];
                                if (existencia[i] < nr[i])
                                    cout << "Solicitar mas producto con el provedor :  " << productos[i] << endl;
                                else{

                                }
                            }
                        }
                        y++;
                    }
                    VentaTotal=y;
                    v += VentaTotal;
                }
            }
        }
    }
}

/* Menu de administradir */
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

    int opcion = 0; //variable local
    do
    {
        cout<< "Estas en el modulo Administrador\n";
        cout<< "1 Alta\n";
        cout << "2  Baja" << '\n';
        cout << "3  Consultas" << '\n';
        cout << "4  Modificaciones"<< '\n';
        cout << "5  Mostrar inventario" << '\n';
        cout << "6  Administrador de cuentas" << '\n';
        cout << "7  Corte de caja General" << '\n';
        cout << "8  Regresar al menu anterior" << '\n';
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
            case 7: CorteDecajaGeneral();
                break;
            case 8: RegresarAlMenuAnterior();
                break;
            default : cout << "opcion invalida";
        }
    }while(opcion != 8);
}

void Altas(/* arguments */)
{
    string temp_prod;
    int temp_pc,temp_pv,temp_exi,temp_nr;
    std::cout << "Ingrese Producto" << '\n';
    cin>>temp_prod;
    if(buscar(temp_prod)== -1){
        producto[total] =temp_prod;
        do{
            std::cout << "ingrese PC" << '\n';
            cin>>temp_pc;
            std::cout << "Ingrese PV" << '\n';
            cin>>temp_pv;
        }while (temp_pc>temp_pv);
        st[total] = 1;
        pc[total] = temp_pc;
        pv[total] = temp_pv;
        do {
            std::cout << "Ingrese existencia" << '\n';
            cin>>temp_exi;
            std::cout << "ingrese NR" << '\n';
            cin>>temp_nr;
        }while(temp_exi<temp_nr);
        existencia[total] = temp_exi;
        nr[total] = temp_nr;
//std::cout << "total" <<total <<'\n';
        id[total] = total+1;
        total++;
    }
    else
        std::cout << "Producto duplicado " << '\n';

}

void Bajas(/* arguments */) {
    string producto;
    int BuscarProducto;
    int i, pos;
    while(true) {
        std::cout << "Producto que se quiere dar de baja" << '\n';
        std::cin >> producto;
        if(producto=="*")
            break;
      // int buscar(string BuscarProducto);
        pos = buscar(producto);
        std::cout << "producto dado de baja " << '\n';
        if(pos==-1)
            std::cout << "no existe" << '\n';
        else {
            if (st[pos]==1)
            {
                std::cout << "Producto dado de baja" << '\n';
                st[pos]=-1;
            }
        }
    }
}
void Consultas(/* arguments */)
{
    int pos; //variable local
    int precio_compra;
    int precio_venta;
    int existencia_consultas;
    int numero_de_reorden;
    int status;

    string BuscarProducto;
    while (true) {
        int i = 0;
        cout << "Producto que desea consultar :";
        cin>>BuscarProducto;
        if (BuscarProducto=="*")
            break;
        pos=buscar(BuscarProducto);
        if (pos == -1 || st[pos] == -1)
            cout << "No existe o esta dado de baja " << endl;
        else{
            std::cout << "Producto En el inventario: " <<producto[pos]<<'\n' ;
            std::cout << "Precio de compra " <<pc[pos]<< '\n';
            std::cout << "Precio de venta" <<pv[pos]<< '\n';
            std::cout << "Status " <<st[pos]<< '\n';
          }
    }
}

int buscar(string BuscarProducto) {
    int i = 0;
    while (i < total && producto[i] != BuscarProducto)
        i++;
    if(i==total)
        return -1;
    else
        return i;
}
/* Menu de Modificaciones de cuentas y productos. */
void Modificaciones(/* arguments */) {
    int mod;
    int opcion = 0;
    string modicaciones;

    while ( true )
    {
        cout << "Cual es el producto para modificar: ?";
        cin>>modicaciones;
        if (modicaciones == "*")
            break;
        mod=buscar(modicaciones);
        if (mod == -1 || st[mod] == -1)
            cout<< "Este producto no existe"<< endl;
        else
        {
            do{

                cout << "Que desea modificar\n";
                cout << "1. Precio de compra(PC) \n";
                cout << "2. Precio de venta(PV) \n";
                cout << "3. Existencias \n";
                cout << "4. NR(Nivel de reorden)\n";
                cout << "5. Salir\n";
                cin >> opcion;

                switch (opcion)
                {

                    case 1:ModificacionPC(mod);
                        break;
                    case 2: ModificacionesDePV(mod);
                        break;
                    case 3: ModificacionExistencias(mod);
                        break;
                    case 4: ModificacionNR(mod);
                        break;
                    case 5: cout << "Cambios Exitosamente Guardados\n";
                }
            }while (opcion != 5);
            return Administrador();
        }
    }
}

void ModificacionPC(int mod){
    int PrecioDecompra;
    cout<<"Ingrese el nuevo precio de compra"<< endl;
    cin>>PrecioDecompra;
    pc[mod]  = PrecioDecompra;
}

void ModificacionesDePV(int mod){
    int PrecioDeVenta;
    cout<<"Ingrese el nuevo precio de venta"<< endl;
    cin>>PrecioDeVenta;
    pv[mod]  = PrecioDeVenta;
}

void ModificacionExistencias(int mod){
    int NuevasExistencias;
    cout<<"Ingrese las nuevas existencias del producto "<< endl;
    cin>>NuevasExistencias;
    existencia[mod]  = NuevasExistencias;
}

void ModificacionNR(int mod){
    int NuevoNivelDeReorden;
    cout<<"Ingrese el nuevo NR(nivel de reorden) "<< endl;
    cin>>NuevoNivelDeReorden;
    nr[mod]  = NuevoNivelDeReorden;
}


/* Menu de constual de inventario */
void MostarInventario( )
{
    int opcion = 0; //variable local


    {
        std::cout << "Presione 1 si desea ver el menu por ID" << '\n';
        std::cout << "/Presione 2 si desea ver el menu por producto" << '\n';
        std::cin >> opcion;
        switch (opcion){
            case 1:

                for (int i = 1; i < total; i++)
                {
                    for (int j = 0; j < total-i; j++)
                    {
                        // id[i] = 5
                        // id[j] = 3
                        if (id[j] > id[j + 1])
//                        if (producto[j] > producto[j + 1])
                        {
                            int temporal = id[j];
                            id[j] = id[j + 1];
                            id[j+ 1] = temporal;

                            string tempString = producto[j];
                            producto[j] = producto[j + 1];
                            producto[j+ 1] = tempString;

                            temporal = pc[j];
                            pc[j] = pc[j + 1];
                            pc[j+ 1] = temporal;

                            temporal = pv[j];
                            pv[j] = pv[j + 1];
                            pv[j+ 1] = temporal;

                                temporal = existencia[j];
                            existencia[j] = existencia[j + 1];
                            existencia[j+ 1] = temporal;

                                temporal = nr[j];
                            nr[j] = nr[j + 1];
                            nr[j+ 1] = temporal;

                                temporal = st[j];
                            st[j] = st[j + 1];
                            st[j+ 1] = temporal;
                        }
                    }
                }

                cout<<setw(10)<<"ID"<<setw(20)<<"Producto"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(12)<<"Existencias"<<setw(10)<<"NR"<<setw(10)<<"ST"<<endl;
                for (int h = 0; h < total; h++)
                {
                    if(st[h]==1)
                    {
                        cout<<setw(10)<<id[h]<<setw(20)<< producto[h] <<setw(10)<<pc[h]<<setw(10)<<pv[h]<<setw(12)<<existencia[h]<<setw(10)<<nr[h]<<setw(10)<<st[h]<<endl;
                    }
                }
                break;
            case 2:
                int j;
                 for (int i = 1; i < total; i++)
                {
                    for (int j = 0; j < total-i; j++)
                    {

                        if (producto[j] > producto[j + 1])
                        {
                            int temporal = id[j];
                            id[j] = id[j + 1];
                            id[j+ 1] = temporal;

                            string tempString = producto[j];
                            producto[j] = producto[j + 1];
                            producto[j+ 1] = tempString;

                            temporal = pc[j];
                            pc[j] = pc[j + 1];
                            pc[j+ 1] = temporal;

                            temporal = pv[j];
                            pv[j] = pv[j + 1];
                            pv[j+ 1] = temporal;

                                temporal = existencia[j];
                            existencia[j] = existencia[j + 1];
                            existencia[j+ 1] = temporal;

                                temporal = nr[j];
                            nr[j] = nr[j + 1];
                            nr[j+ 1] = temporal;

                                temporal = st[j];
                            st[j] = st[j + 1];
                            st[j+ 1] = temporal;
                        }
                    }
                }


                cout<<setw(10)<<"Producto"<<setw(20)<<"ID"<<setw(10)<<"PC"<<setw(10)<<"PV"<<setw(12)<<"Existencias"<<setw(10)<<"NR"<<setw(10)<<"ST"<<endl;
                for (j = 0; j < total; j++)
                    if(st[j]==1)
                        cout<<setw(10)<<producto[j]<<setw(20)<<id[j] <<setw(10)<<pc[j]<<setw(10)<<pv[j]<<setw(12)<<existencia[j]<<setw(10)<<nr[j]<<setw(10)<<st[j]<<endl;
                break;
        }
    }

}
void AdministradorDeCuentasDeUsuario(/* arguments */) {
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
            case 1: AltaUsuario();
                break;
            case 2: BajaUsuario();
                break;
            case 3: ConsultaDeUsario();
                break;
            case 4: ModicacionDeUsuario();
                break;
            case 5: AdministradorDeCuentasDeUsuario();
                break;
            case 6: RegresarAlMenuAnterior();
                break;
            default : cout << "opcion invalida";\
            }
    }while(opcion != 6);

}
void AltaUsuario(/* arguments */) {

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

void BajaUsuario(/* arguments */) {
    string usuarios;
    int i,pos;
    while (true) {
        std::cout << "Usuario que se quiere dar de baja" << '\n';
        std::cin >> usuarios;
        if(usuarios=="*")
            break;
        pos= buscar(usuarios);
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
void ConsultaDeUsario(/* arguments */) {
    std::cout << "Los usuarios registrados son: " << '\n';
    for (int h = 0; h < TotalUsuarios; h++)
        std::cout <<usuarios[h]<< '\n';
}
void ModicacionDeUsuario(/* arguments */) {
    int modUs;
    int opcion =0;
    string modicacionUsuario;
    while (true)
    {
        std::cout << "Escriba el nombre de usuario que quiere modificar" << '\n';
        std::cin >> modicacionUsuario;
        if(modicacionUsuario=="*")
            break;
        modUs=buscar(modicacionUsuario);
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

                    case 1:ModificacionDeUsuarioRegistrado(modUs);
                        break;
                    case 2:ModificacionDeContrasenaRegistrado(modUs);
                        break;
                }
            }while (opcion !=2);
            return AdministradorDeCuentasDeUsuario();
        }

    }
}

void ModificacionDeUsuarioRegistrado(int modUs) {
    int NuevoUsuario;
    std::cout << "Ingrese el nuevo usuario" << '\n';
    std::cin >> NuevoUsuario;
    usuarios[modUs] = NuevoUsuario;

}
void ModificacionDeContrasenaRegistrado(int modUs) {
    int NuevaContrasena;
    std::cout << "Ingrese nueva contrasena" << '\n';
    std::cin >> NuevaContrasena;
    contrasenas[modUs] = NuevaContrasena;

}

/* Menu de corte de caja general*/
void CorteDecajaGeneral(/* arguments */) {
    cout<<setw(40)<<"Abarrotes el Mosri\n \n \n"<<endl;
    int i=0;
    int l=1;

    for(int z(0);z<u;z++) {
    }

    for (i= 0;i<v;i++)
    {
        cout<<setw(10)<<"Vendedor"<< UsuarioVenta[l]<<endl;
        Subtotal +=pv[i]*cantidad_v[i];

    }

    cout<<"Subtotal = "<<Subtotal<<endl;
}
void RegresarAlMenuAnterior(/* arguments */) {
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


    {
    }
}
void TicketDeventa(){
    cout<<setw(40)<<"Abarrotes el Mosri\n \n \n"<<endl;
    int i=0;
    std::cout << "Vendedor: "<<UsuarioVenta[h]<< '\n';h++;
    v--;
    for (i= 0;i<VentaTotal;i++)
    {
            cout << setw(20) << "Producto " << prod[i] << setw(20) << "Cantidad " << cantidad_v[i] << setw(20)
                 << "Precio " << pv[i] << endl;
            Subtotal += pv[i] * cantidad_v[i];
            corteTicket[k] = prod[i];
            k++;
            corteTicketInt[k] = cantidad_v[i];
            k++;
            corteTicketInt[k] = pv[i];
            k++;
    }
    cout<<"Subtotal = "<<Subtotal<<endl;
    VentaTotal = 0;
    Subtotal =0;

}
