//ESCOBAR,Fabián Norberto_39210915//
/*
La EMPRESA 1 que se dedica a la fabricación de heladeras y lavarropas. Cuenta también con casi 5000 productos hasta el momento, para ello se cuenta con los siguientes datos de cada producto (estos datos se hallan en un archivo llamado “empresa1.dat”):
•	Código de Artículo (char, 10 caracteres).
•	Características del Artículo (char, 35 caracteres)
•	Cantidad de unidades en Stock (int, entre 1 y 2000).
•	Punto de reposición (int, entre 1 y 2000).
•	Número de Depósito donde se halla el Artículo (int, entre 1 y 20).

Se pide determinar e informar:
a)	Informar en cada uno de los 20 Depósito, la cantidad de artículos que se encuentran por debajo
del punto de reposición. Informar el Número de Deposito y la Cantidad.

b)	Generar un nuevo archivo llamado “deposito12y15.dat” con aquellos productos
que se encuentran por arriba del punto de reposición y que corresponden al
depósito número 12 y 15. El diseño del registro de este nuevo archivo debe contener:
Código de Artículo, Características del Artículo y Cantidad de unidades en Stock.


FUNCIONES:
1.	Para cargar en memoria todos los datos que se encuentran en el archivo “empresa1.dat”.
2.	Para generar el archivo llamado “deposito12y15.dat”.
3.	Para Inicializar los vectores y/o matrices auxiliares.

*/
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
struct info1
    {
    char cod[11];
    char car[36];
    int st;
    int pr;
    int dep;
    };
struct info2
    {
    char cod[11];
    char car[36];
    int st;
    };
void inicializarvec(int[],int);
int fcarga(struct info1[]);
void funcionb(struct info1[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    struct info1 vec[5000];
    int i,contador[20],cant;
    inicializarvec(contador,20);
    printf("\n\n\a\a\t\t***** EMPRESA1 ***** \n\n");
    printf("\n Empresa de fabricación de heladeras y lavarropas \n\n");
    printf("\n Actualmente se fabrican casi 5000 productos \n\n");
    cant=fcarga(vec);
    printf("\n\n CONTROL DE PRODUCCIÓN");
    printf("\n ---------------------\n\n");
    printf("\n %c Artículos que se encuentran por debajo del punto de reposición \n en cada uno de los 20 depósitos: \n",16);
    for(i=0;i<cant;i++)
        if(vec[i].st<vec[i].pr)
            contador[vec[i].dep-1]++;
    printf("\n\t N° DE DEPÓSITO \t CANTIDAD \n");
    for(i=0;i<20;i++)
        printf("\n\t %d \t\t\t %d",i+1,contador[i]);
    funcionb(vec,cant);
    printf("\n\n %c Se ha creado un archivo llamado deposito12y15.dat en donde \n se encuentran los artículos por arriba del punto de reposición",16);
    printf("\n y que pertenecen a los depósitos número 12 y 15\n");
    printf("\n\t\t\t\t\t Fin del programa... \n\n\a\a");
    getch();
    }
void inicializarvec(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        v[i]=0;
    }
int fcarga(struct info1 v[])
    {
    int i;
    FILE *pf;
    i=0;
    pf=fopen("empresa1.dat","rb");
    if(pf==NULL)
        {
        printf("\n Error al abrir el archivo \n\n");
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
void funcionb(struct info1 v[],int ce)
    {
    int i;
    struct info2 aux;
    FILE *pf;
    pf=fopen("deposito12y15.dat","wb");
    for(i=0;i<ce;i++)
        if((v[i].dep==12||v[i].dep==15)&&v[i].st>v[i].pr)
            {
            strcpy(aux.cod,v[i].cod);
            strcpy(aux.car,v[i].car);
            aux.st=v[i].st;
            fwrite(&aux,sizeof(struct info2),1,pf);
            }
    fclose(pf);
    }
