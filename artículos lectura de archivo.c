#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
#define TAM 10
struct arti
    {
    int nume;
    char desc[26];
    float costo;
    int saldo;
    };
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    FILE *stock;
    struct arti articulo[TAM];
    int i=0,j;
    if((stock=fopen("a:stockfe.dat","rb"))==NULL)
        {
        printf("\n Error al abrir el archivo \n");
        exit(0);
        }
    fread(&articulo[i],sizeof(struct arti),1,stock);
    while(!feof(stock))
        {
        i++;
        fread(&articulo[i],sizeof(struct arti),1,stock);
        }
    fclose(stock);
    printf("\n \t *** LISTADO DE ARTÍCULO *** \n");
    printf("\n Número \t Descripción \t Costo \n");
    printf("\n Saldo actual: \n");
    for(j=0;j<i;j++)
        {
        printf("\n %5d \t %-26s",articulo[j].nume,articulo[j].desc);
        printf("\n %10.2f \t %8d",articulo[j].costo,articulo[j].saldo);
        }
    getch();
    }
