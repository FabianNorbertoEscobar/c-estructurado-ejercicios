#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info2
    {
    int dia;
    char pat[7];
    int paq;
    float pes;
    };
int validadato(int,int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info2 aux;
    int i,dia,paq;
    float pes;
    char pat[7];
    FILE *pf;
    i=0;
    pf=fopen("viajes.dat","ab");
    printf("\n Cargue los datos de los viajes realizados en el mes de Agosto \n\n");
    printf("\n NUEVO VIAJE \n\n");
    printf("\n Ingrese el día del viaje (entre 1 y 31)(finalice con día cero): \n\n\t\t");
    do
        {
        scanf("%d",&dia);
        }
    while(!validadato(dia,0,31));
    while(dia!=0)
        {
        aux.dia=dia;
        printf("\n Ingrese la patente del vehículo (hasta 6 caracteres): \n\n\t\t");
        fflush(stdin);
        gets(pat);
        strcpy(aux.pat,pat);
        printf("\n Ingrese la cantidad de paquetes transportados (entre 1 y 2000): \n\n\t\t");
        do
            {
            scanf("%d",&paq);
            }
        while(!validadato(paq,1,2000));
        aux.paq=paq;
        printf("\n Ingrese el peso de la mercadería transportada: \n\n\t\t");
        do
            {
            scanf("%f",&pes);
            }
        while(pes<=0);
        aux.pes=pes;
        fwrite(&aux,sizeof(struct info2),1,pf);
        i++;
        printf("\n NUEVO VIAJE \n\n");
        printf("\n Ingrese el día del viaje (entre 1 y 31)(finalice con día cero): \n\n\t\t");
        do
            {
            scanf("%d",&dia);
            }
        while(!validadato(dia,0,31));
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
