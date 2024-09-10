#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <sstream>

using namespace std;
using namespace std::chrono;

// Función para sumar dos matrices
vector<vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    size_t n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n, 0));

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }

    return resultado;
}

// Función para restar dos matrices
vector<vector<int>> restarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    size_t n = A.size();
    vector<vector<int>> resultado(n, vector<int>(n, 0));

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            resultado[i][j] = A[i][j] - B[i][j];
        }
    }

    return resultado;
}

// Algoritmo de Strassen para multiplicar matrices
vector<vector<int>> multiplicarStrassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    size_t n = A.size();
    
    if (n == 1) {
        // Caso base: multiplicación de matrices de 1x1
        return {{A[0][0] * B[0][0]}};
    }

    // Dividir las matrices en submatrices
    size_t mitad = n / 2;
    vector<vector<int>> A11(mitad, vector<int>(mitad));
    vector<vector<int>> A12(mitad, vector<int>(mitad));
    vector<vector<int>> A21(mitad, vector<int>(mitad));
    vector<vector<int>> A22(mitad, vector<int>(mitad));
    vector<vector<int>> B11(mitad, vector<int>(mitad));
    vector<vector<int>> B12(mitad, vector<int>(mitad));
    vector<vector<int>> B21(mitad, vector<int>(mitad));
    vector<vector<int>> B22(mitad, vector<int>(mitad));

    // Rellenar las submatrices
    for (size_t i = 0; i < mitad; i++) {
        for (size_t j = 0; j < mitad; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mitad];
            A21[i][j] = A[i + mitad][j];
            A22[i][j] = A[i + mitad][j + mitad];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mitad];
            B21[i][j] = B[i + mitad][j];
            B22[i][j] = B[i + mitad][j + mitad];
        }
    }

    // Calcular las matrices de Strassen
    vector<vector<int>> M1 = multiplicarStrassen(sumarMatrices(A11, A22), sumarMatrices(B11, B22));
    vector<vector<int>> M2 = multiplicarStrassen(sumarMatrices(A21, A22), B11);
    vector<vector<int>> M3 = multiplicarStrassen(A11, restarMatrices(B12, B22));
    vector<vector<int>> M4 = multiplicarStrassen(A22, restarMatrices(B21, B11));
    vector<vector<int>> M5 = multiplicarStrassen(sumarMatrices(A11, A12), B22);
    vector<vector<int>> M6 = multiplicarStrassen(restarMatrices(A21, A11), sumarMatrices(B11, B12));
    vector<vector<int>> M7 = multiplicarStrassen(restarMatrices(A12, A22), sumarMatrices(B21, B22));

    // Calcular las submatrices del resultado
    vector<vector<int>> C11 = sumarMatrices(restarMatrices(sumarMatrices(M1, M4), M5), M7);
    vector<vector<int>> C12 = sumarMatrices(M3, M5);
    vector<vector<int>> C21 = sumarMatrices(M2, M4);
    vector<vector<int>> C22 = sumarMatrices(restarMatrices(sumarMatrices(M1, M3), M2), M6);

    // Combinar las submatrices en la matriz resultado
    vector<vector<int>> resultado(n, vector<int>(n));
    for (size_t i = 0; i < mitad; i++) {
        for (size_t j = 0; j < mitad; j++) {
            resultado[i][j] = C11[i][j];
            resultado[i][j + mitad] = C12[i][j];
            resultado[i + mitad][j] = C21[i][j];
            resultado[i + mitad][j + mitad] = C22[i][j];
        }
    }

    return resultado;
}

// Función para leer una matriz desde un archivo
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

// Función para escribir una matriz en un archivo
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

        // Verificar que las matrices se puedan multiplicar
        if (matrizA.size() != matrizA[0].size() || matrizB.size() != matrizB[0].size() || matrizA.size() != matrizB.size()) {
            cerr << "Error: Las matrices deben ser cuadradas y de igual tamaño para Strassen." << endl;
            return 1;
        }

        // Multiplicar las matrices usando Strassen
        start = high_resolution_clock::now();
        cout << "Multiplicando matrices con el algoritmo de Strassen..." << endl;
        vector<vector<int>> resultado = multiplicarStrassen(matrizA, matrizB);
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
        cout << "El archivo '" << archivoSalida << "' ha sido creado." << endl;
        cout << "Tiempo de escritura de matriz resultado: " << duration.count() << " ms\n" << endl;
        cout << "TERMINAMOS UNA EJECUCION\n" << endl; 
        }
    return 0;
}
