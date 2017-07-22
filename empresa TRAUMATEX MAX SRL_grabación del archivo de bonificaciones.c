#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info2
    {
    float a;
    float b;
    float c;
    };
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info2 aux;
    FILE *pf;
    pf=fopen("bonificaciones.dat","wb");
    printf("\n Cargue las bonificaciones percibidas por los promotores en las ventas \n\n");
    printf("\n Ingrese el porcentaje de bonificación correspondiente a las ventas \n que no superan las 100 unidades: \n\n\t\t");
    do
        {
        scanf("%f",&aux.a);
        }
    while(aux.a<=0);
    printf("\n Ingrese el porcentaje de bonificación correspondiente a las ventas \n de entre 100 y 500 unidades: \n\n\t\t");
    do
        {
        scanf("%f",&aux.b);
        }
    while(aux.b<=0);
    printf("\n Ingrese el porcentaje de bonificación correspondinete a las ventas \n que superan las 500 unidades: \n\n\t\t");
    do
        {
        scanf("%f",&aux.c);
        }
    while(aux.c<=0);
    fwrite(&aux,sizeof(struct info2),1,pf);
    fclose(pf);
    printf("\n Archivo creado/actualizado \n\n");
    getch();
    }
