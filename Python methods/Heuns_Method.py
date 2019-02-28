#Implementation of Heun's Method
import math

def y(t):
	return math.log((math.e**t) + math.e - 1)

def f(t, y):
	return math.e**(t-y)

#def y(t):
	#return math.sqrt((t**2) + (2*t) + 6) - 1

#def f(t, y):
	#return (1+t)/(1+y)

def heuns(a, b, h, result):
	for i in [float(j) / 2 for j in range(a, b, 1)]:
		result += (h/4) * (f(i*h, result) + (3 * f((i*h) +(2/3)*h, result + (2/3)*h*f((i*h)+(h/3), result + f(h*i, result)))))
	return result


result = heuns(0, 1, .5, 1)
actual = y(.5)
print("Result is: ", result)
print("Actual is: ", actual)