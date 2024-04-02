#include <iostream>
using namespace std;

// Funcion que recibe el numero de valores que tendra la llave k(...),
// pide los valores de la llave y los almacena en un arreglo
int* TomaDeValores(int n){
    int c;
    n = n-1;
    int* k = new int[n];
    for (int i = 0; i<= n; i++){
        cout << "Ingrese el valor para el elemento " << i + 1 << " : ";
        cin >> c;
        int j = i;
        while (j>=2){
            if ((c != -1) && (c!=0) && (c!=1)){  // Condicion para verificar que la comparacion si sea un -1,0 y 1
                cout << "Ingrese un valor valido por favor: " ;
                cin >> c;

            }
            else j =1 ;
        }
        while (j == 1){
            if ( (2==k[0]&&(c==2))){
                cout << "Ingrese un valor valido para la columna" << endl ;
                cin >> c;

            }
            else j=2;
        }
        k[i] = c;// Asignacion al arreglo del dato
    }
    return k; // Retorna un puntero al arreglo de datos iniciales
}
    // Define el tamaño de la primera matriz (el tamaño minimo)
int ValidacionImpar(int n , int m ){
    if (n>m){
        int validar = n % 2;
        if (validar == 0){
            n = n +1;
            return n ;
        }
        else return n;
    }
    else if ((n==1) && ( m == 1  )){
        n = 3 ;
        return n;
    }
    else if (n<m){
        int validar = m % 2;
        if (validar == 0){
            m = m +1;
            return m ;
        }
        else return m;
    }
    else {
        int validar = n % 2;
        if (validar == 0){
            n = n +1;
            return n ;
        }
        else return n;
    }
}
// Hace la matriz impar tomando como referencia el numero n
int** inicializarM(int n) {
    int** M = new int*[n];
    for(int i = 0; i < n; ++i)
        M[i] = new int[n];

    int valor = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == n/2 && j == n/2)
                M[i][j] = 0;
            else
                M[i][j] = valor++;
        }
    }
    return M;
}

int** rotarM(int** M, int n, int estado) {
    int** M_rotada = new int*[n];
    for(int i = 0; i < n; ++i)
        M_rotada[i] = new int[n];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            switch(estado) {
            case 0:
                M_rotada[i][j] = M[i][j];

                break;
            case 1:
                M_rotada[n-j-1][i] = M[i][j];
                break;
            case 2:
                M_rotada[n-i-1][n-j-1] = M[i][j];
                break;
            case 3:
                M_rotada[j][n-i-1] = M[i][j];
                break;
            default:
                cout << "opción no valida " << endl;
                break;
            }
        }
    }
    return M_rotada;
}
bool comparacion(int anterior, int proximo , int comp){
    bool flag = false;
    switch(comp){
        case -1:
            if (anterior < proximo) return true;
            else return flag;
        break;

        case 0:
            if (anterior == proximo ) return true;
            else return flag;
        break;

        case 1:
            if(anterior > proximo) return true;
            else return flag;
        default:
            return flag;
    }
}
void DeletePuntero(int **ptr,int n)
{
    for (int i=0; i<n ; i++) delete[] ptr[i];
    delete [] ptr;
}

