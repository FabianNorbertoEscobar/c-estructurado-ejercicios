#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define Pi 3.14
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cod;
    float grad,sex,rad;
    printf("\n\n Ingresar grados sexagesimales y el código 1 para convertir a radianes \n ó grados radianes y el código 2 para convertir a sexagesimales \n (confirme los datos de a uno con enter)\n\n");
    do
        scanf("%f%d",&grad,&cod);
    while(cod!=1&&cod!=2);
    if(cod==1)
        {
        sex=grad;
        rad=sex*2*Pi/360;
        }
    else
        {
        rad=grad;
        sex=rad*360/2*Pi;
        }
    printf("\n\n %8.2f grados sexagesimales equivalen a%8.2f grados radianes\n\n",sex,rad);
    getch();
    }
