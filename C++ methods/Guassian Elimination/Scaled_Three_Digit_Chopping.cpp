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

void rowSwap(double matrix[N][N+1], int i, int j) 
{ 
	printf("Rows %d and %d swapped\n", i+1, j+1); 

	for (int k=0; k<=N; k++) 
	{ 
		double temp = matrix[i][k]; 
		matrix[i][k] = matrix[j][k]; 
		matrix[j][k] = temp; 
	}
	print(matrix);
} 

//Reduces matrix to echelon form
int rowReduction(double matrix[N][N+1]) 
{
	//Vector of max row values
	double s[N];

	for(int k=0; k<N; k++)
	{
		//initialize vector with each row max value
		for(int i = 0; i<N; i++) {
			s[i] = matrix[i][0];
			for(int j=1; j<N; j++) {
				if(abs(matrix[i][j]) > s[i])
					s[i] = matrix[i][j];
			}
		}
		//Max index and value for pivot 
		int i_max = k;
		double v_max = matrix[i_max][k]/s[k];
		v_max = round(v_max);

		//find max aik/si for swap
		for (int i = k+1; i < N; i++) {
			if (abs(matrix[i][k]/s[i]) > v_max)
				v_max = round(abs(matrix[i][k]/s[i])), i_max = i; 
		}

		//check for singular matrix
		if (!matrix[k][i_max]) 
			return k;

		//swap greatest value row with current row
		if (i_max != k) {
			rowSwap(matrix, k, i_max);
		}

		//forward elimination
		for (int i=k+1; i<N; i++) 
		{
			//value of m, factor to get 0s
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

//Finds solutions to echelon form matrix
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
							{3.333, 15920, 10.333, 7953}, 
                           {2.222, 16.710, 9.6120, 0.965}, 
                           {-1.5611, 5.1792, -1.6855, 2.714} 
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
*/