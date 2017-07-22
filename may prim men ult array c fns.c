#include<stdio.h>
#include<conio.h>
#include<locale.h>
void ingreso(int[],int);
void mostmayalpr(int[],int);
int menalult(int[],int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int c,v[10];
    ingreso(v,10);
    printf("\n Mayores al primero:\n\n");
    mostmayalpr(v,10);
    c=menalult(v,10);
    printf("\n\n La cantidad de menores al último es %d \n\n",c);
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
void mostmayalpr(int v[],int ce)
    {
    int i;
    for(i=0;i<ce;i++)
        if(v[i]>v[0])
            printf("\n %d",v[i]);
    }
int menalult(int v[],int ce)
    {
    int i,cont;
    cont=0;
    for(i=0;i<ce;i++)
        if(v[i]<v[9])
            cont++;
    return cont;
    }
