#include<stdio.h>
#include<math.h>
#include<iostream>

using namespace std;

int main()
{
	int N = 4;
    double a[N][N] = {
        {-4,0,.5,.5},
        {.5,-2,0,.5},
        {.5,.5,0,0},
        {0,1,1,4},
    };
    double b[N] = {0,0,0,1};
    double c[N],d=0,temp;

    do {
        for(int i=0; i<N; i++) {
            c[i]=0;
            for(int j=0; j<N; j++)
                c[i]+=a[i][j]*b[j];
        }

        for(int i=0; i<N; i++)
            b[i]=c[i];
            
        temp=d;
        d=0;
        
        for(int i=0; i<N; i++)
        {
            if(fabs(b[i])>fabs(d))
                d=b[i];
        }
        for(int i=0; i<N; i++)
            b[i]/=d;
    } while(fabs(d-temp)>0.000001);

	printf("Eigenvalue: %lf\n",  d);
    printf("Eigenvector:\n");
       for(int i=0;i<N;i++,printf("\n"))
            printf("%lf\n", b[i]);
    
    return 0;
}

/*
	int N = 3;
    double a[N][N] = {
    	{4, 2, 1},
    	{0, 3, 2},
    	{1, 1, 4}
    };
    double b[N] = {1,2,1};

    int N = 4;
    double a[N][N] = {
    	{1, 1, 0, 0},
    	{1, 2, 0, 1},
    	{0, 0, 3, 3},
    	{0, 1, 3, 2},
    };
    double b[N] = {1,1,0,1};

    int N = 4;
    double a[N][N] = {
    	{5, -2, -.5, 1.5},
    	{-2, 5, 1.5, -.5},
    	{-.5, 1.5, 5, -2},
    	{1.5, -.5, -2, 5},
    };
    double b[N] = {1,1,0,-3};

	int N = 4;
    double a[N][N] = {
    	{-4,0,.5,.5},
    	{.5,-2,0,.5},
    	{.5,.5,0,0},
    	{0,1,1,4},
    };
    double b[N] = {0,0,0,1};
*/