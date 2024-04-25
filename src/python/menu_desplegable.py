import json
from typing import *
from fuerza_bruta import *
from backtracking import *
from dp import *

def elegir_funcion() -> str:
   '''
   Despliega el menú de funciones disponibles en la pantalla y devuelve
   la opción elegida por el usuario
   '''
   print()
   print('Funciones disponibles')
   print('---------------------')
   print('A. Fuerza Bruta')
   print('B. Backtracking')
   print('C. Programación Dinámica')
   opción_elegida:str = input('Seleccione una opción: ').upper().strip()
   return opción_elegida

def elegir_archivo() -> str:
   '''
   Despliega el menú de archivos json disponibles como instancias en la pantalla y devuelve
   la opción elegida por el usuario
   '''
   print()
   print('Instancias disponibles')
   print('---------------------')
   print('A. titanium.json')
   print('B. aspen_simulation.json')
   print('C. ethanol_water_vle.json')
   print('D. toy_instance.json')
   print('E. optimistic_instance.json')
   opción_elegida:str = input('Seleccione una opción: ').upper().strip()
   return opción_elegida

################################
# Cuerpo principal del programa

archivo_seleccionado: str = elegir_archivo()
if archivo_seleccionado == 'A':
   instance_name: str = 'titanium.json'
elif archivo_seleccionado == 'B':
   instance_name: str = 'aspen_simulation.json'
elif archivo_seleccionado == 'C':
   instance_name: str = 'ethanol_water_vle.json'
elif archivo_seleccionado == 'D':
   instance_name: str = 'toy_instance.json'
elif archivo_seleccionado == 'E':
   instance_name: str = 'optimistic_instance.json'
else:
   print('Opción inválida.')
   
# filename = "../../data/" + instance_name
filename = "data/" + instance_name
with open(filename) as f:
   instance = json.load(f)
   
K:int = int(input('Ingrese K (cantidad de breakpoints): '))
m1:int = int(input('Ingrese m1 (discretización del eje x): '))
m2:int = int(input('Ingrese m2 (discretización del eje y): '))
N:int = instance["n"] # cantidad de puntos de la instancia

funcion_seleccionada:str = elegir_funcion()
if funcion_seleccionada == 'A':
   best = fuerza_bruta(K, m1, m2, N, instance['x'], instance['y'])
elif funcion_seleccionada == 'B':
   best = backtracking(K, m1, m2, N, instance['x'], instance['y'])
elif funcion_seleccionada == 'C':
   best = dp(K-1, instance['x'], instance['y'], m1, m2)
else:
   print('Opción inválida.')

solution = {}
solution['n'] = len(best['sol'])
solution['x'] = [x[0] for x in best['sol']]
solution['y'] = [x[1] for x in best['sol']]
solution['obj'] = best['error']

print()
print('Solution:')
print(solution)
print()

with open('./solutions/solution_' + instance_name, 'w') as f:
   json.dump(solution, f)
