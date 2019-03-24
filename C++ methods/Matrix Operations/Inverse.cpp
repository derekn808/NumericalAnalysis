#include<stdio.h>
#include<math.h>
#include<iostream> 

#define N 6 //size of input matrix

double a[N][2*N];

double matrix[N][N] = {
{1.000000, 0.500000, 0.333333, 0.250000, 0.200000, 0.166667},
{0.000000, 0.083333, 0.088889, 0.083333, 0.076190, 0.069444},
{0.000000, 0.000000, 0.005953, 0.009921, 0.012245, 0.013528},
{0.000000, 0.000000, 0.000000, 0.000925, 0.001905, 0.002704},
{0.000000, 0.000000, 0.000000, 0.000000, 0.000019, 0.000050},
{0.000000, 0.000000, 0.000000, 0.000000, 0.000000, 0.000001}
}; 


void print(double matrix[N][2*N]) { 
   for (int i=0; i<N; i++, printf("\n")) 
      for (int j=0; j<N; j++) 
         printf("%lf ", matrix[i][j]); 

   printf("\n"); 
}

void printInverse() {
   for (int i=0; i<N; i++, printf("\n")) {
      printf("{");
      for (int j=N; j<2*N; j++) 
         printf("%lf ", a[i][j]);
      printf("}");
   }

   printf("\n"); 
}

void inverse() 
{
   double temp;
   for (int i = 0; i < N; i++) { 
      for (int j = 0; j < 2 * N; j++) { 
         if (j != i) { 
            temp = a[j][i] / a[i][i]; ;
            for (int k = 0; k < 2 * N; k++) {
               a[j][k] -= a[i][k] * temp;
            }
         }
      }
   }

   for (int i = 0; i < N; i++) { 
      temp = a[i][i]; 
      for (int j = 0; j < 2 * N; j++) { 
         a[i][j] = a[i][j] / temp;
      }
   }
}

int main() 
{
   for(int i =0; i<N; i++) {
      for(int j=0; j<N; j++)
         a[i][j] = matrix[i][j];
      for(int j=N; j<2*N; j++)
         a[i][j] = 0;
      a[i][i+N] = 1;
   }

   printf("Matrix: \n");
   print(a);
   inverse();
   printf("Inverse is: \n");
   printInverse();

   return 0; 
}