
#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {


    int Matriz_a[3][4] = {
        {0, 1, 2,4} ,
        {4, 5, 6,4} ,
        {8, 9, 10,4}

    };

    int Matriz_b[4][3] = {
        {0, 1, 2} ,
        {4, 5, 6} ,
        {4, 5, 6},
        {3, 6, 7}

    };
// La matriz se divide entre si misma para determinar de cuanto es
    int a_fila = sizeof(Matriz_a)/sizeof(Matriz_a[0]);
    int a_columnas = sizeof(Matriz_a[0])/sizeof(Matriz_a[0][0]);
    cout<<"El numero de datos en la fila de la matriz A es:  = "<<a_fila <<"\n";
    cout <<'\n';
    cout<<"El numero de datos en la columna de la matriz A es: = "<<a_columnas <<"\n";
    cout <<'\n';


    int b_fila = sizeof(Matriz_b)/sizeof(Matriz_b[0]);
    int b_columnas = sizeof(Matriz_b[0])/sizeof(Matriz_b[0][0]);
    cout<<"El numero de datos en la fila de la matriz B es: =  ="<<b_fila<<"\n";
    cout <<'\n';
    cout<<"El numero de datos en la columna de la matriz B es: = "<<b_columnas<<"\n";
    cout <<'\n';
           // si la Matriz_a =
    if (a_columnas == b_fila){
        std::cout << "El numero de columnas en la Matriz A es igual al numero de filas en la Matriz B " << '\n';
                  std::cout <<'\n';
        std::cout << "La Multiplicacion es posible entre ambas matrices " << '\n';
        std::cout <<'\n';
        std::cout <<'\n';

        int c[a_fila][b_columnas];
        int i, j,k;
        for (i=0;i<a_fila; i++){
            for (j=0;j<b_columnas;j++){
                c[i][j]=0;
                for (k=0;k<b_fila;k++){
                    c[i][j] = c[i][j]+Matriz_a[i][k]*Matriz_b[k][j];
                }
            }
        }

       for(i=0;i<a_fila;i++)
        {
            for(j=0;j<b_columnas;j++)
            {
                cout<<"\t"<<c[i][j];
            }
                cout<<"\n\n";
        }
    }
    else{
        cout<<"La Multiplicacion no es posible ";

    }
    return 0;
}
