//Testing the bisection method for values of p from .1 to .3 with steps of .01
//For the equation of cos(x) -.8 + p x^2
# include <cmath>
# include <iostream>

double func(double x, double p){
    return cos(x) - .8 + (p*x*x);
}

//set a to negative value and b to positive
void bisection(double a, double b, double p) 
{ 
    double c = a;
    int n = 0;
    //Limit number of iterations
    while (n<=30) 
    { 
        //Midpoint Calculation
        c = (a+b)/2;
        //std::cout<< "Iteration: " << n <<" Midpoint: " << c << " Value: " << func(c,p) << std::endl;
        n++;
  
        // Check if mid is root
        if (func(c,p) == 0.0) 
            break; 
  
        // If a*c is negative then c is positive set b to c, else then c is negative or 0 set a to c
        else if (func(c, p)*func(a, p) < 0) 
            b = c; 
        else
            a = c; 
    } 
    std::cout << "The closest root for " << p <<" is: " << c << " with value of: " << func(c, p) << std::endl;; 
}

int main() {
    double a = -2, b = 0;
    for (double p = 0.1; p <.31; p += .01){
        //std::cout << "P = " << p << std::endl;
        bisection(a, b, p);
    }
    return 0; 
}