#include<stdio.h>
#include<conio.h>
#include<locale.h>
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int cant_ing,cod_tam,costoFijo,costoBase,costoIng,costo;
    costoFijo=50;
    costoBase=30;
    costoIng=2;
    printf("\n\n Ingrese la cantidad de ingredientes (entre 1 y 10) \n y el código de tamaño de la pizza (chica:1,mediana:2,grande:3) \n\n");
    scanf("%d%d",&cant_ing,&cod_tam);
    costo=costoFijo+(costoBase*cod_tam)+(cant_ing*costoIng*cod_tam);
    printf("\n\n Costo de la pizza: %d \n\n",costo);
    getch();
    }
