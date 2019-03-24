#include<stdio.h>
#include<math.h>
#include<iostream>

#define N 4

double l[N][N];
double u[N][N];

void print(double matrix[N][N]) { 
   for (int i=0; i<N; i++, printf("\n"))
      for (int j=0; j<N; j++) 
         printf("%lf ", matrix[i][j]); 
   printf("\n"); 
}

int isDiagonal(double matrix[N][N]) {
   for(int i=0; i<N; i++) {
      if(matrix[i][i] == 0) {
         printf("Matrix is diagonal cannot be solved.\n");
         return 1;
      }
   }
   return 0;
}

void luDecomposition(double a[N][N]) {
   double sum;
   for(int i=0; i<N; i++) {
      l[i][i] = 1;
      for(int j=i; j<N; j++) {
         for(int k=0; k<i-1; k++) {
             sum += l[i][k] * u[k][j];
         }
         u[i][j] = a[i][j] - sum;
      }

      for(int j=i+1; j<N; j++) {
         sum = 0;
         for(int k=0; k<i-1; k++) {
            sum += l[j][k] * u[k][i];
         }
         l[j][i] = (a[j][i] - sum)/u[i][i];
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
   if(isDiagonal(matrix)){
      return 0;
   }

   luDecomposition(matrix);
   printf("L:\n");
   print(l);
   if(isDiagonal(l)){
      return 0;
   }
   printf("U:\n");
   print(u);
   if(isDiagonal(u)){
      return 0;
   }
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