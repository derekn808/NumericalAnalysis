# include <cmath>
# include <iostream>

/*double derivFunc(double x, double b) { 
    return ((b/(x*x))*cos(x)) + ((b/x)*sin(x)) + cos(x);
}
  
//Function whose root is being searched for
double func(double x, double b) { 
    return sin(x) - ((b/x)*cos(x));
}*/

double derivFunc(double x, double b) { 
    return (b/(x*x)) + (1/(cos(x)*cos(x)));
}

double func(double x, double b) { 
    return tan(x) - (b/x);
}
  
//Newton's Method
void Newtons(double x, double b) { 
    double h = func(x,b) / derivFunc(x,b);
    int n = 0;
    //limit number of tierations
    while (n < 30) {
        h = func(x, b)/derivFunc(x, b); 
   
        //x(i+1) = x(i) - f(x) / f'(x)
        x = x - h; 
        n++;
    } 
  
    std::cout << "For b = " << b <<" The best approximation of the root is : " << x << " With value : " << func(x,b) << std::endl; 
} 

int main() {
    double b = .001;
    double x = 1;
    Newtons(x, b);
    x = 3;
    Newtons(x, b);
    x = 6;
    Newtons(x, b);

    b = 1;
    x = 1;
    Newtons(x, b);
    x = 3;
    Newtons(x, b);
    x = 6;
    Newtons(x, b);

    b = 100;
    x = 1;
    Newtons(x, b);
    x = 3;
    Newtons(x, b);
    x = 6;
    Newtons(x, b);

    return 0; 
}