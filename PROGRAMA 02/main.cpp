/*
Albán Aguilar Campos
A00818811
ITC

Descripcion del problema:
Aplicación para validar si un string cumple con las siguientes reglas:
• El Usuario y la Contraseña no pueden ser iguales.
• La nueva contraseña no puede ser igual a la anterior.
• Debe contener al menos 8 caracteres.
• Debe contener al menos una letra minúscula.
• Debe contener al menos una letra mayúscula.
• Debe contener al menos un dígito.
• Debe contener al menos uno de los siguientes: “+”, “-“, “*”, “#” y “$”.
• No puede tener más de dos caracteres idénticos en forma consecutiva.
• No puede usar más de dos dígitos consecutivos. Ej. “123”
• No puede emplear más de dos letras consecutivas. Ej. “def”. Ej. “DeF”

Ejemplo de la ejecución del programa
LuisYabe
4Am*2w3r
8
LuisYabe
NO LuisYabe
4Am*2w3r
NO 4Am*2w3r
Am+12nb$
SI Am+12nb$
Abcdefgh
NO Abcdefgh
12345678
NO 12345678
Am+222n$
NO Am#222nb$
2Am+2n$2
SI 2Am-2n$2
Abc+2n$3
NO Abc+2n$3
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//Funcion para validar presencia de letras mayusculas
bool validacionLetraMayuscula (string sContrasenaNueva){
    for ( int iAcum = 0; iAcum < sContrasenaNueva.length(); iAcum++ ){
        if ( sContrasenaNueva[iAcum] >= 65 && sContrasenaNueva[iAcum] <= 90 ){
            return 1;
        }
    }
    return 0;
}

//Funcion para validar presencia de letras minusculas
bool validacionLetraMinuscula (string sContrasenaNueva){
    for ( int iAcum = 0; iAcum < sContrasenaNueva.length(); iAcum++ ){
        if ( sContrasenaNueva[iAcum] >= 97 && sContrasenaNueva[iAcum] <= 122 ){
            return 1;
        }
    }
    return 0;
}

//Funcion para validar presencia de numeros
bool validacionDigito (string sContrasenaNueva){
    for ( int iAcum = 0; iAcum < sContrasenaNueva.length(); iAcum++ ){
        if ( sContrasenaNueva[iAcum] >= 48 && sContrasenaNueva[iAcum] <= 57 ){
            return 1;
        }
    }
    return 0;
}

//Funcion para validar presencia de simbolos o caracteres especiales
bool validacionSimbolo (string sContrasenaNueva){
    for ( int iAcum = 0; iAcum < sContrasenaNueva.length() ; iAcum++ ){
        if ( sContrasenaNueva[iAcum] == '+' || sContrasenaNueva[iAcum] == '-'
        || sContrasenaNueva[iAcum] == '*' || sContrasenaNueva[iAcum] == '#'
        || sContrasenaNueva[iAcum] == '$' ){
            return 1;
        }
    }
    return 0;
}

//Funcion para verificar si hay caracteres identicos continuos
bool validaCaracteresIdenticos ( string sContrasenaNueva ){
    for ( int iAcum = 0; iAcum < sContrasenaNueva.length() - 2; iAcum++ ){
        if (  sContrasenaNueva[iAcum] == sContrasenaNueva[iAcum + 1] ){
            return 0;
        }
    }
    return 1;
}

//Funcion para validar caracteres continuos
bool validaCaracteresContinuos ( string sContrasenaNueva ){
    int iAcumulador = 0;
    for ( int iAcum = 0; iAcum < sContrasenaNueva.length() - 2; iAcum++ ){
        if( sContrasenaNueva[iAcum] == sContrasenaNueva[iAcum + 1] - 1 ){
            iAcumulador++;
        }
        else{
            iAcumulador = 0;
        }
    }
    if ( iAcumulador >= 2 ){
                return 0;
            }
            else{
                return 1;
            }
}

//Funcion para validar presencia de letras continuas
bool validaLetrasContinuas ( string sContrasenaNueva ){
    int iC, iD;
    int iAcumulador = 0;
    for ( int iAcum = 0; iAcum < sContrasenaNueva.length() - 2; iAcum++ ){
            iC = tolower(sContrasenaNueva[iAcum]);
            iD = tolower(sContrasenaNueva[iAcum + 1]);
        if ( iC == iD - 1 ){
            iAcumulador++;
        }
        else{
            iAcumulador = 0;
        }
        if( iAcumulador >= 2 ){
        return 0;
        }
    }
    return 1;
}

//Funcion de entrada de datos
void datos( string &sUsuario, string &sContrasena,int &iNum ){
    cin >> sUsuario;
    cin >> sContrasena;
    cin >> iNum;
}

//Funcion para realizar la validacion de contraseña
void proceso(int iContador, int iNum, string sContrasenaNueva, string sUsuario, string sContrasena){
    while (iContador < iNum){
        cin >> sContrasenaNueva;
        bool bVar = validacionLetraMayuscula(sContrasenaNueva);
        bool bVar1 = validacionLetraMinuscula(sContrasenaNueva);
        bool bVar2 = validacionDigito ( sContrasenaNueva);
        bool bVar3 = validacionSimbolo (sContrasenaNueva);
        bool bVar4 = validaCaracteresIdenticos( sContrasenaNueva );
        bool bVar5 = validaCaracteresContinuos( sContrasenaNueva );
        bool bVar6 = validaLetrasContinuas ( sContrasenaNueva );
        if ( ( sContrasena != sUsuario ) && (sContrasenaNueva != sContrasena) &&
             ( sContrasenaNueva.length() >= 8 ) && ( bVar ) && ( bVar1) && ( bVar2 ) &&
             ( bVar3 ) && ( bVar4 ) && ( bVar5 ) && ( bVar6 ) ){
            cout << "SI " <<sContrasenaNueva << endl;
        }
        else{
            cout << "NO " <<sContrasenaNueva << endl;
        }
        iContador++;
    }
}

int main(){
    string sUsuario, sContrasena, sContrasenaNueva;
    int iNum, iContador = 0;
    datos(sUsuario, sContrasena, iNum);

    proceso(iContador, iNum, sContrasenaNueva, sUsuario, sContrasena);
    return 0;
}
