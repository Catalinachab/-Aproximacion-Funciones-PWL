#include <iostream>
#include "pwl.h"
using namespace std;

void fuerza_bruta_2(int K, int N, vector<float> grid_x, vector<float> grid_y, vector<float> x, vector<float> y, vector<tuple<float, float>>& best, vector<tuple<float, float>> current, float& best_error, float current_error, int j){
   
    if(K==0 || j == grid_x.size()){
        
        if(current_error < best_error && K==0){
            best = current;
            best_error = current_error;
        }
        
    }else{
        for(int i=0; i < grid_y.size(); i++){
            if (j==0){
                current.push_back(make_tuple(grid_x[0], grid_y[i]));
                fuerza_bruta_2(K-1, N, grid_x, grid_y, x, y, best, current, best_error, current_error, j+1);
                if(current.size() > 0){
                    current.pop_back();
                }
               
            }else if (K==1 || j==grid_x.size()-1){
                current.push_back(make_tuple(grid_x[grid_x.size()-1], grid_y[i]));
                float e = error(current, x, y);
                current_error += e;
                fuerza_bruta_2(K-1, N, grid_x, grid_y, x, y, best, current, best_error, current_error, j+1);
                current_error -= e;
                if (current.size() > 0){
                    current.pop_back();
                }
                
            }else{
                fuerza_bruta_2(K, N, grid_x, grid_y, x, y, best, current, best_error, current_error, j+1);
                current.push_back(make_tuple(grid_x[j], grid_y[i]));
                float e = error(current, x, y);
                current_error += e;
                fuerza_bruta_2(K-1, N, grid_x, grid_y, x, y, best, current, best_error, current_error, j+1);
                current_error -= e;
                if (current.size() > 0){
                    current.pop_back();
                }
            }
        }
    }
}

tuple<vector<tuple<float, float>>, float> fuerza_bruta(int K, int m, int n, int N, vector<float> x, vector<float> y){
    
    vector<float> grid_x = grid(x, m);
    vector<float> grid_y = grid(y, n);
    vector<tuple<float, float>> best = {};
    vector<tuple<float, float>> current = {};
    float best_error = 1000000;
    float current_error = 0;
    
    fuerza_bruta_2(K, N, grid_x, grid_y, x, y, best, current, best_error, current_error, 0);
    
    return make_tuple(best, best_error); 
}