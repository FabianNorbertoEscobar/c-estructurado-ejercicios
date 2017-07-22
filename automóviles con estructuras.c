#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<locale.h>
struct auto1
    {
    char marca[13];
    int aniofabri;
    char color[9];
    float precio;
    };
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct auto1 automovil,autito;
    int j;
    float pesos;
    for(j=1;j<4;j++)
        {
        printf("\n\n Ingrese marca, año, color y precio del auto: \n");
        printf("\tIngréselos de a uno y confirmando cada uno con enter\n\n");
        scanf("%s%d%s%f",&automovil.marca,&automovil.aniofabri,&automovil.color,&pesos);
        fflush(stdin);
        automovil.precio=pesos;
        autito=automovil;
        if(autito.precio<9000)
            printf("\n %-13s,%-9s,%5d \n",autito.marca,autito.color,autito.aniofabri);
        }
    getch();
    }
