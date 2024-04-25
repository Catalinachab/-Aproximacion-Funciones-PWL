# Aproximación de datos vía funciones lineales continuas a trozos

## Introducción

Este proyecto se centra en el diseño de algoritmos para la aproximación de datos mediante funciones lineales continuas a trozos (PWL). La aproximación de datos mediante funciones continuas es una herramienta esencial en numerosas disciplinas, abarcando desde la ingeniería hasta la economía, permitiendo modelar eficazmente fenómenos complejos con diversos comportamientos. En este contexto, las funciones lineales continuas a trozos (PWL, por sus siglas en inglés) emergen como un instrumento útil. La naturaleza de muchos fenómenos complejos, cuyas funciones subyacentes son desconocidas, exige estrategias para aproximarlas de manera precisa.
En este trabajo, nos enfocaremos en el desarrollo de métodos para aproximar funciones desconocidas mediante funciones continuas PWL, minimizando el error de aproximación. Para ello, diseñaremos y evaluaremos diferentes algoritmos, implementándolos en Python y C++, y experimentando para analizar tanto la calidad como la performance de las aproximaciones obtenidas en diversas instancias.

## Preliminares y Definiciones

Consideramos una función desconocida \( g(t) \) definida en el intervalo \( [a, b] \) del cual conocemos \( n \) puntos \( (x_1, y_1), \ldots, (x_n, y_n) \). La aproximación mediante funciones PWL se basa en dividir el dominio en segmentos y aproximar los datos linealmente en cada segmento, manteniendo la continuidad en los puntos de unión.

### Error de Aproximación

El error absoluto de aproximación \( e(x_i, y_i) \) de un punto \( (x_i, y_i) \) por una función PWL \( y(t) \) está dado por:

\[
e(x_i, y_i) = |y_i - y(x_i)|
\]

### Función PWL

Una función \( f(t) \) es continua y PWL si está compuesta por \( K \) segmentos lineales \( f_k(t) \) donde \( a = r_1 < r_2 < \ldots < r_K = b \) son los breakpoints. Las funciones \( f_k(t) \) son lineales dentro de cada segmento \( [r_k, r_{k+1}] \) y coinciden en los puntos de unión.

### Error de Aproximación de una Pieza

El error de aproximación de una pieza \( f_k(t) \) definida por los breakpoints \( (r_k, z_k) \) y \( (r_{k+1}, z_{k+1}) \) está dado por:

\[
D((r_k, z_k), (r_{k+1}, z_{k+1})) = ∑_{i=1}^{n} |y_i - f_k(x_i)|


\]

## Datos y Resolución del Problema

1. **Fuerza Bruta**: Implementaremos un algoritmo de fuerza bruta para la aproximación de datos utilizando funciones lineales continuas a trozos.

2. **Backtracking con Podas**: Partiendo del algoritmo de fuerza bruta, desarrollaremos un algoritmo de backtracking que incluya podas por factibilidad y optimalidad para mejorar la eficiencia en la aproximación de datos.

3. **Programación Dinámica**: Implementaremos un algoritmo basado en programación dinámica, inspirado en el trabajo de Bellman y Roth (1969), para encontrar la mejor aproximación de datos utilizando funciones lineales continuas a trozos.

## Experimentación y Evaluación

Realizaremos una evaluación experimental exhaustiva utilizando distintos conjuntos de datos proporcionados. Analizaremos cómo la granularidad de la discretización y la cantidad de piezas seleccionadas afectan la calidad de las aproximaciones. También evaluaremos la performance de los algoritmos en función de los parámetros de las instancias y discutiremos la elección del lenguaje de programación y la implementación.

