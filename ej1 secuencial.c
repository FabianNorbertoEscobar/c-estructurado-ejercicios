#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int dato1,dato2,r1,r2;
    printf("\n Ingrese el primer número: \n\t");
    scanf("%d",&dato1);
    printf("\n Ingrese el segundo número: \n\t");
    scanf("%d",&dato2);
    r1=2*dato1+dato2*dato2;
    r2=(dato1*dato1*dato1+dato2*dato2*dato2)/2;
    printf("\n La suma del doble del primero y el cuadrado del segundo es: %d \n",r1);
    printf("\n El promedio de los cubos de ambos números es: %d \n\n",r2);
    getch();
    }
