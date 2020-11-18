import plotly.graph_objects as go

# Create random data with numpy
import numpy as np
np.random.seed(1)

numeros = [
        100,1000,5000,10000,50000,100000,
        200000,400000,600000,800000,1000000,
        2000000,3000000,4000000]
real = [0.0000159740,0.0008831024,0.0234491825,
        0.1014730930,2.3810970783,9.3211660385,
        37.148332834,151.317466,356.5659,774.6189,
        1658.357457,7285.62698,13335.29,52020.1262
        ]
user = [0.000022,0.000887,0.023292,0.100945,
        2.366768,9.292152,36.972,150.82959,355.057034,
        765.516688,1483.2225,6142.249616,
        12183.666,25118.3596]
sys = [0,0,0,0,0.004,0.012,0.03598,0.111,0.21189,
        1.7673,6.1634,21.108,13.1447,99.8258
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
