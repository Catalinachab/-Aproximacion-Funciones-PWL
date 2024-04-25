#include <iostream>
#include <algorithm>
#include "pwl.h"
using namespace std;
const float BIG_NUMBER = 1000000.0;
vector<vector<vector<float>>>  dp_2(int K, vector<float> x, vector<float> y, vector<float> grid_x, vector<float> grid_y, int m1, int m2, vector<vector<vector<float>>> memo){
    memo.assign(K + 1, vector<vector<float>>(m1, vector<float>(m2, BIG_NUMBER)));

    for(int i=1; i<m1;i++){
        for(int j=0 ; j<m2 ;j++){
            float min_error= BIG_NUMBER;
            for(int p =0; p<m2; p++){
                min_error= min(min_error, error({make_tuple(grid_x[0], grid_y[p]), make_tuple(grid_x[i], grid_y[j])}, x, y));
            }
            memo[1][i][j] = min_error;
        }
    }
    for(int k=2; k<K+1; k++){
       for(int i=2; i<m1;i++){
        for(int j=0; j<m2;j++){
            float min_error = BIG_NUMBER;
            for(int o=0; o<i;o++){
                for(int p=0; p<m2;p++){
                    float current_error = error({make_tuple(grid_x[o], grid_y[p]), make_tuple(grid_x[i], grid_y[j])},x,y)+ memo[k-1][o][p];
                    if (min_error>current_error){
                        min_error=current_error;
                    }
                }
            }
            memo[k][i][j]= min_error;
        }
       } 
    }

        
    
    return memo;
}

tuple<vector<tuple<float, float>>, float> dp(int K, vector<float> x, vector<float> y, int m1, int m2){
    
    vector<float> grid_x = grid(x, m1);
    vector<float> grid_y = grid(y, m2);
    vector<vector<vector<float>>> memo;
    memo = dp_2(K, x, y, grid_x, grid_y, m1, m2, memo);
    vector<tuple<int,int>> res={};
    float best_error;
    vector<tuple<float,float>> best_sol={};
    float minimo=BIG_NUMBER;
    int prev_y;
    for(int j=0; j<m2;j++){
        float current_error = memo[K][m1-1][j];
        if (minimo>current_error){
            minimo =current_error;
            prev_y=j;
        }
    }
    best_error = minimo;
    res.push_back(make_tuple(m1-1, prev_y));
    for(int k=K-1; k>0;k--){
        int min_x;
        int min_y;
        minimo = BIG_NUMBER;
        int lim_x = get<0>(res[0]);
        int lim_y = get<1>(res[0]);
        for (int i = lim_x - 1; i > 0; i--){
            for(int j=0;j<m2;j++){
                float current_error = memo[k][i][j] + error({make_tuple(grid_x[i], grid_y[j]), make_tuple(grid_x[lim_x], grid_y[lim_y])},x,y);
                if (minimo>current_error){
                    minimo =current_error;
                    min_y=j;
                    min_x=i;
                }    
            }
            
        }

        res.insert(res.begin(), make_tuple(min_x, min_y));

    }

    minimo = BIG_NUMBER;
    int min_y;
    for(int j=0;j<m2;j++){
        float current_error = error({make_tuple(grid_x[0], grid_y[j]), 
        make_tuple(grid_x[get<0>(res[0])], grid_y[get<1>(res[0])])},x,y);
        if (minimo>current_error){
            minimo =current_error;
            min_y=j;
        }
    }
    res.insert(res.begin(), make_tuple(0, min_y));

    for(int i =0; i <res.size();i++){
        
        best_sol.push_back(make_tuple(grid_x[get<0>(res[i])], grid_y[get<1>(res[i])]));
    }
    return make_tuple(best_sol, best_error);
            
}