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
struct info2
    {
    int cp;
    int cup;
    };
struct info3
    {
    int cp;
    char des[36];
    int cu;
    };
int fcarga(struct info1[]);
int buscar(struct info1[],int,int);
void funcionb(struct info1[],int);
void funcionc(struct info1[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info1 vec[3000];
    struct info2 aux;
    int cant,i,pos,sumE,sumS,sumM,sumF;
    FILE *pf;
    printf("\n\t\t ***** ENPRESA PANTACOR S.R.L. ****** \n\n");
    printf("\n La empresa se dedica a la fabricación y venta de muebles para oficina \n");
    printf(" Actualmente se poseen casi 3000 artículos a la venta \n");
    printf("\n CONTROL DE ARTÍCULOS \n\n");
    cant=fcarga(vec);
    sumE=sumS=sumM=sumF=0;
    pf=fopen("pedidos2.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    fread(&aux,sizeof(struct info1),1,pf);
    while(!feof(pf))
        {
        pos=buscar(vec,cant,aux.cp);
        if(pos!=-1)
            if(aux.cup<=vec[pos].cu)
                {
                vec[pos].cu-=aux.cup;
                switch(vec[pos].car)
                    {
                    case 'E':sumE+=aux.cup;
                             break;
                    case 'S':sumS+=aux.cup;
                             break;
                    case 'M':sumM+=aux.cup;
                             break;
                    case 'F':sumF+=aux.cup;
                             break;
                    }
                }
            else
                printf("\n Stock insuficiente \n\n");
        else
            {
            printf("\n Tenemos un nuevo artículo. Cargue los datos restantes: \n");
            printf("\n El código del producto es %d \n",aux.cp);
            vec[cant].cp=aux.cp;
            printf("\n La cantidad de unidades en stock es %d \n",aux.cup);
            vec[cant].cu=aux.cup;
            printf("\n Ingrese la descripción del producto (hasta 30 caracteres): \n\n\t\t");
            fflush(stdin);
            gets(vec[cant].des);
            printf("\n La característica puede ser: \n(E:Escritorio, S:silla, M:mesa ,F:fichero)\n");
            printf("\n Ingrese la característica adecuada: \n\n\t\t");
            do
                {
                fflush(stdin);
                scanf("%c",&vec[cant].car);
                }
            while(!(vec[cant].car=='E'||vec[cant].car=='S'||vec[cant].car=='M'||vec[cant].car=='F'));
            cant++;
            }
        fread(&aux,sizeof(struct info1),1,pf);
        }
    fclose(pf);
    printf("\n Cantidad de unidades vendidas de cada característica: \n");
    printf("\n Escritorios: \t %d \n",sumE);
    printf("\n Sillas: \t %d \n",sumS);
    printf("\n Mesas: \t %d \n",sumM);
    printf("\n Ficheros: \t %d \n",sumF);
    funcionb(vec,cant);
    printf("\n Se ha creado un archivo llamado sinstock.dat en el que se encuentran \n los productos que se han quedado sin stock \n");
    funcionc(vec,cant);
    printf("\n Se ha creado un archivo llamado caracteristicaF.dat en el que están \n los datos de los ficheros \n\n");
    printf("\n \t\t\t Fin del programa... \n\n");
    getch();
    }
int fcarga(struct info1 v[])
    {
    int i;
    FILE *pf;
    pf=fopen("productos.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    i=0;
    fread(&v[i],sizeof(struct info1),1,pf);
    while(!feof(pf))
        {
        i++;
        fread(&v[i],sizeof(struct info1),1,pf);
        }
    fclose(pf);
    return i;
    }
int buscar(struct info1 v[],int ce,int cp)
    {
    int p,i;
    p=-1;
    i=0;
    while(p==-1&&i<ce)
        {
        if(v[i].cp==cp)
            p=i;
        else
            i++;
        }
    return p;
    }
void funcionb(struct info1 v[],int ce)
    {
    int i;
    FILE *pf;
    pf=fopen("sinstock.dat","wb");
    for(i=0;i<ce;i++)
        if(v[i].cu==0)
            fwrite(&v[i],sizeof(struct info1),1,pf);
    fclose(pf);
    }
void funcionc(struct info1 v[],int ce)
    {
    int i;
    struct info3 aux;
    FILE *pf;
    pf=fopen("caracteristicaF.dat","wb");
    for(i=0;i<ce;i++)
        {
        if(v[i].car=='F')
            {
            aux.cp=v[i].cp;
            strcpy(aux.des,v[i].des);
            aux.cu=v[i].cu;
            }
        fwrite(&aux,sizeof(struct info3),1,pf);
        }
    fclose(pf);
    }
