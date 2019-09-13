#include <iostream>
using namespace std;

int main(){
    struct dato{
    int valor;
    string dia;
    float peso;
    char cat;
};
    dato info[10];

    cout<<"cual es el valor?: ";
    cin>>info.valor;
    cout<< "Dia: ";
    cin>>info.dia;
    std::cout << "peso:";
    cin>>info.peso;
    cout<<"categoria: ";
    cin>>info.cat;

    cout<<"Dia "<<info.dia;

    return 0;
}
