#include<stdio.h>
#include<conio.h>
#include<locale.h>
void ingreso(int[],int);
int promedio(int[],int);
int contar(int[],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int v1[5],v2[10],prom1,prom2,pr,cont;
    cont=0;
    printf("\n Datos del primer vector: \n\n");
    ingreso(v1,5);
    printf("\n Datos del segundo vector: \n\n");
    ingreso(v2,10);
    prom1=promedio(v1,5);
    prom2=promedio(v2,10);
    if(prom1>prom2)
        pr=prom1;
    else
        pr=prom2;
    cont+=contar(v1,5,pr);
    cont+=contar(v2,10,pr);
    printf("\n La cantidad de números iguales al mayor promedio \n de ambos promedios es de %d \n\n",cont);
    getch();
    }
void ingreso(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        {
        printf("\n Ingrese un número:\n\n");
        scanf("%d",&v[i]);
        }
    }
int promedio(int v[],int ce)
    {
    int i,acum;
    for(i=0;i<ce;i++)
        acum+=v[i];
    return acum/ce;
    }
int contar(int v[],int ce,int x)
    {
    int i,cont;
    cont=0;
    for(i=0;i<ce;i++)
        if(v[i]==x)
            cont++;
    return cont;
    }
