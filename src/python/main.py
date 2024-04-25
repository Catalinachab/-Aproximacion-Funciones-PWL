import json
from typing import *
from fuerza_bruta import *
from backtracking import *
from dp import *
import time
from auxiliares import *
# (correr desde tp1-td5)

def tiempo_promedio(K:int, m:int, n:int, instancia: str, algoritmo:str)->float:
    filename = "../../data/" + instancia
    with open(filename) as f:
        instance = json.load(f)
    N = instance["n"] 
    i=0
    prom=0
    while i<4:
      if algoritmo == "fuerza_bruta":
         inicio = time.time()
         fuerza_bruta(K, m, n, N, instance['x'], instance['y'])
         fin = time.time()
      elif algoritmo== "backtracking":
         inicio = time.time()
         backtracking(K, m, n, N, instance['x'], instance['y'])
         fin = time.time()
      elif algoritmo=="dinamic_programming":
         inicio = time.time()
         dp(K-1, instance['x'], instance['y'], m, n)
         fin = time.time()
      
      prom+=(fin-inicio)*1000
      i+=1
    prom = prom/4 
    return prom 

def main():
   
    K = 5 # (poner siempre K= cantidad de breakpoints)
    m1 = 6
    m2 = 6
    print(tiempo_promedio(K, m1, m2, "titanium.json", "dinamic_programming")) 
   
    
    
if __name__ == "__main__":
	main()
