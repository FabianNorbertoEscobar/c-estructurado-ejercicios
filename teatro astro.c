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
struct info2
    {
    int cv;
    float pre;
    };
struct info3
    {
    int nf;
    int cbs;
    };
void inicializarvec(int[],int);
void fcarga(struct info2[]);
void funcionc(struct info2[]);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info2 vec[20];
    struct info3 aux;
    float sum;
    int i,vnv[20],dis;
    FILE *pf;
    printf("\n\t\t ****** TEATRO ASTRO ****** \n\n");
    printf("\n Control de las ventas de las obras exhibidas en la fecha: \n\n\t\t 21/Septiembre \n\n");
    printf("\n Contamos con 600 butacas, divididas en 20 filas de 30 butacas cada una \n\n");
    inicializarvec(vnv,20);
    fcarga(vec);
    pf=fopen("ventas.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    fread(&aux,sizeof(struct info3),1,pf);
    while(!feof(pf))
        {
        dis=30-vec[aux.nf-1].cv;
        if(dis==0)
            printf("\n Butacas agotadas en la fila %d \n\n",aux.nf);
        if(aux.cbs<=dis)
            vec[aux.nf-1].cv-=aux.cbs;
        else
            {
            printf("\n\t No quedan %d butacas libres en la fila %d \n\n",aux.cbs,aux.nf);
            vnv[aux.nf-1]+=aux.cbs;
            }
        fread(&aux,sizeof(struct info3),1,pf);
        }
    fclose(pf);
    sum=0;
    printf("\n Disponibilidad final de butacas \n");
    printf("\n N° DE FILA \t CANTIDAD DE BUTACAS \n");
    for(i=0;i<20;i++)
        {
        printf("\n %d \t\t %d",i+1,30-vec[i].cv);
        sum+=vec[i].cv*vec[i].pre;
        }
    printf("\n\n Dinero total recaudado con las ventas: %.2f \n\n",sum);
    printf("\n Cantidad de butacas rechazadas por falta de disponibilidad por fila \n\n");
    printf("\n N° DE FILA \t CANTIDAD DE BUTACAS \n");
    for(i=0;i<20;i++)
    printf("\n %d \t\t %d",i+1,vnv[i]);
    funcionc(vec);
    printf("\n\n El archivo Ventas21Septiembre.dat ha sido actualizado \n\n");
    printf("\n Fin del programa... \n\n\a\a");
    getch();
    }
void inicializarvec(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
void fcarga(struct info2 v[])
    {
    int i;
    FILE *pf;
    struct info1 aux;
    pf=fopen("Ventas21Septiembre.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\t\t El archivo está corrupto \n\n");
        exit(0);
        }
    for(i=0;i<20;i++)
        {
        fread(&aux,sizeof(struct info1),1,pf);
        v[aux.nf-1].cv=aux.cv;
        v[aux.nf-1].pre=aux.pre;
        }
    fclose(pf);
    }
void funcionc(struct info2 v[])
    {
    int i;
    struct info1 aux;
    FILE *pf;
    pf=fopen("Ventas21Septiembre.dat","wb");
    for(i=0;i<20;i++)
        {
        aux.nf=i+1;
        aux.cv=v[i].cv;
        aux.pre=v[i].pre;
        fwrite(&aux,sizeof(struct info1),1,pf);
        }
    fclose(pf);
    }
