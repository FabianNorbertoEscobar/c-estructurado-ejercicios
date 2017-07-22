#include<stdio.h>
#include<conio.h>
#include<locale.h>
int factorial(int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n,fact;
    printf("\n Ingrese un número para calcular su factorial: \t");
    scanf("%d",&n);
    fact=factorial(n);
    printf("\n El factorial de %d es %d \n\n",n,fact);
    getch();
    }
int factorial(int n)
    {
    if(n<=1)
        return 1;
    else
        return n*factorial(n-1);
    }
