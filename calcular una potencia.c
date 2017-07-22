#include<stdio.h>
#include<conio.h>
#include<locale.h>
int potencia(int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int b,e,pot;
    printf("\n\n Ingrese una base y un exponente para calcular la potencia. \n Ingréselos de a uno por vez, confirmando cada uno con enter.\n\n");
    scanf("%d%d",&b,&e);
    pot=potencia(b,e);
    printf("\n\n La potencia es %d \n\n",pot);
    getch();
    }
int potencia(int base,int potencia)
    {
    int j,pot;
    pot=1;
    for(j=1;j<=potencia;j++)
        pot*=base;
    return pot;
    }
