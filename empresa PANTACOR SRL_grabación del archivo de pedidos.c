#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info2
    {
    int cp;
    int cup;
    };
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info2 aux;
    int cp,cup;
    FILE *pf;
    pf=fopen("pedidos2.dat","ab");
    printf("\n Cargue los datos de los pedidos. (finalice la carga con código cero) \n");
    printf("\n NUEVO PEDIDO \n");
    printf("\n Ingrese el código del producto (entre 4000 y 14000): \n\n\t\t");
    do
        {
        scanf("%d",&cp);
        }
    while(!(validadato(cp,4000,14000)||cp==0));
    while(cp!=0)
        {
        aux.cp=cp;
           printf("\n Ingrese la cantidad de unidades vendidas (entre 1 y 4000): \n\n\t\t");
        do
            {
            scanf("%d",&cup);
            }
        while(!validadato(cup,1,4000));
        aux.cup=cup;
        fwrite(&aux,sizeof(struct info2),1,pf);
        printf("\n NUEVO PEDIDO \n");
        printf("\n Ingrese el código del producto (entre 4000 y 14000): \n\n\t\t");
        do
            {
            scanf("%d",&cp);
            }
        while(!(validadato(cp,4000,14000)||cp==0));
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
