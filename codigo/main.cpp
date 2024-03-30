#include <iostream>
#include <funciones.h>
using namespace std;

int main()
{
    int n,FilaPrincipal ,ColumnaPrincipal,*arreglo;
    cout << "Ingrese el numero de elementos contando fila, columna y comparacion: " << endl;
    cin >> n;
    while (n < 3) {
        cout << "Ingrese un numero valido: " << endl;
        cin >> n;
    }
    int cerradura[n-2];
    int rotaciones[n-2];
    arreglo = TomaDeValores(n);
////    // Prueba TomaDeValores
//    cout << "el numero de la fila es: " << arreglo[0]<< endl;
//    cout << "el numero de la columna es: " << arreglo[1]<< endl;
////    cout << "el ultimo numero de la fila es: " << arreglo[n-1];
    FilaPrincipal = arreglo[0];
    ColumnaPrincipal = arreglo[1];
    //cout <<"fila: "<<FilaPrincipal <<endl << "Columna Principal: " << ColumnaPrincipal;
    int primervalor= ValidacionImpar(FilaPrincipal, ColumnaPrincipal) ; // Valor maximo impar nxn
    int **primermatriz=inicializarM(primervalor); // matriz nxn valor
    FilaPrincipal = FilaPrincipal -1 ;
    ColumnaPrincipal = ColumnaPrincipal -1;
    int valorComparacion = primermatriz[FilaPrincipal][ColumnaPrincipal]; // Valor sacado para la comparacion
    cerradura[0] = primervalor;
    rotaciones[0] = 0 ;
    for(int i =1; i <= n-2 ; i++){
        int valorcomp2 = arreglo[1+i];  // Valor de comparacion -1 , 0 , 1




//    }
//    cout <<"el valor primero a comparar es: "<< valorComparacion <<endl ;

//    // Prueba de validacionimpar
//    cout << "valor impar mayor: " << primervalor << endl;

//     Prueba Primera matriz
//    cout << "Matriz original:\n";
//    for(int i = 0; i < primervalor; ++i) {
//        for(int j = 0; j < primervalor; ++j) {
//            cout << primermatriz[i][j] << ' ';
//        }
//        cout << '\n';
//    }

//cout << "cerradura "<< cerradura[0] <<" rotaciones:"<<rotaciones[0]<< endl ;




    // Borrado de memoria

    for(int i = 0; i < primervalor; ++i) {
        delete[] primermatriz[i];
    }
    delete[] primermatriz;
    delete[] arreglo ;
    return 0;
}

