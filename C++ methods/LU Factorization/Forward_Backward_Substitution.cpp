#include<stdio.h>
#include<math.h>
#include<iostream> 

#define N 3 //size of input matrix
/*
double lowerTriangle[N][N+1] = {
                        {1, 0, 0, 1}, 
                        {-2, 1, 0, 0}, 
                        {3, 0, 1, -5} 
                        };
double upperTriangular[N][N] = {
                        {2, 1, -1}, 
                        {0, 4, 2}, 
                        {0, 0, 5} 
                        };
*/
double lowerTriangle[N][N+1] = {
                        {1, 0, 0, 4}, 
                        {2, 1, 0, 6}, 
                        {-3, 2, 1, 8} 
                        };
double upperTriangular[N][N] = {
                        {1, 2, -3}, 
                        {0, 1, 2}, 
                        {0, 0, 1} 
                        };

double forwardSub[N];

void print(double matrix[N][N+1]) 
{ 
   for (int i=0; i<N; i++, printf("\n")) 
      for (int j=0; j<=N; j++) 
         printf("%lf ", matrix[i][j]); 

   printf("\n"); 
}

void lowerSolve(double matrix[N][N+1]) 
{
   for (int i = 0; i < N; i++)
   { 
      forwardSub[i] = matrix[i][N]; 

      for (int j=0; j<i; j++) 
      { 
         forwardSub[i] -= matrix[i][j]*forwardSub[j]; 
      } 

      forwardSub[i] = forwardSub[i]/matrix[i][i]; 
   }

   printf("Solution is:\n"); 
   for(int i=0; i<N; i++) {
      printf("x%d = %lf\n", i+1, forwardSub[i]);
   } 
}

//Finds solutions to echelon form matrix (backward substitution)
void solve(double matrix[N][N+1]) 
{
   for (int i = N-1; i >= 0; i--)
   { 
      //Solve from right side
      forwardSub[i] = matrix[i][N]; 

      //Upper triangular solving
      for (int j=i+1; j<N; j++) 
      { 
         //subtract left values except for variable being solved for
         forwardSub[i] -= matrix[i][j]*forwardSub[j]; 
      } 

      forwardSub[i] = forwardSub[i]/matrix[i][i]; 
   }

   printf("Solution is:\n"); 
   for(int i=0; i<N; i++) {
      printf("x%d = %lf\n", i+1, forwardSub[i]);
   } 
}

int main() 
{
   printf("Solving matrix: \n");
   print(lowerTriangle);
   lowerSolve(lowerTriangle);
   double final[N][N+1];
   for(int i = 0; i<N; i++) {
      for(int j = 0; j<N; j++)
         final[i][j] = upperTriangular[i][j];
      final[i][N] = forwardSub[i];
   }

   printf("Solving matrix: \n");
   print(final);
   solve(final);

   return 0; 
}