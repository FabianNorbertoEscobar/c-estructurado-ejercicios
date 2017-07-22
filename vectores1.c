#include<stdio.h>
#include<conio.h>
#include<locale.h>
void listarvectores(int[],int[],int[],int[],int);
int sumarvectores(int[],int);
float promediovectores(int[],int);
int contarvectores(int[],int,int);
void main()
    {
    setlocale(LC_CTYPE,"Spanish");
    int vecA[10],vecB[10],vecC[10],vecD[10],dato,i,suma,n,contn;
    float prom;
    for(i=0;i<10;i++)
        {
        printf("\n Ingrese un número entero:\n\n\t");
        scanf("%d",&dato);
        vecA[i]=dato;
        }
    for(i=0;i<10;i++)
        vecB[i]=vecA[i];
    for(i=0;i<10;i++)
        vecC[i]=vecA[i]+vecB[i];
    for(i=0;i<10;i++)
        vecD[9-i]=vecA[i];
    printf("\n\t\t LISTADO DE VECTORES \n");
    printf("\n\t orden \t vecA \t vecB \t vecC \t vecD");
    listarvectores(vecA,vecB,vecC,vecD,10);
    printf("\n\n Las posiciones de elementos pares son:\n\n");
    for(i=0;i<10;i++)
        if(vecA[i]%2==0)
            printf("\t%d\n\n",i+1);
    printf("\n Los elementos de posiciones impares son:\n\n");
    for(i=0;i<10;i+=2)
        printf("\t%d\n\n",vecA[i]);
    suma=sumarvectores(vecA,10);
    printf("La suma de los elementos ingresados es: %d\n\n",suma);
    prom=promediovectores(vecA,10);
    printf("El promedio de los elementos ingresados es: %.2f\n\n",prom);
    printf("Ingrese un valor entero para contar la cantidad de veces que aparece \n entre los números ingresados:\n\n\t");
    scanf("%d",&n);
    contn=contarvectores(vecA,10,n);
    if(contn!=0)
        printf("\n\n La cantidad de veces que fue ingresado el número %d es: %d\n\n",n,contn);
    else
        printf("\n\n El número %d no fue ninguno de los diez ingresados\n\n",n);
    getch();
    }
void listarvectores(int vecA[],int vecB[],int vecC[],int vecD[],int ce)
    {
    int i,acum;
    acum=0;
    for(i=0;i<ce;i++)
        printf("\n\t %d \t %d \t %d \t %d \t %d",i+1,vecA[i],vecB[i],vecC[i],vecD[i]);
    }
int sumarvectores(int vecA[],int ce)
    {
    int acum,i;
    acum=0;
    for(i=0;i<ce;i++)
        acum+=vecA[i];
    return acum;
    }
float promediovectores(int vecA[],int ce)
    {
    int i,acum;
    float pr;
    acum=0;
    for(i=0;i<ce;i++)
        acum+=vecA[i];
    pr=(float)acum/ce;
    return pr;
    }
int contarvectores(int vecA[],int ce,int x)
    {
    int i, cont;
    cont=0;
    for(i=0;i<ce;i++)
        if(vecA[i]==x)
            cont++;
    return cont;
    }
