#include<stdio.h>
#include<math.h>
#include<iostream>

#define N 3

double u[N][N];
double l[N][N];
double solution[N] = {1, 2, -3};

void print(double matrix[N][N]) 
{ 
   for (int i=0; i<N; i++, printf("\n"))
      for (int j=0; j<N; j++) 
         printf("%lf ", matrix[i][j]); 
   printf("\n"); 
}

void printFull(double matrix[N][N+1]) 
{ 
   for (int i=0; i<N; i++, printf("\n"))
      for (int j=0; j<=N; j++) 
         printf("%lf ", matrix[i][j]); 
   printf("\n"); 
}

void luDecomposition(double a[N][N]) {
   double sum;
    for(int i=0;i<N;i++) {
      l[i][i]=1;

      for(int j=i;j<N;j++) {
         for(int s=0;s<i-1;s++) {
             sum+= l[i][s]*u[s][j];
         }
         u[i][j]=a[i][j]-sum;
      }

      for(int k=i+1;k<N;k++) {
         double sum=0;
         for(int s=0;s<i-1;s++) {
            sum+=l[k][s]*u[s][i];
         }
         l[k][i]=(a[k][i]-sum)/u[i][i];
      }
   }
}

void lowerSolve(double finalLower[N][N+1]) 
{
   for (int i = 0; i < N; i++)
   { 
      solution[i] = finalLower[i][N]; 
      for (int j=0; j<i; j++) 
      { 
         solution[i] -= finalLower[i][j]*solution[j]; 
      } 

      solution[i] = solution[i]/finalLower[i][i]; 
   }

   printf("Solution is:\n"); 
   for(int i=0; i<N; i++) {
      printf("x%d = %lf\n", i+1, solution[i]);
   } 
}

//Finds solutions to echelon form matrix (backward substitution)
void upperSolve(double finalUpper[N][N+1]) 
{
   for (int i = N-1; i >= 0; i--)
   { 
      //Solve from right side
      solution[i] = finalUpper[i][N]; 

      //Upper triangular solving
      for (int j=i+1; j<N; j++) 
      { 
         //subtract left values except for variable being solved for
         solution[i] -= finalUpper[i][j]*solution[j]; 
      } 

      solution[i] = solution[i]/finalUpper[i][i]; 
   }

   printf("Solution is:\n"); 
   for(int i=0; i<N; i++) {
      printf("x%d = %lf\n", i+1, solution[i]);
   } 
}

void forwardSubstitution(double matrix[N][N], double final[N][N+1]) {
   for(int i = 0; i<N; i++) {
      for(int j = 0; j<N; j++)
         final[i][j] = matrix[i][j];
      final[i][N] = solution[i];
   }
}

int main()
{
   double matrix[N][N] = {
                        {1.0/3.0, 1.0/2.0, -1.0/4.0},
                        {1.0/5.0, 2.0/3.0, 3.0/8.0},
                        {2.0/5.0, -2.0/3.0, 5.0/8.0}
                        };

   double finalLower[N][N+1];
   double finalUpper[N][N+1];

   printf("Decomposing matrix:\n");
   print(matrix);
   luDecomposition(matrix);
   printf("L:\n");
   print(l);
   printf("U:\n");
   print(u);


   forwardSubstitution(l, finalLower);
   printf("Solving:\n");
   printFull(finalLower);
   lowerSolve(finalLower);
   forwardSubstitution(u, finalUpper);
   printf("Solving:\n");
   printFull(finalUpper);
   upperSolve(finalUpper);

   return 0; 
} 

/*
double solution[N] = {1.909, 0, -2.101, 6.824};

                        {1.0/3.0, 1.0/2.0, -1.0/4.0},
                        {1.0/5.0, 2.0/3.0, 3.0/8.0},
                        {2.0/5.0, -2.0/3.0, 5.0/8.0}

                        {2.121, -3.46, 0, 5.217},
                        {0, 5.193, -2.197, 4.206},
                        {5.132, 1.414, 3.141, 0},
                        {-3.111, -1.732, 2.718, 5.212}
*/