#include <iostream>
using namespace std;

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
                M_rotada[i][j] = M[i][j];
                break;
            }
        }
    }
    return M_rotada;
}

int main() {
    int n = 3;
    int** M = inicializarM(n);

    cout << "Matriz original:\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << M[i][j] << ' ';
        }
        cout << '\n';
    }

    int estado;
    cout << "\ningresa el estado de rotacion (0 = neutro, 1 = rotacion 1, 2 = rotacion 2, 3 = rotacion 3): ";
    cin >> estado;

    int** M_rotada = rotarM(M, n, estado);

    cout << "\nMatriz rotada (estado " << estado << "):\n";
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << M_rotada[i][j] << ' ';
        }
        cout << '\n';
    }

    for(int i = 0; i < n; ++i) {
        delete[] M[i];
        delete[] M_rotada[i];
    }
    delete[] M;
    delete[] M_rotada;

    return 0;
}

