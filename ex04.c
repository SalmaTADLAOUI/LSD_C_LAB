#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define N 10
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
int main()
{
	float A[N][N];
	float B[N];
	float X[N],C[N][N];
	float s,u,n;
	C[0][0]=sqrt(A[0][0]);
	for(int i=1; i<n; i++)
	{
		C[i][0]=A[i][0];
	}     
	for(int j=1; j<n; j++)
	{
		for(int i=0; i<j; i++)
		{
			C[i][j]=0;
		}
		for(int k=0; k<j ; k++)
		{
			s+=C[j][k]*C[j][k];
		}
		C[j][j]=sqrt(A[j][j]-s);
		for(int i=j+1; i<n; i++)
		{
			for(int k=0; k<j; k++)
			{	
				u+=C[i][k]*C[j][k];
			}	
			C[i][j]=(A[i][j]-u)/C[j][j];
		}
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n ; j++)
			{
				printf("%lf\n",C[i][j]);
			}	
		}


	}





}	
