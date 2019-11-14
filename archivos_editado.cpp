#include <iostream>

#include <fstream>

#include <string>

using namespace std;

int main() {
  //nombre del archivo binario
  ofstream ArchivoInventario("inventario1.bin",ios::out | ios::binary);

  //Variables Globales
  int total = 0;
  int indice;
  char NombreProducto[80];
  int PrecioDeCompra;
  int PrecioDeVenta;
  int ExistenciaFisicas;
  int NumeroDeReorden;

  if (!ArchivoInventario)
    cout << "Error en la apertura del archivo";
  else {
    do {
      cout << "Escriba el codigo del producto(0 para salir): ";
      cin >> indice;
      if (indice != 0) {
        cout << " Escriba el nombre del producto ";
        cin >> NombreProducto;
        fflush(stdin); //vacía el bufer de lectura
        cout << " Escriba el precio de compra ";
        cin >> PrecioDeCompra;
        cout << " Escriba el precio de venta ";
        cin >> PrecioDeVenta;
        cout << " Escriba las exitencias fisicas ";
        cin >> ExistenciaFisicas;
        cout << " Escriba el # de reorder";
        cin >> NumeroDeReorden;
        //Escritura del Archivo en Binario'

        ArchivoInventario.write(
          reinterpret_cast < char * > ( & indice), sizeof(indice));
        ArchivoInventario.write(NombreProducto, 80);
        ArchivoInventario.write(
          reinterpret_cast < char * > ( & PrecioDeCompra), sizeof(PrecioDeCompra));
        ArchivoInventario.write(
          reinterpret_cast < char * > ( & PrecioDeVenta), sizeof(PrecioDeVenta));
        ArchivoInventario.write(
          reinterpret_cast < char * > ( & ExistenciaFisicas), sizeof(ExistenciaFisicas));
        ArchivoInventario.write(
          reinterpret_cast < char * > ( & NumeroDeReorden), sizeof(NumeroDeReorden));

      }
    } while (indice != 0);
    ArchivoInventario.close();
  }
  return 0;
}
