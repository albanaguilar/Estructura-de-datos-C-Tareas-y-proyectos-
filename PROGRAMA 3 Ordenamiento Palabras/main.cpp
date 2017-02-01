/*
Albán Aguilar Campos
A00818811
ITC

Escribe	la función acomodaPalabraEnOrden para acomodar	una	palabra	dentro	de	un	arreglo	de
palabras para que queden en	orden	alfabético de	menor a mayor.

Ejemplo	de	la	ejecución	del	programa
casa
LISTA:	casa
perro
LISTA:	casa	perro
agua
LISTA:	agua	casa	perro
mano
LISTA:	agua	casa	mano	perro
fin

*/

#include <iostream>
#include <string>

using namespace std;

void despliega(string sArr[], int iCantidad) {
    cout << "LISTA: ";
    for(int iK = 0; iK < iCantidad; iK++) {
        cout << sArr[iK] << " ";
    }
    cout << endl;
}

//Funcion para acomodar palabras en orden alfabetico
void acomodaPalabraEnOrden(string sArr[], int iCantidad, string sPalabra){
    string sVar = sPalabra;
    int iJ = iCantidad - 1;
    while ( iJ >= 0 && sVar < sArr[iJ] ){
        sArr[ iJ + 1 ] = sArr[iJ];
        iJ--;
    }
    sArr[iJ + 1] = sVar;
}

int main()
{
    string sPalabra;
    string sArr[50];
    int iCantidad = 0;
    cin >> sPalabra;
    do {
    acomodaPalabraEnOrden(sArr, iCantidad, sPalabra);
    iCantidad++;
    despliega(sArr, iCantidad);
    cin >> sPalabra;
    } while (sPalabra != "fin");
    return 0;
}
