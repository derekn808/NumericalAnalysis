#include<stdio.h>
#include<math.h>
#include<iostream> 

#define N 3 //size of NxN+1 input matrix

void print(double matrix[N][N+1]) 
{ 
	for (int i=0; i<N; i++, printf("\n")) 
		for (int j=0; j<=N; j++) 
			printf("%lf ", matrix[i][j]); 

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
	for (int k=0; k<N; k++) 
	{ 
		//Max index and value for pivot 
		int i_max = k; 
		int v_max = matrix[i_max][k]; 

		for (int i = k+1; i < N; i++) 
			if (abs(matrix[i][k]) > v_max) 
				v_max = matrix[i][k], i_max = i; 

		//check for singular matrix
		if (!matrix[k][i_max]) 
			return k;

		//swap greatest value row with current row
		if (i_max != k) {
			rowSwap(matrix, k, i_max);
		}


		for (int i=k+1; i<N; i++) 
		{
			//value of m factor to get 0s
			double m = matrix[i][k]/matrix[k][k];

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
	double matrix[N][N+1] = {{1.0, -1.0, 1.0, 5.0}, 
							{7.0, 5.0, -1.0, 8.0}, 
							{2.0, 1.0, 1.0, 7.0} 
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