#include <iostream>

using namespace std;

class Nodo
{
public:
    Nodo *pSig;
    int iInfo;
    Nodo( )
    {
        pSig = NULL;
    }
    Nodo (int iDato)
    {
        iInfo = iDato;
        pSig = NULL;
    }
    Nodo (int iDato, Nodo *pSiguiente)
    {
        iInfo = iDato;
        pSig = pSiguiente;
    }
};
class ListaLineal
{
    friend ostream& operator << (ostream &os, const ListaLineal & L){
        Nodo *pP = L.pInicio;
        while ( pP != NULL )
        {
            os << pP->iInfo;
            pP = pP->pSig;
        }
        os << endl;
        return os;
    }
    friend istream& operator >> (istream &is, ListaLineal & L){
        string sS = "";
        is >> sS;
        for (int iK = 0; iK < sS.length(); iK ++)
            L.meterInicioLista(sS[iK] - 48);
        return is;
    }

    friend ListaLineal operator + (const ListaLineal &L1, const ListaLineal &L2){
        Nodo *p1=L1.pInicio;
        Nodo *p2=L2.pInicio;
        ListaLineal L3;
        int idato, iCarry= 0;
        while(p1 != NULL && p2!= NULL)
        {
            if((p1-> iInfo+p2->iInfo)+iCarry>=10)
            {
                iCarry=(p1-> iInfo+p2->iInfo+iCarry)/10;
                idato= (p1-> iInfo+p2->iInfo+iCarry)%10;
                L3.meterFinalLista(idato);
            }
            else
            {
                idato=(p1-> iInfo+p2->iInfo+iCarry);
                iCarry=0;
                L3.meterFinalLista(idato);
            }

            p1=p1->pSig;
            p2=p2->pSig;

        }

        while(p1 !=NULL)
        {
            idato=iCarry+p1->iInfo;
            if(idato>=10)
            {
                iCarry= idato/10;
                idato= idato%10;
                L3.meterFinalLista(idato);
            }
            else
            {
                iCarry=0;
                L3.meterFinalLista(idato);
            }

            p1=p1->pSig;

        }
        while(p1 !=NULL)
        {
            idato=iCarry+p2->iInfo;
            if(idato>=10)
            {

                iCarry= idato/10;
                idato= idato%10;
                L3.meterFinalLista(idato);
            }
            else
            {
                iCarry=0;
                L3.meterFinalLista(idato);
            }

            p2=p2->pSig;

    }

    return L3;

}
private:
    Nodo *pInicio;
public:
//Inicializando la lista como lista vacía
    ListaLineal(){
        pInicio = NULL;
    }
//Borra todos los nodos que queden en la lista
    ~ListaLineal(){
    while ( pInicio != NULL)
    borrarInicioLista();

    }

    //Copy Constructor
    ListaLineal(const ListaLineal &L1)
    {
        pInicio= NULL;
        Nodo*P=L1.pInicio;
        while(P!= NULL)
        {
            meterFinalLista(P->iInfo);
            P=P->pSig;

        }

    }

    ListaLineal& operator =(const ListaLineal &L1){ //Sobracarga de ={

        if(this != &L1)
        {
            while ( pInicio != NULL)
            borrarInicioLista();
            //Copy Constructor
            Nodo*P=L1.pInicio;

            while(P!= NULL)
            {
                meterFinalLista(P->iInfo);
                P=P->pSig;

            }
        }
    return *this;
    }
//La lista está vacía cuando pInicio es NULL
        bool listaVacia()
        {
            return (pInicio == NULL);
        }
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
        int observaLista()
        {
            return pInicio->iInfo;
        }
//Agregar un nodo al final de la lista
        void meterFinalLista(int iValor)
        {
            Nodo *pN = new Nodo(iValor);
            if ( pInicio == NULL ){
                pInicio = pN;
            }
            else
            {
                Nodo *pP = pInicio;
                while ( pP->pSig != NULL ) pP = pP->pSig;
                pP -> pSig = pN;
            }
        }

};

    int main()
    {
        ListaLineal L1, L2;
        cout << "Numerore 1? ";
        cin >> L1;
        cout << "Numerote 2? ";
        cin >> L2;
        ListaLineal L3;
        L3 = L1 + L2;
        cout << "Resultado: " << L3;
        return 0;
    }
