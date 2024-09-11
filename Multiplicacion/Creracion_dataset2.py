import random
import os
def generar_matriz_desordenada(filas, columnas, nombre_archivo):
    # Crear una lista con números consecutivos
    numeros = list(range(1, filas * columnas + 1))
    
    # Desordenar los números
    random.shuffle(numeros)
    
    with open(nombre_archivo, 'w') as archivo:
        index = 0
        for i in range(filas):
            for j in range(columnas):
                archivo.write(f"{numeros[index]} ")
                index += 1
            archivo.write("\n")
    
    print(f"Archivo '{nombre_archivo}' generado correctamente.")

# Solicitar el número de filas y columnas al usuario
filas = int(2**10)
columnas = int(2**10)
filas1 = int(2**11)
columnas1 = int(2**11)
filas2 = int(2**6)
columnas2 = int(2**8)
filas3 = int(3**4)
columnas3 = int(8**3)
filas4 = int(10**3)
columnas4 = int(2**4)
filas5 = int(5**3)
columnas5 = int(3**4)
filas6 = int(9**3)
columnas6 = int(7**2)
filas7 = int(6**4)
columnas7= int(4**6)
filas8 = int(5**5)
columnas8 = int(2**5)
filas9 = int(3**5)
columnas9 = int(7**4)

# Generar la matriz y guardarla en un archivo
generar_matriz_desordenada(filas, columnas, "matrizA.txt")
generar_matriz_desordenada(columnas,filas , "matrizB.txt")
generar_matriz_desordenada(filas1, columnas1, "matrizA1.txt")
generar_matriz_desordenada(filas1, filas6, "matrizB1.txt")
generar_matriz_desordenada(filas2, columnas2, "matrizA2.txt")
generar_matriz_desordenada(columnas2,columnas1 , "matrizB2.txt")
generar_matriz_desordenada(filas3, columnas3, "matrizA3.txt")
generar_matriz_desordenada(columnas3,filas3 , "matrizB3.txt")
generar_matriz_desordenada(columnas7 ,filas4 , "matrizA4.txt")
generar_matriz_desordenada(filas4, columnas4, "matrizB4.txt")
generar_matriz_desordenada(columnas6, filas7, "matrizA5.txt")
generar_matriz_desordenada(filas7, columnas5, "matrizB5.txt")
generar_matriz_desordenada(filas6, filas5, "matrizA6.txt")
generar_matriz_desordenada(filas5, columnas9, "matrizB6.txt")
generar_matriz_desordenada(columnas7,filas2 , "matrizA7.txt")
generar_matriz_desordenada(filas2, columnas4, "matrizB7.txt")
generar_matriz_desordenada(filas8, columnas8, "matrizA8.txt")
generar_matriz_desordenada(columnas8, filas8 , "matrizB8.txt")
generar_matriz_desordenada(filas, columnas9, "matrizA9.txt")
generar_matriz_desordenada(columnas9, columnas6, "matrizB9.txt")