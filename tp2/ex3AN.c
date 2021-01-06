#include<stdio.h>
#include<stdlib.h>
double f(double x)
{
	return x;
}
double trapeze(double (*f)(double), double a , double b, int n)
{
	float I=(0,5)*(f(a)+f(b));
	float h=(b-a)/n;
	double s=0;
	double x;
	for (int i=0; i<n-1; i++)
	{
		x=x+h;
		I+=f(x);
	}
	return h*I;
}
int main()
{
	double inte=0;
	double a=0;
	double b=1;
	int n=100;
	inte=trapeze(f, a, b, n);
	printf("les resultats sont %f\n", inte);
	return 0;
}
