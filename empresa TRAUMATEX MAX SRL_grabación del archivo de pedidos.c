#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
struct info3
    {
    int np;
    int na;
    int cuv;
    };
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info3 aux;
    int np,na,cuv;
    FILE *pf;
    pf=fopen("pedidos.dat","ab");
    printf("\n Cargue los datos de los pedidos que ha recibido la ortopedia: \n\n");
    printf("\n NUEVO PEDIDO \n\n");
    printf("\n Ingrese el número de promotor (entre 1 y 15)(finaliza con cero): \n\n\t\t");
    do
        {
        scanf("%d",&np);
        }
    while(!validadato(np,0,15));
    while(np!=0)
        {
        aux.np=np;
        printf("\n Ingrese el número de artículo (entre 1000 y 15000): \n\n\t\t");
        do
            {
            scanf("%d",&na);
            }
        while(!validadato(na,1000,15000));
        aux.na=na;
        printf("\n Ingrese la cantidad de unidades pedidas (entre 1 y 100): \n\n\t\t");
        do
            {
            scanf("%d",&cuv);
            }
        while(!validadato(cuv,1,1000));
        fwrite(&aux,sizeof(struct info3),1,pf);
        printf("\n NUEVO PEDIDO \n\n");
        printf("\n Ingrese el número de promotor (entre 1 y 15)(finaliza con cero): \n\n\t\t");
        do
            {
            scanf("%d",&np);
            }
        while(!validadato(np,0,15));
        }
    fclose(pf);
    printf("\n Archivo creado/actualizado... \n\n");
    getch();
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
