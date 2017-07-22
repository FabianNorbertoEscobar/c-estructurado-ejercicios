#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
typedef struct articulo
    {
    int codigo;
    char descri[16];
    float costo;
    int saldo;
    };
extern unsigned_floatconvert;
#pragma extref_floatconvert
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct articulo arti[10];
    int cant,i,mincodigo;
    float min;
    char mindes[16];
    do
        {
        printf("\n Ingrese la cantidad de productos (máximo 100): \n\t");
        scanf("%d",&cant);
        }
    while(cant<=0||cant>100);
    for(i=0;i<cant;i++)
        {
        printf("\n Datos del producto %d\n",i+1);
        printf("\n Ingrese código: \n\t");
        scanf("%d",&arti[i].codigo);
        fflush(stdin);
        printf("\n Ingrese descripción: \n\t");
        gets(arti[i].descri);
        printf("\n Ingrese costo: \n\t");
        scanf("%f",&arti[i].costo);
        fflush(stdin);
        printf("\n Ingrese saldo: \n\t");
        scanf("%d",&arti[i].saldo);
        fflush(stdin);
        }
    printf("\n Listado de Productos \n\n",i+1);
    printf(" Código \t Descripción \t Costo \t Saldo \n\n");
    for(i=0;i<cant;i++)
        printf(" %4d \t %-16s \t %8.2f \t %8d \n",arti[i].codigo,arti[i].descri,arti[i].costo,arti[i].saldo);
    printf("\n\n\n");
    for(i=0;i<cant;i++)
        if(i==0||arti[i].costo<min)
            {
            min=arti[i].costo;
            mincodigo=arti[i].codigo;
            strcpy(mindes,arti[i].descri);
            }
    printf("\n\n Los datos del artículo de mínimo costo son: \n");
    printf(" Código:%d \t Descripción:%-s \t Costo:%.2f",mincodigo,mindes,min);
    getch();
    }
