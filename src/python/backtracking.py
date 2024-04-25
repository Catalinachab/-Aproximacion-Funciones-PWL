import numpy as np
from typing import *
from auxiliares import *

def backtracking_2(K, N, grid_x, grid_y, x, y, best, current, i, k_0):
    # Precondicion: K >= 2 & K <= len(grid_x)
    if K==0 or i==len(grid_x):
        if current['error'] < best['error']:
            best['error'] = current['error']
            best['sol'] = current['sol'].copy() 
    else:
        for j in grid_y:
            if  i==0: 
                current['sol'].append((grid_x[0], j))
                backtracking_2(K-1, N,grid_x, grid_y, x, y, best, current, i+1, k_0)
                if current['sol']:  
                    current['sol'].pop()
            elif K==1 or i==len(grid_x)-1: 
                current['sol'].append((max(x), j)) 
                e =  error(current['sol'], x, y)
                current['error'] += e
                backtracking_2(K-1, N, grid_x, grid_y, x, y, best, current, i+1, k_0)
                current['error'] -= e
                if current['sol']: 
                    current['sol'].pop()
            elif current['error'] < best['error'] and len(grid_x[i:]) >= k_0-len(current['sol']):
                if grid_x[i+1] != max(grid_x):
                    backtracking_2(K, N, grid_x, grid_y, x, y, best, current, i+1, k_0)
                current['sol'].append((grid_x[i], j)) 
                e =  error(current['sol'], x, y)
                current['error'] += e
                backtracking_2(K-1, N, grid_x, grid_y, x, y, best, current, i+1, k_0)
                current['error'] -= e
                if current['sol']:
                    current['sol'].pop()

def backtracking(K, m1, m2, N, x, y):
    grid_x = np.linspace(min(x), max(x), num=m1, endpoint=True)
    grid_y = np.linspace(min(y), max(y), num=m2, endpoint=True)
    best = {}
    best['sol'] = []
    best['error'] = BIG_NUMBER
    current = {}
    current['sol'] = []
    current['error'] = 0
    i=0
    k_0 = K
    backtracking_2(K, N, grid_x, grid_y, x, y, best, current,i, k_0)

    return best