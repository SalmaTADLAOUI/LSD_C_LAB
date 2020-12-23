#include<stdio.h>
const int N=10;
void get_input(float A[][N],float *B, int *n)
{
	printf("enter the matrix dimension:");
	scanf("%d",n);
	for(int i=0; i<*n; i++)
	{
		for(int j=0; j<*n; j++)
		{
			printf("A[%d][%d] =",i,j);
			scanf("%f", &A[i][j]);
		}
	}
	for(int i =0; i<*n; i++)
	{
		printf("B[%d]= ",i);
		scanf("%f",&B[i]);
	}

}
int main()
{
	int n;
	float A[N][N], B[N], X[N];
	get_input(A, B, &n);
	for (int k=0; k<=n-1; k++)
	{
		for(int i=k+1; i<=n; i++)
		{
			float factor=A[i][k]/A[k][k];
			for(int j=k+1; j<=n; j++)
			{
				A[i][j]=A[i][j]-factor*A[k][j];
			}
		        B[i]=B[i]-factor*B[k];
		}
	}	
	X[n- 1] =B[n- 1] / A[n- 1][n- 1];
	for (int i= n- 2; i>=0; i--)
	{
		float s=0;
		for (int j =i+1; j< n; j++)
		{
			s = s+A[i][j]*X[j];
		}
		X[i]= (B[i] - s) / A[i][i];
	}
	for (int i=0; i<n ; i++)
		printf("%lf\n", X[i]);
}


