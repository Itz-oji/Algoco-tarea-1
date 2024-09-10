#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>  // Para medir el tiempo de ejecución

using namespace std;
using namespace std::chrono;  // Para simplificar el uso de std::chrono


// Función que combina dos listas ordenadas en una sola lista ordenada
vector<int> merge(const vector<int>& izquierda, const vector<int>& derecha) {
    vector<int> resultado;
    size_t i = 0, j = 0;

    // Comparar los elementos de ambas listas y añadir el menor al resultado
    while (i < izquierda.size() && j < derecha.size()) {
        if (izquierda[i] < derecha[j]) {
            resultado.push_back(izquierda[i]);
            i++;
        } else {
            resultado.push_back(derecha[j]);
            j++;
        }
    }

    // Añadir los elementos restantes de la lista izquierda, si los hay
    while (i < izquierda.size()) {
        resultado.push_back(izquierda[i]);
        i++;
    }

    // Añadir los elementos restantes de la lista derecha, si los hay
    while (j < derecha.size()) {
        resultado.push_back(derecha[j]);
        j++;
    }

    return resultado;
}


vector<int> mergeSort(const vector<int>& lista) {
    if (lista.size() <= 1) {
        return lista;
    }

    // Dividir la lista en dos mitades
    size_t medio = lista.size() / 2;
    vector<int> izquierda(lista.begin(), lista.begin() + medio);
    vector<int> derecha(lista.begin() + medio, lista.end());

    // Ordenar recursivamente ambas mitades
    izquierda = mergeSort(izquierda);
    derecha = mergeSort(derecha);

    // Combinar las dos mitades ordenadas
    return merge(izquierda, derecha);
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
        cout << "Ordenando los numeros usando Merge Sort..." << endl;
        vector<int> numerosOrdenados = mergeSort(numeros);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "Ordenamiento completado." << endl;
        cout << "Tiempo de ordenamiento: " << duration.count() << " ms" << endl;

        // Medir el tiempo de escritura del archivo
        start = high_resolution_clock::now();
        cout << "Escribiendo numeros ordenados a '" << archivoSalida << "'..." << endl;
        escribirNumerosAArchivo(numerosOrdenados, archivoSalida);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
        cout << "El archivo '" << archivoSalida << "' ha sido creado con los numeros ordenados." << endl;
        cout << "Tiempo de escritura: " << duration.count() << " ms\n" << endl;
    }
    return 0;
}
