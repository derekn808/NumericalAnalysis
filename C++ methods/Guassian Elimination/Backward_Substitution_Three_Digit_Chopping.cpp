#include<stdio.h>
#include<math.h>
#include<iostream> 

#define N 3 //size of NxN+1 input matrix

//three digit chopping arithmetic function
double round(double x) {
   if(x>=10000)
      x = (int)(x/100)*100;
   else if(x<=-10000)
      x = (int)(x/-100)*-100;

   else if(x>=1000)
      x = (int)(x/10)*10;
   else if(x<=-1000)
      x = -(int)(x/-10)*-10;

   else if(x>=100)
      x = (int)(x/1)*1;
   else if(x<=-100)
      x = -(int)(x/-1)*-1;

   else if(x>=10)
      x = (int)(x/0.1)*0.1;
   else if(x<=-10)
      x = (int)(x/-0.1)*-0.1;

   else if(x>=1)
      x = (int)(x/.01)*.01;
   else if(x<=-1)
      x = (int)(x/-.01)*-.01;
   
   else if(x>=0)
      x = (int)(x/.001)*.001;
   else
      x = -(int)(x/-.001)*-.001;

   return x;
}

void print(double matrix[N][N+1]) 
{ 
   for (int i=0; i<N; i++, printf("\n")) {
      for (int j=0; j<=N; j++) {
         matrix[i][j] = round(matrix[i][j]);
         printf("%lf ", matrix[i][j]); 
      }
   }

   printf("\n"); 
} 

//Reduces matrix to echelon form
int rowReduction(double matrix[N][N+1]) 
{ 
   for (int k=0; k<N; k++) 
   {
      if (!matrix[k][k]) 
         return k;
      for (int i=k+1; i<N; i++) 
      {
         //value of m factor to get 0s
         double m = matrix[i][k]/matrix[k][k];
         m = round(m);

         //subtract m multiplied by kth row element
         for (int j=k+1; j<=N; j++) 
            matrix[i][j] -= matrix[k][j]*m; 

         //lower half fill with 0
         matrix[i][k] = 0;

         if(m != 0.0) {
            printf("Row %d - %lf * Row %d\n", i+1, m, k+1);
            print(matrix);
         }
      }
   }
   return -1; 
}

//Finds solutions to echelon form matrix (backward substitution)
void solve(double matrix[N][N+1]) 
{ 
   double solution[N];

   for (int i = N-1; i >= 0; i--) 
   { 
      //Solve from right side
      solution[i] = matrix[i][N]; 

      //Upper triangular solving
      for (int j=i+1; j<N; j++) 
      { 
         //subtract left values except for variable being solved for
         solution[i] -= matrix[i][j]*solution[j]; 
      } 

      solution[i] = solution[i]/matrix[i][i];
      solution[i] = round(solution[i]);
   } 

   printf("Solution is:\n"); 
   for(int i=0; i<N; i++) 
      printf("x%d = %lf\n", i+1, solution[i]); 
} 

void gaussianElimination(double matrix[N][N+1]) 
{
   int singular = rowReduction(matrix); 

   if (singular != -1) 
   { 
      printf("Matrix is singular\n"); 

      if (matrix[singular][N]) 
         printf("Matrix inconsistent\n"); 
      else
         printf("Infinite solutions\n"); 

      return; 
   } 

   solve(matrix); 
}

int main() 
{ 
   // input matrix
   double matrix[N][N+1] = {
                           {3.03, -12.1, 14, -119}, 
                           {-3.03, 12.1, -7, 120}, 
                           {6.11, -14.2, 21, -.139} 
                           }; 

   printf("Solving matrix: \n");
   print(matrix);
   gaussianElimination(matrix); 

   return 0; 
}

/*
                           {13.0, 17.0, 1.0, 5.0}, 
                           {0.0, 1.0, 19.0, 1.0}, 
                           {0.0, 12.0, -1.0, 0.0}

                           {1.0, 1.0, -1.0, 0.0}, 
                           {0.0, 12.0, -1.0, 4.0}, 
                           {2.0, 1.0, 1.0, 5.0} 

                           {5.0, 1.0, -6.0, 7.0}, 
                           {2.0, 1.0, -1.0, 8.0}, 
                           {6.0, 12.0, 1.0, 9.0} 

                           {1.0, -1.0, 1.0, 5.0}, 
                           {7.0, 5.0, -1.0, 8.0}, 
                           {2.0, 1.0, 1.0, 7.0}
                           
                           {3.03, -12.1, 14, -119}, 
                           {-3.03, 12.1, -7, 120}, 
                           {6.11, -14.2, 21, -.139} 

                           {58.9, .03, 59.2}, 
                           {-6.10, 5.31, 47.0}

                           {3.333, 15920, 10.333, 7953}, 
                           {2.222, 16.710, 9.6120, 0.965}, 
                           {-1.5611, 5.1792, -1.6855, 2.714} 
*/