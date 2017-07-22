#include<stdio.h>
#include<conio.h>
#include<locale.h>
void ordenarmenor(int[],int);
void ordenarmayor(int[],int);
void main()
    {
    int v[10],i;
    setlocale(LC_CTYPE,"Spanish");
    printf("\n ORDENAMIENTO DE ARRAYS \n\n");
    printf("\n Cargue los datos de un array: \n\n");
    for(i=0;i<10;i++)
        {
        printf("\n Ingrese el valor %d del array: \n\n",i+1);
        scanf("%d",&v[i]);
        }
    ordenarmenor(v,10);
    printf("\n Array ordenado en forma creciente: \n\n");
    for(i=0;i<10;i++)
        printf("\n %d ",v[i]);
    ordenarmayor(v,10);
    printf("\n\n Array ordenado en forma decreciente: \n\n");
    for(i=0;i<10;i++)
        printf("\n %d ",v[i]);
    printf("\n\n Fin del programa \n\n (Presiona una tecla cualquiera para finalizar)\n\n");
    getch();
    }
void ordenarmenor(int v[],int ce)
    {
    int i,j,pm,aux;
    for(j=1;j<ce;j++)
        {
        pm=j-1;
        for(i=j;i<ce;i++)
            if(v[i]<v[pm])
                pm=i;;
        aux=v[pm];
        v[pm]=v[j-1];
        v[j-1]=aux;
        }
    }
void ordenarmayor(int v[],int ce)
    {
    int i,j,pm,aux;
    for(j=1;j<ce;j++)
        {
        pm=j-1;
        for(i=j;i<ce;i++)
            if(v[i]>v[pm])
                pm=i;
        aux=v[pm];
        v[pm]=v[j-1];
        v[j-1]=aux;
        }
    }
