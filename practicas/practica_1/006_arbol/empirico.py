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
user = [0.000032,0.002127,
        0.0468,0.1935,4.713,
        18.915,74,291.64,
        650.98,1097.61,1658.08,
        7198.561,17126.03]
sys = [0,0,0,0.001909,0.00045,
        0.01648,0.0556,0.3264,
        1.1259,3.1794,3.4947,
        0.8198,17.2592,28.7459
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
