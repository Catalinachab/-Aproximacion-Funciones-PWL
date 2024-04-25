from typing import *



BIG_NUMBER = 1e10

def error(sol: List[Tuple], x, y) -> float:
   res = 0
   i = 0
   a = sol[len(sol)-2]
   b = sol[-1]
   m = (b[1]-a[1])/(b[0]-a[0])
   c = a[1]-(m*a[0]) 
   while i<len(x) and x[i]<=b[0]: 
      if x[i]>=a[0]:
         res += abs(y[i]-(m*x[i]+c))
      i+=1
   return res

