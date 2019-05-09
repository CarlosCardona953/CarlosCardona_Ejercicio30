
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation



fig, ax = plt.subplots(figsize=(5,5))
y = np.loadtxt("lax.dat")

xt=y.shape[1]
x = np.linspace(0, 1, xt)

line, = ax.plot(x, y[0])


def animate(i):
    k="{0:.2f}".format((2/xt)*(i+1))
    line.set_ydata(y[i])
    ax.set_title("Tiempo: " + str(k)+ " segundos")
    return line,



def init():
    
    ax.set_xlim(0, 1)
    ax.set_ylim(-0.5, 0.5)
    ax.set_xlabel("Posicion [metros]")
    ax.set_ylabel("U")
    plt.grid(True)
    
    return line,

ani = animation.FuncAnimation(fig, animate, init_func=init,
                              interval=100,frames=range(xt), blit=True)
ani.save("LAX.gif")    
