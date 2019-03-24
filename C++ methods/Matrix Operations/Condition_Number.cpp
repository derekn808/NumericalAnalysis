#include<stdio.h>
#include<math.h>
#include<iostream> 

#define N 1000

double a[N][2*N];
double matrix[N][N];
double inverseMat[N][N];

void print(double matrix[N][N]) { 
   for (int i=0; i<N; i++, printf("\n")) 
      for (int j=0; j<N; j++) 
         printf("%lf ", matrix[i][j]); 
}

double norm(double mat[N][N]) {
   double max = 0;
   double temp;
   for (int i = 0; i < N; i++) {
      temp = 0;
      for (int j = 0; j < N; j++) { 
         temp += fabs(mat[i][j]);
      }
      if(temp > max)
         max = temp;
   }
   //printf("Norm: %lf\n", max);
   return max;
}

void inverse()  {
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

   for (int i=0; i<N; i++) {
      for (int j=0; j<N; j++) 
         inverseMat[i][j] = a[i][j+N];
   }
}

int main() 
{
   printf("%d:\n", N);
   for(int i =0; i<N; i++) {
      for(int j=0; j<N; j++){
         if(j>i)
            matrix[i][j]=0;
         else{
            if((rand() % 100 + 1)<50)
               matrix[i][j]=1;
            else
               matrix[i][j]=-1;
         }
      }
      matrix[i][i]=1;
   }
   //print(matrix);
   double matNorm = norm(matrix);

   for(int i =0; i<N; i++) {
      for(int j=0; j<N; j++)
         a[i][j] = matrix[i][j];
      for(int j=N; j<2*N; j++)
         a[i][j] = 0;
      a[i][i+N] = 1;
   }

   inverse();
   //printf("Inverse is: \n");
   //print(inverseMat);
   double invNorm = norm(inverseMat);
   double cond = matNorm * invNorm;

   printf("Condition number: %lf\n", cond);

   return 0; 
}