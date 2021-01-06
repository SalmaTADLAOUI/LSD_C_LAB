#include<stdio.h>
#include<stdlib.h>
double f(double x)
{
	return x;
}
double f2(double x)
{	return x * x;
}

double rectgauche(double (*f)(double), double a, double b, int n)
{
	float h=(b-a)/n;
	double s=0;
	double x;
	for (int i=1; i<n+1; i++)
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
	inte=rectgauche(f,a,b,n);
	printf("les resultats sont %f\n",inte);
	printf("\n");
	return 0;
}

