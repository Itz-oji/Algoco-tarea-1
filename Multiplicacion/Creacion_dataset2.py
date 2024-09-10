import random
import os
def generar_matriz_desordenada(filas, columnas, nombre_archivo):
    # Crear una lista con números consecutivos
    numeros = list(range(1, filas * columnas + 1))
    
    # Desordenar los números
    random.shuffle(numeros)
    
    carpeta = "Multiplicacion"
    ruta_archivo = os.path.join(carpeta, nombre_archivo)
    with open(ruta_archivo, 'w') as archivo:
        index = 0
        for i in range(filas):
            for j in range(columnas):
                archivo.write(f"{numeros[index]} ")
                index += 1
            archivo.write("\n")
    
    print(f"Archivo '{nombre_archivo}' generado correctamente.")

# Solicitar el número de filas y columnas al usuario


filas = columnas = 2**1  # 1024x1024
filas1 = columnas1 = 2**2  # 2048x2048
filas2 = columnas2 = 2**6  # 64x64
filas3 = columnas3 = 2**7  # 128x128
filas4 = columnas4 = 2**4  # 16x16
filas5 = columnas5 = 2**5  # 32x32
filas6 = columnas6 = 2**4  # 512x512
filas7 = columnas7 = 2**3  # 1024x1024
filas8 = columnas8 = 2**6  # 256x256
filas9 = columnas9 = 2**5 


# Generar la matriz y guardarla en un archivo
generar_matriz_desordenada(filas, columnas, "matrizA.txt")
generar_matriz_desordenada(filas,columnas , "matrizB.txt")
generar_matriz_desordenada(filas1, columnas1, "matrizA1.txt")
generar_matriz_desordenada(filas1, columnas1, "matrizB1.txt")
generar_matriz_desordenada(filas2, columnas2, "matrizA2.txt")
generar_matriz_desordenada(filas2,columnas2 , "matrizB2.txt")
generar_matriz_desordenada(filas3, columnas3, "matrizA3.txt")
generar_matriz_desordenada(filas3,columnas3 , "matrizB3.txt")
generar_matriz_desordenada(filas4 ,columnas4 , "matrizA4.txt")
generar_matriz_desordenada(filas4, columnas4, "matrizB4.txt")
generar_matriz_desordenada(filas5, columnas5, "matrizA5.txt")
generar_matriz_desordenada(filas5, columnas5, "matrizB5.txt")
generar_matriz_desordenada(filas6, columnas6, "matrizA6.txt")
generar_matriz_desordenada(filas6, columnas6, "matrizB6.txt")
generar_matriz_desordenada(filas7,columnas7 , "matrizA7.txt")
generar_matriz_desordenada(filas7, columnas7, "matrizB7.txt")
generar_matriz_desordenada(filas8, columnas8, "matrizA8.txt")
generar_matriz_desordenada(filas8, columnas8 , "matrizB8.txt")
generar_matriz_desordenada(filas9, columnas9, "matrizA9.txt")
generar_matriz_desordenada(filas9, columnas9, "matrizB9.txt")