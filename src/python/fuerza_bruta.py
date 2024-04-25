import numpy as np
from typing import *
from auxiliares import *

def fuerza_bruta_2(K, N, grid_x, grid_y, x, y, best, current,i):
   #Precondicion: K >= 2
   
   if K==0 or i==len(grid_x):
      if current['error'] < best['error'] and K==0:
         best['error'] = current['error']
         best['sol'] = current['sol'].copy() 
   else:
      for j in grid_y: 
         if  i==0: 
               current['sol'].append((grid_x[0], j))
               fuerza_bruta_2(K-1, N,grid_x, grid_y, x, y, best, current,i+1)
               if current['sol']:  
                  current['sol'].pop()
         elif K==1 or i==len(grid_x)-1:
               current['sol'].append((max(x), j)) 
               e =  error(current['sol'], x, y)
               current['error'] += e
               fuerza_bruta_2(K-1, N, grid_x, grid_y, x, y, best, current, i+1)
               current['error'] -= e
               if current['sol']: 
                  current['sol'].pop()
         else:
               fuerza_bruta_2(K, N, grid_x, grid_y, x, y, best, current, i+1) 
               current['sol'].append((grid_x[i], j)) 
               e =  error(current['sol'], x, y)
               current['error'] += e
               fuerza_bruta_2(K-1, N, grid_x, grid_y, x, y, best, current, i+1)
               current['error'] -= e
               if current['sol']:
                  current['sol'].pop()

def fuerza_bruta(K, m1, m2, N, x, y):
   grid_x = np.linspace(min(x), max(x), num=m1, endpoint=True)
   grid_y = np.linspace(min(y), max(y), num=m2, endpoint=True)
   best = {}
   best['sol'] = []
   best['error'] = BIG_NUMBER
   current = {}
   current['sol'] = []
   current['error'] = 0
   i=0
   fuerza_bruta_2(K, N, grid_x, grid_y, x, y, best, current,i)

   return best