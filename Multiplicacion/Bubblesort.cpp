#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>  // Para medir el tiempo de ejecución
#include <sstream>

using namespace std;
using namespace std::chrono;  // Para simplificar el uso de std::chrono

// Función para multiplicar dos matrices
vector<vector<int>> multiplicarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    size_t filasA = A.size();
    size_t columnasA = A[0].size();
    size_t columnasB = B[0].size();

    // Crear una matriz resultado con tamaño adecuado inicializada a 0
    vector<vector<int>> resultado(filasA, vector<int>(columnasB, 0));

    // Realizar la multiplicación de matrices
    for (size_t i = 0; i < filasA; i++) {
        for (size_t j = 0; j < columnasB; j++) {
            for (size_t k = 0; k < columnasA; k++) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return resultado;
}

// Función que lee una matriz desde un archivo
vector<vector<int>> leerMatrizDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    vector<vector<int>> matriz;
    int valor;
    
    if (!archivo) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return matriz;
    }

    while (archivo) {
        vector<int> fila;
        string linea;
        getline(archivo, linea);
        istringstream ss(linea);
        while (ss >> valor) {
            fila.push_back(valor);
        }
        if (!fila.empty()) {
            matriz.push_back(fila);
        }
    }
    
    archivo.close();
    return matriz;
}

// Función que escribe una matriz en un archivo
void escribirMatrizAArchivo(const vector<vector<int>>& matriz, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    
    if (!archivo) {
        cerr << "No se pudo abrir el archivo " << nombreArchivo << endl;
        return;
    }

    for (const auto& fila : matriz) {
        for (size_t i = 0; i < fila.size(); i++) {
            archivo << fila[i];
            if (i != fila.size() - 1) {
                archivo << " ";  // Separador entre columnas
            }
        }
        archivo << endl;
    }

    archivo.close();
}

int main() {
    for(int i=0; i<10; i++){
        string texto1 = "matrizA.txt";
        string texto2 = "matrizB.txt";
        if(i !=0){
            texto1 = texto1.substr(0, 7) + to_string(i) + ".txt";
            texto2 = texto2.substr(0, 7) + to_string(i) + ".txt";
        }
        string archivoMatrizA = texto1;
        string archivoMatrizB = texto2;
        string archivoSalida = "resultado_matriz.txt";

        // Leer la matriz A
        auto start = high_resolution_clock::now();
        cout << "Leyendo matriz A desde '" << archivoMatrizA << "'..." << endl;
        vector<vector<int>> matrizA = leerMatrizDesdeArchivo(archivoMatrizA);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Tamano de la matriz A: " << matrizA.size() << "x" << matrizA[0].size() << endl;
        cout << "Tiempo de lectura de matriz A: " << duration.count() << " ms\n" << endl;

        // Leer la matriz B
        start = high_resolution_clock::now();
        cout << "Leyendo matriz B desde '" << archivoMatrizB << "'..." << endl;
        vector<vector<int>> matrizB = leerMatrizDesdeArchivo(archivoMatrizB);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Tamano de la matriz B: " << matrizB.size() << "x" << matrizB[0].size() << endl;
        cout << "Tiempo de lectura de matriz B: " << duration.count() << " ms\n" << endl;

        // Verificar que las matrices se pueden multiplicar
        if (matrizA[0].size() != matrizB.size()) {
            cerr << "Error: Las matrices no se pueden multiplicar. Columnas de A no coinciden con filas de B." << endl;
            return 1;
        }

        // Multiplicar las matrices
        start = high_resolution_clock::now();
        cout << "Multiplicando matrices..." << endl;
        vector<vector<int>> resultado = multiplicarMatrices(matrizA, matrizB);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Multiplicacion completada." << endl;
        cout << "Tiempo de multiplicacion: " << duration.count() << " ms\n" << endl;

        // Escribir la matriz resultado en el archivo
        start = high_resolution_clock::now();
        cout << "Escribiendo matriz resultado a '" << archivoSalida << "'..." << endl;
        escribirMatrizAArchivo(resultado, archivoSalida);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "El archivo '" << archivoSalida << "' ha sido creado con la matriz resultado." << endl;
        cout << "Tiempo de escritura: " << duration.count() << " ms" << endl;
        cout << "TERMINAMOS UNA EJECUCION\n" << endl;
    }
    return 0;
}
