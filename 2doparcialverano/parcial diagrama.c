#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct info1
    {
    char pat[7];
    int rut;
    int paqm;
    float capm;
    };
struct info2
    {
    int dia;
    char pat[7];
    int paq;
    float pes;
    };
void inicializarvec(int[],int);
void inicializarmat(int[][31],int,int);
int fcarga(struct info1[]);
int buscar(struct info1[],int,char[7]);
void sumarxfila(int[][31],int,int,int[]);
void maximo(int[],int);
void funcionb(struct info1[],int);
void mostrarmatriz(int[][31],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info1 vec[1000];
    struct info2 aux;
    FILE *pf;
    int cant,pos,vxr[200],mat[200][31];
    printf("\n EMPRESA 3 \n");
    printf("\n Prestación de servicios de mensajería, recados, reparto y manipulación \n de correspondencia, entrega de documentos y paquetería \n\n");
    inicializarvec(vxr,200);
    inicializarmat(mat,200,31);
    printf("\n CONTROL DE VIAJES \n\n");
    cant=fcarga(vec);
    pf=fopen("viajes.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    fread(&aux,sizeof(struct info2),1,pf);
    while(!feof(pf))
        {
        pos=buscar(vec,cant,aux.pat);
        if(pos!=-1)
            if(vec[pos].paqm<aux.paq||vec[pos].capm<aux.pes)
                printf("\n No se puede realizar el viaje del vehículo con patente %s \n del día %d porque se superan los topes permitidos \n\n",aux.pat,aux.dia);
            else
                {
                printf("\n Se realiza exitosamente el viaje del vehículo con patente %s del día %d \n\n",aux.pat,aux.dia);
                mat[vec[pos].rut-1][aux.dia-1]++;
                }
        else
            printf("\n No contamos con el vehículo de patente %s \n\n",aux.pat);
        fread(&aux,sizeof(struct info2),1,pf);
        }
    fclose(pf);
    sumarxfila(mat,200,13,vxr);
    printf("\n Para ver la cantidad de viajes realizados por ruta y dia, \n presione una tecla cualquiera \n\n");
    getch();
    printf("\n Cantidad de viajes realizados por ruta y día \n\n RUTA \t VIAJES \n\n");
    mostrarmatriz(mat,200,31);
    maximo(vxr,200);
    funcionb(vec,cant);
    printf("\n Se ha creado un archivo llamado Ruta25,101y158.dat \n en donde se encuentran los vehículos que realizan los viajes \n en las rutas 25, 101 y 158 \n\n");
    printf("\n Fin del programa \n\n");
    getch();
    }
void inicializarvec(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
void inicializarmat(int m[][31],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            m[i][j]=0;
    }
int fcarga(struct info1 v[])
    {
    FILE *pf;
    int i;
    i=0;
    pf=fopen("vehiculos.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t\t El archivo está corrupto \n\n");
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
int buscar(struct info1 v[],int ce,char pat[7])
    {
    int i,p;
    i=0;
    p=-1;
    while(p==-1&&i<ce)
        {
        if(strcmp(v[i].pat,pat)==0)
            p=i;
        else
            i++;
        }
    return p;
    }
void sumarxfila(int m[][31],int f,int c,int v[])
    {
    int i,j;
    for(i=0;i<f;i++)
        for(j=0;j<c;j++)
            v[i]+=m[i][j];
    }
void maximo(int v[],int ce)
    {
    int i,band,may,r;
    band=0;
    for(i=0;i<ce;i++)
        if(band==0||v[i]>may)
            {
            band=1;
            may=v[i];
            r=i+1;
            }
    printf("\n\n La ruta por la que se realizó la mayor cantidad de viajes \n fue la ruta %d, con %d viajes \n\n",r,may);
    }
void funcionb(struct info1 v[],int ce)
    {
    int i;
    struct info1 aux;
    FILE *pf;
    pf=fopen("Ruta25,101y158.dat","wb");
    for(i=0;i<ce;i++)
        if(v[i].rut==25||v[i].rut==101||v[i].rut==158)
            fwrite(&aux,sizeof(struct info1),1,pf);
    fclose(pf);
    }
void mostrarmatriz(int m[][31],int f,int c)
    {
    int i,j;
    for(i=0;i<f;i++)
        {
        Sleep(200);
        printf("\n %d",i+1);
        for(j=0;j<c;j++)
            printf("  %d",m[i][j]);
        }
    }
