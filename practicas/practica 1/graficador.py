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
png_names100k = ("burbuja100k.png", "burbujaOpt100k.png", "insercion100k.png", "seleccion100k.png", "shell100k.png") #, "arbolbin100k.png"
colcir = ("ro", "bo", "go", "mo", "co", "ko")
collin = ("r", "b", "g", "m", "c", "k")
i=0

n_array = np.array([j for j in range(0, 10000000, 10000)])    #crea un arreglo valor n adaptado para la predicción

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
    #plt.plot(data["n"], data["sys"], "go", label="sys")     #se dibujan los datos "sys"
    #plt.plot(data["n"], data["CPU/Wall"], "mo", label="wall")  #se dibujan los datos "wall"
    plt.xlabel("n\n" + "f(n) = "+str(lm.coef_[1]) + "*n+"+str(lm.coef_[2])+"*n^2")                                         #nombramos el label x "n"
    plt.ylabel("tiempo (s)")                                #nombramos el label y "tiempo (s)"
    figure = plt.gcf()

    figure.set_size_inches(8, 6)
    plt.legend()                                            #se muestran las leyendas de colores
    plt.savefig(png_names[i], dpi=100)                               #se guarda la gráfica en archivo png
    plt.clf()                                               #se limpia el plot
    i += 1

i=0
for csvn in csv_names:                                      #se crean las gráficas que comparan los tiempos "real"
    data = pd.read_csv(csvn)

    n = data["n"].values.reshape((-1,1))
    fn = data["real"].values

    poly = PolynomialFeatures(degree=2)                 #regresión polinomial grado 2
    npoly = poly.fit_transform(n)                       #se transforman las n obtenidas de forma empírica
    narrpoly= poly.fit_transform(n_array[:,np.newaxis]) #se tranforman las n para la predicción
    lm = linear_model.LinearRegression()                #algoritmo de regresión lineal
    lm.fit(npoly, fn)                                   #se entrena el modelo con los valores empíricos
    fn_predic = lm.predict(narrpoly)                       #se obtiene la f(n)

    plt.plot(n_array, fn_predic, collin[i], label="pred "+names[i])   #se dibuja la predicción "real" en la gráfica

    plt.title("Comparativo: real")
    plt.plot(data["n"], data["real"], colcir[i], label=names[i])
    plt.xlabel("n\n")
    plt.ylabel("tiempo (s)")
    figure = plt.gcf()

    figure.set_size_inches(8, 6)
    plt.legend()
    plt.savefig("real.png", dpi=100)
    i+=1
plt.clf()

i=0
for csvn in csv_names:                                      #se crean las gráficas que comparan los tiempos "user"
    data = pd.read_csv(csvn)       

    n = data["n"].values.reshape((-1,1))
    fn = data["user"].values

    poly = PolynomialFeatures(degree=2)                 #regresión polinomial grado 2
    npoly = poly.fit_transform(n)                       #se transforman las n obtenidas de forma empírica
    narrpoly= poly.fit_transform(n_array[:,np.newaxis]) #se tranforman las n para la predicción
    lm = linear_model.LinearRegression()                #algoritmo de regresión lineal
    lm.fit(npoly, fn)                                   #se entrena el modelo con los valores empíricos
    fn_predic = lm.predict(narrpoly)                       #se obtiene la f(n)

    

    plt.plot(n_array, fn_predic, collin[i], label="pred "+names[i])   #se dibuja la predicción "real" en la gráfica 
    plt.title("Comparativo: user")
    plt.plot(data["n"], data["user"], colcir[i], label=names[i])
    plt.xlabel("n\n")
    plt.ylabel("tiempo (s)")
    figure = plt.gcf()

    figure.set_size_inches(8, 6)
    plt.legend()
    plt.savefig("user.png", dpi=100)
    i+=1
plt.clf()

i=0
n_array = np.array([j for j in range(0, 100000, 100)])  #################### ----- gráficas a partir de n <= 100 000

