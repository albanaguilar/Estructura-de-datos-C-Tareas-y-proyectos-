// Albán AGuilar Campos
//A00818811
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Nodo
{	public:
    Nodo *pSig;
    int iInfo;
    Nodo( ) { pSig = NULL; }
    Nodo (int iDato) { iInfo = iDato;  pSig = NULL; }
    Nodo (int iDato, Nodo *pSiguiente)
    { iInfo = iDato; pSig = pSiguiente; }
};

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ListaLineal
{
    friend ostream& operator << (ostream &os, const ListaLineal & L)
    {
        Nodo *pP = L.pInicio;
        while ( pP != NULL )
        {
            os << pP->iInfo << " ";
            pP = pP->pSig;
        }
        os << endl;
        return os;
    }
    friend bool operator == (const ListaLineal& L1,const ListaLineal & L2)
    {
        Nodo *pP1 = L1.pInicio;
        Nodo *pP2 = L2.pInicio;
        while ( pP1 != NULL && pP2 != NULL && pP1->iInfo == pP2->iInfo)
        {
            pP1 = pP1->pSig;
            pP2 = pP2->pSig;
        }
        return pP1 == pP2;
    }

private:
    Nodo *pInicio;
public:
    //Inicializando la lista como lista vacía
    ListaLineal() { pInicio = NULL; }
    //Copy Contructor
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
    //Borra el último nodo de la lista
    void borraFinalLista()
    {
        Nodo *pAnt = NULL;
        Nodo *pAct = pInicio;
        while ( pAct->pSig != NULL)
        {
            pAnt = pAct;
            pAct = pAct -> pSig;
        }
        if (pAnt == NULL)
            pInicio = NULL;
        else pAnt->pSig = NULL;
        delete pAct;
    }

    void borraValor(int valor){
        Nodo *pP = pInicio;
        Nodo *pQ = NULL;
        while ( pP != NULL && pP ->iInfo == valor){
            pQ = pP;
            pP = pP ->pSig;
            delete pQ;
        }
    }

    void borraTodosValor(int valor){
        Nodo *pP = pInicio;
        Nodo *pQ = NULL;
        while ( pP != NULL ){
            if ( pP ->iInfo == valor){
                pQ = pP;
                pP = pP ->pSig;
                delete pQ;
                pQ = NULL;
            }
            else
                pP = pP ->pSig;
        }
    }

    friend bool operator < (const ListaLineal & L1, const ListaLineal & L2){
        int iAcum1 = 0;
        int iAcum2 = 0;
        Nodo *pP = L1.pInicio;
        Nodo *pQ = L2.pInicio;
        while(pP != NULL){
            iAcum1 += pP ->iInfo;
            pP = pP -> pSig;
        }
        while( pQ != NULL){
            iAcum2 += pQ -> iInfo;
            pQ = pQ -> pSig;
        }
        return (iAcum1 < iAcum2);
    }

    friend bool operator > (const ListaLineal & L1, const ListaLineal & L2){
        int iAcum1 = 0;
        int iAcum2 = 0;
        Nodo *pP = L1.pInicio;
        Nodo *pQ = L2.pInicio;
        while(pP != NULL){
            iAcum1 += pP ->iInfo;
            pP = pP -> pSig;
        }
        while( pQ != NULL){
            iAcum2 += pQ -> iInfo;
            pQ = pQ -> pSig;
        }
        return (iAcum1 > iAcum2);
    }
};

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    ListaLineal L1;
    for(int iK = 1; iK <= 5; iK++)
        L1.meterFinalLista(iK);

    cout << "Lista 1 = " << L1;
    ListaLineal L2;
    for(int iK = 1; iK <= 5; iK++)
        L2.meterFinalLista(iK);
    cout << "Lista 2 = " << L2;

    return 0;
}
