#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info1
    {
    char pat[7];
    int rut;
    int paqm;
    float capm;
    };
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info1 aux;
    int i,rut,paqm;
    float capm;
    char pat[7];
    FILE *pf;
    i=0;
    pf=fopen("vehiculos.dat","ab");
    printf("\n Cargue los datos de los vehículos. Recuerde que tiene casi 1000 productos. \n\n");
    printf("\n NUEVO VEHÍCULO \n\n");
    printf("\n Ingrese el número de ruta (entre 1 y 200)(Finalice con ruta cero): \n\n\t\t");
    do
        {
        scanf("%d",&rut);
        }
    while(!validadato(rut,0,200));
    while(rut!=0&&i<1000)
        {
        aux.rut=rut;
        printf("\n Ingrese la patente del vehículo (hasta 6 caracteres): \n\n\t\t");
        fflush(stdin);
        gets(pat);
        strcpy(aux.pat,pat);
        printf("\n Ingrese la cantidad máxima de paquetes que pueden ser transportados \n en este vehículo (entre 1 y 2000): \n\n\t\t");
        do
            {
            scanf("%d",&paqm);
            }
        while(!validadato(paqm,1,2000));
        aux.paqm=paqm;
        printf("\n Ingrese la capacidad máxima a transportar por este vehículo: \n\n\t\t");
        do
            {
            scanf("%f",&capm);
            }
        while(capm<=0);
        aux.capm=capm;
        fwrite(&aux,sizeof(struct info1),1,pf);
        i++;
        printf("\n NUEVO VEHÍCULO \n\n");
        printf("\n Ingrese el número de ruta (entre 1 y 200)(Finalice con ruta cero): \n\n\t\t");
        do
            {
            scanf("%d",&rut);
            }
        while(!validadato(rut,0,200));
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
