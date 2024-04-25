import numpy as np
from typing import *
from auxiliares import *
import numpy as np
from typing import *
from auxiliares import *

def dp_2(K, x, y, grid_x, grid_y, m1, m2):
   memo: List[List[List[float]]] = [[[BIG_NUMBER for _ in range(m2)] for _ in range(m1)] for _ in range(K+1)]

   for i in range(1, m1):
         for j in range(m2):
            min_error = BIG_NUMBER            
            for p in range(m2):
               min_error = min(min_error, error([(grid_x[0], grid_y[p]), (grid_x[i], grid_y[j])], x, y))
            memo[1][i][j] = min_error
            
   for k in range(2, K+1):
      for i in range(2, m1):
         for j in range(m2): 
            min_error = BIG_NUMBER
            for o in range(i):
               for p in range(m2):
                  current_error = error([(grid_x[o], grid_y[p]), (grid_x[i], grid_y[j])],x,y)+ memo[k-1][o][p]
                  if min_error > current_error:
                     min_error = current_error
            memo[k][i][j] = min_error
            
   return(memo)

def dp(K, x, y, m1, m2):
   
   grid_x = np.linspace(min(x), max(x), num=m1, endpoint=True)
   grid_y = np.linspace(min(y), max(y), num=m2, endpoint=True)
   memo = dp_2(K, x, y, grid_x, grid_y, m1, m2)
   res = []
   best = {}
   best['sol'] = []
   best['error'] = BIG_NUMBER
   
   minimo = BIG_NUMBER
   for j in range(m2):
      current_error = memo[K][m1-1][j]
      if minimo > current_error:
         minimo = current_error
         prev_y = j
   best['error'] = minimo
   res.append((m1-1, prev_y))
   
   for k in range (K-1, 0, -1): 
      min_x = None
      min_y = None
      minimo = BIG_NUMBER
      lim_x = res[0][0]
      lim_y = res[0][1]
      for i in range (lim_x-1, 0, -1):
         for j in range (m2): 
            current_error = memo[k][i][j] + error([(grid_x[i], grid_y[j]), (grid_x[lim_x], grid_y[lim_y])],x,y)
            if minimo > current_error:
               minimo = current_error
               min_y = j
               min_x = i
      res.insert(0,(min_x,min_y))

   minimo = BIG_NUMBER
   min_y = None
   for j in range(m2):
      current_error = error([(grid_x[0], grid_y[j]), (grid_x[res[0][0]], grid_y[res[0][1]])],x,y)
      if minimo > current_error:
         minimo = current_error
         min_y = j
   res.insert(0,(0,min_y))

   for tupla in res:
      best['sol'].append((grid_x[tupla[0]], grid_y[tupla[1]]))
   
   return best
