#Implementation of Midpoint Method
import math

#def y(t):
	#return (.2*t*(math.e**(3*t)))-(.04*(math.e**(3*t)))+(.04*(math.e**(-2*t)))

#def f(t, y):
	#return (t * (math.e**(3*t))) - (2*y)

#def y(t):
	#return math.log((math.e**t) + math.e - 1)

#def f(t, y):
	#return math.e**(t-y)

def y(t):
	return math.sqrt((t**2) + (2*t) + 6) - 1

def f(t, y):
	return (1+t)/(1+y)

def midpoint(a, b):
	h = .5
	result = 2
	for i in [float(j) / 2 for j in range(a, b, 1)]:
		result += (h * f((i*h)+(h/2), result + ((h/2)*f((i*h), result))))
	return result


result = midpoint(1,2)
actual = y(1.5)
print("Result is: ", result)
print("Actual is: ", actual)