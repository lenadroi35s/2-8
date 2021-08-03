#include <iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

void leer_vector(double vector[], double tamanio) {
    for (int i = 0; i < tamanio; i++) {
        cout << endl << "Ingrese el elemento #" << (i + 1) << ": ";
        cin >> vector[i];
    }
}

void imprime_vector(double vector[], double tamanio) {
    cout << endl << endl << "elementos del vector";
    for (int i = 0; i < tamanio; i++) {
        cout << endl << "Elemento # " << (i + 1) << " : " << vector[i];
    }
}

double sumatoria_vector(double vector[], double tamanio) {
    double suma = 0;
    for (int i = 0; i < tamanio; i++) {
        suma += vector[i];

    }
    return suma;
}

double promedio(double vector[], double tamanio) {
    double suma = 0;
    suma = sumatoria_vector(vector, tamanio) / tamanio;
    return suma;
}

double maxx(double vector[], double tamanio) {
    double m = vector[0];

    for (int i = 1; i < tamanio; i++) {
        if (vector[i] > m) {
            m = vector[i];
        }
    }
    return m;
}

double minn(double vector[], double tamanio) {
    double m = vector[0];

    for (int i = 1; i < tamanio; i++) {
        if (vector[i] < m) {
            m = vector[i];
        }
    }
    return m;
}

void maxmin(double vector[], double tamanio, double &ma, double &mi) {
    ma = maxx(vector, tamanio);
    mi = minn(vector, tamanio);
}

void aleatorio(double vector[], double tamanio) {

    for (int i = 0; i < tamanio; i++) {
        vector[i] = rand();
    }
}

void ordenar(double vector[], double tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vector[i] > vector[j]) {
                double aux;
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

bool ver(double vector[], double max) {
    int b = true;
    for (int x = 0; x < max; x++) {
        int a = vector[x];
        if ((vector[x] - a) > 0) {
            b = false;
        } else {
            b = true;
            break;
        }
    }
    return b;
}

int pos(double vector[], double max) {
    int b = 0;
    for (int x = 0; x < max; x++) {
        int a = vector[x];
        if ((vector[x] - a) > 0) {
            b = -1;
        } else {
            b = x + 1;
            break;
        }
    }
    return b;
}

int main() {
    srand(time(NULL));
    const int max = 3;
    double num[max];
    leer_vector(num, max);
    imprime_vector(num, max);
    double suma = sumatoria_vector(num, max);
    double promedioo = promedio(num, max);
    cout << endl << "La sumatoria del vector es: " << suma;
    cout << endl << "El promedio del vector es: " << promedioo;
    cout << endl << "El max es: " << maxx(num, max);
    cout << endl << "El min es: " << minn(num, max);
    double a, b;
    cout << endl << "Max y min por referencia: ";
    maxmin(num, max, a, b);
    cout << endl << "El max es: " << a;
    cout << endl << "El min es: " << b;
    cout << endl << "Numeros aleatorios";
    double alea[max];
    aleatorio(alea, max);
    imprime_vector(alea, max);
    cout << endl << "Verdadero si hay un entero, falso si no hay entero en el vector" << endl;
    int aa = ver(num, max);
    if (aa == 1) {
        cout << endl << "Es verdadero" << endl;
    } else {
        cout << endl << "Es falso" << endl;
    }
    int bb = pos(num, max);
    if (bb == -1) {
        cout << endl << "No se encontro numero entero" << endl;
    } else {
        cout << endl << "La posicion del numero entero encontrado es: " << bb << endl;
    };
    cout << endl << "Ordenar los valores del vector:" << endl;
    cout << endl << "Desordenado";
    imprime_vector(num, max);
    cout << endl << endl << "Ordenado";
    ordenar(num, max);
    imprime_vector(num, max);
}