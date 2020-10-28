import pandas as pd 
import matplotlib.pyplot as plt 
import math
from sklearn.preprocessing import PolynomialFeatures
from sklearn import linear_model
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

names = ("burbuja", "Burbuja Optimizada", "Insercion", "Seleccion", "Shell") #, "arbolbin.csv"
csv_names = ("burbuja.csv", "burbujaOpt.csv", "insercion.csv", "seleccion.csv", "shell.csv") #, "arbolbin.csv"
png_names = ("burbuja.png", "burbujaOpt.png", "insercion.png", "seleccion.png", "shell.png") #, "arbolbin.png"
colcir = ("ro", "bo", "go", "mo", "co", "ko")
collin = ("r", "b", "g", "m", "c", "k")
i=0

n_array = np.array([j for j in range(0, 1000000, 1000)])    #crea un arreglo valor n adaptado para la predicción

for csvn in csv_names:
    data = pd.read_csv(csvn)
    data.sort_values(by=['n'])

    n = data["n"].values.reshape((-1,1))
    fn = data["real"].values

    poly = PolynomialFeatures(degree=2)                 #regresión polinomial grado 2
    npoly = poly.fit_transform(n)                       #se transforman las n obtenidas de forma empírica
    narrpoly= poly.fit_transform(n_array[:,np.newaxis]) #se tranforman las n para la predicción
    lm = linear_model.LinearRegression()                #algoritmo de regresión lineal
    lm.fit(npoly, fn)                                   #se entrena el modelo con los valores empíricos
    fn_predic = lm.predict(narrpoly)                       #se obtiene la f(n)

    plt.plot(n_array, fn_predic, "y", label="prediccion")   #se dibuja la predicción "real" en la gráfica
    
    plt.title(names[i])                                     #título de la gráfica
    plt.plot(data["n"], data["real"], "ro", label="real")   #se dibujan los datos "real"
    plt.plot(data["n"], data["user"], "bo", label="user")   #se dibujan los datos "user"
    plt.plot(data["n"], data["sys"], "go", label="sys")     #se dibujan los datos "sys"
    #plt.plot(data["n"], data["CPU/Wall"], "mo", label="wall")  #se dibujan los datos "wall"
    plt.xlabel("n")                                         #nombramos el label x "n"
    plt.ylabel("tiempo (s)")                                #nombramos el label y "tiempo (s)"
    plt.legend()                                            #se muestran las leyendas de colores
    plt.savefig(png_names[i])                               #se guarda la gráfica en archivo png
    plt.clf()                                               #se limpia el plot
    i += 1

i=0
for csvn in csv_names:                                      #se crean las gráficas que comparan los tiempos "real"
    data = pd.read_csv(csvn)
    plt.title("Comparativo: real")
    plt.plot(data["n"], data["real"], collin[i], label=names[i])
    plt.xlabel("n")
    plt.ylabel("tiempo (s)")
    plt.legend()
    plt.savefig("real.png")
    i+=1
plt.clf()

i=0
for csvn in csv_names:                                      #se crean las gráficas que comparan los tiempos "user"
    data = pd.read_csv(csvn)        
    plt.title("Comparativo: user")
    plt.plot(data["n"], data["user"], collin[i], label=names[i])
    plt.xlabel("n")
    plt.ylabel("tiempo (s)")
    plt.legend()
    plt.savefig("user.png")
    i+=1
plt.clf()