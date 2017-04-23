/*
Albán Aguilar
A00818811
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main ()
{
    stack<char> Pila, Pila1;
    string sLinea;
    int iCont = 0;
    cin >> sLinea;
    for (int iA = 0; sLinea[iA] != '&' ; iA++){
        iCont++;
        Pila.push( sLinea[iA] );
    }

    for (int iA = iCont+ 1; sLinea[iA] != '&' && sLinea[iA] != NULL; iA++){
        //iCont++;
        Pila1.push( sLinea[iA] );
    }

    //iCont = iCont + 1;
    bool bBandera;
    for (int iA = 0; Pila != NULL && Pila1 != NULL ; iA++ ){
        if ( Pila.top() == Pila1.top() ){
            bBandera = true;
        }
        else{
            bBandera = false;
        }
    }
    if (bBandera)
        cout << "La secuencia es correcta" << endl;
    else
        cout << "La secuencia es incorrecta" << endl;

  return 0;
}
