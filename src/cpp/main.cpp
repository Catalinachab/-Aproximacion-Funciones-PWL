
#include <variant>
#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <cmath>
#include "include/json.hpp"
#include "pwl.h"


// Para libreria de JSON.
using namespace nlohmann;
using namespace std;
using namespace chrono;



double tiempo_promedio(int K, int m, int n, std::string instancia, std::string algoritmo) {
    
    std::string instance_name = "../../data/" + instancia;
    std::cout << "Reading file " << instance_name << std::endl;
    std::ifstream input(instance_name);
    json instance;
    input >> instance;
    input.close();
    int N = instance["n"];
    int i = 0;
    double prom = 0.0;
    
    while (i < 4) {
        auto start=0.0;
        auto end=0.0;
        auto duration=0.0;
        if (algoritmo == "fuerza_bruta") {
            cout<<"entre"<<endl;
            auto start = high_resolution_clock::now();
            fuerza_bruta(K, m, n, N, instance["x"], instance["y"]);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            
            prom = prom + (double)duration;
        } else if (algoritmo == "backtracking") { 
            cout<<"entre"<<endl;
            auto start = high_resolution_clock::now();
            backtracking(K, m, n, N,  instance["x"], instance["y"]);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            prom = prom + (double)duration;
            
            
        } else if (algoritmo == "dinamic_programming") {
            auto start = high_resolution_clock::now();
            dp(K-1,  instance["x"], instance["y"], m, n);
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(end - start).count();
            prom = prom + (double)duration;
        }
        
        
        i++;
        
    }
    prom = prom / 4;
    
    return prom;
}


int main(int argc, char** argv) {

    int K = 5;
    int m = 7;
    int n = 7;
    
    cout<<tiempo_promedio(K, m, n, "optimistic_instance.json", "dinamic_programming")<< endl;
    
    
    return 0;
}