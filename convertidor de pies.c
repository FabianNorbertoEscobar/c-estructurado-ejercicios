#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
{
setlocale(LC_CTYPE,"Spanish");
float ft,in,yd,cm,m;
printf("\n ******************* \n");
printf(" CONVERTIDOR DE PIES \n");
printf(" ******************* \n\n");
    printf("\n Ingrese una medida expresada en pies:\n\n\t");
    scanf("%f",&ft);
        in=ft*12;
        yd=ft/3;
        cm=in*2.54;
        m=cm/100;
    printf("\n\n Pies: %f \n\n Pulgadas: %f \n\n Yardas: %f \n\n Centímetros: %f \n\n Metros: %f \n\n",ft,in,yd,cm,m);
getch();
}
