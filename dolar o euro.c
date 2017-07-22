#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    float dol,eu,p,s;
    int c;
    printf("\n Ingrese el valor del dólar: \n\t");
    scanf("%f",&dol);
    printf("\n Ingrese el valor del euro: \n\t");
    scanf("%f",&eu);
    printf("\n Ingrese el monto que desea comprar (en pesos) \n\t");
    scanf("%f",&p);
    printf("\n Ingrese el código 1 para comprar dólares o 2 para euros \n");
    scanf("%d",&c);
    if(c==1)
        printf("\n Monto de dólares a comprar: %8.2f \n\n",p/dol);
    else
        printf("\n Monto de euros a comprar: %8.2f \n\n",p/eu);
    getch();
    }
