# include <cmath>
# include <iostream>

/*double secondDeriv(double x){
    return 12*x*x - 18*x + 6.74;
} 

double derivFunc(double x) { 
    return 4*x*x*x - 9*x*x + 6.74*x - 1.680;
}

double func(double x) { 
    return x*x*x*x - 3.0*x*x*x + 3.37*x*x - 1.680*x + 0.3136;
}

double secondDeriv(double x){
    return 30*x*x*x*x - 242*x*x*x + 714*x*x - 911.1*x + 425.325;
} 

double derivFunc(double x) { 
    return 6*x*x*x*x*x - 60.5*x*x*x*x + 238*x*x*x - 455.55*x*x + 425.325*x - 156.6;
}

double func(double x) { 
    return x*x*x*x*x*x - 12.1*x*x*x*x*x + 59.5*x*x*x*x - 151.85*x*x*x + 212.6625*x*x - 156.6*x + 48.5625;
}*/

double secondDeriv(double x){
    return 6*x + 3;
} 

double derivFunc(double x) { 
    return 3*x*x + 3*x - 5.75;
}

double func(double x) { 
    return x*x*x + 1.5*x*x - 5.75*x + 4.37;
}
  
//Newton's Method
void Newtons(double x) { 
    double h = func(x) / derivFunc(x);
    int n = 0;
    //assume max error will be at x
    double max = x;
    //limit number of tierations
    while (n < 100) {
        h = func(x)/derivFunc(x); 
   
        //x(i+1) = x(i) - f(x) / f'(x)
        x = x - h; 
        n++;
    } 
  
    std::cout << "The best approximation of the root is : " << x << " With value : " << func(x) << std::endl;
    std::cout << "Error is: " << (2*derivFunc(max))/secondDeriv(max) << std::endl;
}

int main() {
    double x = -3;
    Newtons(x);

    return 0; 
}