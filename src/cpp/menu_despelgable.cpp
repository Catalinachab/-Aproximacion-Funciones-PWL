#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include "include/json.hpp"
#include "pwl.h"
using namespace std;
using namespace chrono;

using json = nlohmann::json;

string elegir_funcion() {
    string opcion_elegida;
    while (true) {
        cout << "\nFunciones disponibles\n---------------------\nA. Fuerza Bruta\nB. Backtracking\nC. Programación Dinámica\n";
        cout << "Seleccione una opción: ";
        getline(cin, opcion_elegida);

        transform(opcion_elegida.begin(), opcion_elegida.end(), opcion_elegida.begin(), ::toupper);

        if (opcion_elegida == "A" || opcion_elegida == "B" || opcion_elegida == "C") {
            break; 
        } else {
            cout << "Opción inválida. Inténtelo de nuevo.\n";
        }
    }
    return opcion_elegida;
}

string elegir_archivo() {
    string opcion_elegida;
    while (true) {
        cout << "\nInstancias disponibles\n---------------------\nA. titanium.json\nB. aspen_simulation.json\nC. ethanol_water_vle.json\nD. toy_instance.json\nE. optimistic_instance.json\n";
        cout << "Seleccione una opción: ";
        getline(cin, opcion_elegida);

        transform(opcion_elegida.begin(), opcion_elegida.end(), opcion_elegida.begin(), ::toupper);

        if (opcion_elegida == "A" || opcion_elegida == "B" || opcion_elegida == "C" || opcion_elegida == "D" || opcion_elegida == "E") {
            break; 
        } else {
            cout << "Opción inválida. Inténtelo de nuevo.\n";
        }
    }
    return opcion_elegida;
}


int main() {
    string archivo_seleccionado = elegir_archivo();
    string instance_name;
    if (archivo_seleccionado == "A") instance_name = "titanium.json";
    else if (archivo_seleccionado == "B") instance_name = "aspen_simulation.json";
    else if (archivo_seleccionado == "C") instance_name = "ethanol_water_vle.json";
    else if (archivo_seleccionado == "D") instance_name = "toy_instance.json";
    else if (archivo_seleccionado == "E") instance_name = "optimistic_instance.json";
    else cout << "Opción inválida.\n";

    ifstream f("../../data/" + instance_name);
    json instance;
    f >> instance;

    int K, m1, m2;
    cout << "Ingrese K (cantidad de breakpoints): ";
    cin >> K;
    cin.ignore();
    cout << "Ingrese m1 (discretización del eje x): ";
    cin >> m1;
    cin.ignore();
    cout << "Ingrese m2 (discretización del eje y): ";
    cin >> m2;
    cin.ignore();
    int N = instance["n"];

    string funcion_seleccionada = elegir_funcion();
    tuple<vector<tuple<float, float>>, float> best;
    auto start = high_resolution_clock::now(); 
    if (funcion_seleccionada == "A") best = fuerza_bruta(K, m1, m2, N, instance["x"], instance["y"]);
    else if (funcion_seleccionada == "B") best = backtracking(K, m1, m2, N, instance["x"], instance["y"]);
    else if (funcion_seleccionada == "C") best = dp(K-1, instance["x"], instance["y"], m1, m2);
    else cout << "Opción inválida.\n";

    auto end = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(end - start).count();
    cout << "Tiempo que tardó en ejecutarse: " << duration << "milisegundoss\n";
    
    ofstream output("solution_" + instance_name); 
    
    vector<float> x ={};
    vector<float> y ={};
    
    for (auto const& pair : get<0>(best)) {
         x.push_back(get<0>(pair));    
    }
    
    for (auto const& pair : get<0>(best)) {
        
        y.push_back(get<1>(pair));
    }
    
    instance["n"] = K;
    instance["x"] = x;
    instance["y"] = y;
    instance["obj"] = get<1>(best);
    
  

    output << instance;
    output.close();
    
    

    cout << "\nSolución:\n" << instance << "\n";

   

    return 0;
}