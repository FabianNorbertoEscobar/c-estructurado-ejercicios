#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info1
    {
    int cp;
    char des[36];
    char car;
    int cu;
    };
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info1 aux;
    int cp,cu,i;
    char des[36],car;
    FILE *pf;
    pf=fopen("productos.dat","ab");
    printf("\n Cargue los datos de los productos. Recuerde que tiene casi 5000 artículos \n\n");
    i=0;
    printf("\n NUEVO ARTÍCULO \n\n");
    printf("\n Ingrese el código de producto (entre 4000 y 14000)(finalice con cero):\n\n\t\t");
    do
        {
        scanf("%d",&cp);
        }
    while(!(validadato(cp,4000,14000)||cp==0));
    while(cp!=0&&i<5000)
        {
        aux.cp=cp;
        printf("\n Ingrese la descripción del producto (hasta 35 caracteres): \n\n\t\t");
        fflush(stdin);
        gets(des);
        strcpy(aux.des,des);
        printf("\n La característica puede ser: \n(E:escritorio, S:silla, M:mesa ,F:fichero)\n");
        printf("\n Ingrese la característica adecuada: \n\n\t\t");
        do
            {
            scanf("%c",&car);
            }
        while(!(car=='E'||car=='S'||car=='M'||car=='F'));
        aux.car=car;
        printf("\n Ingrese la cantidad de unidades en stock (entre 1 y 4000): \n\n\t\t");
        do
            {
            scanf("%d",&cu);
            }
        while(!validadato(cu,1,4000));
        aux.cu=cu;
        fwrite(&aux,sizeof(struct info1),1,pf);
        i++;
        printf("\n NUEVO ARTÍCULO \n\n");
        printf("\n Ingrese el código de producto (entre 4000 y 14000)(finalice con cero):\n\n\t\t");
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
