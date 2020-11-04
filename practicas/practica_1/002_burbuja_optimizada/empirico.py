import plotly.graph_objects as go

# Create random data with numpy
import numpy as np
np.random.seed(1)

numeros = [
        100,1000,5000,10000,50000,100000,
        200000,400000,600000,800000,1000000,2000000]
real = [0.0000498295,0.0041589737,0.1198511124,
        0.6726350784,14.1653201580,55.2328548431,
        245.3414561749,1527.5245831013,2354.0040469170
        ,3525.9426441193,26550.4987308979,27206.6378860474]
user = [0.0000550,0.004039,0.110924,0.484267,
        13.099037,53.0172,213.140367,876.02615,
        1954.463537,3471.599477,5434.591275,21427.76965]
sys = [0,0,0,0,0.012027,0.10555,0.498158,4.862449,
        4.115906,3.130041,6.44151,93.15668]
# Create traces
fig = go.Figure()
fig.add_trace(go.Scatter(x=numeros, y=real,
                    mode='lines+markers',
                    name='real'))
fig.add_trace(go.Scatter(x=numeros, y=user,
                    mode='lines+markers',
                    name='user'))
fig.add_trace(go.Scatter(x=numeros, y=sys,
                    mode='lines+markers', name='sys'))

fig.show()
