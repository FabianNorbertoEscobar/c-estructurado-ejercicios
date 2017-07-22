#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info1
    {
    int na;
    char art[31];
    int st;
    float pre;
    };
struct info2
    {
    float a;
    float b;
    float c;
    };
struct info3
    {
    int np;
    int na;
    int cuv;
    };
struct info4
    {
    int na;
    char art[31];
    int st;
    };
void inicializarveci(int[],int);
void inicializarvecf(float[],int);
int fcarga1(struct info1[]);
struct info2 fcarga2(void);
void funcionb(struct info1[],int,int[]);
void funcionc(struct info1[],int);
int buscar(struct info1[],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info1 vec[5000];
    struct info2 bon;
    struct info3 aux;
    int i,cant,bandera[5000],pos;
    float bonif,ve[15];
    FILE *pf;
    inicializarveci(bandera,5000);
    inicializarvecf(ve,15);
    cant=fcarga1(vec);
    bon=fcarga2();
    printf("\n\a\a\t\t *** EMPRESA TRAUMATEX MAX SRL *** \n\n");
    printf("\n Nuestra empresa se dedica a la exportación y venta de productos \n ortopédicos de primera categoría. \n");
    printf("\n Contamos con casi 5000 artículos y 15 promotores \n\n");
    printf("\n Aquí llevamos el control de las ventas y la actualización de stock \n\n");
    pf=fopen("pedidos.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    fread(&aux,sizeof(struct info3),1,pf);
    while(!feof(pf))
        {
        pos=buscar(vec,cant,aux.na);
        if(pos!=-1)
            {
            if(aux.cuv<=vec[pos].st)
                {
                vec[pos].st-=aux.cuv;
                if(aux.cuv<100)
                    bonif=bon.a;
                else
                    if(aux.cuv<500)
                        bonif=bon.b;
                    else
                        bonif=bon.c;
                ve[aux.np-1]+=(float)aux.cuv*vec[pos].pre*bonif/100;
                bandera[pos]=1;
                }
            else
                printf("\n Stock insuficiente \n\n\a\a");
            }
        else
            printf("\n El número de artículo solicitado no existe \n\n");
        fread(&aux,sizeof(struct info3),1,pf);
        }
    fclose(pf);
    printf("\n Comisión percibida por cada promotor \n");
    printf("\n N° DE PROMOTOR \t COMISIÓN PERCIBIDA \n");
    for(i=0;i<15;i++)
        printf("\n %d \t\t %.2f",i+1,ve[i]);
    funcionb(vec,cant,bandera);
    printf("\n\n Se ha generado el archivo sinventas.dat que contiene \n aquellos artículos que no han tenido ventas \n");
    funcionc(vec,cant);
    printf("\n Además, se ha generado el archivo artículosactualizados.dat \n que contiene el nuevo stock de los productos \n");
    printf("\n\t\t Fin del programa ... \n\n");
    getch();
    }
void inicializarveci(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
void inicializarvecf(float v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
int fcarga1(struct info1 v[])
    {
    int i;
    FILE *pf;
    i=0;
    pf=fopen("artículos.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    fread(&v[i],sizeof(struct info1),1,pf);
    while(!feof(pf))
        {
        i++;
        fread(&v[i],sizeof(struct info1),1,pf);
        }
    fclose(pf);
    return i;
    }
struct info2 fcarga2(void)
    {
    struct info2 aux;
    FILE *pf;
    pf=fopen("bonificaciones.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    fread(&aux,sizeof(struct info2),1,pf);
    fclose(pf);
    return aux;
    }
void funcionb(struct info1 v[],int ce,int b[])
    {
    int i;
    FILE *pf;
    pf=fopen("sinventas.dat","wb");
    for(i=0;i<ce;i++)
        if(b[i]==0)
            fwrite(&v[i],sizeof(struct info1),1,pf);
    fclose(pf);
    }
void funcionc(struct info1 v[],int ce)
    {
    int i;
    FILE *pf;
    struct info4 aux;
    pf=fopen("artículosactualizados.dat","wb");
    for(i=0;i<ce;i++)
        {
        strcpy(aux.art,v[i].art);
        aux.st=v[i].st;
        aux.na=v[i].na;
        fwrite(&aux,sizeof(struct info4),1,pf);
        }
    fclose(pf);
    }
int buscar(struct info1 v[],int ce,int na)
    {
    int i,p;
    p=-1;
    i=0;
    while(p==-1&&i<ce)
        {
        if(v[i].na==na)
            p=i;
        else
            i++;
        }
    return p;
    }
