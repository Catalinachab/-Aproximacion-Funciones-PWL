#include "pwl.h"
#include <iostream>
#include <algorithm>
using namespace std;


vector<float> grid(vector<float> x, int m){
    // precondicion: x_i < x_j para todo i < j
    vector<float> res ={};
    float min = *min_element(x.begin(), x.end());
    float max = *max_element(x.begin(), x.end());
    float k = (max-min)/(m-1);
    
    for (int i = 0; i < m; i+=1){
        res.push_back(min+k*i);
            
    }
    return res;  
};

float error(vector<tuple<float, float>> sol, vector<float> x, vector<float> y){
    
    float res = 0;
    int i = 0;
    tuple<float, float> a = sol[sol.size()-2];
    tuple<float, float> b = sol[sol.size()-1];
   
    float m = ((get<1>(b)-get<1>(a))/(get<0>(b)-get<0>(a)));
    float c = get<1>(a) - m*get<0>(a);
    
    while (i<x.size() && x[i]<=get<0>(b)){
        
        if(x[i] >= get<0>(a)){
            res += abs(y[i] - (m*x[i] + c));
        }
        i+=1;
    }
    
    return res;
};