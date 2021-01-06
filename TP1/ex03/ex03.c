#include<stdio.h>
#include<stdlib.h>
const int N=10;
void get_input(float A[][N], float *B, int *n)
{
	printf("enter the matrix dimension : ");
	scanf("%d",n);
	for(int i=0; i<*n; i++)
	{
		for(int j=0; j<*n; j++)
		{
			printf("A[%d][%d] =",i,j);
			scanf("%f", &A[i][j]);
		}	

	}	
	for(int i=0; i<*n; i++)
	{
		printf("B[%d]=",i);
		scanf("%f", &B[i]);
	}	
}

float *lu(float A[N][N], float B[N], int n)
{
	float s;
	float *X , L[N][N] , Y[N];
	X = (float *)malloc(sizeof(float));
        for( int k=0; k<n-1; k++)
	{
                for(int i=k+1; i<n ; i++)
		{
		        L[i][k] = A[i][k] / A[k][k];
		        for (int j=k+1; j<n ; j++)
	                {
			        A[i][j]=A[i][j] - L[i][k]*A[k][j]; 
	                }		
		}
	}
        Y[0]=B[0];
	for(int i=1; i<n; i++)
	{
		s=0;
		for(int j=0; j< i; j++)
		{
			s+= L[i][j]*Y[j];
		}
		Y[i]=B[i] - s;
	}
	X[n-1]=Y[n-1]/A[n-1][n-1];
	for( int i= n-2; i>=0; i--)
	{

	        s=0;
		for(int j=i+1; j<= n-1; j++)
		{
			s+=A[i][j]*X[j];
		}
		X[i]=(Y[i] - s)/ A[i][i];
	}
	return(X);
}	
int main()
{
	float A[N][N];
	float B[N];
	float *x;
	int n;
	get_input(A,B,&n);
	x= lu(A,B,n);
	printf("the resulting vector: [");
	for(int i=0; i<n ; i++)
		printf("%f%c",x[i], ",]"[i == n - 1]);
}	
