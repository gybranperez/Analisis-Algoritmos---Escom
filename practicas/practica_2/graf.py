import pandas as pd 
import matplotlib.pyplot as plt 
import math
import numpy as np

#   intalación de los paquetes necesarios
#   sudo apt install python3-pip            #solo si no tienes instalado pip3
#   sudo pip3 install pandas numpy
#   python3 -mpip install matplotlib
#   sudo pip3 install -U scikit-learn
#    ejecutar solo despues de haber generado los .csv
#
#----ejecución: python3 graficador.py
#

#def lineal_m():
#    return np.array([1/2.5e-9 for j in range(1,10_000_000, 100_000)])
#def lineal_p():
#    return np.array([j/2.5e-9 for j in range(1,10_000_000, 100_000)])

names = ("lineal", "binaria", "ABB", "exponencial", "fibonacci")
csv_names = ("lineal_p.csv", "bin_p.csv", "abb_p.csv", "exp_p.csv", "fibo_p.csv")
png_names = ("lineal_p.png", "bin_p.png", "abb_p.png", "exp_ppng", "fibo_p.png")

n_array = np.array([j for j in range(1, 10_000_000, 100_000)])    #crea un arreglo valor n adaptado para la predicción

i=0
for csv_n in csv_names:
    data = pd.read_csv(csv_n)
    data.sort_values(by=['n'])

    n = data["n"].values
    fn = data["promedio"].values

    plt.loglog(n, fn, "bo", label="promedio")            #se dibuja en un plot logarítmico

    p = np.polyfit(np.log(n),np.log(fn), 1)             #regresión polinomial con valores logaritmicos de n y fn
    z = np.polyval(p, np.log(n_array))                  #saca la función predictiva para 1 a 10 M
    plt.loglog(n_array, np.exp(z), "r", label="prediccion")   #se dibuja la predicción "real" en la gráfica
        
    plt.title("Búsqueda {}".format(names[i]))                                     #título de la gráfica
    #plt.plot(data["n"], data["promedio"], "ro", label="promedio")   #se dibujan los datos 
    plt.xlabel("n")                                         #nombramos el label x "n"
    plt.ylabel("tiempo (s)")                                #nombramos el label y "tiempo (s)"
    figure = plt.gcf()

    figure.set_size_inches(8, 6)
    plt.legend()                                            #se muestran las leyendas de colores
    plt.savefig(png_names[i], dpi=100)                               #se guarda la gráfica en archivo png
    plt.clf()     
    i += 1                                          #se limpia el plot

