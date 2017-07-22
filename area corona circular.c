#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define Pi 3.14
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float a,b,area;
    printf("\n\n Ingrese el radio mayor y el radio menor de la corona circular, en cm, \n de a uno por vez, confirmando cada uno con enter:\n\n");
    scanf("%f%f",&a,&b);
    area=Pi*(a*a-b*b);
    printf("\n\n El área de la corona circular es %8.2f cm2 \n\n",area);
    getch();
    }
