#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>
struct info1
    {
    int nf;
    int cv;
    float pre;
    };
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int i;
    struct info1 aux;
    FILE *pf;
    printf("\n Cargue las ventas del 21 de septiembre \n\n");
    pf=fopen("Ventas21Septiembre.dat","wb");
    for(i=0;i<20;i++)
        {
        printf("\n Número de fila: %d \n",i+1);
        aux.nf=i+1;
        printf("\n Ingrese la cantidad de butacas vendidas (entre 1 y 30):\n\n\t\t");
        do
            {
            scanf("%d",&aux.cv);
            }
        while(!validadato(aux.cv,1,30));
        printf("\n Ingrese el precio de cada butaca de esta fila: \n\n\t\t");
        do
            {
            scanf("%f",&aux.pre);
            }
        while(aux.pre<=0);
        fwrite(&aux,sizeof(struct info1),1,pf);
        }
    fclose(pf);
    printf("\n Archivo creado/actualizado ... \n\n");
    getch();
    }
int validadato(int x,int li,int ls)
    {
    if(x>=li&&x<=ls)
        return 1;
    else
        return 0;
    }
