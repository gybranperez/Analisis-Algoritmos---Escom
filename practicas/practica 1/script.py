import subprocess

numeros = [100,1000,5000,10_000,50_000,100_000,200_000, 400_000, 600_000]#, 7000_000, 8000_000, 9000_000, 10_000_000]
modos = (1, 2, 3, 4, 5)

subprocess.call(["make", "clear"])
subprocess.call("make")
with open("../numeros10millones") as myinp:
    for n in numeros:
        for m in modos:
            subprocess.call(["./main", str(n), str(m)], stdin=myinp)