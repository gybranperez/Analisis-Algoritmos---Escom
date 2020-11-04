import plotly.graph_objects as go

# Create random data with numpy
import numpy as np
np.random.seed(1)

numeros = [
        100,1000,5000,10000,50000,100000,
        200000,400000,600000,800000,1000000,
        2000000,3000000]
real = [0.0000269413,0.0055449009,0.0583109856,
        0.2252438068,5.223597,21.5511469,85.208667,
        325.3906,739.3778,1197.7238,1668.376,
        8267.6752,39963.2199
        ]
user = [0.000032,0.002127]
sys = [0,0,0,0,
        ]
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
