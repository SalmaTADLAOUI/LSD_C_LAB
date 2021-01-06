#include<stdio.h>
#include <stdlib.h>
void arabic()
{
	printf("SALAM ALIKOM\n");
}
void french()
{
	printf("BONJOUR\n");
}	
void english()
{
	printf("HELLO\n");
}	
void spanish()
{
	printf("HOLA\n");
}	
void greeting( void (* f)(void))
{
	int n;
	f();
		
	
}	
int main()
{
	int n;
	void (*arr[4])(void);
	arr[0]=arabic;
	arr[1]=french;
	arr[2]=english;
	arr[3]=spanish;
	printf("donner une langue si arab taper 1, si fr taper 2, si ag taper 3, si spa taper 4\n");
	scanf("%d",&n);
	greeting(arr[n-1]);
 }	
