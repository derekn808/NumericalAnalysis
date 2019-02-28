#include<stdio.h>
#include<math.h>
#include<iostream>

#define N 4

double upper[N][N];
double lower[N][N];

void print(double matrix[N][N]) 
{ 
   for (int i=0; i<N; i++, printf("\n"))
      for (int j=0; j<N; j++) 
         printf("%lf ", matrix[i][j]); 
   printf("\n"); 
}

void luDecomposition(double matrix[N][N]) {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         if (j < i)
            lower[j][i] = 0;
         else {
            lower[j][i] = matrix[j][i];
            for (int k = 0; k < i; k++) {
               lower[j][i] = lower[j][i] - lower[j][k] * upper[k][i];
            }
         }
      }
      for (int j = 0; j < N; j++) {
         if (j < i)
            upper[i][j] = 0;
         else if (j == i)
            upper[i][j] = 1;
         else {
            upper[i][j] = matrix[i][j] / lower[i][i];
            for (int k = 0; k < i; k++) {
               upper[i][j] = upper[i][j] - ((lower[i][k] * upper[k][j]) / lower[i][i]);
            }
         }
      }
   }
}

int main()
{
   double matrix[N][N] = {
                        {2.121, -3.46, 0, 5.217},
                        {0, 5.193, -2.197, 4.206},
                        {5.132, 1.414, 3.141, 0},
                        {-3.111, -1.732, 2.718, 5.212}
                        };

   printf("Decomposing matrix:\n");
   print(matrix);

   luDecomposition(matrix);
   printf("Upper triangular matrix:\n");
   print(upper);
   printf("Lower triangular matrix:\n");
   print(lower);
   return 0; 
} 

/*
                        {1.0/3.0, 1.0/2.0, -1.0/4.0},
                        {1.0/5.0, 2.0/3.0, 3.0/8.0},
                        {2.0/5.0, -2.0/3.0, 5.0/8.0}

                        {2.121, -3.46, 0, 5.217},
                        {0, 5.193, -2.197, 4.206},
                        {5.132, 1.414, 3.141, 0},
                        {-3.111, -1.732, 2.718, 5.212}
*/