import subprocess

#Ejecución $python3 script.py

numeros = [100,1000,5000,10_000,50_000,100_000,200_000, 400_000, 600_000]#, 7000_000, 8000_000, 9000_000, 10_000_000]
modos = (1, 2, 3, 4, 5) #,6)    1. burbuja 2. burbuja opt 3. insercion 4. seleccion 5. shell 6. arbol

subprocess.call(["make", "clear"])
subprocess.call("make")
with open("../numeros10millones") as myinp:
    for n in numeros:
        for m in modos:
            subprocess.call(["./main", str(n), str(m)], stdin=myinp)    #Ejecuta ./main n m < numeros10millones