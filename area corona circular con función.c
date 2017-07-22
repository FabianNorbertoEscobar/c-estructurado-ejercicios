#include<stdio.h>
#include<conio.h>
#include<locale.h>
#define Pi 3.14
float areacorona(float,float);
void main()
    {
    float a,b,area;
    setlocale(LC_CTYPE,"Spanish");
    printf("\n\n Ingrese el radio mayor y el radio menor de la corona circular,\n de a uno por vez, confirmando cada uno con enter:\n\n");
    scanf("%f%f",&a,&b);
    area=areacorona(a,b);
    printf("\n\n El área de la corona circular es de %8.2f cm2 \n\n",area);
    getch();
    }
float areacorona(float x,float y)
    {
    float sup;
    sup=Pi*(x*x-y*y);
    return sup;
    }
