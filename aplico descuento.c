#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cod;
    float pi,pf;
    printf("\n\n Ingrese el precio del producto y un código \n (1 para aplicar descuento, 0 para no hacerlo) \n confirme cada uno con enter \n\n");
    scanf("%f%d",&pi,&cod);
    pf=pi-pi*20/100*cod;
    printf("\n\n Precio final: %8.2f",pf);
    getch();
    }
