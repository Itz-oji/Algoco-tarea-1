import random
import os

i = 0
numeros = list(range(1, 3**8 + 1))  
random.shuffle(numeros)  

carpeta = "Ordenamiento"
ruta_archivo = os.path.join(carpeta, 'numeros.txt')
with open(ruta_archivo, 'w') as archivo:
    for numero in numeros:
        archivo.write(f'{numero}\n')

print("El archivo 'numeros.txt' ha sido creado con números desordenados.")

i += 1

numeros = list(range(1, 3**9 + 1))  
random.shuffle(numeros)  
texto = 'numeros' + str(i)
ruta_archivo = os.path.join(carpeta, f'{texto}.txt')
with open(ruta_archivo, 'w') as archivo:
    for numero in numeros:
        archivo.write(f'{numero}\n')

print(f"El archivo '{texto}.txt' ha sido creado con números desordenados.")

i += 1

numeros = list(range(1, 4**8 + 1))  
random.shuffle(numeros)  
texto = 'numeros' + str(i)
ruta_archivo = os.path.join(carpeta, f'{texto}.txt')
with open(ruta_archivo, 'w') as archivo:
    for numero in numeros:
        archivo.write(f'{numero}\n')

print(f"El archivo '{texto}.txt' ha sido creado con números desordenados.")

i += 1

numeros = list(range(1, 7**6 + 1))  
random.shuffle(numeros)  
texto = 'numeros' + str(i)
ruta_archivo = os.path.join(carpeta, f'{texto}.txt')
with open(ruta_archivo, 'w') as archivo:
    for numero in numeros:
        archivo.write(f'{numero}\n')

print(f"El archivo '{texto}.txt' ha sido creado con números desordenados.")

i += 1

numeros = list(range(1, 8**6 + 1))  
random.shuffle(numeros)  
texto = 'numeros' + str(i)
ruta_archivo = os.path.join(carpeta, f'{texto}.txt')
with open(ruta_archivo, 'w') as archivo:
    for numero in numeros:
        archivo.write(f'{numero}\n')

print(f"El archivo '{texto}.txt' ha sido creado con números desordenados.")

i += 1

numeros = list(range(1, 7**7 + 1))  
random.shuffle(numeros)  
texto = 'numeros' + str(i)
ruta_archivo = os.path.join(carpeta, f'{texto}.txt')
with open(ruta_archivo, 'w') as archivo:
    for numero in numeros:
        archivo.write(f'{numero}\n')

print(f"El archivo '{texto}.txt' ha sido creado con números desordenados.")

i += 1

numeros = list(range(1, 982**2 + 1))  
random.shuffle(numeros)  
texto = 'numeros' + str(i)
ruta_archivo = os.path.join(carpeta, f'{texto}.txt')
with open(ruta_archivo, 'w') as archivo:
    for numero in numeros:
        archivo.write(f'{numero}\n')

print(f"El archivo '{texto}.txt' ha sido creado con números desordenados.")

i += 1

numeros = list(range(1, 10**6 + 1))  
random.shuffle(numeros)  
texto = 'numeros' + str(i)
ruta_archivo = os.path.join(carpeta, f'{texto}.txt')
with open(ruta_archivo, 'w') as archivo:
    for numero in numeros:
        archivo.write(f'{numero}\n')

print(f"El archivo '{texto}.txt' ha sido creado con números desordenados.")

i += 1

numeros = list(range(1, 8**7 + 1))  
random.shuffle(numeros)  
texto = 'numeros' + str(i)
ruta_archivo = os.path.join(carpeta, f'{texto}.txt')
with open(ruta_archivo, 'w') as archivo:
    for numero in numeros:
        archivo.write(f'{numero}\n')

print(f"El archivo '{texto}.txt' ha sido creado con números desordenados.")

i += 1

numeros = list(range(1, 9**7 + 1))  
random.shuffle(numeros)  
texto = 'numeros' + str(i)
ruta_archivo = os.path.join(carpeta, f'{texto}.txt')
with open(ruta_archivo, 'w') as archivo:
    for numero in numeros:
        archivo.write(f'{numero}\n')

print(f"El archivo '{texto}.txt' ha sido creado con números desordenados.")
