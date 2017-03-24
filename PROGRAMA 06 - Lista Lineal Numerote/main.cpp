#include <iostream>
using namespace std;

class Nodo
{ public:
 Nodo *pSig;
 int iInfo;
 Nodo( ) { pSig = NULL; }
 Nodo (int iDato) { iInfo = iDato; pSig = NULL; }
 Nodo (int iDato, Nodo *pSiguiente)
 { iInfo = iDato; pSig = pSiguiente; }
};
class ListaLineal
{
 friend ostream& operator << (ostream &os, const ListaLineal & L)
 {
 Nodo *pP = L.pInicio;
 while ( pP != NULL )
 {
 os << pP->iInfo;
 pP = pP->pSig;
 }
 os << endl;
 return os;
 }
 friend istream& operator >> (istream &is, ListaLineal & L)
 {
 string sS = "";
 is >> sS;
 for (int iK = 0; iK < sS.length(); iK ++)
 L.meterInicioLista(sS[iK] - 48);
 return is;
 }
 friend ListaLineal operator + (const ListaLineal &L1, const ListaLineal &L2){
    Nodo L3;
    Nodo *p1 = L1.pInicio;
    Nodo *p2 = L2.pInicio;
    int dato;
    int carrier = 0;

    while ( p1 != NULL && p2 != NULL){
        if ( (p1 -> iInfo + p2 -> iInfo) + carrier >= 10){
            carrier = (p1 -> iInfo + p2 -> iInfo) + carrier % 10;
            //L3.iInfo = meterFinalLista(carrier);
        }
        else{
            carrier = 0;
        }
        L3.iInfo = meterFinalLista( p1 -> iInfo + p2 -> iInfo + carrier );
        p1 = p1 -> pSig;
        p2 = p2 -> pSig;
        dato = *p1 + *p2;
    }

}
private:
 Nodo *pInicio;
public:
 //Inicializando la lista como lista vacía
 ListaLineal() { pInicio = NULL; }
 ListaLineal ( const ListaLineal &L){
     pInicio = NULL;
    int p;
    while ( p != NULL ){
        meterFinalLista(p -> iInfo);
        p = p -> pSig;
    }
 }
 ListaLineal& operator= (const ListaLineal &L){
    if(this != &L1)
        {
          while ( pInicio != NULL)
            borrarInicioLista();
            //Copy Constructor
            Nodo*p = L1.pInicio;
            while(p!= NULL){
            meterFinalLista(p->iInfo);
            p = p->pSig;

        }
        return *this;
    }
 }
 //Borra todos los nodos que queden en la lista
 ~ListaLineal()
 {
 while ( pInicio != NULL)
 borrarInicioLista();
 }
 //La lista está vacía cuando pInicio es NULL
 bool listaVacia() { return (pInicio == NULL); }
 //Agregar un nodo al inicio de la lista
 //El inicio esta apuntado por pInicio
 void meterInicioLista(int iValor)
 {
 //Crear un nodo
 Nodo *pNuevo = new Nodo(iValor, pInicio);
 pInicio = pNuevo;
 }
 //Quita el nodo que esta apuntado por pInicio
 //PRECONDICIÓN: La lista no debe estar vacía
 void borrarInicioLista()
 {
 //pP apunta al nodo que voy a borrar
 Nodo *pP = pInicio;
 //pInicio apunta al siguiente nodo de la lista
 pInicio = pInicio -> pSig;
 //Borrar el nodo
 delete pP;
 }
 //Regresa el contenido del nodo apuntado por inicio
 int observaLista() { return pInicio->iInfo; }
 //Agregar un nodo al final de la lista
 void meterFinalLista(int iValor)
 {
 Nodo *pN = new Nodo(iValor);
 if ( pInicio == NULL )
 pInicio = pN;
 else
 {
 Nodo *pP = pInicio;
 while ( pP->pSig != NULL ) pP = pP->pSig;
 pP -> pSig = pN;
 }
 }
};

int main(int argc, const char * argv[]) {
 ListaLineal L1, L2;
 cout << "Numerore 1? ";
 cin >> L1;
 cout << "Numerote 2? ";
 cin >> L2;
 ListaLineal LR;
 LR = L1 + L2;
 cout << "Resultado: " << LR;
 return 0;
}
