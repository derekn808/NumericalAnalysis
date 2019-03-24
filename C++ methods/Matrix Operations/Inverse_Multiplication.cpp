#include <iostream>
#include<stdio.h>
#include<math.h>
  
using namespace std; 
  
#define N 2

double lInverse[N][2*N];
double uInverse[N][2*N];

double l[N][N] = {
{1.000000, 0.000000},
{0.500000, 1.000000}
}; 
  
double u[N][N] = {
{1.000000, 0.500000},
{0.000000, 0.083333}
}; 

void print(double matrix[N][N]) {
   for (int i=0; i<N; i++, printf("\n"))
      for (int j=0; j<N; j++)
         printf("%lf ", matrix[i][j]);
}

void multiply(double mat1[][N], double mat2[][N], double res[][N]) { 
    int i, j, k; 
    for (i = 0; i < N; i++) 
    { 
        for (j = 0; j < N; j++) 
        { 
            res[i][j] = 0; 
            for (k = 0; k < N; k++) 
                res[i][j] += mat1[i][k] * mat2[k][j]; 
        } 
    } 
}

void inverse(double matrix[N][N], double a[N][2*N]) {
	for(int i = 0; i<N; i++) {
		for(int j=0; j<N; j++)
			a[i][j] = matrix[i][j];
		for(int j=N; j<2*N; j++)
			a[i][j] = 0;
		a[i][i+N] = 1;
	}
	for (int i = 0; i < N; i++) { 
        for (int j = 0; j < 2*N; j++) { 
            printf("%lf  ", a[i][j]); 
        } 
        printf("\n"); 
    }
	double temp;
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < 2 * N; j++) { 
            if (j != i) {
                temp = 0;
                if(j<N) {
                    temp = a[j][i] / a[i][i];
                }
                for (int k = 0; k < 2 * N; k++) {
                    if(j<N) {
                        a[j][k] -= a[i][k] * temp;
                        printf("%lf  ", a[j][k]); 
                    }
                } 
            } 
        } 
    }

    for (int i = 0; i < N; i++) {
        temp = a[i][i]; 
        for (int j = 0; j < 2 * N; j++) { 
  			if(j<N) {
            	a[i][j] = a[i][j] / temp;
            }
        } 
    }
}

int main() 
{
  printf("%d:\n", N);
  double res[N][N];
  inverse(l, lInverse);
  inverse(u, uInverse);

  for(int i=0; i<N; i++) {
  	for(int j=0; j<N; j++) {
  		l[i][j] = lInverse[i][j+N];
  		u[i][j] = uInverse[i][j+N];
  	}
  }
  
  printf("L inverse:\n");
  print(l);
  printf("U inverse:\n");
  print(u);

  multiply(l,u,res);
  printf("Result:\n");
  print(res);

  return 0; 
} 