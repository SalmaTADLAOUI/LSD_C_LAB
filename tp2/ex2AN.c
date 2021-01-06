#include<stdio.h>
#include<stdlib.h>
double f(double x)
{
	return x;
}
double rectdroit(double (*f)(double),double a, double b, double n)
{
	float h=(b-a)/n;
	double s=0;
	double x;
	for (int i=0; i<n ; i++)
	{
		x=a+i*h;
		s+=f(x);
	}
	return s*h;	
}
int main()
{
	double inte=0;
	double a=0;
	double b=1;
	int n=100;
	inte= rectdroit(f,a,b,n);
	printf("les resultats sont %f\n", inte);
	return 0;
}	
