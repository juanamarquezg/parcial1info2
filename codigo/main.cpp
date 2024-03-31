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
    int cerradura[n-1];
    int rotaciones[n-1];
    arreglo = TomaDeValores(n);
    int fallaCond = arreglo[2];

////    // Prueba TomaDeValores
//    cout << "el numero de la fila es: " << arreglo[0]<< endl;
//    cout << "el numero de la columna es: " << arreglo[1]<< endl;
////    cout << "el ultimo numero de la fila es: " << arreglo[n-1];
    FilaPrincipal = arreglo[0];
    ColumnaPrincipal = arreglo[1];
    //cout <<"fila: "<<FilaPrincipal <<endl << "Columna Principal: " << ColumnaPrincipal;
    int primervalor= ValidacionImpar(FilaPrincipal, ColumnaPrincipal) ; // Valor maximo impar nxn
    if (fallaCond ==1){
            if ((arreglo[0]==1) &&(arreglo[1]<primervalor)){
                cout <<" Valor no valido :( " << endl;
                return 0;
            }

}
    int **primermatriz=inicializarM(primervalor); // matriz nxn valor

    FilaPrincipal = FilaPrincipal -1 ; // fila de la primera matriz
    ColumnaPrincipal = ColumnaPrincipal -1; // columna de la primera matriz
    int valorComparacion = primermatriz[FilaPrincipal][ColumnaPrincipal]; // Valor sacado para la comparacion ubicado segun fila y columna
    cerradura[0] = primervalor;
    rotaciones[0] = 0 ;
    int copiaFila = FilaPrincipal - 1;
    int copiaColumna = ColumnaPrincipal - 1 ;
    int copiaValorAnterior = valorComparacion; // Valor de la primera matriz 22
    for(int i =1; i <= n-2 ; i++){
        int valorcomp2 = arreglo[1+i];  // Valor de comparacion -1 , 0 , 1
        bool flag = true ;
        int copiaValor = primervalor -2; // Copia el primer valor impar necesario// Copia la primera matriz
        while (flag == true) {
            copiaValor = copiaValor + 2 ; // Aumenta la dimension nxn en 2  3x3--> 5x5
            int **MatrizAnterior=inicializarM(copiaValor); // Crea las matrices nxn 3x3--> 5x5 --> 7x7
            copiaFila = copiaFila + 1 ; // hace una copia de la ubicacion en fila
            copiaColumna = copiaColumna + 1;// hace una copia de la ubicacion en columna
            for (int estado=0 ; estado < 4 ; estado ++){
                int **matrizComparacion = rotarM(MatrizAnterior,copiaValor,estado);// Saca una nueva matriz , la siguiente a comparar
                int ValorCompaProximo = matrizComparacion[copiaFila][copiaColumna]; //Valor de la matriz futura
                bool flag2 = comparacion(copiaValorAnterior,ValorCompaProximo,valorcomp2);
                if (flag2 == true){
                    cerradura[i] = copiaValor;
                    rotaciones[i] = estado;
                    copiaValorAnterior = ValorCompaProximo; // el valor anterior se vuelve el proximo
                    flag = false; // pa salirse del while
                    estado = 4; // pa salise del four
                    copiaFila = FilaPrincipal - 1;
                    copiaColumna = ColumnaPrincipal - 1 ;
                    // Borrado de memoria de rotarM
                    for(int k = 0; k < copiaValor; k++) {
                        delete[] matrizComparacion[k];
                    }
                    delete[] matrizComparacion;
                }
                else {
                // Borrado de memoria de rotarM
                    for(int k = 0; k < copiaValor; k++) {
                    delete[] matrizComparacion[k];
                    }
                    delete[] matrizComparacion;
                }


            }
        for(int i = 0; i <copiaValor; i++) {
            delete[] MatrizAnterior[i];
        }
        delete[] MatrizAnterior ;
        }
    }
    cout << "los valores de la cerradura son: " ;
    for(int p =0;p< n-1 ;p++){
        cout << cerradura[p]<<" " ;

    }
    cout << "los valores de las rotaciones son: " ;
    for(int p =0;p< n-1 ;p++){
        cout << rotaciones[p]<<" " ;

    }

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

