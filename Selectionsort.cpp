#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>  // Para medir el tiempo de ejecución

using namespace std;
using namespace std::chrono;  // Para simplificar el uso de std::chrono

// Función que implementa el algoritmo Selection Sort
void selectionSort(vector<int>& lista) {
    int n = lista.size();

    for (int i = 0; i < n - 1; i++) {
        // Encontrar el índice del elemento mínimo en la sublista no ordenada
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[min_idx]) {
                min_idx = j;
            }
        }
        // Intercambiar el elemento mínimo con el primer elemento de la sublista no ordenada
        swap(lista[min_idx], lista[i]);
    }
}

// Función que lee números de un archivo de texto y los devuelve como un vector de enteros
vector<int> leerNumerosDesdeArchivo(const string& nombreArchivo) {
    vector<int> numeros;
    ifstream archivo(nombreArchivo);
    int numero;

    if (!archivo) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return numeros;
    }

    while (archivo >> numero) {
        numeros.push_back(numero);
    }

    archivo.close();
    return numeros;
}

// Función que escribe una lista de números en un archivo de texto, uno por línea
void escribirNumerosAArchivo(const vector<int>& numeros, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);

    if (!archivo) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    for (int numero : numeros) {
        archivo << numero << endl;
    }

    archivo.close();
}

int main() {
    for(int i=0; i<10; i++){
        string texto = "numeros.txt";
        if(i !=0){
            texto = texto.substr(0, 7) + to_string(i) + ".txt";
        }
        string archivoEntrada = texto;
        string archivoSalida = "numeros_ordenados.txt";

        // Medir el tiempo de lectura del archivo
        auto start = high_resolution_clock::now();
        cout << "Leyendo numeros desde '" << archivoEntrada << "'..." << endl;
        vector<int> numeros = leerNumerosDesdeArchivo(archivoEntrada);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Total de numeros leidos: " << numeros.size() << endl;
        cout << "Tiempo de lectura: " << duration.count() << " ms" << endl;

        // Medir el tiempo de ordenamiento
        start = high_resolution_clock::now();
        cout << "Ordenando los numeros usando Selection Sort..." << endl;
        selectionSort(numeros);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Ordenamiento completado." << endl;
        cout << "Tiempo de ordenamiento: " << duration.count() << " ms" << endl;

        // Medir el tiempo de escritura del archivo
        start = high_resolution_clock::now();
        cout << "Escribiendo numeros ordenados a '" << archivoSalida << "'..." << endl;
        escribirNumerosAArchivo(numeros, archivoSalida);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "El archivo '" << archivoSalida << "' ha sido creado con los numeros ordenados." << endl;
        cout << "Tiempo de escritura: " << duration.count() << " ms\n" << endl;
    }
    return 0;
}
