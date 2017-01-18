/*
Albán Aguilar Campos
A00818811
ITC

Homework 1.- Desencrypt the code and display the mesaje, problem based on ACM´s 3488 problem (http://acm.pku.edu.cn/JudgeOnline/problem?id=3488)
Example of execution:
Cantidad de líneas? 3
Teclea las líneas del mensaje:
__arrsc_mancao__a__
_.mgpousehoarreelan
_sao_hmoc\imgpdsclE
El mensaje descifrado es:
En la clase de programacion
hacemos muchos programas.
*/

#include <iostream>
#include <string>

using namespace std;

int numeroLineas (){
    int iNum;
    cout << "Teclea un numero: ";
    cin >> iNum;
    cin.ignore();
    return iNum;
}

string mensajeEsncriptado(string sLinea, string sMensaje, int iNum){
    for (int iAcum = 0; iAcum < iNum; iAcum++) {
        cout << "Teclea la cadena: ";
        cin >> sLinea;
        sMensaje += sLinea;
    }
    cout << endl;
    return sMensaje;
}

void desplegarMatriz(int iRenglones, int iColumnas, char cMatriz[50][50], string sMensaje){
    int iK = 0;
    for (int iRen = 0; iRen < iRenglones; iRen++ ){
        for (int iCol = 0; iCol < iColumnas; iCol++ ){
            cMatriz[iRen][iCol] = sMensaje[iK];
            iK++;
            cout << cMatriz[iRen][iCol];
        }
        cout <<endl;
    }
}

void mensajeDesencriptado( string sLinea, int iColumnas, int iRenglones, char cMatriz[50][50] ){
    sLinea = "";
    for (int iCol = iColumnas - 1; iCol > 0; iCol--){
        for (int iRen = iRenglones - 1; iRen >= 0; iRen--){
            sLinea = sLinea + cMatriz[iRen][iCol];
        }
   }

   for (int iAcum = 0; iAcum < sLinea.length(); iAcum++ ){
        if ( sLinea[iAcum] == '_' ){
            sLinea[iAcum] = ' ';
        }
        else if ( sLinea[iAcum] == '\\'){
            sLinea[iAcum] = '\n';
        }
    }
    cout << endl;
    cout << sLinea;
    cout << endl;
}

int main()
{
    int iNum;
    char cMatriz[50][50];
    string sLinea, sMensaje = "";
    iNum = numeroLineas();
    sMensaje = mensajeEsncriptado(sMensaje, sLinea, iNum);
    int iRenglones = iNum;
    int iColumnas = sMensaje.length() / iNum;
    desplegarMatriz( iRenglones, iColumnas, cMatriz, sMensaje );
    mensajeDesencriptado( sLinea, iColumnas, iRenglones, cMatriz );

    return 0;
}
