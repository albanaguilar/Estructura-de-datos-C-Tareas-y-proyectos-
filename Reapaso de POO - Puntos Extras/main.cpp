/*
Albán Aguilar Campos
A00818811
ITC

Programa para verificar el paso de dtos y repaso de programacion orientada a objetos
*/

#include <iostream>
#include <string>
using namespace std;

//Clase persona con los atributos de edad y nombre, constructor default, constructor con parametros, y despliega
class Persona{
private:
    string sNombre;
    int iEdad;

public:
    Persona(){
        sNombre = "";
        iEdad = 1;
    }
    Persona(string sNombre, int iEdad ){
        this->sNombre = sNombre;
        this->iEdad = iEdad;
    }
    void despliega(){
        cout << sNombre << endl;
        cout << iEdad << endl;
        cout << endl;
    }
};

//Funcion para desplegar datos
void Hace (Persona Z){
    Z.despliega();
}

//Funcion para obtener datos
Persona obtiene(){
        Persona N ("Luis", 35);
        return N;
    }

int main()
{
    Persona P("Juan", 18);
    P.despliega();
    Persona W(P);
    W.despliega();
    Hace(P);
    P.despliega();
    Persona M = obtiene();
    M.despliega();

    return 0;
}
