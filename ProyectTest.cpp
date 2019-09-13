#include <iostream>

using namespace std;

int total = 0;

struct fecha{
    int dia;
    string mes;
    int anio;
};

struct dato {// definicion de la estrucutura
    int valor;
    string dia;
    float peso;
    char cat;
    fecha fechacompra;
};
dato info[10];// declaracion del arreglo de estructura

void Altas();
void Mostrar();
void Administrador();
void Ventas();

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

    Altas();
    Mostrar();
    Ventas();
    Administrador();
    return 0;
}

void Altas() {
    int i;
    i=total;
    int valor_temp;
    while (true) {
        cout << "Cual es el valor?: ";
        cin>>valor_temp;
        if (valor_temp == 0)
            break;
        info[i].valor = valor_temp;
        cout << "Dia: ";
        cin >> info[i].dia;
        cout << "Peso: ";
        cin >> info[i].peso;
        cout << "Categor�a: ";
        cin >> info[i].cat;
        cout<<"Fecha de compra (dia mes ano): ";
        cin>>info[i].fechacompra.dia>>info[i].fechacompra.mes>>info[i].fechacompra.anio;
        i++;
    }
    total = i;
}

void Mostrar(){
    int i;
    for(i=0;i<total;i++)
        cout<<info[i].peso<<info[i].fechacompra.mes<<endl;
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

void Ventas(){

}
