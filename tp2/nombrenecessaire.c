#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double f(double x)
{
	return exp(x);
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
unsigned nombrenecessaire(double (*f)(double), double a, double b, double err, double (*methode)(double(*)(double), double,double, int), double I)
{
	int n=1;
	double res=methode(f,a,b,n);
	while (fabs(I-res)>err)
	{ 
		n++;
		res=methode(f,a,b,n);
	}
	return n;	
	
}
int main()
{
	unsigned nb;
	double a=0;
	double b=1;
	int n=100;
	nb = nombrenecessaire(f,a,b,0.001,simpson,exp(1.0)-1);
	printf("le resultat est %u\n : ", nb);
	return 0;


}	
