
#include <iostream>

using namespace std;

struct dato{ // estructura
    string nombre;
    int cel;
};
dato agenda[100]; //arreglo de estructuras 

struct info{  //estructura
    string nombre;
    int cel;
    info *sig;
};
info *inicio;
info *fin;
info *ptr;
info *nuevo;

int main(){
    string nombre_temp;
    int i=0,j;
    while(true){
        cout<<"Nombre: ";
        cin>>nombre_temp;
        if (nombre_temp=="*")
            break;
        agenda[i].nombre=nombre_temp; 
        cout<<"Celular: ";
        cin>>agenda[i].cel;
        i++;
    }
    nuevo=new(info);
    nuevo->nombre=agenda[0].nombre; //construccion de la lista 
    nuevo->cel=agenda[0].cel;
    nuevo->sig=NULL;
    inicio=nuevo;
    fin=nuevo;
    
    for(j=1;j<i;j++){
        nuevo=new(info);
        nuevo->nombre=agenda[j].nombre;
        nuevo->cel=agenda[j].cel;
        nuevo->sig=NULL;
        fin->sig=nuevo;
        fin=nuevo;
    }
    
    ptr=inicio;
    for(j=0;j<i;j++){
        cout<<ptr->nombre<<" "<<ptr->cel<<endl;
        ptr=ptr->sig;
    }    
    return 0;
}

