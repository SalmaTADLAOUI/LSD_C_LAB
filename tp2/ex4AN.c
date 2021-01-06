#include<stdio.h>
#include<stdlib.h>
double f(double x)
{
	return x;
}
double simpson(double (*f)(double), double a, double b, int n)
{
	float h=(b-a)/n;
	float x=a+h;
	float z=(a+h)/2;
	double I1=0;
	double I2=f(z);
	for (int i=0; i<n-1 ; i++)
	{
		z+=h;
		x+=h;
		I1+=f(x);
		I2+=f(z);
	}
	return (h/6)*(f(a)+f(b)+2*I1+4*I2);	
}
int main()
{
	double a=0;
	double b=1;
	int n=1000;
	double inte=0;
	inte= simpson(f, a, b, n);
	printf("les resultats sont : %f\n",inte);
	return 0;
}	
