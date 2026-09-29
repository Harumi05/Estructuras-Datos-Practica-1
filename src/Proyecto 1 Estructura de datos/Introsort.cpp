#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;


// ======================================================
// INTROSORT
// ======================================================

void introsort(vector<string>& palabras) {
    // std::sort utiliza Introsort en las implementaciones
    // estándar modernas de C++.
    sort(palabras.begin(), palabras.end());
}


// ======================================================
// PROGRAMA PRINCIPAL
// ======================================================

int main() {

    // Hace más rápida la entrada/salida
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> palabras;

    // Reservamos espacio aproximado para el dataset
    palabras.reserve(200001);

    // --------------------------------------------------
    // ABRIR DATASET
    // --------------------------------------------------

    ifstream archivo("dataset.txt");

    if (!archivo.is_open()) {
        cerr << "Error: no se pudo abrir dataset.txt\n";
        return 1;
    }


    // --------------------------------------------------
    // LEER PALABRAS
    // --------------------------------------------------

    string palabra;

    while (archivo >> palabra) {
        palabras.push_back(palabra);
    }

    archivo.close();

    cout << "Cantidad de palabras cargadas: "
         << palabras.size()
         << "\n";


    // --------------------------------------------------
    // MEDIR TIEMPO DE INTROSORT
    // --------------------------------------------------

    auto inicio = chrono::high_resolution_clock::now();

    introsort(palabras);

    auto fin = chrono::high_resolution_clock::now();


    // --------------------------------------------------
    // TIEMPO EN SEGUNDOS
    // --------------------------------------------------

    chrono::duration<double> tiempo = fin - inicio;

    cout << "\nTiempo de ordenamiento: "
         << tiempo.count()
         << " segundos\n";


    // --------------------------------------------------
    // MOSTRAR ALGUNAS PALABRAS ORDENADAS
    // --------------------------------------------------

    cout << "\nPrimeras palabras ordenadas:\n";

    int cantidadMostrar = min(20, (int)palabras.size());

    for (int i = 0; i < cantidadMostrar; i++) {
        cout << i + 1 << ". " << palabras[i] << "\n";
    }


    // --------------------------------------------------
    // GUARDAR RESULTADO
    // --------------------------------------------------

    ofstream salida("dataset_ordenado.txt");

    if (!salida.is_open()) {
        cerr << "Error: no se pudo crear dataset_ordenado.txt\n";
        return 1;
    }

    for (const string& p : palabras) {
        salida << p << "\n";
    }

    salida.close();


    cout << "\nLas palabras ordenadas fueron guardadas en "
            "dataset_ordenado.txt\n";

    return 0;
}