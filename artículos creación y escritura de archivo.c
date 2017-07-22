#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<locale.h>
struct arti
    {
    int nume;
    char desc[26];
    float costo;
    int saldo;
    };
void leedatos(struct arti *);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    FILE *stock;
    struct arti articulo;
    if((stock=fopen("a:stockfe.dat","wb"))==NULL)
        {
        printf("\n\n Error al crear el archivo \n");
        exit(0);
        }
    leedatos(&articulo);
    while(articulo.nume!=0)
        {
        fwrite(&articulo,sizeof(struct arti),1,stock);
        leedatos(&articulo);
        }
    fclose(stock);
    getch();
    }
void leedatos(struct arti *a)
    {
    printf("\n Ingrese número de artículo: \n\t");
    scanf("%d",&a->nume);
    fflush(stdin);
    printf("\n Ingrese descripción: \n\t");
    gets(a->desc);
    printf("\n Ingrese costo unitario: \n\t");
    fflush(stdin);
    printf("\n Ingrese el saldo actual: \n\t");
    scanf("%d",&a->saldo);
    fflush(stdin);
    }
