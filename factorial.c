#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n,i,fact;
    printf("\n\n Ingrese un número entero para calcular su factorial:\n\n\t");
    scanf("%d",&n);
    fact=1;
    for(i=1;i<=n;i++)
        fact*=i;
    printf("\n\n Factorial de %d: \t %d \n\n",n,fact);
    getch();
    }
