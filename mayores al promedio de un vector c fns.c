#include<stdio.h>
#include<conio.h>
#include<locale.h>
void ingreso(int[],int);
int promedio(int[],int);
void mostrar(int[],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int vnum[5],prom;
    ingreso(vnum,5);
    prom=promedio(vnum,5);
    printf("\n Los mayores al promedio son: \n");
    mostrar(vnum,5,prom);
    getch();
    }
void ingreso(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        {
        printf("\n Ingrese un número:\t\t");
        scanf("%d",&v[i]);
        }
    }
int promedio(int v[],int ce)
    {
    int i,acum;
    acum=0;
    for(i=0;i<ce;i++)
        acum+=v[i];
    return acum/ce;
    }
void mostrar(int v[],int ce,int p)
    {
    int i;
    for(i=0;i<ce;i++)
        if(v[i]>p)
            printf("\n %d",v[i]);
    }
