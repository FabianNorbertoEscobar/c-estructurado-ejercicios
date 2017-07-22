#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
struct info3
    {
    int nf;
    int cbs;
    };
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info3 aux;
    FILE *pf;
    pf=fopen("ventas.dat","ab");
    printf("\n Cargue los pedidos de ventas de butacas \n\n");
    printf("\n Ingrese el número de fila (entre 1 y 20)(finaliza con cero): \n\n\t\t");
    do
        {
        scanf("%d",&aux.nf);
        }
    while(!validadato(aux.nf,0,20));
    while(aux.nf!=0)
        {
        printf("\n Ingrese la cantidad de butacas solicitadas (entre 1 y 10):\n\n\t\t");
        do
            {
            scanf("%d",&aux.cbs);
            }
        while(!validadato(aux.cbs,1,10));
        fwrite(&aux,sizeof(struct info3),1,pf);
        printf("\n Ingrese el número de fila (entre 1 y 20)(finaliza con cero): \n\n\t\t");
        do
            {
            scanf("%d",&aux.nf);
            }
        while(!validadato(aux.nf,0,20));
        }
    fclose(pf);
    printf("\n\n Archivo creado/actualizado ... \n\n");
    getch();
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
