#include <iostream>
#include <fstream>

using namespace std;
int main(){
fstream archivo("personal.dat",ios::out);//Funcion de escritura de archivos y lectura 
//Declaracion de variables 
char nombre[80];
int codigo; // 
double sueldo;

if(!archivo) cout<<"Error en la apertura del archivo";
else{
 do{
 cout<<"Escriba el codigo del empleado (0 para salir): ";
 cin>>codigo;
 if(codigo!=0){
 cout<<"Escriba el nombre";
 cin>>nombre;
 fflush(stdin);//vacía el bufer de lectura
 cout<<"Escriba el sueldo";
 cin>>sueldo;
 //escritura en el archivo, separando los campos
 //con espacios el fin de registro lo da un Intro
 archivo<<codigo<<" "<<nombre<<" "<<sueldo<<endl;
 }
}while(codigo!=0);
archivo.close();
}
return 0;
}
