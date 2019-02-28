#Implementation of 4th order Runge-Kutta Method
import math

#def y(t):
    #return math.log((math.e**t) + math.e - 1)

#def f(t, y):
    #return math.e**(t-y)

def y(t):
    return math.sqrt((t**2) + (2*t) + 6) - 1

def f(t, y):
    return (1+t)/(1+y)

def Runge_Kutta(a, b, h, result):
    for i in [float(j) / 4 for j in range(a, b, 1)]:
        k1 = h * f(h*i, result)
        k2 = h * f((h*i) + (h/2), result + ((1/2)*k1))
        k3 = h * f((h*i) + (h/2), result + ((1/2)*k2))
        k4 = h * f(h*(i+1), result + k3)
        result += (1/6) * (k1 + (2*k2) + (2*k3) + k4)
    return result


result = Runge_Kutta(1, 2, .25, 2)
actual = y(1.5)
print("Result is: ", result)
print("Actual is: ", actual)