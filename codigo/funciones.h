#ifndef FUNCIONES_H
#define FUNCIONES_H

int *TomaDeValores(int n);
int ValidacionImpar(int n , int m );
int** inicializarM(int n);
int** rotarM(int** M, int n, int estado);
bool comparacion(int anterior, int proximo , int comp);
void DeletePuntero(int **ptr,int n);

#endif // FUNCIONES_H
