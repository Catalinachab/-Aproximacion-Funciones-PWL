#include <set>
#include <string>
#include <map>
#include <vector>
using namespace std;

// class Grilla{
//     vector<float> grid(vector<float> x);
// };
vector<float> grid(vector<float> x, int m);
float error(vector<tuple<float, float>> sol, vector<float> x, vector<float> y);
//tuple<vector<tuple<float, float>>, float> fuerza_bruta(int K, int m, int n, int N, vector<float> x, vector<float> y);
//void fuerza_bruta_2(int K, int N, vector<float> grid_x, vector<float> grid_y, vector<float> x, vector<float> y, vector<tuple<float, float>> best, vector<tuple<float, float>> current, float best_error, float current_error, int j);
void fuerza_bruta_2(int K, int N, vector<float> grid_x, vector<float> grid_y, vector<float> x, vector<float> y, vector<tuple<float, float>>& best, vector<tuple<float, float>> current, float& best_error, float current_error, int j);
tuple<vector<tuple<float, float>>, float> fuerza_bruta(int K, int m, int n, int N, vector<float> x, vector<float> y);
void backtracking_2(int K, int k_0, int N, vector<float> grid_x, vector<float> grid_y, vector<float> x, vector<float> y, vector<tuple<float, float>>& best, vector<tuple<float, float>> current, float& best_error, float current_error, int j);
tuple<vector<tuple<float, float>>, float> backtracking(int K, int m, int n, int N, vector<float> x, vector<float> y);
vector<vector<vector<float>>> dp_2(int K, vector<float> x, vector<float> y, vector<float> grid_x, vector<float> grid_y, int m1, int m2, vector<vector<vector<float>>> memo);
tuple<vector<tuple<float, float>>, float> dp(int K, vector<float> x, vector<float> y, int m1, int m2);
string elegir_funcion();
string elegir_archivo();