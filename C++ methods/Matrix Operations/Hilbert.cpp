#include<stdio.h>
#include<math.h>
#include<iostream>

void Hilbert(int n) { 
    double H[n][n]; 
  
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < n; j++) { 
            H[i][j] = (double)1.0 /((i + 1) + (j + 1) - 1.0); 
        } 
    } 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++)  
            printf("%lf ", H[i][j]);
        printf("\n");
    } 
} 

int main() { 
    for(int i=2; i<7; i++) {
        printf("Hilbert for %d:\n", i);
        Hilbert(i);
        printf("\n");
    }
    return 0; 
} 