import plotly.graph_objects as go

# Create random data with numpy
import numpy as np
np.random.seed(1)

numeros = [
        100,1000,5000,10000,50000,100000,
        200000,400000,600000,800000,1000000,2000000]
real = [0.0000469685,0.0027458668,0.0772631168,0.3015670776,8.2441289425,
        36.0162460804,140.1718690395,548.5710499287,1332.2080180645,
        2403.2938318253,3959.3237750530,22405.9610691071]
user = [0.0000530000,0.0027510000,0.0771660000,0.3013730000,
        8.2414240000,35.7616470000,139.734110,548.0899780,1325.102308,
        2387.496367,3907.8908,19929.497955]
sys = [0,0,0,0,0.000488,0.015999,0.023992,0.104015,0.823577,
        7.556456,7.136743,40.095113]
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