for csvn in csv_names:
    data = pd.read_csv(csvn).query('n <= 100000')
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
    
    plt.title(names[i] + " 100k")                                     #título de la gráfica
    plt.plot(data["n"], data["real"], "ro", label="real")   #se dibujan los datos "real"
    plt.plot(data["n"], data["user"], "bo", label="user")   #se dibujan los datos "user"
    #plt.plot(data["n"], data["sys"], "go", label="sys")     #se dibujan los datos "sys"
    #plt.plot(data["n"], data["CPU/Wall"], "mo", label="wall")  #se dibujan los datos "wall"
    plt.xlabel("n\n" + "f(n) = "+str(lm.coef_[1]) + "*n+"+str(lm.coef_[2])+"*n^2")                                         #nombramos el label x "n"
    plt.ylabel("tiempo (s)")                                #nombramos el label y "tiempo (s)"
    figure = plt.gcf()

    figure.set_size_inches(8, 6)
    plt.legend()                                            #se muestran las leyendas de colores
    plt.savefig(png_names100k[i], dpi=100)                               #se guarda la gráfica en archivo png
    plt.clf()                                               #se limpia el plot
    i += 1
    
i=0
for csvn in csv_names:                                      #se crean las gráficas que comparan los tiempos "real"
    data = pd.read_csv(csvn).query('n <= 100000')


    n = data["n"].values.reshape((-1,1))
    fn = data["real"].values

    poly = PolynomialFeatures(degree=2)                 #regresión polinomial grado 2
    npoly = poly.fit_transform(n)                       #se transforman las n obtenidas de forma empírica
    narrpoly= poly.fit_transform(n_array[:,np.newaxis]) #se tranforman las n para la predicción
    lm = linear_model.LinearRegression()                #algoritmo de regresión lineal
    lm.fit(npoly, fn)                                   #se entrena el modelo con los valores empíricos
    fn_predic = lm.predict(narrpoly)                       #se obtiene la f(n)

    plt.plot(n_array, fn_predic, collin[i], label="pred "+names[i])   #se dibuja la predicción "real" en la gráfica

    #plt.xlim(0,100000)
    plt.title("Comparativo: real")
    plt.plot(data["n"] , data["real"], colcir[i], label=names[i])
    plt.xlabel("n")
    plt.ylabel("tiempo (s)")
    figure = plt.gcf()

    figure.set_size_inches(8, 6)
    plt.legend()
    plt.savefig("real100k.png", dpi=100)
    i+=1
plt.clf()

i=0
for csvn in csv_names:                                      #se crean las gráficas que comparan los tiempos "user"
    data = pd.read_csv(csvn).query('n <= 100000')       

    n = data["n"].values.reshape((-1,1))
    fn = data["user"].values

    poly = PolynomialFeatures(degree=2)                 #regresión polinomial grado 2
    npoly = poly.fit_transform(n)                       #se transforman las n obtenidas de forma empírica
    narrpoly= poly.fit_transform(n_array[:,np.newaxis]) #se tranforman las n para la predicción
    lm = linear_model.LinearRegression()                #algoritmo de regresión lineal
    lm.fit(npoly, fn)                                   #se entrena el modelo con los valores empíricos
    fn_predic = lm.predict(narrpoly)                       #se obtiene la f(n)

    #plt.xlim(0,100000)
    plt.plot(n_array, fn_predic, collin[i], label="pred "+names[i])   #se dibuja la predicción "real" en la gráfica 
    plt.title("Comparativo: user")
    plt.plot(data["n"] , data["user"], colcir[i], label=names[i])
    plt.xlabel("n")
    plt.ylabel("tiempo (s)")
    figure = plt.gcf()
    figure.set_size_inches(8, 6)
    plt.legend()
    plt.savefig("user100k.png", dpi=100)
    i+=1
plt.clf()    
