#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int n,pot;
    printf("\n\n Ingrese el número del cual quiere calcular algunas de sus potencias: \n\n\t");
    scanf("%d",&n);
    pot=1;
    printf("\n\n Sus primeras potencias son: \n\n");
    while(pot<100000000)
        {
        pot*=n;
        printf("\n\t%d",pot);
        }
    getch();
    }
